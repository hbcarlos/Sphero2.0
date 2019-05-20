#include "Device.h"

Device::Device(string n, uint64_t a) {
	name = winrt::to_hstring(n);
	address = a;

	readableChar = vector<GattCharacteristic>();
	writableChar = vector<GattCharacteristic>();
	notifiableChar = vector<GattCharacteristic>();
	indicatableChar = vector<GattCharacteristic>();

	Scanner scaner = Scanner(name, 0);
	device = scaner.getDevice();
}

void Device::search() {
	Scanner scaner = Scanner(name, address);
	device = scaner.getDevice();
}

void Device::searchChar() {
	IVectorView<GattDeviceService> services = device.GattServices();

	for (int i = 0; i < services.Size(); i++) {
		cout << "servicio " << i << endl;
		IVectorView<GattCharacteristic> car = services.GetAt(i).GetAllCharacteristics();
		
		for (int j = 0; j < car.Size(); j++) {
			cout << "caracteristica " << j << endl;

			if (car.GetAt(j) != NULL) {
				GattCharacteristicProperties p = car.GetAt(j).CharacteristicProperties();

				
				if ((p & GattCharacteristicProperties::Read) == GattCharacteristicProperties::Read) {
					cout << "Read" << endl;
					readableChar.push_back(car.GetAt(j));
					read(car.GetAt(j));
				}

				if ((p & GattCharacteristicProperties::Write) == GattCharacteristicProperties::Write) {
					cout << "Write" << endl;
					writableChar.push_back(car.GetAt(j));
					write(car.GetAt(j), {0xFF, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x02});
				}

				if ((p & GattCharacteristicProperties::Notify) == GattCharacteristicProperties::Notify) {
					cout << "Notify" << endl;
					notifiableChar.push_back(car.GetAt(j));
					notify(car.GetAt(j));
				}

				if ((p & GattCharacteristicProperties::Indicate) == GattCharacteristicProperties::Indicate) {
					cout << "The characteristic is indicatable." << endl;
					indicatableChar.push_back(car.GetAt(j));
					indicate(car.GetAt(j));
				}
			}
		}
	}
}

void Device::read(GattCharacteristic charac) {
	IAsyncOperation<GattReadResult> op = charac.ReadValueAsync();
	op.Completed({ this, &Device::OnCompletedRead });
	std::cout << "Reading..." << std::endl;

	while (op.Status() != AsyncStatus::Completed);
	Sleep(100);
}

void Device::write(GattCharacteristic charac, vector<uint8_t> data) {
	DataWriter wr = DataWriter();

	for (size_t idx = 0; idx < data.size(); ++idx) {
		wr.WriteByte(data[idx]);
	}

	#ifdef BLE_DEBUG
		std::stringstream mss;
		mss << "[SEND][" << setw(3) << data.size() << "B] ";
		for (size_t idx = 0; idx < data.size(); ++idx) {
			mss << std::uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data[idx]) << " ";
		}
		std::cout << mss.str() << std::endl;
	#endif
	
	IAsyncOperation<GattCommunicationStatus> op = charac.WriteValueAsync(wr.DetachBuffer());
	op.Completed({ this, &Device::OnCompletedWrite });
	std::cout << "Writing..." << std::endl;

	while (op.Status() != AsyncStatus::Completed);
	Sleep(100);
}

void Device::notify(GattCharacteristic charac) {
	IAsyncOperation<GattCommunicationStatus> op = charac.WriteClientCharacteristicConfigurationDescriptorAsync(GattClientCharacteristicConfigurationDescriptorValue::Notify);
	op.Completed({ this, &Device::OnCompletedNotify });
	std::cout << "Notifying..." << std::endl;

	while (op.Status() != AsyncStatus::Completed);
	charac.ValueChanged({ this, &Device::OnNotify });
	Sleep(100);
}

