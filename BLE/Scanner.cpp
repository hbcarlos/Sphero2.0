#include "Scanner.h"

Scanner::Scanner(winrt::hstring n, uint64_t a) {
	name = n;
	address = a;
}

void Scanner::start() {
	auto filter = BluetoothLEAdvertisementFilter();
	auto advert = BluetoothLEAdvertisement();

	filter.Advertisement(advert);
	watcher.AdvertisementFilter(filter);
	watcher.ScanningMode(BluetoothLEScanningMode::Active);

	watcher.Received({ this, &Scanner::OnAdvertisementRecieved });
	watcher.Stopped({ this, &Scanner::OnAdvertisementStopped });

	watcher.Start();
	std::cout << "Scanning..." << std::endl;

	while (watcher.Status() != BluetoothLEAdvertisementWatcherStatus::Stopped);
	Sleep(100);
}

void Scanner::stop() {
	if (watcher.Status() == BluetoothLEAdvertisementWatcherStatus::Started){ watcher.Stop(); }
}

string Scanner::getData() {
	Collections::IVector<BluetoothLEAdvertisementDataSection> data = msg.DataSections();
	//std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(data);
	stringstream res;
	for (int i = 0; i < data.Size(); i++) {
		res << "Data Type: " << char(data.GetAt(i).DataType()) << endl;
		res << "Data: " << char(data.GetAt(i).Data().data()) << endl;
	}

	return res.str();
}

string Scanner::getFlags() {
	BluetoothLEAdvertisementFlags flag;
	msg.Flags(flag);
	
	stringstream res;
	if ((flag & BluetoothLEAdvertisementFlags::ClassicNotSupported) == BluetoothLEAdvertisementFlags::ClassicNotSupported) {
		res << "Bluetooth BR / EDR not supported." << endl;
	}
	if ((flag & BluetoothLEAdvertisementFlags::DualModeControllerCapable) == BluetoothLEAdvertisementFlags::DualModeControllerCapable) {
		res << "Simultaneous Bluetooth LE and BR/EDR to same device capable (controller)." << endl;
	}
	if ((flag & BluetoothLEAdvertisementFlags::DualModeHostCapable) == BluetoothLEAdvertisementFlags::DualModeHostCapable) {
		res << "Simultaneous Bluetooth LE and BR/EDR to same device capable (host)" << endl;
	}
	if ((flag & BluetoothLEAdvertisementFlags::GeneralDiscoverableMode) == BluetoothLEAdvertisementFlags::GeneralDiscoverableMode) {
		res << "Bluetooth LE General Discoverable Mode." << endl;
	}
	if ((flag & BluetoothLEAdvertisementFlags::LimitedDiscoverableMode) == BluetoothLEAdvertisementFlags::LimitedDiscoverableMode) {
		res << "Bluetooth LE Limited Discoverable Mode." << endl;
	}
	if ((flag & BluetoothLEAdvertisementFlags::None) == BluetoothLEAdvertisementFlags::None) {
		res << "None" << endl;
	}

	return res.str();
}

string Scanner::getLocalName() {
	return to_string(msg.LocalName());
}

string Scanner::getManufacturerData() {
	Collections::IVector<BluetoothLEManufacturerData> manuFacturerData = msg.ManufacturerData();

	stringstream res;
	for (int i = 0; i < manuFacturerData.Size(); i++) {
		res << "Company ID: " << manuFacturerData.GetAt(i).CompanyId() << endl;
		res << "Data: " << manuFacturerData.GetAt(i).Data().data() << endl;
	}

	return res.str();
}

string Scanner::getServices() {
	Collections::IVector<winrt::guid> uuids = msg.ServiceUuids();

	stringstream res;
	for (int i = 0; i < uuids.Size(); i++) {
		winrt::guid uuid = uuids.GetAt(i);
		res << static_cast<int>(uuid.Data1) << static_cast<int>(uuid.Data2) << static_cast<int>(uuid.Data3);
		res << static_cast<int>(uuid.Data4[0]) << static_cast<int>(uuid.Data4[1]) << static_cast<int>(uuid.Data4[2]);
		res << static_cast<int>(uuid.Data4[3]) << static_cast<int>(uuid.Data4[4]) << static_cast<int>(uuid.Data4[5]);
		res << static_cast<int>(uuid.Data4[6]) << static_cast<int>(uuid.Data4[7]) << endl;
	}

	return res.str();
}

BluetoothLEDevice Scanner::getDevice() {
	start();
	
	IAsyncOperation<BluetoothLEDevice> op = BluetoothLEDevice::FromBluetoothAddressAsync(address);
	op.Completed({ this, &Scanner::OnCompletedTask });
	//std::cout << "Searching device..." << std::endl;

	while (op.Status() != AsyncStatus::Completed);
	Sleep(1000);

	return device;
}

void Scanner::OnAdvertisementRecieved(BluetoothLEAdvertisementWatcher const& watcher, BluetoothLEAdvertisementReceivedEventArgs const& args) {
	BluetoothLEAdvertisement ad = args.Advertisement();
	address = args.BluetoothAddress();
	std::cout << "Device: " << args.BluetoothAddress() << std::endl;
	std::cout << "LocalName: " << to_string(ad.LocalName()) << std::endl;
	std::cout << std::endl;

	/*std::cout << "Address: " << args.BluetoothAddress() << std::endl;
	std::cout << "Data Type: ";
	switch (args.AdvertisementType()) {
		case BluetoothLEAdvertisementType::ConnectableDirected: std::cerr << "The advertisement is directed and indicates that the device is connectable but not scannable." << std::endl; break;
		case BluetoothLEAdvertisementType::ConnectableUndirected: std::cerr << "The advertisement is undirected and indicates that the device is connectable and scannable." << std::endl; break;
		case BluetoothLEAdvertisementType::NonConnectableUndirected: std::cerr << "The advertisement is undirected and indicates that the device is not connectable nor scannable." << std::endl; break;
		case BluetoothLEAdvertisementType::ScannableUndirected: std::cerr << "The advertisement is undirected and indicates that the device is scannable but not connectable." << std::endl; break;
		case BluetoothLEAdvertisementType::ScanResponse: std::cerr << "This advertisement is a scan response to a scan request issued for a scannable advertisement." << std::endl; break;
		default: break;
	}

	std::cout << "LocalName: " << to_string(ad.LocalName()) << std::endl;
	std::cout << "Signal: " << args.RawSignalStrengthInDBm() << std::endl;
	//std::cout << "Timestamp: " << args.Timestamp() << std::endl;*/

	if (ad.LocalName() == name) { watcher.Stop(); address = args.BluetoothAddress(); msg = ad; }
	//if (args.BluetoothAddress() == address) { watcher.Stop(); msg = ad; }
}

void Scanner::OnAdvertisementStopped(BluetoothLEAdvertisementWatcher const & watcher, BluetoothLEAdvertisementWatcherStoppedEventArgs const & args) {
	//std::cout << "Scanner stoped" << std::endl;
	std::cout << std::endl;
}

void Scanner::OnCompletedTask(IAsyncOperation<BluetoothLEDevice> const &op, AsyncStatus const &state) {
	device = op.GetResults();
	std::cout << "Device connected" << std::endl;
}