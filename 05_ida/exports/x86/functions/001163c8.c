/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1163c8. */
int __cdecl socantsendmore(int a1)
{
  *(_BYTE *)(a1 + 6) |= 0x10u; /*0x1163ce*/
  return sowakeup(a1, a1 + 60); /*0x1163de*/
}
