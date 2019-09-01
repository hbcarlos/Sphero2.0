#pragma comment(lib, "windowsapp")
#include <windows.h>
#include <ppltasks.h>
#include <iostream>
#include <sstream>
#include <string>

#include <winrt/Windows.System.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/windows.devices.enumeration.h>

#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.devices.bluetooth.advertisement.h>

namespace bth {
	using namespace winrt::Windows::Devices::Bluetooth;
	using namespace winrt::Windows::Devices::Bluetooth::Advertisement;
}

namespace utils {
	using namespace winrt::Windows::System;
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Storage::Streams;
	using namespace winrt::Windows::Devices::Enumeration;
}

using namespace concurrency;
using namespace std;
using namespace bth;
using namespace utils;

//#define BLE_DEBUG

class Scanner {
	private:
		winrt::hstring name;
		uint64_t address;
		BluetoothLEDevice device = BluetoothLEDevice(NULL);
		BluetoothLEAdvertisement msg;
		BluetoothLEAdvertisementWatcher watcher;

	public:
		Scanner(winrt::hstring n, uint64_t a);
		void start();
		void stop();

		string getData();
		string getFlags();
		string getLocalName();
		string getManufacturerData();
		string getServices();
		BluetoothLEDevice getDevice();

		void OnAdvertisementRecieved(BluetoothLEAdvertisementWatcher const& watcher, BluetoothLEAdvertisementReceivedEventArgs const& args);
		void OnAdvertisementStopped(BluetoothLEAdvertisementWatcher const & watcher, BluetoothLEAdvertisementWatcherStoppedEventArgs const & args);
		void OnCompletedTask(IAsyncOperation<BluetoothLEDevice> const &op, AsyncStatus const &state);
};