/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccab0. */
_BOOL4 __cdecl _mapStrIsEqual(int a1, char *__s1, char *__s2)
{
  const char *v4; // edi

  if ( __s1 == __s2 ) /*0x1ccabc*/
    return 1; /*0x1ccac3*/
  if ( !__s1 ) /*0x1ccaca*/
  {
    v4 = __s2; /*0x1ccace*/
    return strlen(v4) == 0; /*0x1ccaef*/
  }
  if ( !__s2 ) /*0x1ccad6*/
  {
    v4 = __s1; /*0x1ccada*/
    return strlen(v4) == 0; /*0x1ccada*/
  }
  return *__s2 == *__s1 && strcmp(__s1, __s2) == 0; /*0x1ccb06*/
}
