/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be4e4. */
int __cdecl audio_convertLinear16ToLinear8(int a1, _BYTE *a2, int a3)
{
  int result; // eax

  result = a3; /*0x1be4ee*/
  while ( --result != -1 ) /*0x1be4fd*/
  {
    *a2 = *(_BYTE *)(a1 + 1); /*0x1be4f7*/
    a1 += 2; /*0x1be4f9*/
    ++a2; /*0x1be4fc*/
  }
  return result; /*0x1be503*/
}
