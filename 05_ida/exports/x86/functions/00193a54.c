/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193a54. */
int __cdecl machine_exception(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  if ( a1 == 2 ) /*0x193a67*/
  {
    *a4 = 4; /*0x193a70*/
    *a5 = a2; /*0x193a76*/
  }
  else
  {
    if ( a1 != 3 ) /*0x193a6c*/
      return 0; /*0x193a8a*/
    *a4 = 8; /*0x193a7c*/
    *a5 = a2; /*0x193a82*/
  }
  return 1; /*0x193a91*/
}
