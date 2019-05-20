#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <pthread.h>
#include <signal.h>
#include <sys/time.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

#include <sstream>
#include <iostream>
#include <iomanip>

//#define SPHERO_DEBUG

#include "Commands.h"
#include "Messages.h"

//======================================================================================================================
#define BLUETOOTH_SOCKET_INVALID INVALID_SOCKET
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
        int fd = NULL;
        int t = 10000;
        bool kill = false;
		BthState state = SpheroState_None;
    
        pthread_attr_t attr;
        pthread_t thread;
        pthread_mutex_t mutex;
    
        SequenceId currentSequence = 0;
        std::vector<ubyte> receiveBuffer;
        std::vector<SpheroMessage> messages;
    
        bool bthInitialize();
        void bthCleanup();
        bool bthGetDeviceAddress(std::string n);
        SequenceId nextSeqId();
        bool bthSend(const std::vector<ubyte> data);
        bool bthReceive(std::vector<ubyte>& data, bool bBlocking = false);
        bool deviceReceive();
        static void *listeningThread(void *ptrSphero);
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
    
        SequenceId deviceSend(DeviceId device, ubyte command, std::vector<ubyte> data = std::vector<ubyte>());
        SpheroMessage receive(SequenceId id);
        SpheroMessage receiveAsync(AsyncResponseIdCode id);
};
