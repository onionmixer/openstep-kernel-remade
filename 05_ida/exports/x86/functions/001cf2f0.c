/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf2f0. */
char *__cdecl _nameForHeader(int a1)
{
  int v1; // edx
  _DWORD *v2; // eax
  unsigned int v3; // edx

  if ( !a1 || *(_DWORD *)(a1 + 12) != 3 ) /*0x1cf304*/
    return *(char **)NXArgv; /*0x1cf33c*/
  v1 = sub_1CF2C0(); /*0x1cf30b*/
  v2 = (_DWORD *)(v1 + 28); /*0x1cf30d*/
  v3 = v1 + 28 + *(_DWORD *)(v1 + 20); /*0x1cf313*/
  if ( (unsigned int)v2 >= v3 ) /*0x1cf317*/
    return nullptr; /*0x1cf32d*/
  while ( *v2 != 6 || v2[4] != a1 ) /*0x1cf324*/
  {
    v2 = (_DWORD *)((char *)v2 + v2[1]); /*0x1cf326*/
    if ( (unsigned int)v2 >= v3 ) /*0x1cf32b*/
      return nullptr; /*0x1cf32b*/
  }
  return (char *)v2 + v2[2]; /*0x1cf33e*/
}
