/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17cabc. */
int __cdecl vnode_pager_findpage(int a1, _BYTE *a2)
{
  int v3; // esi
  int v4; // eax
  int i; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // [esp+Ch] [ebp-8h]

  if ( !a1 ) /*0x17cac9*/
  {
    if ( (int *)dword_1E7288 == &dword_1E7288 ) /*0x17cad5*/
      return 5; /*0x17cc1f*/
    a1 = dword_1E7288; /*0x17caf8*/
  }
  v3 = a1; /*0x17cafb*/
  while ( 1 ) /*0x17cb04*/
  {
    lock_write(v3 + 52); /*0x17cb04*/
    if ( *(_DWORD *)(v3 + 24) ) /*0x17cb0c*/
    {
      i = 0; /*0x17cb24*/
      v10 = *(_DWORD *)(v3 + 36) / 8; /*0x17cb33*/
      v6 = *(_DWORD *)(v3 + 20); /*0x17cb36*/
      while ( 1 ) /*0x17cb3c*/
      {
        v7 = v6 + 7; /*0x17cb3c*/
        if ( v6 + 7 < 0 ) /*0x17cb41*/
          v7 = v6 + 14; /*0x17cb43*/
        if ( v10 >= v7 >> 3 ) /*0x17cb4c*/
          break; /*0x17cb4c*/
        if ( *(_BYTE *)(v10 + *(_DWORD *)(v3 + 16)) != 0xFF ) /*0x17cb58*/
        {
          for ( i = 0; i <= 7; ++i ) /*0x17cb5a*/
          {
            v8 = *(char *)(i / 8 + *(_DWORD *)(v3 + 16) + v10); /*0x17cb7e*/
            if ( !_bittest(&v8, i % 8) ) /*0x17cb81*/
              break; /*0x17cb84*/
          }
          break; /*0x17cb8a*/
        }
        ++v10; /*0x17cb90*/
      }
      v9 = i + 8 * v10; /*0x17cb98*/
      if ( *(_DWORD *)(v3 + 20) <= v9 ) /*0x17cba1*/
        panic(aVnodePagerAllo); /*0x17cba8*/
      if ( *(_DWORD *)(v3 + 32) < v9 ) /*0x17cbb3*/
        *(_DWORD *)(v3 + 32) = v9; /*0x17cbb5*/
      *(_BYTE *)(v9 / 8 + *(_DWORD *)(v3 + 16)) |= 1 << (v9 % 8); /*0x17cbe1*/
      --*(_DWORD *)(v3 + 24); /*0x17cbe4*/
      *(_DWORD *)(v3 + 36) = v9; /*0x17cbe7*/
      lock_done(v3 + 52); /*0x17cbee*/
      v4 = v9; /*0x17cbf3*/
    }
    else
    {
      lock_done(v3 + 52); /*0x17cb13*/
      v4 = -1; /*0x17cb18*/
    }
    if ( v4 != -1 ) /*0x17cbfb*/
      break; /*0x17cbfb*/
    if ( (int *)v3 == &dword_1E7288 ) /*0x17cc07*/
      v3 = dword_1E7288; /*0x17cc09*/
    else
      v3 = *(_DWORD *)v3; /*0x17cc14*/
    if ( a1 == v3 ) /*0x17cc19*/
      return 5; /*0x17cc19*/
  }
  *a2 = *(_BYTE *)(v3 + 48); /*0x17cae2*/
  *(_DWORD *)a2 = (v4 << 8) | (unsigned __int8)*a2; /*0x17caee*/
  return 0; /*0x17cc27*/
}
