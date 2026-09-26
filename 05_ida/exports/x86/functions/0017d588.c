/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d588. */
int __cdecl vnode_pager_file_init(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  int result; // eax
  unsigned int v5; // esi
  _DWORD *v6; // esi
  int v7; // eax
  unsigned int v8; // eax
  int v9; // edx
  int v10; // eax
  int i; // ebx
  int v12; // eax
  _WORD *v13; // [esp+Ch] [ebp-8Ch]
  int v14; // [esp+10h] [ebp-88h]
  _BYTE v15[4]; // [esp+18h] [ebp-80h] BYREF
  int v16; // [esp+1Ch] [ebp-7Ch]
  int v17; // [esp+20h] [ebp-78h]
  _BYTE v18[24]; // [esp+58h] [ebp-40h] BYREF
  unsigned int v19; // [esp+70h] [ebp-28h]

  *a1 = 0; /*0x17d597*/
  mfs_uncache((int *)a2); /*0x17d5a1*/
  if ( (*(_BYTE *)(*(_DWORD *)a2 + 56) & 0x10) != 0 ) /*0x17d5af*/
    return 16; /*0x17d5b6*/
  v13 = *(_WORD **)(active_u + 28); /*0x17d5c4*/
  (*(void (__cdecl **)(int, _BYTE *, _WORD *))(*(_DWORD *)(a2 + 28) + 20))(a2, v18, v13); /*0x17d5df*/
  v5 = v19; /*0x17d5e1*/
  if ( a3 >= v19 /*0x17d60b*/
    || (vattr_null(v18),
        v5 = a3,
        v19 = a3,
        (result = (*(int (__cdecl **)(int, _BYTE *, _WORD *))(*(_DWORD *)(a2 + 28) + 24))(a2, v18, v13)) == 0) )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = v5; /*0x17d616*/
    v6 = (_DWORD *)kalloc(0x40u); /*0x17d620*/
    ++*(_WORD *)(a2 + 6); /*0x17d622*/
    v6[2] = a2; /*0x17d626*/
    ++*v13; /*0x17d62f*/
    *(_DWORD *)(*(_DWORD *)a2 + 48) = v13; /*0x17d634*/
    v6[3] = 0; /*0x17d637*/
    v6[9] = 0; /*0x17d63e*/
    v6[7] = (~page_mask & (page_mask + a3)) >> page_shift; /*0x17d65c*/
    if ( !a4 ) /*0x17d666*/
    {
      v7 = (*(int (__cdecl **)(_DWORD, _BYTE *))(*(_DWORD *)(*(_DWORD *)(a2 + 36) + 4) + 12))(*(_DWORD *)(a2 + 36), v15); /*0x17d676*/
      if ( v7 ) /*0x17d67d*/
      {
        v14 = v7; /*0x17d682*/
        kfree((int)v6, 0x40u); /*0x17d688*/
        return v14; /*0x17d693*/
      }
      a4 = v16 * v17; /*0x17d69f*/
    }
    v8 = a4 >> page_shift; /*0x17d6ab*/
    v6[5] = a4 >> page_shift; /*0x17d6ad*/
    v6[6] = v8; /*0x17d6b0*/
    v9 = v6[5]; /*0x17d6b3*/
    v10 = v9 + 7; /*0x17d6b6*/
    if ( v9 + 7 < 0 ) /*0x17d6bb*/
      v10 = v9 + 14; /*0x17d6bd*/
    v6[4] = kalloc(v10 >> 3); /*0x17d6c9*/
    for ( i = 0; v6[5] > i; ++i ) /*0x17d6d4*/
      *(_BYTE *)(i / 8 + v6[4]) &= __ROL4__(-2, i % 8); /*0x17d701*/
    v6[8] = -1; /*0x17d70a*/
    v6[11] = 0; /*0x17d711*/
    lock_init(v6 + 13, 1); /*0x17d71e*/
    v12 = dword_1E728C; /*0x17d723*/
    if ( (int *)dword_1E728C == &dword_1E7288 ) /*0x17d72d*/
      dword_1E7288 = (int)v6; /*0x17d72f*/
    else
      *(_DWORD *)dword_1E728C = v6; /*0x17d738*/
    v6[1] = v12; /*0x17d73a*/
    *v6 = &dword_1E7288; /*0x17d73d*/
    dword_1E728C = (int)v6; /*0x17d743*/
    v6[12] = ++dword_1E7290; /*0x17d755*/
    dword_1E7294[dword_1E7290] = (int)v6; /*0x17d75d*/
    *a1 = v6; /*0x17d767*/
    return 0; /*0x17d769*/
  }
  return result; /*0x17d771*/
}
