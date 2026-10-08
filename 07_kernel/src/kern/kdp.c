/*
 * kern/kdp.c -- kernel debugging protocol requests (plan 257).
 *
 * Written for this project from the OPENSTEP 4.2 x86 kernel object
 * [0x161f4c, 0x1624a8) (D024).  Darwin 0.1 kern/kdp.c, a later form of
 * this file, was consulted for structure only.  The request handling
 * is fixed by the bytes and may resemble Darwin's (D027).  Differences
 * from Darwin 0.1: the packet copy buffer is on the stack, and the
 * diagnostics are printed with safe_prf.
 */

#import <mach/mach_types.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/socket.h>
#import <net/if.h>
#import <netinet/in.h>

#import <kern/kdp_internal.h>
#import <kern/miniMon.h>

static boolean_t
	kdp_unknown(kdp_pkt_t *, int *, unsigned short *),
	kdp_connect(kdp_pkt_t *, int *, unsigned short *),
	kdp_disconnect(kdp_pkt_t *, int *, unsigned short *),
	kdp_hostinfo(kdp_pkt_t *, int *, unsigned short *),
	kdp_suspend(kdp_pkt_t *, int *, unsigned short *),
	kdp_resumecpus(kdp_pkt_t *, int *, unsigned short *),
	kdp_writemem(kdp_pkt_t *, int *, unsigned short *),
	kdp_readmem(kdp_pkt_t *, int *, unsigned short *),
	kdp_maxbytes(kdp_pkt_t *, int *, unsigned short *),
	kdp_regions(kdp_pkt_t *, int *, unsigned short *),
	kdp_writeregs(kdp_pkt_t *, int *, unsigned short *),
	kdp_readregs(kdp_pkt_t *, int *, unsigned short *);

/* handlers indexed by request number */
static kdp_dispatch_t
    dispatch_table[KDP_TERMINATION - KDP_CONNECT + 1] =
    {
	kdp_connect,		/* KDP_CONNECT */
	kdp_disconnect,		/* KDP_DISCONNECT */
	kdp_hostinfo,		/* KDP_HOSTINFO */
	kdp_regions,		/* KDP_REGIONS */
	kdp_maxbytes,		/* KDP_MAXBYTES */
	kdp_readmem,		/* KDP_READMEM */
	kdp_writemem,		/* KDP_WRITEMEM */
	kdp_readregs,		/* KDP_READREGS */
	kdp_writeregs,		/* KDP_WRITEREGS */
	kdp_unknown,		/* KDP_LOAD */
	kdp_unknown,		/* KDP_IMAGEPATH */
	kdp_suspend,		/* KDP_SUSPEND */
	kdp_resumecpus,		/* KDP_RESUMECPUS */
	kdp_unknown,		/* KDP_EXCEPTION */
	kdp_unknown		/* KDP_TERMINATION */
    };

kdp_glob_t	kdp;

/*
 * Handle one request in pkt (copied to an aligned buffer first);
 * TRUE when a reply was built in its place.
 */
boolean_t
kdp_packet(
    unsigned char	*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    unsigned		aligned_pkt[1538/sizeof(unsigned)+1];
    kdp_pkt_t		*rd = (kdp_pkt_t *)aligned_pkt;
    int			plen = *len;
    unsigned int	req;
    boolean_t		ret;

    bcopy(pkt, rd, sizeof(aligned_pkt));

    if (plen < sizeof (rd->hdr) || rd->hdr.len != plen) {
	safe_prf("kdp_packet bad len pkt %d hdr %d\n", plen, rd->hdr.len);
	return (FALSE);
    }

    if (rd->hdr.is_reply) {
	safe_prf("kdp_packet reply recvd req %x seq %x\n",
	    rd->hdr.request, rd->hdr.seq);
	return (FALSE);
    }

    req = rd->hdr.request;
    if (req < KDP_CONNECT || req > KDP_TERMINATION) {
	safe_prf("kdp_packet bad request %x len %d seq %x key %x\n",
	    rd->hdr.request, rd->hdr.len, rd->hdr.seq, rd->hdr.key);
	return (FALSE);
    }

    ret = ((*dispatch_table[req - KDP_CONNECT])(rd, len, reply_port));

    bcopy(rd, pkt, *len);

    return (ret);
}

static boolean_t
kdp_unknown(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_pkt_t		*rd = (kdp_pkt_t *)pkt;

    safe_prf("kdp_unknown request %x len %d seq %x key %x\n",
	rd->hdr.request, rd->hdr.len, rd->hdr.seq, rd->hdr.key);

    return (FALSE);
}

