/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ed58 */

void _null_init(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &_afswitch;
  do {
    if (*ppuVar1 == (undefined *)0x0) {
      *ppuVar1 = _null_hash;
      *ppuVar1 = *ppuVar1;
    }
    ppuVar1 = ppuVar1 + 2;
  } while (ppuVar1 < &_ifqmaxlen);
  return;
}

