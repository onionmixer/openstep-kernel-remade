/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1019c0. */
int __cdecl page_set(_DWORD *a1, int a2, int a3)
{
  int result; // eax

  result = a2; /*0x1019c9*/
  do /*0x1019ea*/
  {
    *a1 = a2; /*0x1019cc*/
    a1[1] = a2; /*0x1019cf*/
    a1[2] = a2; /*0x1019d2*/
    a1[3] = a2; /*0x1019d5*/
    a1[4] = a2; /*0x1019d8*/
    a1[5] = a2; /*0x1019db*/
    a1[6] = a2; /*0x1019de*/
    a1[7] = a2; /*0x1019e1*/
    a1 += 8; /*0x1019e4*/
    a3 -= 32; /*0x1019e7*/
  }
  while ( a3 ); /*0x1019ea*/
  return result; /*0x1019ee*/
}
