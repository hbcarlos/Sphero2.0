#include <iostream>
#include <sstream>
#include <string>

#include "Device.h"
//#include "Scanner.h"

using namespace std;

int main(int argc, const char * argv[]) {
	std::cout << "Hello Sphero!\n";
	std::cout << "True: " << true << std::endl;
	std::cout << "False: " << false << std::endl;
	
	// MINI
	//std::string name = "SM-0AF9";
	//long addres = 242689762659065;

	// SPRK+
	std::string name = "SK-5FD4";
	uint64_t addres = 232370790817748;

	Device dev = Device(name, addres);
	
	std::cout << "Connect: " << std::endl;
	dev.connect();
	std::cout << std::endl;
	system("pause");

	//                       SOP1, SOP2, DID,  CID,  SEQ,  DLEN, data, CHK
	vector<uint8_t> data = { 0xFF, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x02 };
	dev.sentCommand(dev.generateCommand(0x00, 0x01, 0x01, {}));
	std::cout << "Waiting response..." << std::endl;

	system("pause");
	return(0);
}

/*
[RECV][  6B] FF FE 05 00 01 F9
[RECV][  6B] FF FE 14 00 01 EA
[RECV][  2B] 75 3E
*/