/*
 * Copyright (C) 1990 by NeXT, Inc., All Rights Reserved
 *
 * HISTORY
 * 09-Apr-90  Bradley Taylor (btaylor) at NeXT, Inc.
 *	Created, loosely based upon BSD loopback driver.
 */

/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */ 
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)if_loop.c	7.1 (Berkeley) 6/4/86
 */

#import <sys/types.h>
#import <sys/param.h>
#import <sys/errno.h>
#import <sys/socket.h>
#import <net/netbuf.h>
#import <net/netif.h>
#import <net/if.h>		/* plan 226: IFF_MULTICAST, struct ifreq */

static const char IFTYPE_IP[] = "Internet Protocol";

#define	LOMTU	(1024+512)

netif_t loifp;

netbuf_t
logetbuf(
	 netif_t ifp
	 )
{
	return (nb_alloc(LOMTU));
}

int
looutput(
	 netif_t ifp,
	 netbuf_t nb,
	 void *addr
	 )
{
	struct sockaddr *dst = (struct sockaddr *)addr;
	
	switch (dst->sa_family) {
	case AF_INET:
		inet_queue(ifp, nb);
		break;
	default:
		nb_free(nb);
		return (EAFNOSUPPORT);
	}
	if_opackets_set(ifp, if_opackets(ifp) + 1);
	if_ipackets_set(ifp, if_ipackets(ifp) + 1);
	return (0);
}

/*
 * Process an ioctl request.
 */
/* ARGSUSED */
int
locontrol(
	  netif_t ifp,
	  char *command,
	  void *data
	  )
{
#if	MULTICAST
	struct ifreq *ifr = (struct ifreq *)data;	/* plan 226.1: before error (register choice, original 0x11f4a9) */
#endif
	int error = 0;

	if (strcmp(command, IFCONTROL_SETADDR) == 0) {
		/* plan 226 (authored): IFF_RUNNING as well (original 0x11f4c9) */
		if_flags_set(ifp, if_flags(ifp) | IFF_UP | IFF_RUNNING);
		/*
		 * Everything else is done at a higher level.
		 */
#if	MULTICAST
	} else if (strcmp(command, IFCONTROL_ADDMULTICAST) == 0 ||
		   strcmp(command, IFCONTROL_ADDMULTICAST) == 0) {
		/*
		 * plan 226 (authored, D024; original 0x11f4d8-0x11f505):
		 * only IP multicast groups.  The original compares with
		 * IFCONTROL_ADDMULTICAST twice (0x1d1255 at 0x11f4d8 and
		 * 0x11f4ea); IFCONTROL_RMVMULTICAST is not used.
		 */
		if (ifr->ifr_addr.sa_family != AF_INET)
			error = EAFNOSUPPORT;
#endif	/* MULTICAST */
	} else {
		error = EINVAL;
	}
	return (error);
}

loattach()
{
	loifp = if_attach(NULL, NULL, looutput, logetbuf, locontrol, "lo", 0,
			  IFTYPE_IP, LOMTU, IFF_LOOPBACK | IFF_MULTICAST,	/* plan 226 (0x11f526) */
			  NETIFCLASS_VIRTUAL, NULL);
}
