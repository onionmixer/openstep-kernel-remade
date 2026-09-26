/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be50c. */
void __cdecl audio_convertLinear16ToMulaw8(__int16 *a1, _BYTE *a2, int a3)
{
  __int16 v5; // [esp-4h] [ebp-10h]

  while ( --a3 != -1 ) /*0x1be531*/
  {
    v5 = *a1++; /*0x1be523*/
    *a2 = audio_shortToMulaw(v5); /*0x1be52c*/
  }
}
