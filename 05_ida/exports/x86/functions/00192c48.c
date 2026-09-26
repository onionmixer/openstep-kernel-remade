/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192c48. */
void __cdecl byte_swap_shorts(_WORD *a1, int a2)
{
  int i; // ecx

  for ( i = 0; i < a2; ++i ) /*0x192c53*/
  {
    *a1 = __ROR2__(*a1, 8); /*0x192c5f*/
    ++a1; /*0x192c62*/
  }
}
