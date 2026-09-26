/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f820. */
int __cdecl rinactive(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 112); /*0x12f827*/
  if ( result ) /*0x12f82c*/
  {
    result = crfree(*(_WORD **)(a1 + 112)); /*0x12f82f*/
    *(_DWORD *)(a1 + 112) = 0; /*0x12f834*/
  }
  return result; /*0x12f83b*/
}
