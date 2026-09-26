/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1097f8. */
_DWORD *__cdecl gsignal(_DWORD *a1, char *a2)
{
  _DWORD *result; // eax

  result = a1; /*0x1097fb*/
  if ( a1 ) /*0x109800*/
  {
    result = pgfind((int)a1); /*0x109803*/
    if ( result ) /*0x10980d*/
      return (_DWORD *)pgsignal((int)result, a2, 0); /*0x109816*/
  }
  return result; /*0x10981d*/
}
