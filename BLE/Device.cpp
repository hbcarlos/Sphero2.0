#include "Device.h"

Device::Device(string n, uint64_t a) {
	name = winrt::to_hstring(n);
	address = a;
	device = NULL;

	controlService = GattDeviceService(NULL);
	commandsChar = GattCharacteristic(NULL);
	responseChar = GattCharacteristic(NULL);
	responseDesc = GattDescriptor(NULL);
}

void Device::connect() {
	Scanner scanner = Scanner(name, address);
	scanner.start();
	device = scanner.getDevice();
	
	IAsyncOperation<DeviceAccessStatus> opAcc = device.RequestAccessAsync();
	std::cout << "Getting Access to device..." << std::endl;
	opAcc.Completed({ this, &Device::OnAccessResponse });
	while (opAcc.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	devModeOn();
	
	IAsyncOperation<GattDeviceServicesResult> opService = device.GetGattServicesForUuidAsync(RobotControlService, BluetoothCacheMode::Uncached);
	opService.Completed({ this, &Device::OnServicesRecived });
	std::cout << "Getting services..." << std::endl;
	while (opService.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	/*controlService.Session().MaintainConnection(true);

	IAsyncOperation<GattOpenStatus> opOpen = controlService.OpenAsync(GattSharingMode::SharedReadAndWrite); //Exclusive SharedReadAndWrite
	opOpen.Completed({ this, &Device::OnOpenResponse });
	std::cout << "Opening services..." << std::endl;
	while (opOpen.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	#ifdef BLE_DEBUG
		std::cout << "Service Configuration:" << std::endl;
		GattSession session = controlService.Session();
		std::cout << "	CanMaintainConnection: " << session.CanMaintainConnection() << std::endl;
		std::cout << "	SessionStatus: ";
		switch (session.SessionStatus()) {
			case GattSessionStatus::Closed: std::cout << "The GATT session is closed." << std::endl; break;
			case GattSessionStatus::Active: std::cout << "The GATT session is active." << std::endl; break;
			default: break;
		}
		std::cout << "	SharingMode: ";
		switch (controlService.SharingMode()) {
			case GattSharingMode::Unspecified: std::cout << "The sharing mode is unspecified." << std::endl; break;
			case GattSharingMode::Exclusive: std::cout << "The sharing mode is exclusive." << std::endl; break;
			case GattSharingMode::SharedReadOnly: std::cout << "The sharing mode is read only." << std::endl; break;
			case GattSharingMode::SharedReadAndWrite: std::cout << "The sharing mode is read and write." << std::endl; break;
			default: break;
		}
		std::cout << std::endl;
	#endif*/

	IAsyncOperation<GattCharacteristicsResult> opChar = controlService.GetCharacteristicsAsync(BluetoothCacheMode::Uncached);
	opChar.Completed({ this, &Device::OnCharacteristicsRecived });
	std::cout << "Getting characteristics..." << std::endl;
	while (opChar.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	/*IAsyncOperation<GattWriteResult> opDesWrite = commandsChar.WriteClientCharacteristicConfigurationDescriptorWithResultAsync(GattClientCharacteristicConfigurationDescriptorValue::Notify);
	opDesWrite.Completed({ this, &Device::OnDescriptorWrite });
	std::cout << "Writing descriptor..." << std::endl;
	while (opDesWrite.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;*/

	//IAsyncOperation<GattReadClientCharacteristicConfigurationDescriptorResult> opDesRead = responseChar.ReadClientCharacteristicConfigurationDescriptorAsync();
	//IAsyncOperation<GattCommunicationStatus> opDesRead = responseChar.WriteClientCharacteristicConfigurationDescriptorAsync(GattClientCharacteristicConfigurationDescriptorValue::Notify);
	IAsyncOperation<GattWriteResult> opDesRead = responseChar.WriteClientCharacteristicConfigurationDescriptorWithResultAsync(GattClientCharacteristicConfigurationDescriptorValue::Notify);
	opDesRead.Completed({ this, &Device::OnDescriptorWriteWithResult });
	std::cout << "Reading descriptor..." << std::endl;
	while (opDesRead.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	//commandsHandle = commandsChar.AttributeHandle();
	responseChar.ValueChanged({ this, &Device::OnNotify });
	std::cout << "Conected" << std::endl;

	///write(WakeCharacteristic, { 0x13 });
}
void Device::disconnect() {
	device.Close();
	device = BluetoothLEDevice(NULL);

	controlService = GattDeviceService(NULL);
	commandsChar = GattCharacteristic(NULL);
	responseChar = GattCharacteristic(NULL);
	responseDesc = GattDescriptor(NULL);

	std::cout << "Disconected" << std::endl;
}
void Device::devModeOn() {
	IAsyncOperation<GattDeviceServicesResult> opService = device.GetGattServicesForUuidAsync(BLEService, BluetoothCacheMode::Uncached);
	opService.Completed({ this, &Device::OnServicesRecived });
	std::cout << "Getting services..." << std::endl;
	while (opService.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	/*serviceBLE.Session().MaintainConnection(true);

	IAsyncOperation<GattOpenStatus> opOpen = serviceBLE.OpenAsync(GattSharingMode::SharedReadAndWrite); //Exclusive SharedReadAndWrite
	opOpen.Completed({ this, &Device::OnOpenResponse });
	std::cout << "Opening services..." << std::endl;
	while (opOpen.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

#ifdef BLE_DEBUG
	std::cout << "Service Configuration:" << std::endl;
	GattSession session = serviceBLE.Session();
	std::cout << "	CanMaintainConnection: " << session.CanMaintainConnection() << std::endl;
	std::cout << "	SessionStatus: ";
	switch (session.SessionStatus()) {
	case GattSessionStatus::Closed: std::cout << "The GATT session is closed." << std::endl; break;
	case GattSessionStatus::Active: std::cout << "The GATT session is active." << std::endl; break;
	default: break;
	}
	std::cout << "	SharingMode: ";
	switch (serviceBLE.SharingMode()) {
	case GattSharingMode::Unspecified: std::cout << "The sharing mode is unspecified." << std::endl; break;
	case GattSharingMode::Exclusive: std::cout << "The sharing mode is exclusive." << std::endl; break;
	case GattSharingMode::SharedReadOnly: std::cout << "The sharing mode is read only." << std::endl; break;
	case GattSharingMode::SharedReadAndWrite: std::cout << "The sharing mode is read and write." << std::endl; break;
	default: break;
	}
	std::cout << std::endl;
#endif*/

	IAsyncOperation<GattCharacteristicsResult> opChar = serviceBLE.GetCharacteristicsAsync(BluetoothCacheMode::Uncached);
	opChar.Completed({ this, &Device::OnCharacteristicsRecived });
	std::cout << "Getting characteristics..." << std::endl;
	while (opChar.Status() != AsyncStatus::Completed);
	Sleep(1000);
	std::cout << std::endl;

	//std::wstring msg(L"011ie");
	//write(AntiDosCharacteristic, { static_cast<unsigned char>(std::stol(msg)) });
	//write(TXPowerCharacteristic, { 7 });
	//write(WakeCharacteristic, { 1 });// generateCommand(0x00, 0x01, 0x01, {}));

	std::cout << "Conected devModeOn" << std::endl;
}

int Device::sentCommand(vector<uint8_t> data) {
	write(commandsChar, data);
	return 0;
}
std::vector<uint8_t> Device::generateCommand(uint8_t device, uint8_t command, uint8_t sequence, std::vector<uint8_t> data) {

	std::vector<uint8_t> returnData;

	returnData.push_back(0xFF);
	returnData.push_back(0xFE);
	returnData.push_back(device);
	returnData.push_back(command);
	returnData.push_back(sequence);
	returnData.push_back(data.size() + 1);

	returnData.insert(returnData.end(), data.begin(), data.end());

	unsigned long byteSum = std::accumulate(returnData.begin() + 2, returnData.end(), 0);

	returnData.push_back(static_cast<uint8_t>(~(byteSum % 256)));

	return returnData;
}

void Device::read(GattCharacteristic charac) {
	IAsyncOperation<GattReadResult> op = responseDesc.ReadValueAsync(BluetoothCacheMode::Uncached);
	op.Completed({ this, &Device::OnCompletedRead });
	std::cout << "Reading..." << std::endl;
}
void Device::write(GattCharacteristic charac, vector<uint8_t> data) {
	DataWriter wr = DataWriter();

	for (int idx = 0; idx < data.size(); idx++) {
		wr.WriteByte(data[idx]);
	}
	wr.WriteByte(data.size() + 1);

#ifdef BLE_DEBUG
	std::stringstream mss;
	mss << "[SEND][" << setw(3) << data.size() << "B] ";
	for (size_t idx = 0; idx < data.size(); ++idx) {
		mss << std::uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data[idx]) << " ";
	}
	std::cout << mss.str() << std::endl;
#endif

	//GattWriteRequest req = GattWriteRequest(nullptr);

	//GattReliableWriteTransaction writable = GattReliableWriteTransaction();
	//writable.WriteValue(charac, wr.DetachBuffer());
	//writable.CommitWithResultAsync();
	//writable.CommitAsync();

	IAsyncOperation<GattCommunicationStatus> op = charac.WriteValueAsync(wr.DetachBuffer(), GattWriteOption::WriteWithResponse);// WithResultAsync(wr.DetachBuffer(), GattWriteOption::WriteWithResponse);
	op.Completed({ this, &Device::OnCompletedWrite });
	std::cout << "Writing..." << std::endl;
}

void Device::OnAccessResponse(IAsyncOperation<DeviceAccessStatus> const &op, AsyncStatus const &state) {
	if (asyncStatus(state)) {
		std::cout << "	AccessResponse: ";
		switch (op.GetResults()) {
		case DeviceAccessStatus::Allowed: std::cout << "Access to the device is allowed." << std::endl; break;
		case DeviceAccessStatus::DeniedBySystem: std::cout << "Access to the device has been disallowed by the system." << std::endl; break;
		case DeviceAccessStatus::DeniedByUser: std::cout << "Access to the device has been disallowed by the user." << std::endl; break;
		case DeviceAccessStatus::Unspecified: std::cout << "The device access is not specified." << std::endl; break;
		default: break;
		}
	}
}
void Device::OnOpenResponse(IAsyncOperation<GattOpenStatus> const &op, AsyncStatus const &state) {
	if (asyncStatus(state)) {
		std::cout << "	OpenStatus: ";
		switch (op.GetResults()) {
			case GattOpenStatus::Unspecified: std::cout << "Unspecified error." << std::endl; break;
			case GattOpenStatus::Success: std::cout << "The GATT device service was successfully opened." << std::endl; break;
			case GattOpenStatus::AlreadyOpened: std::cout << "The GATT device service is already opened." << std::endl; break;
			case GattOpenStatus::NotFound: std::cout << "The GATT device service was not found." << std::endl; break;
			case GattOpenStatus::SharingViolation: std::cout << "There was a sharing violation." << std::endl; break;
			case GattOpenStatus::AccessDenied: std::cout << "Access is denied." << std::endl; break;
			default: break;
		}
	}
}
void Device::OnServicesRecived(IAsyncOperation<GattDeviceServicesResult> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults().Status())) {
		GattDeviceServicesResult resServices = op.GetResults();

		IVectorView<GattDeviceService> services = resServices.Services();
		for (int i = 0; i < services.Size(); i++) {
			if (services.GetAt(i).Uuid() == RobotControlService) {
				controlService = services.GetAt(i);
				std::cout << "	controlService optained" << std::endl;
			}

			if (services.GetAt(i).Uuid() == BLEService) {
				serviceBLE = services.GetAt(i);
				std::cout << "	BLEService optained" << std::endl;
			}

		}
	}
}
void Device::OnCharacteristicsRecived(IAsyncOperation<GattCharacteristicsResult> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults().Status())) {
		GattCharacteristicsResult resCharacteristics = op.GetResults();

		IVectorView<GattCharacteristic> car = resCharacteristics.Characteristics();
		//std::cout << car.Size() << std::endl;
		for (int j = 0; j < car.Size(); j++) {
			if (car.GetAt(j).Uuid() == CommandsCharacteristic) {
				commandsChar = car.GetAt(j);
				std::cout << "	commandsChar optained for";
			}

			if (car.GetAt(j).Uuid() == ResponseCharacteristic) {
				responseChar = car.GetAt(j);
				std::cout << "	responseChar optained for";
			}

			if (car.GetAt(j).Uuid() == AntiDosCharacteristicUUID) {
				AntiDosCharacteristic = car.GetAt(j);
				std::cout << "	AntiDosCharacteristic optained for";
			}

			if (car.GetAt(j).Uuid() == TXPowerCharacteristicUUID) {
				TXPowerCharacteristic = car.GetAt(j);
				std::cout << "	TXPowerCharacteristic optained for";
			}

			if (car.GetAt(j).Uuid() == WakeCharacteristicUUID) {
				WakeCharacteristic = car.GetAt(j);
				std::cout << "	WakeCharacteristic optained for";
			}

			if (car.GetAt(j).Uuid() == CommandsCharacteristic || car.GetAt(j).Uuid() == ResponseCharacteristic ||
				car.GetAt(j).Uuid() == AntiDosCharacteristicUUID || car.GetAt(j).Uuid() == TXPowerCharacteristicUUID || car.GetAt(j).Uuid() == WakeCharacteristicUUID) {
				
				GattCharacteristicProperties p = car.GetAt(j).CharacteristicProperties();
				if ((p & GattCharacteristicProperties::Read) == GattCharacteristicProperties::Read) { std::cout << " Read"; }
				if ((p & GattCharacteristicProperties::Write) == GattCharacteristicProperties::Write) { std::cout << " Write"; }
				if ((p & GattCharacteristicProperties::Notify) == GattCharacteristicProperties::Notify) { std::cout << " Notify"; }
				if ((p & GattCharacteristicProperties::Indicate) == GattCharacteristicProperties::Indicate) { std::cout << " The characteristic is indicatable"; }
				if ((p & GattCharacteristicProperties::Broadcast) == GattCharacteristicProperties::Broadcast) { std::cout << " Broadcast " << endl; }
				if ((p & GattCharacteristicProperties::ExtendedProperties) == GattCharacteristicProperties::ExtendedProperties) { std::cout << " ExtendedProperties"; }
				if ((p & GattCharacteristicProperties::ReliableWrites) == GattCharacteristicProperties::ReliableWrites) { std::cout << " ReliableWrites"; }
				if ((p & GattCharacteristicProperties::WritableAuxiliaries) == GattCharacteristicProperties::WritableAuxiliaries) { std::cout << " WritableAuxiliaries"; }
				if ((p & GattCharacteristicProperties::WriteWithoutResponse) == GattCharacteristicProperties::WriteWithoutResponse) { std::cout << " WriteWithoutResponse"; }
				std::cout << std::endl;

				/*IVectorView<GattDescriptor> des = car.GetAt(j).GetAllDescriptors();
				std::cout << des.Size() << std::endl;
				stringstream res;
				for (int k = 0; k < des.Size(); k++) {
					if (des.GetAt(k) != NULL) {
						responseDesc = des.GetAt(k);
						winrt::guid uuid = des.GetAt(k).Uuid();
						res << "\t\tDescriptor UUID: " << hex << static_cast<int>(uuid.Data1) << hex << static_cast<int>(uuid.Data2) << hex << static_cast<int>(uuid.Data3);
						res << hex << static_cast<int>(uuid.Data4[0]) << hex << static_cast<int>(uuid.Data4[1]) << hex << static_cast<int>(uuid.Data4[2]);
						res << hex << static_cast<int>(uuid.Data4[3]) << hex << static_cast<int>(uuid.Data4[4]) << hex << static_cast<int>(uuid.Data4[5]);
						res << hex << static_cast<int>(uuid.Data4[6]) << hex << static_cast<int>(uuid.Data4[7]) << endl;
					}
				}

				std::cout << res.str() << std::endl;*/
			}
		}
	}
}

