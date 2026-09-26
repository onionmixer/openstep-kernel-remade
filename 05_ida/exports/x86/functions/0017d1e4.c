/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d1e4. */
int __cdecl vnode_pager_setup(int a1, int a2, int a3)
{
  int *v3; // eax
  _WORD *v4; // eax
  _WORD *v5; // ebx
  int v6; // eax
  int v7; // eax

  if ( a2 ) /*0x17d1f0*/
    *(_BYTE *)(a1 + 4) |= 2u; /*0x17d1f2*/
  if ( **(_DWORD **)a1 ) /*0x17d1f8*/
    goto LABEL_14; /*0x17d1fb*/
  v3 = (int *)dword_1E7288; /*0x17d201*/
  if ( (int *)dword_1E7288 == &dword_1E7288 ) /*0x17d20b*/
  {
LABEL_7:
    v4 = (_WORD *)zalloc(vstruct_zone); /*0x17d222*/
    v5 = v4; /*0x17d22e*/
    if ( v4 ) /*0x17d235*/
    {
      bzero(v4, 0x18u); /*0x17d23a*/
      *(_DWORD *)v5 = 0; /*0x17d23f*/
      v5[7] = 1; /*0x17d245*/
      **(_DWORD **)a1 = v5; /*0x17d24d*/
      *((_DWORD *)v5 + 5) = a1; /*0x17d24f*/
      *((_BYTE *)v5 + 12) &= ~1u; /*0x17d252*/
      ++*(_WORD *)(a1 + 6); /*0x17d256*/
      do /*0x17d279*/
      {
        while ( vstruct_lock ) /*0x17d267*/
          ; /*0x17d265*/
      }
      while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d279*/
      --v5[7]; /*0x17d27b*/
      _InterlockedExchange(&vstruct_lock, 0); /*0x17d281*/
    }
    if ( a3 ) /*0x17d28b*/
    {
      v6 = vm_object_lookup(**(_DWORD **)a1); /*0x17d294*/
      vm_object_cache_object(v6, 1); /*0x17d29d*/
    }
LABEL_14:
    v7 = zalloc(vstruct_zone); /*0x17d2a5*/
    zfree(vstruct_zone, v7); /*0x17d2b9*/
    return **(_DWORD **)a1; /*0x17d2c2*/
  }
  while ( v3[2] != a1 ) /*0x17d213*/
  {
    v3 = (int *)*v3; /*0x17d219*/
    if ( v3 == &dword_1E7288 ) /*0x17d220*/
      goto LABEL_7; /*0x17d220*/
  }
  return 0; /*0x17d2c9*/
}
