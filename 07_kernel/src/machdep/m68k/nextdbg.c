/*
 * Copyright (c) 1990, NeXT Inc.
 *
 * HISTORY
 *  2-Mar-90  Gregg Kellogg (gk) at NeXTE
 *	Clean up #import syntax.
 *
 * 28-Feb-90  John Seamons (jks) at NeXT
 *	General cleanup of Ethernet-based debugging routines.
 */
 
#pragma CC_OPT_OFF

/*
 * plan 739 (D166, D013, D024, D104): the 1997 m68k nextdbg.c.
 * NeXTMach mk-108.1 next/nextdbg.c with the include lines reduced to the OPENSTEP
 * paths the 1997 unit needs (next/cpu.h is not included in C: it is assembly only;
 * the other NeXTMach headers are not used) and these changes, from the original
 * bytes [0x4095460, 0x4096700) (plans 737-738):
 *	functions that differ from NeXTMach: dbg_trap, kdbg_connect, rdmem, wrmem, kdebug_send, m68k_dbginit (NeXTMach nextdbginit)
 *	unchanged: dbg_kresume, hookbuserr, unhookbuserr
 *	new functions: dbg_panic, dbg_dispatch, gdb_from_trap, dbg_from_ether, dbg_process, dbg_recv, dbg_ack, SENDEXC, inet_aton
 *	removed (not in this 1997 unit): the functions dbg_exit, btoh, htobs, htob, kdbg, putnib, putpkt, ack, getnib, getpkt, gfunc, pfunc
 * The original has no symbols for its static data and static functions: the NeXTMach
 * statics keep their names; dbg_nest, dbg_from_net, dbg_sig, dbg_fault_addr,
 * dbg_vecoff, dbg_recv, dbg_ack, the packet structures and the request and reply
 * names are given by this project (D166); ri, ti and locked are the names of the
 * words of NeXTMach struct kdb_net with the same roles.  The goto, the empty else
 * and the other forms marked plan 739 are forms that give the original bytes, not
 * evidence of the original source.  The file needs #pragma CC_OPT_OFF (line 12):
 * the compiler then prints "warning: optimization turned off" (a known warning of
 * the acceptance record).  Lines marked plan 739, and the lines of a plan 739
 * BEGIN/END region (which may include unchanged lines), differ from NeXTMach.
 */

/* plan 739 (D024): NeXTMach lines 14-17 removed (not in the 1997 kernel) */
#import <sys/types.h>
#import <sys/param.h>
/* plan 739 (D024): NeXTMach lines 20-41 removed (not in the 1997 kernel) */

#define NO_IPLMEAS	1	/* Don't measure, we're recursive */
#import <machine/spl.h>
/* plan 739 (D024): NeXTMach lines 45-56 removed (not in the 1997 kernel) */

#define	VEC_BUSERR	2
#define	VEC_ADDRERR	3
#define	VEC_ILLINST	4
#define	VEC_TRACE	9
/* plan 739 (D024, D166) BEGIN: declarations and data */
#define	VEC_BRKPT	47	/* trap #15 */
/* plan 739 END */
#define ERROR(s) panic(s)

#define	R_D0		0
#define	R_D1		1
#define	R_D2		2
#define	R_D3		3
#define	R_D4		4
#define	R_D5		5
#define	R_D6		6
#define	R_D7		7

#define	R_A0		8
#define	R_A1		9
#define	R_A2		10
#define	R_A3		11
#define	R_A4		12
#define	R_A5		13
#define	R_A6		14
#define	R_A7		15
#undef	R_SP
#define	R_SP		R_A7

#define	NREGS		16

#define	SR_T		0x8000

/* plan 739 (D024): NeXTMach lines 89-91 removed (not in the 1997 kernel) */
typedef int jmpbuf[17];
static jmpbuf dbgjb;
typedef	unsigned unlong;
/* plan 739 (D024): NeXTMach line 95 removed (not in the 1997 kernel) */

struct sf_4wd {
	short sf4_sr;
	unlong sf4_pc;
	short sf4_ftype:4,		/* can be 0 or 1 */
	      sf4_vecoff:12;
};

struct sf_6wd {
	short sf6_sr;
	unlong sf6_pc;
	short sf6_ftype:4,		/* must be 2 */
	      sf6_vecoff:12;
	unlong sf6_instadr;
};

struct sf_float {
	short sf_sr;
	unlong sf_pc;
	short sf_ftype:4,		/* must be 3 */
	      sf_vecoff:12;
	unlong sf_effadr;
};

