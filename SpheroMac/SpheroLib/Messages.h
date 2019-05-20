#pragma once
#include <vector>
#include "Commands.h"

/*From here forward the redundant fields in both transmit and receive
packets will be omitted for clarity; we assume the MRSP is 00h (for success),
SEQ is echoed and CHK is computed correctly both ways.*/

const ubyte SPHERO_REQUEST_SOP1_MASK = 0xFF;
const ubyte SPHERO_REQUEST_SOP2_MASK = 0xFC;
const ubyte SPHERO_REQUEST_SOP2_MASK_RESET = 0x02;
const ubyte SPHERO_REQUEST_SOP2_MASK_ANSWER = 0x01;
const ubyte SPHERO_RESPONSE_SOP1_MASK = 0xFF;
const ubyte SPHERO_RESPONSE_SOP2_MASK_ACK = 0xFF;
const ubyte SPHERO_RESPONSE_SOP2_MASK_ASYNC = 0xFE;
const ubyte SPHERO_RESPONSE_HEADER_SIZE = 0x05;

typedef ubyte SequenceId;
const ubyte INVALID_SEQUENCE_ID = 0;

typedef std::vector<ubyte> MessageData;
typedef ubyte Data;

enum ResponseCode {
	ResponseCode_OK = 0x00,
	ResponseCode_EGEN = 0x01,
	ResponseCode_ECHKSUM = 0x02,
	ResponseCode_EFRAG = 0x03,
	ResponseCode_EBAD_CMD = 0x04,
	ResponseCode_EUNSUPP = 0x05,
	ResponseCode_EBAD_MSG = 0x06,
	ResponseCode_EPARAM = 0x07,
	ResponseCode_EEXEC = 0x08,
	ResponseCode_EBAD_DID = 0x09,
	ResponseCode_MEM_BUSY = 0x0A,
	ResponseCode_BAD_PASSWORD = 0x0B,
	ResponseCode_POWER_NOGOOD = 0x31,
	ResponseCode_PAGE_ILLEGAL = 0x32,
	ResponseCode_FLASH_FAIL = 0x33,
	ResponseCode_MA_CORRUPT = 0x34,
	ResponseCode_MSG_TIMEOUT = 0x35
};

enum AsyncResponseIdCode {
	AsyncResponseId_Invalid = 0x00,
	AsyncResponseId_PowerNotification = 0x01,
	AsyncResponseId_Level1DiagnosticResponse = 0x02,
	AsyncResponseId_SensorDataStreaming = 0x03,
	AsyncResponseId_ConfigBlockContents = 0x04,
	AsyncResponseId_PreSleepWarning10Sec = 0x05,
	AsyncResponseId_MacroMarkers = 0x06,
	AsyncResponseId_CollisionDetected = 0x07,
	AsyncResponseId_orbBasicPrintMessage = 0x08,
	AsyncResponseId_orbBasicErrorMessageASCII = 0x09,
	AsyncResponseId_orbBasicErrorMessageBinary = 0x0A,
	AsyncResponseId_SelfLevelResult = 0x0B,
	AsyncResponseId_GyroAxisLimitExceeded = 0x0C,
	AsyncResponseId_SpheroSoulData = 0x0D,
	AsyncResponseId_LevelUpNotification = 0x0E,
	AsyncResponseId_ShieldDamageNotification = 0x0F,
	AsyncResponseId_XPUpdateNotification = 0x10,
	AsyncResponseId_BoostUpdateNotification = 0x11
};

enum Battery {
    Battery_Charging = 1,
    Battery_Ok = 2,
    Battery_Low = 3,
    Battery_Critical = 4
};

enum SelfLevelRoutine {
    SelfLevel_Unknown = 0,
    SelfLevel_TimedOut = 1,
    SelfLevel_SensorsError = 2,
    SelfLevel_Disabled = 3,
    SelfLevel_Aborted = 4,
    SelfLevel_ChargerNotFound = 5,
    SelfLevel_Success = 6
};

struct SpheroMessage {
	AsyncResponseIdCode idCode = AsyncResponseId_Invalid; // MRSP for asinc
	ResponseCode responseCode = ResponseCode_MSG_TIMEOUT; // MRSP
	SequenceId sequenceId = INVALID_SEQUENCE_ID; // SEQ

	MessageData data;
};

