/*	@(#)if_en.c	1.0	11/17/87	(c) 1987 NeXT	*/

/* 
 **********************************************************************
 * HISTORY
 * 22-Aug-90  John Seamons (jks) at NeXT
 *	Changed call to dma_sync_cache to pass direction argument.
 *
 *  4-Aug-90  John Seamons (jks) at NeXT
 *	Added automatic switching between thin and TPE.
 *
 *  4-Jun-90  John Seamons (jks) at NeXT
 *	Use bytecopy() instead of bcopy() when setting interface address
 *	as required by 040.
 *
 * 09-Apr-90  Bradley Taylor (btaylor) at NeXT
 *	Open driver to non-IP protocols using new netbuf and netif 
 *	interfaces. Some cleanup still remains tbd (XXX).
 *
 * 19-Jun-89  Mike DeMoney (mike) at NeXT
 *	Cleaned up spls(), make sure timeouts running at splimp()
 *	(i.e. device level).
 *
 * 17-Nov-87  John Seamons (jks) at NeXT
 *	Created.
 *
 **********************************************************************
 */ 

/*
 * Driver for the NeXT integrated Ethernet controller
 *
 * FIXME:
 *	- write "next" at "next+0x200" when not chunk aligned!
 *	- remove endbug printf's.
 *	- instrumentation to find out if more receive buffers are needed.
 *	- grow and shrink receive buffers as needed.
 *	- don't always copy transmit data.
 *	- on receive, should look at BOP/EOP bits to determine false chains.
 *	- splimp() could be lowered to be equal to splnet() as long as dma
 *	  softint's (i.e. effectively device interrupts) are at splnet
 */

/*
 * plan 727 (D163, D013, D024, D104, D110): the 1997 m68k if_en.c.
 * NeXTMach mk-108.1 nextif/if_en.c with the include lines in OPENSTEP paths
 * and these changes, from the original bytes [0x408db8a, 0x408fd9e) (plan 725):
 *	functions that differ from NeXTMach: enattach, eninit, en_rx_grabbufs, en_rx_dmaintr, enoutput, enstart, en_antijam, en_jam, encontrol, en_setaddr, en_xmit
 *	new functions: en_getreg, en_putreg, en_regok, en_accept_multicast, en_rx_devintr, en_tx_guard, en_tx_devintr, enintsetup, en_bufalloc
 *	en_tx_dmaintr, en_recv, en_send are written as file-scope asm (the
 *	text of cc -S of a C form patched to the original bytes; plan 726,
 *	D163): no C form was found that gives the original bytes
 *	struct en_softc (1324 bytes): five new members and two new flags
 *	(ENF_RXMODE 0x20, ENF_TXGUARD 0x40); the offsets and sizes are from the
 *	bytes, the names are this project's
 *	the controller registers are read and written by byte through
 *	en_getreg, en_putreg and en_regok (three static functions without a
 *	symbol in the original; copywithin returns 14 on a fault)
 *	the standalone (gdb) packet buffers dbgstack, en_pkt and en_pkt_hdr and
 *	the CRC-32 table crctab are globals of the original
 *	ppkt (NeXTMach, under DEBUG) is not built
 * The register constants are numbers; the comments give the names of
 * if_enreg.h where it has them (D163).  Lines marked plan 727, and the lines
 * of a plan 727 BEGIN/END region (which may include unchanged lines), differ
 * from NeXTMach.
 */

#import <en.h>
#if NEN > 0
#import <gdb.h>

#import <sys/param.h>
#import <sys/systm.h>
#import <sys/time.h>
#import <sys/kernel.h>
#import <sys/mbuf.h>
#import <sys/buf.h>
#import <sys/protosw.h>
#import <sys/socket.h>
#import <sys/ioctl.h>
#import <sys/errno.h>
#import <sys/callout.h>
#import <net/if.h>
#import <net/netbuf.h>
#import <net/netisr.h>
#import <net/route.h>
/* plan 727 (D024, D163) BEGIN: declarations and data */
#import <m68k/psl.h>	/* plan 727 (D104): NeXTMach <next/psl.h> */
#import <mach/m68k/vm_param.h>	/* plan 727 (D104): NeXTMach <next/vm_param.h> */
#import <next/event_meter.h>
#import <m68k/bmap.h>	/* plan 727 (D104): NeXTMach <next/bmap.h> */
#import <nextdev/dma.h>
#import <dev/busvar.h>	/* plan 727 (D104): NeXTMach <nextdev/busvar.h> */
/* plan 727 END */
#import <nextif/if_enreg.h>

/* plan 727 (D024, D163) BEGIN: declarations and data */
#import <machine/spl.h>	/* plan 727 (D104): NeXTMach <next/spl.h> */

/* plan 727 (D110): names of NeXTMach <next/cpu.h> (kernel, non-assembler branch; lines 95-98, 139, 140, 151, 213, 226, 227, 254, 255)
 * used by this file; <next/scr.h> is not used by it */
extern int slot_id, slot_id_bmap;
#define	SLOT_ID		slot_id
#define	SLOT_ID_BMAP	slot_id_bmap
#define	P_ENETX_CSR	(SLOT_ID+0x02000110)
#define	P_ENETR_CSR	(SLOT_ID+0x02000150)
#define	P_ENET		(SLOT_ID_BMAP+0x02006000)
#define	I(l,i,b)	(((b) << 8) | ((l) << 4) | (i))
#define	I_ENETX_DMA	I(6,1,28)
#define	I_ENETR_DMA	I(6,2,27)
#define	I_ENETX		I(3,3,10)
#define	I_ENETR		I(3,4,9)
/* plan 727 END */
#import <kern/xpr.h>

#import <net/etherdefs.h>
/* plan 727 (D024, D163) BEGIN: declarations and data */
#import <vm/pmap.h>	/* plan 727 (D024): mem_region */
/* plan 727 END */
#import <nextif/if_bus.h>

#if defined(INET) && (defined(DEBUG) || defined(GDB))
/*
 * We'd really like to rid ourselves of any IP-level protocol stuff
 * in this module. Oh, well....
 */
#import <netinet/in.h>
#import <netinet/in_systm.h>
#import <netinet/in_var.h>
#import <netinet/ip.h>
#import <netinet/if_ether.h>
#import <netinet/tcp.h>
#import <netinet/udp.h>
#import <netinet/ip_icmp.h>
#endif

#ifndef ntohs
#define ntohs(x) (x)
#endif

#if	DEBUG
int	endbug;
#define	dbug1		if (endbug & 1) printf		/* rx/tx dbug */
#define	dbug2		if (endbug & 2) printf		/* init dbug */
#define	DBUG_PPKT	0x04
#define	dbug4		if (endbug & DBUG_PPKT) printf	/* dump pkts */
#else	DEBUG
#define	dbug1
#define	dbug2
#define	dbug4
#endif	DEBUG

#define NRXBUFS		16
#define NTXBUFS		8
#define	EN_TX_TIMEOUT	hz
#define	EN_RX_TIMEOUT	10

u_char etherbcastaddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

int	enprobe(), enattach();
void	en_rx_dmaintr(), en_tx_dmaintr();
int	eninit(netif_t);
int 	enoutput(netif_t, netbuf_t, void *);
int	encontrol(netif_t, const char *, void *);
int	enreset();

extern netbuf_t engetbuf();

struct	bus_device *eninfo[NEN];
struct	bus_driver endriver = {
	enprobe, 0, enattach, 0, 0, 0, 0, 1, "en", eninfo,
};

/* plan 727 (D024, D163) BEGIN: declarations and data */
/* plan 727 (D024, D163): the CRC-32 table of the original __data 0x40b2492 (global _crctab; not in NeXTMach) */
unsigned int crctab[256] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
	0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
	0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
	0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

