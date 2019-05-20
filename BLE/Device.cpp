#include "Device.h"

Device::Device(string n, uint64_t a) {
	name = winrt::to_hstring(n);
	address = a;

	Scanner scaner = Scanner(name, 0);
	device = scaner.getDevice();
}

void Device::search() {
	Scanner scaner = Scanner(name, address);
	device = scaner.getDevice();
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
	Collections::IVectorView<GattDeviceService> services = device.GattServices();
	
	stringstream res;
	for (int i = 0; i < services.Size(); i++) {
		if (services.GetAt(i) != NULL) {
			winrt::guid uuid = services.GetAt(i).Uuid();
			res << "Service UUID: " << static_cast<int>(uuid.Data1) << static_cast<int>(uuid.Data2) << static_cast<int>(uuid.Data3);
			res << static_cast<int>(uuid.Data4[0]) << static_cast<int>(uuid.Data4[1]) << static_cast<int>(uuid.Data4[2]);
			res << static_cast<int>(uuid.Data4[3]) << static_cast<int>(uuid.Data4[4]) << static_cast<int>(uuid.Data4[5]);
			res << static_cast<int>(uuid.Data4[6]) << static_cast<int>(uuid.Data4[7]) << endl;

			Collections::IVectorView<GattCharacteristic> car = services.GetAt(i).GetAllCharacteristics();
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

					Collections::IVectorView<GattDescriptor> des = car.GetAt(j).GetAllDescriptors();
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

string Device::getGattPresentationFormat(Collections::IVectorView<GattPresentationFormat> f) {

	stringstream res;
	for (int i = 0; i < f.Size(); i++) {
		res << "\t\t\t" << f.GetAt(i).Description() << endl;
	}
	return res.str();
}