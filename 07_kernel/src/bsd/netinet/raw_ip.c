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
 *	@(#)raw_ip.c	7.3 (Berkeley) 12/7/87
 */

#import <sys/param.h>
#import <sys/mbuf.h>
#import <sys/socket.h>
#import <sys/protosw.h>
#import <sys/socketvar.h>
#import <sys/errno.h>

#import <net/if.h>
#import <net/route.h>
#import <net/raw_cb.h>

#import <netinet/in.h>
#import <netinet/in_systm.h>
#import <netinet/ip.h>
#import <netinet/ip_var.h>
#ifdef	MULTICAST
#import <netinet/in_var.h>	/* plan 168: INADDR_TO_IFP */
#endif	MULTICAST

/*
 * Raw interface to IP protocol.
 */

struct	sockaddr_in ripdst = { AF_INET };
struct	sockaddr_in ripsrc = { AF_INET };
struct	sockproto ripproto = { PF_INET };
/*
 * Setup generic address and protocol structures
 * for raw_input routine, then pass them along with
 * mbuf chain.
 */
rip_input(m)
	struct mbuf *m;
{
	register struct ip *ip = mtod(m, struct ip *);

	ripproto.sp_protocol = ip->ip_p;
	ripdst.sin_addr = ip->ip_dst;
	ripsrc.sin_addr = ip->ip_src;
	raw_input(m, &ripproto, (struct sockaddr *)&ripsrc,
	  (struct sockaddr *)&ripdst);
}

/*
 * Generate IP header and pass packet to ip_output.
 * Tack on options user may have setup with control call.
 */
rip_output(m0, so)	/* plan 168.1 (authored): parameter m0, working m (original registers) */
	struct mbuf *m0;
	struct socket *so;
{
	register struct ip *ip;
	register struct mbuf *m;
	int error;
	int len = 0;
	struct rawcb *rp = sotorawcb(so);
	struct sockaddr_in *sin;
#ifdef	MULTICAST
	struct ifnet *ifp;	/* plan 168 */
#endif	MULTICAST
	/*
	 * if the protocol is IPPROTO_RAW, the user handed us a 
	 * complete IP packet.  Otherwise, allocate an mbuf for a
	 * header and fill it in as needed.
	 */
	if (rp->rcb_proto.sp_protocol != IPPROTO_RAW
#ifdef	MULTICAST
	    && rp->rcb_proto.sp_protocol != IPPROTO_IGMP	/* plan 168 (authored; original bytes) */
#endif	MULTICAST
	    ) {
		/*
		 * Calculate data length and get an mbuf
		 * for IP header.
		 */

		for (m = m0; m; m = m->m_next)
			len += m->m_len;

		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			m = m0;
			error = ENOBUFS;
			goto bad;
		}
		m->m_off = MMAXOFF - sizeof(struct ip);
		m->m_len = sizeof(struct ip);
		m->m_next = m0;

		ip = mtod(m, struct ip *);
		ip->ip_tos = 0;
		ip->ip_off = 0;
#ifdef	MULTICAST
		/* plan 168 (authored; original 0x1282fe-0x128339) */
		ip->ip_p = rp->rcb_proto.sp_protocol;
		ip->ip_len = sizeof(struct ip) + len;
		if (rp->rcb_flags & RAW_LADDR) {
			sin = (struct sockaddr_in *)&rp->rcb_laddr;
			if (sin->sin_family != AF_INET) {
				error = EAFNOSUPPORT;
				goto bad;
			}
			ip->ip_src.s_addr = sin->sin_addr.s_addr;
		} else
			ip->ip_src.s_addr = 0;
		ip->ip_dst = ((struct sockaddr_in *)&rp->rcb_faddr)->sin_addr;
		ip->ip_ttl = MAXTTL;
	} else {
		/* plan 168 (authored; original 0x128340-0x12837b) */
		m = m0;
		ip = mtod(m, struct ip *);
		if (ip->ip_src.s_addr) {
			INADDR_TO_IFP(ip->ip_src, ifp);
			if (ifp == 0) {
				error = EADDRNOTAVAIL;
				goto bad;
			}
		}
		ip->ip_dst = ((struct sockaddr_in *)&rp->rcb_faddr)->sin_addr;
	}

	return (ip_output(m, rp->rcb_options, &rp->rcb_route,
	   (so->so_options & SO_DONTROUTE) | IP_ALLOWBROADCAST |
	   IP_MULTICASTOPTS, rp->rcb_moptions));
#else	MULTICAST
		ip->ip_p = (rp->rcb_proto.sp_protocol ? rp->rcb_proto.sp_protocol : IPPROTO_RAW);
		ip->ip_len = sizeof(struct ip) + len;
		ip->ip_ttl = MAXTTL;
	} else {
		m = m0;
		ip = mtod(m, struct ip *);
	}

	if (rp->rcb_flags & RAW_LADDR) {
		sin = (struct sockaddr_in *)&rp->rcb_laddr;
		if (sin->sin_family != AF_INET) {
			error = EAFNOSUPPORT;
			goto bad;
		}
		ip->ip_src.s_addr = sin->sin_addr.s_addr;
	} else
		ip->ip_src.s_addr = 0;

	ip->ip_dst = ((struct sockaddr_in *)&rp->rcb_faddr)->sin_addr;

	return (ip_output(m, rp->rcb_options, &rp->rcb_route, 
	   (so->so_options & SO_DONTROUTE) | IP_ALLOWBROADCAST));
