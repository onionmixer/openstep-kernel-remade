/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdf20. */
char __cdecl audio_twosComp8ToUnary(_BYTE *a1, _BYTE *a2, int a3)
{
  char result; // al

  while ( --a3 != -1 ) /*0x1bdf3f*/
  {
    result = *a1 & 0x7F; /*0x1bdf37*/
    *a2++ = result | *a1++ ^ 0x80; /*0x1bdf3b*/
  }
  return result; /*0x1bdf48*/
}
