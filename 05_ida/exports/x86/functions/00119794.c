/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119794. */
int __cdecl vfs_add(int a1, int a2, __int16 a3)
{
  int result; // eax
  int *v4; // eax

  result = vfs_lock(a2); /*0x1197a4*/
  if ( !result ) /*0x1197ae*/
  {
    if ( a1 ) /*0x1197b6*/
    {
      if ( *(_DWORD *)(a1 + 12) ) /*0x1197b8*/
      {
        vfs_unlock(a2); /*0x1197bf*/
        return 16; /*0x1197c9*/
      }
      if ( a3 >= 0 ) /*0x1197d3*/
      {
        *(_DWORD *)(a1 + 12) = a2; /*0x1197ec*/
      }
      else
      {
        *(_DWORD *)(a2 + 288) = *(_DWORD *)(a1 + 16); /*0x1197d8*/
        *(_DWORD *)(a1 + 16) = a2; /*0x1197de*/
        microtime(a1 + 20); /*0x1197e5*/
      }
      v4 = (int *)rootvfs; /*0x1197ef*/
      *(_DWORD *)a2 = *(_DWORD *)rootvfs; /*0x1197f6*/
      *v4 = a2; /*0x1197f8*/
    }
    else
    {
      rootvfs = a2; /*0x1197fc*/
      *(_DWORD *)a2 = 0; /*0x119802*/
    }
    *(_DWORD *)(a2 + 8) = a1; /*0x119808*/
    if ( (a3 & 1) != 0 ) /*0x119811*/
      *(_BYTE *)(a2 + 12) |= 1u; /*0x119813*/
    else
      *(_DWORD *)(a2 + 12) &= ~1u; /*0x11981c*/
    if ( (a3 & 2) != 0 ) /*0x119826*/
      *(_BYTE *)(a2 + 12) |= 8u; /*0x119828*/
    else
      *(_DWORD *)(a2 + 12) &= ~8u; /*0x119830*/
    if ( (a3 & 8) != 0 ) /*0x11983a*/
      *(_BYTE *)(a2 + 12) |= 0x10u; /*0x11983c*/
    else
      *(_DWORD *)(a2 + 12) &= ~0x10u; /*0x119844*/
    if ( (a3 & 0x20) != 0 ) /*0x11984e*/
      *(_BYTE *)(a2 + 12) |= 0x20u; /*0x119850*/
    else
      *(_DWORD *)(a2 + 12) &= ~0x20u; /*0x119858*/
    *(_DWORD *)(a2 + 12) &= ~0x80u; /*0x11985c*/
    return 0; /*0x119863*/
  }
  return result; /*0x119868*/
}
