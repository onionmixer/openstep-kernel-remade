/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf2c0. */
int sub_1CF2C0()
{
  int v0; // edx
  int result; // eax

  v0 = 0; /*0x1cf2c3*/
  if ( !_nel ) /*0x1cf2cb*/
    return 0; /*0x1cf2e9*/
  while ( 1 ) /*0x1cf2d7*/
  {
    result = *((_DWORD *)dword_1E55F8 + 6 * v0); /*0x1cf2d7*/
    if ( *(_DWORD *)(result + 12) != 3 ) /*0x1cf2de*/
      break; /*0x1cf2de*/
    if ( _nel <= ++v0 ) /*0x1cf2e7*/
      return 0; /*0x1cf2e7*/
  }
  return result; /*0x1cf2ed*/
}
