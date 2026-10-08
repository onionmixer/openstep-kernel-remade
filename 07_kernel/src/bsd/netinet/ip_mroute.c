/*
 * IP multicast routing entry points for a kernel built without
 * multicast routing (plan 250).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024);
 * no reference text has these routines.
 */

#import <sys/param.h>
#import <sys/errno.h>
#import <sys/mbuf.h>
#import <sys/socket.h>

#import <net/if.h>

#import <netinet/in.h>
#import <netinet/in_systm.h>
#import <netinet/ip.h>

struct socket	*ip_mrouter = 0;	/* multicast routing daemon socket */
int		ip_mrtproto = 0;	/* routing protocol, for netstat */

int
ip_mrouter_cmd(cmd, so, m)
	int cmd;
	struct socket *so;
	struct mbuf *m;
{
	return (EOPNOTSUPP);
}

int
ip_mrouter_done()
{
	return (0);
}

int
ip_mforward(ip, ifp)
	struct ip *ip;
	struct ifnet *ifp;
{
	return (0);
}
