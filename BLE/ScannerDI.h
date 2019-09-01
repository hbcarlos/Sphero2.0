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

#define BLE_DEBUG

class ScannerDI {
	private:
		winrt::hstring name;
		uint64_t address;
		DeviceWatcher watcher = NULL;
		DeviceInformation info = DeviceInformation(nullptr);
		BluetoothLEDevice device = BluetoothLEDevice(nullptr);

	public:
		ScannerDI(winrt::hstring n, uint64_t a);
		void start();
		void stop();

		BluetoothLEDevice getDevice();

		void OnDeviceAdded(DeviceWatcher const& watcher, DeviceInformation const& info);
		void OnDeviceUpdated(DeviceWatcher const& watcher, DeviceInformationUpdate const& inf);
		void OnDeviceRemoved(DeviceWatcher const& watcher, DeviceInformationUpdate const& inf);
		void OnDeviceCompleted(DeviceWatcher const& watcher, IInspectable const& none);
		void OnDeviceStopped(DeviceWatcher const& watcher, IInspectable const& none);

		void OnDeviceFound(IAsyncOperation<BluetoothLEDevice> const &op, AsyncStatus const &state);
		void OnDevicePaired(IAsyncOperation<DevicePairingResult> const &op, AsyncStatus const &state);
		void OnDevicePairedCustom(DeviceInformationCustomPairing const &op, DevicePairingRequestedEventArgs const &args);
};