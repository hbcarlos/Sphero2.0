#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>

#include "Device.h"

using namespace std;

int main(int argc, const char * argv[]) {
	std::cout << "Hello Sphero!\n";
	std::string name = "SK-5FD4";
	long addres = 232370790817748;
	std::cout << std::endl;

	Device dev = Device(name, addres);
	std::cout << dev.getName() << std::endl;
	//std::cout << dev.getAll() << std::endl;
	std::cout << std::endl;
	dev.searchChar();

	system("pause");
	return(0);
}

/*
Device:
232370790817748
SK-5FD4

Service UUID: 614404096128001289515552251
		Characteristic UUID: 1075204096128001289515552251
				Description: Nombre del dispositivo
							[RECV][  7B] 53 4B 2D 35 46 44 34
							SK-5FD4
							83754553706852
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1075304096128001289515552251
				Description:
							[RECV][  2B] 80 00
							Ç
							1280
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1075604096128001289515552251
				Description:
							[RECV][  8B] 08 00 10 00 00 00 AF 00
							 ?   »
							 80160001750
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.

Service UUID: 614504096128001289515552251
		Characteristic UUID: 1075704096128001289515552251
				Description:
							[RECV][  3B] 05 FF FF
							?
							5255255
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is indicatable.
				Descriptor UUID: 1049804096128001289515552251

Service UUID: 5827103831116830036451111141011041128339 COLISION??
		Characteristic UUID: 5827103831116930036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic supports Write Without Response.
						The characteristic is writable.
		Characteristic UUID: 5827103831117430036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is notifiable.
				Descriptor UUID: 1049804096128001289515552251

Service UUID: 5827103831118430036451111141011041128339 METODOS NORMALES??
		Characteristic UUID: 5827103831118530036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831118630036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119030036451111141011041128339
				Description:
							[RECV][  1B] D1
							Ð
							209
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
						The characteristic is notifiable.
				Descriptor UUID: 1050004096128001289515552251
				Descriptor UUID: 1049804096128001289515552251
		Characteristic UUID: 5827103831119130036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119230036451111141011041128339
				Description:
							[RECV][  1B] 32
							2
							50
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119330036451111141011041128339
				Description:
							[RECV][  2B] 0F 00
							?
							150
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119430036451111141011041128339
				Description:
							[RECV][  2B] AF 00
							»
							1750
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119730036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic supports Write Without Response.
						The characteristic is writable.
		Characteristic UUID: 5827103831119830036451111141011041128339
				Description:
							[RECV][  1B] 1E
							?
							30
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119930036451111141011041128339
				Description:
							[RECV][  1B] 00
							      
							0
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831529030036451111141011041128339
				Description:
							[RECV][  2B] 01 00
							?
							10
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251

Service UUID: 41185350645771553502910165165
		Characteristic UUID: 41155350645771553502910165165
				Description:
							[RECV][  1B] 01
							?
							1
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is writable.
		Characteristic UUID: 41195350645771553502910165165
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is writable.
		Characteristic UUID: 41165350645771553502910165165
				Description:
							[RECV][  0B]
							\n
							\n
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is notifiable.
				Descriptor UUID: 1049804096128001289515552251

Service UUID: 615404096128001289515552251 ASYC RESPONSE ??
		Characteristic UUID: 1079104096128001289515552251
				Description:
							[RECV][  6B] 41 00 00 00 00 00
							A
							6500000
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1078904096128001289515552251
				Description: MAC?
							[RECV][ 17B] 44 33 3A 35 37 3A 30 41 3A 37 31 3A 35 46 3A 44 34
							D3:57:0A:71:5F:D4
							6851585355584865585549585370586852
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 1078804096128001289515552251
				Description:
							[RECV][  3B] 35 30 00
							50
							53480
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1079304096128001289515552251
				Description: Nombre?
							[RECV][  6B] 53 70 68 65 72 6F
							Sphero
							83112104101114111
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1079004096128001289515552251
				Description: version?
							[RECV][  4B] 31 2E 35 35
							1.55
							49465353
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251


*/