#endif	MULTICAST
bad:
	m_freem(m);
	return (error);
}
/*
 * Raw IP socket option processing.
 */
rip_ctloutput(op, so, level, optname, m)
	int op;
	struct socket *so;
	int level, optname;
	struct mbuf **m;
{
	int error = 0;
	register struct rawcb *rp = sotorawcb(so);

	if (level != IPPROTO_IP)
		error = EINVAL;
	else switch (op) {

	case PRCO_SETOPT:
		switch (optname) {
		case IP_OPTIONS:
			return (ip_pcbopts(&rp->rcb_options, *m));
#ifdef	MULTICAST
		/* plan 168 (authored; original 0x1283fc-0x128426) */
		case IP_MULTICAST_IF:
		case IP_MULTICAST_TTL:
		case IP_MULTICAST_LOOP:
		case IP_ADD_MEMBERSHIP:
		case IP_DROP_MEMBERSHIP:
			error = ip_setmoptions(optname, &rp->rcb_moptions, *m);
			break;
		default:
			error = ip_mrouter_cmd(optname, so, *m);
			break;
#else	MULTICAST
		default:
			error = EINVAL;
			break;
#endif	MULTICAST
		}
		break;

	case PRCO_GETOPT:
		switch (optname) {
		case IP_OPTIONS:
			*m = m_get(M_WAIT, MT_SOOPTS);
			if (rp->rcb_options) {
				(*m)->m_off = rp->rcb_options->m_off;
				(*m)->m_len = rp->rcb_options->m_len;
				bcopy(mtod(rp->rcb_options, caddr_t),
				    mtod(*m, caddr_t), (unsigned)(*m)->m_len);
			} else
				(*m)->m_len = 0;
			break;
#ifdef	MULTICAST
		/* plan 168 (authored; original 0x128488-0x128493) */
		case IP_MULTICAST_IF:
		case IP_MULTICAST_TTL:
		case IP_MULTICAST_LOOP:
		case IP_ADD_MEMBERSHIP:
		case IP_DROP_MEMBERSHIP:
			error = ip_getmoptions(optname, rp->rcb_moptions, m);
			break;
#endif	MULTICAST
		default:
			error = EINVAL;
			break;
		}
		break;
	}
	if (op == PRCO_SETOPT && *m)
		(void)m_free(*m);
	return (error);
}

