/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113360. */
int __cdecl nextc(_DWORD *a1, int a2)
{
  int result; // eax

  if ( !*a1 ) /*0x113369*/
    return 0; /*0x113369*/
  result = a2 + 1; /*0x11336e*/
  if ( a1[2] == a2 + 1 ) /*0x113372*/
    return 0; /*0x113388*/
  if ( (result & 0x3F) == 0 ) /*0x113376*/
    return *(_DWORD *)(a2 - 63) + 12; /*0x11337b*/
  return result; /*0x113380*/
}
