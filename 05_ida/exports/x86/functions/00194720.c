/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194720. */
_BOOL4 __cdecl eisa_id(__int16 a1, _BYTE *a2)
{
  _BOOL4 result; // eax

  if ( !dword_1E7744 ) /*0x194732*/
  {
    if ( !strncmp((const char *)0xFFFD9, aEisa_5, 4u) ) /*0x194740*/
      dword_1E2C50 = 1; /*0x19474c*/
    dword_1E7744 = 1; /*0x194756*/
  }
  result = false; /*0x1947b8*/
  if ( dword_1E2C50 ) /*0x194767*/
  {
    a2[3] = inb((a1 << 12) | 0xC80); /*0x19477f*/
    a2[2] = inb(((a1 << 12) | 0xC80) + 1); /*0x19478d*/
    a2[1] = inb(((a1 << 12) | 0xC80) + 2); /*0x19479b*/
    *a2 = inb(((a1 << 12) | 0xC80) + 3); /*0x1947a9*/
    if ( *(_DWORD *)a2 != -1 ) /*0x1947ae*/
      return true; /*0x194767*/
  }
  return result; /*0x1947bd*/
}
