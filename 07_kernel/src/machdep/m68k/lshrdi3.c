/*
 * machdep/m68k/lshrdi3.c -- __lshrdi3, 64-bit logical right shift (plan 639, D145).
 *
 * Written from the original bytes (D024, D145): the 1997 m68k kernel range
 * [0x4093146, 0x4093192) (76 bytes; inventory row m68k-291 with __lshldi3).
 * The shift count is the low word of a long long (the original reads fp@(20);
 * plan 637).
 * The shape of these helpers looks like the GCC 1.x gnulib2.c family, but
 * that text was neither imported nor compared (D145); the license judgement
 * is the user's.
 * C names carry one leading _ less than the symbols (the compiler adds it).
 */

#import <machdep/m68k/dword.h>

long long
_lshrdi3(u, count)	/* plan 639 (D024, D145): from the original bytes 0x4093146 */
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
	w.s.high = 0;
	w.s.low = (unsigned long)uu.s.high >> -bm;
    } else {
	carries = (unsigned long)uu.s.high << bm;
	w.s.high = (unsigned long)uu.s.high >> b;
	w.s.low = ((unsigned long)uu.s.low >> b) | carries;
    }
    return w.ll;
}