/* plan 727 END */
struct	en_softc {
	netif_t is_if;			/* network visible interface */
	struct ether_addr is_addr;	/* hardware Ethernet address */
#if GDB
	struct in_addr is_ac_ipaddr;	/* copy of ip address for GDB */
#endif
	struct	dma_chan is_tx_dmachan;	/* transmitter DMA info */
	struct	dma_chan is_rx_dmachan;	/* receiver DMA info */
	volatile struct	en_regs *is_regs; /* controller registers */
	int	is_flags;
#define ENF_RUNNING	0x00000001	/* eninit has been called */
#define ENF_OACTIVE	0x00000002	/* transmit in progress */
#define ENF_SETADDR	0x00000004	/* change physical address */
#define	ENF_JAMMED	0x00000008	/* down because of excessive jams */
#define	ENF_JAM_MSG	0x00000010	/* message has been seen */
/* plan 727 (D024, D163) BEGIN: declarations and data */
#define	ENF_RXMODE	0x00000020	/* plan 727 (D024, D163): receive mode update pending */
#define	ENF_TXGUARD	0x00000040	/* plan 727 (D024, D163): transmit guard timer expired */
#define	EN_JAM_MAX	10		/* shutdown after this many jams */
#define	EN_ANTIJAM	(hz * 10)	/* recheck network after this time */
	int	is_jam_count;		/* current jam count */
	int	is_tpe_count;		/* plan 727 (D024, D163) */
	struct	timeval is_last_rx;	/* last time something received */
	u_int	is_rxstate;		/* plan 727 (D024, D163) */
/* plan 727 END */
	struct	en_dmabuf is_rx_dhp[NRXBUFS];
	struct	en_dmabuf is_tx_dhp[NTXBUFS];
	struct	dma_hdr *is_tx_free;	/* list of free transmit headers */
	struct	dma_hdr *is_rx_free;	/* list of free receive headers */
/* plan 727 (D024, D163) BEGIN: declarations and data */
	struct	ether_addr *is_multicast;	/* plan 727 (D024, D163) */
	int	is_nmulticast;		/* plan 727 (D024, D163) */
	u_char	is_txstat;		/* plan 727 (D024, D163) */
} en_softc[NEN];

/* plan 727 (D024, D163): standalone (gdb) packet buffers */
vm_offset_t dbgstack;
struct en_pkt {
	struct	ether_header ether;
	struct	ip ip;
	struct udphdr udp;
	char pad[536];
};
struct en_pkt *en_pkt[4];
struct {
	struct	ether_header ether;
	struct	ip ip;
	struct udphdr udp;
} en_pkt_hdr;

extern vm_offset_t enbuf_get(), kalloc();
extern void kfree();
extern const char IFCONTROL_RCVPROMISCUOUS[], IFCONTROL_RCVPROMISCOFF[];
void en_rx_devintr(), en_tx_devintr(), en_tx_guard();
/* plan 727 END */

#if GDB
const char IFCONTROL_SETIPADDRESS[] = "set-ipaddress";
#endif
/* plan 727 (D024, D163) BEGIN: en_getreg, en_putreg, en_regok */

/* plan 727 (D024, D163): byte access to the controller registers that may fault; copywithin returns 14 on a fault */
extern int copywithin();

static u_char en_getreg(addr)
	volatile char *addr;
{
	u_char c;
	int i = 0;

	int r;

	do {
		if (copywithin(addr, &c, 1) != 14) {
			r = c;
			goto out;
		}
	} while (i++ <= 15);
	r = 0;
out:
	return (r);
}

static void en_putreg(volatile char *addr, u_char val)
{
	u_char c = val;
	int i = 0;

	do {
		if (copywithin(&c, addr, 1) != 14)
			break;
	} while (i++ <= 15);
}

static int en_regok(addr)
	volatile char *addr;
{
	u_char c;
	int i;

	for (i = 0; i < 10; i++) {
		if (copywithin(addr, &c, 1) != 14)
			break;
		delay(1000);
	}
	if (i == 10)
		return (0);
	return (1);
}
/* plan 727 END */

enprobe (reg, ctrl)
	register caddr_t reg;
{
	reg += slot_id_bmap;
	return((int)reg);
}

/* plan 727 (D024, D163) BEGIN: en_accept_multicast, en_rx_devintr, en_rx_dmaintr, en_rx_grabbufs, enattach, eninit, enoutput, enstart */
enattach (bd)
	register struct bus_device *bd;
{
	register struct en_softc *is = &en_softc[bd->bd_unit];
	register struct dma_chan *tcp = &is->is_tx_dmachan;
	register struct dma_chan *rcp = &is->is_rx_dmachan;
	volatile register struct en_regs *regs =
		(struct en_regs*) bd->bd_addr;
	register struct dma_hdr *dhp;
	register int i;
	extern u_char etheraddr[];

	is->is_regs = regs;

	/* etheraddr is passed from the monitor */
	bcopy (etheraddr, &is->is_addr, sizeof (is->is_addr));
	bytecopy (etheraddr, regs->en_addr, sizeof (regs->en_addr));
	printf("en%d: Ethernet address %s\n", bd->bd_unit,
		ether_sprintf (&is->is_addr));
	regs->en_reset = EN_RESET_MODE;
	if (dma_chip != 313)
		regs->en_reset = 0;

	/* initialize transmitter DMA */
	bzero (tcp, sizeof *tcp);
	tcp->dc_handler = (dma_chip == 313) ? en_tx_dmaintr : 0;
	tcp->dc_hndlrarg = bd->bd_unit;
	tcp->dc_hndlrpri = CALLOUT_PRI_SOFTINT1;	/* splnet */
	tcp->dc_ddp = (struct dma_dev*) P_ENETX_CSR;
	tcp->dc_flags = (dma_chip == 313) ? (DMACHAN_AUTOSTART | DMACHAN_ENETX | DMACHAN_INTR) : (DMACHAN_AUTOSTART | DMACHAN_ENETX);
	tcp->dc_direction = DMACSR_WRITE;
	dma_init (tcp, I_ENETX_DMA);
	install_scanned_intr (I_ENETX, en_tx_devintr, bd->bd_unit);
	is->is_tx_free = 0;
	is->is_rx_free = 0;
	for (i = 0; i < NTXBUFS; i++) {
		dhp = end2dh(&is->is_tx_dhp[i]);
		dhp->dh_link = is->is_tx_free;
		is->is_tx_free = dhp;
	}

	/* initialize receiver DMA */
	bzero (rcp, sizeof *rcp);
	rcp->dc_handler = en_rx_dmaintr;
	rcp->dc_hndlrarg = bd->bd_unit;
	rcp->dc_hndlrpri = CALLOUT_PRI_SOFTINT1;	/* splnet */
	rcp->dc_ddp = (struct dma_dev*) P_ENETR_CSR;
	rcp->dc_flags = DMACHAN_AUTOSTART | DMACHAN_ENETR | DMACHAN_INTR |
		DMACHAN_CHAININTR;
	rcp->dc_direction = DMACSR_READ;
	dma_init (rcp, I_ENETR_DMA);
	if (dma_chip != 313)
		install_scanned_intr (I_ENETR, en_rx_devintr, bd->bd_unit);
	for (i = 0; i < NRXBUFS; i++) {
		dhp = end2dh(&is->is_rx_dhp[i]);
		if (!if_busalloc(dh2end(dhp), NULL)) {
			dhp->dh_link = is->is_rx_free;
			is->is_rx_free = dhp;
			continue;
		}
		dhp->dh_stop = (char*) roundup ((int)dhp->dh_start + BUF_SIZE,
			DMA_ENDALIGNMENT);
		dhp->dh_flags = DMADH_INITBUF;
		dma_enqueue (rcp, dhp);
	}
	is->is_nmulticast = 0;

	is->is_if = if_attach(eninit, NULL, enoutput, engetbuf, encontrol,
			      "en", bd->bd_unit, IFTYPE_ETHERNET, ETHERMTU,
			      0, NETIFCLASS_REAL, NULL);
}

