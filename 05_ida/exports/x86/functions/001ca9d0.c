/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca9d0. */
_DWORD *__cdecl _threadFreeExceptionStack(int a1)
{
  _DWORD *result; // eax

  result = &unk_1E551C; /*0x1ca9d6*/
  if ( &unk_1E551C ) /*0x1ca9dd*/
  {
    do /*0x1ca9ea*/
    {
      if ( result[4] == a1 ) /*0x1ca9e3*/
        break; /*0x1ca9e3*/
      result = (_DWORD *)result[5]; /*0x1ca9e5*/
    }
    while ( result ); /*0x1ca9ea*/
    if ( result ) /*0x1ca9ee*/
    {
      *result = 0; /*0x1ca9f0*/
      result[3] = 0; /*0x1ca9f6*/
      result[4] = 0; /*0x1ca9fd*/
    }
  }
  return result; /*0x1caa06*/
}
