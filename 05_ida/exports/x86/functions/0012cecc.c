/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cecc. */
_DWORD *__cdecl findexport(void *a1, _WORD *a2)
{
  _DWORD *v2; // ebx
  unsigned __int16 *v3; // edx

  v2 = (_DWORD *)exported; /*0x12ced8*/
  if ( !exported ) /*0x12cee0*/
    return nullptr; /*0x12cf27*/
  while ( 1 ) /*0x12ceeb*/
  {
    if ( !bcmp(v2 + 8, a1, 8u) ) /*0x12ceeb*/
    {
      v3 = (unsigned __int16 *)v2[10]; /*0x12cef7*/
      if ( *a2 == *v3 && !bcmp(v3 + 1, a2 + 1, *v3) ) /*0x12cf10*/
        break; /*0x12cf10*/
    }
    v2 = (_DWORD *)v2[11]; /*0x12cf20*/
    if ( !v2 ) /*0x12cf25*/
      return nullptr; /*0x12cf25*/
  }
  return v2; /*0x12cf2c*/
}
