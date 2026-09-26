/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ca60. */
int __cdecl linw(unsigned __int16 a1, _WORD *a2, int a3)
{
  unsigned __int16 v5; // ax
  int result; // eax

  while ( 1 ) /*0x18ca7e*/
  {
    result = a3--; /*0x18ca7e*/
    if ( !result ) /*0x18ca83*/
      break; /*0x18ca83*/
    v5 = __inword(a1); /*0x18ca76*/
    *a2++ = v5; /*0x18ca78*/
  }
  return result; /*0x18ca88*/
}
