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
#include <winrt/Windows.Globalization.DateTimeFormatting.h>

#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>

#include "Scanner.h"

namespace bth {
	using namespace winrt::Windows::Devices::Bluetooth;
	using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;
}

namespace utils {
	using namespace winrt::Windows::System;
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Storage::Streams;
	using namespace winrt::Windows::Devices::Enumeration;
	using namespace winrt::Windows::Globalization::DateTimeFormatting;
}

using namespace concurrency;
using namespace std;
using namespace bth;
using namespace utils;

class Device {
	private:
		winrt::hstring name;
		uint64_t address;
		BluetoothLEDevice device = BluetoothLEDevice(NULL);

	public:
		Device(string n, uint64_t a);
		void search();
		string getName();
		string getDeviceId();
		string getBluetoothDeviceId();
		ULONG getBluetoothAddress();
		string getBluetoothAddressType();
		string getConnectionStatus();
		string getDeviceAccessInformation();
		string getDeviceInformation();
		string getAll();
		string getCharacteristicProperties(GattCharacteristicProperties car);
		string getGattPresentationFormat(Collections::IVectorView<GattPresentationFormat> f);
};