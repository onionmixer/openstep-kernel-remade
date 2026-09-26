/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116594. */
int __cdecl sbreserve(int a1, unsigned int a2)
{
  __int16 v3; // ax

  if ( a2 > 0xCCCC ) /*0x1165a2*/
    return 0; /*0x1165a4*/
  *(_WORD *)(a1 + 2) = a2; /*0x1165ac*/
  v3 = 2 * a2; /*0x1165b0*/
  if ( (int)(2 * a2) > 0xFFFF ) /*0x1165b7*/
    v3 = -1; /*0x1165b9*/
  *(_WORD *)(a1 + 6) = v3; /*0x1165be*/
  return 1; /*0x1165a8*/
}
