/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15126c. */
int __cdecl ipc_splay_tree_join(int a1, int a2)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edx
  _DWORD *v4; // ecx
  _DWORD *v5; // edx
  _DWORD *v6; // edx
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  int result; // eax
  _DWORD *i; // [esp+10h] [ebp-14h]
  _DWORD *v12; // [esp+20h] [ebp-4h]

  v2 = *(_DWORD **)(a2 + 4); /*0x151278*/
  if ( v2 ) /*0x151280*/
  {
    v3 = *(_DWORD **)(a2 + 20); /*0x151289*/
    **(_DWORD **)(a2 + 12) = v2[6]; /*0x15128f*/
    *v3 = v2[7]; /*0x151294*/
    v2[6] = *(_DWORD *)(a2 + 8); /*0x15129c*/
    v2[7] = *(_DWORD *)(a2 + 16); /*0x1512a2*/
    *(_DWORD *)(a2 + 4) = 0; /*0x1512a5*/
    v4 = *(_DWORD **)(a1 + 4); /*0x1512af*/
    v12 = v4; /*0x1512b2*/
    if ( v4 ) /*0x1512b7*/
    {
      if ( *(_DWORD *)a1 ) /*0x1512c7*/
      {
        v5 = *(_DWORD **)(a1 + 20); /*0x1512d3*/
        **(_DWORD **)(a1 + 12) = v4[6]; /*0x1512d9*/
        *v5 = v4[7]; /*0x1512e1*/
        v4[6] = *(_DWORD *)(a1 + 8); /*0x1512e9*/
        v4[7] = *(_DWORD *)(a1 + 16); /*0x1512ef*/
        v6 = v4; /*0x1512f2*/
        for ( i = (_DWORD *)(a1 + 16); v6[4]; v6 = (_DWORD *)v6[6] ) /*0x151318*/
        {
          v7 = (_DWORD *)v6[6]; /*0x15132e*/
          if ( !v7 ) /*0x151333*/
            break; /*0x151333*/
          if ( v7[4] ) /*0x151339*/
          {
            if ( v7[6] ) /*0x151340*/
            {
              v8 = v6; /*0x151346*/
              v6 = (_DWORD *)v6[6]; /*0x151348*/
              v8[6] = v7[7]; /*0x15134d*/
              v7[7] = v8; /*0x151350*/
            }
          }
          *i = v6; /*0x151356*/
          i = v6 + 6; /*0x15135b*/
        }
        v12 = v6; /*0x1513d8*/
        *(_DWORD *)(a1 + 12) = a1 + 8; /*0x1513e1*/
        *(_DWORD *)(a1 + 20) = i; /*0x1513e9*/
      }
      v9 = *(_DWORD **)(a1 + 20); /*0x1513f4*/
      **(_DWORD **)(a1 + 12) = v12[6]; /*0x1513fa*/
      *v9 = v12[7]; /*0x1513ff*/
      v12[6] = *(_DWORD *)(a1 + 8); /*0x151407*/
      v12[7] = *(_DWORD *)(a1 + 16); /*0x151410*/
      v12[6] = v2; /*0x151419*/
    }
    else
    {
      v12 = v2; /*0x1512bc*/
    }
    *(_DWORD *)(a1 + 4) = v12; /*0x151422*/
    result = v12[4]; /*0x151428*/
    *(_DWORD *)a1 = result; /*0x15142b*/
    *(_DWORD *)(a1 + 12) = a1 + 8; /*0x151433*/
    *(_DWORD *)(a1 + 20) = a1 + 16; /*0x15143c*/
  }
  return result; /*0x151442*/
}
