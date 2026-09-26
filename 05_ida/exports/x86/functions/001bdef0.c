/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdef0. */
int __cdecl audio_swapSamples(__int16 *a1, _WORD *a2, int a3)
{
  __int16 v6; // ax
  int result; // eax

  while ( --a3 != -1 ) /*0x1bdf10*/
  {
    v6 = *a1++; /*0x1bdf00*/
    LOWORD(result) = __ROR2__(v6, 8); /*0x1bdf06*/
    *a2++ = result; /*0x1bdf0a*/
  }
  return result; /*0x1bdf16*/
}
