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
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1075304096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1075604096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.

Service UUID: 614504096128001289515552251
		Characteristic UUID: 1075704096128001289515552251
				Description:
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
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119330036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119430036451111141011041128339
				Description:
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
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831119930036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 5827103831529030036451111141011041128339
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic supports Write Without Response.
						The characteristic is writable.
				Descriptor UUID: 1050004096128001289515552251

Service UUID: 41185350645771553502910165165
		Characteristic UUID: 41155350645771553502910165165
				Description:
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
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
						The characteristic is notifiable.
				Descriptor UUID: 1049804096128001289515552251

Service UUID: 615404096128001289515552251 ASYC RESPONSE ??
		Characteristic UUID: 1079104096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1078904096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
		Characteristic UUID: 1078804096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1079304096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
		Characteristic UUID: 1079004096128001289515552251
				Description:
				Properties:
						The characteristic doesnÆt have any properties that apply.
						The characteristic is readable.
				Descriptor UUID: 1050004096128001289515552251
*/