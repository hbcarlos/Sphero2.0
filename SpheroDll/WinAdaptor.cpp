#pragma once
#include "stdafx.h"
#include "WinAdaptor.h"

Adaptor::Adaptor(){
}

Adaptor::Adaptor(std::string n) {
	name = n;
	if (!bthInitialize()) {
		state = SpheroState_Error_BluetoothError;
	} else if (!bthAvailable()) {
		state = SpheroState_Error_BluetoothUnavailable;
	} else {
		bthGetDeviceAddress(name);

		if (!bthDevicePaired()) {
			state = SpheroState_Error_NotPaired;
		}

		state = SpheroState_Disconnected;
	}
}

SequenceId Adaptor::nextSeqId() {
	if (currentSequence == 255)
		currentSequence = 0;

	return ++currentSequence;
}

BthState Adaptor::bthState() {
	return state;
}

bool Adaptor::bthInitialize() {
	WSADATA     WSAData = { 0 };
	return (WSAStartup(MAKEWORD(2, 2), &WSAData) == 0);
};

void Adaptor::bthCleanup() {
	WSACleanup();
}

bool Adaptor::bthAvailable() {
	bool adapterFound = false;

	HANDLE info;
	BLUETOOTH_FIND_RADIO_PARAMS params;
	params.dwSize = sizeof(params);

	HBLUETOOTH_RADIO_FIND find = BluetoothFindFirstRadio(&params, &info);

	if (find != 0) {
		adapterFound = true;
		CloseHandle(info);
	}

	BluetoothFindRadioClose(find);
	return adapterFound;
}

bool Adaptor::bthDevicePaired() {
	return (address.ullLong != BLUETOOTH_NULL_ADDRESS);
}

bool Adaptor::bthGetDeviceAddress(std::string n) {
	BLUETOOTH_DEVICE_SEARCH_PARAMS params = {
		sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS),
		TRUE, FALSE, FALSE, TRUE, FALSE, 0, NULL
	};

	//std::cout << "Buscando dispositivos bluetooth..." << std::endl;

	BLUETOOTH_DEVICE_INFO info;
	info.dwSize = sizeof(info);
	HBLUETOOTH_DEVICE_FIND found = BluetoothFindFirstDevice(&params, &info);

	//std::cout << "Buscando sphero..." << std::endl;
	//std::cout << "Name: " << name.c_str() << std::endl;
	for (; found != NULL; BluetoothFindNextDevice(found, &info)) {
		
		//std::cout << "Encontrado: " << CW2A(info.szName) << std::endl;

		if (strcmp(CW2A(info.szName), name.c_str()) == 0) {
			address = info.Address;
			//std::cout << "Addres: " << address.ullLong << std::endl;
			break;
		}
	}

	BluetoothFindDeviceClose(found);
	return true;
}

std::string Adaptor::bthGetAddress() {
	std::stringstream mss;
	mss << "[ADDR]" << address.ullLong;
	return mss.str();
}

bool Adaptor::bthConnect() {

	//std::cout << "Comprobando direccion..." << std::endl;
	//std::cout << "Addres: " << address.ullLong << std::endl;
	if (address.ullLong == BLUETOOTH_NULL_ADDRESS) {
		std::cout << "BLUETOOTH_SOCKET_INVALID: NULL ADDRESS" << std::endl;
		sc = BLUETOOTH_SOCKET_INVALID;
		state = SpheroState_Error_ConnectionFailed;
		return false;
	}

	//std::cout << "Creando el socket..." << std::endl;
	SOCKADDR_BTH socketAddress;
	socketAddress.addressFamily = AF_BTH;
	socketAddress.btAddr = address.ullLong;
	socketAddress.port = 0;
	socketAddress.serviceClassId = SerialPortServiceClass_UUID;

	sc = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);

	if (sc == INVALID_SOCKET) {
		std::cout << "BLUETOOTH_SOCKET_INVALID: BAD SOCKET" << std::endl;
		sc = BLUETOOTH_SOCKET_INVALID;
		state = SpheroState_Error_ConnectionFailed;
		return false;
	}

	//std::cout << "Conectando..." << std::endl;
	if (connect(sc, (struct sockaddr *)&socketAddress, sizeof(socketAddress)) == SOCKET_ERROR) {
		std::cout << "BLUETOOTH_SOCKET_INVALID: CONNECTION ERROR" << std::endl;
		sc = BLUETOOTH_SOCKET_INVALID;
		state = SpheroState_Error_ConnectionFailed;
		return false;
	}

	state = SpheroState_Connected;
	myHandle = CreateThread(0, 0, listeningThread, this, 0, &myThreadID);
	mMessage = CreateMutex(NULL, FALSE, NULL);
	mSocket = CreateMutex(NULL, FALSE, NULL);
	if (mMessage == NULL || mSocket == NULL || myHandle == NULL){
		std::cout << "PROBLEM WITH THREAD: CONNECTION ERROR" << std::endl;
		return false;
	}

	return true;
}

