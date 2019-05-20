#include <iostream>
#include <conio.h>

#include "Sphero.h"

std::stringstream mss;

static void printStateBth(BthState state) {
    switch (state) {
        case SpheroState_None: { std::cout << "Sphero not initialized" << std::endl; break; }
        case SpheroState_Error_BluetoothError: { std::cout << "Error - Couldn't initialize Bluetooth stack" << std::endl; break; }
        case SpheroState_Error_BluetoothUnavailable: { std::cout << "Error - No valid Bluetooth adapter found" << std::endl; break; }
        case SpheroState_Error_NotPaired: { std::cout << "Error - Specified Sphero not Paired" << std::endl; break; }
        case SpheroState_Error_ConnectionFailed: { std::cout << "Error - Connecting failed" << std::endl; break; }
        case SpheroState_Disconnected: { std::cout << "Sphero disconnected" << std::endl; break; }
        case SpheroState_Connected: { std::cout << "Sphero connected" << std::endl;  break; }
    }
}

static void printStateMsg(ResponseCode state) {
    switch (state) {
        case ResponseCode_OK: { std::cout << "Command succeeded" << std::endl; break; }
        case ResponseCode_EGEN: { std::cout << "General, non-specific error" << std::endl; break; }
        case ResponseCode_ECHKSUM: { std::cout << "Received checksum failure" << std::endl; break; }
        case ResponseCode_EFRAG: { std::cout << "Received command fragment" << std::endl; break; }
        case ResponseCode_EBAD_CMD: { std::cout << "Unknown command ID" << std::endl; break; }
        case ResponseCode_EUNSUPP: { std::cout << "Command currently unsupported" << std::endl; break; }
        case ResponseCode_EBAD_MSG: { std::cout << "Bad message format" << std::endl; break; }
        case ResponseCode_EPARAM: { std::cout << "Parameter value(s) invalid" << std::endl; break; }
        case ResponseCode_EEXEC: { std::cout << "Failed to execute command" << std::endl; break; }
        case ResponseCode_EBAD_DID: { std::cout << "Unknown Device ID" << std::endl; break; }
        case ResponseCode_MEM_BUSY: { std::cout << "Generic RAM access needed but it is busy" << std::endl; break; }
        case ResponseCode_BAD_PASSWORD: { std::cout << "Supplied password incorrect" << std::endl; break; }
        case ResponseCode_POWER_NOGOOD: { std::cout << "Voltage too low for reflash operation" << std::endl; break; }
        case ResponseCode_PAGE_ILLEGAL: { std::cout << "Illegal page number provided" << std::endl; break; }
        case ResponseCode_FLASH_FAIL: { std::cout << "Page did not reprogram correctly" << std::endl; break; }
        case ResponseCode_MA_CORRUPT: { std::cout << "Main Application corrupt" << std::endl; break; }
        case ResponseCode_MSG_TIMEOUT: { std::cout << "Msg state machine timed out" << std::endl; break; }
    }

	system("pause");
}

static void encenderLEDs(Sphero *sphero) {
	std::string str;
	std::cout << "Introduce el color del led principal (RGB 0-255)" << std::endl;
	std::cout << "RED: "; std::getline(std::cin, str, '\n');
	ubyte red = std::atoi(str.c_str());

	std::cout << "GREEN: "; std::getline(std::cin, str, '\n');
	ubyte green = std::atoi(str.c_str());

	std::cout << "BLUE: "; std::getline(std::cin, str, '\n');
	ubyte blue = std::atoi(str.c_str());
	std::cout << std::endl;

	
	bool persistente = true;
	sphero->setRGBLedOutput(red, green, blue, persistente);

	system("pause");
}

static void encenderLEDTrasero(Sphero *sphero) {
	std::string str;
	std::cout << "Introduce la intensidad del led trasero (0-255)" << std::endl;
	std::cout << "Intensidad: "; std::getline(std::cin, str, '\n');
	ubyte intensity = std::atoi(str.c_str());
	std::cout << std::endl;
	sphero->setBackLEDOutput(intensity);

	system("pause");
}

