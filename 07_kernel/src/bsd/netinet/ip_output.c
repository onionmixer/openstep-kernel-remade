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
 *	@(#)ip_output.c	7.10 (Berkeley) 4/7/88
 */

#import <sys/param.h>
#import <sys/mbuf.h>
#import <sys/errno.h>
#import <sys/protosw.h>
#import <sys/socket.h>
#import <sys/socketvar.h>

#import <machine/spl.h>

#import <net/if.h>
#import <net/route.h>
#if	NeXT
#import <net/netbuf.h>
#endif	NeXT

#import <netinet/in.h>
#import <netinet/in_pcb.h>
#import <netinet/in_systm.h>
#import <netinet/in_var.h>
#import <netinet/ip.h>
#import <netinet/ip_var.h>

#ifdef vax
#import <vax/mtpr.h>
#endif

struct mbuf *ip_insertoptions();

/*
 * IP output.  The packet in mbuf chain m contains a skeletal IP
 * header (with len, off, ttl, proto, tos, src, dst).
 * The mbuf chain containing the packet will be freed.
 * The mbuf opt, if present, will not be freed.
 */
/*
 * plan 175 (authored, D024; original _ip_output 0x127280-0x1278b4): fifth
 * argument mopts (multicast options in an mbuf), the MULTICAST 1.x block,
 * and fragment headers built in a local struct ip and copied into the
 * netbuf.
 */
ip_output(m0, opt, ro, flags, mopts)
	struct mbuf *m0;
	struct mbuf *opt;
	struct route *ro;
	int flags;
	struct mbuf *mopts;
{
	register int hlen = sizeof (struct ip);	/* plan 175.1: declaration order from the original stack slots */
	register struct ip *ip, *mhip;
	register struct ifnet *ifp;
	register struct in_ifaddr *ia = 0;
	register struct mbuf *m = m0;
	int len, off, error = 0;
	struct route iproute;
	struct ip iph;
	struct sockaddr_in *dst;
#ifdef	MULTICAST
	struct ip_moptions *imo;
#endif	MULTICAST
#if	NeXT
	netbuf_t nb;
	char *map;
	int mhlen;
#endif	NeXT

	if (opt) {
		m = ip_insertoptions(m, opt, &len);
		hlen = len;
	}
	ip = mtod(m, struct ip *);
	/*
	 * Fill in IP header.
	 */
	if ((flags & IP_FORWARDING) == 0) {
		ip->ip_v = IPVERSION;
		ip->ip_off &= IP_DF;
		ip->ip_id = htons(ip_id++);
		ip->ip_hl = hlen >> 2;
	} else
		hlen = ip->ip_hl << 2;

	/*
	 * Route packet.
	 */
	if (ro == 0) {
		ro = &iproute;
		bzero((caddr_t)ro, sizeof (*ro));
	}
	dst = (struct sockaddr_in *)&ro->ro_dst;
	/*
	 * If there is a cached route,
	 * check that it is to the same destination
	 * and is still up.  If not, free it and try again.
	 */
	if (ro->ro_rt && ((ro->ro_rt->rt_flags & RTF_UP) == 0 ||
	   dst->sin_addr.s_addr != ip->ip_dst.s_addr)) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
	}
	if (ro->ro_rt == 0) {
		dst->sin_family = AF_INET;
		dst->sin_addr = ip->ip_dst;
	}
	/*
	 * If routing to interface only,
	 * short circuit routing lookup.
	 */
	if (flags & IP_ROUTETOIF) {
		/* plan 175: ia is the function-scope variable (original esi) */
		ia = (struct in_ifaddr *)ifa_ifwithdstaddr(dst);
		if (ia == 0)
			ia = in_iaonnetof(in_netof(ip->ip_dst));
		if (ia == 0) {
			error = ENETUNREACH;
			goto bad;
		}
		ifp = ia->ia_ifp;
	} else {
		if (ro->ro_rt == 0)
			rtalloc(ro);
		if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0) {
			if (in_localaddr(ip->ip_dst))
				error = EHOSTUNREACH;
			else
				error = ENETUNREACH;
			goto bad;
		}
		ro->ro_rt->rt_use++;
		if (ro->ro_rt->rt_flags & RTF_GATEWAY)
			dst = (struct sockaddr_in *)&ro->ro_rt->rt_gateway;
	}
