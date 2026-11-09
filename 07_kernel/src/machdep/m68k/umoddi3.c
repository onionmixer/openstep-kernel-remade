/*
 * machdep/m68k/umoddi3.c -- __umoddi3, 64-bit unsigned remainder (plan 639, D145).
 *
 * Written from the original bytes (D024, D145): the 1997 m68k kernel range
 * [0x409aa92, 0x409aaf6) (100 bytes; inventory row m68k-322 with __udivdi3).
 * The digits go to __bdiv (machdep/m68k/bdiv.c) as 16- and 8-byte arrays.
 * The shape of these helpers looks like the GCC 1.x gnulib2.c family, but
 * that text was neither imported nor compared (D145); the license judgement
 * is the user's.
 * C names carry one leading _ less than the symbols (the compiler adds it).
 */

#import <machdep/m68k/dword.h>

extern void	_bdiv();

long long
_umoddi3(u, v)	/* plan 639 (D024, D145): from the original bytes 0x409aa92 */
    long long		u, v;
{
    unsigned long	a[4], b[2], q[2], r[2];
    dword_t		w, uu, vv;

    uu.ll = u;
    vv.ll = v;
    a[0] = 0;
    a[1] = 0;
    a[2] = uu.s.high;
    a[3] = uu.s.low;
    b[0] = vv.s.high;
    b[1] = vv.s.low;
    _bdiv(a, b, q, r, sizeof a, sizeof b);
    w.s.high = r[0];
    w.s.low = r[1];
    return w.ll;
}
