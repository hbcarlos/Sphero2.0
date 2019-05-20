#pragma once
#include "Sphero.h"

Sphero::Sphero() {
}
Sphero::Sphero(std::string n) {
	name = n;
	adaptor = Adaptor(name);
}

// BthCommands
BthState Sphero::state() {
	return adaptor.bthState();
}
void Sphero::connect() {
	adaptor.bthConnect();
}
void Sphero::disconnect() {
	adaptor.bthDisconnect();
}
bool Sphero::bthAvailable() {
	return adaptor.bthAvailable();
}
bool Sphero::bthDevicePaired() {
	return adaptor.bthDevicePaired();
}
std::string Sphero::bthGetDeviceAddress() {
	return adaptor.bthGetAddress();
}


//*******************************************************************************************************/
//************************************        Core commands         *************************************
//*******************************************************************************************************/
ResponseCode Sphero::ping() {
	/*The Ping command is used to verify both a solid data link with the Client
	and that Sphero is awake and dispatching commands.Even though Ping is neither
	a set or getformat command, it still enjoys a Simple Response. */

	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_PING);
	SpheroMessage msg = adaptor.receive(seq);
    //std::cout << "Ping: " << msg.responseCode << std::endl;
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getVersioning(MsgVersioning &res) {
	/*The Get Versioning command returns a whole slew of software
	and hardware information. It’s useful if your Client Application
	requires a minimum version number of some resource within Sphero
	in order to operate. The data recordstructure is comprised of fieldsfor
	each resource that encodesthe version number according to the specified format*/

	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_VERSION);
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
		
    //std::cout << msg.data.size() << std::endl;
    res.RECV = static_cast<int>(msg.data[0]);
    res.MDL = static_cast<int>(msg.data[1]);
    res.HW = static_cast<int>(msg.data[2]);
    res.MSAver = static_cast<int>(msg.data[3]);
    res.MSArev = static_cast<int>(msg.data[4]);
    
    float n = (msg.data[5] & 0xf0) >> 4;
    float d = (msg.data[5] & 0x0f) < 10 ? (msg.data[5] & 0x0f) / 10.0 : (msg.data[5] & 0x0f) / 100.0;
    res.BL = n + d;
    n = (msg.data[6] & 0xf0) >> 4;
    d = (msg.data[6] & 0x0f) < 10 ? (msg.data[6] & 0x0f) / 10.0 : (msg.data[6] & 0x0f) / 100.0;
    res.BAS = n + d;
    n = (msg.data[7] & 0xf0) >> 4;
    d = (msg.data[7] & 0x0f) < 10 ? (msg.data[7] & 0x0f) / 10.0 : (msg.data[7] & 0x0f) / 100.0;
    res.MACRO = n + d;

    //res.APImaj = static_cast<int>(msg.data[8]);
    //res.APImin static_cast<int>(msg.data[9]);
    
	return ResponseCode_OK;
}

ResponseCode Sphero::setUARTTxLine(const bool enable) {
	/*This is a factory command that either enables or disables the CPU's
	UART transmit line so that another physicallyconnected client can
	configure the Bluetooth module. The receive line is always listening,
	which is how you can re-enable the Tx line later. Or just reboot as this
	setting is not persistent.*/
    
	ubyte flag_enable = enable ? 0x01 : 0x00;
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_CONTROL_UART_TX, { flag_enable });
	
    SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setDeviceName(const std::string name) {
	/*This formerly reprogrammed the Bluetooth module to advertise with a
	different name, but this is no longer the case. This assigned name is
	held internally and produced as part of the Get Bluetooth Info service below.
	Names are clipped at 48 characters in length to support UTF-8 sequences;
	you can send something longer but the extra will be discarded.This field defaults
	to the Bluetooth advertising name
	
	To alter the Bluetooth advertising name from the standard Sphero-RGB pattern you
	will need to $$$ into the RN-42 within 60 seconds after power up, issue the command
	SN,mynewname and finish withr,1 to reboot the module*/

	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SET_BT_NAME, std::vector<ubyte>(name.begin(), name.end()));
	
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getBluetoothInfo(std::string &name, std::string &bta, std::string &idColors) {
	/*This returns a structure containing the textual name in ASCII of
	the ball (defaults to the Bluetooth advertising name but can be changed),
	the Bluetooth address in ASCII and the ID colors the ball blinks when not connected
	to a smartphone.
	
	The ASCII name field is padded with zeros to its maximum size.
	
	This is provided as a courtesy for Clients that have don’t have a method
	to interrogate their underlying Bluetooth stack for this information*/
	
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_GET_BT_NAME);
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream n;
    for (int j = 0; j < 16; j++) n << char(msg.data[j]);
	name = n.str();

	std::stringstream b;
	for (int j = 16; j < 26; j+=2) b << char(msg.data[j]) << char(msg.data[j+1]) << ":";
	b << char(msg.data[26]) << char(msg.data[27]);
	bta = b.str();

	std::stringstream color;
	for (int j = 29; j < 32; j++) color << char(msg.data[j]);
	idColors = color.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::setAutoReconnect(const bool enable, const ubyte secTimeout) {
	/*This configures the control of the Bluetooth module in its attempt to
	automatically reconnect with the last mobile Apple device. This is a courtesy behavior
	since the Apple Bluetooth stack doesn't initiate automatic reconnection on its own.
	
	The two parameters are simple: flag is00h to disable or 01h to enable, and time is
	the number of seconds after power-up in which to enable auto reconnectmode.
	For example, if time = 30 then the module will be attempt reconnecting30 secondsafte
	waking up.(refer to RN-APL-EVAL pg.7 for more info)*/

	ubyte flag_enable = enable ? 0x01 : 0x00;
	std::vector<ubyte> data;
	data.push_back(flag_enable);
	data.push_back(secTimeout);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SET_AUTO_RECONNECT, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getAutoReconnect(bool &flag, int &time) {
	/*This returnsthe Bluetooth auto reconnect values as defined in the “Set Auto Reconnect” command.*/
	
    SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_GET_AUTO_RECONNECT);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	flag = static_cast<int>(msg.data[0]);
	time = static_cast<int>(msg.data[1]);

	return ResponseCode_OK;
}

ResponseCode Sphero::getPowerState(MsgPowerState &res) {
	/*This returns the current power state and some additional
	parameters to theClient. They are detailed below.*/
	
    SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_GET_PWR_STATE);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.RecVer = static_cast<int>(msg.data[0]);
	res.PowerState = static_cast<int>(msg.data[1]);
	res.BattVoltage = ((msg.data[2] << 8) + msg.data[3]) / 100.0;
	res.NumCharges = static_cast<int>(msg.data[4] + msg.data[5]);
	res.TimeSinceChg = static_cast<int>(msg.data[6] + msg.data[7]);

	return ResponseCode_OK;
}

ResponseCode Sphero::setPowerNotification(const bool enable) {
    /*This enables Sphero to asynchronously notify the Client periodically
	with the power state or immediately when the power manager detects a statechange.
	Timed notifications arrive every 10 seconds until they're explicitly disabled
	or Sphero is unpaired. The flag is as you would expect, 00h to disable and 01h
	to enable. This setting is volatile and therefore not retained across sleep cycles*/

	ubyte flag_enable = enable ? 0x01 : 0x00;
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SET_PWR_NOTIFY, { flag_enable });
	
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::sleep(const ushort secSleepDuration) {
	/*This command puts Sphero to sleep immediately. There are three optional parameters that program the
	robot for future actions:

		Wakeup: The number of seconds for Sphero to sleep for and then automatically
		reawaken. Zero does not program a wakeup interval, so he sleeps forever.
		FFFFh attempts to put him into deep sleep (if supported in hardware) and
		returns an error if the hardware does notsupport it.

		MacroIf non-zero, Sphero will attempt to run this macro ID upon wakeup.
		
		orbBasicIf non-zero, Sphero will attempt to run an orbBasic program in Flash from 
		this line number.*/
    
	std::vector<ubyte> data;
	ushort net_secSleepDuration = htons(secSleepDuration);
	ushort net_wakeupOrbBasicMacro = htons(0);
	data.push_back((net_secSleepDuration >> (8 * 0)) & 0xff);
	data.push_back((net_secSleepDuration >> (8 * 1)) & 0xff);
	data.push_back(0);
	data.push_back((net_wakeupOrbBasicMacro >> (8 * 0)) & 0xff);
	data.push_back((net_wakeupOrbBasicMacro >> (8 * 1)) & 0xff);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SLEEP, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getVoltageTripPoints(double &voltLow, double &voltCritical) {
	/*This returns the voltage trip points for what Sphero considers
	Low battery and Critical battery. The values are expressed in 100ths
	of a volt, so the defaults of 7.00V and 6.50V respectively are returned
	as 700 and 650.*/
    
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_GET_POWER_TRIPS);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    
    //Record version code the following definition is for 01h
	voltLow = static_cast<int>((msg.data[0] << 8) + msg.data[1]) / 100.0;
    //High-level state of the power systemas concluded by the power manager
	voltCritical = static_cast<int>((msg.data[2] << 8) + msg.data[3]) / 100.0;

	return ResponseCode_OK;
}

