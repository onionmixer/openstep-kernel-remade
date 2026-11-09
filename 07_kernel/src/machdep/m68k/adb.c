/*
 * plan 766 (D024, D027, D030, D173): the 1997 m68k ADB driver (adb.c).
 * Written from the original bytes [0x4064216, 0x4065bbc) of the OPENSTEP 4.2 m68k
 * mach_kernel (21 functions, 6566 bytes; __cstring 286, __data 48, __const 128, static
 * bss 192 bytes estimated); the diagnostic is plan 765.  There is no reference text for
 * this file: NeXTMach mk-108.1 and Mach4 have no ADB code and Darwin 0.1 has an ADB
 * header (bsd/dev/adb.h, see adb.h) and PPC ADB sources that are not the m68k driver
 * (they were neither imported nor compared).  The 18 external functions are original
 * symbols; adb_intr, adb_reset_ctl and adb_command are static in the original, and the
 * static data names, struct adb_dev, struct adb_kqent, struct adb_bits, ADB_KEY_TRANSLATE
 * and adb_restart_request are given by this project (D173; the bytes do not decide them).
 * The forms below give the original bytes and are not evidence of the original source:
 * block-local volatile pointers for the controller data registers, the rotated goto loop,
 * the post-increment inside the key queue index, the do { } while (0) around the command
 * and delay calls, the scalar modifier byte, the 3 byte array under a bit field overlay,
 * the key code table and the one pointer that reaches the event bytes.  The functions are
 * in the address order of the original.
 */

#import <sys/types.h>
#import <sys/param.h>
#import <mach/boolean.h>
#import <m68k/cpu.h>
#import <machdep/m68k/adb.h>
#import <mon/global.h>
#import <nextdev/kmreg.h>
#import <bsd/dev/ev_types.h>

extern int slot_id;
extern int printf();
extern void delay();
extern void callout_dispatch();

/* hardware: the ADB controller registers used are at slot_id + 0x02208000 (csr 0, 8, 0x18, ctl 0x20, status 0x28, command 0x30, length 0x38, data 0x80 and 0x88) */
/* static data and functions have no symbol in the original: the names below are this project's (provisional, D173) */
int ADB_present = 0;
/* address of the device kept as the default poll target (the mouse, 3, if one answers) */
static int adb_present_addr = 0;
/* address polled by the next talk register 0 command */
static int adb_cur_addr = 0;
extern void adb_null(), adb_keyboard(), adb_mouse();
static void (*adb_handler[8])() = { adb_null, adb_null, adb_keyboard, adb_mouse, adb_null, adb_null, adb_null, adb_null };
static int adb_polling_off = 0;
static int adb_wd_count;
/* one record per address 1..7 found by adb_initialize; next is the ring of found devices (10 bytes) */
struct adb_dev {
	int addr;
	unsigned char type;
	int next;
};
static struct adb_dev adb_dev[16];
/* not referenced; fills the 4 bytes the original has between the device table and the key queue */
static int adb_dev_pad;
/* key queue: two 16 bit entries (up flag, 7 bit ADB key code) filled by adb_keyboard / adb_check_keyboard */
struct adb_kqent {
	unsigned short up:1, code:7, :8;
};
static struct adb_kqent adb_kq[2];
static int adb_kq_head;
static int adb_kq_tail;
/* flag bits (meanings provisional): 0 keyboard found, 1 keyboard accepted handler 3 (LED register 2), 16 mouse found, 17 mouse accepted the Logitech setup, 19 mouse answered the extended protocol */
static int adb_flags;
/* modifier key state (names from the ADB key codes 54/125, 58/124, 56/123, 55; provisional): 0x80 and 0x40 control, 0x20 and 0x10 alt, 8 and 4 shift, 2 command */
static unsigned char adb_kbs0;
/* byte 0: 0x80 caps lock state, 0x40 caps lock LED (struct adb_bits overlay at an odd address; the compiler ignores packed) */
static unsigned char adb_led[3];
struct adb_bits {
	unsigned char caps:1, led:1;
	unsigned char pad[2];
};
#define ADB_LED ((struct adb_bits *)adb_led)
#define adb_led_b0 adb_led[0]
static struct keyboard adb_kbd_event;
extern void uninstall_scanned_intr(), ev_m_intr(), ev_k_intr(), mini_mon(), km_reset(), AllKeysUp();
extern int eventsOpen;
/* ADB key code -> NeXT key code (bytes of the original __const table; entries are masked with 0x7f) */
static const unsigned char adb_keymap[128] = {
	0x39, 0x3a, 0x3b, 0x3c, 0x40, 0x3d, 0x31, 0x32, 0x33, 0x34, 0x0a, 0x35, 0x42, 0x43, 0x44, 0x45,
	0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x4d, 0x4f, 0x50, 0x1c, 0x1f, 0x4e, 0x1d, 0x1e, 0x20, 0x04, 0x07,
	0x46, 0x05, 0x06, 0x08, 0x2a, 0x2d, 0x3f, 0x2b, 0x3e, 0x2c, 0x03, 0x2e, 0x30, 0x37, 0x36, 0x2f,
	0x41, 0x38, 0x26, 0x1b, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x10, 0x0f, 0x16, 0x00,
	0x00, 0x0c, 0x00, 0x25, 0x00, 0x15, 0x00, 0x49, 0x00, 0x00, 0x00, 0x28, 0x0d, 0x00, 0x24, 0x00,
	0x00, 0x27, 0x0b, 0x11, 0x17, 0x14, 0x12, 0x18, 0x13, 0x21, 0x00, 0x22, 0x23, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1a, 0x19, 0x29, 0x00, 0x02, 0x00, 0x01, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00
};
extern struct mon_global *mon_global;
static int adb_intr();
extern void adb_keybd_init(), adb_mouse_init();
extern void adb_talk(), adb_listen();
static void adb_reset_ctl();
static void adb_command();
void adb_watchdog();

