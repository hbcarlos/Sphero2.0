#include "ScannerDI.h"

ScannerDI::ScannerDI(winrt::hstring n, uint64_t a) {
	name = n;
	address = a;
	info = DeviceInformation(nullptr);
	device = BluetoothLEDevice(nullptr);
}

void ScannerDI::start() {

	// Query for extra properties you want returned
	//Collections::IVector<winrt::hstring> requestedProperties = Collections::IVector<winrt::hstring>();
	//requestedProperties.Append(winrt::to_hstring("System.Devices.Aep.DeviceAddress"));
	//requestedProperties.Append(winrt::to_hstring("System.Devices.Aep.IsConnected"));

	watcher = DeviceInformation::CreateWatcher(
			BluetoothLEDevice::GetDeviceSelectorFromBluetoothAddress(address),
			nullptr, //requestedProperties,
			DeviceInformationKind::AssociationEndpoint);

	// Register event handlers before starting the watcher.
	// Added, Updated and Removed are required to get all nearby devices
	watcher.Added( TypedEventHandler<DeviceWatcher, DeviceInformation>(this, &ScannerDI::OnDeviceAdded) );
	watcher.Updated( TypedEventHandler<DeviceWatcher, DeviceInformationUpdate>(this, &ScannerDI::OnDeviceUpdated) );
	watcher.Removed( TypedEventHandler<DeviceWatcher, DeviceInformationUpdate>(this, &ScannerDI::OnDeviceRemoved) );

	// EnumerationCompleted and Stopped are optional to implement.
	watcher.EnumerationCompleted( TypedEventHandler<DeviceWatcher, IInspectable>(this, &ScannerDI::OnDeviceCompleted) );
	watcher.Stopped( TypedEventHandler<DeviceWatcher, IInspectable>(this, &ScannerDI::OnDeviceStopped) );

	// Start the watcher.
	watcher.Start();
	std::cout << "Scanning..." << std::endl;

	while (watcher.Status() != DeviceWatcherStatus::Stopped){ Sleep(100); }
	Sleep(100);
}

void ScannerDI::stop() { watcher.Stop(); }

BluetoothLEDevice ScannerDI::getDevice() {
	IAsyncOperation<BluetoothLEDevice> op = BluetoothLEDevice::FromIdAsync(info.Id());
	op.Completed({ this, &ScannerDI::OnDeviceFound });
	std::cout << "Serching device..." << std::endl;
	while (op.Status() != AsyncStatus::Completed);
	Sleep(100);
	std::cout << std::endl;

	return device;
}

void ScannerDI::OnDeviceAdded(DeviceWatcher const& watcher, DeviceInformation const& inf) {
	#ifdef BLE_DEBUG
		std::cout << "Device: " << to_string(inf.Id()) << std::endl;
		std::cout << "	LocalName: " << to_string(inf.Name()) << std::endl;
		std::cout << "	IsEnable: " << to_string(inf.IsEnabled()) << std::endl;
		
		Collections::IMapView<winrt::hstring, IInspectable> properties = inf.Properties();
		DeviceInformationKind kind = inf.Kind();
		string res = " ";
		switch (kind) {
			case DeviceInformationKind::Unknown: res = "Unknown"; break;
			case DeviceInformationKind::DeviceInterface: res = "DeviceInterface"; break;
			case DeviceInformationKind::DeviceContainer: res = "DeviceContainer"; break;
			case DeviceInformationKind::Device: res = "Device"; break;
			case DeviceInformationKind::DeviceInterfaceClass: res = "DeviceInterfaceClass"; break;
			case DeviceInformationKind::AssociationEndpoint: res = "AssociationEndpoint"; break;
			case DeviceInformationKind::AssociationEndpointContainer: res = "AssociationEndpointContainer"; break;
			case DeviceInformationKind::AssociationEndpointService: res = "AssociationEndpointService"; break;
			case DeviceInformationKind::DevicePanel: res = "DevicePanel"; break;
			default: break;
		}
		std::cout << "	Kind: " << res << std::endl;

		DeviceInformationPairing dev = inf.Pairing();
		std::cout << "	Pair info: " << std::endl;
		std::cout << "		CanPair: " << to_string(dev.CanPair()) << std::endl;
		std::cout << "		IsPaired: " << to_string(dev.IsPaired()) << std::endl;
		
		switch (dev.ProtectionLevel()) {
			case DevicePairingProtectionLevel::Default: res = "The default value.This should not be used."; break;
			case DevicePairingProtectionLevel::None: res = "Pair the device using no levels of protection."; break;
			case DevicePairingProtectionLevel::Encryption: res = "Pair the device using encryption."; break;
			case DevicePairingProtectionLevel::EncryptionAndAuthentication: res = "Pair the device using encryption and authentication."; break;
			default: break;
		}
		std::cout << "		Proteccion: " << res << std::endl;
		std::cout << std::endl;
	#endif

	if (inf.Pairing().CanPair() && !inf.Pairing().IsPaired()) {
		DeviceInformationCustomPairing custom = inf.Pairing().Custom();
		custom.PairingRequested(TypedEventHandler<DeviceInformationCustomPairing, DevicePairingRequestedEventArgs>(this, &ScannerDI::OnDevicePairedCustom));

		IAsyncOperation<DevicePairingResult> opPair = custom.PairAsync(DevicePairingKinds::ConfirmOnly, DevicePairingProtectionLevel::None);
		opPair.Completed({ this, &ScannerDI::OnDevicePaired });
		std::cout << "Trying to pair..." << std::endl;
		while (opPair.Status() != AsyncStatus::Completed);
		Sleep(100);
		std::cout << std::endl;
	}

	info = inf;
	watcher.Stop();
}
void ScannerDI::OnDeviceUpdated(DeviceWatcher const& watcher, DeviceInformationUpdate const& inf) {
	std::cout << "Device updated: " << std::endl;
	std::cout << "	Device: " << to_string(inf.Id()) << std::endl;
	std::cout << std::endl;
}
void ScannerDI::OnDeviceRemoved(DeviceWatcher const& watcher, DeviceInformationUpdate const& inf) {
	std::cout << "Device removed: " << std::endl;
	std::cout << "	Device: " << to_string(inf.Id()) << std::endl;
	std::cout << std::endl;
}
void ScannerDI::OnDeviceCompleted(DeviceWatcher const& watcher, IInspectable const& none) {
	std::cout << "Scanner completed. Device not found" << std::endl;
	std::cout << std::endl;
	system("pause");
	exit(1);
}
void ScannerDI::OnDeviceStopped(DeviceWatcher const& watcher, IInspectable const& none) {
	std::cout << "Finising scan..." << std::endl;
	std::cout << std::endl;
}