bool Adaptor::bthDisconnect() {
	if (sc != BLUETOOTH_SOCKET_INVALID) {
		TerminateThread(myHandle, 0);
		CloseHandle(mMessage);
		CloseHandle(mSocket);
		CloseHandle(myHandle);
		closesocket(sc);
		sc = BLUETOOTH_SOCKET_INVALID;
		state = SpheroState_Disconnected;
		return true;
	}
	return false;
}

DWORD WINAPI Adaptor::listeningThread(LPVOID lpParameter){
	Adaptor *sp = (Adaptor*)lpParameter;
	SYSTEMTIME tv;
	GetSystemTime(&tv);
	int ant = (int)tv.wMilliseconds;
	int act = (int)tv.wMilliseconds;
	int dif;

	while (true) {
		sp->deviceReceive();

		GetSystemTime(&tv);
		act = (int)tv.wMilliseconds;
		dif = act - ant;
		ant = act;
		if (dif < 20) { Sleep((20 - dif)); }
	}
	return 0;
}

bool Adaptor::bthSend(const std::vector<ubyte> data) {
	if (data.empty()) return true;

	SetLastError(0);
	//std::cout << "SEND: Escriviendo socket..." << std::endl;
	WaitForSingleObject(mSocket, 20);
	int bytesSent = send(sc, reinterpret_cast<const char*>(data.data()), data.size(), 0);
	ReleaseMutex(mSocket);
	//std::cout << "SEND: Socket escrito" << std::endl;
	
	if (bytesSent == SOCKET_ERROR) {
		if (GetLastError() == WSAEWOULDBLOCK)
			return true;
		else
			return false;
	}

	return true;
}

bool Adaptor::bthReceive(std::vector<ubyte>& data, bool bBlocking) {

	//std::cout << "Comprobando socket..." << std::endl;
	u_long blockingMode = bBlocking ? 0 : 1; // Non-zero means non-blocking
	if (ioctlsocket(sc, FIONBIO, &blockingMode) == SOCKET_ERROR) {
		//std::cout << "SOCKET_ERROR" << std::endl;
		return false;
	}

	data.reserve(2048);
	data.resize(2048);

	SetLastError(0);
	//std::cout << "Reciviendo datos..." << std::endl;
	int bytesRead = recv(sc, reinterpret_cast<char*>(data.data()), data.capacity(), 0);
	if (bytesRead == 0) {
		data.resize(0);
		return false;
	}
	else if (bytesRead == SOCKET_ERROR) {
		//std::cout << "SOCKET_ERROR: Leyendo datos" << std::endl;
		data.resize(0);
		if (GetLastError() == WSAEWOULDBLOCK) {
			//std::cout << "Fin mensage" << std::endl;
			return true;
		}
		else
			return false;
	}

	data.resize(bytesRead);
	return true;
}

SpheroMessage Adaptor::receive(SequenceId id) {
	
	SpheroMessage msg;
	SYSTEMTIME tv;
	GetSystemTime(&tv);
	int ant = (int)tv.wMilliseconds;
	int act = (int)tv.wMilliseconds;
	
	while (act - ant < 1000){
	//for (int fin = 0; fin < t; fin++) {

		for (int i = 0; i < messages.size(); i++) {

			//std::cout << "Id: " << (int)id << " Msg: " << (int)messages[i].sequenceId << std::endl;
			if (messages[i].sequenceId == id) {
				msg = messages[i];

				//std::cout << "SINC: Borrando mensage..." << std::endl;
				WaitForSingleObject(mMessage, 20);
				messages.erase(messages.begin() + i);
				ReleaseMutex(mMessage);
				//std::cout << "SINC: Mensage borrado" << std::endl;
				return msg;
			}
		}
		//std::cout << "Witing message... " << fin << std::endl;
		Sleep(20); //20ms
		int act = (int)tv.wMilliseconds;
	}
	std::cout << "Message not find: " << std::endl;
	return msg;
}

SpheroMessage Adaptor::receiveAsync(AsyncResponseIdCode id) {
	
	SpheroMessage msg;
	std::cout << "Message size: " << messages.size() << std::endl;
	for (int i = 0; i < messages.size(); i++) {

		if (messages[i].idCode == id) {
			msg = messages[i];

			//std::cout << "ASYNC: Borrando mensage..." << std::endl;
			WaitForSingleObject(mMessage, 20);
			messages.erase(messages.begin() + i);
			ReleaseMutex(mMessage);
			//std::cout << "ASYNC: Mensage borrado" << std::endl;

			//std::cout << "Message find: " << fin << std::endl;
			return msg;
		}
	}
	return msg;
}