ResponseCode Sphero::setVoltageTripPoints(const double voltLow, const double voltCritical) {
	/*This assigns the voltage trip points for Low and Critical battery voltages. The values are specified in
	100ths of a voltand the limitations on adjusting these away from their defaults are:
	
	+Vlow must be in the range 675 to 725(±25)
	+Vcrit must be in the range 625 to 675(±25)
	+There must be 0.25V of separation between the two values
	
	Shifting these values too low could result in very little warning before Sphero forces himself to sleep,
	depending on the age and history of the battery pack.So be careful*/
    
	std::vector<ubyte> data;
    
    std::cout << "net_voltLow: " << ((int)(voltLow * 100) & 0xffff) << std::endl;
    std::cout << "net_voltCritical: " << ((int)(voltCritical * 100) & 0xffff) << std::endl;
    
    ushort net_voltLow = voltLow * 100;//htons(voltLow * 100);
    ushort net_voltCritical = voltCritical * 100;//htons(voltCritical * 100);
    std::cout << "net_voltLow: " << net_voltLow << std::endl;
    std::cout << "net_voltCritical: " << net_voltCritical << std::endl;
    
	data.push_back((net_voltLow >> 8) & 0x00ff);
	data.push_back(net_voltLow & 0x00ff);
	data.push_back((net_voltCritical >> 8) & 0x00ff);
	data.push_back(net_voltCritical & 0x00ff);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SET_POWER_TRIPS, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setInactivityTimeout(const ushort secInactivityTimeout) {
	/*To save battery power, Sphero normally goes to sleep after a period of inactivity. From the factory this
	value is set to 600 seconds (10 minutes) but this API command can alter it to any value of 60 seconds or
	greater.
	
	The inactivity timer is reset every time an API command is received over Bluetooth or a shell command
	is executed in User Hack mode. In addition, the timer is continually reset when a macro is running unless
	the MF_STEALTH flag is set, and the same for orbBasic unless the BF_STEALTH flag is set.*/

	std::vector<ubyte> data;
	ushort net_secInactivityTimeout = htons(secInactivityTimeout);
	data.push_back((net_secInactivityTimeout >> (8 * 0)) & 0xff);
	data.push_back((net_secInactivityTimeout >> (8 * 1)) & 0xff);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_SET_INACTIVE_TIMER, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::jumpToBootloader() {
	/*This command requests a jump into the Bootloaderto prepare for a firmware download. It always
	succeeds, because you can always stop where you are, shut everything down and transfer execution. All
	commands after this one must comply with the Bootloader Protocol Specification, which is a separate
	document.
	
	Note that just because you can always vector into the Bootloader, it doesn't mean you can get anything
	done. Further details are explained in the associated document but in short: the Bootloader doesn't
	implement the entire Core Device messageset and if the battery is deemed too low to execute
	reflashing operations, all you can do is return to the Main Application.*/

	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_GOTO_BL);
	
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::performLevel1Diagnostics() {
	/*This is a developer-level command to help diagnose aberrant behavior. Most system counters, process
     flags, and system states are decoded into human readable ASCII. There are two responses to this
     command: a Simple Response followed by a large async message containing the results of the diagnostic
     tests. As of FW version 0.99, the answer was well over 1K in length and similar to:*/
    
    SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_RUN_L1_DIAGS);
    
    SpheroMessage msg = adaptor.receive(seq);
    if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    return ResponseCode_OK;
}

ResponseCode Sphero::performLevel2Diagnostics(MsgPerformLevel2Diagnostics &res) {
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_RUN_L2_DIAGS);
    
    SpheroMessage msg = adaptor.receive(seq);
    if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    
    res.RecVer = static_cast<int>((msg.data[0] << 8) | msg.data[1]);
    // empty: msg.data[1]
    
    res.Rx_Good = static_cast<int>( (msg.data[3] << 24) | (msg.data[4] << 16) | (msg.data[5] << 8) | msg.data[6]);
    res.Rx_Bad_DID = static_cast<int>( (msg.data[7] << 24) | (msg.data[8] << 16) | (msg.data[9] << 8) | msg.data[10]);
    res.Rx_Bad_DLEN = static_cast<int>( (msg.data[11] << 24) | (msg.data[12] << 16) | (msg.data[13] << 8) | msg.data[14]);
    res.Rx_Bad_CID = static_cast<int>( (msg.data[15] << 24) | (msg.data[16] << 16) | (msg.data[17] << 8) | msg.data[18]);
    res.Rx_Bad_CHK = static_cast<int>( (msg.data[19] << 24) | (msg.data[20] << 16) | (msg.data[21] << 8) | msg.data[22]);
    res.Rx_Buff_Ovr = static_cast<int>( (msg.data[23] << 24) | (msg.data[24] << 16) | (msg.data[25] << 8) | msg.data[26]);
    res.Tx_Msgs = static_cast<int>( (msg.data[27] << 24) | (msg.data[28] << 16) | (msg.data[29] << 8) | msg.data[30]);
    res.Tx_Buff_Ovr = static_cast<int>( (msg.data[31] << 24) | (msg.data[32] << 16) | (msg.data[33] << 8) | msg.data[34]);
    
    res.LastBootReason = static_cast<int>(msg.data[35]);
    for (int i = 36; i < 68; i+=2) {
        res.BootCounters.push_back(static_cast<int>((msg.data[i] << 8) | msg.data[i+1]));
    }
    
    // empty: (msg.data[68] << 8) | msg.data[69]
    res.ChargeCount = static_cast<int>((msg.data[70] << 8) | msg.data[71]);
    res.SecondsSinceCharge = static_cast<int>((msg.data[72] << 8) | msg.data[73]);
    res.SecondsOn = static_cast<int>((msg.data[74] << 24) | (msg.data[75] << 16) | (msg.data[76] << 8) | msg.data[77]);
    res.DistanceRolled = static_cast<int>((msg.data[78] << 24) | (msg.data[79] << 16) | (msg.data[80] << 8) | msg.data[81]);
    res.SensorFailures = static_cast<int>((msg.data[82] << 8) | msg.data[83]);
    res.GyroAdjustCount = static_cast<int>((msg.data[84] << 24) | (msg.data[85] << 16) | (msg.data[86] << 8) | msg.data[87]);
    
    return ResponseCode_OK;
}