struct MsgVersioning {
	int RECV = 0; // This record version number, currently set to 02h. This will increase when more resources are added.
	int MDL = 0; // Model number; currently02h for Sphero
	int HW = 0; // Hardware version code (ranges 1 through 9)
	int MSAver = 0; // Main Sphero Application version byte
	int MSArev = 0; // Main Sphero Application revision byte
	float BL = 0; // Bootloader version in packed nibble format (i.e. 32h is version 3.2)
	float BAS = 0; // orbBasicversion in packed nibble format (i.e. 4.4)
	float MACRO = 0; // Macro executive version in packed nibble format (4.4)
	int APImaj = 0; // API major revision code this firmware implements
	int APImin = 0; // API minor revision code this firmware implements
};

struct MsgPowerState {
	int RecVer = 0; //Record version code –the following definition is for 01h
	int PowerState = 0; //01h = Battery Charging, 02h = Battery OK, 03h = Battery Low, 04h = Battery Critical
	float BattVoltage = 0.0; //Current battery voltage scaledin 100ths of a volt; 02EFh would be 7.51 volts(unsigned 16-bit value)
	int NumCharges = 0; //Number of battery recharges in the life of this Sphero (unsigned 16-bit value)
	int TimeSinceChg = 0;//Seconds awake since last recharge(unsigned 16-bit value)
};

struct MsgPerformLevel2Diagnostics {
    int RecVer = 0; //Record version code -the following definition is for 01h
    
    int Rx_Good = 0; //Good packets received (unsigned 32-bit value)
    int Rx_Bad_DID = 0; //Packets with a bad Device ID (unsigned 32-bit value)
    int Rx_Bad_DLEN = 0; //Packets with a bad data length (unsigned 32-bit value)
    int Rx_Bad_CID = 0; //Packets with a bad Command ID (unsigned 32-bit value)
    int Rx_Bad_CHK = 0; //Packets with a bad checksum (unsigned 32-bit value)
    int Rx_Buff_Ovr = 0; //Receive buffer overruns (unsigned 32-bit value)
    int Tx_Msgs = 0; //Messages transmitted (unsigned 32-bit value)
    int Tx_Buff_Ovr = 0; //Transmit buffer overruns (unsigned 32-bit value)
    
    int LastBootReason = 0; //Reason for last boot (8-bit value)
    std::vector<int> BootCounters; //16 different counts of boot reasons
    
    int ChargeCount = 0; //Charge cycles (unsigned 16-bit value)
    int SecondsSinceCharge = 0; //Awake time in seconds since last charge (unsigned 16-bit value)
    int SecondsOn = 0; //Life awake time in seconds (unsigned 32-bit value)
    int DistanceRolled = 0; //Distance rolled (unsigned 32-bit value)
    int SensorFailures = 0; //Count of I2C bus failures (unsigned 16-bit value)
    int GyroAdjustCount = 0; //Lifetime count of automatic GACs (unsigned 32-bit value)
};

struct MsgSelfLevel {
    // 0 aborts the routine if in progress. 1 starts the routine.
    bool startStop = false;
    // 0 just stops. 1 rotates to heading equal to beginning heading.
    bool finalAngle = false;
    // 0 stays awake after leveling. 1 goes to sleep after leveling.
    bool sleep = false;
    // 0 leaves control system off. 1 leaves control system on (after leveling).
    bool controlSystem = false;
    
    // 0 Use the default value. 1 to 90   Set the max angle for completion (in degrees)
    int angleLimit = 3;
    
    // 0 Use the default value. 1 to 255  Set maximum seconds to run the routine
    int timeout = 15;
    
    // 0 Use the default value. 1 to 255  Set the required Òtest for levelnessÓ time to 10*True Time (in milliseconds)
    int trueTime = 30;
};

struct MsgSetDataStreaming {
    // Divisor of the maximum sensor sampling rate
    int N = 0;
    // Number of sample frames emitted per packet
    int M = 0;
    // Bitwise selector of data sources to stream
    //uint mask = 0x00000000;
    // Packet count 1-255 (or 0 for unlimited streaming)
    int PCNT = 0;
    // Bitwise selector of more data sources to stream (optional)
    //uint mask2 = 0x00000000;
	
	// accelerometer axis X, raw, -2048 to 2047, 4mG
	bool accelXRaw = false;
	// accelerometer axis Y, raw, -2048 to 2047, 4mG
	bool accelYRaw = false;
	// accelerometer axis Z, raw, -2048 to 2047, 4mG
	bool accelZRaw = false;

	// gyro axis X, raw, -32768 to 32767, 0.068 degrees
	bool gyroXRaw = false;
	// gyro axis Y, raw, -32768 to 32767, 0.068 degrees
	bool gyroYRaw = false;
	// gyro axis Z, raw, -32768 to 32767, 0.068 degrees
	bool gyroZRaw = false;


	// right motor back EMF, raw, -32768 to 32767, 22.5 cm
	bool rightEMFRaw = false;
	// left motor back EMF, raw, -32768 to 32767, 22.5 cm
	bool leftEMFRaw = false;

