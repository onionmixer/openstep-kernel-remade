/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160674. */
unsigned int __cdecl ns_time_to_tsval(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  *a3 = __PAIR64__(a2 % 0x3E8, a1) / 0x3E8; /*0x1606ab*/
  a3[1] = a2 / 0x3E8; /*0x1606c3*/
  return a2 / 0x3E8; /*0x1606c6*/
}
