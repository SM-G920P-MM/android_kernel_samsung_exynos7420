#ifndef _UAPI_ESOC_CTRL_H_
#define _UAPI_ESOC_CTRL_H_

#define ESOC_CODE		0xCC

#define ESOC_CMD_EXE		_IOW(ESOC_CODE, 1, u32)
#define ESOC_WAIT_FOR_REQ	_IOR(ESOC_CODE, 2, u32)
#define ESOC_NOTIFY		_IOW(ESOC_CODE, 3, u32)
#define ESOC_GET_STATUS		_IOR(ESOC_CODE, 4, u32)
#define ESOC_WAIT_FOR_CRASH	_IOR(ESOC_CODE, 6, u32)
#define ESOC_REG_REQ_ENG	_IO(ESOC_CODE, 7)
#define ESOC_REG_CMD_ENG	_IO(ESOC_CODE, 8)
#define ESOC_SET_CRASH		_IOW(ESOC_CODE, 9, u32)
#define ESOC_GET_CRASH		_IOR(ESOC_CODE, 10, u32)
#define ESOC_SECURE_FAIL	_IO(ESOC_CODE, 11)
#define ESOC_SET_HSIC_READY	_IO(ESOC_CODE, 12)
#define ESOC_GET_RESTARTED	_IOR(ESOC_CODE, 13, u32)
#define ESOC_PANIC		_IO(ESOC_CODE, 14)

/*Link types for communication with external SOCs*/
#define HSIC		"HSIC"
#define HSICPCIe	"HSIC+PCIe"
#define PCIe		"PCIe"

enum esoc_evt {
	ESOC_RUN_STATE = 0x1,
	ESOC_UNEXPECTED_RESET,
	ESOC_ERR_FATAL,
	ESOC_IN_DEBUG,
	ESOC_REQ_ENG_ON,
	ESOC_REQ_ENG_OFF,
	ESOC_CMD_ENG_ON,
	ESOC_CMD_ENG_OFF,
	ESOC_INVALID_STATE,
};

enum esoc_cmd {
	ESOC_PWR_ON = 1,
	ESOC_PWR_OFF,
	ESOC_RESET,
	ESOC_PREPARE_DEBUG,
	ESOC_EXE_DEBUG,
	ESOC_EXIT_DEBUG,
	ESOC_SET_CRASH_OCCURRENCE,
	ESOC_GET_CRASH_OCCURRENCE,
	ESOC_GET_RESTART_REASON,
};

enum esoc_notify {
	ESOC_IMG_XFER_DONE = 1,
	ESOC_BOOT_DONE,
	ESOC_BOOT_FAIL,
	ESOC_IMG_XFER_RETRY,
	ESOC_IMG_XFER_FAIL,
	ESOC_UPGRADE_AVAILABLE,
	ESOC_DEBUG_DONE,
	ESOC_DEBUG_FAIL,
	ESOC_PRIMARY_CRASH,
	ESOC_PRIMARY_REBOOT,
	ESOC_FORCE_CPCRASH,
	ESOC_DIAG_DISABLE,
	ESOC_CP_SILENT_RESET,
};

enum esoc_req {
	ESOC_REQ_IMG = 1,
	ESOC_REQ_DEBUG,
	ESOC_REQ_SHUTDOWN,
};

#ifdef __KERNEL__
/**
 * struct esoc_handle: Handle for clients of esoc
 * @name: name of the external soc.
 * @link: link of external soc.
 * @id: id of external soc.
 */
struct esoc_handle {
	const char *name;
	const char *link;
	unsigned int id;
};
#endif
#endif
