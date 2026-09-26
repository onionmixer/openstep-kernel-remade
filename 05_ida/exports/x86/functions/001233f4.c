/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1233f4. */
void *__cdecl ether_sprintf(_BYTE *a1)
{
  _BYTE *v2; // edx
  int i; // ebx
  _BYTE *v4; // edx

  v2 = &unk_1E58E2; /*0x1233fb*/
  for ( i = 0; i <= 5; ++i ) /*0x123400*/
  {
    *v2 = byte_1DBA87[*a1 >> 4]; /*0x123414*/
    v4 = v2 + 1; /*0x123416*/
    *v4 = byte_1DBA87[*a1++ & 0xF]; /*0x123422*/
    *++v4 = 58; /*0x123426*/
    v2 = v4 + 1; /*0x123429*/
  }
  *(v2 - 1) = 0; /*0x123430*/
  return &unk_1E58E2; /*0x123439*/
}
