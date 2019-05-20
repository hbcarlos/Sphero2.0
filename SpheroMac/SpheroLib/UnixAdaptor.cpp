#include "UnixAdaptor.h"

Adaptor::Adaptor(){
}

Adaptor::Adaptor(std::string n) {
    name = n;
    state = SpheroState_Disconnected;
}

bool Adaptor::bthInitialize(){
    std::cout << "bthInitialize: Not implemented on unix" << std::endl;
    return false;
}
void Adaptor::bthCleanup(){
    std::cout << "bthCleanup: Not implemented on unix" << std::endl;
}

bool Adaptor::bthGetDeviceAddress(std::string n){
    std::cout << "bthGetDeviceAddress: Not implemented on unix" << std::endl;
    return false;
}

SequenceId Adaptor::nextSeqId() {
    if (currentSequence == 255)
        currentSequence = 0;
    
    return ++currentSequence;
}

BthState Adaptor::bthState() {
	return state;
}

bool Adaptor::bthAvailable(){
    std::cout << "bthAvailable: Not implemented on unix" << std::endl;
    return false;
}
bool Adaptor::bthDevicePaired(){
    std::cout << "bthDevicePaired: Not implemented on unix" << std::endl;
    return false;
}

std::string Adaptor::bthGetAddress(){
    std::cout << "bthGetAddress: Not implemented on unix" << std::endl;
    return "bthGetAddress: Not implemented on unix";
}