#ifdef	MULTICAST
	/* plan 175 (authored, D024; original 0x12742c-0x127534): MULTICAST 1.x */
	if (IN_MULTICAST(ntohl(ip->ip_dst.s_addr))) {
		struct in_multi *inm;
		extern struct ifnet *loifp;
		extern struct socket *ip_mrouter;

		dst = (struct sockaddr_in *)&ro->ro_dst;
		/*
		 * See if the caller provided any multicast options
		 */
		if ((flags & IP_MULTICASTOPTS) && mopts != NULL) {
			imo = mtod(mopts, struct ip_moptions *);
			ip->ip_ttl = imo->imo_multicast_ttl;
			if (imo->imo_multicast_ifp != NULL)
				ifp = imo->imo_multicast_ifp;
		} else {
			imo = NULL;
			ip->ip_ttl = IP_DEFAULT_MULTICAST_TTL;
		}
		/*
		 * If source address not specified yet, use address
		 * of outgoing interface.
		 */
		if (ip->ip_src.s_addr == INADDR_ANY) {
			for (ia = in_ifaddr; ia; ia = ia->ia_next)
				if (ia->ia_ifp == ifp) {
					ip->ip_src = IA_SIN(ia)->sin_addr;
					break;
				}
		}
		/*
		 * Is this host a member of the group on the outgoing
		 * interface?  (The address found above is used; no new
		 * interface lookup, as in the original.)
		 */
		if (ia == NULL)
			inm = NULL;
		else
			for (inm = ia->ia_multiaddrs;
			     inm != NULL &&
			     inm->inm_addr.s_addr != ip->ip_dst.s_addr;
			     inm = inm->inm_next)
				;
		if (inm != NULL &&
		   (imo == NULL || imo->imo_multicast_loop)) {
			/*
			 * We are a member; loop back a copy of the datagram.
			 */
			ip_mloopback(ifp, m, dst);
		}
		else if (ip_mrouter && (flags & IP_FORWARDING) == 0) {
			/*
			 * We are a multicast router; let it forward the
			 * datagram on the other interfaces.
			 */
			if (ip_mforward(ip, ifp) != 0) {
				m_freem(m);
				goto done;
			}
		}
		/*
		 * Multicasts with a time-to-live of zero, or sent on
		 * the loopback interface, are not sent further.
		 */
		if (ip->ip_ttl == 0 || ifp == loifp) {
			m_freem(m);
			goto done;
		}
		goto sendit;
	}
#endif	MULTICAST
#ifndef notdef
	/*
	 * If source address not specified yet, use address
	 * of outgoing interface.
	 */
	if (ip->ip_src.s_addr == INADDR_ANY) {
		/* plan 175: ia is the function-scope variable (original esi) */
		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if (ia->ia_ifp == ifp) {
				ip->ip_src = IA_SIN(ia)->sin_addr;
				break;
			}
	}
#endif
	/*
	 * Look for broadcast address and
	 * and verify user is allowed to send
	 * such a packet.
	 */
	if (in_broadcast(dst->sin_addr)) {
		if ((ifp->if_flags & IFF_BROADCAST) == 0) {
			error = EADDRNOTAVAIL;
			goto bad;
		}
		if ((flags & IP_ALLOWBROADCAST) == 0) {
			error = EACCES;
			goto bad;
		}
		/* don't allow broadcast messages to be fragmented */
		if (ip->ip_len > ifp->if_mtu) {
			error = EMSGSIZE;
			goto bad;
		}
	}