static void leerPosicion(Sphero *sphero) {
	MsgReadLocator res;
	sphero->readLocator(res);
	std::cout << "Posición" << res.x << std::endl;
	std::cout << "X: " << res.x << std::endl;
	std::cout << "Y: " << res.y << std::endl;
	std::cout << "Velocidad X: " << res.vx << std::endl;
	std::cout << "Velocidad Y: " << res.vy << std::endl;
	std::cout << "SOG: " << res.sog << std::endl;
	std::cout << std::endl;

	system("pause");
}

static void notificacionesColision(Sphero *sphero) {

	MsgConfigureCollisionDetection data;
	// Detection method type to use. Supportedmethods are 01h, 02h, and 03h (see the collision
	// detection document for details). Use 00h to completely disable this service.
	data.meth = 1;
	// An 8-bit settable threshold for the X (left/right) and Y (front/back) axes of Sphero.
	// A value of 00h disables the contribution of that axis.
	data.xt = 100;
	data.yt = 100;
	// An 8-bit settable speed value for the X and Y axes. This setting is ranged by the speed,
	// then added to Xt, Yt to generate the final threshold value.
	data.xspd = 100;
	data.yspd = 100;
	// An 8-bit post-collision dead time to prevent retriggering; specifiedin 10ms increments.
	data.dead = 100; // 1segundo
	sphero->configureCollisionDetection(data);
}

static void activarStreaming(Sphero *sphero) {
	MsgSetDataStreaming data;
	data.N = 20;            // Divisor of the maximum sensor sampling rate
	data.M = 1;             // Number of sample frames emitted per packet
	data.PCNT = 4;          // Packet count 1-255 (or 0 for unlimited streaming)
	data.accelXRaw = true;
	data.accelYRaw = true;
	data.accelZRaw = true;
	data.q0 = true;
	data.q1 = true;
	data.q2 = true;
	data.q3 = true;
	printStateMsg(sphero->setDataStreaming(data));
}

static void juego(Sphero *sphero) {

	std::stringstream msg;
	msg << "Controles:" << std::endl;
	msg << "\t+ ENTER: Salir." << std::endl;
	msg << "\t+ SPACE: Freno de mano." << std::endl;
	msg << "\t+ R/r: Girar 180º." << std::endl;
	msg << "\t+ W/w: Acelerar." << std::endl;
	msg << "\t+ S/s: Frenar." << std::endl;
	msg << "\t+ D/d: Girar a la derecha." << std::endl;
	msg << "\t+ A/a: Girar a la izquierda." << std::endl;
	msg << std::endl;

	ubyte speed = 50;
	ushort heading = 0;
	ubyte state = 0;

	while (true) {
		system("cls");
		std::cout << msg.str() << std::endl;
		std::cout << "Speed: " << (int)speed << std::endl;
		std::cout << "Heading: " << (int)heading << std::endl;
		std::cout << "State: " << (int)state << std::endl;

		switch (_getch()) {
		case 13: std::cout << "EXIT" << std::endl; return; break;
		case ' ':
			state = 0;
			break;

		case 'R':
		case 'r':
			std::cout << "R" << std::endl;
			heading = 180;
			state = 0;
			break;

		case 'W':
		case 'w':
			std::cout << "VK_UP" << std::endl;
			speed++;
			state = 1;
			break;

		case 'S':
		case 's':
			std::cout << "VK_DOWN" << std::endl;
			speed--;
			state = 1;
			break;

		case 'D':
		case 'd':
			std::cout << "VK_RIGHT" << std::endl;
			heading = heading == 360 ? 0 : heading + 10;
			state = 1;
			break;

		case 'A':
		case 'a':
			std::cout << "VK_LEFT" << std::endl;
			heading = heading == 0 ? 360 : heading - 10;
			state = 1;
			break;
		default: break;
		}

		sphero->roll(speed, heading, state);
	}

	system("pause");
}