/* translate one queued key event into adb_kbd_event; the original has this code once in adb_keyboard and twice in adb_check_keyboard */
#define ADB_KEY_TRANSLATE() \
	e = adb_kq[adb_kq_head++ & 1]; \
	kp = &adb_kbd_event; \
	kp->up_down = e.up; \
	kp->key_code = adb_keymap[e.code]; \
	if (kp->key_code) \
		kp->valid = 1; \
	else \
		kp->valid = 0; \
	if (e.up) { \
		switch (e.code) { \
		case 54: \
			{ unsigned char t; struct keyboard *cp = &adb_kbd_event; \
			t = adb_kbs0; \
			adb_kbs0 = t & 0x7f; \
			cp->control = (t & 0x40) != 0; } \
			break; \
		case 125: \
			{ unsigned char t; struct keyboard *cp = &adb_kbd_event; \
			t = adb_kbs0; \
			adb_kbs0 = t & 0xbf; \
			cp->control = (t >> 7) != 0; } \
			break; \
		case 55: \
			adb_kbs0 &= ~2; \
			adb_kbd_event.command_right = 0; \
			adb_kbd_event.command_left = 0; \
			break; \
		case 56: \
			adb_kbs0 &= ~8; \
			adb_kbd_event.shift_left = 0; \
			break; \
		case 123: \
			adb_kbs0 &= ~4; \
			if (!(adb_led_b0 & 0x80)) \
				adb_kbd_event.shift_right = 0; \
			break; \
		case 58: \
			adb_kbd_event.alt_left = 0; \
			adb_kbs0 &= ~0x20; \
			break; \
		case 124: \
			adb_kbd_event.alt_right = 0; \
			adb_kbs0 &= ~0x10; \
			break; \
		case 57: \
			adb_led_b0 &= 0x7f; \
			if (!(adb_kbs0 & 4)) \
				adb_kbd_event.shift_right = 0; \
			adb_keyboard_LED(0); \
			break; \
		} \
	} else { \
		switch (e.code) { \
		case 54: \
			{ unsigned char t; struct keyboard *cp = &adb_kbd_event; \
			t = adb_kbs0 | 0x80; \
			adb_kbs0 = t; \
			cp->control = (t & 0xc0) != 0; } \
			break; \
		case 125: \
			{ unsigned char t; struct keyboard *cp = &adb_kbd_event; \
			t = adb_kbs0 | 0x40; \
			adb_kbs0 = t; \
			cp->control = (t & 0xc0) != 0; } \
			break; \
		case 55: \
			adb_kbs0 |= 2; \
			adb_kbd_event.command_right = 1; \
			adb_kbd_event.command_left = 1; \
			break; \
		case 56: \
			adb_kbs0 |= 8; \
			adb_kbd_event.shift_left = 1; \
			break; \
		case 123: \
			adb_kbs0 |= 4; \
			adb_kbd_event.shift_right = 1; \
			break; \
		case 58: \
			adb_kbd_event.alt_left = 1; \
			adb_kbs0 |= 0x20; \
			break; \
		case 124: \
			adb_kbd_event.alt_right = 1; \
			adb_kbs0 |= 0x10; \
			break; \
		case 57: \
			adb_led_b0 |= 0x80; \
			adb_kbd_event.shift_right = 1; \
			adb_keyboard_LED(1); \
			break; \
		} \
	}