#ifdef	MULTICAST
sendit:				/* plan 175 */
#endif	MULTICAST

	/*
	 * If small enough for interface, can just send directly.
	 */
	if (ip->ip_len <= ifp->if_mtu) {
		ip->ip_len = htons((u_short)ip->ip_len);
		ip->ip_off = htons((u_short)ip->ip_off);
		ip->ip_sum = 0;
		ip->ip_sum = in_cksum(m, hlen);
#if	NeXT
		error = if_output_mbuf(ifp, m, (struct sockaddr *)dst);
#else	NeXT
		error = (*ifp->if_output)(ifp, m, (struct sockaddr *)dst);
#endif	NeXT
		goto done;
	}

	/*
	 * Too large for interface; fragment if possible.
	 * Must be able to put at least 8 bytes per fragment.
	 */
	if (ip->ip_off & IP_DF) {
		error = EMSGSIZE;
		goto bad;
	}
	len = (ifp->if_mtu - hlen) &~ 7;
	if (len < 8) {
		error = EMSGSIZE;
		goto bad;
	}

#if	NeXT	
	/*
	 * plan 175 (authored, D024): headers are built in iph and copied
	 * into the netbuf, whose data need not be aligned (original
	 * 0x127665-0x1276c8).
	 */
	nb = ifp->if_getbuf(ifp);
	if (nb == 0) {
		error = ENOBUFS;
		goto bad;
	}
	map = nb_map(nb);
	mbuf_read(m, map, 0, hlen + len);
	iph = *ip;			/* plan 175 */
	iph.ip_len = htons((u_short)(hlen + len));
	iph.ip_off = htons((u_short)(ip->ip_off | IP_MF));
	iph.ip_sum = 0;
	bcopy((caddr_t)&iph, map, sizeof (struct ip));
	iph.ip_sum = in_cksum(nb, hlen);
	map[10] = ((char *)&iph.ip_sum)[0];
	map[11] = ((char *)&iph.ip_sum)[1];
	error = (*ifp->if_output)(ifp, nb, (struct sockaddr *)dst);
	if (error) {
		goto bad;
	}

	/*
	 * Loop through length of segment after first fragment,
	 * make new header and copy data of each part and link onto chain.
	 */
	mhlen = sizeof (struct ip);
	for (off = hlen + len; off < ip->ip_len; off += len) {
		nb = ifp->if_getbuf(ifp);
		if (nb == 0) {
			error = ENOBUFS;
			goto bad;
		}
		map = nb_map(nb);
		mhip = (struct ip *)map;
		iph = *ip;
		if (hlen > sizeof (struct ip)) {
			mhlen = ip_optcopy(ip, (struct ip *)map) + sizeof (struct ip);
			iph.ip_hl = mhlen >> 2;
		}
		iph.ip_off = ((off - hlen) >> 3) + (ip->ip_off & ~IP_MF);
		if (ip->ip_off & IP_MF)
			iph.ip_off |= IP_MF;
		if (off + len >= ip->ip_len) {
			nb_shrink_bot(nb, off + len - ip->ip_len);
			len = ip->ip_len - off;
		} else {
			iph.ip_off |= IP_MF;
		}
		iph.ip_len = htons((u_short)(len + mhlen));
		mbuf_read(m, map + mhlen, off, len);
		iph.ip_off = htons((u_short)iph.ip_off);
		iph.ip_sum = 0;
		bcopy((caddr_t)&iph, (caddr_t)mhip, sizeof (struct ip));
		iph.ip_sum = in_cksum(nb, mhlen);
		{
			/*
			 * plan 383 (authored, D024; original [0x12781a, 0x12782b)):
			 * the checksum bytes are stored through cp and map is
			 * reused as the source pointer, so that cse does not fold
			 * the address back to map + 10 (original "mov eax, map;
			 * add eax, 0xa").  The original source form is not known;
			 * this form gives the original bytes.
			 */
			char *cp;

			cp = map + 10;
			map = (char *)&iph.ip_sum;
			cp[0] = map[0];
			cp[1] = map[1];
		}
		error = (*ifp->if_output)(ifp, nb, (struct sockaddr *)dst);
		if (error) {
			goto bad;
		}
	}
	m_freem(m0);
