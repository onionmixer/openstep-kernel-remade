/*
 * plan 766 (D024, D032, D173): ADB types of the 1997 m68k kernel (adb.h).
 * nearly the same as Darwin 0.1 kernel/bsd/dev/adb.h (kernel-1.tar.gz): the union views
 * (adb_data_t: longword, byte, reg3, m_reg0, logitech_s13_m_reg0, k_reg0, k_reg2,
 * logitech_s13_m_reg1) and the ADB_ADDR_* values are Darwin's text; this file is project
 * authored without Darwin's notice (D030, D032; license judgement is the user's).
 * Differences: no KERNEL_PRIVATE condition, no notices or comments, no declarations, no
 * import of ev_types.h, adb_cmd_t.cmd has a pad byte (the original passes adb_cmd_t by
 * value in a 2 byte slot: movew %d1,%sp@-; subqw #2,%sp), the ADB_reset/flush/listen/talk
 * values are defined here and not inside the structure.  Which views the original source
 * had is not known; these are the views the bytes of adb.c use.
 */
#ifndef _NEXTDEV_ADB_H_
#define _NEXTDEV_ADB_H_
typedef union {
    struct { unsigned char cmd; unsigned char pad; } cmd;
    struct { unsigned char addr:4, cmd:4; } gen;
    struct { unsigned char addr:4, cmd:2, reg:2; } reg;
} adb_cmd_t;
#define ADB_reset	0
#define ADB_flush	1
#define ADB_listen	2
#define ADB_talk	3
typedef union {
    struct { unsigned data0; unsigned data1; } longword;
    struct { unsigned char data[8]; } byte;
    struct { unsigned short :1, exceptionalEvent:1, serviceReqEnb:1, :1, addr:4, devHandlerID:8; } reg3;
    struct { unsigned short left_up:1, Y_delta:7, right_up:1, X_delta:7; } m_reg0;
    struct { unsigned int left_up:1, Y_delta:7, :1, X_delta:7, :5, left_down:1, middle_down:1, right_down:1, :8; } logitech_s13_m_reg0;
    struct { unsigned short key1_up:1, key1_code:7, key2_up:1, key2_code:7; } k_reg0;
    struct { unsigned short :1, key_delete:1, key_cap_lock:1, key_reset:1, key_control:1, key_shift:1, key_alt:1, key_command:1, key_num_lock:1, key_scroll_lock:1, :3, led_scroll_lock:1, led_cap_lock:1, led_num_lock:1; } k_reg2;
    struct { unsigned char byteaddr, byteval, _unknown1_, _unknown2_, right_button, middle_button, left_button, _unknown3_; } logitech_s13_m_reg1;
} adb_data_t;
#define ADB_ADDR_INVALID	0
#define ADB_ADDR_LOW		1
#define ADB_ADDR_KEYBOARD	2
#define ADB_ADDR_MOUSE		3
#define ADB_ADDR_TABLET		4
#define ADB_ADDR_SOFT		8
#define ADB_ADDR_HIGH		15
#endif