/* probe addresses 1..7 (talk register 3), set service request, run the keyboard / mouse initializers, install adb_intr */
void
adb_initialize()
{
	int first = 0;
	int last = 0;
	volatile int *p18 = (volatile int *)(slot_id + 0x02208018);
	volatile int *p08 = (volatile int *)(slot_id + 0x02208008);
	struct mon_global *mg = mon_global;
	adb_data_t data;
	int len;
	int addr;

	*p18 = 0;
	*p08 = 0;
	adb_reset_ctl(1);
	for (addr = 1; addr <= 7; addr++) {
		adb_talk(addr, 3, &data, &len);
		if (len == 0)
			continue;
		{
			struct adb_dev *dp = &adb_dev[addr];

			dp->addr = addr;
			dp->type = data.byte.data[1];
		}
		printf("ADB device %x reg3 %02x%02x\n", addr, data.byte.data[0], data.byte.data[1]);
		if (!data.reg3.serviceReqEnb) {
			data.reg3.serviceReqEnb = 1;
			adb_listen(addr, 3, &data, len);
		}
		if (addr == 2)
			adb_keybd_init(2, &data);
		else if (addr == 3)
			adb_mouse_init(3, &data);
		if (first == 0)
			first = addr;
		else
			adb_dev[last].next = addr;
		last = addr;
		if (adb_present_addr != 3)
			adb_present_addr = last;
	}
	if (last)
		adb_dev[last].next = first;
	if ((adb_cur_addr = adb_present_addr) != 0) {
		callout_dispatch(2, adb_intr, 0);
		mg->mg_flags2 |= 0x10000000;
		adb_watchdog(1);
		do {
			adb_cmd_t cmd;

			cmd.reg.addr = adb_cur_addr;
			cmd.reg.cmd = ADB_talk;
			cmd.reg.reg = 0;
			adb_command(cmd, 0, 0, 0);
		} while (0);
	}
}

void
adb_suspend_poll()
{
	adb_polling_off = 1;
}

void
adb_resume_poll()
{
	adb_cmd_t cmd;

	adb_polling_off = 0;
	cmd.reg.addr = adb_cur_addr;
	cmd.reg.cmd = ADB_talk;
	cmd.reg.reg = 0;
	adb_command(cmd, 0, 0, 0);
}