static boolean_t
kdp_connect(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_connect_req_t	*rq = &pkt->connect_req;
    int			plen = *len;
    kdp_connect_reply_t	*rp = &pkt->connect_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    if (kdp.is_conn) {
	if (rq->hdr.seq == kdp.conn_seq)	/* repeated request */
	    rp->error = KDPERR_NO_ERROR;
	else
	    rp->error = KDPERR_ALREADY_CONNECTED;
    }
    else {
	kdp.reply_port = rq->req_reply_port;
	kdp.exception_port = rq->exc_note_port;
	kdp.is_conn = TRUE;
	kdp.conn_seq = rq->hdr.seq;

	rp->error = KDPERR_NO_ERROR;
    }

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_disconnect(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_disconnect_req_t	*rq = &pkt->disconnect_req;
    int				plen = *len;
    kdp_disconnect_reply_t	*rp = &pkt->disconnect_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    if (!kdp.is_conn)
	return (FALSE);

    *reply_port = kdp.reply_port;

    kdp.reply_port = kdp.exception_port = 0;
    kdp.is_halted = kdp.is_conn = FALSE;
    kdp.exception_seq = kdp.conn_seq = 0;

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_hostinfo(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_hostinfo_req_t	*rq = &pkt->hostinfo_req;
    int			plen = *len;
    kdp_hostinfo_reply_t *rp = &pkt->hostinfo_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    kdp_machine_hostinfo(&rp->hostinfo);

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_suspend(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_suspend_req_t	*rq = &pkt->suspend_req;
    int			plen = *len;
    kdp_suspend_reply_t *rp = &pkt->suspend_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    kdp.is_halted = TRUE;

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_resumecpus(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_resumecpus_req_t	*rq = &pkt->resumecpus_req;
    int				plen = *len;
    kdp_resumecpus_reply_t	*rp = &pkt->resumecpus_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    kdp.is_halted = FALSE;

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_writemem(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_writemem_req_t	*rq = &pkt->writemem_req;
    int			plen = *len;
    kdp_writemem_reply_t *rp = &pkt->writemem_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    if (rq->nbytes > MAX_KDP_DATA_SIZE)
	rp->error = KDPERR_BAD_NBYTES;
    else {
	copywithin(rq->data, rq->address, rq->nbytes);
	rp->error = KDPERR_NO_ERROR;
    }

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_readmem(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_readmem_req_t	*rq = &pkt->readmem_req;
    int			plen = *len;
    kdp_readmem_reply_t *rp = &pkt->readmem_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    if (rq->nbytes > MAX_KDP_DATA_SIZE)
	rp->error = KDPERR_BAD_NBYTES;
    else {
	unsigned int	n = rq->nbytes;

	copywithin(rq->address, rp->data, rq->nbytes);
	rp->error = KDPERR_NO_ERROR;

	rp->hdr.len += n;
    }

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_maxbytes(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_maxbytes_req_t	*rq = &pkt->maxbytes_req;
    int			plen = *len;
    kdp_maxbytes_reply_t *rp = &pkt->maxbytes_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    rp->max_bytes = MAX_KDP_DATA_SIZE;

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_regions(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_regions_req_t	*rq = &pkt->regions_req;
    int			plen = *len;
    kdp_regions_reply_t *rp = &pkt->regions_reply;
    kdp_region_t	*r;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    r = rp->regions;
    rp->nregions = 0;

    /* one region: the kernel's first gigabyte */
    r->address = (void *) 0;
    r->nbytes = 0x40000000;
    r->protection = VM_PROT_ALL; r++; rp->nregions++;

    rp->hdr.len += rp->nregions * sizeof (kdp_region_t);

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_writeregs(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_writeregs_req_t	*rq = &pkt->writeregs_req;
    int			plen = *len;
    int			size;
    kdp_writeregs_reply_t *rp = &pkt->writeregs_reply;

    if (plen < sizeof (*rq))
	return (FALSE);

    size = rq->hdr.len - sizeof(kdp_hdr_t) - sizeof(unsigned int);
    rp->error = kdp_machine_write_regs(rq->cpu, rq->flavor, rq->data, &size);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}

static boolean_t
kdp_readregs(
    kdp_pkt_t		*pkt,
    int			*len,
    unsigned short	*reply_port
)
{
    kdp_readregs_req_t	*rq = &pkt->readregs_req;
    int			plen = *len;
    kdp_readregs_reply_t *rp = &pkt->readregs_reply;
    int			size;

    if (plen < sizeof (*rq))
	return (FALSE);

    rp->hdr.is_reply = 1;
    rp->hdr.len = sizeof (*rp);

    rp->error = kdp_machine_read_regs(rq->cpu, rq->flavor, rp->data, &size);
    rp->hdr.len += size;

    *reply_port = kdp.reply_port;
    *len = rp->hdr.len;

    return (TRUE);
}
