/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1193d4. */
int __cdecl unmount(const char *a1, int a2)
{
  char v2; // dl
  int result; // eax
  int v4; // ebx
  char v5; // dl
  int v6; // [esp+4h] [ebp-4h] BYREF

  v2 = lookupname(**(_DWORD **)(dword_1E875C + 36), 0, 1, 0, &v6); /*0x1193f5*/
  result = dword_1E875C; /*0x1193f7*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x1193fc*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x119408*/
  {
    if ( (*(_BYTE *)(v6 + 4) & 1) != 0 ) /*0x119415*/
    {
      v4 = *(_DWORD *)(v6 + 36); /*0x119428*/
      vn_rele(v6); /*0x11942c*/
      if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) == *(_WORD *)(v4 + 292) || suser() ) /*0x119449*/
      {
        mfs_cache_clear(); /*0x119460*/
        vm_object_cache_clear(); /*0x119465*/
        v5 = dounmount(v4); /*0x119470*/
        result = dword_1E875C; /*0x119472*/
        *(_BYTE *)(dword_1E875C + 104) = v5; /*0x119477*/
      }
      else
      {
        result = dword_1E875C; /*0x119452*/
        *(_BYTE *)(dword_1E875C + 104) = 1; /*0x119457*/
      }
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x119417*/
      LOWORD(result) = vn_rele(v6); /*0x11941f*/
    }
  }
  return result; /*0x11947a*/
}