static void control(Sphero *sphero) {

	std::stringstream msg;
	msg << "Controles:" << std::endl;
	msg << "\t+ ENTER: Salir." << std::endl;
	msg << "\t+ SPACE: Freno." << std::endl;
	msg << "\t+ W/w: Acelerar." << std::endl;
	msg << "\t+ S/s: Marcha atras." << std::endl;
	msg << "\t+ D/d: Girar a la derecha." << std::endl;
	msg << "\t+ A/a: Girar a la izquierda." << std::endl;
	msg << std::endl;

	ubyte modeLeft = 0x01;
	ubyte powerLeft = 100;
	ubyte modeRight = 0x01;
	ubyte powerRight = 100;

	while (true) {
		system("cls");
		std::cout << msg.str() << std::endl;
		std::cout << "Left: " << (int)modeLeft << " " << (int)powerLeft << std::endl;
		std::cout << "Right: " << (int)modeRight << " " << (int)powerRight << std::endl;

		switch (_getch()) {
			case 13: std::cout << "EXIT" << std::endl; return; break;
			case ' ':
				modeLeft = 0x03;
				modeRight = 0x03;
				break;

			case 'W':
			case 'w':
				std::cout << "VK_UP" << std::endl;
				modeLeft = 0x01;
				modeRight = 0x01;
				powerLeft = 100;
				powerRight = 100;
				break;

			case 'S':
			case 's':
				std::cout << "VK_DOWN" << std::endl;
				modeLeft = 0x02;
				modeRight = 0x02;
				powerLeft = 100;
				powerRight = 100;
				break;

			case 'D':
			case 'd':
				std::cout << "VK_RIGHT" << std::endl;
				powerLeft = 100;
				powerRight = 80;
				break;

			case 'A':
			case 'a':
				std::cout << "VK_LEFT" << std::endl;
				powerLeft = 80;
				powerRight = 100;
				break;
			default: break;
		}

		sphero->setRAWMotorValues(modeLeft, powerLeft, modeRight, powerRight);
	}

	system("pause");
}

static void asyncNotificaciones(Sphero *sphero) {
	int bateryState;
	if (sphero->asyncPowerNotification(bateryState) == ResponseCode_OK) {
		std::cout << "Bateria: " << bateryState << std::endl;
		std::cout << std::endl;
	}
	
	MsgCollisionDetection col;
	if (sphero->asyncCollisionDetected(col) == ResponseCode_OK) {
		std::cout << "Colision: " << std::endl;
		std::cout << "X: " << col.x << std::endl;
		std::cout << "Y: " << col.y << std::endl;
		std::cout << "Z: " << col.z << std::endl;
		std::cout << "Axis: " << col.axis << std::endl;
		std::cout << "X Magnitude: " << col.xMagnitude << std::endl;
		std::cout << "Y Magnitude: " << col.yMagnitude << std::endl;
		std::cout << "Speed: " << col.speed << std::endl;
		std::cout << "Timestamp: " << col.timestamp << std::endl;
		std::cout << std::endl;
	}

	MsgData data;
	printStateMsg(sphero->asyncSensorDataStreaming(data));
	if (sphero->asyncSensorDataStreaming(data) == ResponseCode_OK) {
		std::cout << "Data streaming:" << std::endl;
		std::cout << "\tAccel X:" << data.accelXRaw << std::endl;
		std::cout << "\tAccel Y:" << data.accelYRaw << std::endl;
		std::cout << "\tAccel Z:" << data.accelZRaw << std::endl;
		std::cout << "\tQ0:" << data.q0 << std::endl;
		std::cout << "\tQ1:" << data.q1 << std::endl;
		std::cout << "\tQ2:" << data.q2 << std::endl;
		std::cout << "\tQ3:" << data.q3 << std::endl;
		std::cout << std::endl;
	}

	system("pause");
}

