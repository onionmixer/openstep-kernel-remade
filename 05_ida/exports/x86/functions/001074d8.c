/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1074d8. */
_DWORD *__cdecl pgfind(int a1)
{
  _DWORD *result; // eax

  result = (_DWORD *)pgrphash[a1 & 0x3F]; /*0x1074e3*/
  if ( !result ) /*0x1074ec*/
    return nullptr; /*0x1074fb*/
  while ( result[3] != a1 ) /*0x1074f3*/
  {
    result = (_DWORD *)*result; /*0x1074f5*/
    if ( !result ) /*0x1074f9*/
      return nullptr; /*0x1074f9*/
  }
  return result; /*0x1074ff*/
}
