/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104478. */
int __cdecl fset(int a1, int a2, int a3)
{
  int v3; // eax

  if ( a3 ) /*0x104485*/
    *(_DWORD *)(a1 + 8) |= a2; /*0x104487*/
  else
    *(_DWORD *)(a1 + 8) &= ~a2; /*0x104490*/
  v3 = -2147195267; /*0x104497*/
  if ( a2 == 4 ) /*0x10449f*/
    v3 = -2147195266; /*0x1044a1*/
  return fioctl(a1, v3, &a3); /*0x1044af*/
}
