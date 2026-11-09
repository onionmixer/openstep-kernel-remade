/*
 * m68k Internet checksum (plans 518-520, D024, D027, D103, D111).
 *
 * Written for this project from the OPENSTEP 4.2 m68k kernel bytes.
 * in_cksum is the in_cksum body of the i386 in_cksum.c of this project
 * (plan 247) without the two "<< 8" of the odd-byte additions (m68k is
 * big-endian; original _in_cksum at 0x40927d4, 212 bytes).  oc_cksum is the
 * instruction sequence of the original _oc_cksum (0x40928a8, 182 bytes),
 * written as a file-scope asm after in_cksum (D111); there is no reference
 * text for it.  The i386 file notes that its sequence may coincide with
 * Darwin 0.1 machdep/i386/in_cksum.c; no Darwin text is used here.
 */

#import <sys/param.h>
#import <sys/mbuf.h>

int oc_cksum(unsigned char *buf, int len, unsigned long oldsum);	/* plan 518 (D111): prototype */

in_cksum(m, len)
	register struct mbuf *m;
	register int len;
{
	register int sum = 0;
	register int i;

	while (len > m->m_len) {
		sum = oc_cksum(mtod(m, u_char *), i = m->m_len, sum);
		m = m->m_next;
		len -= i;
		if (i & 1) {
			/*
			 * An odd number of bytes was summed: continue the
			 * following mbufs a byte out of phase.
			 */
			register u_char *cp;

			while (len > m->m_len) {
				cp = mtod(m, u_char *);
				if (i & 1) {
					i = m->m_len - 1;
					--len;
					sum += (*cp++);	/* plan 518 (D111): no << 8 (big-endian) */
				} else
					i = m->m_len;
				sum = oc_cksum(cp, i, sum);
				m = m->m_next;
				len -= i;
			}
			if (i & 1) {
				cp = mtod(m, u_char *);
				sum += (*cp++);	/* plan 518 (D111): no << 8 (big-endian) */
				return (0xffff & ~oc_cksum(cp, len - 1, sum));
			}
		}
	}
	return (0xffff & ~oc_cksum(mtod(m, u_char *), len, sum));
}

/* plan 518 (D111): the original _oc_cksum (0x40928a8-0x409295e) as file-scope asm */
asm("
	.text
	.globl	_oc_cksum
_oc_cksum:
	link	a6,#0
	movl	a6@(0x8),a0
	movl	a6@(0xc),d1
	movl	a6@(0x10),d0
	movl	d2,sp@-
	btst	#0,d1
	bne	5f
	btst	#1,d1
	bne	7f
1:	movl	d1,d2
	lsrl	#6,d1
	andl	#0x3c,d2
	negl	d2
	andb	#0xf,cc
	jmp	pc@(0x42,d2:l)
3:
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	movl	a0@+,d2
	addxl	d2,d0
	dbf	d1,3b
	movl	d0,d1
	swap	d1
	addxw	d1,d0
	bcc	4f
	addqw	#1,d0
4:	andl	#0xffff,d0
	movl	sp@+,d2
	unlk	a6
	rts
5:	btst	#1,d1
	beq	6f
	clrl	d2
	movw	a0@(-3,d1:l),d2
	addl	d2,d0
6:	clrl	d2
	movb	a0@(-1,d1:l),d2
	lsll	#8,d2
	addl	d2,d0
	bra	1b
7:	clrl	d2
	movw	a0@(-2,d1:l),d2
	addl	d2,d0
	bra	1b
");
