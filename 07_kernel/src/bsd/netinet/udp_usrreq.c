/* 
 * Mach Operating System
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */ 
 
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	@(#)udp_usrreq.c	7.5 (Berkeley) 3/11/88
 *
 * HISTORY
 * 25-Sep-89  Morris Meyer (mmeyer) at NeXT
 *	NFS 4.0 Changes: protect udp_usrreq with splnet() to avoid race
 *			 in_pcballoc.
 *
 * 20-Oct-87  Peter King (king) at NeXT
 *	SUN_RPC: Increase packet size.
 *
 * 21-Jun-86  Mike Accetta (mja) at Carnegie-Mellon University
 *	Added temporary check against sending ICMP replies to
 *	a wide variety of broadcast addresses until this is handled
 *	better at a lower level.
 *
 */
 
#import <sun_rpc.h>

#import <sys/param.h>
#import <sys/dir.h>
#import <sys/user.h>
#import <sys/mbuf.h>
#import <sys/protosw.h>
#import <sys/socket.h>
#import <sys/socketvar.h>
#import <sys/errno.h>
#import <sys/stat.h>

#import <machine/spl.h>

#import <net/if.h>
#import <net/route.h>

#import <netinet/in.h>
#import <netinet/in_pcb.h>
#import <netinet/in_systm.h>
#import <netinet/in_var.h>
#import <netinet/ip.h>
#import <netinet/ip_var.h>
#import <netinet/ip_icmp.h>
#import <netinet/udp.h>
#import <netinet/udp_var.h>

/*	@(#)udp_usrreq.c	2.2 88/05/23 4.0NFSSRC SMI;	from UCB 7.1 6/5/86	*/

/*
 * UDP protocol implementation.
 * Per RFC 768, August, 1980.
 */
udp_init()
{

	udb.inp_next = udb.inp_prev = &udb;
}

#ifndef	COMPAT_42
int	udpcksum = 1;
#else
int	udpcksum = 0;		/* XXX */
#endif
int	udp_ttl = UDP_TTL;

struct	sockaddr_in udp_in = { AF_INET };

udp_input(m0, ifp)
	struct mbuf *m0;
	struct ifnet *ifp;
{
	register struct udpiphdr *ui;
	register struct inpcb *inp;
	register struct mbuf *m;
	int len;
	struct ip ip;

	/*
	 * Get IP and UDP header together in first mbuf.
	 */
	m = m0;
	if ((m->m_off > MMAXOFF || m->m_len < sizeof (struct udpiphdr)) &&
	    (m = m_pullup(m, sizeof (struct udpiphdr))) == 0) {
		udpstat.udps_hdrops++;
		return;
	}
	ui = mtod(m, struct udpiphdr *);
	if (((struct ip *)ui)->ip_hl > (sizeof (struct ip) >> 2))
		ip_stripoptions((struct ip *)ui, (struct mbuf *)0);

	/*
	 * Make mbuf data length reflect UDP length.
	 * If not enough data to reflect UDP length, drop.
	 */
	len = ntohs((u_short)ui->ui_ulen);
	if (((struct ip *)ui)->ip_len != len) {
		if (len > ((struct ip *)ui)->ip_len) {
			udpstat.udps_badlen++;
			goto bad;
		}
		m_adj(m, len - ((struct ip *)ui)->ip_len);
		/* ((struct ip *)ui)->ip_len = len; */
	}
	/*
	 * Save a copy of the IP header in case we want restore it for ICMP.
	 */
	ip = *(struct ip*)ui;

	/*
	 * Checksum extended UDP header and data.
	 */
	if (udpcksum && ui->ui_sum) {
		ui->ui_next = ui->ui_prev = 0;
		ui->ui_x1 = 0;
		ui->ui_len = ui->ui_ulen;
		if (ui->ui_sum = in_cksum(m, len + sizeof (struct ip))) {
			udpstat.udps_badsum++;
			m_freem(m);
			return;
		}
	}

	/*
	 * Locate pcb for datagram.
	 */
#ifdef	MULTICAST
	/* plan 169 (authored; original 0x12b3bc-0x12b4fe, MULTICAST 1.0 form):
	 * deliver a multicast or broadcast datagram to every matching socket */
	if (IN_MULTICAST(ntohl(ui->ui_dst.s_addr)) ||
	    in_broadcast(ui->ui_dst)) {
		struct socket *last;
		struct mbuf *n;

		udp_in.sin_port = ui->ui_sport;
		udp_in.sin_addr = ui->ui_src;
		m->m_len -= sizeof (struct udpiphdr);
		m->m_off += sizeof (struct udpiphdr);
		last = NULL;
		for (inp = udb.inp_next; inp != &udb; inp = inp->inp_next) {
			if (inp->inp_lport != ui->ui_dport)
				continue;
			if (inp->inp_laddr.s_addr != INADDR_ANY) {
				if (inp->inp_laddr.s_addr != ui->ui_dst.s_addr)
					continue;
			}
			if (inp->inp_faddr.s_addr != INADDR_ANY) {
				if (inp->inp_faddr.s_addr != ui->ui_src.s_addr ||
				    inp->inp_fport != ui->ui_sport)
					continue;
			}
			if (last != NULL) {
				if ((n = m_copy(m, 0, M_COPYALL)) != NULL) {
					if (sbappendaddr(&last->so_rcv,
					    (struct sockaddr *)&udp_in, n,
					    (struct mbuf *)0) == 0)
						m_freem(n);
					else
						sorwakeup(last);
				}
			}
			last = inp->inp_socket;
			if ((last->so_options & SO_REUSEADDR) == 0)
				break;
		}
		if (last == NULL)
			goto bad;
		if (sbappendaddr(&last->so_rcv, (struct sockaddr *)&udp_in,
		    m, (struct mbuf *)0) == 0)
			goto bad;
		sorwakeup(last);
		return;
	}
#endif	MULTICAST

	inp = in_pcblookup(&udb,
	    ui->ui_src, ui->ui_sport, ui->ui_dst, ui->ui_dport,
		INPLOOKUP_WILDCARD);
	if (inp == 0) {
		register struct in_ifaddr *ia;
	        u_long dst = ntohl(ui->ui_dst.s_addr);

		/*
		 *  Temporary check for many different flavors of broadcast addresses
		 *  (the drivers should really pass a broadcast indication up to the
		 *  IP level rather than having to go through these contortions).
		 */
		for (ia = in_ifaddr; ia; ia = ia->ia_next)
		{
			if ((ia->ia_ifp->if_flags & IFF_BROADCAST))
			{
				u_long match;

				/*
				 *  Look for a match on our network number with
				 *  a host of-all 0's or all-1's.
				 */
				match = (ia->ia_net^dst);
				if (match == ~ia->ia_netmask || match == 0)
				    goto bad;
				/*
				 *  Look for a match on our sub-network number with
				 *  a sub-host of-all 0's or all-1's.
				 */
				match = (ia->ia_subnet^dst);
				if (match == ~ia->ia_subnetmask || match == 0)
				    goto bad;
			}
		}
		if (ui->ui_dst.s_addr == (u_long)INADDR_BROADCAST)
			goto bad;
		if (ui->ui_dst.s_addr == INADDR_ANY)
			goto bad;
		/* don't send ICMP response for broadcast packet */
		if (in_broadcast(ui->ui_dst))
			goto bad;
		*(struct ip *)ui = ip;
		icmp_error((struct ip *)ui, ICMP_UNREACH, ICMP_UNREACH_PORT,
		    ifp, (struct in_addr *)0);	/* plan 169 (authored): 5th argument */
		return;
	}

	/*
	 * Construct sockaddr format source address.
	 * Stuff source address and datagram in user buffer.
	 */
	udp_in.sin_port = ui->ui_sport;
	udp_in.sin_addr = ui->ui_src;
	m->m_len -= sizeof (struct udpiphdr);
	m->m_off += sizeof (struct udpiphdr);
	if (sbappendaddr(&inp->inp_socket->so_rcv, (struct sockaddr *)&udp_in,
	    m, (struct mbuf *)0) == 0)
		goto bad;
	sorwakeup(inp->inp_socket);
	return;
bad:
	m_freem(m);
}

/*
 * Notify a udp user of an asynchronous error;
 * just wake up so that he can collect error status.
 */
udp_notify(inp)
	register struct inpcb *inp;
{

	sorwakeup(inp->inp_socket);
	sowwakeup(inp->inp_socket);
}

udp_ctlinput(cmd, sa, ip)	/* plan 169 (authored, 4.3-Reno form; original 0x12b664) */
	int cmd;
	struct sockaddr *sa;
	register struct ip *ip;
{
	register struct udphdr *uh;
	extern struct in_addr zeroin_addr;
	extern u_char inetctlerrmap[];

	if (cmd != PRC_ROUTEDEAD &&
	    ((unsigned)cmd > PRC_NCMDS || inetctlerrmap[cmd] == 0))
		return;
	if (ip) {
		uh = (struct udphdr *)((caddr_t)ip + (ip->ip_hl << 2));
		in_pcbnotify(&udb, sa, uh->uh_dport, ip->ip_src, uh->uh_sport,
			cmd, udp_notify);
	} else
		in_pcbnotify(&udb, sa, 0, zeroin_addr, 0, cmd, udp_notify);
}

udp_output(inp, m0)
	register struct inpcb *inp;
	struct mbuf *m0;
{
	register struct mbuf *m;
	register struct udpiphdr *ui;
	register int len = 0;

	/*
	 * Calculate data length and get a mbuf
	 * for UDP and IP headers.
	 */
	for (m = m0; m; m = m->m_next)
		len += m->m_len;
	MGET(m, M_DONTWAIT, MT_HEADER);
	if (m == 0) {
		m_freem(m0);
		return (ENOBUFS);
	}

	/*
	 * Fill in mbuf with extended UDP header
	 * and addresses and length put into network format.
	 */
	m->m_off = MMAXOFF - sizeof (struct udpiphdr);
	m->m_len = sizeof (struct udpiphdr);
	m->m_next = m0;
	ui = mtod(m, struct udpiphdr *);
	ui->ui_next = ui->ui_prev = 0;
	ui->ui_x1 = 0;
	ui->ui_pr = IPPROTO_UDP;
	ui->ui_len = htons((u_short)len + sizeof (struct udphdr));
	ui->ui_src = inp->inp_laddr;
	ui->ui_dst = inp->inp_faddr;
	ui->ui_sport = inp->inp_lport;
	ui->ui_dport = inp->inp_fport;
	ui->ui_ulen = ui->ui_len;

	/*
	 * Stuff checksum and output datagram.
	 */
	ui->ui_sum = 0;
	if (udpcksum) {
	    if ((ui->ui_sum = in_cksum(m, sizeof (struct udpiphdr) + len)) == 0)
		ui->ui_sum = 0xffff;
	}
	((struct ip *)ui)->ip_len = sizeof (struct udpiphdr) + len;
#if	TTLCONTROL
	((struct ip *)ui)->ip_ttl = inp->inp_ttl;
#else	TTLCONTROL
	((struct ip *)ui)->ip_ttl = udp_ttl;
#endif	TTLCONTROL
#ifdef	MULTICAST
	return (ip_output(m, inp->inp_options, &inp->inp_route,	/* plan 169 (authored) */
	    (inp->inp_socket->so_options & (SO_DONTROUTE | SO_BROADCAST)) |
	    IP_MULTICASTOPTS, inp->inp_moptions));
#else	MULTICAST
	return (ip_output(m, inp->inp_options, &inp->inp_route,
	    inp->inp_socket->so_options & (SO_DONTROUTE | SO_BROADCAST)));
#endif	MULTICAST
}

#if	SUN_RPC
	/* udp delivers data + sockaddr, must make space */
int	udp_sendspace = 9000;		/* really max datagram size */
int	udp_recvspace = 2*(9000+sizeof(struct sockaddr)); /* 2 8K dgrams */
#else	SUN_RPC
int	udp_sendspace = 2048;		/* really max datagram size */
int	udp_recvspace = 4 * (1024+sizeof(struct sockaddr_in)); /* 4 1K dgrams */
#endif	SUN_RPC

/*ARGSUSED*/
udp_usrreq(so, req, m, nam, rights)
	struct socket *so;
	int req;
	struct mbuf *m, *nam, *rights;
{
	struct inpcb *inp = sotoinpcb(so);
	int error = 0;
        /*
         * XXX Protect udp_usrreq just like tcp.
         * Avoids race condition with in_pcballoc;
         * also keeps icmp error from aborting a udp
         * socket that is not connected (sendto used).
         */
        int s;

	if (req == PRU_CONTROL)
		return (in_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));

        s = splnet();	/* plan 169 (authored): before the checks that go to release */
	if (rights && rights->m_len) {
		error = EINVAL;
		goto release;
	}
	if (inp == NULL && req != PRU_ATTACH) {
		error = EINVAL;
		goto release;
	}
	switch (req) {

	case PRU_ATTACH:
		if (inp != NULL) {
			error = EINVAL;
			break;
		}
		error = in_pcballoc(so, &udb);
		if (error)
			break;
		error = soreserve(so, udp_sendspace, udp_recvspace);
		if (error)
			break;
		break;

	case PRU_DETACH:
		in_pcbdetach(inp);
		break;

	case PRU_BIND:
		error = in_pcbbind(inp, nam);
		break;

	case PRU_LISTEN:
		error = EOPNOTSUPP;
		break;

	case PRU_CONNECT:
		if (inp->inp_faddr.s_addr != INADDR_ANY) {
			error = EISCONN;
			break;
		}
		error = in_pcbconnect(inp, nam);
		if (error == 0)
			soisconnected(so);
		break;

	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

	case PRU_ACCEPT:
		error = EOPNOTSUPP;
		break;

	case PRU_DISCONNECT:
		if (inp->inp_faddr.s_addr == INADDR_ANY) {
			error = ENOTCONN;
			break;
		}
		in_pcbdisconnect(inp);
		so->so_state &= ~SS_ISCONNECTED;		/* XXX */
		break;

	case PRU_SHUTDOWN:
		socantsendmore(so);
		break;

	case PRU_SEND: {
		struct in_addr laddr;

		if (nam) {
			laddr = inp->inp_laddr;
			if (inp->inp_faddr.s_addr != INADDR_ANY) {
				error = EISCONN;
				break;
			}
			error = in_pcbconnect(inp, nam);
			if (error)
				break;
		} else {
			if (inp->inp_faddr.s_addr == INADDR_ANY) {
				error = ENOTCONN;
				break;
			}
		}
		error = udp_output(inp, m);
		m = NULL;
		if (nam) {
			in_pcbdisconnect(inp);
			inp->inp_laddr = laddr;
		}
		}
		break;

	case PRU_ABORT:
		soisdisconnected(so);
		in_pcbdetach(inp);
		break;

	case PRU_SOCKADDR:
		in_setsockaddr(inp, nam);
		break;

	case PRU_PEERADDR:
		in_setpeeraddr(inp, nam);
		break;

	case PRU_SENSE:
		/*
		 * stat: don't bother with a blocksize.
		 */
		(void) splx(s);
		return (0);

	case PRU_SENDOOB:
	case PRU_FASTTIMO:
	case PRU_SLOWTIMO:
	case PRU_PROTORCV:
	case PRU_PROTOSEND:
		error =  EOPNOTSUPP;
		break;

	case PRU_RCVD:
	case PRU_RCVOOB:
		(void)splx(s);
		return (EOPNOTSUPP);	/* do not free mbuf's */

	default:
		panic("udp_usrreq");
	}
release:
	splx(s);
	if (m != NULL)
		m_freem(m);
	return (error);
}