struct sf_access {
	short sf_sr;
	unlong sf_pc;
	short sf_ftype:4,		/* must be 7 */
	      sf_vecoff:12;
	unlong sf_junk[13];
};

struct sf_10wd {
	short sf10_sr;
	unlong sf10_pc;
	short sf10_ftype:4,		/* must be 9 */
	      sf10_vecoff:12;
	unlong sf10_instadr;
	short sf10_junk[4];
};

struct sf_16wd {
	short sf16_sr;
	unlong sf16_pc;
	short sf16_ftype:4,		/* must be 10 */
	      sf16_vecoff:12;
	short sf16_junk[12];
};

struct sf_46wd {
	short sf46_sr;
	unlong sf46_pc;
	short sf46_ftype:4,		/* must be 11 */
	      sf46_vecoff:12;
	short sf46_junk[42];
};

union stk_frms {
	struct sf_4wd sf_4wd;
	struct sf_6wd sf_6wd;
	struct sf_10wd sf_10wd;
	struct sf_16wd sf_16wd;
	struct sf_46wd sf_46wd;
};

#define	sf_sr		sf_4wd.sf4_sr
#define	sf_pc		sf_4wd.sf4_pc
#define	sf_ftype	sf_4wd.sf4_ftype
#define	sf_vecoff	sf_4wd.sf4_vecoff

struct nextdbgpcb {
	unsigned usp;
	unsigned regs[16];
	short zero;
	union stk_frms sf;
};

struct nextdbgpcb client_pcb;
static int *nofault;
int client_running;
#define DBG_BUSERR	2
#define DBG_ADRERR	3
#define DBG_TRACE	9
#define DBG_BKPT	46	/* trap #14 */

static void hookbuserr(), unhookbuserr();

static int *oldbuserr, *oldadrerr, *oldtrace, *oldbkpt;
static int trace_expected;
/* plan 739 (D024): NeXTMach lines 185-187 removed (not in the 1997 kernel) */

/* plan 739 (D024, D166) BEGIN: dbg_dispatch, dbg_from_ether, dbg_kresume, dbg_panic, dbg_process, dbg_trap, gdb_from_trap, kdbg_connect, m68k_dbginit, rdmem, wrmem */
/* plan 739 (D166): request kinds and reply codes of the debug protocol; the names are this project's guesses of the roles, read from the bytes */
#define	DBG_RQ_CONNECT		8
#define	DBG_RQ_QUERY		9
#define	DBG_RQ_REGIONS		11
#define	DBG_RQ_READMEM		12
#define	DBG_RQ_WRITEMEM		13
#define	DBG_RQ_READREGS		14
#define	DBG_RQ_WRITEREGS	15
#define	DBG_RQ_ACK16		16
#define	DBG_RQ_INTERRUPT	17
#define	DBG_RQ_RESUME		18
#define	DBG_RQ_STEP		19
#define	DBG_RQ_DETACH		20
#define	DBG_RQ_REBOOT		21
#define	DBG_RP_OK		1
#define	DBG_RP_CONNECTED	2
#define	DBG_RP_MEMORY		3
#define	DBG_RP_REGS		4
#define	DBG_RP_QUERY		5
#define	DBG_RP_REGIONS		6
#define	DBG_RP_ERROR		22

/* plan 739 (D166): packet layouts reconstructed from the original bytes: 42 bytes of Ethernet, IP and UDP headers, then seq @0, code @4,
 * addr @12, len @16, dlen @20 and the data @24 of the debug header (names are this project's) */
struct dbg_pkt {
	char dbg_hdr[42];
	char *seq;
	int dbg_type;
};
extern struct dbg_pkt *dbg_connect_pkt;
/* plan 739 (D166): the first three words of the COMMON kdb_net; ri, ti and locked are the names of the words of NeXTMach struct kdb_net
 * (next/nextdbg.h) with the same roles; the 1997 layout differs, so only these three are declared */
struct kdb_n { char *ri; char *ti; int locked; };
struct dbg_hdr { char *seq; int code; int pad; char *addr; int len; int dlen; char data[512]; };
extern struct kdb_n kdb_net;
#define SFADR(off)	(*(int *)((char *)&client_pcb.sf + (off)))
extern void bcopy(), nmi_prf(), adb_watchdog();
extern int dbg_setjmp(), get_vbr(), cache_push();
extern void dbg_longjmp();
extern int dbg_process();
extern int en_pkt[4], kdb_ipaddr;
extern struct dbg_pkt *en_recv();
extern void en_send();
static struct dbg_pkt *dbg_recv();
extern char *index();
extern void mon_call(), mon_boot();
extern int slot_id;
extern short dma_chip;
extern unsigned char machine_type;
extern int rdmem(), wrmem();
extern int SENDEXC();
static void dbg_ack();
extern void en_bufalloc();

