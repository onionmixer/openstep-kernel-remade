/* S1-C sample byte_swap_ints -- cut verbatim from darwin01/kernel/bsd/ufs/ufs/ufs_byte_order.c lines 61-68
 * (SHA-256 392b35920203db33366ada547c8b57fb4b1c5715dff35d0265e2ee251036e26f, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: lines 43-51 of the same file */
#include <architecture/byte_order.h>
#if 0
#define	byte_swap_longlong(thing) ((thing) = NXSwapBigLongLongToHost(thing))
#define	byte_swap_int(thing) ((thing) = NXSwapBigLongToHost(thing))
#define	byte_swap_short(thing) ((thing) = NXSwapBigShortToHost(thing))
#else
#define	byte_swap_longlong(thing) ((thing) = NXSwapLongLong(thing))
#define	byte_swap_int(thing) ((thing) = NXSwapLong(thing))
#define	byte_swap_short(thing) ((thing) = NXSwapShort(thing))
#endif
/* ---- verbatim ---- */
void
byte_swap_ints(int *array, int count)
{
	register int	i;

	for (i = 0;  i < count;  i++)
		byte_swap_int(array[i]);
}
