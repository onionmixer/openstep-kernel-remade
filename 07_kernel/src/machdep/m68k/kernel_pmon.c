/* 
 * Copyright (c) 1990 NeXT, Inc.
 *
 * This file contains the basic data structures that form the interface between
 * the loadable PMON server and the rest of the kernel.
 *
 * HISTORY
 *
 * 1-Feb-89	Brian Pinkerton at NeXT
 *	Created
 *
 */
/*
 * src/machdep/m68k/kernel_pmon.c -- m68k OPENSTEP 4.2 PMON hooks (plans 640-642, D146).
 * NeXTMach mk-108.1 next/kernel_pmon.c (notice and HISTORY above kept, D013) with
 * the 1997 additions written from the original bytes (D024): row m68k-276
 * [0x4092a1a, 0x4092c50) _kpmon_null and the four pmonlog* functions, __data
 * [0x40b28da, 0x40b28ee) and the __common names _vm_saved_context_data0/1/name.
 * The data and function names are the original external symbols; argument and
 * local names are this project's.
 */
#import <next/kernel_pmon.h>
#import <kern/time_stamp.h>	/* plan 642 (D146): struct tsval */
#import <machdep/m68k/eventc.h>	/* plan 642 (D146): event_set_ts, as in the original _pmonlogevent */
#import <vm/vm_page.h>		/* plan 642 (D146): vm_page_wire_count, vm_page_free_count, thread_t */

extern char	*strncpy();		/* plan 642 (D146) */

#define	PMON	1	/* plan 642 (D146): the 1997 kernel has these without DEBUG (user decision) */

#ifdef	PMON

int pmon_flags[40];	/* event masks for each source */
	/* plan 642 (D146): 40, not PMON_KERNEL_SOURCES_MAX (100): the original __common has 160 B
	   from _pmon_flags to the next symbol (user decision) */

/* plan 642 (D024, D146): the original __data [0x40b28da, 0x40b28ea), before _pmon_event_log_p */
int		vm_saved_context_flushed = 0;
thread_t	vm_saved_context_thread = 0;
int		vm_flushed_thread = 0;
int		periodic_vminfo = 0;

void kpmon_null();
void(*pmon_event_log_p)() = kpmon_null;	/* pointer to pmon_event_log() */

/* plan 642 (D024, D146): the original __common _vm_saved_context_data0/1/name */
unsigned short	vm_saved_context_data0;
unsigned short	vm_saved_context_data1;
char		vm_saved_context_name[12];

void kpmon_null() {
}

/* plan 642 (D024, D146): from the original bytes 0x4092a22 */
void
pmonlogevent(source, event_type, data1, data2, data3)
	int	source, event_type;
	int	data1, data2, data3;
{
	struct tsval	event_timestamp;

	event_set_ts(&event_timestamp);
	(*pmon_event_log_p)(source, event_type, &event_timestamp,
	    data1, data2, data3);
}

/* plan 642 (D024, D146): from the original bytes 0x4092aee */
void
pmonlogcontext(source, event_type, thread, name)
	int	source, event_type;
	thread_t thread;
	char	*name;
{
	char	*cp;
	int	i;

	if (thread == vm_saved_context_thread)
		return;
	vm_saved_context_flushed = 0;
	vm_saved_context_thread = thread;
	vm_saved_context_data0 = vm_page_wire_count;
	vm_saved_context_data1 = vm_page_free_count;
	for (cp = name + 1; *cp; cp++)
		;
	for (i = 0; i < 12; i++)
		if (--cp <= name)
			break;
	strncpy(vm_saved_context_name, cp, 12);
}

/* plan 642 (D024, D146): from the original bytes 0x4092b56 */
void
pmonlogexec(source, event_type, thread, name)
	int	source, event_type;
	thread_t thread;
	char	*name;
{
	unsigned short	data0, data1;
	char		buf[12];
	char		*cp;
	int		i;

	data0 = vm_page_wire_count;
	data1 = vm_page_free_count;
	for (cp = name + 1; *cp; cp++)
		;
	for (i = 0; i < 12; i++)
		if (--cp <= name)
			break;
	strncpy(buf, cp, 12);
	pmonlogevent(source, event_type, thread, (data0 << 16) | data1, 0);
	pmonlogevent(source, 0x08000000,
	    ((int *)buf)[0], ((int *)buf)[1], ((int *)buf)[2]);
}

/* plan 642 (D024, D146): from the original bytes 0x4092be4 */
void
pmonlogcontextflush(source, event_type)
	int	source, event_type;
{
	if (vm_saved_context_flushed)
		return;
	vm_saved_context_flushed = 1;
	pmonlogevent(source, event_type, vm_saved_context_thread,
	    (vm_saved_context_data0 << 16) | vm_saved_context_data1, 0);
	pmonlogevent(source, 0x20000000, ((int *)vm_saved_context_name)[0],
	    ((int *)vm_saved_context_name)[1], ((int *)vm_saved_context_name)[2]);
}


#endif	PMON