/* plan 739 (D166): the five static words at 0x40b5628..0x40b5638 of the original (names are this project's) */
static int dbg_nest;
static int dbg_from_net;
static int dbg_sig;
static int dbg_fault_addr;
static int dbg_vecoff;

m68k_dbginit()
{
	int *vbp;
	int _dbg_trap();

	vbp = (int *)get_vbr();
	oldbkpt = (int *)vbp[VEC_BRKPT];
	vbp[VEC_BRKPT] = (int)_dbg_trap;
	dbg_kresume();
	adb_watchdog(0);
	dbg_process(dbg_connect_pkt);
	adb_watchdog(1);
}

dbg_kresume()
{
	int sig;
	struct nextdbgpcb *pcb;
	struct sf_4wd *sfp;

	if (sig = dbg_setjmp(dbgjb))
		return(sig);
	client_pcb.regs[R_SP] -= sizeof(struct sf_4wd);
	sfp = (struct sf_4wd *)client_pcb.regs[R_SP];
	sfp->sf4_sr = client_pcb.sf.sf_sr;
	sfp->sf4_pc = client_pcb.sf.sf_pc;
	sfp->sf4_ftype = 0;
	nofault = dbgjb;
	_dbg_kresume();
	/* doesn't return */
}

dbg_panic(s)
char *s;
{
	nmi_prf("dbg_panic: %s\n", s);
	while (1)
		;
}

int *
dbg_trap(pcb)
register struct nextdbgpcb *pcb;
{
	int sig;
	int *vbp;
	int _dbg_trap();

	adb_watchdog(0);
	vbp = (int *)get_vbr();
	if (client_running) {
		if ((pcb->sf.sf_sr & 0x2000) == 0) {
			switch(pcb->sf.sf_vecoff>>2) {
			case VEC_BRKPT:
				adb_watchdog(1);
				return(oldbkpt);
			case VEC_TRACE:
				adb_watchdog(1);
				return(oldtrace);
			default:
				nmi_prf("dbg_trap returning, vecoff = %d\n",
					pcb->sf.sf_vecoff);
				dbg_panic("dbg_trap: bad user vecoff");
			}
		}

		client_running = 0;
		client_pcb = *pcb;
		dbg_fault_addr = 0;
		dbg_vecoff = pcb->sf.sf_vecoff;

		switch (pcb->sf.sf_ftype) {
		case 0:
		case 1:
			client_pcb.regs[R_SP] += sizeof(struct sf_4wd);
			break;
		case 2:
			client_pcb.regs[R_SP] += sizeof(struct sf_6wd);
			break;
		case 3:
			client_pcb.regs[R_SP] += sizeof(struct sf_float);
			break;
		case 7:
			client_pcb.regs[R_SP] += sizeof(struct sf_access);
			dbg_fault_addr = SFADR(16);
			break;
		case 9:
			client_pcb.regs[R_SP] += sizeof(struct sf_10wd);
			dbg_fault_addr = SFADR(8);
			break;
		case 10:
			client_pcb.regs[R_SP] += sizeof(struct sf_16wd);
			dbg_fault_addr = SFADR(16);
			break;
		case 11:
			client_pcb.regs[R_SP] += sizeof(struct sf_46wd);
			dbg_fault_addr = SFADR(16);
			break;
		default:
			dbg_panic("stack frame screw-up\n");
		}

		switch (client_pcb.sf.sf_vecoff>>2) {
		case VEC_BUSERR:
		case VEC_ADDRERR:
			dbg_sig = 1;
			break;
		case VEC_ILLINST:
			dbg_sig = 2;
			break;
		case VEC_TRACE:
			if (nofault && trace_expected) {
				int *vbp;

				vbp = (int *)get_vbr();
				vbp[VEC_TRACE] = (int)oldtrace;
				client_pcb.sf.sf_sr &= ~SR_T;
				trace_expected = 0;
			}
			/* fall through */
		case VEC_BRKPT:
			dbg_sig = 6;
			break;
		default:
			dbg_sig = 5;
			break;
		}
	} else
		dbg_sig = 5;
	adb_watchdog(1);
	dbg_dispatch();
}