/* initialization of interface */
int
eninit(
       netif_t netif
       )
{
	unsigned unit = if_unit(netif);
	register struct en_softc *is = &en_softc[unit];
	register struct bus_device *bd = eninfo[unit];
	volatile register struct en_regs *regs =
		(struct en_regs*) bd->bd_addr;
	register struct ifnet *ifp = (struct ifnet *)netif;

	if (is->is_flags & ENF_RUNNING)
		return;

	is->is_flags |= ENF_RUNNING;
	ifp->if_flags |= IFF_UP | IFF_RUNNING;

	/*
	 * Initialize controller.
	 * Receive  and transmit interrupts are driven by
	 * DMA completion.
	 */
	regs->en_reset = EN_RESET_MODE;
	if (dma_chip != 313)
		regs->en_reset = 0;

	/* set physical address if required */
	if (is->is_flags & ENF_SETADDR) {
		bytecopy (&is->is_addr, regs->en_addr, sizeof (regs->en_addr));
		is->is_flags &= ~ENF_SETADDR;
	}
	if (dma_chip != 313) {
		regs->en_txmode = 4;
		DELAY(500000);
	} else
		regs->en_txmode = 0;
	regs->en_txstat = EN_TXSTAT_CLEAR;
	regs->en_txmask = (dma_chip != 313) ? 0x8e : 4;	/* 0x8e: EN_TXMASK_READYIE|EN_TXMASK_UNDERFLOWIE|EN_TXMASK_COLLIE|EN_TXMASK_COLL16IE; 4: EN_TXMASK_COLLIE */
	en_putreg(&regs->en_rxstat, EN_RXSTAT_CLEAR);
	en_putreg(&regs->en_rxmask, (dma_chip == 313) ? 0 : 0x41);	/* 0x41: EN_RXMASK_OVERFLOWIE + 0x40 (no name) */
	en_putreg(&regs->en_rxmode, (dma_chip == 313) ? 0 : 0x80);	/* 0x80: EN_RXMODE_TEST */
	if (dma_chip == 313)
		regs->en_reset = 0;
	if (dma_chip == 313)
		regs->en_txmode = EN_TXMODE_LB_DISABLE;
	if (dma_chip == 313)
		regs->en_rxmode = EN_RXMODE_NORMAL;
	else
		en_putreg(&regs->en_rxmode, 0xa2);	/* 0xa2: EN_RXMODE_TEST|EN_RXMODE_MULTICAST + 0x20 (no name) */
}

en_rx_grabbufs(is)
	struct en_softc *is;
{
	register struct dma_chan *rcp = &is->is_rx_dmachan;
	int s;
	struct dma_hdr *dhp;

	/*
	 * Queue up any receive buffers waiting for memory, if possible.
	 */
	
	s = splimp();
	while (dhp = is->is_rx_free) {
		is->is_rx_free = dhp->dh_link;
		splx(s);
		if (!if_busalloc(dh2end(dhp), NULL)) {
			splimp();
			dhp->dh_link = is->is_rx_free;
			is->is_rx_free = dhp;
			splx(s);
			timeout(en_rx_grabbufs, is, hz);
			return;
		}
		dhp->dh_stop = (char*) roundup ((int)dhp->dh_start + BUF_SIZE,
			DMA_ENDALIGNMENT);
		dhp->dh_flags = DMADH_INITBUF;
		dma_enqueue (rcp, dhp);
		s = splimp();
	}
	splx(s);
}

int
en_accept_multicast(is, addr)
	struct en_softc *is;
	u_char *addr;
{
	struct ifnet *ifp = (struct ifnet *)is->is_if;
	register int i, found;

	if (ifp->if_flags & IFF_PROMISC)
		return (1);
	if (*(long *)addr == -1 && *(short *)(addr + 4) == -1)
		return (1);
	i = 0;
	found = 0;
	for (; i < is->is_nmulticast; i++) {
		if (*(long *)addr == *(long *)&is->is_multicast[i] &&
		    ((short *)addr)[2] == ((short *)&is->is_multicast[i])[2]) {
			found = 1;
			break;
		}
	}
	return (found);
}

void
en_rx_devintr(unit)
	int unit;
{
	register struct en_softc *is = &en_softc[unit];
	volatile register struct en_regs *regs = is->is_regs;
	register u_char rxstat;

	rxstat = en_getreg(&regs->en_rxstat);
	en_putreg(&regs->en_rxstat, EN_RXSTAT_CLEAR);
	if (rxstat & 0x40)	/* 0x40: no name in if_enreg.h */
		if_collisions_set(is->is_if, if_collisions(is->is_if) + 1);
	if (rxstat & 0x01)	/* 0x01: EN_RXSTAT_OVERFLOW */
		en_putreg(&regs->en_rxmode, en_getreg(&regs->en_rxmode) | 0x80);	/* 0x80: EN_RXMODE_TEST */
}

