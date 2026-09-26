/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a557c. */
int __cdecl IOFindValueForName(char *__s2, int a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  const char **v4; // ebx

  v3 = (_DWORD *)a2; /*0x1a5582*/
  if ( !*(_DWORD *)(a2 + 4) ) /*0x1a5588*/
    return -706; /*0x1a55bb*/
  v4 = (const char **)(a2 + 4); /*0x1a558e*/
  while ( strcmp(*v4, __s2) ) /*0x1a55a5*/
  {
    v4 += 2; /*0x1a55b0*/
    v3 += 2; /*0x1a55b3*/
    if ( !*v4 ) /*0x1a55b6*/
      return -706; /*0x1a55b9*/
  }
  *a3 = *v3; /*0x1a55a9*/
  return 0; /*0x1a55c3*/
}
