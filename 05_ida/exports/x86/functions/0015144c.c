/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15144c. */
_DWORD *__cdecl ipc_splay_tree_bounds(int a1, unsigned int a2, unsigned int *a3, unsigned int *a4)
{
  _DWORD *v4; // ecx
  _DWORD *v5; // edx
  _DWORD *v6; // edx
  _DWORD *v7; // ebx
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ebx
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  _DWORD *result; // eax
  unsigned int v15; // ecx
  int v16; // edx
  int v17; // edx
  _DWORD *v18; // [esp+Ch] [ebp-14h]
  _DWORD *v19; // [esp+10h] [ebp-10h]
  _DWORD *v20; // [esp+1Ch] [ebp-4h]

  v4 = *(_DWORD **)(a1 + 4); /*0x151458*/
  v20 = v4; /*0x15145b*/
  if ( v4 ) /*0x151460*/
  {
    if ( *(_DWORD *)a1 != a2 ) /*0x151484*/
    {
      v5 = *(_DWORD **)(a1 + 20); /*0x15148d*/
      **(_DWORD **)(a1 + 12) = v4[6]; /*0x151493*/
      *v5 = v4[7]; /*0x15149b*/
      v4[6] = *(_DWORD *)(a1 + 8); /*0x1514a3*/
      v4[7] = *(_DWORD *)(a1 + 16); /*0x1514ac*/
      v6 = v4; /*0x1514af*/
      v18 = (_DWORD *)(a1 + 8); /*0x1514b7*/
      v19 = (_DWORD *)(a1 + 16); /*0x1514c9*/
      while ( 1 ) /*0x151579*/
      {
        v13 = v6[4]; /*0x151579*/
        if ( a2 == v13 ) /*0x15157f*/
          break; /*0x15157f*/
        if ( a2 >= v13 ) /*0x1514df*/
        {
          v10 = (_DWORD *)v6[7]; /*0x151530*/
          if ( !v10 ) /*0x151535*/
            break; /*0x151535*/
          v11 = v10[4]; /*0x151537*/
          if ( a2 > v11 && v10[7] ) /*0x15153f*/
          {
            v12 = v6; /*0x151545*/
            v6 = (_DWORD *)v6[7]; /*0x151547*/
            v12[7] = v10[6]; /*0x15154c*/
            v10[6] = v12; /*0x15154f*/
          }
          *v18 = v6; /*0x151555*/
          v18 = v6 + 7; /*0x15155a*/
          v6 = (_DWORD *)v6[7]; /*0x15155d*/
          if ( a2 < v11 && v10[6] ) /*0x151565*/
          {
            *v19 = v6; /*0x15156e*/
            v19 = v6 + 6; /*0x151573*/
            v6 = (_DWORD *)v6[6]; /*0x151576*/
          }
        }
        else
        {
          v7 = (_DWORD *)v6[6]; /*0x1514e1*/
          if ( !v7 ) /*0x1514e6*/
            break; /*0x1514e6*/
          v8 = v7[4]; /*0x1514ec*/
          if ( a2 < v8 && v7[6] ) /*0x1514f4*/
          {
            v9 = v6; /*0x1514fa*/
            v6 = (_DWORD *)v6[6]; /*0x1514fc*/
            v9[6] = v7[7]; /*0x151501*/
            v7[7] = v9; /*0x151504*/
          }
          *v19 = v6; /*0x15150a*/
          v19 = v6 + 6; /*0x15150f*/
          v6 = (_DWORD *)v6[6]; /*0x151512*/
          if ( a2 > v8 && v7[7] ) /*0x15151a*/
          {
            *v18 = v6; /*0x151523*/
            v18 = v6 + 7; /*0x151528*/
            v6 = (_DWORD *)v6[7]; /*0x15152b*/
          }
        }
      }
      v20 = v6; /*0x151585*/
      *(_DWORD *)(a1 + 12) = v18; /*0x15158e*/
      *(_DWORD *)(a1 + 20) = v19; /*0x151596*/
      *(_DWORD *)a1 = a2; /*0x15159e*/
      *(_DWORD *)(a1 + 4) = v6; /*0x1515a3*/
    }
    result = v20; /*0x1515a6*/
    v15 = v20[4]; /*0x1515a9*/
    if ( a2 < v15 ) /*0x1515af*/
    {
      result = (_DWORD *)(a1 + 8); /*0x1515bb*/
      v16 = *(_DWORD *)(a1 + 12); /*0x1515c1*/
      if ( v16 == a1 + 8 ) /*0x1515c6*/
        *a3 = -1; /*0x1515cb*/
      else
        *a3 = *(_DWORD *)(v16 - 12); /*0x1515da*/
    }
    else
    {
      *a3 = v15; /*0x1515b4*/
    }
    if ( a2 > v15 ) /*0x1515df*/
    {
      result = (_DWORD *)(a1 + 16); /*0x1515eb*/
      v17 = *(_DWORD *)(a1 + 20); /*0x1515f1*/
      if ( v17 == a1 + 16 ) /*0x1515f6*/
        *a4 = 0; /*0x1515fb*/
      else
        *a4 = *(_DWORD *)(v17 - 8); /*0x15160a*/
    }
    else
    {
      *a4 = v15; /*0x1515e4*/
    }
  }
  else
  {
    *a3 = -1; /*0x151465*/
    *a4 = 0; /*0x15146e*/
  }
  return result; /*0x15160f*/
}
