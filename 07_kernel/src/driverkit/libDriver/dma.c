/*
 * driverkit/libDriver/dma.c (plan 397, 398).
 *
 * IONamedValue strings of the DMA status values (IODMAStatusStrings) in the
 * OPENSTEP 4.2 kernel, __TEXT,__const [0x1d5eac, 0x1d5ee4) 56 B.  The text is
 * nearly the same as Darwin 0.1 driverkit-1/libDriver/dma.c; kept as
 * project-authored under D030, without Darwin's notices (license judgement:
 * D017).
 */

#import <driverkit/driverTypes.h>

const IONamedValue IODMAStatusStrings[] = {
	{IO_None,		"No Status Reported"		},
	{IO_Complete,		"DMA Channel Idle"		},
	{IO_Running,		"DMA Channel Running"		},
	{IO_Underrun,		"DMA Over/Underrun"		},
	{IO_BusError,		"DMA Bus Error"			},
	{IO_BufferError,	"DMA Buffer Error"		},
	{0,			NULL				},
};