SequenceId Adaptor::deviceSend(DeviceId device, ubyte command, std::vector<ubyte> data) {
	if (bthState() != SpheroState_Connected)
		return 0;

	SequenceId seqId = nextSeqId();
	std::vector<ubyte> commandData = generateCommand(device, command, seqId, data);

#ifdef SPHERO_DEBUG
	std::stringstream mss;
	mss << "[SEND][" << std::setw(3) << commandData.size() << "B] ";
	for (size_t idx = 0; idx < commandData.size(); ++idx) {
		mss << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(commandData[idx]) << " ";
	}
	std::cout << mss.str() << std::endl;
#endif

	if (!bthSend(commandData)) {
		return 0;
	}

	return seqId;
}

bool Adaptor::deviceReceive() {
	if (bthState() != SpheroState_Connected)
		return false;

	bool receiveState = false;
	std::vector<ubyte> receiveData;

	//std::cout << "Receiving data..." << std::endl;
	// Receive all pending data
	//std::cout << "REC: Leyendo socket..." << std::endl;
	WaitForSingleObject(mSocket, 20);
	while (true) {
		receiveData.clear();
		receiveState = bthReceive(receiveData);

		//std::cout << "Estoy colgado..." << receiveData.size() << " " << receiveState << std::endl;

		if (receiveData.size() <= 0 || receiveState != true)
			break;

		receiveBuffer.insert(receiveBuffer.end(), receiveData.begin(), receiveData.end());
	}
	ReleaseMutex(mSocket);
	//std::cout << "REC: Socket leido" << std::endl;

	//std::cout << "Creating message..." << std::endl;
	//std::cout << "Data size: " << receiveBuffer.size() << std::endl;
	// Parse data to messages
	while (receiveBuffer.size() > SPHERO_RESPONSE_HEADER_SIZE) {
		if (receiveBuffer[0] != SPHERO_RESPONSE_SOP1_MASK) {
			return false;
		}

		SpheroMessage newMessage;
		size_t dataLength = 0;
		if (receiveBuffer[1] == SPHERO_RESPONSE_SOP2_MASK_ACK) {
			newMessage.responseCode = (ResponseCode)receiveBuffer[2];
			newMessage.sequenceId = receiveBuffer[3];
			dataLength = receiveBuffer[4];
		}
		else if (receiveBuffer[1] == SPHERO_RESPONSE_SOP2_MASK_ASYNC) {
			newMessage.responseCode = ResponseCode_OK;
			newMessage.sequenceId = INVALID_SEQUENCE_ID;
			newMessage.idCode = (AsyncResponseIdCode)receiveBuffer[2];
			dataLength = (receiveBuffer[3] << 8 | receiveBuffer[4]);
		}
		else {
			return false;
		}

		// Check if message can be complete
		if (receiveBuffer.size() < (dataLength + SPHERO_RESPONSE_HEADER_SIZE))
			break;

		size_t messageLength = SPHERO_RESPONSE_HEADER_SIZE + dataLength;

		// Check message checksum
		unsigned long byteSum = std::accumulate(receiveBuffer.begin() + 2, receiveBuffer.begin() + (messageLength - 1), 0);
		ubyte checkSum = static_cast<ubyte>(~(byteSum % 256));
		if (receiveBuffer[dataLength + 4] != checkSum) {
			return false;
		}

#ifdef SPHERO_DEBUG
		std::stringstream mss;
		mss << "[RECV][" << std::setw(3) << messageLength << "B] ";
		for (size_t idx = 0; idx < messageLength; ++idx) {
			mss << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(receiveBuffer[idx]) << " ";
		}
		std::cout << mss.str() << std::endl;
#endif

		newMessage.data.insert(newMessage.data.end(), receiveBuffer.begin() + SPHERO_RESPONSE_HEADER_SIZE, receiveBuffer.begin() + (messageLength - 1));
		receiveBuffer.erase(receiveBuffer.begin(), receiveBuffer.begin() + messageLength);

		//std::cout << "REC: Escriviendo mensage..." << std::endl;
		WaitForSingleObject(mMessage, 20);
		messages.push_back(newMessage);
		ReleaseMutex(mMessage);
		//std::cout << "REC: Mensage escrito" << std::endl;	
	}

	// Check for errors
	if (receiveState == false)
		return false;

	return true;
}

std::vector<ubyte> Adaptor::generateCommand(DeviceId device, ubyte command, ubyte sequence, std::vector<ubyte> data) {

	std::vector<ubyte> returnData;

	returnData.push_back(SPHERO_REQUEST_SOP1_MASK);
	returnData.push_back(SPHERO_REQUEST_SOP2_MASK | SPHERO_REQUEST_SOP2_MASK_ANSWER);
	returnData.push_back(device);
	returnData.push_back(command);
	returnData.push_back(sequence);
	returnData.push_back(data.size() + 1);

	returnData.insert(returnData.end(), data.begin(), data.end());

	unsigned long byteSum = std::accumulate(returnData.begin() + 2, returnData.end(), 0);

	returnData.push_back(static_cast<ubyte>(~(byteSum % 256)));

	return returnData;
}