void Device::indicate(GattCharacteristic charac) {
	IAsyncOperation<GattCommunicationStatus> op = charac.WriteClientCharacteristicConfigurationDescriptorAsync(GattClientCharacteristicConfigurationDescriptorValue::Indicate);
	op.Completed({ this, &Device::OnCompletedIndicate });
	std::cout << "indicating..." << std::endl;

	while (op.Status() != AsyncStatus::Completed);
	charac.ValueChanged({ this, &Device::OnIndicate });
	Sleep(100);
}

void Device::OnCompletedRead(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state) {
	GattReadResult msg = op.GetResults();
	DataReader data = DataReader::FromBuffer(msg.Value());
	uint32_t nBytes = data.UnconsumedBufferLength();
	
	if (msg.Status() == GattCommunicationStatus::Success) {
		#ifdef BLE_DEBUG
			std::stringstream mss;
			mss << "[RECV][" << setw(3) << nBytes << "B] ";
			for (size_t idx = 0; idx < nBytes; ++idx) {
				mss << uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data.ReadByte()) << " ";
			}
			std::cout << mss.str() << std::endl;
		#endif
	} else {
		switch (msg.Status()) {
			case GattCommunicationStatus::Unreachable: cerr << "No communication can be performed with the device, at this time." << endl; break;
			case GattCommunicationStatus::ProtocolError: cerr << "There was a GATT communication protocol error." << endl; break;
			case GattCommunicationStatus::AccessDenied: cerr << "Access is denied." << endl; break;
			default: break;
		}
	}

	cout << to_string(data.ReadString(nBytes)) << endl;
}

void Device::OnCompletedWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state) {
	switch (op.GetResults()) {
		case GattCommunicationStatus::Success: cout << "The operation completed successfully." << endl; break;
		case GattCommunicationStatus::Unreachable: cerr << "No communication can be performed with the device, at this time." << endl; break;
		case GattCommunicationStatus::ProtocolError: cerr << "There was a GATT communication protocol error." << endl; break;
		case GattCommunicationStatus::AccessDenied: cerr << "Access is denied." << endl; break;
		default: break;
	}
}

void Device::OnCompletedNotify(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state) {
	switch (op.GetResults()) {
		case GattCommunicationStatus::Success: cout << "The operation completed successfully." << endl; break;
		case GattCommunicationStatus::Unreachable: cerr << "No communication can be performed with the device, at this time." << endl; break;
		case GattCommunicationStatus::ProtocolError: cerr << "There was a GATT communication protocol error." << endl; break;
		case GattCommunicationStatus::AccessDenied: cerr << "Access is denied." << endl; break;
		default: break;
	}
}

void Device::OnCompletedIndicate(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state) {
	switch (op.GetResults()) {
	case GattCommunicationStatus::Success: cout << "The operation completed successfully." << endl; break;
	case GattCommunicationStatus::Unreachable: cerr << "No communication can be performed with the device, at this time." << endl; break;
	case GattCommunicationStatus::ProtocolError: cerr << "There was a GATT communication protocol error." << endl; break;
	case GattCommunicationStatus::AccessDenied: cerr << "Access is denied." << endl; break;
	default: break;
	}
}

void Device::OnNotify(GattCharacteristic  const & watcher, GattValueChangedEventArgs  const & args) {
	DataReader data = DataReader::FromBuffer(args.CharacteristicValue());
	uint32_t nBytes = data.UnconsumedBufferLength();

	#ifdef BLE_DEBUG
		std::stringstream mss;
		mss << "[RECV][" << setw(3) << nBytes << "B] ";
		for (size_t idx = 0; idx < nBytes; ++idx) {
			mss << uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data.ReadByte()) << " ";
		}
		std::cout << mss.str() << std::endl;
	#endif

	cout << to_string(data.ReadString(nBytes)) << endl;
}