dbg_dispatch()
{
	int *jbp;

	if (nofault) {
		jbp = nofault;
		nofault = 0;
		spl7();
		dbg_longjmp(jbp, dbg_sig);
	}
	dbg_panic("debugger screw-up\n");
}

kdbg_connect(arg)
{
	struct kdb_n *n = &kdb_net;
	char *cp;
	int len;

	if (n->locked)
		return(0);
	n->ri = 0;
	n->ti = 0;
	en_bufalloc(arg);
	dbg_connect_pkt = dbg_recv(1);
	if (dbg_connect_pkt) {
		if (dbg_connect_pkt->dbg_type != DBG_RQ_CONNECT) {
			nmi_prf("old debugging info packet (%d) ignored\n", dbg_connect_pkt->dbg_type);
			return(0);
		}
		n->locked = 1;
		if (dbg_nest)
			dbg_dispatch();
		asm ("trap #15");
		return(1);
	}
	return(0);
}

gdb_from_trap(regs, sr, pc, faultaddr)
int *regs;
int sr;
unsigned pc;
int faultaddr;
{
	struct kdb_n *n = &kdb_net;

	if (++dbg_nest != 1)
		return;
	client_pcb.sf.sf_vecoff = 8;
	dbg_sig = 1;
	dbg_fault_addr = faultaddr;
	bcopy(regs, client_pcb.regs, 72);
	client_pcb.sf.sf_pc = pc;
	client_pcb.sf.sf_sr = sr;
	if (!n->locked)
		return;
	nmi_prf("gdb_from_trap:pc %x sp %x sr %x faultaddr %x\n",
		client_pcb.sf.sf_pc, client_pcb.regs[R_SP], sr, faultaddr);
	dbg_dispatch();
}

dbg_from_ether(pkt)
struct dbg_pkt *pkt;
{
	if (!kdb_net.locked)
		return;
	if (pkt->dbg_type != DBG_RQ_INTERRUPT)
		return;
	dbg_connect_pkt = pkt;
	dbg_from_net = 1;
	asm ("trap #15");
}

dbg_process(pkt)
struct dbg_pkt *pkt;
{
	struct dbg_hdr *reply = (struct dbg_hdr *)((char *)en_pkt[2] + 42);
	int err;
	int i;
	int unused1, unused2;
	char *cp;
	struct kdb_n *np = &kdb_net;
	struct dbg_hdr *req;
	int *wp;
	int _dbg_trap();