void
en_rx_dmaintr (unit)
	int unit;
{
	register struct en_softc *is = &en_softc[unit];
	register struct dma_chan *rcp = &is->is_rx_dmachan;
	register struct dma_hdr *dhp;
	netbuf_t nb;
	int len, off, resid, s;
	register struct ifqueue *inq;
	register char *bp;
	struct ether_header *eh;
	struct ifnet *ifp = (struct ifnet *)is->is_if;
	volatile struct en_regs *regs = is->is_regs;
	int npackets = 0;
	u_char *myaddr = (u_char *)&is->is_addr;
	int cand;
	u_int crc, i;

dbug1 ("\nrxint: ");
	while ((dhp = dma_dequeue (rcp, DMADQ_DONE)) != NULL) {
dbug1 ("dhp 0x%x ", dhp);

	if (rcp->dc_flags & DMACHAN_ERROR) {
		printf ("en%d: DMA error on receive\n", unit);
		rcp->dc_flags &= ~DMACHAN_ERROR;
	}
	bp = (char *)dhp->dh_start;
	/*
	 * Determine packet length from dh_next.
	 * Strip BOP & EOP bits first.
	 */
	len = ((int) dhp->dh_next & ~(ENRX_EOP|ENRX_BOP)) -
		(int) bp - HDR_SIZE - FCS_SIZE;
	if (len < ETHERMIN || len > ETHERMTU + 1) {
dbug1 ("enrx: packet length %d bad, dh_next 0x%x bp 0x%x\n", len, dhp->dh_next, bp);
		if_ierrors_set(is->is_if, if_ierrors(is->is_if) + 1);
		goto resetup;
	}
	if (dma_chip == 0 && (ifp->if_flags & IFF_PROMISC) == 0) {
		if (bcmp(bp + 1, myaddr, 6) == 0 ||
		    bcmp(bp + 1, etherbcastaddr, 6) == 0) {
			len--;
			bp++;
		} else {
			cand = 0;
			if (is->is_nmulticast != 0 &&
			    bcmp(bp, myaddr, 6) != 0 &&
			    bcmp(bp, etherbcastaddr, 6) != 0)
				cand = 1;
			if (cand && (bp[0] & 1) == (bp[1] & 1) &&
			    (bp[6] & 1) == (bp[7] & 1)) {
				crc = ~0;
				for (i = 0; i < len + HDR_SIZE + FCS_SIZE; i++)
					crc = (crc >> 8) ^ crctab[(crc ^ (u_char)bp[i]) & 0xff];
				if (crc != 0xdebb20e3) {
					len--;
					bp++;
				}
			} else if (cand && ((bp[0] & 1) < (bp[1] & 1) ||
				   (bp[6] & 1) > (bp[7] & 1))) {
				len--;
				bp++;
			}
		}
	}
	if ((bp[0] & 1) && !en_accept_multicast(is, (u_char *)bp))
		goto resetup;
	if (*(short *)(bp + 34) == 1139 && bp[23] == IPPROTO_UDP &&
	    *(short *)(bp + 12) == ETHERTYPE_IP)
		dbg_from_ether((u_char *)bp);
	npackets++;
	nb = if_rbusget (dh2end(dhp), (caddr_t)bp, HDR_SIZE + len);
	if (nb == 0) {
		printf ("enrx: no network buffers\n");
		goto resetup;
	} else {
		if_handle_input(is->is_if, nb, NULL);
	}
		    
setup:
	if (!if_busalloc(dh2end(dhp), NULL)) {
		s = splimp();
		dhp->dh_link = is->is_rx_free;
		is->is_rx_free = dhp;
		splx(s);
		timeout(en_rx_grabbufs, is, hz);
	} else {
resetup:
		dhp->dh_stop = (char*) roundup ((int)dhp->dh_start + BUF_SIZE,
			DMA_ENDALIGNMENT);
		dhp->dh_flags = DMADH_INITBUF;
		dma_enqueue (rcp, dhp);	/* queue up buffer on rx chain */
	}
	}	/* while */
	s = splimp();
	if (npackets) {
		if_ipackets_set(is->is_if, if_ipackets(is->is_if) + npackets);
		is->is_flags &= ~ENF_JAM_MSG;
		is->is_last_rx = time;
		is->is_rxstate = 0;
		if (is->is_flags & ENF_RXMODE) {
			if ((ifp->if_flags & IFF_PROMISC) == 0) {
				if (dma_chip != 313)
					en_putreg(&regs->en_rxmode, 0xa2);	/* 0xa2: EN_RXMODE_TEST|EN_RXMODE_MULTICAST + 0x20 (no name) */
				else if (ifp->if_flags & IFF_ALLMULTI)
					regs->en_rxmode = EN_RXMODE_MULTICAST;
				else
					regs->en_rxmode = EN_RXMODE_NORMAL;
			}
			is->is_flags &= ~ENF_RXMODE;
		}
	}
	splx(s);
dbug1 ("enrx: done ");
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
enoutput(
	 netif_t netif,
	 netbuf_t nb,
	 void *dst
	 )
{
	int type, s, error;
 	u_char edst[6];
	struct ifnet *ifp = (struct ifnet *)netif; /* XXX */
	struct mbuf *m = (struct mbuf *)nb; /* XXX */ 
	register struct en_softc *is = &en_softc[ifp->if_unit];
	volatile struct en_regs *regs = is->is_regs;
	register struct ether_header *outeh;
	register int off;
	int usetrailers;
	netbuf_t m2;


	if (!(is->is_flags & ENF_RUNNING) || (is->is_flags & ENF_JAMMED)) {
		error = ENETDOWN;
		goto bad;
	}

	outeh = mtod(m, struct ether_header *);
 	bcopy(dst, (caddr_t)outeh->ether_dhost, sizeof (outeh->ether_dhost));
 	bcopy((caddr_t)&is->is_addr, (caddr_t)outeh->ether_shost,
	      sizeof(outeh->ether_shost));
	if (*(u_char *)dst & 1) {
		if ((bmap_chip && (bmap_chip->bm_drw & BMAP_TPE_RXSEL)) ||
		    (dma_chip != 313 && (regs->en_txmode & 4))) {	/* 0x04: no name in if_enreg.h */
			if (en_accept_multicast(is, dst) == 1) {
				m2 = (netbuf_t) m_copy(m, 0, M_COPYALL);
				if (m2)
					if_handle_input(is->is_if, m2, NULL);
			}
		}
	}

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		splx(s);
		m_freem(m);
		/* printf ("entx: q full\n"); */
		return (ENOBUFS);
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	if ((is->is_flags & ENF_OACTIVE) == 0)
		enstart(ifp->if_unit);
	splx(s);
	return (0);

bad:
	nb_free(nb);
	return (error);
}


/*
 * Start output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
 */
enstart(unit)
	int unit;
{
	int len;
	register struct en_softc *is = &en_softc[unit];
	register struct dma_chan *tcp = &is->is_tx_dmachan;
	netbuf_t nb;
	struct mbuf *m;
	register struct dma_hdr *dhp;
	int s;
	volatile struct en_regs *regs = is->is_regs;
	struct ifnet *ifp = (struct ifnet *)is->is_if; /* XXX */

	s = splimp();
	IF_DEQUEUE(&ifp->if_snd, m);
	splx(s);
	if (m == 0)
		return;
	nb = (netbuf_t)m; /* XXX */
	s = splimp();
	if ((dhp = is->is_tx_free) == 0) {
		splx (s);
		printf ("entx: no dma headers\n");
		nb_free(nb);
		return;
	}
	is->is_tx_free = dhp->dh_link;
	splx (s);
	len = nb_size(nb);
	if_busalloc(dh2end(dhp), nb);
	if (len - sizeof(struct ether_header) < ETHERMIN)
		len = ETHERMIN + sizeof(struct ether_header);
	dhp->dh_stop = (char*) ((int) dhp->dh_start + len);
	if (dma_chip == 313) {
		dhp->dh_stop = (char*) ((int) dhp->dh_stop | ENTX_EOP);
		dhp->dh_stop += 15;
	}

	dhp->dh_flags = DMADH_INITBUF | DMADH_LONGALIGN;

	/*
	 *  When the network is disconnected, sometimes carrier detect
	 *  remains continuously busy which prevents any packet from
	 *  being transmitted and the 16-collisions-in-a-row error from
	 *  hapenning (which is normally used to detect network disconnects).
	 *  So a guard timer is maintained to catch this possiblity.
	 */
	s = splimp();
	timeout (en_tx_guard, is, EN_TX_TIMEOUT);
	is->is_flags |= ENF_OACTIVE;
	dma_enqueue (tcp, dhp);
	if (dma_chip != 313)
		regs->en_txmode |= 0x80;	/* 0x80: no name in if_enreg.h */
	splx(s);
}
/* plan 727 END */

en_down (unit)
{
	register struct en_softc *is = &en_softc[unit];
	register s;

	s = splimp();
	if_down (is->is_if);
	splx(s);
}

/* plan 727 (D024, D163) BEGIN: en_antijam */
en_antijam (is)
	register struct en_softc *is;
{
	register int s;
	register int flags;

	s = splimp();
	flags = is->is_flags;
	if ((flags & ENF_JAMMED) == 0) {
		splx(s);
		return;
	}
	is->is_flags = flags & ~ENF_JAMMED;
	if ((flags & ENF_OACTIVE) == 0)
		enstart (is - en_softc);
	splx(s);
}
/* plan 727 END */

/* 150 mS max between TPE heartbeats */
#define	EN_TPE_TIMEOUT	150000

/* plan 727 (D024, D163) BEGIN: en_bufalloc, en_jam, en_setaddr, en_tx_devintr, en_tx_dmaintr, en_tx_guard, encontrol, enintsetup */
en_jam (is)
	register struct en_softc *is;
{
	volatile register struct en_regs *en = is->is_regs;
	register int s, i;

	s = splimp();
	is->is_jam_count = 0;
	splx(s);
	
	if (bmap_chip) {
		/* if connected to thin, switch to TPE if heartbeat heard */
		if (!(bmap_chip->bm_drw & BMAP_TPE_RXSEL)) {
			for (i = event_get(); event_delta(i) < EN_TPE_TIMEOUT;)
				if ((bmap_chip->bm_drw & BMAP_HEARTBEAT) == 0)
					break;
			if (event_delta(i) < EN_TPE_TIMEOUT) {
				s = splimp();
				bmap_chip->bm_drw |= BMAP_TPE;
				en->en_txmode &= ~EN_TXMODE_LB_DISABLE;
				splx(s);
				return (0);
			}
		} else {
			for (i = event_get(); event_delta(i) < EN_TPE_TIMEOUT;)
				if ((bmap_chip->bm_drw & BMAP_HEARTBEAT) == 0)
					break;
			if (event_delta(i) >= EN_TPE_TIMEOUT) {
				s = splimp();
				bmap_chip->bm_drw &= ~BMAP_TPE;
				en->en_txmode |= EN_TXMODE_LB_DISABLE;
				splx(s);
				return (1);
			}
			return (0);
		}
	}
	if (dma_chip != 313) {
		s = splimp();
		en->en_txmode |= 4;
		splx(s);
		DELAY(500000);
		if (en->en_reset & 0x40)	/* 0x40: no name in if_enreg.h */
			goto linkup;
	again:
		if (++is->is_tpe_count > 5)
			goto disabled;
		return (0);
	linkup:
		s = splimp();
		en->en_txmode &= ~4;
		splx(s);
		DELAY(500000);
		if (!en_regok(&en->en_rxstat)) {
			s = splimp();
			en->en_txmode |= 4;
			splx(s);
			DELAY(500000);
			goto again;
		}
		if (++is->is_tpe_count > 3)
			goto disabled;
		return (1);
	}
disabled:
	s = splimp();
	if ((is->is_flags & ENF_JAM_MSG) == 0) {
		printf ("The network is disabled or your computer "
			"isn't connected to it.\n");
		is->is_flags |= ENF_JAM_MSG;
	}
	is->is_flags |= ENF_JAMMED;
	en_down (is - en_softc);
	timeout (en_antijam, is, EN_ANTIJAM);
	splx(s);
	return (2);
}

void
en_tx_guard(is)
	struct en_softc *is;
{
	volatile struct en_regs *regs = is->is_regs;
	int s;

	(void) ((volatile struct dma_dev *) P_ENETX_CSR)->dd_csr;
	(void) regs->en_txstat;
	s = splimp();
	is->is_flags |= ENF_TXGUARD;
	splx(s);
	callout_dispatch (CALLOUT_PRI_SOFTINT1, en_tx_dmaintr, is - en_softc);
}

void
en_tx_devintr(unit)
	int unit;
{
	register struct en_softc *is = &en_softc[unit];
	volatile struct en_regs *regs = is->is_regs;

	if (regs->en_txstat & EN_TXSTAT_COLLERR)
		if_collisions_set(is->is_if, if_collisions(is->is_if) + 1);
	if (dma_chip == 313)
		regs->en_txstat |= EN_TXSTAT_COLLERR;
	else {
		(void) regs->en_txstat;
		is->is_txstat = regs->en_txstat;
		regs->en_txstat = EN_TXSTAT_CLEAR;
		callout_dispatch (CALLOUT_PRI_SOFTINT1, en_tx_dmaintr, unit);
	}
}

/* plan 727 (D163): en_tx_dmaintr from the original bytes 0x408ed0a-0x408f15a as file-scope asm */
asm("
	.text
.cstring
LENC7:
	.ascii \"en%d: spurious xmit interrupt, status 0x%x\\12\\0\"
LENC8:
	.ascii \"en%d: transmitter not ready\\12\\0\"
LENC9:
	.ascii \"en%d: DMA error on transmit\\12\\0\"
.text
	.align 1
.globl _en_tx_dmaintr
_en_tx_dmaintr:
	link a6,#-4
	moveml #0x3f3c,sp@-
	movel a6@(8),d5
	movel d5,d0
	mulsl #1324,d0
	movel d0,a3
	addl #_en_softc,a3
	lea a3@(14),a5
	movel a3@(510),a4
	movel a3@,a6@(-4)
	movel a3,sp@-
	pea _en_jam
	lea _untimeout,a2
	jbsr a2@
	movel a3,sp@-
	pea _en_tx_guard
	jbsr a2@
	addqw #8,sp
	addqw #8,sp
	btst #1,a3@(517)
	jne LEN213
	cmpw #313,_dma_chip
	jne LEN214
	moveb a4@,d0
	extbl d0
	jra LEN215
LEN214:
	clrl d0
	moveb a3@(1322),d0
LEN215:
	movel d0,sp@-
	movel d5,sp@-
	pea LENC7
	jbsr _printf
	jra LEN212
LEN213:
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	cmpw #313,_dma_chip
	jeq LEN216
	moveb a4@(4),d0
	andb #127,d0
	moveb d0,a4@(4)
LEN216:
#APP
	movw	sr,d0
#NO_APP
	movew a2,d6
#APP
	movw	d6,sr
#NO_APP
	btst #6,a3@(517)
	jeq LEN217
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	moveq #-65,d7
	andl d7,a3@(514)
#APP
	movw	sr,d0
#NO_APP
	movew a2,d6
#APP
	movw	d6,sr
#NO_APP
	clrl d3
	movel a5,sp@-
	jbsr _dma_abort
	moveq #1,d2
	addqw #4,sp
	jra LEN218
LEN217:
	cmpw #313,_dma_chip
	jne LEN219
	subl a0,a0
	moveb a4@,d0
	eorw #128,d0
	tstb d0
	jge LEN221
LEN223:
	addqw #1,a0
	cmpl #99999,a0
	sle d1
	extbl d1
	moveb a4@,d0
	eorw #128,d0
	bfextu d0{#24:#1},d0
	andl d1,d0
	jne LEN223
LEN221:
	cmpl #100000,a0
	jne LEN225
	movel d5,sp@-
	pea LENC8
	jbsr _printf
	addqw #8,sp
LEN225:
	moveb a4@,d0
	moveb d0,d3
	extbl d3
	st a4@
	jra LEN226
LEN219:
	clrl d3
	moveb a3@(1322),d3
	movel a5,sp@-
	jbsr _dma_abort
	addqw #4,sp
LEN226:
	clrl d2
LEN218:
	clrl sp@-
	movel a5,sp@-
	jbsr _dma_dequeue
	movel d0,d4
	addqw #8,sp
	jeq LEN266
	tstl d2
	jeq LEN228
	cmpw #313,_dma_chip
	jeq LEN229
	pea a4@(2)
	jbsr _en_regok
	addqw #4,sp
	tstl d0
	jne LEN229
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	moveb a4@(4),d0
	orb #4,d0
	moveb d0,a4@(4)
#APP
	movw	sr,d0
#NO_APP
	movew a2,d7
#APP
	movw	d7,sr
#NO_APP
	movel #500000,sp@-
	jbsr _delay
	addqw #4,sp
	jra LEN230
LEN229:
	movel a3@(518),d0
	addql #1,a3@(518)
	moveq #3,d6
	cmpl d0,d6
	jge LEN230
	jra LEN232
LEN228:
	movel _time,d2
	subl a3@(526),d2
	moveq #2,d6
	cmpl d2,d6
	slt d0
	moveb d0,d2
	extbl d2
	negl d2
	jeq LEN233
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	movel _time,d6
	movel _time+4,d7
	movel d6,a3@(526)
	movel d7,a3@(530)
	movel a3@(534),d0
	moveq #1,d7
	cmpl d0,d7
	jeq LEN236
	jhi LEN235
	moveq #2,d6
	cmpl d0,d6
	jeq LEN239
	jra LEN234
LEN235:
	moveq #1,d7
	jra LEN271
LEN236:
	cmpw #313,_dma_chip
	jeq LEN237
	pea 161:w
	pea a4@(5)
	jbsr _en_putreg
	addqw #8,sp
	jra LEN238
LEN237:
	moveb #3,a4@(5)
LEN238:
	moveq #32,d6
	orl d6,a3@(514)
	moveq #2,d7
LEN271:
	movel d7,a3@(534)
	clrl d2
	jra LEN234
LEN239:
	btst #5,a3@(517)
	jeq LEN240
	movel a6@(-4),a1
	movew a1@(12),d0
	btst #8,d0
	jne LEN241
	cmpw #313,_dma_chip
	jeq LEN242
	pea 162:w
	pea a4@(5)
	jbsr _en_putreg
	addqw #8,sp
	jra LEN241
LEN242:
	btst #9,d0
	jeq LEN244
	moveb #2,a4@(5)
	jra LEN241
LEN244:
	moveb #1,a4@(5)
LEN241:
	moveq #-33,d6
	andl d6,a3@(514)
LEN240:
	clrl a3@(534)
LEN234:
#APP
	movw	sr,d0
#NO_APP
	movew a2,d7
#APP
	movw	d7,sr
#NO_APP
LEN233:
	clrl d1
	movel _bmap_chip,a0
	tstl a0
	jeq LEN250
	movel a0@(52),d0
	jlt LEN249
LEN250:
	cmpw #313,_dma_chip
	jeq LEN248
	moveb a4@(4),d0
	btst #2,d0
	jeq LEN248
LEN249:
	moveq #1,d1
LEN248:
	tstl d1
	jne LEN251
	btst #1,d3
	jne LEN252
	tstl d2
	jeq LEN251
LEN252:
	movel a3@,sp@-
	jbsr _if_oerrors
	addql #1,d0
	movel d0,sp@-
	movel a3@,sp@-
	jbsr _if_oerrors_set
	addqw #8,sp
	addqw #4,sp
	movel a3@(518),d0
	addql #1,a3@(518)
	moveq #10,d6
	cmpl d0,d6
	jge LEN255
	btst #3,a3@(517)
	jeq LEN254
LEN255:
	tstl d2
	jeq LEN230
LEN254:
	tstl d2
	jeq LEN256
	moveq #4,d7
	movel d7,a3@(522)
LEN256:
	movel a3,sp@-
	jbsr _en_jam
	addqw #4,sp
	moveq #2,d6
	cmpl d0,d6
	jeq LEN258
	jra LEN230
LEN251:
	movel _bmap_chip,a0
	tstl a0
	jeq LEN261
	movel a0@(52),d0
	jge LEN261
	tstl d2
	jne LEN232
LEN261:
	cmpw #313,_dma_chip
	jeq LEN263
	moveb a4@(4),d0
	btst #2,d0
	jeq LEN259
	moveb a4@(6),d0
	btst #6,d0
	jeq LEN259
LEN232:
	movel a3,sp@-
	jbsr _en_jam
	addqw #4,sp
	moveq #2,d7
	cmpl d0,d7
	jeq LEN258
	jra LEN230
LEN259:
	cmpw #313,_dma_chip
	jeq LEN263
	moveq #12,d0
	andl d3,d0
	jne LEN230
LEN263:
	movel a5@(44),d0
	btst #14,d0
	jeq LEN265
	movel d5,sp@-
	pea LENC9
	jbsr _printf
	movel a5@(44),d0
	andw #49151,d0
	movel d0,a5@(44)
	addqw #8,sp
	jra LEN230
LEN265:
	movel a3@,sp@-
	jbsr _if_opackets
	addql #1,d0
	movel d0,sp@-
	movel a3@,sp@-
	jbsr _if_opackets_set
	addqw #8,sp
	addqw #4,sp
LEN258:
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	clrl a3@(518)
	clrl a3@(522)
	movel d4,sp@-
	jbsr _if_busfree
	movel d4,a1
	movel a3@(1306),a1@
	movel d4,a3@(1306)
	addqw #4,sp
#APP
	movw	sr,d0
#NO_APP
	movew a2,d6
#APP
	movw	d6,sr
#NO_APP
LEN266:
	clrl sp@-
	movel a5,sp@-
	jbsr _dma_dequeue
	addqw #8,sp
	tstl d0
	jne LEN266
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	movel a3@(514),d0
	moveq #-3,d7
	andl d0,d7
	movel d7,a3@(514)
	btst #3,d0
	jne LEN269
	movel d5,sp@-
	jbsr _enstart
LEN269:
#APP
	movw	sr,d0
#NO_APP
	movew a2,d6
#APP
	movw	d6,sr
#NO_APP
	jra LEN212
LEN230:
#APP
	movw	sr,d0
	movw	#8960,sr
#NO_APP
	movew d0,a2
	movel _hz,sp@-
	movel a3,sp@-
	pea _en_tx_guard
	jbsr _timeout
	moveq #5,d7
	movel d4,a1
	movel d7,a1@(12)
	movel d4,sp@-
	movel a5,sp@-
	jbsr _dma_enqueue
	cmpw #313,_dma_chip
	jeq LEN270
	moveb a4@(4),d0
	orb #-128,d0
	moveb d0,a4@(4)
LEN270:
#APP
	movw	sr,d0
#NO_APP
	movew a2,d6
#APP
	movw	d6,sr
#NO_APP
LEN212:
	moveml a6@(-44),#0x3cfc
	unlk a6
	rts
	.text
");

/*
 * Process an ioctl request.
 */
int
encontrol(
	  netif_t netif,
	  const char *command,
	  void *data
	  )
{
	struct ifnet *ifp = (struct ifnet *)netif; /* XXX */
	struct en_softc *is = &en_softc[ifp->if_unit];
	volatile struct en_regs *regs =
		(struct en_regs *) eninfo[if_unit(netif)]->bd_addr;
	int s;
	int error = 0;
	int i, n, found, size;
	struct ether_addr *p;

	s = splimp();
	if (strcmp(command, IFCONTROL_SETFLAGS) == 0) {
		if ((*(short *)data & IFF_UP) && !(is->is_flags & ENF_RUNNING))
			eninit(netif);
	} else if (strcmp(command, IFCONTROL_GETADDR) == 0) {
		bcopy(&is->is_addr, data, sizeof(is->is_addr));
#if GDB
	} else if (strcmp(command, IFCONTROL_SETIPADDRESS) == 0) {
		bcopy(data, &is->is_ac_ipaddr, sizeof(struct in_addr));
#endif
	} else if (strcmp(command, IFCONTROL_ADDMULTICAST) == 0) {
		if (is->is_nmulticast % 5 == 0) {
			size = (is->is_nmulticast + 5) * 6;
			p = (struct ether_addr *) kalloc(size);
			if (is->is_multicast == 0) {
				is->is_multicast = p;
				if ((ifp->if_flags & IFF_PROMISC) == 0 && dma_chip == 313)
					regs->en_rxmode = EN_RXMODE_MULTICAST;
				ifp->if_flags |= IFF_ALLMULTI;
			} else {
				size = is->is_nmulticast * 6;
				bytecopy(is->is_multicast, p, size);
				kfree(is->is_multicast, size);
				is->is_multicast = p;
			}
		}
		found = 0;
		for (i = 0; i < is->is_nmulticast; i++) {
			if (*(long *)&is->is_multicast[i] == *(long *)data &&
			    ((short *)data)[2] == ((short *)&is->is_multicast[i])[2]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			bytecopy(data, &is->is_multicast[i], 6);
			is->is_nmulticast++;
		}
	} else if (strcmp(command, IFCONTROL_RCVPROMISCUOUS) == 0) {
		if (dma_chip == 313)
			regs->en_rxmode = EN_RXMODE_PROMISCUOUS;
		else
			en_putreg(&regs->en_rxmode, 0xa1);	/* 0xa1: EN_RXMODE_TEST|EN_RXMODE_NORMAL + 0x20 (no name) */
		ifp->if_flags |= IFF_PROMISC;
	} else if (strcmp(command, IFCONTROL_RMVMULTICAST) == 0 &&
		   is->is_multicast != 0) {
		{
			i = 0;
			if (data == NULL) {
				size = ((is->is_nmulticast + 4) / 5) * 30;
				kfree(is->is_multicast, size);
				is->is_multicast = 0;
				is->is_nmulticast = 0;
			} else {
				for (; i < is->is_nmulticast; i++) {
					if (*(long *)data == *(long *)&is->is_multicast[i] &&
					    ((short *)data)[2] == ((short *)&is->is_multicast[i])[2]) {
						do {
							bytecopy(&is->is_multicast[i + 1], &is->is_multicast[i], 6);
							i++;
						} while (i < is->is_nmulticast);
						is->is_nmulticast--;
						break;
					}
				}
				n = is->is_nmulticast;
				if (n == 0) {
					kfree(is->is_multicast, 30);
					is->is_multicast = 0;
					if ((ifp->if_flags & IFF_PROMISC) == 0 && dma_chip == 313)
						regs->en_rxmode = EN_RXMODE_NORMAL;
					ifp->if_flags &= ~IFF_ALLMULTI;
				} else if (n % 5 == 0) {
					size = n * 6;
					p = (struct ether_addr *) kalloc(size);
					bytecopy(is->is_multicast, p, size);
					kfree(is->is_multicast, size + 30);
					is->is_multicast = p;
				}
			}
		}
	} else if (strcmp(command, IFCONTROL_RCVPROMISCOFF) == 0) {
		if (dma_chip == 313) {
			if (ifp->if_flags & IFF_ALLMULTI)
				regs->en_rxmode = EN_RXMODE_MULTICAST;
			else
				regs->en_rxmode = EN_RXMODE_NORMAL;
		} else
			en_putreg(&regs->en_rxmode, 0xa2);	/* 0xa2: EN_RXMODE_TEST|EN_RXMODE_MULTICAST + 0x20 (no name) */
		ifp->if_flags &= ~IFF_PROMISC;
	} else {
		error = EINVAL;
	}
	splx(s);
	return (error);
}

/*
 * set ethernet address for unit
 */
en_setaddr(physaddr, unit)
u_char *physaddr;
int unit;
{
	register struct en_softc *is = &en_softc[unit];
	struct ifnet *ifp = (struct ifnet *)is->is_if;
	register int s;
	
	s = splimp();
	bcopy((caddr_t)physaddr, (caddr_t)&is->is_addr, sizeof is->is_addr);
	is->is_flags |= ENF_SETADDR;
	if (!(is->is_flags & ENF_RUNNING)) {
		splx(s);
		return;
	}
	is->is_flags &= ~ENF_RUNNING;
	ifp->if_flags &= ~(IFF_UP | IFF_RUNNING);
	eninit(is->is_if);
	splx(s);
}

enintsetup()
{
	volatile struct en_regs *regs = (struct en_regs*) P_ENET;

	if (dma_chip != 313) {
		regs->en_txmode = 4;
		DELAY(500000);
		regs->en_txmask = 0;
		en_putreg(&regs->en_rxmask, 0);
	}
}

en_bufalloc(first)
	int first;
{
	static int done;
	register int i;
	register char *p;
	vm_offset_t q;

	if (!done) {
		if (first == 1) {
			dbgstack = enbuf_get();
			for (i = 0; i < 4; i++) {
				if ((en_pkt[i] = (struct en_pkt *) enbuf_get()) == 0)
					panic("no gdb enet buffers");
				en_pkt[i] = (struct en_pkt *) pmap_resident_extract(pmap_kernel(), (vm_offset_t) en_pkt[i]);
			}
		} else {
			p = (char *) mem_region[0].first_phys_addr;
			dbgstack = (vm_offset_t) p;
			q = (vm_offset_t) p;
			q += 1024;
			p = (char *) roundup(q, m68k_page_size);
			for (i = 0; i < 4; i++) {
				p = (char *) roundup((int)p, DMA_ENDALIGNMENT);
				en_pkt[i] = (struct en_pkt *) p;
				p += BUF_SIZE;
			}
			mem_region[0].first_phys_addr = (vm_offset_t) p;
		}
		if (dbgstack == 0)
			panic("no gdb stack buffer");
		_m68k_dbginit();
		done = 1;
	}
}
/* plan 727 (D024): NeXTMach line 816 removed (not in the 1997 kernel) */
/* plan 727 END */

/* standalone routines for debugger interface */
#if	GDB

/* plan 727 (D024, D163) BEGIN: en_recv */
/* plan 727 (D163): en_recv from the original bytes 0x408f6ba-0x408fa10 as file-scope asm */
asm("
	.text
	.align 1
.globl _en_recv
_en_recv:
	pea a6@
	movel sp,a6
	moveml #0x3c3c,sp@-
	movel a6@(20),d0
	movel _slot_id,a0
	movel #33554768,a5
	addl a0,a5
	movel a0,d4
	addl #33554704,d4
	movel _slot_id_bmap,a3
	addl #33579008,a3
	clrl d3
	tstl d0
	jeq LEN344
	movel d0,_en_softc+10
LEN344:
	btst #0,_en_softc+517
	jne LEN345
	tstl _rx_init
	jne LEN345
	pea 6:w
	pea _en_softc+4
	pea _etheraddr
	jbsr _bcopy
	pea 6:w
	pea a3@(8)
	pea _etheraddr
	jbsr _bytecopy
	moveb #-128,a3@(6)
	addw #24,sp
	cmpw #313,_dma_chip
	jeq LEN346
	clrb a3@(6)
LEN346:
	clrb a3@(1)
	pea 255:w
	pea a3@(2)
	lea _en_putreg,a4
	jbsr a4@
	clrl sp@-
	pea a3@(3)
	jbsr a4@
	addqw #8,sp
	addqw #8,sp
	clrl d0
	cmpw #313,_dma_chip
	jeq LEN347
	moveq #127,d0
	notb d0
LEN347:
	movel d0,sp@-
	lea a3@(5),a2
	movel a2,sp@-
	jbsr a4@
	addqw #8,sp
	cmpw #313,_dma_chip
	jne LEN349
	clrb a3@(6)
LEN349:
	cmpw #313,_dma_chip
	jne LEN350
	moveb a3@(4),d0
	orb #2,d0
	moveb d0,a3@(4)
	moveb #1,a2@
	jra LEN351
LEN350:
	pea 162:w
	movel a2,sp@-
	jbsr a4@
	addqw #8,sp
LEN351:
	moveq #1,d5
	movel d5,_rx_init
LEN345:
	tstl _rx_cached
	jne LEN352
	movel #262144,sp@-
	movel _en_pkt+4,a0
	pea a0@(578)
	movel a0,sp@-
	jbsr _cache_flush
	clrl _epi
	moveq #1,d5
	movel d5,_rx_cached
	addqw #8,sp
	addqw #4,sp
LEN352:
	cmpw #313,_dma_chip
	jeq LEN353
	lea a3@(2),a2
	movel a2,sp@-
	jbsr _en_regok
	addqw #4,sp
	tstl d0
	jeq LEN353
	movel a2,sp@-
	lea _en_getreg,a4
	jbsr a4@
	addqw #4,sp
	btst #0,d0
	jeq LEN353
	pea 255:w
	movel a2,sp@-
	lea _en_putreg,a2
	jbsr a2@
	movel a3,d2
	addql #5,d2
	movel d2,sp@-
	jbsr a4@
	orb #128,d0
	clrl sp@-
	moveb d0,sp@(3)
	movel d2,sp@-
	jbsr a2@
	addw #20,sp
LEN353:
	tstl _rx_active
	jeq LEN356
	movew _dma_chip,d1
LEN357:
	movel a5@,d0
	cmpw #313,d1
	jne LEN358
	tstl d0
	jeq LEN357
LEN358:
	btst #24,d0
	jeq LEN362
	clrl d0
	jra LEN379
LEN362:
	movel _epi,d0
	lea _en_pkt,a2
	movel a2@(d0:l:4),a0
	clrl d0
	movew a0@(12),d0
	cmpl #2048,d0
	jeq LEN364
	cmpl #2054,d0
	jeq LEN373
	jra LEN356
LEN364:
	cmpb #17,a0@(23)
	jne LEN356
	clrl d0
	movew a0@(34),d0
	movel a6@(8),a1
	movel d0,a1@
	cmpw #313,_dma_chip
	jne LEN366
	movel a5@(16384),d0
	andl #1073741823,d0
	jra LEN380
LEN366:
	movel _slot_id_bmap,a1
	movel #33579008,a0
	moveb a0@(7,a1:l),d1
	moveq #-16,d5
	orl d5,d1
	movel a5@(16384),d0
	addl d1,d0
LEN380:
	movel _epi,d1
	subl a2@(d1:l:4),d0
	movel d0,d2
	subql #4,d2
	movel _epi,d0
	lea _en_pkt,a0
	movel a0@(d0:l:4),a3
	tstw _dma_chip
	jne LEN368
	pea 6:w
	moveq #4,d5
	addl #_en_softc,d5
	movel d5,sp@-
	lea a3@(1),a2
	movel a2,sp@-
	lea _bcmp,a4
	jbsr a4@
	addqw #8,sp
	addqw #4,sp
	tstl d0
	jeq LEN370
	pea 6:w
	pea _etherbcastaddr
	movel a2,sp@-
	jbsr a4@
	addqw #8,sp
	addqw #4,sp
	tstl d0
	jne LEN368
LEN370:
	subql #1,d2
	movel a2,a3
LEN368:
	cmpl #1500,d2
	jhi LEN356
	cmpl a6@(12),d2
	jlt LEN356
	movel a3,d3
	tstl d2
	jeq LEN356
	tstl a6@(16)
	jne LEN356
	pea 42:w
	pea _en_pkt_hdr
	movel d3,sp@-
	jbsr _bcopy
	addqw #8,sp
	addqw #4,sp
	jra LEN356
LEN373:
	movel a0,sp@-
	jbsr _en_arp_input
	addqw #4,sp
LEN356:
	movel _epi,d1
	eorw #1,d1
	movel d1,_epi
	movew _dma_chip,d2
	movel #9699328,d0
	cmpw #313,d2
	jne LEN376
	moveq #52,d0
	swap d0
LEN376:
	movel d0,a5@
	lea _en_pkt,a0
	movel a0@(d1:l:4),a5@(16384)
	movel a0@(d1:l:4),d0
	addl #1504,d0
	movel d0,a5@(16388)
	cmpw #313,d2
	jeq LEN378
	movel d4,a1
	movel a0@(d1:l:4),a1@(16396)
LEN378:
	movel #327680,a5@
	movel #262144,sp@-
	movel _epi,d0
	eorw #1,d0
	movel a0@(d0:l:4),a0
	pea a0@(578)
	movel a0,sp@-
	jbsr _cache_flush
	moveq #1,d5
	movel d5,_rx_active
	movel d3,d0
LEN379:
	moveml a6@(-32),#0x3c3c
	unlk a6
	rts
	.lcomm _rx_active,4
	.lcomm _rx_cached,4
	.lcomm _rx_init,4
	.lcomm _epi,4
	.text
");
/* plan 727 END */

en_arp_input(bp)
	struct en_pkt *bp;
{
	register struct ether_header *eh = (struct ether_header *) bp;
	register struct ether_arp *arp = (struct ether_arp *) ((char*)bp+sizeof(*eh));
	int len;
	struct en_softc *is = en_softc;
	
	if (arp->arp_op == ARPOP_REQUEST && arp->arp_hrd == ARPHRD_ETHER &&
	    arp->arp_pro == ETHERTYPE_IP &&
	    ((struct in_addr*)arp->arp_tpa)->s_addr == is->is_ac_ipaddr.s_addr) {
		/* It's our arp request */
		bcopy (arp->arp_sha, arp->arp_tha, 6);
		bcopy (arp->arp_spa, arp->arp_tpa, 4);
		bcopy (&is->is_addr, arp->arp_sha, 6);
		*(struct in_addr*) arp->arp_spa = is->is_ac_ipaddr;
		arp->arp_op = ARPOP_REPLY;
		bcopy (arp->arp_tha, eh->ether_dhost, 6);
		bcopy (&is->is_addr, eh->ether_shost, 6);
		len = sizeof (struct ether_header) + sizeof (struct ether_arp);
		en_xmit((caddr_t)eh, len);
	    }
}

/* plan 727 (D024, D163) BEGIN: en_send, en_xmit */
/* plan 727 (D163): en_send from the original bytes 0x408faba-0x408fb9a as file-scope asm */
asm("
	.text
	.align 1
.globl _en_send
_en_send:
	pea a6@
	movel sp,a6
	moveml #0x203c,sp@-
	movel a6@(8),d2
	movel a6@(12),a3
	movel a6@(16),a5
	lea _en_pkt_hdr,a4
	movel a3,a0
	movel a4@,a0@+
	movel _en_pkt_hdr+4,a0@+
	movel _en_pkt_hdr+8,a0@+
	movew _en_pkt_hdr+12,a0@
	pea 6:w
	movel a3,sp@-
	pea _en_pkt_hdr+6
	lea _bcopy,a2
	jbsr a2@
	pea 6:w
	pea a3@(6)
	movel a4,sp@-
	jbsr a2@
	movel _en_pkt_hdr+14,a3@(14)
	movel _en_pkt_hdr+18,a3@(18)
	movel _en_pkt_hdr+22,a3@(22)
	movel _en_pkt_hdr+26,a3@(26)
	movel _en_pkt_hdr+30,a3@(30)
	lea a3@(34),a2
	movel _en_pkt_hdr+30,a3@(26)
	movel _en_pkt_hdr+26,a3@(30)
	movew a5,d1
	addw #-14,d1
	movew d1,a3@(16)
	clrw a3@(24)
	pea 10:w
	pea a3@(14)
	jbsr _checksum_16
	notw d0
	movew d0,a3@(24)
	movew d2,a3@(36)
	movew _en_pkt_hdr+36,a2@
	movew a5,d1
	addw #-34,d1
	movew d1,a3@(38)
	clrw a3@(40)
	addw #32,sp
	pea a5@(14)
	movel a3,sp@-
	jbsr _en_xmit
	moveml a6@(-20),#0x3c04
	unlk a6
	rts
	.text
");

int en_xmit(bp, len)
	struct en_pkt *bp;
{
	volatile struct en_regs *en = (struct en_regs*) P_ENET;
	volatile struct dma_dev *tdma = (struct dma_dev*) P_ENETX_CSR;
	u_int lim, time, timeouts = 0;
	int timedout;

	if (len < ETHERMIN + sizeof (struct ether_header))
		len = ETHERMIN + sizeof (struct ether_header);
	do  {	
		if (dma_chip == 313) {
			while (!(en->en_txstat & EN_TXSTAT_READY))
				;
		} else
			en->en_txstat = EN_TXSTAT_CLEAR;
		cache_flush (bp, (char *)bp + sizeof *bp, DMACSR_WRITE);
		tdma->dd_csr = (dma_chip == 313) ? (DMACSR_RESET | DMACSR_INITBUF | DMACSR_WRITE) : (DMACSR_RESET | DMACSR_INITBUF_TURBO | DMACSR_WRITE);
		tdma->dd_next = (char*)bp;
		if (dma_chip == 313)
			tdma->dd_saved_next = (char*)bp;
		else
			tdma->dd_start = (char*)bp;
		lim = (u_int)bp + len;
		if (dma_chip == 313)
			lim += 15 | ENTX_EOP;
		tdma->dd_limit = (char*)lim;
		if (dma_chip == 313)
			tdma->dd_saved_limit = (char*)lim;
		tdma->dd_csr = DMACSR_WRITE | DMACSR_SETENABLE;
		if (dma_chip != 313)
			en->en_txmode |= 0x80;	/* 0x80: no name in if_enreg.h */
	
		time = event_get();
		timedout = 0;
		for (;;) {
			if (dma_chip == 313) {
				if (!(tdma->dd_csr & DMACSR_COMPLETE))
					goto wait;
				break;
			} else if (en->en_txstat & EN_TXSTAT_READY)
				break;
		wait:
			DELAY(1);
			if (event_get() - time > 10000)  {
				timeouts++;
				printf ("en_xmit: timeout\n");
				timedout = 1;
				break;
			}
		}
	} while (timedout && timeouts < 4);
	tdma->dd_csr = DMACSR_RESET;
	if (dma_chip != 313)
		en->en_txmode &= 0x7f;	/* clears 0x80: no name in if_enreg.h */
	if (timeouts < 4)
		return (1);
	else
		return (-1);
}
/* plan 727 END */
#endif	GDB
#endif
/* plan 779 (D178): kdb_net tentative definition (type of nextdbg.c:207) written to match the original bytes (D024, plan 778.15) */
struct kdb_n { char *ri; char *ti; int locked; } kdb_net;