/* callout handler: reads the controller status and dispatches the received data to adb_handler[address] */
static int
adb_intr()
{
	volatile int *statp = (volatile int *)(slot_id + 0x02208028);
	volatile int *csrp = (volatile int *)(slot_id + 0x02208000);
	volatile int *ctlp = (volatile int *)(slot_id + 0x02208020);
	int csr, stat;
	adb_data_t data;
	struct adb_dev *dp;
	adb_cmd_t cmd;

	csr = *csrp;
	*csrp = csr;
	stat = *statp;
	*ctlp = 16;
	if (adb_polling_off)
		return 1;
	if (csr & 4) {
		dp = &adb_dev[adb_cur_addr];
		if (stat & 8) {
			volatile unsigned int *lp = (volatile unsigned int *)(slot_id + 0x02208038);
			int len = *lp >> 3;

			if (len > 0) {
				volatile int *dp = (volatile int *)(slot_id + 0x02208080);
				data.longword.data0 = *dp;
			}
			if (len > 4) {
				volatile int *dp = (volatile int *)(slot_id + 0x02208088);
				data.longword.data1 = *dp;
			}
			(*adb_handler[dp->addr])(&data, len);
		}
		if (stat & 2)
			adb_cur_addr = dp->next;
		else
			adb_cur_addr = adb_present_addr;
	} else if (stat & 0x20)
		return 1;
	cmd.reg.addr = adb_cur_addr;
	cmd.reg.cmd = ADB_talk;
	cmd.reg.reg = 0;
	adb_command(cmd, 0, 0, 0);
	return 1;
}

int
adb_poll_keyboard(data)
	adb_data_t *data;
{
	int got = 0;
	volatile int *statp = (volatile int *)(slot_id + 0x02208028);
	volatile int *csrp = (volatile int *)(slot_id + 0x02208000);
	volatile int *ctlp = (volatile int *)(slot_id + 0x02208020);
	int csr, stat;

	if (adb_present_addr == 0)
		return 0;
	csr = *csrp;
	*csrp = csr;
	stat = *statp;
	*ctlp = 16;
	if (csr & 4) {
		if (adb_cur_addr == 2 && (stat & 8)) {
			volatile unsigned int *lp = (volatile unsigned int *)(slot_id + 0x02208038);
			int len = *lp >> 3;

			if (len > 0) {
				volatile int *dp = (volatile int *)(slot_id + 0x02208080);
				data->longword.data0 = *dp;
			}
			if (len > 4) {
				volatile int *dp = (volatile int *)(slot_id + 0x02208088);
				data->longword.data1 = *dp;
			}
			got = 1;
		}
	} else if (stat & 0x20)
		goto done;
	adb_cur_addr = 2;
	do {
		adb_cmd_t cmd;

		cmd.reg.addr = 2;
		cmd.reg.cmd = ADB_talk;
		cmd.reg.reg = 0;
		adb_command(cmd, 0, 0, 0);
	} while (0);
	do { delay(8000); } while (0);
done:
	return got;
}

static void
adb_reset_ctl(wait)
	int wait;
{
	volatile int *ctlp = (volatile int *)(slot_id + 0x02208020);
	volatile int *csrp = (volatile int *)(slot_id + 0x02208000);

	*csrp = *csrp;
	*ctlp = 8;
	if (wait) {
		while ((*csrp & 8) == 0)
			;
		*csrp = 8;
	}
}

static void
adb_command(cmd, data, len, wait)
	adb_cmd_t cmd;
	adb_data_t *data;
	int len;
	int wait;
{
	volatile int *cmdp = (volatile int *)(slot_id + 0x02208030);
	volatile int *lenp = (volatile int *)(slot_id + 0x02208038);
	volatile int *ctlp = (volatile int *)(slot_id + 0x02208020);
	volatile int *csrp = (volatile int *)(slot_id + 0x02208000);

	*cmdp = cmd.cmd.cmd;
	if (data) {
		if (len > 0) {
			volatile int *dp = (volatile int *)(slot_id + 0x02208080);
			*dp = data->longword.data0;
		}
		if (len > 4) {
			volatile int *dp = (volatile int *)(slot_id + 0x02208088);
			*dp = data->longword.data1;
		}
		*lenp = len << 3;
	} else
		*lenp = 0;
	*ctlp = 4;
	if (wait) {
		while ((*csrp & 4) == 0)
			;
		*csrp = 4;
	}
}