ResponseCode Sphero::clearCouters() {
	/*This is a developers-only command to clear the various system counters described in command 41h. It is
	denied when Sphero is in Normal mode*/
	
    SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_CLEAR_COUNTERS);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::assignTimeValue(const uint timeValue) {
	/*Sphero contains a 32-bit counter that increments every millisecond. It has no absolute temporal
	meaning, just a relative one. This command assigns the counter a specific value for subsequent
	sampling.Though it starts at zero when Sphero wakes up, assigning it too high of a value with this
	command could cause it to roll over.*/
    
	std::vector<ubyte> data;
	data.push_back((timeValue >> 24) & 0xff);
	data.push_back((timeValue >> 16) & 0xff);
	data.push_back((timeValue >> 8) & 0xff);
	data.push_back((timeValue) & 0xff);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_ASSIGN_TIME, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::pollPacketTimes(int &delay, int &offset) {
	/*This command helps the Client application profile the transmission and processing latencies in Sphero so
	that a relative synchronization of timebases can be performed. This technique is based upon the scheme
	in theNetwork Time Protocol (RFC 5905) and allows the Client to reconcile time stamped messages
	from Sphero to its own time stamped events.In the following discussion, each 32-bit value is a count of
	milliseconds from some referencewithin the device.
	
	The scheme is as follows: the Client sends the command with the Client Tx time (T1) filled in. Upon
	receipt of the packet, the command processor in Sphero copies that time into the response packet and
	places the current value of the millisecond counter into the Sphero Rx time field(T2). Just before the
	transmit engine streams it into the Bluetooth module, the Sphero Tx time value (T3) is filled in. If the
	Client then records the time at which the response is received (T4) the relevant time segments can be
	computed from the four time stampsT1-T4:
	
		-The value offset represents the maximum-likelihood time offset of the Client clock to Sphero's
		system clock:
	
				offset = 1/2 * [(T2 -T1) + (T3 -T4)]
	
		-The value delay represents the round-trip delay between the Client and Sphero:
	
				delay = (T4 -T1) -(T3 -T2)
	*/
    
	std::vector<ubyte> data;
	uint spheroTxTime = 0;

	#ifdef _WIN32 // 32-bit or 64-bit Windows
		SYSTEMTIME tv;
		GetSystemTime(&tv);
		spheroTxTime = (uint)tv.wMilliseconds;
	
	#else // Linux or Mac OS
		timeval tv;
		gettimeofday(&tv, NULL);
		spheroTxTime = (uint)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	#endif // Linux or Mac OS
    
    
    data.push_back((spheroTxTime >> 24) & 0xff);
    data.push_back((spheroTxTime >> 16) & 0xff);
    data.push_back((spheroTxTime >> 8) & 0xff);
    data.push_back((spheroTxTime) & 0xff);
	SequenceId seq = adaptor.deviceSend(DeviceId_CORE, CoreCommandId_POLL_TIMES, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	int t1 = (msg.data[0] << 24) + (msg.data[1] << 16) + (msg.data[2] << 8) + msg.data[3];
	int t2 = (msg.data[4] << 24) + (msg.data[5] << 16) + (msg.data[6] << 8) + msg.data[7];
	int t3 = (msg.data[8] << 24) + (msg.data[9] << 16) + (msg.data[10] << 8) + msg.data[11];
    int t4 = 0;
    
	#ifdef _WIN32 // 32-bit or 64-bit Windows
		GetSystemTime(&tv);
		t4 = (uint)tv.wMilliseconds;

	#else // Linux or Mac OS
		gettimeofday(&tv, NULL);
		t4 = (uint)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	#endif // Linux or Mac OS
    
    offset = 0.5 * ((t2-t1) + (t3-t4));
    delay = ((t4-t1)-(t3-t2));

	return ResponseCode_OK;
}

//*******************************************************************************************************/
//***********************************        Sphero commands         *************************************
//*******************************************************************************************************/
ResponseCode Sphero::setHeading(const ushort heading) {
	/*This allows the smartphone client to adjust the orientation of Sphero by commanding a new reference
	heading in degrees, which ranges from 0 to 359. You will see the ball respond immediately to this
	command if stabilization is enabled.
	
	In FW version 3.10 and later thisalso clears the maximum value counters for the rate gyro, effectively
	re-enabling the generation of an async message alerting the client to this event.*/
    
	std::vector<ubyte> data;
	data.push_back((heading >> 8) & 0xff);
	data.push_back(heading & 0xff);
	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_CAL, data);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setStabilisation(const bool enable) {
	/*This turns on or off the internal stabilization of Sphero, in which the IMU is used to match the ball's
	orientation to its various set points. The flag value is as you would expect, 00h for off and 01h for on.
	Stabilization is enabled by default when Sphero powers up. You will want to disable stabilization when
	using Sphero as an external input controlleror even to save battery power during testing that doesn't
	involve movement (orbBasic, etc.)
	
	An error is returned if the sensor network is dead; without sensors the IMU won't operate and thus
	there is no feedback to control stabilization*/
	ubyte flag_enable = enable ? 0x01 : 0x00;
	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_STABILIZ, { flag_enable });

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setRotationRate(const ubyte rate) {
	/*This allows you to control the rotation rate that Sphero will use to meet new heading commands(DID
	02h, CID 01h). A lower value offers better control but with a larger turning radius. A higher value will
	yield quick turnsbut Sphero may roll over on itselfand lose control.
	
	The commanded valueisin units of 0.784 degrees/sec. So, setting a value of C8h will set the rotation
	rate to 157 degrees/sec. A value of 255 jumps tothe maximum (currently 400 degrees/sec). A value of
	zero doesn't make muchsense so it's interpreted as 1, the minimum.*/
    
	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_ROTATION_RATE, { rate });
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getChassisId(std::string &chassisId) {
	/*Returns the Chassis ID, a 16-bit value, which was set at the factory*/
	
    SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_CHASSIS_ID);

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream mss;
	ushort chassis = ((msg.data[0] << 8) | msg.data[1]);
	mss << std::hex << static_cast<int>(chassis);
	chassisId = mss.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::selfLevel(const MsgSelfLevel op) {
    /*This command controls the self level routine. The self level routine attempts to achieve a horizontal
    orientation where pitch and roll angles are less than the provided Angle Limit. After both angle limits are
    satisfied, option bits control sleep, final angle (heading), and control system on/off. An asynchronous
    message is returned when the self level routine completes (only when started by API call). The required
    parameters are:
     
     + Bit 0: (Start/Stop) 0 aborts the routine if in progress. 1 starts the routine.
     + Bit 1: (Final Angle) 0 just stops. 1 rotates to heading equal to beginning heading.
     + Bit 2: (Sleep) 0 stays awake after leveling. 1 goes to sleep after leveling.
     + Bit 3: (Control System) 0 leaves control system off. 1 leaves control system on (after leveling).
     
     + Angle Limit:
            0     Use the default value
        1 to 90   Set the max angle for completion (in degrees)
     
     + Timeout
            0     Use the default value
        1 to 255  Set maximum seconds to run the routine
     
     + True Time
            0     Use the default value
        1 to 255  Set the required “test for levelness” time to 10*True Time (in milliseconds)
     
    Default values are: Angle = 3, Timeout = 15, True Time = 30 (300 milliseconds)
    True Time*10 specifies the number of milliseconds that the pitch and roll angles must remain below the
    Angle Limit after the routine completes. If one of the values exceeds the Angle Limit, the ball will self
    level again and the accuracy timer will start again from 0.*/
    
    std::vector<ubyte> data;
    ubyte aux = ( (op.controlSystem << 3) | (op.sleep << 2) | (op.finalAngle << 1) | op.startStop ) & 0xff;
    data.push_back(aux);
    data.push_back(op.angleLimit & 0xff);
    data.push_back(op.timeout & 0xff);
    data.push_back(op.trueTime & 0xff);
    
    SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SELF_LEVEL, data);
	
    SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setDataStreaming(const MsgSetDataStreaming op) {
    /*Sphero supports asynchronous data streaming of certain control system and sensor parameters. This
    command selects the internal sampling frequency, packet size, parameter mask and optionally, the total
    number of packets.
     
     + N: Divisor of the maximum sensor sampling rate
     + M: Number of sample frames emitted per packet
     + MASK: Bitwise selector of data sources to stream
     + PCNT: Packet count 1-255 (or 0 for unlimited streaming)
     + MASK2: Bitwise selector of more data sources to stream (optional)
     
    MASK and PCNT are pretty obvious but the N, M terms bear a little more explanation. Currently the
    control system runs at 400Hz and because it's pretty unlikely you will want to see data at that rate, N
    allows you to divide that down. N = 2 yields data samples at 200Hz, N = 10, 40Hz, etc. Every data sample
    consists of a "frame" made up of the individual sensor values as defined by the MASK. The M value
    defines how many frames to collect in memory before the packet is emitted. In this sense, it controls the
    latency of the data you receive. Increasing N and the number of bits set in MASK drive the required
    throughput. You should experiment with different values of N, M and MASK to see what works best for you.
    
    The MASK2 bitfield was added to extend MASK when we developed more than 32 data sources. The API
    processor is implemented so that this value is optional; if it isn't included then all of its bits are set to
    zero. (Added in FW 1.15)
     
    Each parameter is returned as a 16-bit signed integer. The table below defines the bits in MASK to those
    parameters with the indicated ranges and units. If the command is issued with a MASK of zero, then
    data streaming is disabled.*/
    
	stream = op;

    std::vector<ubyte> data;
    data.push_back((op.N >> 8) & 0xff);
    data.push_back(op.N & 0xff);
    
    data.push_back((op.M >> 8) & 0xff);
    data.push_back(op.M & 0xff);
    
	ubyte mask = ((op.accelXRaw && 0xff) << 7) + ((op.accelYRaw && 0xff) << 6) + ((op.accelZRaw && 0xff) << 5) + ((op.gyroXRaw && 0xff) << 4);
	mask = mask + ((op.gyroYRaw && 0xff) << 3) + ((op.gyroZRaw && 0xff) << 2);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
    data.push_back(mask);

    mask = ((op.rightEMFRaw && 0xff) << 6) + ((op.leftEMFRaw && 0xff) << 5) + ((op.leftPWMRaw && 0xff) << 4);
    mask = mask + ((op.rightPWMRaw && 0xff) << 3) + ((op.pitchIMU && 0xff) << 2) + ((op.rollIMU && 0xff) << 1) + (op.yawIMU && 0xff);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
    data.push_back(mask);
    
	mask = ((op.accelX && 0xff) << 7) + ((op.accelY && 0xff) << 6) + ((op.accelZ && 0xff) << 5) + ((op.gyroX && 0xff) << 4);
    mask = mask + ((op.gyroY && 0xff) << 3) + ((op.gyroZ && 0xff) << 2);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
	data.push_back(mask);

	mask = ((op.rightEMF && 0xff) << 6) + ((op.leftEMF && 0xff) << 5);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
	data.push_back(mask);
    
    data.push_back(op.PCNT & 0xff);
    
	mask = ((op.q0 && 0xff) << 7) + ((op.q1 && 0xff) << 6) + ((op.q2 && 0xff) << 5) + ((op.q3 && 0xff) << 4);
	mask = mask + ((op.odometerX && 0xff) << 3) + ((op.odometerY && 0xff) << 2) + ((op.accelOne && 0xff) << 1) + (op.velocityX && 0xff);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
	data.push_back(mask);

	mask = (op.velocityY << 7);
    //std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(mask) << std::endl;
	data.push_back(mask);
	data.push_back(0x00);
	data.push_back(0x00);

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_DATA_STREAMING, data);
    
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::configureCollisionDetection(const MsgConfigureCollisionDetection op) {
	/*Sphero contains a powerful analysis function to filter accelerometer data in order to detect collisions.
	Because this is a great example of a high-level concept that humans excel and –but robots do not– a
	number of parameters control the behavior.  When a collision is detected anasynchronous message is
	generated to the client. The configuration fields are defined as follows:
		
		meth: Detection method type to use. Supportedmethods are 01h, 02h, and 03h (see the collision
			  detection document for details). Use00h to completely disable this service.

		Xt, Yt: An 8-bit settable threshold for the X (left/right) and Y (front/back) axes of Sphero.
			  A value of 00h disables the contribution of that axis.

		Xspd, Yspd: An 8-bit settable speed value for the X and Y axes. This setting is ranged by the speed,
			  then added to Xt, Yt to generate the final threshold value.

		Dead: An 8-bit post-collision dead timeto prevent retriggering; specifiedin 10ms increments.
	*/

	std::vector<ubyte> data;
	data.push_back(op.meth & 0xff);
	data.push_back(op.xt & 0xff);
	data.push_back(op.xspd & 0xff);
	data.push_back(op.yt & 0xff);
	data.push_back(op.yspd & 0xff);
	data.push_back(op.dead & 0xff);

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_COLLISION_DET, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::configureLocator(const MsgConfigureLocator op) {
	/*Through the streaming interface, Sphero provides real-time location data in the form of (X,Y)
	coordinates on the ground plane. When Sphero wakes up it has coordinates (0,0) and heading 0, which
	corresponds to facing down the positive Y­‐axis with the positive X‐axis to your right. This command
	allows you to move Sphero to a new location and change the alignment of locator coordinates with IMU
	headings.
	
	When Sphero receives a Set Heading command it changes which direction corresponds to heading 0. By 
	default, the locator compensates for this by modifying its value for yaw tare so that the Y-­axis is still
	pointing in the same real-­world direction. For instance, if you wake up Sphero and drive straight, you 
	will be driving down the Y­‐axis. If you use the Set Heading feature in the drive app to turn 90 degrees,
	you will still have heading 0, but the locator knows you have turned 90 degrees and are now facing
	down the X­‐axis. This feature can be turned off, in which case the locator knows nothing about the Set
	Heading command. This can lead to some strange results. For instance, if you drive using only roll
	commands with heading 0 and set heading commands to change direction the locator will perceive your
	entire path as lying on the Y-­axis.
	
		Flags: Bit 0 – Determines whether calibrate commands automatically correct the yaw tare value.
			   When false, the positive Y axis coincides with heading 0 (assuming you do not change the
			   yaw tare manually using this API command).
			   Other Bits - Reserved
		
		X,Y: The current (X,Y) coordinates of Sphero on the ground plane in centimeters.

		Yaw Tare: Controls how the X,Y-plane is aligned with Sphero’s heading coordinate system. When this
				  parameter is set to zero, it means that having yaw = 0 corresponds to facing down the 
				  Y-axis in the positive direction.  The value will be interpreted in the range 0-359 
				  inclusive.
	*/

	std::vector<ubyte> data;
	data.push_back(op.autoCalibrate & 0x01);
	data.push_back((op.x & 0xff00) >> 8);
	data.push_back(op.x & 0xff);
	data.push_back((op.y & 0xff00) >> 8);
	data.push_back(op.y & 0xff);
	data.push_back((op.yawTare & 0xff00) >> 8);
	data.push_back(op.yawTare & 0xff);

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_LOCATOR, data);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setAccelerometerRange(const ubyte range) {
	/*Normally, Sphero's solid state accelerometer is set for a range of ±8Gs. There may be times when you
	would like to alter this, say to resolve finer accelerations. This command takes an index for the
	supported range as explained below.
	
		0 ±2Gs
		1 ±4Gs
		2 ±8Gs (default)
		3 ±16Gs
	
	Note that setting this to other than the default value will have indeterminate consequences for driving
	and collision detection; you shouldn't expect either to work*/
    
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_ACCELERO, { range });
	
    SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::readLocator(MsgReadLocator &res) {
	/*This reads Sphero's current position(X,Y), component velocitiesand SOG (speed over ground). The
	position is a signed value in centimeters, the component velocitiesare signedcm/sec while the SOG is
	unsigned cm/sec.*/
    
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_READ_LOCATOR);
	
    SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	int aux = ((msg.data[0] << 8) & 0Xffff) + (msg.data[1] & 0Xffff);
	int sig = msg.data[0] >> 7;
	res.x = sig ? -aux : aux;

	/*std::cout << "X:" << std::endl;
	std::cout << aux << std::endl;
	std::cout << sig << std::endl;
	std::cout << res.x << std::endl;
	std::cout << std::endl;*/

	aux = ((msg.data[2] << 8) & 0Xffff) + (msg.data[3] & 0Xffff);
	sig = msg.data[2] >> 7;
	res.y = sig ? -aux : aux;

	/*std::cout << "Y:" << std::endl;
	std::cout << aux << std::endl;
	std::cout << sig << std::endl;
	std::cout << res.y << std::endl;
	std::cout << std::endl;*/

	aux = ((msg.data[4] << 8) & 0Xffff) + (msg.data[5] & 0Xffff);
	sig = msg.data[4] >> 7;
	res.vx = sig ? -aux : aux;

	/*std::cout << "VX:" << std::endl;
	std::cout << aux << std::endl;
	std::cout << sig << std::endl;
	std::cout << res.vx << std::endl;
	std::cout << std::endl;*/

	aux = ((msg.data[6] << 8) & 0Xffff) + (msg.data[7] & 0Xffff);
	sig = msg.data[6] >> 7;
	res.vy = sig ? -aux : aux;

	/*std::cout << "VY:" << std::endl;
	std::cout << aux << std::endl;
	std::cout << sig << std::endl;
	std::cout << res.vy << std::endl;
	std::cout << std::endl;*/

	int b = static_cast<int>(((msg.data[8] << 8) & 0Xffff) + (msg.data[9] & 0Xffff));
	res.sog = b;

	/*std::cout << "SOG:" << std::endl;
	std::cout << res.sog << std::endl;
	std::cout << std::endl;*/

	return ResponseCode_OK;
}

ResponseCode Sphero::setRGBLedOutput(const ubyte red, const ubyte green, const ubyte blue, const bool persist) {
	/*This allows you to set the RGB LED color. The composite value is stored as the "application LED color"
	and immediately driven to the LED(if not overridden by a macro or orbBasic operation). If FLAG is true,
	the value is alsosaved as the "user LED color" whichpersists across power cyclesand is rendered in the
	gap between an application connecting and sending this command.*/
    
	ubyte flag_persist = persist ? 0x01 : 0x00;
	std::vector<ubyte> data;
	data.push_back(red);
	data.push_back(green);
	data.push_back(blue);
	data.push_back(flag_persist);
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_RGB_LED, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setBackLEDOutput(const ubyte intensity) {
	/*This allows you to control the brightness of the back LED. The value does not persist across power
	cycles*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_BACK_LED, { intensity });
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getRGBLed(MsgGetRGBLed &res) {
	/*This retrieves the "user LED color" which is stored in the config block (which may or may not be actively
	driven to the RGB LED)*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_RGB_LED);
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.red = static_cast<int>(msg.data[0]);
	res.green = static_cast<int>(msg.data[1]);
	res.blue = static_cast<int>(msg.data[2]);

	return ResponseCode_OK;
}

ResponseCode Sphero::roll(const ubyte speed, const ushort heading, const ubyte state) {
	/*This commands Sphero to roll along the provided vector. Both a speedand a heading are required; the
	latter is considered relative to the last calibrated direction.A state valueis also provided. In the CES
	firmware, this was used to gate the control system to either obey the roll vector or ignore it and apply
	optimalbraking to zero speed.Please refer to Appendix C for detailed information.
	
	The client convention for heading follows the 360 degrees on a circle, relative to the ball: 0 is straight
	ahead, 90 is to the right, 180 is back and 270 is to the left. The valid range is 0..359.
     
    The roll command takes three parameters: heading, speed and a state variable (internally referred to as
    the "go" value). The heading parameter is self explanatory and always acted upon by the control system
    but the other two bear additional explanation.
    
    As of the 1.13 Sphero firmware their relationship is as follows:
     
     Go Speed       Result
     1   >0         Normal driving
     1    0         Rotate in place for setting heading if speed is very small. (If sent when Sphero is
                    driving then it plugs the pitch controller for a far too aggressive stop. This should
                    be avoided.)
     2    X         Force fast rotation to this heading independent of speed.
     0    X         Commence optimal braking to zero speed
     
     Note that beginning in the 1.16 firmware, there are two different rotation speeds employed when acting
     upon the heading parameter. The first is the value set with the Set Rotation Rate command in the
     Sphero DID and is used for normal driving. The second is a much faster rate used to improve
     performance while rotating in place and setting the heading. It defaults to 1,000 degrees/sec but can be
     accessed through the shell commands hss and hgs.
     
     Beginning in the 1.21 firmware the "go" parameter will also act on a value of 2 to override the speed-
     dependent nature of fast turning.*/

	std::vector<ubyte> data;
	data.push_back(speed);
	data.push_back((heading & 0xff00) >> 8);
	data.push_back(heading & 0xff);
	data.push_back(state);
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_ROLL, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::boost(const bool enable) {
	/*Beginning with FW 1.46 (S2) and 3.25(S3), this executes the boost macro from within the SSB.It takes a
	1 byte parameter which is either 01h to begin boosting or 00h to stop.*/

	ubyte flag_enable = enable ? 0x01 : 0x00;
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_BOOST, { flag_enable });

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setRAWMotorValues(const ubyte modeLeft, const ubyte powerLeft, const ubyte modeRight, const ubyte powerRight) {
	/*This allows you to take over one or both of the motor output values, instead of having the stabilization
	system control them. Each motor (left andright) requires a mode(see below) and a power value from 0-255.
	This commandwill disablestabilization if both modes aren't"ignore" so you'll need to re-enable it via 
	CID 02h once you're done.
	
		+ 00h Off (motor is open circuit)
		+ 01h Forward
		+ 02h Reverse
		+ 03h Brake (motor is shorted)
		+ 04h Ignore (motor mode and power is left unchanged)
	*/
	
	std::vector<ubyte> data;
	data.push_back(modeLeft);
	data.push_back(powerLeft);
	data.push_back(modeRight);
	data.push_back(powerRight);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_RAW_MOTORS, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setMotionTimeout(const ushort msecTimeout) {
	/*This sets the ultimate timeout for the last motion command to keep Sphero from rolling away in the
	case of a crashed (or paused) client app. The TIME parameter is expressed in milliseconds and defaults
	to 2000 upon wake-up.
	
	If the control system is enabled, the timeout triggers a stop otherwise it commands zero PWM to both
	motors. This"termination behavior" is inhibited if a macro is running with the flag MF_EXCLUSIVE_DRV
	set, or an orbBasic program is executing with a similar flag, BF_EXCLUSIVE_DRV.
	
	Note that you must enable this action by setting System Option Flag #4.*/
	
	std::vector<ubyte> data;
    data.push_back((msecTimeout & 0xff00) >> 8);
    data.push_back(msecTimeout & 0xff);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_MOTION_TO, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setPermanentOptionFlags(const MsgOptionFlags op) {
	/*Assigns the permanent option flags to the provided valueand writes them immediately to the config
	block for persistence across power cycles. See below for the bit definitions.*/
	
	std::vector<ubyte> data;
	ubyte aux = 0x00;
	data.push_back(aux);
	data.push_back(aux);

	aux = 0x01 & op.gyroMaxAsync;
	data.push_back(aux);

	ubyte aux1 = (op.sleepCharge + (op.vectorDrive << 1) + (op.selfLevelingCharger << 2) + (op.forceTailLED << 3)) & 0xff;
	ubyte aux2 = ((op.motionTimeOuts + (op.retailDemoMode << 1) + (op.awakeLight << 2) + (op.awakeHeavy << 3)) << 4) & 0xff;
	aux = aux1 + aux2;
	data.push_back(aux);

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_OPTIONS_FLAG, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getPermanentOptionFlags(MsgOptionFlags &res) {
	/*Returns the permanent option flags as a bitfieldas defined below:
	
		+ 0 Set to prevent Sphero from immediately going to sleep when 
			placed in the charger andconnected over Bluetooth.
		+ 1 Set to enable Vector Drive, that is, when Sphero is stopped
			and a new roll command is issued it achieves the heading before
			moving along it.
		+ 2 Set to disable self-leveling when Sphero is inserted into the charger.
		+ 3 Set to force the tail LED always on.
		+ 4 Set to enable motion timeouts (seeDID 02h, CID 34h)
		+ 5 Set to enable retail Demo Mode (when placed in the charger, ball
			runs a slow rainbow macro for 60 minutes and then goes to sleep).
		+ 6 Set double tap awake sensitivity to Light
		+ 7 Set double tap awake sensitivity to Heavy
		+ 8 Enable gyro max asyncmessage(NOT SUPPORTED IN VERSION 1.47)
		+ 6-31 Unassigned
	*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_OPTIONS_FLAG);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.sleepCharge = msg.data[3] & 0x01;
	res.vectorDrive = (msg.data[3] >> 1) & 0x01;
	res.selfLevelingCharger = (msg.data[3] >> 2) & 0x01;
	res.forceTailLED = (msg.data[3] >> 3) & 0x01;
	res.motionTimeOuts = (msg.data[3] >> 4) & 0x01;
	res.retailDemoMode = (msg.data[3] >> 5) & 0x01;
	res.awakeLight = (msg.data[3] >> 6) & 0x01;
	res.awakeHeavy = (msg.data[3] >> 7) & 0x01;
	res.gyroMaxAsync = msg.data[2] & 0x01;

	return ResponseCode_OK;
}

ResponseCode Sphero::setTemporaryOptionFlags(const bool op) {
	/*Enable Stop On Disconnect behavior: when the Bluetooth link transitions from
	connected to disconnected, Sphero is commanded to stop rolling. This is ignored
	if a macro or orbBasicprogram is running though both have option flags to allow
	this during their execution. This flag is cleared after it is obeyed, thus it
	is a one-shot.*/

	std::vector<ubyte> data;
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x01 & op);

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_TEMP_OPTIONS_FLAG, data);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getTemporaryOptionFlags(bool &res) {
	/*Enable Stop On Disconnect behavior: when the Bluetooth link transitions from
	connected to disconnected, Sphero is commanded to stop rolling. This is ignored
	if a macro or orbBasicprogram is running though both have option flags to allow
	this during their execution. This flag is cleared after it is obeyed, thus it
	is a one-shot.*/
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_TEMP_OPTIONS_FLAG);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = msg.data[3] & 0x01;

	return ResponseCode_OK;
}

ResponseCode Sphero::getConfigurationBlock(const ubyte id) {
	/*This command retrieves one of the configuration blocks. The response is a simple one; an error code of
	08h is returned when the resources are currently unavailable to send the requested block back. The
	actual configuration block data returns in an asynchronous message of type 04h due to its length (if
	there is no error).
	
		ID = 00h requests the factory configuration block
		ID = 01h requests the user configuration block, which is updated with current values first
	*/

	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_CONFIG_BLK, { id });

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setSSBModifierBlock(const uint pwd, const CommandParameters op) {
	/*This development-only command allows the SSB to be patched with a new modifier block, including the
	Boost macro. The changes take effectimmediately.*/
    
    std::vector<ubyte> data;
	data.push_back((pwd >> 24) & 0xff);
	data.push_back((pwd >> 16) & 0xff);
	data.push_back((pwd >> 8) & 0xff);
	data.push_back(pwd & 0xff);
	data.insert(data.end(), op.begin(), op.end());
	
    SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_SSB_PARAMS, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setDeviceMode(const bool enableHackMode) {
	/*Assigns the operation mode of Sphero based on the supplied mode value:
	
		00h Normal mode
		01h User Hack mode(see below)
	
	User Hack mode enables ASCII shell commands; refer to the associated document for a detailed list
	of operations.*/
	
	ubyte flag_enableHackMode = enableHackMode ? 0x01 : 0x00;
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_DEVICE_MODE, { flag_enableHackMode });
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setConfigurationBlock(const CommandParameters data) {
	/*This command accepts an exact copy of the configuration block and loads it into the RAM copy of the
	configuration block.  Then the RAM copy is saved to flash.  The configuration block can be obtained by
	using the Get Configuration Block command.*/
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_CFG_BLOCK, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::getDeviceMode(bool &res) {
	/*This returns the current device mode, 00h for Normal mode or 01h for User Hack mode.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_DEVICE_MODE);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    
    res = msg.data[0];

	return ResponseCode_OK;
}

ResponseCode Sphero::getSSB() {
	/*This command retrieves Sphero'sSoul Block. The response is simpleand then the actual block of
	soulular data returns in an asynchronous message of type 0Dh due to its 0x400 byte length (if there
	is no error).*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_SSB);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::setSSB(const uint password, const CommandParameters op) {
	/*This command sets Sphero's Soul Block. The actual payload length is 404h bytes but if you use the
	special DLEN encoding of ffh, Sphero will know what to expect. You need to supply the password in
	order for it to work.*/
    
    std::vector<ubyte> data;
    data.push_back((password >> 24) & 0xff);
    data.push_back((password >> 16) & 0xff);
    data.push_back((password >> 8) & 0xff);
    data.push_back(password & 0xff);
    data.insert(data.end(), op.begin(), op.end());
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_SSB, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::refillBank(const ubyte type, int &res) {
	/*This command attempts to refill either the Boost bank (TYPE = 00h) or the Shield bank (TYPE = 01h) by
	attempting to deduct the respective refill cost from the current number of cores. If it succeeds the bank
	is set to the maximum attainable for that level, the cores are spent and an API success response is
	returned with the lower core balance. This also commits the SSB to flash to register this transaction.
	
	If there are not enough cores available to spend the API responds with an EEXEC error (code 08h).*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_REFILL, { type });
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>((msg.data[0] << 24) | (msg.data[1] << 16) | (msg.data[2] << 8) | msg.data[3]);

	return ResponseCode_OK;
}

ResponseCode Sphero::buyConsumable(const ubyte id, const ubyte quantity, MsgBuyConsumable &res) {
	/*This command attempts to spend cores on consumables. The consumable ID (0..7) is given as well as the
	quantity requested to purchase. If the purchase succeeds the consumable count is increased, the cores
	are spent and an API success responseis returned with both the increased consumable quantity and
	lower core balance. This also commits the SSB to flash to register this transaction.
	
	If there are not enough cores available to spend or the purchase would exceed the max consumable
	quantity of 255 the API responds with an EEXEC error (code 08h).*/
	
	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_BUY, { id, quantity });
	
	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.QTY = static_cast<int>(msg.data[0]);
	res.cores = static_cast<int>((msg.data[1] << 24) | (msg.data[2] << 16) | (msg.data[3] << 8) | msg.data[4]);

	return ResponseCode_OK;
}

ResponseCode Sphero::useConsumable(const ubyte id, MsgUseConsumable &res) {
	/*Attempt to use a consumable (run a macro) if the quantity remaining is non-zero. On success the return
	message echoes the ID of this consumable and how many of them remain. Note that this will NOT
	immediately commit the SSB to flash.
	
	If the associated macro is already runningor the quantity remaining is zero, this returns an EEXEC error
	(code 08h).*/

	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_USE_CONSUMEABLE, { id });

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.id = static_cast<int>(msg.data[0]);
	res.QTY = static_cast<int>(msg.data[1]);

	return ResponseCode_OK;
}

ResponseCode Sphero::grantCores(const uint password, const uint quantity, const ubyte flags, int &res) {
	/*This command adds the supplied number of cores.If the first bit in the flags byte is set the command
	immediately commits the SSB to flash.  Otherwise it does not.All other bits are reserved.  If the
	password is not accepted, this command fails without consequence.*/

	std::vector<ubyte> data;
	uint net_password = htons(password);
	uint net_quantity = htons(quantity);
	data.push_back((net_password >> (8 * 0)) & 0xff);
	data.push_back((net_password >> (8 * 1)) & 0xff);
	data.push_back((net_password >> (8 * 2)) & 0xff);
	data.push_back((net_password >> (8 * 3)) & 0xff);
	data.push_back((net_quantity >> (8 * 0)) & 0xff);
	data.push_back((net_quantity >> (8 * 1)) & 0xff);
	data.push_back((net_quantity >> (8 * 2)) & 0xff);
	data.push_back((net_quantity >> (8 * 3)) & 0xff);
	data.push_back(flags);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_GRANT_CORES, data);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>((msg.data[0] << 24) | (msg.data[1] << 16) | (msg.data[2] << 8) | msg.data[3]);

	return ResponseCode_OK;
}

ResponseCode Sphero::addXP(const uint password, const uint quantity, int &res) {
	/*This command increases XP by adding the supplied number of minutes of drive timeand immediately
	commits the SSB to flash. If the password is not accepted, this command fails without consequence.*/

	std::vector<ubyte> data;
	uint net_password = htons(password);
	uint net_quantity = htons(quantity);
	data.push_back((net_password >> (8 * 0)) & 0xff);
	data.push_back((net_password >> (8 * 1)) & 0xff);
	data.push_back((net_password >> (8 * 2)) & 0xff);
	data.push_back((net_password >> (8 * 3)) & 0xff);
	data.push_back((net_quantity >> (8 * 0)) & 0xff);
	data.push_back((net_quantity >> (8 * 1)) & 0xff);
	data.push_back((net_quantity >> (8 * 2)) & 0xff);
	data.push_back((net_quantity >> (8 * 3)) & 0xff);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_ADD_XP, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}

ResponseCode Sphero::levelUpAttribute(const uint password, const ubyte attrId, MsgLevelUpAttribute &res) {
	/*This command attempts to increase the level of the specified attribute by spending attribute points. The
	IDs are 00h = Speed, 01h = Boost, 02h = Brightness and 03h = Shield. If successful the SSB is committed
	to flash. If there are not enough attribute points, this command returns an EEXEC error (code 08h).
	
	If the password is not accepted, this command fails without consequence.
	
	On success the response packet contains the attribute ID, the new level and the remaining attribute
	points.*/

	std::vector<ubyte> data;
	uint net_password = htons(password);
	data.push_back((net_password >> (8 * 0)) & 0xff);
	data.push_back((net_password >> (8 * 1)) & 0xff);
	data.push_back((net_password >> (8 * 2)) & 0xff);
	data.push_back((net_password >> (8 * 3)) & 0xff);
	data.push_back(attrId);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_LEVEL_UP_ATTR, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.id = static_cast<int>(msg.data[0]);
	res.level = static_cast<int>(msg.data[1]);
	res.ptsRemaining = static_cast<int>((msg.data[2] << 8) | msg.data[4]);

	return ResponseCode_OK;
}

ResponseCode Sphero::getPasswordSeed(int &res) {
	/*Protected Sphero commands require a password and this returns the seed to you.
	Refer to Appendix D for what to do next.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_PW_SEED);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>((msg.data[0] << 24) | (msg.data[1] << 16) | (msg.data[2] << 8) | msg.data[3]);

	return ResponseCode_OK;
}

ResponseCode Sphero::enableSSBAsyncMessages(const bool enable) {
	/*Turn on/off soul block related asynchronous messages. This includes shield collision and regrowth
	messages, boost use and regrowth messages, XP growth and level-up messages. This feature defaults
	to off.*/

	ubyte flag_enable = enable ? 0x01 : 0x00;
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SSB_ENABLE_ASYNC, { flag_enable });
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

	// Macro commands
ResponseCode Sphero::runMacro(const ubyte id) {
	/*This attempts to execute the specified macro. Macro IDs are organized into groups: 01 –31 are System
	Macros, that is, they are compiled into the Main Application. As such they are always available to be
	run and cannot be deleted. Macro IDs 32–253 are User Macros that are downloaded and persistently
	stored. They can be deletedin total. MacroID 255is a special user macro called the Temporary Macro
	as it is held in RAM for execution.Macro ID 254 is also a special user macro called the Stream Macro
	that doesn't require this call to begin execution.
	
	This command will fail if there is currentlyan executing macro or the specified ID Code isn't found.
	In the case of the former, send an abort command first.*/

	SequenceId seq = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_RUN_MACRO, { id });

	SpheroMessage msg = adaptor.receive(seq);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::saveTemporaryMacro(const CommandParameters macroData) {
	/*This stores the attached macro definition intothe temporary RAM buffer for later execution. Any
	existing macro ID can be sent through this command and itisthen renamed toID FFh. If this command
	is sent while a Temporary or Stream Macro is executing it will be terminated so that its storage space
	can be overwritten.As with all macros, the longest definition that can be sent is 254 bytes (thus
	requiring DLEN to be FFh).
	
	You must follow this with a Run Macro command to begin execution.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SAVE_TEMP_MACRO, macroData);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::saveMacro(const CommandParameters macroData) {
	/*This stores the attached macro definition into the persistent store forlater execution. This command
	can be sent even if other macrosare executing. You will receive a failure response if you attempt to 
	send an ID number in the System Macro range, 255 for the Temp Macro and ID of an existing user macro
	in the storage block.As with all macros, the longest definition that can be sent is 254 bytes (thus
	requiring DLEN to be FFh).
	
	A special case of this command is to start and continue execution of the Stream Macro, ID 254. If a
	Temporary Macro is running it will be terminated and the Stream Macro will begin. If a Stream Macro is
	already running, this chunkwill be appended (if there is room). Stream Macros terminate via Abort or
	with a special END code.Refer to the Sphero Macro documentation for more detail.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SAVE_MACRO, macroData);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::reinitMacroExecutive() {
	/*This terminates any running macro and reinitializes the macro system. The table of any persistent
	user macros is cleared.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_REINIT_MACRO_EXECUTIVE);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::abortMacro(int &res) {
	/*This command aborts any executing macro and returns both its ID code and the command number
	currently in process. An exceptionis a System Macro that is executing with the UNKILLABLE flag set.
	A normal return code indicates the ID Code of the aborted macro as well as the command number at
	which execution was stopped. A return ID code of 00hindicates that no macro was running and an ID
	code with FFFFhas the CmdNum that the macro was unkillable.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_ABORT_MACRO);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>((msg.data[0] << 8) | msg.data[1]);

	return ResponseCode_OK;
}
ResponseCode Sphero::getMacroStatus(MsgGetMacroStatus &res) {
	/*This command returns the ID code and command number of the currently executing macro. If no macro
	is currently running,  00his returned for the ID code while the command number is left over from the
	last macro.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_GET_MACRO_STATUS);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.id = static_cast<int>(msg.data[0]);
	res.cmdNum = static_cast<int>((msg.data[1] << 8) | msg.data[2]);

	return ResponseCode_OK;
}
ResponseCode Sphero::setMacroParameter(const ubyte parameter, const ubyte valueOne, const ubyte value) {
	/*This command allows system globals that influence certain macro commands to be selectively altered
	from outside of the macro system itself. The values of Val1 and Val2 depend on the parameterindex.
	
		00h Assign System Delay 1: Val1 = MSB, Val2 = LSB
		01h Assign System Delay 2: Val1 = MSB, Val2 = LSB
		02h Assign System Speed 1: Val1 = speed, Val2 = 0 (ignored)
		03h Assign System Speed 2: Val1 = speed, Val2 = 0 (ignored)
		04h Assign System Loops: Val1 = loop count,Val2 = 0 (ignored)
	
	Details of what these system variables change are presented in the Sphero Macro document.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SET_MACRO_PARAMETER, { parameter, valueOne, value });

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::appendMacroChunk(const CommandParameters macroData) {
	/*This stores the attached macro definition into the temporary RAM buffer for later execution. It is similar
	to the Save Temporary Macro call but allows you to build up longer temporary macros.
	
	Any existing macro ID can be sent through this command and executed through the Run Macro call
	using ID FFh. If this command is sent while a Temporary or Stream Macro is executing it will be
	terminated so that its storage space can be overwritten. As with all macros, the longest chunkthat can
	be sent is 254 bytes (thus requiring DLEN to be FFh).
	
	You must follow this with a Run Macro command (ID FFh) to actually get it to go and it is best to prefix
	this command with an Abort call to make certain the larger buffer is completely initialized.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_APPEND_MACRO_CHUNK, macroData);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

	// OrbBasic commands
ResponseCode Sphero::eraseOrbBasicStorage(const ubyte area) {
	/*This erases any existing program in the specified storage area. Specify 00h for the temporary RAM buffer
	or 01h for the persistent storage area*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_ERASE_ORBBASIC_STORAGE, { area });

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::appendOrbBasicFragment(const ubyte area, const CommandParameters fragment) {
	/*Sending an orbBasic program to Sphero involves appending blocks of text toexisting ones in the
	specified storage area (00h for RAM, 01h for persistent). Complete lines are not required. A line
	begins with a decimal line number followed by a space and is terminated with a <LF>. See the orbBasic
	Interpreter document for complete information.
	
	Possible error responses would be ORBOTIX_RSP_CODE_EPARAM if an illegal storage area is specified or
	ORBOTIX_RSP_CODE_EEXEC  if the specified storage areais full*/

	std::vector<ubyte> data;
	data.push_back(area);
	data.insert(data.end(), fragment.begin(), fragment.end());
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_APPEND_ORBBASIC_FRAGMENT, data);

	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::executeOrbBasicProgram(const ubyte area, const ushort startLine) {
	/*This attempts to run a programin the specified storage area beginning at the specified line number. This
	command will fail if there is already an orbBasic program executing.*/

	std::vector<ubyte> data;
	ushort net_startLine = htons(startLine);
	data.push_back(area);
	data.push_back((net_startLine >> (8 * 0)) & 0xff);
	data.push_back((net_startLine >> (8 * 1)) & 0xff);
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_EXECUTE_ORBBASIC_PROGRAM, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::abortOrbBasicProgram() {
	/*Aborts execution of any currently running orbBasic program.*/
	
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_ABORT_ORBBASIC_PROGRAM);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::submitValueToInputStatement(const uint value) {
	/*This takes the place of the typical user console in orbBasic and allows a user to answer an input request.
	If there is no pending input request when this API command is sent, the supplied value is ignored
	without error.Refer to the orbBasic language document for further information.*/

	std::vector<ubyte> data;
	uint net_value = htons(value);
	data.push_back((net_value >> (8 * 0)) & 0xff);
	data.push_back((net_value >> (8 * 1)) & 0xff);
	data.push_back((net_value >> (8 * 2)) & 0xff);
	data.push_back((net_value >> (8 * 3)) & 0xff);
	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_SUBMIT_VALUE_TO_INPUT_STATEMENT, data);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}
ResponseCode Sphero::commitRAMProgramToFlash() {
	/*This copies thecurrent orbBasic RAM program to persistent storage in Flash. It will fail if a program is
	currently executing out of Flash.*/

	SequenceId id = adaptor.deviceSend(DeviceId_SPHERO, SpheroCommandId_COMMIT_RAM_PROGRAM_TO_FLASH);
	
	SpheroMessage msg = adaptor.receive(id);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

//*******************************************************************************************************/
//******************************        Async response commands         *********************************
//*******************************************************************************************************/
ResponseCode Sphero::asyncPowerNotification(int &bateryState) {
	/*The power state byte mimics that of CID 20h above: 01h = Battery Charging, 02h = Battery OK, 
	03h = Battery Low, 04h = Battery Critical*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_PowerNotification);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	
	bateryState = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncLevel1DiagnosticResponse(std::string &res) {
	/*This is a developer-level command to help diagnose aberrant behavior. Most system counters, process
	flags, and system states are decoded into human readable ASCII.There are two responses to this
	command: a Simple Response followed by a large asyncmessage containing the results of the diagnostic
	tests. As of FW version 0.99, the answer was well over 1K in length and similar to:*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_Level1DiagnosticResponse);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream aux;
	for (int i = 0; i < msg.data.size(); i++) aux << char(msg.data[i]);
	res = aux.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncSensorDataStreaming(MsgData &res) {
	/* Each parameter is returned as a 16-bit signed integer. The table below defines the bits in MASK to those
     parameters with the indicated ranges and units. If the command is issued with a MASK of zero, then
     data streaming is disabled */

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_SensorDataStreaming);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    
	MsgSetDataStreaming aux = stream;

    for (int i = 0; i < msg.data.size(); i+=2) {
        
        int number = static_cast<int>(((msg.data[i] << 8) & 0Xffff) + (msg.data[i+1] & 0Xffff));
        int sig = msg.data[i] >> 7;
        
        //std::cout << (sig ? -number : number) << std::endl;
        
		if (aux.accelXRaw) {
            res.accelXRaw = sig ? -number : number;
			aux.accelXRaw = false;
		
		} else if (aux.accelYRaw) {
            res.accelYRaw = sig ? -number : number;
			aux.accelYRaw = false;

		} else if (aux.accelZRaw) {
            res.accelZRaw = sig ? -number : number;
			aux.accelZRaw = false;

		}
		else if (aux.gyroXRaw) {
            res.gyroXRaw = sig ? -number : number;
			aux.gyroXRaw = false;

		} else if (aux.gyroYRaw) {
            res.gyroYRaw = sig ? -number : number;
			aux.gyroYRaw = false;

		} else if (aux.gyroZRaw) {
            res.gyroZRaw = sig ? -number : number;
			aux.gyroZRaw = false;

		}
		else if (aux.rightEMFRaw) {
            res.rightEMFRaw = sig ? -number : number;
			aux.rightEMFRaw = false;
		
		} else if (aux.leftEMFRaw) {
            res.leftEMFRaw = sig ? -number : number;
			aux.leftEMFRaw = false;
		
		}
		else if (aux.leftPWMRaw) {
            res.leftPWMRaw = sig ? -number : number;
			aux.leftPWMRaw = false;
		
		} else if (aux.rightPWMRaw) {
            res.rightPWMRaw = sig ? -number : number;
			aux.rightPWMRaw = false;
		
		}
		else if (aux.pitchIMU) {
            res.pitchIMU = sig ? -number : number;
			aux.pitchIMU = false;

		} else if (aux.rollIMU) {
            res.rollIMU = sig ? -number : number;
			aux.rollIMU = false;

		} else if (aux.yawIMU) {
            res.yawIMU = sig ? -number : number;
			aux.yawIMU = false;

		}
		else if (aux.accelX) {
            res.accelX = sig ? -number : number;
			aux.accelX = false;

		} else if (aux.accelY) {
            res.accelY = sig ? -number : number;
			aux.accelY = false;

		} else if (aux.accelZ) {
            res.accelZ = sig ? -number : number;
			aux.accelZ = false;

		}
		else if (aux.gyroX) {
            res.gyroX = sig ? -number : number;
			aux.gyroX = false;

		} else if (aux.gyroY) {
            res.gyroY = sig ? -number : number;
			aux.gyroY = false;

		} else if (aux.gyroZ) {
            res.gyroZ = sig ? -number : number;
			aux.gyroZ = false;

		}
		else if (aux.rightEMF) {
            res.rightEMF = sig ? -number : number;
			aux.rightEMF = false;

		} else if (aux.leftEMF) {
            res.leftEMF = sig ? -number : number;
			aux.leftEMF = false;

		}
		else if (aux.q0) {
            res.q0 = sig ? -number : number;
			aux.q0 = false;

		} else if (aux.q1) {
			res.q1 = sig ? -number : number;
			aux.q1 = false;

		} else if (aux.q2) {
			res.q2 = sig ? -number : number;
			aux.q2 = false;

		} else if (aux.q3) {
			res.q3 = sig ? -number : number;
			aux.q3 = false;

		}
		else if (aux.odometerX) {
			res.odometerX = sig ? -number : number;
			aux.odometerX = false;

		} else if (aux.odometerY) {
			res.odometerY = sig ? -number : number;
			aux.odometerY = false;

		}
		else if (aux.accelOne) {
			res.accelOne = sig ? -number : number;
			aux.accelOne = false;

		}
		else if (aux.velocityX) {
			res.velocityX = sig ? -number : number;
			aux.velocityX = false;

		} else if (aux.velocityY) {
			res.velocityY = sig ? -number : number;
			aux.velocityY = false;

		}
    }
    
	return ResponseCode_OK;
}

ResponseCode Sphero::asyncConfigBlockContents(std::vector<ubyte> &res) {
	/*This command retrieves one of the configuration blocks. The response is a simple one; an error code of
	08h is returned when the resources are currently unavailable to send the requested block back. The
	actual configuration block data returns in an asynchronous message of type 04h due to its length (if
	there is no error).*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_ConfigBlockContents);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
    
    res.insert(res.end(), msg.data.begin(), msg.data.end());

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncPreSleepWarning10Sec() {
	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_PreSleepWarning10Sec);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::asyncMacroMarkers() {
	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_MacroMarkers);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;
	return ResponseCode_OK;
}

ResponseCode Sphero::asyncCollisionDetected(MsgCollisionDetection &res) {
	/**/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_CollisionDetected);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.x = static_cast<int>((msg.data[0] << 8) | msg.data[1]);
	res.y = static_cast<int>((msg.data[2] << 8) | msg.data[3]);
	res.z = static_cast<int>((msg.data[4] << 8) | msg.data[5]);

	res.axis = static_cast<int>(msg.data[6]);

	res.xMagnitude = static_cast<int>((msg.data[7] << 8) | msg.data[8]);
	res.yMagnitude = static_cast<int>((msg.data[9] << 8) | msg.data[10]);

	res.speed = static_cast<int>(msg.data[11]);

	res.timestamp = static_cast<int>((msg.data[12] << 24) | (msg.data[13] << 16) | (msg.data[14] << 8) | msg.data[15]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncOrbBasicPrintMessage(std::string &res) {
	/*The orbBasic PRINT ID 08h is akin to STDOUT*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_orbBasicPrintMessage);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream aux;
	aux << "MESSAGE: ";
	for (int i = 0; i < msg.data.size(); i++) aux << char(msg.data[i]);
	res = aux.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncOrbBasicErrorMessageASCII(std::string &res) {
	/* 09h to STDER*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_orbBasicErrorMessageASCII);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream aux;
	aux << "ERROR: ";
	for (int i = 0; i < msg.data.size(); i++) aux << char(msg.data[i]);
	res = aux.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncOrbBasicErrorMessageBinary(std::string &res) {
	/*d 0Ah a machine readable version of STDERR*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_orbBasicErrorMessageBinary);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	std::stringstream aux;
	aux << "ERROR binary: ";
	for (int i = 0; i < msg.data.size(); i++) aux << char(msg.data[i]);
	res = aux.str();

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncSelfLevelResult(int &res) {
	/*The result byte can be: 00h = Unknown, 01h = Timed Out (level was not achieved), 02h = Sensors Error,
	03h = Self Level Disabled (see Option Flags), 04h = Aborted (by API call), 05h = Charger not found,
	06h = Success*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_SelfLevelResult);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncGyroAxisLimitExceeded(MsgGyroAxisLimitExceeded &res) {
	/*The Gyro Axis Limit Exceeded message contains one byte of data where the bits
	signify the axes that exceeded the limit: bit 0 = X positive, bit 1 = X negative,
	bit 2 = Y+, bit 3 = Y-, bit 4 = Z+ and bit 5 = Z-. The message is emitted when one
	threshold is exceeded and all of the max measurements are cleared upon receipt of
	a Set Heading API command (DID 02h, CID 01h)*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_GyroAxisLimitExceeded);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.x = static_cast<int>((msg.data[0]) & 0x01);
	res.xn = static_cast<int>((msg.data[0] >> 1) & 0x01);
	
	res.y = static_cast<int>((msg.data[0] >> 2) & 0x01);
	res.yn = static_cast<int>((msg.data[0] >> 3) & 0x01);
		
	res.z = static_cast<int>((msg.data[0] >> 4) & 0x01);
	res.zn = static_cast<int>((msg.data[0] >> 5) & 0x01);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncSpheroSoulData(std::vector<ubyte> &res) {
    /*This command retrieves Sphero's Soul Block. The response is simple and then the actual block of
    soulular data returns in an asynchronous message of type 0Dh due to its 0x400 byte length (if there is no
    error).*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_SpheroSoulData);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.insert(res.end(), msg.data.begin(), msg.data.end());

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncLevelUpNotification(MsgLevelUpNotification &res) {
	/*The level up notification contains two 16-bit unsigned integers. The first is the
	new robot level. The second is the total number of attribute points the user has
	to spend.*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_LevelUpNotification);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res.level = static_cast<int>((msg.data[0] << 8) | msg.data[1]);
	res.attributes = static_cast<int>((msg.data[2] << 8) | msg.data[3]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncShieldDamageNotification(int &res) {
	/*The Shield damage notification contains one unsigned byte representing the portion of
	shield left (out of 255). The shields are damaged when Sphero collides with other objects.
	The shields are regenerate automatically over time. Both collisions and regeneration
	generate asynchronous updates.*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_ShieldDamageNotification);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncXPUpdateNotification(int &res) {
	/*The XP update notification contains one byte representing how much experience Sphero
	has gained toward the next robot level. The scale is from 0=0% to 255=100%.*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_XPUpdateNotification);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}

ResponseCode Sphero::asyncBoostUpdateNotification(int &res) {
	/*The boost update notification contains one byte representing how much boost capability
	Sphero has. The value goes down when boost is used and automatically regenerates over time.
	Regeneration and use both generate asynchronous updates. The scale is from 0=0% to 255=100%*/

	SpheroMessage msg = adaptor.receiveAsync(AsyncResponseId_BoostUpdateNotification);
	if (msg.responseCode != ResponseCode_OK) return msg.responseCode;

	res = static_cast<int>(msg.data[0]);

	return ResponseCode_OK;
}