void ScannerDI::OnDeviceFound(IAsyncOperation<BluetoothLEDevice> const &op, AsyncStatus const &state) {
	device = op.GetResults();
}
void ScannerDI::OnDevicePaired(IAsyncOperation<DevicePairingResult> const &op, AsyncStatus const &state) {
	DevicePairingResult resPair = op.GetResults();
	string res = " ";
	switch (resPair.Status()) {
		case DevicePairingResultStatus::Paired: res = "The device object is now paired."; break;
		case DevicePairingResultStatus::NotReadyToPair: res = "The device object is not in a state where it can be paired."; break;
		case DevicePairingResultStatus::NotPaired: res = "The device object is not currently paired."; break;
		case DevicePairingResultStatus::AlreadyPaired: res = "The device object has already been paired."; break;
		case DevicePairingResultStatus::ConnectionRejected: res = "The device object rejected the connection."; break;
		case DevicePairingResultStatus::TooManyConnections: res = "The device object indicated it cannot accept any more incoming connections."; break;
		case DevicePairingResultStatus::HardwareFailure: res = "The device object indicated there was a hardware failure."; break;
		case DevicePairingResultStatus::AuthenticationTimeout: res = "The authentication process timed out before it could complete."; break;
		case DevicePairingResultStatus::AuthenticationNotAllowed: res = "The authentication protocol is not supported, so the device is not paired."; break;
		case DevicePairingResultStatus::AuthenticationFailure: res = "Authentication failed, so the device is not paired. Either the device object or the application rejected the authentication."; break;
		case DevicePairingResultStatus::NoSupportedProfiles: res = "There are no network profiles for this device object to use."; break;
		case DevicePairingResultStatus::ProtectionLevelCouldNotBeMet: res = "The minimum level of protection is not supported by the device object or the application."; break;
		case DevicePairingResultStatus::AccessDenied: res = "Your application does not have the appropriate permissions level to pair the device object."; break;
		case DevicePairingResultStatus::InvalidCeremonyData: res = "The ceremony data was incorrect."; break;
		case DevicePairingResultStatus::PairingCanceled: res = "The pairing action was canceled before completion."; break;
		case DevicePairingResultStatus::OperationAlreadyInProgress: res = "The device object is already attempting to pair or unpair."; break;
		case DevicePairingResultStatus::RequiredHandlerNotRegistered: res = "Either the event handler wasn't registered or a required DevicePairingKinds was not supported."; break;
		case DevicePairingResultStatus::RejectedByHandler: res = "The application handler rejected the pairing."; break;
		case DevicePairingResultStatus::RemoteDeviceHasAssociation: res = "The remove device already has an association."; break;
		case DevicePairingResultStatus::Failed: res = "An unknown failure occurred."; break;
		default: break;
	}
	std::cout << "Pair results: " << res << std::endl;
}
void ScannerDI::OnDevicePairedCustom(DeviceInformationCustomPairing const &op, DevicePairingRequestedEventArgs const &args) {
	args.Accept();
	info = args.DeviceInformation();
}