void
adb_talk(addr, reg, data, len)
	int addr;
	int reg;
	adb_data_t *data;
	int *len;
{
	volatile int *statp = (volatile int *)(slot_id + 0x02208028);
	adb_cmd_t cmd;

	cmd.reg.addr = addr;
	cmd.reg.cmd = ADB_talk;
	cmd.reg.reg = reg;
	adb_command(cmd, 0, 0, 1);
	if (*statp & 8) {
		volatile unsigned int *lp = (volatile unsigned int *)(slot_id + 0x02208038);

		if ((*len = *lp >> 3) > 0) {
			volatile int *dp = (volatile int *)(slot_id + 0x02208080);
			data->longword.data0 = *dp;
		}
		if (*len > 4) {
			volatile int *dp = (volatile int *)(slot_id + 0x02208088);
			data->longword.data1 = *dp;
		}
	} else
		*len = 0;
}

void
adb_listen(addr, reg, data, len)
	int addr;
	int reg;
	adb_data_t *data;
	int len;
{
	adb_cmd_t cmd;

	cmd.reg.addr = addr;
	cmd.reg.cmd = ADB_listen;
	cmd.reg.reg = reg;
	adb_command(cmd, data, len, 1);
}

void
adb_force_NMI()
{
	if (dma_chip != 313) {
		adb_watchdog(0);
		*(volatile int *)(slot_id + 0x02200020) |= 1;
		delay(8000);
		adb_watchdog(1);
	}
}

void
adb_watchdog(on)
	int on;
{
	volatile int *p18 = (volatile int *)(slot_id + 0x02208018);
	volatile int *p20 = (volatile int *)(slot_id + 0x02208020);

	if (on == 1)
		adb_wd_count--;
	if (adb_wd_count < 0)
		adb_wd_count = 0;
	if (dma_chip != 313 && adb_wd_count == 0) {
		*p20 = 16;
		if (on == 1) {
			if (adb_cur_addr)
				*p18 = 3;
		} else
			*p18 = 0;
	}
	if (on == 0)
		adb_wd_count++;
}

int
adb_system_info(out, max)
	NXEventSystemDevice *out;
	int max;
{
	int start;
	int addr;
	int i;

	if (adb_present_addr == 0)
		return 0;
	start = adb_present_addr;
	addr = start;
	i = 0;
	do {
		out[i].interface = NX_EVS_DEVICE_INTERFACE_ADB;
		out[i].interface_addr = adb_dev[addr].addr;
		out[i].id = adb_dev[addr].type;
		switch (adb_dev[addr].addr) {
		case 2:
			out[i].dev_type = NX_EVS_DEVICE_TYPE_KEYBOARD;
			break;
		case 3:
			out[i].dev_type = NX_EVS_DEVICE_TYPE_MOUSE;
			break;
		case 4:
			out[i].dev_type = NX_EVS_DEVICE_TYPE_TABLET;
			break;
		default:
			out[i].dev_type = NX_EVS_DEVICE_TYPE_OTHER;
			break;
		}
		addr = adb_dev[addr].next;
		i++;
	} while (i != max && addr != start);
	return i;
}

void
adb_keyboard_LED(on)
	int on;
{
	adb_data_t data;

	if (adb_flags & 2) {
		if (ADB_LED->led != on) {
			data.k_reg2.led_cap_lock = !on;
			data.k_reg2.led_num_lock = 1;
			data.k_reg2.led_scroll_lock = 1;
			ADB_LED->led = on;
			adb_listen(2, 2, &data, 2);
		}
	}
}

