/* 
 * Copyright (c) 1987, 1988, 1989 NeXT, Inc.
 */
/*
 * m68k: the machine-dependent shutdown hooks of the 1997 m68k kernel
 * (plans 613-614, D024, D103, D139), called by kern_shutdown.c boot().
 * Notice above from NeXTMach mk-108.1 next/machdep.c:1-3.  The bodies are
 * written from the original bytes [0x40990ba, 0x4099184) with the lines of
 * the NeXTMach next/machdep.c boot() tail (1272-1328): od_update/od_eject,
 * rtc_power_down, splhigh, the halt and reboot messages, mon_call, mon_boot.
 * 1997 changes: md_prepare_for_shutdown calls adb_watchdog(0); the optical
 * calls run only for machine_type 0 or 2; both messages end in two newlines;
 * no empty RB_PANIC block.  Not taken from boot(): the sync/unmount/buffer
 * part (kern_shutdown.c), the NOC and NCPUS > 1 blocks.  The file name and
 * the void return type are user decisions (D139).  Only the notice and the
 * lines of the boot() tail are NeXTMach text; the marks give each part's source.
 */
#import <sys/param.h>
#import <sys/reboot.h>
#import <kern/task.h>
#import <m68k/cpu.h>
#import <machine/spl.h>

#define	NeXT_CUBE	0	/* plan 614 (D139, D113): NeXTMach next/scr.h:34 */
#define	NeXT_X15	2	/* plan 614 (D139, D113): NeXTMach next/scr.h:36 */

extern void adb_watchdog();

void
md_prepare_for_shutdown(paniced, howto, command)	/* plan 614 (D024, D139): body from the original bytes 0x40990ba */
	int paniced, howto;
	char *command;
{
	adb_watchdog(0);
}

void
md_shutdown_devices(paniced, howto, command)	/* plan 614 (D024, D139): NeXTMach boot() lines, 0x40990ca */
	int paniced, howto;
	char *command;
{
	if (machine_type == NeXT_CUBE || machine_type == NeXT_X15) {
		/*
		 *  Update optical tables after regular I/O has finished.
		 */
		od_update();
		if ((howto & RB_EJECT) && kernel_task)
			od_eject();
	}
}

void
md_do_shutdown(paniced, howto, command)	/* plan 614 (D024, D139): NeXTMach boot() lines, 0x40990fc */
	int paniced, howto;
	char *command;
{
	int s;

	if (howto & RB_POWERDOWN) {
		rtc_power_down();
	}
	s = splhigh();			/* extreme priority */
	if (howto & RB_HALT) {
		printf ("halting...\n\n");
		mon_call ("-h");
	} else {
		printf("rebooting Mach...\n\n");
		if (howto & RB_COMMAND)
			mon_call(command);
		else
			mon_boot(howto & RB_SINGLE? "-s" : 0);
	}
	splx(s);
}
