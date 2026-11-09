/*
 * machdep/m68k/dword.h -- a 64-bit value as two 32-bit words (plan 639, D145).
 *
 * Written for this project (D024, D145): ashldi3.c, lshldi3.c, lshrdi3.c,
 * udivdi3.c and umoddi3.c of this directory, whose functions are written
 * from the original bytes of the 1997 m68k kernel, keep a long long and its
 * two words in this union.
 * The shape of these helpers looks like the GCC 1.x gnulib2.c family, but
 * that text was neither imported nor compared (D145); the license judgement
 * is the user's.
 */

typedef union {
    long long		ll;
    struct {
	long		high;
	long		low;
    }			s;
} dword_t;	/* m68k: the most significant word first */
