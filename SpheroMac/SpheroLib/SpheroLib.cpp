#include <iostream>
#include <unistd.h>
#include "Sphero.h"

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
}

int main(int argc, const char * argv[]){
    std::cout << "Hello Sphero!\n";
    
    //std::string name = "Sphero-RRO"; // Windows
    //std::string name = "/dev/rfcomm0"; // Linux
    std::string name = "/dev/tty.Sphero-RRO-RN-SPP"; // OSX
    
    Sphero sphero = Sphero(name);
    printStateBth(sphero.state());
    
    sphero.connect();
    printStateBth(sphero.state());
    std::cout << std::endl;
    
    if (sphero.state() != SpheroState_Connected) exit(-1);
	system("pause");
    
    //std::cout << "ping" << std::endl;
    //printStateMsg(sphero.ping());
    //std::cout << std::endl;
    
    /*MsgVersioning res;
    std::cout << "getVersioning" << std::endl;
    printStateMsg(sphero.getVersioning(res));
    std::cout << res.RECV << std::endl;
    std::cout << res.MDL << std::endl;
    std::cout << res.HW << std::endl;
    std::cout << res.MSAver << std::endl;
    std::cout << res.MSArev << std::endl;
    std::cout << res.BL << std::endl;
    std::cout << res.BAS << std::endl;
    std::cout << res.MACRO << std::endl;
    std::cout << res.APImaj << std::endl;
    std::cout << res.APImin << std::endl;
    std::cout << std::endl;*/
    
    //std::cout << "setUARTTxLine" << std::endl;
    //printStateMsg(sphero.setUARTTxLine(true));
    //std::cout << std::endl;
    
    /*std::cout << "setDeviceName" << std::endl;
    printStateMsg(sphero.setDeviceName("Sphero"));
    std::cout << std::endl;*/
    
    /*std::string name;
    std::string bta;
    std::string idColors;
    std::cout << "getBluetoothInfo" << std::endl;
    printStateMsg(sphero.getBluetoothInfo(name, bta, idColors));
    std::cout << res.Name << std::endl;
    std::cout << res.BTA << std::endl;
    std::cout << res.IDColors << std::endl;
    std::cout << std::endl;*/
    
    /*std::cout << "setAutoReconnect" << std::endl;
    printStateMsg(sphero.setAutoReconnect(true, 30));
    std::cout << std::endl;*/
    
    /*bool flag;
    int time;
    std::cout << "getAutoReconnect" << std::endl;
    printStateMsg(sphero.getAutoReconnect(flag, time));
    std::cout << flag << std::endl;
    std::cout << time << std::endl;
    std::cout << std::endl;*/
    
    /*MsgPowerState res;
    std::cout << "getPowerState" << std::endl;
    printStateMsg(sphero.getPowerState(res));
    std::cout << res.RecVer << std::endl;
    std::cout << res.PowerState << std::endl;
    std::cout << res.BattVoltage << std::endl;
    std::cout << res.NumCharges << std::endl;
    std::cout << res.TimeSinceChg << std::endl;
    std::cout << std::endl;*/
    
    /*std::cout << "setPowerNotification" << std::endl;
    printStateMsg(sphero.setPowerNotification(true));
    std::cout << std::endl;
    
    int bateryState;
    int cont = 0;
    while ( cont < 100 ){
        sphero.asyncPowerNotification(bateryState);
        cont++;
    }
    std::cout << "asyncPowerNotification" << std::endl;
    std::cout << bateryState << std::endl;
    std::cout << std::endl;*/
    
    /*std::cout << "sleep" << std::endl;
    printStateMsg(sphero.sleep(10));
    std::cout << std::endl;*/
    
    /*/ ****** NO FUNCIONA ******
    std::cout << "setVoltageTripPoints" << std::endl;
    printStateMsg(sphero.setVoltageTripPoints(6.76, 6.26));
    std::cout << std::endl;
    
    double voltLow;
    double voltCritical;
    std::cout << "getVoltageTripPoints" << std::endl;
    printStateMsg(sphero.getVoltageTripPoints(voltLow, voltCritical));
    std::cout << voltLow << std::endl;
    std::cout << voltCritical << std::endl;
    std::cout << std::endl;*/
    
    /*std::cout << "setInactivityTimeout" << std::endl;
    printStateMsg(sphero.setInactivityTimeout(600));
    std::cout << std::endl;*/
    
    /*std::cout << "performLevel1Diagnostics" << std::endl;
    printStateMsg(sphero.performLevel1Diagnostics());
    std::cout << std::endl;
    
    std::string res;
    int cont = 0;
    while ( cont < 100 ){
        sphero.asyncLevel1DiagnosticResponse(res);
        cont++;
    }
    std::cout << "asyncPowerNotification" << std::endl;
    std::cout << res << std::endl;
    std::cout << std::endl;*/
    
    /*MsgPerformLevel2Diagnostics res;
    std::cout << "performLevel2Diagnostics" << std::endl;
    printStateMsg(sphero.performLevel2Diagnostics(res));
    std::cout << res.RecVer << std::endl;
    std::cout << res.Rx_Good << std::endl;
    std::cout << res.Rx_Bad_DID << std::endl;
    std::cout << res.Rx_Bad_DLEN << std::endl;
    std::cout << res.Rx_Bad_CID << std::endl;
    std::cout << res.Rx_Bad_CHK << std::endl;
    std::cout << res.Rx_Buff_Ovr << std::endl;
    std::cout << res.Tx_Msgs << std::endl;
    std::cout << res.Tx_Buff_Ovr << std::endl;
    std::cout << res.LastBootReason << std::endl;
    std::cout << "BootCounters:" << std::endl;
    for (int i = 0; i < res.BootCounters.size(); i++) {
        std::cout << "\t" << res.BootCounters[i] << std::endl;
    }
    std::cout << res.ChargeCount << std::endl;
    std::cout << res.SecondsSinceCharge << std::endl;
    std::cout << res.SecondsOn << std::endl;
    std::cout << res.DistanceRolled << std::endl;
    std::cout << res.SensorFailures << std::endl;
    std::cout << res.GyroAdjustCount << std::endl;
    std::cout << std::endl;*/
    
    /*std::cout << "clearCouters" << std::endl;
    printStateMsg(sphero.clearCouters());
    std::cout << std::endl;*/
    
    /*std::cout << "assignTimeValue" << std::endl;
    printStateMsg(sphero.assignTimeValue(1000));
    std::cout << std::endl;*/
     
    /*int delay;
    int offset;
    std::cout << "pollPacketTimes" << std::endl;
    printStateMsg(sphero.pollPacketTimes(delay, offset));
    std::cout << "Offset: " << offset << "ms" << std::endl;
    std::cout << "Delay: " << delay << "ms" << std::endl;
    std::cout << std::endl;*/
    
    
    
    //****************************************************************************************/
    //*************************       Sphero commands         ********************************
    //****************************************************************************************/
    
    
    //std::cout << "LED:" << std::endl;
    //printStateMsg(sphero.setBackLEDOutput(250));
    //printStateMsg(sphero.setRGBLedOutput(0, 0, 0, true));
    //std::cout << std::endl;
    
    /*std::cout << "setHeading" << std::endl;
    printStateMsg(sphero.setHeading(0));
    std::cout << std::endl;*/
    
    /*std::cout << "setRotationRate" << std::endl;
    printStateMsg(sphero.setRotationRate(100));
    std::cout << std::endl;*/
    
    /*std::string chassisId;
    std::cout << "getChassisId" << std::endl;
    printStateMsg(sphero.getChassisId(chassisId));
    std::cout << chassisId << std::endl;
    std::cout << std::endl;*/
    
    /*MsgSelfLevel data;
    data.startStop = true;
    data.finalAngle = true;
    data.sleep = false;
    data.controlSystem = true;
    data.angleLimit = 3;
    data.timeout = 15;
    data.trueTime = 30;
    std::cout << "selfLevel" << std::endl;
    printStateMsg(sphero.selfLevel(data));
    
    int res = SelfLevel_Unknown;
    int cont = 0;
    while ( cont < 100 ){
        sphero.asyncSelfLevelResult(res);
        cont++;
    }
    std::cout << "asyncSelfLevelResult" << std::endl;
    std::cout << res << std::endl;
    std::cout << std::endl;*/
    
    /*MsgSetDataStreaming data;
    data.N = 20;            // Divisor of the maximum sensor sampling rate
    data.M = 1;             // Number of sample frames emitted per packet
    data.PCNT = 1;          // Packet count 1-255 (or 0 for unlimited streaming)
    data.accelXRaw = data.accelYRaw = data.accelZRaw = true;
    data.accelX = data.accelY = data.accelZ = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    MsgData res;
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tAccel X Raw: " << res.accelXRaw << std::endl;
    std::cout << "\tAccel Y Raw: " << res.accelYRaw << std::endl;
    std::cout << "\tAccel Z Raw: " << res.accelZRaw << std::endl;
    std::cout << "\tAccel X: " << res.accelX << std::endl;
    std::cout << "\tAccel Y: " << res.accelY << std::endl;
    std::cout << "\tAccel Z: " << res.accelZ << std::endl;
    std::cout << std::endl;
    
    data.accelXRaw = data.accelYRaw = data.accelZRaw = false;
    data.accelX = data.accelY = data.accelZ = false;
    data.gyroXRaw = data.gyroYRaw = data.gyroZRaw = true;
    data.gyroX = data.gyroY = data.gyroZ = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tGyro X Raw: " << res.gyroXRaw << std::endl;
    std::cout << "\tGyro Y Raw: " << res.gyroYRaw << std::endl;
    std::cout << "\tGyro Z Raw: " << res.gyroZRaw << std::endl;
    std::cout << "\tGyro X: " << res.gyroX << std::endl;
    std::cout << "\tGyro Y: " << res.gyroY << std::endl;
    std::cout << "\tGyro Z: " << res.gyroZ << std::endl;
    std::cout << std::endl;
    
    data.gyroXRaw = data.gyroYRaw = data.gyroZRaw = false;
    data.gyroX = data.gyroY = data.gyroZ = false;
    
    data.rightEMFRaw = data.leftEMFRaw = true;
    data.rightEMF = data.leftEMF = true;
    data.leftPWMRaw = data.rightPWMRaw = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tRight EMF Raw: " << res.rightEMFRaw << std::endl;
    std::cout << "\tLeft EMF Raw: " << res.leftEMFRaw << std::endl;
    std::cout << "\tRight EMF: " << res.rightEMF << std::endl;
    std::cout << "\tLeft EMF: " << res.leftEMF << std::endl;
    std::cout << "\tLeft PWM Raw: " << res.leftPWMRaw << std::endl;
    std::cout << "\tRight PWM Raw: " << res.rightPWMRaw << std::endl;
    std::cout << std::endl;
    
    data.rightEMFRaw = data.leftEMFRaw = false;
    data.rightEMF = data.leftEMF = false;
    data.leftPWMRaw = data.rightPWMRaw = false;
    
    data.pitchIMU = data.rollIMU = data.yawIMU = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tPitch IMU: " << res.pitchIMU << std::endl;
    std::cout << "\tRoll IMU: " << res.rollIMU << std::endl;
    std::cout << "\tYaw IMU: " << res.yawIMU << std::endl;
    std::cout << std::endl;
    
    data.pitchIMU = data.rollIMU = data.yawIMU = false;
    
    data.q0 = data.q1 = data.q2 = data.q3 = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tQ0: " << res.q0 << std::endl;
    std::cout << "\tQ1: " << res.q1 << std::endl;
    std::cout << "\tQ2: " << res.q2 << std::endl;
    std::cout << "\tQ3: " << res.q3 << std::endl;
    std::cout << std::endl;
    
    data.q0 = data.q1 = data.q2 = data.q3 = false;
    
    data.odometerX = data.odometerY = data.accelOne = data.velocityX = data.velocityY = true;
    std::cout << "setDataStreaming" << std::endl;
    printStateMsg(sphero.setDataStreaming(data));
    
    printStateMsg(sphero.asyncSensorDataStreaming(res));
    std::cout << "asyncSensorDataStreaming" << std::endl;
    std::cout << "\tOdometer X: " << res.odometerX << std::endl;
    std::cout << "\tOdometer Y: " << res.odometerY << std::endl;
    std::cout << "\tAccelOne: " << res.accelOne << std::endl;
    std::cout << "\tVelocity X: " << res.velocityX << std::endl;
    std::cout << "\tVelocity Y: " << res.velocityY << std::endl;
    std::cout << std::endl;*/
    
    /*
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
    // An 8-bit post-collision dead timeto prevent retriggering; specifiedin 10ms increments.
    data.dead = 100; // 1segundo
    std::cout << "configureCollisionDetection" << std::endl;
    printStateMsg(sphero.configureCollisionDetection(data));

    MsgCollisionDetection res;
    int cont=0;
    while ( cont < 20 ){
        cont++;
        sphero.asyncCollisionDetected(res);

        std::cout << "asyncCollisionDetected" << std::endl;
        std::cout << res.x << std::endl;
        std::cout << res.y << std::endl;
        std::cout << res.z << std::endl;
        std::cout << res.axis << std::endl;
        std::cout << res.xMagnitude << std::endl;
        std::cout << res.yMagnitude << std::endl;
        std::cout << res.speed << std::endl;
        std::cout << res.timestamp << std::endl;
        std::cout << std::endl;
    }*/
    
    /*MsgConfigureLocator data;
    data.autoCalibrate = 1;
    data.x = 0;
    data.y = 0;
    data.yawTare = 0;
    std::cout << "configureLocator" << std::endl;
    printStateMsg(sphero.configureLocator(data));*/
    
    /*ubyte data = 0x02;
    std::cout << "setAccelerometerRange" << std::endl;
    printStateMsg(sphero.setAccelerometerRange(data));*/
    
    /*MsgReadLocator dat;
    printStateMsg(sphero.setHeading(0));
    printStateMsg(sphero.readLocator(dat));
    std::cout << dat.x << std::endl;
    std::cout << dat.y << std::endl;
    std::cout << dat.vx << std::endl;
    std::cout << dat.vy << std::endl;
    std::cout << dat.sog << std::endl;
    std::cout << std::endl;*/
    
    /*ubyte red = 0;
    ubyte green = 0;
    ubyte blue = 0;
    bool persist = 0;
    std::cout << "setRGBLedOutput" << std::endl;
    printStateMsg(sphero.setRGBLedOutput(red, green, blue, persist));
    
    ubyte intensity = 10;
    std::cout << "setBackLEDOutput" << std::endl;
    printStateMsg(sphero.setBackLEDOutput(intensity));*/
    
    /*MsgGetRGBLed res;
    printStateMsg(sphero.getRGBLed(res));
    std::cout << res.red << std::endl;
    std::cout << res.green << std::endl;
    std::cout << res.blue << std::endl;
    std::cout << std::endl;*/
    
    /*ubyte speed = 100;
    ushort heading = 0;
    ubyte state = 0;
    std::cout << "roll" << std::endl;
    printStateMsg(sphero.roll(speed, heading, state));*/
    
    /*bool enable = 0;
    std::cout << "boost" << std::endl;
    printStateMsg(sphero.boost(enable));*/
    
    /*ubyte modeLeft = 0x00;
    ubyte powerLeft = 10;
    ubyte modeRight = 0x01;
    ubyte powerRight = 10;
    std::cout << "setRAWMotorValues" << std::endl;
    printStateMsg(sphero.setRAWMotorValues(modeLeft, powerLeft, modeRight, powerRight));*/
    
    /*ushort msecTimeout = 0;
    std::cout << "setMotionTimeout" << std::endl;
    printStateMsg(sphero.setMotionTimeout(msecTimeout));*/
    
    /*
    MsgOptionFlags res;
    printStateMsg(sphero.getPermanentOptionFlags(res));
    std::cout << res.sleepCharge << std::endl;
    std::cout << res.vectorDrive << std::endl;
    std::cout << res.selfLevelingCharger << std::endl;
    std::cout << res.forceTailLED << std::endl;
    std::cout << res.motionTimeOuts << std::endl;
    std::cout << res.retailDemoMode << std::endl;
    std::cout << res.awakeLight << std::endl;
    std::cout << res.awakeHeavy << std::endl;
    std::cout << res.gyroMaxAsync << std::endl;
    std::cout << std::endl;

    res.sleepCharge = 1;
    res.vectorDrive = 1;
    res.selfLevelingCharger = 1;
    res.forceTailLED = 0;
    res.motionTimeOuts = 0;
    res.retailDemoMode = 0;
    res.awakeLight = 1;
    res.awakeHeavy = 1;
    res.gyroMaxAsync = 1;

    printStateMsg(sphero.setPermanentOptionFlags(res));
    std::cout << std::endl;

    printStateMsg(sphero.getPermanentOptionFlags(res));
    std::cout << res.sleepCharge << std::endl;
    std::cout << res.vectorDrive << std::endl;
    std::cout << res.selfLevelingCharger << std::endl;
    std::cout << res.forceTailLED << std::endl;
    std::cout << res.motionTimeOuts << std::endl;
    std::cout << res.retailDemoMode << std::endl;
    std::cout << res.awakeLight << std::endl;
    std::cout << res.awakeHeavy << std::endl;
    std::cout << res.gyroMaxAsync << std::endl;
    std::cout << std::endl;*/
    
    /*bool res;
    printStateMsg(sphero.getTemporaryOptionFlags(res));
    std::cout << res << std::endl;
    std::cout << std::endl;

    res = 1;
    printStateMsg(sphero.setTemporaryOptionFlags(res));
    std::cout << std::endl;

    printStateMsg(sphero.getTemporaryOptionFlags(res));
    std::cout << res << std::endl;
    std::cout << std::endl;*/
    
    /*ubyte id = 0x00;
    std::cout << "getConfigurationBlock" << std::endl;
    printStateMsg(sphero.getConfigurationBlock(id));
    
    std::vector<ubyte> res;
    sphero.asyncConfigBlockContents(res);
    std::cout << "asyncConfigBlockContents" << std::endl;
    for (int i = 0; i < res.size(); i++) std::cout << char(res[i]);
    std::cout << std::endl;*/
    
    /*uint pwd = 0;
    CommandParameters op;
    std::cout << "setSSBModifierBlock" << std::endl;
    printStateMsg(sphero.setSSBModifierBlock(pwd, op));*/
    
    /*bool enableHackMode = 0;
    std::cout << "setDeviceMode" << std::endl;
    printStateMsg(sphero.setDeviceMode(enableHackMode));*/
    
    /*CommandParameters op;
    std::cout << "setConfigurationBlock" << std::endl;
    printStateMsg(sphero.setConfigurationBlock(op));*/
    
    /*bool res;
    std::cout << "getDeviceMode" << std::endl;
    printStateMsg(sphero.getDeviceMode(res));
    std::cout << res << std::endl;
    std::cout << std::endl;*/
    
    sphero.sleep(1111111111111111);
    sphero.disconnect();
    printStateBth(sphero.state());
	system("pause");
}
