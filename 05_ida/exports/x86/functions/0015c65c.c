/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c65c. */
int __cdecl nextsect(int a1, int a2)
{
  int v2; // eax

  if ( a1 && *(_DWORD *)(a1 + 48) ) /*0x15c66b*/
    v2 = a1 + 56; /*0x15c678*/
  else
    v2 = 0; /*0x15c671*/
  if ( (-252645135 * (a2 - v2)) >> 2 >= (unsigned int)(*(_DWORD *)(a1 + 48) - 1) ) /*0x15c6a0*/
    return 0; /*0x15c6a8*/
  else
    return a2 + 68; /*0x15c6a2*/
}
