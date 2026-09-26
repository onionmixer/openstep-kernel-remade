/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d998. */
int *__cdecl vnode_alloc(int a1)
{
  int v1; // ebx
  int i; // eax
  int *j; // ecx
  int v4; // esi
  int *v5; // ebx
  unsigned int v6; // eax
  int v7; // eax
  void *v8; // edx
  int v9; // ecx
  int v10; // edx
  int v12; // [esp+Ch] [ebp-48h]
  int v13; // [esp+10h] [ebp-44h]

  v13 = 0; /*0x17d9a1*/
  v1 = 0; /*0x17d9a8*/
  v12 = 0; /*0x17d9aa*/
  if ( dword_1E7290 <= 1 ) /*0x17d9ba*/
  {
    if ( dword_1E7290 == 1 ) /*0x17da17*/
      v1 = dword_1E7288; /*0x17da19*/
  }
  else
  {
    for ( i = 0; i <= 3; ++i ) /*0x17d9bc*/
    {
      for ( j = (int *)dword_1E7288; j != &dword_1E7288; j = (int *)*j ) /*0x17d9cc*/
      {
        if ( (i > 1 || j[11]) && ((i & 1) != 0 || *(_UNKNOWN **)(j[2] + 28) == &ufs_vnodeops) && v12 < j[6] ) /*0x17d9f5*/
        {
          v12 = j[6]; /*0x17d9f7*/
          v1 = (int)j; /*0x17d9fa*/
        }
      }
      if ( v1 ) /*0x17da08*/
        break; /*0x17da08*/
    }
  }
  v4 = v1; /*0x17da1f*/
  if ( v1 ) /*0x17da23*/
  {
    v5 = zalloc_noblock(vstruct_zone); /*0x17da35*/
    if ( v5 ) /*0x17da3c*/
    {
      v6 = (~page_mask & (unsigned int)(page_mask + a1)) >> page_shift; /*0x17da62*/
      v5[4] = v6; /*0x17da64*/
      if ( v6 ) /*0x17da69*/
      {
        if ( 4 * v6 <= 0x40 ) /*0x17da82*/
          v7 = kalloc_noblock(4 * v6); /*0x17da95*/
        else
          v7 = kalloc_noblock(4 * ((v6 - 1) >> 4) + 4); /*0x17da90*/
        v5[2] = v7; /*0x17da9a*/
        v8 = (void *)v5[2]; /*0x17daa0*/
        if ( !v8 ) /*0x17daa5*/
        {
          zfree(vstruct_zone, v5); /*0x17daaf*/
          return nullptr; /*0x17dabb*/
        }
        v9 = v5[4]; /*0x17dac0*/
        if ( (unsigned int)(4 * v9) <= 0x40 ) /*0x17dacd*/
        {
          v10 = 0; /*0x17dae8*/
          if ( v9 > 0 ) /*0x17daec*/
          {
            do /*0x17dafb*/
              *(_BYTE *)(v5[2] + 4 * v10++) = 0; /*0x17daf3*/
            while ( v5[4] > v10 ); /*0x17dafb*/
          }
        }
        else
        {
          bzero(v8, 4 * ((unsigned int)(v9 - 1) >> 4) + 4); /*0x17dade*/
        }
      }
      else
      {
        v5[2] = 0; /*0x17da6b*/
      }
      *v5 = 0; /*0x17dafd*/
      *((_WORD *)v5 + 7) = 1; /*0x17db03*/
      v5[5] = *(_DWORD *)(v4 + 8); /*0x17db0c*/
      *((_BYTE *)v5 + 12) |= 1u; /*0x17db0f*/
      v5[1] = v4; /*0x17db13*/
      ++*(_DWORD *)(v4 + 12); /*0x17db16*/
      do /*0x17db35*/
      {
        while ( vstruct_lock ) /*0x17db23*/
          ; /*0x17db21*/
      }
      while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17db35*/
      --*((_WORD *)v5 + 7); /*0x17db37*/
      _InterlockedExchange(&vstruct_lock, 0); /*0x17db3d*/
      return v5; /*0x17db43*/
    }
    else
    {
      return nullptr; /*0x17da3e*/
    }
  }
  return (int *)v13; /*0x17db4c*/
}
