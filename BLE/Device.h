#pragma comment(lib, "windowsapp")
#include <windows.h>
#include <ppltasks.h>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>


#include <winrt/Windows.System.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/windows.devices.enumeration.h>
#include <winrt/Windows.Globalization.DateTimeFormatting.h>

#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>

//#include "ScannerDI.h"
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

		GattDeviceService controlService = GattDeviceService(NULL);
		GattCharacteristic commandsChar = GattCharacteristic(NULL);
		GattCharacteristic responseChar = GattCharacteristic(NULL);
		GattDescriptor responseDesc = GattDescriptor(NULL);

		GattDeviceService serviceBLE = GattDeviceService(NULL);
		GattCharacteristic AntiDosCharacteristic = GattCharacteristic(NULL);
		GattCharacteristic TXPowerCharacteristic = GattCharacteristic(NULL);
		GattCharacteristic WakeCharacteristic = GattCharacteristic(NULL);

		winrt::guid RobotControlService = { 0x22bb746f, 0x2ba0, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };
		winrt::guid CommandsCharacteristic = { 0x22bb746f, 0x2ba1, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };
		winrt::guid ResponseCharacteristic = { 0x22bb746f, 0x2ba6, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };

		winrt::guid BLEService = { 0x22bb746f, 0x2bb0, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };
		winrt::guid AntiDosCharacteristicUUID = { 0x22bb746f, 0x2bbd, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };
		winrt::guid TXPowerCharacteristicUUID = { 0x22bb746f, 0x2bb2, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };
		winrt::guid WakeCharacteristicUUID = { 0x22bb746f, 0x2bbf, 0x7554, { 0x2d, 0x6f, 0x72, 0x65, 0x68, 0x70, 0x53, 0x27 } };

	public:
		Device(string n, uint64_t a);
		void connect();
		void disconnect();
		void devModeOn();

		int sentCommand(vector<uint8_t> data);
		std::vector<uint8_t> generateCommand(uint8_t device, uint8_t command, uint8_t sequence, std::vector<uint8_t> data);

		void read(GattCharacteristic charac);
		void write(GattCharacteristic charac, vector<uint8_t> data);

		void OnAccessResponse(IAsyncOperation<DeviceAccessStatus> const &op, AsyncStatus const &state);
		void OnOpenResponse(IAsyncOperation<GattOpenStatus> const &op, AsyncStatus const &state);
		void OnServicesRecived(IAsyncOperation<GattDeviceServicesResult> const &op, AsyncStatus const &state);
		void OnCharacteristicsRecived(IAsyncOperation<GattCharacteristicsResult> const &op, AsyncStatus const &state);

		void OnDescriptorWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state);
		void OnDescriptorWriteWithResult(IAsyncOperation<GattWriteResult> const &op, AsyncStatus const &state);
		void OnDescriptorRead(IAsyncOperation<GattReadClientCharacteristicConfigurationDescriptorResult> const &op, AsyncStatus const &state);

		void OnCompletedRead(IAsyncOperation<GattReadResult> const &op, AsyncStatus const &state);
		void OnCompletedWrite(IAsyncOperation<GattCommunicationStatus> const &op, AsyncStatus const &state);
		void OnNotify(GattCharacteristic  const &characteristic, GattValueChangedEventArgs  const &args);

		bool asyncStatus(AsyncStatus res);
		bool gattCommunicationStatus(GattCommunicationStatus res);
};