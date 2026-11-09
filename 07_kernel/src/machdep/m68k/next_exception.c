/* 
 * Copyright (c) 1989 NeXT, Inc.
 *
 * HISTORY
 * 17-Feb-88  John Seamons (jks) at NeXT
 *	Created (from VAX version).
 */

/*
 * plan 602 (D104, D135): the 1997 m68k machine_exception [0x4094ab2,
 * 0x4094afe) is this NeXTMach mk-108.1 next/next_exception.c text unchanged;
 * only the three include lines are written with their OPENSTEP paths
 * (marked plan 602).
 */

#import <mach/boolean.h>	/* plan 602 (D104): NeXTMach <sys/boolean.h> */
#import <mach/exception.h>	/* plan 602 (D104): NeXTMach <sys/exception.h> */
#import <mach/kern_return.h>	/* plan 602 (D104): NeXTMach <sys/kern_return.h> */
#import <sys/signal.h>

/*
 *	machine_exception translates a mach exception to a unix exception
 *	and code.  This handles all the hardware-specific exceptions for
 *	NeXT.  unix_exception() handles the machine-independent ones.
 *
 *	FIXME: create real codes & subcodes in next/exception.h
 */

boolean_t machine_exception(exception, code, subcode, unix_signal, unix_code)
int	exception, code, subcode;
int	*unix_signal, *unix_code;
{
	switch(exception) {

	    case EXC_BAD_INSTRUCTION:
	        *unix_signal = SIGILL;
		*unix_code = code;
		break;

	    case EXC_ARITHMETIC:
	        *unix_signal = SIGFPE;
		*unix_code = code;
		break;

	    case EXC_EMULATION:
	        *unix_signal = SIGEMT;
		*unix_code = code;
		break;

	    default:
		return(FALSE);
	}
	return(TRUE);
}