#else	NeXT
    {
	int mhlen, firstlen = len;
	struct mbuf **mnext = &m->m_act;

	/*
	 * Loop through length of segment after first fragment,
	 * make new header and copy data of each part and link onto chain.
	 */
	m0 = m;
	mhlen = sizeof (struct ip);
	for (off = hlen + len; off < ip->ip_len; off += len) {
		MGET(m, M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_off = MMAXOFF - hlen;
		mhip = mtod(m, struct ip *);
		*mhip = *ip;
		if (hlen > sizeof (struct ip)) {
			mhlen = ip_optcopy(ip, mhip) + sizeof (struct ip);
			mhip->ip_hl = mhlen >> 2;
		}
		m->m_len = mhlen;
		mhip->ip_off = ((off - hlen) >> 3) + (ip->ip_off & ~IP_MF);
		if (ip->ip_off & IP_MF)
			mhip->ip_off |= IP_MF;
		if (off + len >= ip->ip_len)
			len = ip->ip_len - off;
		else
			mhip->ip_off |= IP_MF;
		mhip->ip_len = htons((u_short)(len + mhlen));
		m->m_next = m_copy(m0, off, len);
		if (m->m_next == 0) {
			error = ENOBUFS;	/* ??? */
			goto sendorfree;
		}
		mhip->ip_off = htons((u_short)mhip->ip_off);
		mhip->ip_sum = 0;
		mhip->ip_sum = in_cksum(m, mhlen);
		*mnext = m;
		mnext = &m->m_act;
	}
	/*
	 * Update first fragment by trimming what's been copied out
	 * and updating header, then send each fragment (in order).
	 */
	m_adj(m0, hlen + firstlen - ip->ip_len);
	ip->ip_len = htons((u_short)(hlen + firstlen));
	ip->ip_off = htons((u_short)(ip->ip_off | IP_MF));
	ip->ip_sum = 0;
	ip->ip_sum = in_cksum(m0, hlen);
sendorfree:
	for (m = m0; m; m = m0) {
		m0 = m->m_act;
		m->m_act = 0;
		if (error == 0)
			error = (*ifp->if_output)(ifp, m,
			    (struct sockaddr *)dst);
		else
			m_freem(m);
	}
    }
#endif	NeXT
done:
	if (ro == &iproute && (flags & IP_ROUTETOIF) == 0 && ro->ro_rt)
		RTFREE(ro->ro_rt);
	return (error);
bad:
	m_freem(m0);
	goto done;
}

/*
 * Insert IP options into preformed packet.
 * Adjust IP destination as required for IP source routing,
 * as indicated by a non-zero in_addr at the start of the options.
 */
struct mbuf *
ip_insertoptions(m, opt, phlen)
	register struct mbuf *m;
	struct mbuf *opt;
	int *phlen;
{
	register struct ipoption *p = mtod(opt, struct ipoption *);
	struct mbuf *n;
	register struct ip *ip = mtod(m, struct ip *);
	unsigned optlen;

	optlen = opt->m_len - sizeof(p->ipopt_dst);
	if (p->ipopt_dst.s_addr)
		ip->ip_dst = p->ipopt_dst;
	if (m->m_off >= MMAXOFF || MMINOFF + optlen > m->m_off) {
		MGET(n, M_DONTWAIT, MT_HEADER);
		if (n == 0)
			return (m);
		m->m_len -= sizeof(struct ip);
		m->m_off += sizeof(struct ip);
		n->m_next = m;
		m = n;
		m->m_off = MMAXOFF - sizeof(struct ip) - optlen;
		m->m_len = optlen + sizeof(struct ip);
		bcopy((caddr_t)ip, mtod(m, caddr_t), sizeof(struct ip));
	} else {
		m->m_off -= optlen;
		m->m_len += optlen;
		ovbcopy((caddr_t)ip, mtod(m, caddr_t), sizeof(struct ip));
	}
	ip = mtod(m, struct ip *);
	bcopy((caddr_t)p->ipopt_list, (caddr_t)(ip + 1), (unsigned)optlen);
	*phlen = sizeof(struct ip) + optlen;
	ip->ip_len += optlen;
	return (m);
}

/*
 * Copy options from ip to jp,
 * omitting those not copied during fragmentation.
 */
ip_optcopy(ip, jp)
	struct ip *ip, *jp;
{
	register u_char *cp, *dp;
	int opt, optlen, cnt;

