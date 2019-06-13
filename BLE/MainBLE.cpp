#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>

#include "Device.h"

using namespace std;

int main(int argc, const char * argv[]) {
	std::cout << "Hello Sphero!\n";
	
	// SPRK+
	std::string name = "SK-5FD4";
	long addres = 232370790817748;

	// MINI
	//std::string name = "SM-0AF9";
	//long addres = 242689762659065;
	
	Device dev = Device(name, addres);
	std::cout << std::endl;
	
	std::cout << "Name: ";
	std::cout << dev.getName() << std::endl;
	std::cout << std::endl;
	system("pause");

	std::cout << "ID: ";
	std::cout << dev.getDeviceId() << std::endl;
	std::cout << std::endl;
	system("pause");

	std::cout << "Device access information: ";
	//std::cout << dev.getDeviceAccessInformation() << std::endl;
	std::cout << std::endl;
	system("pause");

	std::cout << "Connection status: ";
	std::cout << dev.getConnectionStatus() << std::endl;
	std::cout << std::endl;
	system("pause");
	
	std::cout << "Get all services and characteristics: " << std::endl;
	std::cout << dev.getAll() << std::endl;
	std::cout << std::endl;
	system("pause");
	
	system("pause");
	return(0);
}

/*
SPRK2: {type:"SPRK+", name : "sprkPlusName", prefix : "SK-", displayName : "Sprk+", id : 2, modelNumber : 50}
[n.f.SPHERO.type] : 80, [n.f.OLLIE.type] : 80, [n.f.BB8.type] : 80, [n.f.SPRK2.type] : 80,

function(e, t, r){
	r(11),
		r(9);
	const n = r(1), i = r(17), a = r(53), o = r(52), s = r(51), u = r(50);
	e.exports = class extends
		i {
		constructor(e) {
			super(e), new n({ "Class Name": "TOY SPHERO" }),
				this.driveControl = new o({ this: this }),
				this.ledControl = new s({ this:this }),
				this.activationsStatsControl = new u({ this:this,statsManager : e.statsManager }),
				this.sensorControl = new a({ this:this,supportedSensors : {
					Attitude: {key:"attitude",sensors : {
						Pitch: {key:"pitch",value : 262144,mask : 1,modifier : null},
						Roll : {key:"roll",value : 131072,mask : 1,modifier : null},
						Yaw : {key:"yaw",value : 65536,mask : 1,modifier : null}}},
					Accelerometer : {key:"accelerometer",sensors : {
						X: {key:"x",value : 32768,mask : 1,modifier : function(e) {return e / 4096}},
						Y : {key:"y",value : 16384,mask : 1,modifier : function(e) {return e / 4096}},
						Z : {key:"z",value : 8192,mask : 1,modifier : function(e) {returne / 4096}}}},
					Gyroscope:{key:"gyroscope",sensors : {
						X: {key:"x",value : 4096,mask : 1,modifier : function(e) { return.1*e }},
						Y : {key:"y",value : 2048,mask : 1,modifier : function(e) { return.1*e }},
						Z : {key:"z",value : 1024,mask : 1,modifier : function(e) { return.1*e }}}},
					BackEmf : {key:"backEmf",sensors : {
						Left: {key:"left",value : 64,mask : 1,modifier : null},
						Right : {key:"right",value : 32,mask : 1,modifier : null}}},
					Quaternion : {key:"quaternion",sensors : {
						X: {key:"x",value : 2147483648,mask : 2,modifier : function(e) { return e / 1e4}},
						Y : {key:"y",value : 1073741824,mask : 2,modifier : function(e) {return e / 1e4}},
						Z : {key:"z",value : 536870912,mask : 2,modifier : function(e) {return e / 1e4}},
						W : {key:"w",value : 268435456,mask : 2,modifier : function(e) {return e / 1e4}}}},
					Locator:{key:"locator",sensors : {
						X: {key:"x",value : 134217728,mask : 2,modifier : null},
						Y : {key:"y",value : 67108864,mask : 2,modifier : null}}},
					AccelOne : {key:"accelOne",sensors : {AccelOne: {key:"accelOne",value : 33554432,mask : 2,modifier : null}}},
					Velocity : {key:"velocity",sensors : {
						X: {key:"x",value : 16777216,mask : 2,modifier : function(e) { return.1*e }},
						Y : {key:"y",value : 8388608,mask : 2,modifier : function(e) { return.1*e }}}},
					Speed : {key:"speed",sensors : {Speed: {key:"speed",value : 4194304,mask : 2,modifier : null}}}} }),

this.getSupportedFirmwareVersion = function() { return"1.0" },
this.addCommand("0x00", "Ping", "0x00", "0x01"),
this.addCommand("0x00", "GetVersions", "0x00", "0x02"),
this.addCommand("0x00", "Set BluetoothName", "0x00", "0x10"),
this.addCommand("0x00", "Get BluetoothInfo","0x00","0x11"),
this.addCommand("0x00","Get PowerState","0x00","0x20"),
this.addCommand("0x00","Enable Battery State ChangedNotify","0x00","0x21"),
this.addCommand("0x00","Sleep","0x00","0x22"),
this.addCommand("0x00","SetInactivity Timeout","0x00","0x25"),
this.addCommand("0x00","Get Charger	State","0x00","0x26"),
this.addCommand("0x00","Jump To Bootloader","0x00","0x30"),
this.addCommand("0x01","Begin Reflash","0x01","0x02"),
this.addCommand("0x01","Here Is Page","0x01","0x03"),
this.addCommand("0x01","Jump To Main","0x01","0x04"),
this.addCommand("0x02","Set Heading","0x02","0x01"),
this.addCommand("0x02","Set Stabilization","0x02","0x02"),
this.addCommand("0x02","Set Rotation Rate","0x02","0x03"),
this.addCommand("0x02","Get Chassis Id","0x02","0x07"),
this.addCommand("0x02","Set Chassis Id","0x02","0x08"),
this.addCommand("0x02","Self Level","0x02","0x09"),
this.addCommand("0x02","Set Data Streaming","0x02","0x11"),
this.addCommand("0x02","Configure Collision Detection","0x02","0x12"),
this.addCommand("0x02","Configure Locator","0x02","0x13"),
this.addCommand("0x02","Get Temperature","0x02","0x16"),
this.addCommand("0x02","Set Main Led","0x02","0x20"),
this.addCommand("0x02","Set Back Led Brightness","0x02","0x21"),
this.addCommand("0x02","Roll","0x02","0x30"),
this.addCommand("0x02","Boost","0x02","0x31"),
this.addCommand("0x02","Set Raw Motors","0x02","0x33"),
this.addCommand("0x02","Set Motion Timeout","0x02","0x34"),
this.addCommand("0x02","Set Persistent Options","0x02","0x35"),
this.addCommand("0x02","Get Persistent Options","0x02","0x36"),
this.addCommand("0x02","Set Temporary Options","0x02","0x37"),
this.addCommand("0x02","Get Temporary Options","0x02","0x38"),
this.addNotification("0xFF","Battery State Changed Notify","0xFF","0x01"),
this.addNotification("0xFF","Sensor Streaming Data Notify","0xFF","0x03"),
this.addNotification("0xFF","Config Block Contents Notify","0xFF","0x04"),
this.addNotification("0xFF","Will Sleep Notify","0xFF","0x05"),
this.addNotification("0xFF","Collision Detected Notify","0xFF","0x07"),
this.addNotification("0xFF","Gyro Max Notify","0xFF","0x0C"),
this.addNotification("0xFF","Did Sleep Notify","0xFF","0x14")}}}
*/