void Device::OnDescriptorWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults())) {}
}
void Device::OnDescriptorWriteWithResult(IAsyncOperation<GattWriteResult> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults().Status())) {
		GattWriteResult res = op.GetResults();
	}
}
void Device::OnDescriptorRead(IAsyncOperation<GattReadClientCharacteristicConfigurationDescriptorResult> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults().Status())) {
		GattReadClientCharacteristicConfigurationDescriptorResult res = op.GetResults();
		std::cout << "	Descriptor results: ";
		switch (res.ClientCharacteristicConfigurationDescriptor()) {
			case GattClientCharacteristicConfigurationDescriptorValue::None: std::cout << "Neither notification nor indications are enabled." << std::endl; break;
			case GattClientCharacteristicConfigurationDescriptorValue::Notify: std::cout << "Characteristic notifications are enabled." << std::endl; break;
			case GattClientCharacteristicConfigurationDescriptorValue::Indicate: std::cout << "Characteristic indications are enabled." << std::endl; break;
			default: break;
		}
	}
}

void Device::OnCompletedRead(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state) {
	if (asyncStatus(state) && gattCommunicationStatus(op.GetResults().Status())) {
		GattReadResult msg = op.GetResults();
		
		DataReader data = DataReader::FromBuffer(msg.Value());
		uint32_t nBytes = data.UnconsumedBufferLength();

		#ifdef BLE_DEBUG
			std::cout << "Buffer length: " << msg.Value().Length() << std::endl;
			std::stringstream mss;
			mss << "[RECV][" << setw(3) << nBytes << "B] ";
			for (size_t idx = 0; idx < nBytes; ++idx) {
				mss << uppercase << setw(2) << setfill('0') << hex << static_cast<int>(data.ReadByte()) << " ";
			}
			std::cout << mss.str() << std::endl;
		#endif
	}
}
void Device::OnCompletedWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state) {
	if ( asyncStatus(state) && gattCommunicationStatus(op.GetResults()) ) { //.Status())) {
		GattCommunicationStatus write = op.GetResults();
	}
		
}
void Device::OnNotify(GattCharacteristic  const &characteristic, GattValueChangedEventArgs  const &args) {
	if (characteristic == commandsChar) {
		std::cout << "Device ready to use" << std::endl;
	
	} else {
		std::cout << "HAY ALGO PARA LEER" << std::endl;
		read(characteristic);
	}
}

