#pragma once
#include <algorithm>
#include <vector>

typedef uint8_t ubyte;
typedef uint16_t ushort;

typedef uint32_t uint;

typedef std::vector<ubyte> CommandParameters;

enum DeviceId {
	DeviceId_CORE = 0x00,
	DeviceId_BOOTLOADER = 0x01,
	DeviceId_SPHERO = 0x02
};

enum CoreCommandId {
	CoreCommandId_PING = 0x01,
	CoreCommandId_VERSION = 0x02,
	CoreCommandId_CONTROL_UART_TX = 0x03,
	CoreCommandId_SET_BT_NAME = 0x10,
	CoreCommandId_GET_BT_NAME = 0x11,
	CoreCommandId_SET_AUTO_RECONNECT = 0x12,
	CoreCommandId_GET_AUTO_RECONNECT = 0x13,
	CoreCommandId_GET_PWR_STATE = 0x20,
	CoreCommandId_SET_PWR_NOTIFY = 0x21,
	CoreCommandId_SLEEP = 0x22,
	CoreCommandId_GET_POWER_TRIPS = 0x23,
	CoreCommandId_SET_POWER_TRIPS = 0x24,
	CoreCommandId_SET_INACTIVE_TIMER = 0x25,
	CoreCommandId_GOTO_BL = 0x30,
	CoreCommandId_RUN_L1_DIAGS = 0x40,
	CoreCommandId_RUN_L2_DIAGS = 0x41,
	CoreCommandId_CLEAR_COUNTERS = 0x42,
	CoreCommandId_ASSIGN_TIME = 0x50,
	CoreCommandId_POLL_TIMES = 0x51
};

enum BootloaderCommandId {
	BootloaderCommandId_BEGIN_REFLASH = 0x02,
	BootloaderCommandId_HERE_IS_PAGE = 0x03,
	BootloaderCommandId_LEAVE_BOOTLOADER = 0x04,
	BootloaderCommandId_IS_PAGE_BLANK = 0x05,
	BootloaderCommandId_CMD_ERASE_USER_CONFIG = 0x06
};

enum SpheroCommandId {
	SpheroCommandId_SET_CAL = 0x01,
	SpheroCommandId_SET_STABILIZ = 0x02,
	SpheroCommandId_SET_ROTATION_RATE = 0x03,
	SpheroCommandId_SET_CREATION_DATE = 0x04,
	SpheroCommandId_GET_BALL_REG_WEBSITE = 0x05,
	SpheroCommandId_REENABLE_DEMO = 0x06,
	SpheroCommandId_GET_CHASSIS_ID = 0x07,
	SpheroCommandId_SET_CHASSIS_ID = 0x08,
	SpheroCommandId_SELF_LEVEL = 0x09,
	SpheroCommandId_SET_VDL = 0x0A,
	SpheroCommandId_SET_DATA_STREAMING = 0x11,
	SpheroCommandId_SET_COLLISION_DET = 0x12,
	SpheroCommandId_LOCATOR = 0x13,
	SpheroCommandId_SET_ACCELERO = 0x14,
	SpheroCommandId_READ_LOCATOR = 0x15,
	SpheroCommandId_SET_RGB_LED = 0x20,
	SpheroCommandId_SET_BACK_LED = 0x21,
	SpheroCommandId_GET_RGB_LED = 0x22,
	SpheroCommandId_ROLL = 0x30,
	SpheroCommandId_BOOST = 0x31,
	SpheroCommandId_MOVE = 0x32,
	SpheroCommandId_SET_RAW_MOTORS = 0x33,
	SpheroCommandId_SET_MOTION_TO = 0x34,
	SpheroCommandId_SET_OPTIONS_FLAG = 0x35,
	SpheroCommandId_GET_OPTIONS_FLAG = 0x36,
	SpheroCommandId_SET_TEMP_OPTIONS_FLAG = 0x37,
	SpheroCommandId_GET_TEMP_OPTIONS_FLAG = 0x38,
	SpheroCommandId_GET_CONFIG_BLK = 0x40,
	SpheroCommandId_SET_SSB_PARAMS = 0x41,
	SpheroCommandId_SET_DEVICE_MODE = 0x42,
	SpheroCommandId_SET_CFG_BLOCK = 0x43,
	SpheroCommandId_GET_DEVICE_MODE = 0x44,
	SpheroCommandId_GET_SSB = 0x46,
	SpheroCommandId_SET_SSB = 0x47,
	SpheroCommandId_SSB_REFILL = 0x48,
	SpheroCommandId_SSB_BUY = 0x49,
	SpheroCommandId_SSB_USE_CONSUMEABLE = 0x4A,
	SpheroCommandId_SSB_GRANT_CORES = 0x4B,
	SpheroCommandId_SSB_ADD_XP = 0x4C,
	SpheroCommandId_SSB_LEVEL_UP_ATTR = 0x4D,
	SpheroCommandId_GET_PW_SEED = 0x4E,
	SpheroCommandId_SSB_ENABLE_ASYNC = 0x4F,
	SpheroCommandId_RUN_MACRO = 0x50,
	SpheroCommandId_SAVE_TEMP_MACRO = 0x51,
	SpheroCommandId_SAVE_MACRO = 0x52,
	SpheroCommandId_REINIT_MACRO_EXECUTIVE = 0x54,
	SpheroCommandId_ABORT_MACRO = 0x55,
	SpheroCommandId_GET_MACRO_STATUS = 0x56,
	SpheroCommandId_SET_MACRO_PARAMETER = 0x57,
	SpheroCommandId_APPEND_MACRO_CHUNK = 0x58,
	SpheroCommandId_ERASE_ORBBASIC_STORAGE = 0x60,
	SpheroCommandId_APPEND_ORBBASIC_FRAGMENT = 0x61,
	SpheroCommandId_EXECUTE_ORBBASIC_PROGRAM = 0x62,
	SpheroCommandId_ABORT_ORBBASIC_PROGRAM = 0x63,
	SpheroCommandId_SUBMIT_VALUE_TO_INPUT_STATEMENT = 0x64,
	SpheroCommandId_COMMIT_RAM_PROGRAM_TO_FLASH = 0x65
};
