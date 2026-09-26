/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150bac. */
_DWORD *__cdecl ipc_splay_tree_insert(int a1, unsigned int a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // edx
  _DWORD *v6; // ebx
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // ebx
  unsigned int v10; // ecx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  _DWORD *result; // eax
  _DWORD *v14; // [esp+Ch] [ebp-14h]
  _DWORD *v15; // [esp+10h] [ebp-10h]
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = *(_DWORD **)(a1 + 4); /*0x150bb8*/
  v16 = v3; /*0x150bbb*/
  if ( v3 ) /*0x150bc0*/
  {
    if ( *(_DWORD *)a1 != a2 ) /*0x150be0*/
    {
      v4 = *(_DWORD **)(a1 + 20); /*0x150be9*/
      **(_DWORD **)(a1 + 12) = v3[6]; /*0x150bef*/
      *v4 = v3[7]; /*0x150bf7*/
      v3[6] = *(_DWORD *)(a1 + 8); /*0x150bff*/
      v3[7] = *(_DWORD *)(a1 + 16); /*0x150c08*/
      v5 = v3; /*0x150c0b*/
      v14 = (_DWORD *)(a1 + 8); /*0x150c13*/
      v15 = (_DWORD *)(a1 + 16); /*0x150c25*/
      while ( 1 ) /*0x150cd5*/
      {
        v12 = v5[4]; /*0x150cd5*/
        if ( a2 == v12 ) /*0x150cdb*/
          break; /*0x150cdb*/
        if ( a2 >= v12 ) /*0x150c3b*/
        {
          v9 = (_DWORD *)v5[7]; /*0x150c8c*/
          if ( !v9 ) /*0x150c91*/
            break; /*0x150c91*/
          v10 = v9[4]; /*0x150c93*/
          if ( a2 > v10 && v9[7] ) /*0x150c9b*/
          {
            v11 = v5; /*0x150ca1*/
            v5 = (_DWORD *)v5[7]; /*0x150ca3*/
            v11[7] = v9[6]; /*0x150ca8*/
            v9[6] = v11; /*0x150cab*/
          }
          *v14 = v5; /*0x150cb1*/
          v14 = v5 + 7; /*0x150cb6*/
          v5 = (_DWORD *)v5[7]; /*0x150cb9*/
          if ( a2 < v10 && v9[6] ) /*0x150cc1*/
          {
            *v15 = v5; /*0x150cca*/
            v15 = v5 + 6; /*0x150ccf*/
            v5 = (_DWORD *)v5[6]; /*0x150cd2*/
          }
        }
        else
        {
          v6 = (_DWORD *)v5[6]; /*0x150c3d*/
          if ( !v6 ) /*0x150c42*/
            break; /*0x150c42*/
          v7 = v6[4]; /*0x150c48*/
          if ( a2 < v7 && v6[6] ) /*0x150c50*/
          {
            v8 = v5; /*0x150c56*/
            v5 = (_DWORD *)v5[6]; /*0x150c58*/
            v8[6] = v6[7]; /*0x150c5d*/
            v6[7] = v8; /*0x150c60*/
          }
          *v15 = v5; /*0x150c66*/
          v15 = v5 + 6; /*0x150c6b*/
          v5 = (_DWORD *)v5[6]; /*0x150c6e*/
          if ( a2 > v7 && v6[7] ) /*0x150c76*/
          {
            *v14 = v5; /*0x150c7f*/
            v14 = v5 + 7; /*0x150c84*/
            v5 = (_DWORD *)v5[7]; /*0x150c87*/
          }
        }
      }
      v16 = v5; /*0x150ce1*/
      *(_DWORD *)(a1 + 12) = v14; /*0x150cea*/
      *(_DWORD *)(a1 + 20) = v15; /*0x150cf2*/
    }
    if ( v16[4] <= a2 ) /*0x150cfd*/
    {
      **(_DWORD **)(a1 + 12) = v16; /*0x150d1e*/
      result = *(_DWORD **)(a1 + 20); /*0x150d20*/
      *result = 0; /*0x150d23*/
    }
    else
    {
      **(_DWORD **)(a1 + 12) = 0; /*0x150d05*/
      result = *(_DWORD **)(a1 + 20); /*0x150d0b*/
      *result = v16; /*0x150d11*/
    }
    a3[6] = *(_DWORD *)(a1 + 8); /*0x150d32*/
    a3[7] = *(_DWORD *)(a1 + 16); /*0x150d3e*/
  }
  else
  {
    a3[6] = 0; /*0x150bc5*/
    a3[7] = 0; /*0x150bcc*/
  }
  a3[4] = a2; /*0x150d47*/
  *(_DWORD *)(a1 + 4) = a3; /*0x150d4d*/
  *(_DWORD *)a1 = a2; /*0x150d53*/
  *(_DWORD *)(a1 + 12) = a1 + 8; /*0x150d5b*/
  *(_DWORD *)(a1 + 20) = a1 + 16; /*0x150d64*/
  return result; /*0x150d6a*/
}