void Device::OnIndicate(GattCharacteristic  const & watcher, GattValueChangedEventArgs  const & args) {
	DataReader data = DataReader::FromBuffer(args.CharacteristicValue());
	uint32_t nBytes = data.UnconsumedBufferLength();

	#ifdef BLE_DEBUG
		std::stringstream mss;
		mss << "[RECV][" << setw(3) << nBytes << "B] ";
		for (size_t idx = 0; idx < nBytes; ++idx) {
			mss << uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data.ReadByte()) << " ";
		}
		std::cout << mss.str() << std::endl;
	#endif

	cout << to_string(data.ReadString(nBytes)) << endl;
}

string Device::getName() {
	return to_string(device.Name());
}

string Device::getDeviceId() {
	return to_string(device.DeviceId());
}

string Device::getBluetoothDeviceId() {
	return to_string(device.BluetoothDeviceId().Id() );
}

ULONG Device::getBluetoothAddress() {
	return device.BluetoothAddress();
}

string Device::getBluetoothAddressType() {
	string res = " ";
	switch (device.BluetoothAddressType()) {
		case BluetoothAddressType::Public: res = "Public address."; break;
		case BluetoothAddressType::Random: res = "Random address."; break;
		case BluetoothAddressType::Unspecified: res = "Unspecified address."; break;
		default: break;
	}
	return res;
}

string Device::getConnectionStatus() {
	string res = " ";
	switch (device.ConnectionStatus()) {
		case BluetoothConnectionStatus::Connected: res = "The device is connected."; break;
		case BluetoothConnectionStatus::Disconnected: res = "The device is disconnected."; break;
		default: break;
	}
	return res;
}

string Device::getDeviceAccessInformation() {
	string res = " ";
	switch (device.DeviceAccessInformation().CurrentStatus()) {
		case DeviceAccessStatus::Allowed: res = "Access to the device is allowed."; break;
		case DeviceAccessStatus::DeniedBySystem: res = "Access to the device has been disallowed by the system."; break;
		case DeviceAccessStatus::DeniedByUser: res = "Access to the device has been disallowed by the user."; break;
		case DeviceAccessStatus::Unspecified: res = "The device access is not specified."; break;
		default: break;
	}
	return res;
}

string Device::getDeviceInformation() {
	cout << "Not implemented" << endl;
	return " ";
}

string Device::getAll() {
	IVectorView<GattDeviceService> services = device.GattServices();
	
	stringstream res;
	for (int i = 0; i < services.Size(); i++) {
		if (services.GetAt(i) != NULL) {
			winrt::guid uuid = services.GetAt(i).Uuid();
			res << "Service UUID: " << static_cast<int>(uuid.Data1) << static_cast<int>(uuid.Data2) << static_cast<int>(uuid.Data3);
			res << static_cast<int>(uuid.Data4[0]) << static_cast<int>(uuid.Data4[1]) << static_cast<int>(uuid.Data4[2]);
			res << static_cast<int>(uuid.Data4[3]) << static_cast<int>(uuid.Data4[4]) << static_cast<int>(uuid.Data4[5]);
			res << static_cast<int>(uuid.Data4[6]) << static_cast<int>(uuid.Data4[7]) << endl;

			IVectorView<GattCharacteristic> car = services.GetAt(i).GetAllCharacteristics();
			for (int j = 0; j < car.Size(); j++) {
				if (car.GetAt(j) != NULL) {
					uuid = car.GetAt(j).Uuid();
					res << "\tCharacteristic UUID: " << static_cast<int>(uuid.Data1) << static_cast<int>(uuid.Data2) << static_cast<int>(uuid.Data3);
					res << static_cast<int>(uuid.Data4[0]) << static_cast<int>(uuid.Data4[1]) << static_cast<int>(uuid.Data4[2]);
					res << static_cast<int>(uuid.Data4[3]) << static_cast<int>(uuid.Data4[4]) << static_cast<int>(uuid.Data4[5]);
					res << static_cast<int>(uuid.Data4[6]) << static_cast<int>(uuid.Data4[7]) << endl;

					res << "\t\tDescription: " << to_string(car.GetAt(j).UserDescription()) << endl;
					res << "\t\tProperties: " << endl;
					res << getCharacteristicProperties(car.GetAt(j).CharacteristicProperties());
					//res << "\t\tPresentation Format: " << endl;
					//res << getGattPresentationFormat(car.GetAt(j).PresentationFormats());

					IVectorView<GattDescriptor> des = car.GetAt(j).GetAllDescriptors();
					for (int k = 0; k < des.Size(); k++) {
						if (des.GetAt(k) != NULL) {
							uuid = des.GetAt(k).Uuid();
							res << "\t\tDescriptor UUID: " << static_cast<int>(uuid.Data1) << static_cast<int>(uuid.Data2) << static_cast<int>(uuid.Data3);
							res << static_cast<int>(uuid.Data4[0]) << static_cast<int>(uuid.Data4[1]) << static_cast<int>(uuid.Data4[2]);
							res << static_cast<int>(uuid.Data4[3]) << static_cast<int>(uuid.Data4[4]) << static_cast<int>(uuid.Data4[5]);
							res << static_cast<int>(uuid.Data4[6]) << static_cast<int>(uuid.Data4[7]) << endl;
						}
					}
				}
			}
		}
		res << endl;
	}

	return res.str();
}

