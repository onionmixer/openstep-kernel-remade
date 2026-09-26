/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be940. */
int __cdecl audio_clear_peaks(_DWORD *a1, int a2)
{
  int result; // eax

  result = a2; /*0x1be946*/
  while ( --result != -1 ) /*0x1be955*/
    *a1++ = 0; /*0x1be94c*/
  return result; /*0x1be95d*/
}
