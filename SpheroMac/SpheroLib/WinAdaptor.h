#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

#include <sstream>
#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "AtlBase.h"
#include "AtlConv.h"
#include <winsock2.h>
#include <ws2bth.h>
#pragma comment(lib, "Ws2_32.lib")
#include "BluetoothAPIs.h"
#pragma comment(lib, "Bthprops.lib")

//#define SPHERO_DEBUG
#ifdef SPHERO_DEBUG
#endif

#include "Commands.h"
#include "Messages.h"

//======================================================================================================================
#define BLUETOOTH_SOCKET_INVALID INVALID_SOCKET
typedef SOCKET BluetoothSocket;
typedef unsigned char ubyte;

enum BthState {
	SpheroState_None = 0,
	SpheroState_Error_BluetoothError = 1,
	SpheroState_Error_BluetoothUnavailable = 2,
	SpheroState_Error_NotPaired = 3,
	SpheroState_Error_ConnectionFailed = 4,
	SpheroState_Disconnected = 5,
	SpheroState_Connected = 6
};

class Adaptor {
	private:
		std::string name;
		int t = 1000;
		BthState state = SpheroState_None;
		BLUETOOTH_ADDRESS address = { BLUETOOTH_NULL_ADDRESS };
		BluetoothSocket sc = BLUETOOTH_SOCKET_INVALID;

		DWORD myThreadID;
		HANDLE myHandle;
		HANDLE mMessage;
		HANDLE mSocket;

		SequenceId currentSequence = 0;
		std::vector<ubyte> receiveBuffer;
		std::vector<SpheroMessage> messages;

		bool bthInitialize();
		void bthCleanup();
		bool bthGetDeviceAddress(std::string n);
		SequenceId nextSeqId();
		bool bthSend(const std::vector<ubyte> data);
		bool bthReceive(std::vector<ubyte>& data, bool bBlocking = false);
		static DWORD WINAPI listeningThread(LPVOID lpParameter);
		std::vector<ubyte> generateCommand(DeviceId device, ubyte command, ubyte sequence = 0x00, std::vector<ubyte> data = std::vector<ubyte>());

	public:
		Adaptor();
		Adaptor(std::string n);

		BthState bthState();
		bool bthAvailable();
		bool bthDevicePaired();
		std::string bthGetAddress();

		bool bthConnect();
		bool bthDisconnect();

		bool deviceReceive();
		SequenceId deviceSend(DeviceId device, ubyte command, std::vector<ubyte> data = std::vector<ubyte>());
		SpheroMessage receive(SequenceId id);
		SpheroMessage receiveAsync(AsyncResponseIdCode id);
};
