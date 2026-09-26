/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be544. */
int __cdecl audio_convertMulaw8ToLinear16(unsigned __int8 *a1, _BYTE *a2, int a3)
{
  int result; // eax

  while ( --a3 != -1 ) /*0x1be562*/
  {
    result = *a1; /*0x1be554*/
    LOBYTE(result) = audio_muLaw[result]; /*0x1be557*/
    *a2 = result; /*0x1be55e*/
    ++a1; /*0x1be560*/
    ++a2; /*0x1be561*/
  }
  return result; /*0x1be568*/
}
