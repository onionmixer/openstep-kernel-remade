/*
 * ioconf.c (plan 397): the pseudo-device initialisation table that NeXTMach
 * config (src/config/mkioconf.c, NeXT_pseudo_inits) writes; the OPENSTEP 4.2
 * kernel has only this table here (__data [0x1e4f80, 0x1e4f98) =
 * {32, pty_init}, {1, venip_config}, {0, 0}).  Reconstructed generator-output
 * form written from the original bytes (plan 398); not produced by a config run.
 */
#include "sys/param.h"
#import <dev/busvar.h>		/* struct pseudo_init (as driverkit/autoconfCommon.m) */

extern pty_init();
extern venip_config();

struct pseudo_init pseudo_inits[] = {
	32,	pty_init,
	1,	venip_config,
	0,	0,
};