	cp = (u_char *)(ip + 1);
	dp = (u_char *)(jp + 1);
	cnt = (ip->ip_hl << 2) - sizeof (struct ip);
	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[0];
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
		else
			optlen = cp[IPOPT_OLEN];
		/* bogus lengths should have been caught by ip_dooptions */
		if (optlen > cnt)
			optlen = cnt;
		if (IPOPT_COPIED(opt)) {
			bcopy((caddr_t)cp, (caddr_t)dp, (unsigned)optlen);
			dp += optlen;
		}
	}
	for (optlen = dp - (u_char *)(jp+1); optlen & 0x3; optlen++)
		*dp++ = IPOPT_EOL;
	return (optlen);
}

/*
 * IP socket option processing.
 */
ip_ctloutput(op, so, level, optname, m)
	int op;
	struct socket *so;
	int level, optname;
	struct mbuf **m;
{
	int error = 0;
	struct inpcb *inp = sotoinpcb(so);

	if (level != IPPROTO_IP)
		error = EINVAL;
	else switch (op) {

	case PRCO_SETOPT:
		switch (optname) {
		case IP_OPTIONS:
			return (ip_pcbopts(&inp->inp_options, *m));

#ifdef	MULTICAST
		/* plan 175 (authored; original 0x127acc-0x127af4) */
		case IP_MULTICAST_IF:
		case IP_MULTICAST_TTL:
		case IP_MULTICAST_LOOP:
		case IP_ADD_MEMBERSHIP:
		case IP_DROP_MEMBERSHIP:
			error = ip_setmoptions(optname, &inp->inp_moptions, *m);
			break;
#endif	MULTICAST

		default:
			error = EINVAL;
			break;
		}
		break;

	case PRCO_GETOPT:
		switch (optname) {
		case IP_OPTIONS:
			*m = m_get(M_WAIT, MT_SOOPTS);
			if (inp->inp_options) {
				(*m)->m_off = inp->inp_options->m_off;
				(*m)->m_len = inp->inp_options->m_len;
				bcopy(mtod(inp->inp_options, caddr_t),
				    mtod(*m, caddr_t), (unsigned)(*m)->m_len);
			} else
				(*m)->m_len = 0;
			break;
#ifdef	MULTICAST
		/* plan 175 (authored; original 0x127b58-0x127b63) */
		case IP_MULTICAST_IF:
		case IP_MULTICAST_TTL:
		case IP_MULTICAST_LOOP:
		case IP_ADD_MEMBERSHIP:
		case IP_DROP_MEMBERSHIP:
			error = ip_getmoptions(optname, inp->inp_moptions, m);
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

/*
 * Set up IP options in pcb for insertion in output packets.
 * Store in mbuf with pointer in pcbopt, adding pseudo-option
 * with destination address if source routed.
 */
ip_pcbopts(pcbopt, m)
	struct mbuf **pcbopt;
	register struct mbuf *m;
{
	register cnt, optlen;
	register u_char *cp;
	u_char opt;

	/* turn off any old options */
	if (*pcbopt)
		(void)m_free(*pcbopt);
	*pcbopt = 0;
	if (m == (struct mbuf *)0 || m->m_len == 0) {
		/*
		 * Only turning off any previous options.
		 */
		if (m)
			(void)m_free(m);
		return (0);
	}

#ifndef	vax
	if (m->m_len % sizeof(long))
		goto bad;
#endif
	/*
	 * IP first-hop destination address will be stored before
	 * actual options; move other options back
	 * and clear it when none present.
	 */
#if	MAX_IPOPTLEN >= MMAXOFF - MMINOFF
	if (m->m_off + m->m_len + sizeof(struct in_addr) > MAX_IPOPTLEN)
		goto bad;
#else
	if (m->m_off + m->m_len + sizeof(struct in_addr) > MMAXOFF)
		goto bad;
#endif
	cnt = m->m_len;
	m->m_len += sizeof(struct in_addr);
	cp = mtod(m, u_char *) + sizeof(struct in_addr);
	ovbcopy(mtod(m, caddr_t), (caddr_t)cp, (unsigned)cnt);
	bzero(mtod(m, caddr_t), sizeof(struct in_addr));

	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[IPOPT_OPTVAL];
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
		else {
			optlen = cp[IPOPT_OLEN];
			if (optlen <= IPOPT_OLEN || optlen > cnt)
				goto bad;
		}
		switch (opt) {

		default:
			break;

		case IPOPT_LSRR:
		case IPOPT_SSRR:
			/*
			 * user process specifies route as:
			 *	->A->B->C->D
			 * D must be our final destination (but we can't
			 * check that since we may not have connected yet).
			 * A is first hop destination, which doesn't appear in
			 * actual IP option, but is stored before the options.
			 */
			if (optlen < IPOPT_MINOFF - 1 + sizeof(struct in_addr))
				goto bad;
			m->m_len -= sizeof(struct in_addr);
			cnt -= sizeof(struct in_addr);
			optlen -= sizeof(struct in_addr);
			cp[IPOPT_OLEN] = optlen;
			/*
			 * Move first hop before start of options.
			 */
			bcopy((caddr_t)&cp[IPOPT_OFFSET+1], mtod(m, caddr_t),
			    sizeof(struct in_addr));
			/*
			 * Then copy rest of options back
			 * to close up the deleted entry.
			 */
			ovbcopy((caddr_t)(&cp[IPOPT_OFFSET+1] +
			    sizeof(struct in_addr)),
			    (caddr_t)&cp[IPOPT_OFFSET+1],
			    (unsigned)cnt + sizeof(struct in_addr));
			break;
		}
	}
	*pcbopt = m;
	return (0);

bad:
	(void)m_free(m);
	return (EINVAL);
}

#ifdef	MULTICAST
/*
 * plan 175 (authored, D024; original _ip_setmoptions 0x127cc8,
 * _ip_getmoptions 0x1280c4, _ip_freemoptions 0x128190, _ip_mloopback
 * 0x1281d4; MULTICAST 1.x form, options kept in an mbuf).
 *
 * Set the IP multicast options in response to user setsockopt().
 */
int
ip_setmoptions(optname, imop, m)
	int optname;
	struct mbuf **imop;
	struct mbuf *m;
{
	register int error = 0;
	u_char loop;
	register int i;
	struct in_addr addr;
	register struct ip_mreq *mreq;
	register struct ifnet *ifp;
	register struct ip_moptions *imo;
	struct route ro;
	register struct sockaddr_in *dst;

	if (*imop == NULL) {
		/*
		 * No multicast option buffer attached to the pcb;
		 * allocate one and initialize to default values.
		 */
		MGET(*imop, M_WAIT, MT_IPMOPTS);
		if (*imop == NULL)
			return (ENOBUFS);
		imo = mtod(*imop, struct ip_moptions *);
		imo->imo_multicast_ifp = NULL;
		imo->imo_multicast_ttl = IP_DEFAULT_MULTICAST_TTL;
		imo->imo_multicast_loop = IP_DEFAULT_MULTICAST_LOOP;
		imo->imo_num_memberships = 0;
	}
	imo = mtod(*imop, struct ip_moptions *);

	switch (optname) {

	case IP_MULTICAST_IF:
		/*
		 * Select the interface for outgoing multicast packets.
		 */
		if (m == NULL || m->m_len != sizeof(struct in_addr)) {
			error = EINVAL;
			break;
		}
		addr = *(mtod(m, struct in_addr *));
		/*
		 * INADDR_ANY is used to remove a previous selection.
		 * When no interface is selected, a default one is
		 * chosen every time a multicast packet is sent.
		 */
		if (addr.s_addr == INADDR_ANY) {
			imo->imo_multicast_ifp = NULL;
			break;
		}
		/*
		 * The selected interface is identified by its local
		 * IP address.  Find the interface.
		 */
		INADDR_TO_IFP(addr, ifp);
		if (ifp == NULL) {
			error = EADDRNOTAVAIL;
			break;
		}
		imo->imo_multicast_ifp = ifp;
		break;

	case IP_MULTICAST_TTL:
		/*
		 * Set the IP time-to-live for outgoing multicast packets.
		 */
		if (m == NULL || m->m_len != 1) {
			error = EINVAL;
			break;
		}
		imo->imo_multicast_ttl = *(mtod(m, u_char *));
		break;

	case IP_MULTICAST_LOOP:
		/*
		 * Set the loopback flag for outgoing multicast packets.
		 * Must be zero or one.
		 */
		if (m == NULL || m->m_len != 1 ||
		   (loop = *(mtod(m, u_char *))) > 1) {
			error = EINVAL;
			break;
		}
		imo->imo_multicast_loop = loop;
		break;

	case IP_ADD_MEMBERSHIP:
		/*
		 * Add a multicast group membership.
		 * Group must be a valid IP multicast address.
		 */
		if (m == NULL || m->m_len != sizeof(struct ip_mreq)) {
			error = EINVAL;
			break;
		}
		mreq = mtod(m, struct ip_mreq *);
		if (!IN_MULTICAST(ntohl(mreq->imr_multiaddr.s_addr))) {
			error = EINVAL;
			break;
		}
		/*
		 * If no interface address was provided, use the interface of
		 * the route to the given multicast address.
		 */
		if (mreq->imr_interface.s_addr == INADDR_ANY) {
			ro.ro_rt = NULL;
			dst = (struct sockaddr_in *)&ro.ro_dst;
			dst->sin_family = AF_INET;
			dst->sin_addr = mreq->imr_multiaddr;
			rtalloc(&ro);
			if (ro.ro_rt == NULL) {
				error = EADDRNOTAVAIL;
				break;
			}
			ifp = ro.ro_rt->rt_ifp;
			rtfree(ro.ro_rt);
		}
		else {
			INADDR_TO_IFP(mreq->imr_interface, ifp);
		}
		/*
		 * See if we found an interface.
		 */
		if (ifp == NULL) {
			error = EADDRNOTAVAIL;
			break;
		}
		/*
		 * See if the membership already exists or if all the
		 * membership slots are full.
		 */
		for (i = 0; i < imo->imo_num_memberships; ++i) {
			if (imo->imo_membership[i]->inm_ifp == ifp &&
			    imo->imo_membership[i]->inm_addr.s_addr
						== mreq->imr_multiaddr.s_addr)
				break;
		}
		if (i < imo->imo_num_memberships) {
			error = EADDRINUSE;
			break;
		}
		if (i == IP_MAX_MEMBERSHIPS) {
			error = ETOOMANYREFS;
			break;
		}
		/*
		 * Everything looks good; add a new record to the multicast
		 * address list for the given interface.
		 */
		if ((imo->imo_membership[i] =
		    in_addmulti(mreq->imr_multiaddr, ifp)) == NULL) {
			error = ENOBUFS;
			break;
		}
		++imo->imo_num_memberships;
		break;

	case IP_DROP_MEMBERSHIP:
		/*
		 * Drop a multicast group membership.
		 * Group must be a valid IP multicast address.
		 */
		if (m == NULL || m->m_len != sizeof(struct ip_mreq)) {
			error = EINVAL;
			break;
		}
		mreq = mtod(m, struct ip_mreq *);
		if (!IN_MULTICAST(ntohl(mreq->imr_multiaddr.s_addr))) {
			error = EINVAL;
			break;
		}
		/*
		 * If an interface address was specified, get a pointer
		 * to its ifnet structure.
		 */
		if (mreq->imr_interface.s_addr == INADDR_ANY)
			ifp = NULL;
		else {
			INADDR_TO_IFP(mreq->imr_interface, ifp);
			if (ifp == NULL) {
				error = EADDRNOTAVAIL;
				break;
			}
		}
		/*
		 * Find the membership in the membership array.
		 */
		for (i = 0; i < imo->imo_num_memberships; ++i) {
			if ((ifp == NULL ||
			     imo->imo_membership[i]->inm_ifp == ifp) &&
			     imo->imo_membership[i]->inm_addr.s_addr ==
			     mreq->imr_multiaddr.s_addr)
				break;
		}
		if (i == imo->imo_num_memberships) {
			error = EADDRNOTAVAIL;
			break;
		}
		/*
		 * Give up the multicast address record to which the
		 * membership points.
		 */
		in_delmulti(imo->imo_membership[i]);
		/*
		 * Remove the gap in the membership array.
		 */
		for (++i; i < imo->imo_num_memberships; ++i)
			imo->imo_membership[i-1] = imo->imo_membership[i];
		--imo->imo_num_memberships;
		break;

	default:
		error = EOPNOTSUPP;
		break;
	}

	/*
	 * If all options have default values, no need to keep the mbuf.
	 */
	if (imo->imo_multicast_ifp == NULL &&
	    imo->imo_multicast_ttl == IP_DEFAULT_MULTICAST_TTL &&
	    imo->imo_multicast_loop == IP_DEFAULT_MULTICAST_LOOP &&
	    imo->imo_num_memberships == 0) {
		m_free(*imop);
		*imop = NULL;
	}

	return (error);
}

/*
 * Return the IP multicast options in response to user getsockopt().
 */
int
ip_getmoptions(optname, mopts, mp)
	int optname;
	struct mbuf *mopts;
	register struct mbuf **mp;
{
	register struct ip_moptions *imo;
	u_char *ttl;
	u_char *loop;
	struct in_addr *addr;
	struct in_ifaddr *ia;

	*mp = m_get(M_WAIT, MT_IPMOPTS);
	imo = (mopts == NULL) ? NULL : mtod(mopts, struct ip_moptions *);

	switch (optname) {

	case IP_MULTICAST_IF:
		addr = mtod(*mp, struct in_addr *);
		(*mp)->m_len = sizeof(struct in_addr);
		if (imo == NULL || imo->imo_multicast_ifp == NULL)
			addr->s_addr = INADDR_ANY;
		else {
			IFP_TO_IA(imo->imo_multicast_ifp, ia);
			addr->s_addr = (ia == NULL) ? INADDR_ANY
					: IA_SIN(ia)->sin_addr.s_addr;
		}
		return (0);

	case IP_MULTICAST_TTL:
		ttl = mtod(*mp, u_char *);
		(*mp)->m_len = 1;
		*ttl = (imo == NULL) ? IP_DEFAULT_MULTICAST_TTL
				     : imo->imo_multicast_ttl;
		return (0);

	case IP_MULTICAST_LOOP:
		loop = mtod(*mp, u_char *);
		(*mp)->m_len = 1;
		*loop = (imo == NULL) ? IP_DEFAULT_MULTICAST_LOOP
				      : imo->imo_multicast_loop;
		return (0);

	default:
		return (EOPNOTSUPP);
	}
}

/*
 * Discard the IP multicast options.
 */
void
ip_freemoptions(mopts)
	register struct mbuf *mopts;
{
	register struct ip_moptions *imo;
	register int i;

	if (mopts != NULL) {
		imo = mtod(mopts, struct ip_moptions *);
		for (i = 0; i < imo->imo_num_memberships; ++i)
			in_delmulti(imo->imo_membership[i]);
		m_free(mopts);
	}
}

/*
 * Routine called from ip_output() to loop back a copy of an IP multicast
 * packet to the input queue of a specified interface.
 */
ip_mloopback(ifp, m, dst)
	struct ifnet *ifp;
	register struct mbuf *m;
	register struct sockaddr_in *dst;
{
	register struct ip *ip;
	struct mbuf *copym;

	copym = m_copy(m, 0, M_COPYALL);
	if (copym != NULL) {
		/*
		 * We don't bother to fragment if the IP length is greater
		 * than the interface's MTU.  Can this possibly matter?
		 */
		ip = mtod(copym, struct ip *);
		ip->ip_len = htons((u_short)ip->ip_len);
		ip->ip_off = htons((u_short)ip->ip_off);
		ip->ip_sum = 0;
		ip->ip_sum = in_cksum(copym, ip->ip_hl << 2);
		(void) looutput(ifp, copym, (struct sockaddr *)dst);
	}
}
#endif	MULTICAST