void
adb_keybd_init(addr, data)
	int addr;
	adb_data_t *data;
{
	int len;

	adb_flags |= 1;
	uninstall_scanned_intr(0x33a);
	data->reg3.devHandlerID = 3;
	adb_listen(addr, 3, data, 2);
	adb_talk(addr, 3, data, &len);
	if (len == 2 && data->reg3.devHandlerID == 3) {
		adb_flags |= 2;
		adb_talk(addr, 2, data, &len);
		if (len > 1) {
			{ int v = !data->k_reg2.key_cap_lock;
			ADB_LED->caps = v; }
			{ int v = !data->k_reg2.key_cap_lock;
			ADB_LED->led = v; }
			data->k_reg2.led_cap_lock = data->k_reg2.key_cap_lock;
			data->k_reg2.led_num_lock = 1;
			data->k_reg2.led_scroll_lock = 1;
			adb_listen(addr, 2, data, 2);
		}
	}
}

/* a static inline function compiled before adb_keyboard puts its two strings first in __cstring and keeps the watchdog calls uncached, as the original bytes show */
static inline void
adb_restart_request()
{
	adb_watchdog(0);
	mini_mon("restart", "Restart/Power-Off");
	adb_watchdog(1);
}

void
adb_keyboard(data, len)
	adb_data_t *data;
	int len;
{
	struct adb_kqent e;
	int code;
	unsigned char mods;
	struct keyboard *kp;

	if (len < 2 || len > 8) {
		printf("adb_keyboard: event had reg0 length %d\n", len);
		return;
	}
	if (data->k_reg0.key1_code != 0x7f) {
		adb_kq[adb_kq_tail & 1].code = data->k_reg0.key1_code;
		adb_kq[adb_kq_tail++ & 1].up = data->k_reg0.key1_up;
		if (data->k_reg0.key2_code != 0x7f) {
			adb_kq[adb_kq_tail & 1].code = data->k_reg0.key2_code;
			adb_kq[adb_kq_tail++ & 1].up = data->k_reg0.key2_up;
		}
		if (adb_kq_head != adb_kq_tail) {
next:
			ADB_KEY_TRANSLATE();
			if (eventsOpen)
				adb_kbd_event.key_code = e.code;
			code = e.code;
			mods = ((unsigned char *)&adb_kbd_event)[2];
			if (mods & 0x80) {
				switch (code) {
				case 67:
					if ((mods & 0x28) == 0x28) {
						do
							km_reset();
						while ((((unsigned char *)&adb_kbd_event)[2] & 0x28) == 0x28);
					}
					break;
				case 50:
					if (!adb_kbd_event.up_down) {
						if ((mods & 0x28) == 0x28)
							adb_force_NMI();
						else if (mods & 8) {
							adb_restart_request();
						} else
							break;
						AllKeysUp();
						goto test;
					}
					break;
				}
			}
			ev_k_intr(&adb_kbd_event);
test:
			if (adb_kq_head != adb_kq_tail)
				goto next;
		}
	} else {
		printf("adb_keyboard: event with NULL keycodes!\n", len);
		AllKeysUp();
	}
}

int
adb_check_keyboard(out)
	struct keyboard *out;
{
	adb_data_t data;
	struct adb_kqent e;
	struct keyboard *kp;

	if (adb_kq_head != adb_kq_tail) {
		ADB_KEY_TRANSLATE();
		goto done;
	}
	if (!adb_poll_keyboard(&data))
		goto zero;
	if (data.k_reg0.key1_code != 0x7f) {
		adb_kq[adb_kq_tail & 1].code = data.k_reg0.key1_code;
		adb_kq[adb_kq_tail++ & 1].up = data.k_reg0.key1_up;
	}
	if (data.k_reg0.key2_code != 0x7f) {
		adb_kq[adb_kq_tail & 1].code = data.k_reg0.key2_code;
		adb_kq[adb_kq_tail++ & 1].up = data.k_reg0.key2_up;
	}
	if (adb_kq_head == adb_kq_tail)
		goto zero;
	ADB_KEY_TRANSLATE();
done:
	*out = adb_kbd_event;
	return 1;
zero:
	return 0;
}