	// left motor, PWM, raw, -2048 to 2047, duty cycle
	bool leftPWMRaw = false;
	// right motor, PWM, raw, -2048 to 2047, duty cycle
	bool rightPWMRaw = false;

	// IMU pitch angle, filtered -179 to 180 degrees
	bool pitchIMU = false;
	// IMU roll angle, filtered -179 to 180 degrees
	bool rollIMU = false;
	// IMU yaw angle, filtered -179 to 180 degrees
	bool yawIMU = false;

	// accelerometer axis X, filtered, -32768 to 32767, 1/4096 G
	bool accelX = false;
	// accelerometer axis Y, filtered, -32768 to 32767, 1/4096 G
	bool accelY = false;
	// accelerometer axis Z, filtered, -32768 to 32767, 1/4096 G
	bool accelZ = false;

	// gyro axis X, filtered, -20000 to 20000, 0.1 dps
	bool gyroX = false;
	// gyro axis Y, filtered, -20000 to 20000, 0.1 dps
	bool gyroY = false;
	// gyro axis Z, filtered, -20000 to 20000, 0.1 dps
	bool gyroZ = false;

	// right motor back EMF, filtered, -32768 to 32767, 22.5 cm
	bool rightEMF = false;
	// left motor back EMF, filtered, -32768 to 32767, 22.5 cm
	bool leftEMF = false;

	// Quaternion Q0, -10000 to 10000, 1/10000 Q
	bool q0 = false;
	// Quaternion Q1, -10000 to 10000, 1/10000 Q
	bool q1 = false;
	// Quaternion Q2, -10000 to 10000, 1/10000 Q
	bool q2 = false;
	// Quaternion Q3, -10000 to 10000, 1/10000 Q
	bool q3 = false;

	// Odometer X, -32768 to 32767, cm
	bool odometerX = false;
	// Odometer Y, -32768 to 32767, cm
	bool odometerY = false;

	// AccelOne, 0 to 8000, 1 mG
	bool accelOne = false;

	// Velocity X, -32768 to 32767, mm/s
	bool velocityX = false;
	// Velocity Y, -32768 to 32767, mm/s
	bool velocityY = false;
};

struct MsgData {
	// accelerometer axis X, raw, -2048 to 2047, 4mG
	int accelXRaw = 0;
	// accelerometer axis Y, raw, -2048 to 2047, 4mG
	int accelYRaw = 0;
	// accelerometer axis Z, raw, -2048 to 2047, 4mG
	int accelZRaw = 0;

	// gyro axis X, raw, -32768 to 32767, 0.068 degrees
	int gyroXRaw = 0;
	// gyro axis Y, raw, -32768 to 32767, 0.068 degrees
	int gyroYRaw = 0;
	// gyro axis Z, raw, -32768 to 32767, 0.068 degrees
	int gyroZRaw = 0;


	// right motor back EMF, raw, -32768 to 32767, 22.5 cm
	int rightEMFRaw = 0;
	// left motor back EMF, raw, -32768 to 32767, 22.5 cm
	int leftEMFRaw = 0;

	// left motor, PWM, raw, -2048 to 2047, duty cycle
	int leftPWMRaw = 0;
	// right motor, PWM, raw, -2048 to 2047, duty cycle
	int rightPWMRaw = 0;

	// IMU pitch angle, filtered -179 to 180 degrees
	int pitchIMU = 0;
	// IMU roll angle, filtered -179 to 180 degrees
	int rollIMU = 0;
	// IMU yaw angle, filtered -179 to 180 degrees
	int yawIMU = 0;

	// accelerometer axis X, filtered, -32768 to 32767, 1/4096 G
	int accelX = 0;
	// accelerometer axis Y, filtered, -32768 to 32767, 1/4096 G
	int accelY = 0;
	// accelerometer axis Z, filtered, -32768 to 32767, 1/4096 G
	int accelZ = 0;

	// gyro axis X, filtered, -20000 to 20000, 0.1 dps
	int gyroX = 0;
	// gyro axis Y, filtered, -20000 to 20000, 0.1 dps
	int gyroY = 0;
	// gyro axis Z, filtered, -20000 to 20000, 0.1 dps
	int gyroZ = 0;

	// right motor back EMF, filtered, -32768 to 32767, 22.5 cm
	int rightEMF = 0;
	// left motor back EMF, filtered, -32768 to 32767, 22.5 cm
	int leftEMF = 0;