bool Adaptor::bthConnect() {

    fd = open(name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    int i = 0;
    
    //std::cout << "Conecting 2..." << std::endl;
    
    while ( fd < 0 && i < 5 ) fd = open(name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY); i++;
    
    //std::cout << "fd: " << fd << " i: " << i << std::endl;
    
    if (fd >= 0){
        //std::cout << "Opened bluetooth port" << std::endl;
        state = SpheroState_Connected;
        
        currentSequence = 0;
        messages.clear();
        receiveBuffer.clear();
        
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_attr_init(&attr);
        pthread_create(&thread, &attr, Adaptor::listeningThread, this);
        
        return true;
        
    } else if (fd == -1) {
        state = SpheroState_Error_BluetoothError;
        return false;
        
    } else if (fd == -2) {
        state = SpheroState_Error_BluetoothUnavailable;
        return false;
        
    } else if (fd == -3){
        state = SpheroState_Error_NotPaired;
        return false;
        
    } else {
        state = SpheroState_Error_BluetoothError;
        return false;
    }
}

bool Adaptor::bthDisconnect() {
    if (fd != NULL) {
        
        kill = true;
        pthread_join(thread, NULL);
        
        close(fd);
		state = SpheroState_Disconnected;
        //std::cout << "Closed bluetooth port" << std::endl;
		return true;
	}
	return false;
}

void *Adaptor::listeningThread(void *ptrSphero){
    Adaptor *sp = (Adaptor*)ptrSphero;
    timeval tv;
    gettimeofday(&tv, NULL);
    int ant = (int)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
    int act = (int)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
    int dif;
    
    while(true) {
        sp->deviceReceive();
        if (sp->kill) return 0;
        
        gettimeofday(&tv, NULL);
        act = (int)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
        dif = act - ant;
        ant = act;
        if (dif < 20) usleep((20-dif)*1000);
    }
}

SpheroMessage Adaptor::receive(SequenceId id) {
    int i = 0;
    SpheroMessage msg;
    int fin = 0;
    
    for (; fin < t; fin++) {
        //deviceReceive();
        //if (i < messages.size()) std::cout << "id: " << messages[i].sequenceId << std::endl;
        if (i < messages.size() && messages[i].sequenceId == id) {
            msg = messages[i];
            
            pthread_mutex_lock(&mutex);
            messages.erase(messages.begin() + i);
            pthread_mutex_unlock(&mutex);
            
            //std::cout << "Message find: " << fin << std::endl;
            return msg;
        }
        i = i >= messages.size() ? 0 : i++;
        //std::cout << "Witing message... " << std::endl;
        usleep(20000); //20ms
    }
    //std::cout << "Message not find: " << fin << std::endl;
    return msg;
}

SpheroMessage Adaptor::receiveAsync(AsyncResponseIdCode id) {
    int i = 0;
    SpheroMessage msg;
    for (int fin = 0; fin < t; fin++) {
        //deviceReceive();
        //if (i < messages.size()) std::cout << "id: " << messages[i].idCode << fin << std::endl;
        //if (i < messages.size()) std::cout << "id: " << id << fin << std::endl;
        
        if (i < messages.size() && messages[i].idCode == id) {
            msg = messages[i];
            
            pthread_mutex_lock(&mutex);
            messages.erase(messages.begin() + i);
            pthread_mutex_unlock(&mutex);
            
            //std::cout << "Message find: " << fin << std::endl;
            return msg;
        }
        i = i >= messages.size() ? 0 : i++;
        //std::cout << "Witing message... " << std::endl;
        usleep(20000); //20ms
    }
    return msg;
}

bool Adaptor::bthSend(const std::vector<ubyte> data) {
    
    /*#ifdef SPHERO_DEBUG
        std::stringstream msg;
        msg << "[SEND][" << std::setw(3) << data.size() << "B] ";
        for (size_t idx = 0; idx < data.size(); ++idx) {
            msg << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(data[idx]) << " ";
        }
        std::cout << msg.str() << std::endl;
    #endif*/
    
    ssize_t bytesWrites = write(fd, reinterpret_cast<const char*>(data.data()), data.size());
    //std::cout << "Data write" << std::endl;

    if (bytesWrites >= 0){
        return true;
    } else {
        return false;
    }
}

bool Adaptor::bthReceive(std::vector<ubyte>& data, bool bBlocking) {

    data.reserve(2048);
    data.resize(2048);
    
    ssize_t bytesReads = read(fd, reinterpret_cast<char*>(data.data()), data.capacity());
    if (bytesReads < 0) return false;
    
    data.resize(bytesReads);
    /*std::cout << "Data read" << std::endl;
    
    #ifdef SPHERO_DEBUG
        std::stringstream mss;
        mss << "[RECV][" << std::setw(3) << data.size() << "B] ";
        for (size_t idx = 0; idx < data.size(); ++idx) {
            mss << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(data[idx]) << " ";
        }
        std::cout << mss.str() << std::endl;
    #endif*/
    
    if (bytesReads >= 0) return true;
    return false;
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
    
    //pthread_mutex_lock(&mutex);
    if (!bthSend(commandData)){
        //pthread_mutex_unlock(&mutex);
        return 0;
    }
    //pthread_mutex_unlock(&mutex);
    
    return seqId;
}

bool Adaptor::deviceReceive() {
    if (bthState() != SpheroState_Connected)
        return false;
    
    bool receiveState = false;
    std::vector<ubyte> receiveData;
    
    //std::cout << "Receiving data..." << std::endl;
    // Receive all pending data
    while (true) {
        receiveData.clear();
        receiveState = bthReceive(receiveData);
        
        //std::cout << "Estoy colgado..." << receiveData.size() << " " << receiveState << std::endl;
        
        if (receiveData.size() <= 0 || receiveState != true)
            break;
        
        receiveBuffer.insert(receiveBuffer.end(), receiveData.begin(), receiveData.end());
    }
    
    //std::cout << "Creating message..." << std::endl;
    //std::cout << "Data size: " << receiveBuffer.size() << std::endl;
    // Parse data to messages
    while (receiveBuffer.size() > SPHERO_RESPONSE_HEADER_SIZE) {
        if (receiveBuffer[0] != SPHERO_RESPONSE_SOP1_MASK){
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
        if (receiveBuffer[dataLength + 4] != checkSum){
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
        
        pthread_mutex_lock(&mutex);
        messages.push_back(newMessage);
        pthread_mutex_unlock(&mutex);
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