	if (!np->locked || !pkt)
		return;
	nmi_prf("connecting to debugger\n");
	for (;;) {
		req = (struct dbg_hdr *)((char *)pkt + 42);
		switch ((int)req->code) {
		case DBG_RQ_CONNECT:
			cp = index((char *)req + 24, ':');
			if (cp)
				*cp = 0;
			nmi_prf("\ndebugging connection from %s on %s\n",
				(char *)req + 24, cp + 1);
			np->ti = 0;
			reply->code = DBG_RP_CONNECTED;
			break;
		case DBG_RQ_QUERY:
			reply->len = 1;
			reply->code = DBG_RP_QUERY;
			break;
		case DBG_RQ_REGIONS:
			wp = (int *)((char *)reply + 24);
			reply->dlen = 0;
			*wp++ = slot_id;
			*wp++ = 0x20000;
			*wp++ = 1;
			*wp++ = slot_id + 0x1000000;
			*wp++ = 0x20000;
			*wp++ = 1;
			*wp++ = slot_id + 0x2000000;
			*wp++ = 0xC0040;
			*wp++ = 3;
			*wp++ = slot_id + 0x2100000;
			*wp++ = 0x1E000;
			*wp++ = 3;
			*wp++ = slot_id + 0x4000000;
			*wp++ = dma_chip == 313 ? (machine_type == 3 ? 0x2000000 : 0x4000000) : 0x8000000;
			*wp++ = 3;
			switch (machine_type) {
			case 3:
				*wp++ = 0x4000000;
				*wp++ = 0x8000000;
				*wp++ = 3;
				*wp++ = 0xC000000;
				*wp++ = 0x10000000;
				*wp++ = 3;
				*wp++ = 0x24000000;
				*wp++ = 0x28000000;
				*wp++ = 3;
				*wp++ = 0x2C000000;
				*wp++ = 0x30000000;
				*wp++ = 3;
				break;
			case 1:
			case 2:
				break;
			case 4:
			case 5:
			default:
				*wp++ = slot_id + 0x2200000;
				*wp++ = 0x9000;
				*wp++ = 3;
				*wp++ = slot_id + 0x2210000;
				*wp++ = 4;
				*wp++ = 3;
				*wp++ = slot_id + 0x3E00000;
				*wp++ = 0x80000;
				*wp++ = 3;
				break;
			}
			*wp++ = 0x10000000;
			*wp++ = 0x4000000;
			*wp++ = 3;
			reply->dlen = (char *)wp - ((char *)reply + 24);
			reply->code = DBG_RP_REGIONS;
			break;
		case DBG_RQ_ACK16:
		case DBG_RQ_INTERRUPT:
			reply->code = DBG_RP_OK;
			reply->dlen = 0;
			break;
		case DBG_RQ_DETACH:
			kdb_net.locked = 0;
			dbg_from_net = 1;
		case DBG_RQ_RESUME:
		case DBG_RQ_STEP:
			reply->code = DBG_RP_OK;
			reply->dlen = 0;
			dbg_ack();
			if (client_pcb.sf.sf_sr & SR_T) {
				wp = (int *)get_vbr();
				oldtrace = (int *)wp[VEC_TRACE];
				wp[VEC_TRACE] = (int)_dbg_trap;
				trace_expected = 1;
			} else ;	/* plan 739 (D166): the bytes need this empty else (a jump to the next instruction) */
			dbg_kresume();
			if (dbg_from_net) {
				dbg_from_net = 0;
				pkt = dbg_connect_pkt;
				dbg_connect_pkt = 0;
				continue;
			}
			SENDEXC();
			goto recv;
		case DBG_RQ_READMEM:
			if (req->len > 512)
				dbg_panic("Bad length of data to process");
			for (i = 0; i < req->len; i += 4) {
				if (rdmem(req->addr + i, 4, (int *)((char *)reply + 24 + i)))
					goto error;
			}
			reply->code = DBG_RP_MEMORY;
			reply->dlen = req->len;
			break;
		case DBG_RQ_WRITEMEM:
			if (req->dlen != 512)
				dbg_panic("Bad length of data to process");
			err = 0;
			for (i = 0; i <= 511; i += 4) {
				wp = (int *)((char *)req + 24 + i);
				err = wrmem(req->addr + i, 4, *wp);
				if (err)
					goto error;
			}
			reply->code = DBG_RP_OK;
			reply->dlen = 0;
			break;
		case DBG_RQ_READREGS:
			bcopy(client_pcb.regs, (char *)reply + 24, 72);
			reply->dlen = 72;
			reply->code = DBG_RP_REGS;
			break;
		case DBG_RQ_WRITEREGS:
			bcopy((char *)req + 24, client_pcb.regs, 72);
			reply->code = DBG_RP_OK;
			reply->dlen = 0;
			break;
		case DBG_RQ_REBOOT:
			if (req->dlen != 0 && req->dlen <= 511) {
				req->data[req->dlen] = 0;
				mon_call((char *)req + 24);
			} else
				mon_boot(0);
			break;
		default:
			nmi_prf("kdbg unknown rq type %d\n", reply->code);
		error:
			reply->code = DBG_RP_ERROR;
			reply->dlen = 0;
		}
		dbg_ack();
	recv:
		pkt = dbg_recv(0);
	}
}

rdmem(addr, size, valp)
unsigned addr;
int size, *valp;
{
	int error;

	if (error = dbg_setjmp(dbgjb)) {
		unhookbuserr();
		return(error);
	}
	nofault = dbgjb;
	hookbuserr();
	switch (size) {
	case sizeof(char):
		*valp = *(char *)addr;
		*valp &= 0xff;
		break;
	case sizeof(short):
		*valp = *(short *)addr;
		*valp &= 0xffff;
		break;
	case sizeof(int):
		*valp = *(int *)addr;
		break;
	default:
		nofault = 0;
		dbg_panic("rdmem: bad size\n");
	}
	unhookbuserr();
	nofault = 0;
	return(0);
}

