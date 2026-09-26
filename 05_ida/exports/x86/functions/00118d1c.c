/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118d1c. */
int __cdecl unp_mark(int a1)
{
  int result; // eax

  result = a1; /*0x118d1f*/
  if ( (*(_BYTE *)(a1 + 8) & 0x10) == 0 ) /*0x118d26*/
  {
    ++unp_defer; /*0x118d28*/
    *(_BYTE *)(a1 + 8) |= 0x30u; /*0x118d2e*/
  }
  return result; /*0x118d34*/
}
