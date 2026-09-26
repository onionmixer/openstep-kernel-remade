/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x110fa4. */
int __cdecl ttyrubo(int a1, int a2)
{
  char *v2; // esi
  int i; // ebx
  int result; // eax

  v2 = asc_1DAFD9; /*0x110fb0*/
  if ( (*(_BYTE *)(a1 + 62) & 4) != 0 ) /*0x110fb9*/
    v2 = asc_1DAFD5; /*0x110fbb*/
  for ( i = a2 - 1; i >= 0; --i ) /*0x110fc1*/
    result = ttyoutstr(v2, a1); /*0x110fc6*/
  return result; /*0x110fd4*/
}