	// Quaternion Q0, -10000 to 10000, 1/10000 Q
	int q0 = 0;
	// Quaternion Q1, -10000 to 10000, 1/10000 Q
	int q1 = 0;
	// Quaternion Q2, -10000 to 10000, 1/10000 Q
	int q2 = 0;
	// Quaternion Q3, -10000 to 10000, 1/10000 Q
	int q3 = 0;

	// Odometer X, -32768 to 32767, cm
	int odometerX = 0;
	// Odometer Y, -32768 to 32767, cm
	int odometerY = 0;

	// AccelOne, 0 to 8000, 1 mG
	int accelOne = 0;
	
	// Velocity X, -32768 to 32767, mm/s
	int velocityX = 0;
	// Velocity Y, -32768 to 32767, mm/s
	int velocityY = 0;
};

struct MsgConfigureCollisionDetection {
	// Detection method type to use. Supportedmethods are 01h, 02h, and 03h (see the collision
	// detection document for details). Use 00h to completely disable this service.
	int meth = 0;
	
	// An 8-bit settable threshold for the X (left/right) and Y (front/back) axes of Sphero.
	// A value of 00h disables the contribution of that axis.
	int xt = 0;
	int yt = 0;

	// An 8-bit settable speed value for the X and Y axes. This setting is ranged by the speed,
	// then added to Xt, Yt to generate the final threshold value.
	int xspd = 0;
	int yspd = 0;

	// An 8-bit post-collision dead timeto prevent retriggering; specifiedin 10ms increments.
	int dead = 0;
};

struct MsgConfigureLocator {
	bool autoCalibrate = false;
	int x = 0; // X position
	int y = 0; // Y position
	int yawTare = 0; // Angulo orientación respecto Y
};

struct MsgReadLocator {
	int x = 0; // X position
	int y = 0; // Y position
	int vx = 0; // X velociti
	int vy = 0; // y velociti
	int sog = 0; // speed over ground
};

struct MsgGetRGBLed {
	int red = 0;
	int green = 0;
	int blue = 0;
};

struct MsgOptionFlags {
	/*Set to prevent Sphero from immediately going to sleep when placed in the charger and connected
	over Bluetooth.*/
	bool sleepCharge = 0;
	/*Set to enable Vector Drive, that is,when Sphero is stopped and a new roll command is issued it
	achieves the heading before moving along it.*/
	bool vectorDrive = 0;
	/*Set to disable self-leveling when Sphero is inserted into the charger*/
	bool selfLevelingCharger = 0;
	/*Set to force the tail LED always on.*/
	bool forceTailLED = 0;
	/*Set to enable motion timeouts (seeDID 02h, CID 34h)*/
	bool motionTimeOuts = 0;
	/*Set to enable retail Demo Mode (when placed in the charger, ball runs a slow rainbow macro for
	60 minutes and then goes to sleep).*/
	bool retailDemoMode = 0;
	/*Set double tap awake sensitivity to Light*/
	bool awakeLight = 0;
	/*Set double tap awake sensitivity to Heavy*/
	bool awakeHeavy = 0;
	/*Enable gyro max asyncmessage(NOT SUPPORTED IN VERSION 1.47)*/
	bool gyroMaxAsync = 0;
};

struct MsgBuyConsumable {
	int QTY = 0;
	int cores = 0;
};

struct MsgUseConsumable {
	int id = 0; 
	int QTY = 0;
};

struct MsgLevelUpAttribute {
	int id = 0;
	int level = 0;
	int ptsRemaining = 0;
};

struct MsgGetMacroStatus {
	int id = 0;
	int cmdNum = 0;
};

struct MsgCollisionDetection {
	// Impact components normalized as a signed 16-bit value. Use these to determine the
	// direction of collision event. If you don't require this level of fidelity, the two
	// Magnitude fields encapsulate the same data in pre-processed format.
	int x = 0;
	int y = 0;
	int z = 0;

	// This bitfield specifies which axes had their trigger thresholds exceeded to generate
	// the event.  Bit 0 (01h) signifies the X axis and bit 1 (02h) the Y axis.
	int axis = 0;
	
	// This is the power that crossed the programming threshold Xt + Xs.
	int xMagnitude = 0;
	// This is the power that crossed the programming threshold Yt + Ys.
	int yMagnitude = 0;

	// The speed of Sphero when the impact was detected.
	int speed = 0;

	// An 8-bit post-collision dead timeto prevent retriggering; specifiedin 10ms increments.
	int timestamp = 0;
};

struct MsgGyroAxisLimitExceeded {
	bool x = 0;
	bool xn = 0;

	bool y = 0;
	bool yn = 0;
	
	bool z = 0;
	bool zn = 0;
};

struct MsgLevelUpNotification {
	// New robot level
	int level = 0;
	// The second is the total number of attribute points the user has to spend
	int attributes = 0;
};
