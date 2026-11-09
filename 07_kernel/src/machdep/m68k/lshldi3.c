/*
 * machdep/m68k/lshldi3.c -- __lshldi3, 64-bit left shift (the same bytes as __ashldi3) (plan 639, D145).
 *
 * Written from the original bytes (D024, D145): the 1997 m68k kernel range
 * [0x40930fa, 0x4093146) (76 bytes; inventory row m68k-291 with __lshrdi3).
 * The shift count is the low word of a long long (the original reads fp@(20);
 * plan 637).
 * The shape of these helpers looks like the GCC 1.x gnulib2.c family, but
 * that text was neither imported nor compared (D145); the license judgement
 * is the user's.
 * C names carry one leading _ less than the symbols (the compiler adds it).
 */

#import <machdep/m68k/dword.h>

long long
_lshldi3(u, count)	/* plan 639 (D024, D145): from the original bytes 0x40930fa */
    long long		u;
    long long		count;
{
    dword_t		w, uu;
    unsigned long	carries;
    int			bm, b = count;

    if (b == 0)
	return u;
    uu.ll = u;
    bm = 32 - b;
    if (bm <= 0) {
	w.s.low = 0;
	w.s.high = (unsigned long)uu.s.low << -bm;
    } else {
	carries = (unsigned long)uu.s.low >> bm;
	w.s.low = (unsigned long)uu.s.low << b;
	w.s.high = ((unsigned long)uu.s.high << b) | carries;
    }
    return w.ll;
}