bool Device::asyncStatus(AsyncStatus res) {
#ifdef BLE_DEBUG
	std::cout << "	Status Operation: ";
	switch (res) {
		case AsyncStatus::Started: std::cout << "The operation has started." << std::endl; break;
		case AsyncStatus::Completed: std::cerr << "The operation has completed." << std::endl; break;
		case AsyncStatus::Canceled: std::cerr << "The operation was canceled." << std::endl; break;
		case AsyncStatus::Error: std::cerr << "The operation has encountered an error." << std::endl; break;
		default: break;
	}
#endif
	switch (res) {
		case AsyncStatus::Started: return false; break;
		case AsyncStatus::Completed: return true; break;
		case AsyncStatus::Canceled: return false; break;
		case AsyncStatus::Error: return false; break;
		default: break;
	}
	return false;
}
bool Device::gattCommunicationStatus(GattCommunicationStatus res) {
#ifdef BLE_DEBUG
	std::cout << "	Status Communication: ";
	switch (res) {
		case GattCommunicationStatus::Success: std::cout << "The operation completed successfully." << std::endl; break;
		case GattCommunicationStatus::Unreachable: std::cout << "No communication can be performed with the device, at this time." << std::endl; break;
		case GattCommunicationStatus::ProtocolError: std::cout << "There was a GATT communication protocol error." << std::endl; break;
		case GattCommunicationStatus::AccessDenied: std::cout << "Access is denied." << std::endl; break;
		default: break;
	}
#endif
	switch (res) {
		case GattCommunicationStatus::Success: return true; break;
		case GattCommunicationStatus::Unreachable: return false; break;
		case GattCommunicationStatus::ProtocolError: return false; break;
		case GattCommunicationStatus::AccessDenied: return false; break;
		default: break;
	}
	return false;
}