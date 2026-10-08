/*
 * i386 Internet checksum (plan 247).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes
 * (D024, D027).  The assembler sequence is the one in the original
 * kernel, so it may coincide with Darwin 0.1 machdep/i386/in_cksum.c,
 * which was consulted for structure only.
 */

#import <sys/param.h>
#import <sys/mbuf.h>

/*
 * Add len bytes at buf to the 16-bit one's complement sum oldsum.
 */
static inline int
oc_cksum(
    unsigned char	*buf,
    int			len,
    unsigned long	oldsum
)
{
    unsigned short	sum;

    asm("
	testb	$1, %%ecx
	jne	5f
	testb	$2, %%ecx
	jne	7f
0:
	adc	$0, %%eax
	shr	$3, %%ecx
	jnc	1f
	add	(%%esi), %%eax
	adc	$0, %%eax
	add	$4, %%esi
1:
	test	%%ecx, %%ecx
	jz	4f
	mov	(%%esi), %%edx
	mov	4(%%esi), %%ebx
	dec	%%ecx
	jz	3f
	add	$8, %%esi
2:
	add	%%edx, %%eax
	mov	(%%esi), %%edx
	adc	%%ebx, %%eax
	mov	4(%%esi), %%ebx
	adc	$0, %%eax
	add	$8, %%esi
	dec	%%ecx
	jnz	2b
3:
	add	%%edx, %%eax
	adc	%%ebx, %%eax
	adc	$0, %%eax
4:
	mov	%%eax, %%edx
	shr	$16, %%edx
	add	%%dx, %%ax
	adc	$0, %%eax
	jmp	8f
5:
	testb	$2, %%ecx
	je	6f
	movzwl	-3(%%esi,%%ecx), %%ebx
	add	%%ebx, %%eax
6:
	movzbl	-1(%%esi,%%ecx), %%ebx
	adc	%%ebx, %%eax
	jmp	0b
7:
	movzwl	-2(%%esi,%%ecx), %%ebx
	add	%%ebx, %%eax
	jmp	0b
8:
    " : "=a" (sum) : "c" (len), "S" (buf), "a" (oldsum) :
    "eax", "ebx", "ecx", "edx", "esi");

    return (sum);
}

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
					sum += (*cp++) << 8;
				} else
					i = m->m_len;
				sum = oc_cksum(cp, i, sum);
				m = m->m_next;
				len -= i;
			}
			if (i & 1) {
				cp = mtod(m, u_char *);
				sum += (*cp++) << 8;
				return (0xffff & ~oc_cksum(cp, len - 1, sum));
			}
		}
	}
	return (0xffff & ~oc_cksum(mtod(m, u_char *), len, sum));
}
