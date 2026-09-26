/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13ba10. */
int __cdecl fspause(int a1)
{
  int v1; // ecx
  int v2; // edx
  const char *v3; // eax

  v1 = *(_DWORD *)(dword_1E875C + 108); /*0x13ba19*/
  v2 = *(char *)(dword_1E875C + 112); /*0x13ba1c*/
  *(_DWORD *)(dword_1E875C + 108) = 0; /*0x13ba20*/
  *(_BYTE *)(dword_1E875C + 112) = 0; /*0x13ba2c*/
  if ( v1 && v2 && *(_BYTE *)(dword_1E875C + 104) == 28 && (*(_BYTE *)(active_u + 608) & 8) != 0 && !a1 ) /*0x13ba56*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 0; /*0x13ba58*/
    v3 = aFileSystemIsFu; /*0x13ba5c*/
    if ( (v2 & 1) == 0 ) /*0x13ba64*/
      v3 = aOutOfInodes_0; /*0x13ba66*/
    if ( rpsleep((void (__cdecl *)(int, int))fssleep, v1, v2, (const char *)(v1 + 212), v3) ) /*0x13ba7a*/
      return 1; /*0x13ba88*/
    *(_BYTE *)(dword_1E875C + 104) = 28; /*0x13ba91*/
  }
  return 0; /*0x13ba97*/
}
