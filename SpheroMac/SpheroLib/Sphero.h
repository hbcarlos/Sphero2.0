#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

#include "Commands.h"
#include "Messages.h"

//#define _WIN32
#ifdef _WIN32 // 32-bit or 64-bit Windows
	#include "WinAdaptor.h"
	#include <Windows.h>
#else // Linux or Mac OS
	#include "UnixAdaptor.h"
	#include <sys/time.h>
#endif // Linux or Mac OS

#define SPHERO_DEBUG
#ifdef SPHERO_DEBUG
    #include <sstream>
    #include <iostream>
    #include <iomanip>
#endif

class Sphero {
	private:
		std::string name;
		MsgSetDataStreaming stream;
		Adaptor adaptor;

	public:
		Sphero();
		Sphero(std::string n);

		// BthCommands
		BthState state();
		void connect();
		void disconnect();
		bool bthAvailable();
		bool bthDevicePaired();
		std::string bthGetDeviceAddress();

		// Core commands
		ResponseCode ping();
		ResponseCode setDeviceName(const std::string name);
		ResponseCode getBluetoothInfo(std::string &name, std::string &bta, std::string &idColors);
		ResponseCode getPowerState(MsgPowerState &res);
		ResponseCode setPowerNotification(const bool enable = true);
		ResponseCode sleep(const ushort secSleepDuration = 0xFFFF);
		ResponseCode setInactivityTimeout(const ushort secInactivityTimeout = 600);
		ResponseCode pollPacketTimes(int &delay, int &offset);

		// Sphero commands
		ResponseCode setHeading(const ushort heading);
		ResponseCode setStabilisation(const bool enable = true);
		ResponseCode setRotationRate(const ubyte rate);
		ResponseCode getChassisId(std::string &chassisId);
		ResponseCode selfLevel(const MsgSelfLevel op);
		ResponseCode setDataStreaming(const MsgSetDataStreaming op);
		ResponseCode configureCollisionDetection(const MsgConfigureCollisionDetection op);
		ResponseCode configureLocator(const MsgConfigureLocator op);
		ResponseCode setAccelerometerRange(const ubyte range);
		ResponseCode readLocator(MsgReadLocator &res);
		ResponseCode setRGBLedOutput(const ubyte red, const ubyte green, const ubyte blue, const bool persist);
		ResponseCode setBackLEDOutput(const ubyte intensity);
		ResponseCode getRGBLed(MsgGetRGBLed &res);
		ResponseCode roll(const ubyte speed, const ushort heading, const ubyte state);
		ResponseCode boost(const bool enable = true);
		ResponseCode setRAWMotorValues(const ubyte modeLeft, const ubyte powerLeft, const ubyte modeRight, const ubyte powerRight);
		ResponseCode setMotionTimeout(const ushort msecTimeout);
		ResponseCode setPermanentOptionFlags(const MsgOptionFlags op);
		ResponseCode getPermanentOptionFlags(MsgOptionFlags &res);
		ResponseCode setTemporaryOptionFlags(const bool op);
		ResponseCode getTemporaryOptionFlags(bool &res);
    
        // Async response commands
        ResponseCode asyncPowerNotification(int &bateryState);
        ResponseCode asyncSensorDataStreaming(MsgData &res);
        ResponseCode asyncPreSleepWarning10Sec();
        ResponseCode asyncCollisionDetected(MsgCollisionDetection &res);
        ResponseCode asyncSelfLevelResult(int &res);
        ResponseCode asyncGyroAxisLimitExceeded(MsgGyroAxisLimitExceeded &res);

    private:// Unused Commands
        ResponseCode getVersioning(MsgVersioning &res);
        ResponseCode setUARTTxLine(const bool enable = true);
        ResponseCode setAutoReconnect(const bool enable = true, const ubyte secTimeout = 30);
        ResponseCode getAutoReconnect(bool &flag, int &time);
        ResponseCode getVoltageTripPoints(double &voltLow, double &voltCritical);
        ResponseCode setVoltageTripPoints(const double voltLow = 700, const double voltCritical = 650);
        ResponseCode jumpToBootloader();
        ResponseCode performLevel1Diagnostics();
        ResponseCode performLevel2Diagnostics(MsgPerformLevel2Diagnostics &res);
        ResponseCode clearCouters();
        ResponseCode assignTimeValue(const uint timeValue = 0);
		
        ResponseCode getConfigurationBlock(const ubyte id);
        ResponseCode setSSBModifierBlock(const uint pwd, const CommandParameters data);
        ResponseCode setDeviceMode(const bool enableHackMode);
        ResponseCode setConfigurationBlock(const CommandParameters data);
        ResponseCode getDeviceMode(bool &res);
        ResponseCode getSSB();
		ResponseCode setSSB(const uint password, const CommandParameters data);
		ResponseCode refillBank(const ubyte type, int &res);
		ResponseCode buyConsumable(const ubyte id, const ubyte quantity, MsgBuyConsumable &res);
		ResponseCode useConsumable(const ubyte id, MsgUseConsumable &res);
		ResponseCode grantCores(const uint password, const uint quantity, const ubyte flags, int &res);
		ResponseCode addXP(const uint password, const uint quantity, int &res);
		ResponseCode levelUpAttribute(const uint password, const ubyte attrId, MsgLevelUpAttribute &res);
		ResponseCode getPasswordSeed(int &res);
		ResponseCode enableSSBAsyncMessages(const bool enable = true);
		
			// Macro commands
		ResponseCode runMacro(const ubyte id);
		ResponseCode saveTemporaryMacro(const CommandParameters macroData);
		ResponseCode saveMacro(const CommandParameters macroData);
		ResponseCode reinitMacroExecutive();
		ResponseCode abortMacro(int &res);
		ResponseCode getMacroStatus(MsgGetMacroStatus &res);
		ResponseCode setMacroParameter(const ubyte parameter, const ubyte valueOne, const ubyte value);
		ResponseCode appendMacroChunk(const CommandParameters macroData);
		
			// OrbBasic commands
		ResponseCode eraseOrbBasicStorage(const ubyte area);
		ResponseCode appendOrbBasicFragment(const ubyte area, const CommandParameters fragment);
		ResponseCode executeOrbBasicProgram(const ubyte area, const ushort startLine);
		ResponseCode abortOrbBasicProgram();
		ResponseCode submitValueToInputStatement(const uint value);
		ResponseCode commitRAMProgramToFlash();
    
        // Async response commands
        ResponseCode asyncLevel1DiagnosticResponse(std::string &res);
        ResponseCode asyncConfigBlockContents(std::vector<ubyte> &res);
        ResponseCode asyncMacroMarkers();
		ResponseCode asyncOrbBasicPrintMessage(std::string &res);
		ResponseCode asyncOrbBasicErrorMessageASCII(std::string &res);
		ResponseCode asyncOrbBasicErrorMessageBinary(std::string &res);
		ResponseCode asyncLevelUpNotification(MsgLevelUpNotification &res);
		ResponseCode asyncShieldDamageNotification(int &res);
		ResponseCode asyncXPUpdateNotification(int &res);
		ResponseCode asyncBoostUpdateNotification(int &res);
        ResponseCode asyncSpheroSoulData(std::vector<ubyte> &res);
};
