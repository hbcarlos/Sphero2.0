#pragma comment(lib, "windowsapp")
#include <windows.h>
#include <ppltasks.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

/*#include <vector>
#include <map>
#include <algorithm>
#include <numeric>*/




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
	using namespace winrt::Windows::Foundation::Collections;
	using namespace winrt::Windows::Globalization::DateTimeFormatting;
}

using namespace concurrency;
using namespace std;
using namespace bth;
using namespace utils;

#define BLE_DEBUG

class Device {
	private:
		winrt::hstring name;
		uint64_t address;
		BluetoothLEDevice device = BluetoothLEDevice(NULL);
		IVector<GattCharacteristic> readableChar;
		IVector<GattCharacteristic> writableChar;
		IVector<GattCharacteristic> notifiableChar;

	public:
		Device(string n, uint64_t a);
		void search();
		void searchChar();
		void read(GattCharacteristic charac);
		void write(GattCharacteristic charac);
		void OnCompletedRead(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state);
		void OnCompletedWrite(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state);

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
		string getGattPresentationFormat(IVectorView<GattPresentationFormat> f);
};