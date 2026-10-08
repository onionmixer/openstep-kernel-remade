/*
 * Power management through the APM BIOS (plan 254).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024).
 * Darwin 0.1 machdep/i386/APM_i386.c and APM_BIOS.h were consulted for
 * structure only; the control flow is fixed by the bytes, so the text
 * may resemble Darwin's (D027).  Unlike Darwin, PMUpdateClock reads the
 * real-time clock.
 */

#import <mach/mach_types.h>

#import <sys/time.h>

#import <kern/power.h>

#import <machdep/i386/pmap.h>
#import <machdep/i386/seg.h>
#import <machdep/i386/table_inline.h>
#import <machdep/i386/desc_inline.h>
#import <machdep/i386/bios.h>

#import <architecture/i386/frame.h>

/*
 * The APM fields of the boot loader's parameter block at physical
 * 0x11000 (offsets from the original; no i386 kernBootStruct.h in the
 * reference material).
 */
struct apm_boot_config {
	unsigned short	major_vers;		/* +0x368 */
	unsigned short	minor_vers;		/* +0x36a */
	unsigned long	cs32_base;		/* +0x36c */
	unsigned long	cs16_base;		/* +0x370 */
	unsigned long	ds_base;		/* +0x374 */
	unsigned long	cs_length;		/* +0x378 */
	unsigned long	ds_length;		/* +0x37c */
	unsigned long	entry_offset;		/* +0x380 */
	unsigned long	_unused;		/* +0x384 */
	unsigned long	connected;		/* +0x388 */
};

struct apm_boot_struct {
	char			_pad[0x368];
	struct apm_boot_config	apm_config;
};
#define	APM_BOOT_STRUCT	((struct apm_boot_struct *) 0x11000)

/* APM 1.0 function codes (in AL, with AH = 0x53) */
#define APM_BIOS_CODE		0x53
#define APM_BIOS_IDLE		0x05
#define APM_BIOS_BUSY		0x06
#define APM_BIOS_SETSTATE	0x07
#define APM_BIOS_DISABLE	0x08
#define APM_BIOS_DEFAULT	0x09
#define APM_BIOS_GETSTATUS	0x0A
#define APM_BIOS_GETEVENT	0x0B

static unsigned long	APM_BIOS_addr;
static boolean_t	APM_BIOS_connected;
static struct {
	unsigned	major;
	unsigned	minor;
} APM_BIOS_version;

/*
 * Fill in the request for an APM BIOS call through bios32().
 */
static inline void
APMBIOS_init(
    biosBuf_t		*bb,
    unsigned char	code
)
{
    union {
	unsigned short	data;
	sel_t		sel;
    } u;

    bb->eax.r.h = APM_BIOS_CODE;
    bb->eax.r.l = code;
    u.sel = APMCODE32_SEL;
    bb->cs = u.data;
    u.sel = KDS_SEL;
    bb->ds = u.data;
    bb->addr = APM_BIOS_addr;
}

/*
 * Kernel error for the BIOS error code in AH.
 */
static inline PMReturn
APMBIOS_error(
    int		code
)
{
    if (code == 0)
	return PM_R_UNKNOWN;
    return (PMReturn) pm_err(code);
}

static inline PMReturn
APMBIOS_call(
    biosBuf_t		*bb
)
{
    bios32(bb);
    if ((bb->flags & EFL_CF) == 0)
	return PM_R_SUCCESS;
    return APMBIOS_error(bb->eax.r.h);
}

static inline PMReturn
APMBIOS_Idle(void)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_IDLE);
    bios32(&bb);
    if ((bb.flags & EFL_CF) == 0)
	return PM_R_SUCCESS;
    else
	return APMBIOS_error(bb.eax.r.h);
}

static inline PMReturn
APMBIOS_Busy(void)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_BUSY);
    bios32(&bb);
    if ((bb.flags & EFL_CF) == 0)
	return PM_R_SUCCESS;
    else
	return APMBIOS_error(bb.eax.r.h);
}

static inline PMReturn
APMBIOS_SetPowerState(
    unsigned short	deviceID,
    unsigned short	stateID
)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_SETSTATE);
    bb.ebx.rx = deviceID;
    bb.ecx.rx = stateID;
    return APMBIOS_call(&bb);
}

static inline PMReturn
APMBIOS_GetPowerStatus(
    unsigned char	*line_status,
    unsigned char	*batt_status,
    unsigned char	*batt_life
)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_GETSTATUS);
    bb.ebx.rx = 0x0001;
    bios32(&bb);
    if ((bb.flags & EFL_CF) == 0) {
	*line_status = bb.ebx.r.h;
	*batt_status = bb.ebx.r.l;
	*batt_life = bb.ecx.r.l;
	return PM_R_SUCCESS;
    }
    return APMBIOS_error(bb.eax.r.h);
}

static inline PMReturn
APMBIOS_GetPowerEvent(
    unsigned short	*event_code
)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_GETEVENT);
    bios32(&bb);
    if ((bb.flags & EFL_CF) == 0) {
	*event_code = bb.ebx.rx;
	return PM_R_SUCCESS;
    }
    return APMBIOS_error(bb.eax.r.h);
}

static inline PMReturn
APMBIOS_SetSystemPowerManagement(
    int		enabled
)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_DISABLE);
    bb.ecx.rx = enabled ? 1 : 0;
    bb.ebx.rx = 0xffff;			/* all devices */
    return APMBIOS_call(&bb);
}