int main(int argc, const char * argv[]) {
	std::cout << "Hello Sphero!\n";
	std::string name = "Sphero-RRO";

	Sphero sphero = Sphero(name);
	printStateBth(sphero.state());

	sphero.connect();
	printStateBth(sphero.state());
	std::cout << std::endl;

	system("pause");
	if (sphero.state() != SpheroState_Connected) exit(-1);

	std::cout << std::endl;
	std::cout << "Configuramos el sphero para usarlo" << std::endl;
	std::cout << "**********************************" << std::endl;
	
	sphero.setBackLEDOutput(0);
	sphero.setRGBLedOutput(0, 0, 0, true);
	sphero.setAccelerometerRange(0x02);
	sphero.setRotationRate(100);
	
	MsgConfigureLocator data;
	data.autoCalibrate = 1;
	data.x = 0;
	data.y = 0;
	data.yawTare = 0;
	sphero.configureLocator(data);
	
	MsgOptionFlags res;
	res.sleepCharge = 1;
	res.vectorDrive = 1;
	res.selfLevelingCharger = 1;
	res.forceTailLED = 0;
	res.motionTimeOuts = 1;
	res.retailDemoMode = 0;
	res.awakeLight = 1;
	res.awakeHeavy = 0;
	res.gyroMaxAsync = 0;
	sphero.setPermanentOptionFlags(res);

	std::cout << "Usa SPACE para rodar el sphero hasta poner" << std::endl;
	std::cout << "la luz detras y pulsa ENTER para salir." << std::endl;
	std::cout << std::endl;

	int t = 0;
	int grados = 0;
	sphero.setBackLEDOutput(255);
	while (t != 13) {
		t = _getch();
		if (t == VK_SPACE) sphero.setHeading(10);
    }
	sphero.setBackLEDOutput(0);
	
	mss << "Ahora a jugar" << std::endl;
	mss << "*************" << std::endl;
	mss << "Pulsa ENTER para salir." << std::endl;
	mss << std::endl;

	mss << "Opciones:" << std::endl;
	mss << "\t+ T/t: Probar conexión (Ping)." << std::endl;
	mss << "\t+ L/l: Encender led." << std::endl;
	mss << "\t+ H/h: Encender led trasero." << std::endl;
	mss << "\t+ P/p: Leer posición." << std::endl;
	mss << "\t+ N/n: Activar notificaciones de bateria." << std::endl;
	mss << "\t+ C/c: Activar notificaciones de colisión." << std::endl;
	mss << "\t+ D/d: Activar streaming de datos." << std::endl;
	mss << "\t+ A/a: Comprobar mensages." << std::endl;
	mss << "\t+ J/j: Modo juego." << std::endl;
	mss << "\t+ B/b: Modo control." << std::endl;
	mss << std::endl;

	t = 0;
	while (t != 13) {

		system("cls");
		std::cout << mss.str() << std::endl;

		t = _getch();
		switch (t) {
			case 'T': 
			case 't': printStateMsg(sphero.ping()); break;
		
			case 'L': 
			case 'l': encenderLEDs(&sphero); break;
				
			case 'H':
			case 'h': encenderLEDTrasero(&sphero); break;

			case 'P':
			case 'p': leerPosicion(&sphero); break;
		
			case 'N':
			case 'n': sphero.setPowerNotification(true); break;
		
			case 'C':
			case 'c': notificacionesColision(&sphero); break;
		
			case 'D':
			case 'd': activarStreaming(&sphero); break;

			case 'A':
			case 'a': asyncNotificaciones(&sphero); break;

			case 'J':
			case 'j': juego(&sphero); break;

			case 'B':
			case 'b': control(&sphero); break;
			
			default: break;
		}
	}
    
	sphero.sleep(1111111111111111);
    sphero.disconnect();
    printStateBth(sphero.state());
	system("pause");
}