void
adb_mouse_init(addr, data)
	int addr;
	adb_data_t *data;
{
	int len;

	adb_flags |= 0x10000;
	adb_talk(addr, 3, data, &len);
	data->reg3.devHandlerID = 4;
	adb_listen(addr, 3, data, 2);
	adb_talk(addr, 3, data, &len);
	if (data->reg3.devHandlerID == 4) {
		adb_talk(addr, 1, data, &len);
		if (len == 8) {
			char *names[3] = { "Tablet", "Mouse", "Trackball" };
			char *cls = "unknown";
			unsigned short res;

			printf("Found ADB device using extended protocol:\n");
			printf("ID: %c%c%c%c, ", data->byte.data[0], data->byte.data[1], data->byte.data[2], data->byte.data[3]);
			res = (data->byte.data[4] << 8) | data->byte.data[5];
			printf("resolution %d units/inch, ", res);
			printf("class: %d ", data->byte.data[6]);
			if (data->byte.data[6] <= 2)
				cls = names[data->byte.data[6]];
			printf("(%s) ", cls);
			printf("with %d buttons\n", data->byte.data[7]);
			adb_flags |= 0x80000;
			return;
		}
	}
	adb_talk(addr, 3, data, &len);
	data->reg3.devHandlerID = 3;
	adb_listen(addr, 3, data, 2);
	adb_talk(addr, 3, data, &len);
	if (data->reg3.devHandlerID == 3) {
		adb_talk(addr, 1, data, &len);
		if (len == 8) {
			data->logitech_s13_m_reg1.byteaddr = 0;
			data->logitech_s13_m_reg1.byteval = 0x83;
			adb_listen(addr, 1, data, 8);
			data->logitech_s13_m_reg1.byteaddr = 1;
			data->logitech_s13_m_reg1.byteval = 0x82;
			adb_listen(addr, 1, data, 8);
			data->logitech_s13_m_reg1.byteaddr = 2;
			data->logitech_s13_m_reg1.byteval = 0x81;
			adb_listen(addr, 1, data, 8);
			adb_flags |= 0x20000;
		}
	}
}

void
adb_mouse(data, len)
	adb_data_t *data;
	int len;
{
	struct mouse ev;

	if (len >= 2 && len <= 8) {
		ev.delta_y = ~(data->byte.data[0] & 0x7f) + 1;
		ev.delta_x = ~(data->byte.data[1] & 0x7f) + 1;
		if (len == 3) {
			if (adb_flags & 0x20000) {
				if (data->logitech_s13_m_reg0.middle_down) {
					data->logitech_s13_m_reg0.right_down = 1;
					data->logitech_s13_m_reg0.left_down = 1;
				}
				ev.button_right = data->logitech_s13_m_reg0.right_down ^ 1;
				ev.button_left = data->logitech_s13_m_reg0.left_down ^ 1;
				goto send;
			} else if (adb_flags & 0x80000) {
				if (!(data->byte.data[1] & 0x80)) {
					data->byte.data[2] &= 0x7f;
					data->byte.data[0] &= 0x7f;
				}
				ev.button_right = data->byte.data[2] >> 7;
				ev.button_left = data->byte.data[0] >> 7;
				goto send;
			}
		}
		ev.button_left = data->byte.data[0] >> 7;
		ev.button_right = data->byte.data[1] >> 7;
		if (adb_flags & 0x20000) {
			adb_flags &= ~0x20000;
			adb_mouse_init(3, data);
		}
send:
		ev_m_intr(&ev);
	}
}

int
adb_mouse_present()
{
	return (adb_flags >> 16) & 1;
}

int
adb_keybd_present()
{
	return adb_flags & 1;
}

void
adb_null()
{
}

