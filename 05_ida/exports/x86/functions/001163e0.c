/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1163e0. */
int __cdecl socantrcvmore(int a1)
{
  *(_BYTE *)(a1 + 6) |= 0x20u; /*0x1163e6*/
  return sowakeup(a1, a1 + 36); /*0x1163f6*/
}