wrmem(addr, size, val)
unsigned addr;
int size, val;
{
	int error;

	if (error = dbg_setjmp(dbgjb)) {
		unhookbuserr();
		return(error);
	}
	nofault = dbgjb;
	hookbuserr();

	switch (size) {
	case sizeof(char):
		*(char *)addr = val;
		break;
	case sizeof(short):
		*(short *)addr = val;
		break;
	case sizeof(int):
		*(int *)addr = val;
		break;
	default:
		nofault = 0;
		dbg_panic("wrmem: bad size\n");
	}
	cache_push();
	nofault = 0;
	unhookbuserr();
	cache_push();
	return(0);
}
/* plan 739 END */

static void
hookbuserr()
{
	int *vbp;
	int _dbg_trap();

	vbp = (int *)get_vbr();		/* Get the vector base register */
	oldbuserr = (int *)vbp[DBG_BUSERR];
	oldadrerr = (int *)vbp[DBG_ADRERR];
	vbp[DBG_BUSERR] = (int) _dbg_trap;
	vbp[DBG_ADRERR] = (int) _dbg_trap;
}

static void
unhookbuserr()
{
	int *vbp;

	vbp = (int *)get_vbr();		/* Get the vector base register */
	vbp[DBG_BUSERR] = (int)oldbuserr;
	vbp[DBG_ADRERR] = (int)oldadrerr;
}

/* plan 739 (D024, D166) BEGIN: SENDEXC, dbg_ack, dbg_recv, inet_aton, kdebug_send */
kdebug_send(a, b)
{
	char *p;
	int *q;

	p = (char *)en_pkt[2];
	q = (int *)(p + 42);
	*q = b;
	en_send(a, p, 0x242);
}

static struct dbg_pkt *
dbg_recv(arg)
{
	struct kdb_n *np = &kdb_net;
	struct dbg_pkt *pkt;
	struct dbg_hdr *q;
	int i = 0;
	int unused;
	int port;

	again:			/* plan 739 (D166): the bytes need this goto, not a for or while loop */
		do {
			pkt = en_recv(&port, 0x242, np->locked, kdb_ipaddr);
		} while (!pkt && (arg == 0 || i++ < arg));
		if (arg != 0 && pkt == 0)
			return(0);
		if (port != 1139)
			goto again;
		q = (struct dbg_hdr *)((char *)pkt + 42);
		if (q->seq != np->ri) {
			if (q->seq == np->ri - 1)
				kdebug_send(1139, q->seq);
			else if (q->seq == 0 && q->code == DBG_RQ_CONNECT) {
				np->ri = 0;
				return(pkt);
			}
			goto again;
		}
		return(pkt);
}

static void
dbg_ack()
{
	struct kdb_n *np = &kdb_net;

	kdebug_send(1139, np->ri);
	np->ri++;
}

SENDEXC()
{
	struct kdb_n *np = &kdb_net;
	char *pkt = (char *)en_pkt[3];
	struct dbg_hdr *q = (struct dbg_hdr *)(pkt + 42);
	struct dbg_pkt *ret;
	int i;
	int port;
	struct dbg_hdr *q2;

	q->code = dbg_sig;
	q->len = dbg_vecoff;
	q->addr = (char *)dbg_fault_addr;
	q->seq = np->ti;
	for (;;) {
		en_send(1140, pkt, 0x242);
		for (i = 0; i <= 49999; i++) {
			ret = en_recv(&port, 0x242, np->locked, kdb_ipaddr);
			if (ret) {
				if (port == 1140 && ret->seq == np->ti) {
					np->ti++;
					return;
				}
				port = 1139;
				q2 = (struct dbg_hdr *)((char *)ret + 42);
				if (q2->seq == np->ri - 1)
					kdebug_send(1139, q2->seq);
			}
		}
	}
}

inet_aton(str, addr)
char *str;
long *addr;
{
	register char *cp;
	register char *p;
	long u;
	long val;

	p = (char *)&u;
	val = 0;
	cp = str;
	for (; *cp; cp++) {
		if (*cp == '.') {
			if (p >= (char *)&u + 3)
				return(0);
			*p++ = val;
			val = 0;
		} else {
			if (*cp < '0' || *cp > '9')
				return(0);
			val = val * 10;
			val += *cp - '0';
			if (val > 255 || val < 0)
				return(0);
		}
	}
	if (p != (char *)&u + 3)
		return(0);
	*p = val;
	*addr = u;
	return(1);
}
/* plan 739 END */

/* plan 739 (D024): NeXTMach lines 978-979 removed (a blank line) */
/* plan 779 (D178): dbg_connect_pkt tentative definition (type of the extern above) written to match the original bytes (D024, plan 778.15) */
struct dbg_pkt *dbg_connect_pkt;
