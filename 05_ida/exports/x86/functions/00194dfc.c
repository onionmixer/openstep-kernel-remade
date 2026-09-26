/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194dfc. */
__int16 __cdecl kd_slmwd(_WORD *a1, int a2, __int16 a3)
{
  __int16 result; // ax

  result = a3; /*0x194e06*/
  while ( a2 ) /*0x194e0a*/
  {
    *a1++ = a3; /*0x194e0a*/
    --a2; /*0x194e0a*/
  }
  return result; /*0x194e0d*/
}
