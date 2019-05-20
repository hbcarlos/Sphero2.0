#pragma comment(lib, "windowsapp")
#include <windows.h>
#include <ppltasks.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

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
		vector<GattCharacteristic> readableChar;
		vector<GattCharacteristic> writableChar;
		vector<GattCharacteristic> notifiableChar;
		vector<GattCharacteristic> indicatableChar;

	public:
		Device(string n, uint64_t a);
		void search();
		void searchChar();

		void read(GattCharacteristic charac);
		void write(GattCharacteristic charac, vector<uint8_t> data);
		void notify(GattCharacteristic charac);
		void indicate(GattCharacteristic charac);
		
		void OnCompletedRead(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state);
		void OnCompletedWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state);
		void OnCompletedNotify(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state);
		void OnCompletedIndicate(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state);
		void OnNotify(GattCharacteristic  const & watcher, GattValueChangedEventArgs  const & args);
		void OnIndicate(GattCharacteristic  const & watcher, GattValueChangedEventArgs  const & args);

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