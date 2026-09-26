/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1192d0. */
int __cdecl statfs(const char *a1, statfs *a2)
{
  int *v2; // ebx
  int result; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = *(int **)(dword_1E875C + 36); /*0x1192dc*/
  *(_BYTE *)(dword_1E875C + 104) = lookupname(*v2, 0, 1, 0, (int)&v4); /*0x1192f8*/
  result = dword_1E875C; /*0x1192fb*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x119303*/
  {
    cstatfs(*(_DWORD *)(v4 + 36), v2[1]); /*0x119314*/
    LOWORD(result) = vn_rele(v4); /*0x11931d*/
  }
  return result; /*0x119322*/
}