string Device::getCharacteristicProperties(GattCharacteristicProperties p) {
	
	stringstream res;
	if ((p & GattCharacteristicProperties::None) == GattCharacteristicProperties::None) {
		res << "\t\t\tThe characteristic doesn’t have any properties that apply." << endl;
	}
	if ((p & GattCharacteristicProperties::Broadcast) == GattCharacteristicProperties::Broadcast) {
		res << "\t\t\tThe characteristic supports broadcasting." << endl;
	}
	if ((p & GattCharacteristicProperties::Read) == GattCharacteristicProperties::Read) {
		res << "\t\t\tThe characteristic is readable." << endl;
	}
	if ((p & GattCharacteristicProperties::WriteWithoutResponse) == GattCharacteristicProperties::WriteWithoutResponse) {
		res << "\t\t\tThe characteristic supports Write Without Response." << endl;
	}
	if ((p & GattCharacteristicProperties::Write) == GattCharacteristicProperties::Write) {
		res << "\t\t\tThe characteristic is writable." << endl;
	}
	if ((p & GattCharacteristicProperties::Notify) == GattCharacteristicProperties::Notify) {
		res << "\t\t\tThe characteristic is notifiable." << endl;
	}
	if ((p & GattCharacteristicProperties::Indicate) == GattCharacteristicProperties::Indicate) {
		res << "\t\t\tThe characteristic is indicatable." << endl;
	}
	if ((p & GattCharacteristicProperties::AuthenticatedSignedWrites) == GattCharacteristicProperties::AuthenticatedSignedWrites) {
		res << "\t\t\tThe characteristic supports signed writes." << endl;
	}
	if ((p & GattCharacteristicProperties::ExtendedProperties) == GattCharacteristicProperties::ExtendedProperties) {
		res << "\t\t\tThe ExtendedProperties Descriptor is present." << endl;
	}
	if ((p & GattCharacteristicProperties::ReliableWrites) == GattCharacteristicProperties::ReliableWrites) {
		res << "\t\t\tThe characteristic supports reliable writes." << endl;
	}
	if ((p & GattCharacteristicProperties::WritableAuxiliaries) == GattCharacteristicProperties::WritableAuxiliaries) {
		res << "\t\t\tThe characteristic has writable auxiliaries." << endl;
	}

	return res.str();
}

string Device::getGattPresentationFormat(IVectorView<GattPresentationFormat> f) {

	stringstream res;
	for (int i = 0; i < f.Size(); i++) {
		res << "\t\t\t" << f.GetAt(i).Description() << endl;
	}
	return res.str();
}