static inline PMReturn
APMBIOS_RestoreDefaults(void)
{
    biosBuf_t	bb;

    APMBIOS_init(&bb, APM_BIOS_DEFAULT);
    bb.ebx.rx = 0xffff;			/* all devices */
    return APMBIOS_call(&bb);
}

/*
 * Map the BIOS's 32-bit code, 16-bit code and data segments.
 */
static void
APM_map_segments(void)
{
    struct apm_boot_struct	*kbp = APM_BOOT_STRUCT;

    map_code((code_desc_t *) sel_to_gdt_entry(APMCODE32_SEL),
	     (vm_offset_t) KERNEL_LINEAR_BASE + kbp->apm_config.cs32_base,
	     (vm_size_t) kbp->apm_config.cs_length,
	     KERN_PRIV,
	     FALSE);

    map_code_16((code_desc_t *) sel_to_gdt_entry(APMCODE16_SEL),
	     (vm_offset_t) KERNEL_LINEAR_BASE + kbp->apm_config.cs16_base,
	     (vm_size_t) kbp->apm_config.cs_length,
	     KERN_PRIV,
	     FALSE);

    map_data((data_desc_t *) sel_to_gdt_entry(APMDATA_SEL),
	     (vm_offset_t) KERNEL_LINEAR_BASE + kbp->apm_config.ds_base,
	     (vm_size_t) kbp->apm_config.ds_length,
	     KERN_PRIV,
	     FALSE);

    APM_BIOS_addr = kbp->apm_config.entry_offset;
}

PMReturn
PMConnect(void)
{
    struct apm_boot_struct	*kbp = APM_BOOT_STRUCT;

    APM_BIOS_version.major = kbp->apm_config.major_vers;
    APM_BIOS_version.minor = kbp->apm_config.minor_vers;

    if (kbp->apm_config.connected) {
	APM_BIOS_connected = TRUE;
	APM_map_segments();
	printf("Power management is enabled.\n");
	return PM_R_SUCCESS;
    }
    return PM_R_NO_PM;
}

PMReturn
PMDisconnect(void)
{
    return PM_R_SUCCESS;
}

PMReturn
PMSetCpuState(
    PMCpuState		state
)
{
    boolean_t	ret;

    if (APM_BIOS_connected) {
	switch (state) {
	case PM_CPU_IDLE:
	    ret = APMBIOS_Idle();
	    break;
	case PM_CPU_BUSY:
	    ret = APMBIOS_Busy();
	    break;
	default:
	    ret = FALSE;
	}
	/* plan 254: a successful call (0) also ends here, as in the original */
	if (ret == FALSE)
	    return PM_R_BAD_STATE;
    }
    else if (state == PM_CPU_IDLE)
	asm volatile("hlt");

    return PM_R_SUCCESS;
}

PMReturn
PMSetPowerState(
    PMDeviceID		device,
    PMPowerState	state
)
{
    union {
	struct {
	    unsigned int	deviceNumber	:8;
	    unsigned int	deviceType	:8;
	} device;
	unsigned short	data;
    } du;
    union {
	PMPowerState	state;
	unsigned short	data;
    } su;

    if (device.deviceType == PM_SYSTEM && device.deviceNumber == 1)
	_io_setDriverPowerState(state);

    if (APM_BIOS_connected) {
	if (device.deviceType == PM_SYSTEM && device.deviceNumber == 1) {
	    /* the whole system cannot be set to ready or off */
	    if (state == PM_READY || state == PM_OFF)
		return PM_R_BAD_STATE;
	}
	du.device.deviceNumber = device.deviceNumber;
	du.device.deviceType = device.deviceType;
	su.state = state;
	return APMBIOS_SetPowerState(du.data, su.data);
    }
    return PM_R_NOT_CONNECTED;
}

PMReturn
PMGetPowerEvent(
    PMPowerEvent	*event
)
{
    unsigned short	event_code;
    PMReturn		ret;

    if (APM_BIOS_connected) {
	if ((ret = APMBIOS_GetPowerEvent(&event_code)) == PM_R_SUCCESS) {
	    *event = (PMPowerEvent) event_code;
	    return PM_R_SUCCESS;
	}
	return ret;
    }
    return PM_R_NOT_CONNECTED;
}

PMReturn
PMGetPowerStatus(
    PMPowerStatus	*status
)
{
    unsigned char	line_status, batt_status, batt_life;
    PMReturn		ret;

    if (APM_BIOS_connected) {
	if ((ret = APMBIOS_GetPowerStatus(&line_status, &batt_status,
					  &batt_life)) == PM_R_SUCCESS) {
	    status->lineStatus = (PMLineStatus) line_status;
	    status->batteryStatus = (PMBatteryStatus) batt_status;
	    status->batteryLife = (batt_life == 0xff) ? -1 : (int) batt_life;
	    return PM_R_SUCCESS;
	}
	return ret;
    }
    return PM_R_NOT_CONNECTED;
}

PMReturn
PMSetPowerManagement(
    PMDeviceID			device,
    PMPowerManagementState	state
)
{
    if (APM_BIOS_connected) {
	if (device.deviceType == PM_SYSTEM && device.deviceNumber == 1)
	    return APMBIOS_SetSystemPowerManagement(state);
	return PM_R_BAD_ID;
    }
    return PM_R_NOT_CONNECTED;
}

PMReturn
PMRestoreDefaults(void)
{
    if (APM_BIOS_connected)
	return APMBIOS_RestoreDefaults();
    return PM_R_NOT_CONNECTED;
}

void
PMUpdateClock(void)
{
    extern struct timeval	time;

    readtodc(&time);			/* plan 254 */
}
