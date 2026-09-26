/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151060. */
int __cdecl ipc_splay_tree_split(int a1, unsigned int a2, _DWORD *a3)
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
  int result; // eax
  _DWORD *v14; // [esp+Ch] [ebp-14h]
  _DWORD *v15; // [esp+10h] [ebp-10h]
  _DWORD *v16; // [esp+1Ch] [ebp-4h]
  int v17; // [esp+1Ch] [ebp-4h]
  int v18; // [esp+1Ch] [ebp-4h]

  a3[1] = 0; /*0x15106c*/
  v3 = *(_DWORD **)(a1 + 4); /*0x151076*/
  v16 = v3; /*0x151079*/
  if ( v3 ) /*0x15107e*/
  {
    if ( *(_DWORD *)a1 != a2 ) /*0x151089*/
    {
      v4 = *(_DWORD **)(a1 + 20); /*0x151092*/
      **(_DWORD **)(a1 + 12) = v3[6]; /*0x151098*/
      *v4 = v3[7]; /*0x1510a0*/
      v3[6] = *(_DWORD *)(a1 + 8); /*0x1510a8*/
      v3[7] = *(_DWORD *)(a1 + 16); /*0x1510b1*/
      v5 = v3; /*0x1510b4*/
      v14 = (_DWORD *)(a1 + 8); /*0x1510bc*/
      v15 = (_DWORD *)(a1 + 16); /*0x1510ce*/
      while ( 1 ) /*0x15117d*/
      {
        v12 = v5[4]; /*0x15117d*/
        if ( a2 == v12 ) /*0x151183*/
          break; /*0x151183*/
        if ( a2 >= v12 ) /*0x1510e3*/
        {
          v9 = (_DWORD *)v5[7]; /*0x151134*/
          if ( !v9 ) /*0x151139*/
            break; /*0x151139*/
          v10 = v9[4]; /*0x15113b*/
          if ( a2 > v10 && v9[7] ) /*0x151143*/
          {
            v11 = v5; /*0x151149*/
            v5 = (_DWORD *)v5[7]; /*0x15114b*/
            v11[7] = v9[6]; /*0x151150*/
            v9[6] = v11; /*0x151153*/
          }
          *v14 = v5; /*0x151159*/
          v14 = v5 + 7; /*0x15115e*/
          v5 = (_DWORD *)v5[7]; /*0x151161*/
          if ( a2 < v10 && v9[6] ) /*0x151169*/
          {
            *v15 = v5; /*0x151172*/
            v15 = v5 + 6; /*0x151177*/
            v5 = (_DWORD *)v5[6]; /*0x15117a*/
          }
        }
        else
        {
          v6 = (_DWORD *)v5[6]; /*0x1510e5*/
          if ( !v6 ) /*0x1510ea*/
            break; /*0x1510ea*/
          v7 = v6[4]; /*0x1510f0*/
          if ( a2 < v7 && v6[6] ) /*0x1510f8*/
          {
            v8 = v5; /*0x1510fe*/
            v5 = (_DWORD *)v5[6]; /*0x151100*/
            v8[6] = v6[7]; /*0x151105*/
            v6[7] = v8; /*0x151108*/
          }
          *v15 = v5; /*0x15110e*/
          v15 = v5 + 6; /*0x151113*/
          v5 = (_DWORD *)v5[6]; /*0x151116*/
          if ( a2 > v7 && v6[7] ) /*0x15111e*/
          {
            *v14 = v5; /*0x151127*/
            v14 = v5 + 7; /*0x15112c*/
            v5 = (_DWORD *)v5[7]; /*0x15112f*/
          }
        }
      }
      v16 = v5; /*0x151189*/
      *(_DWORD *)(a1 + 12) = v14; /*0x151192*/
      *(_DWORD *)(a1 + 20) = v15; /*0x15119a*/
    }
    if ( v16[4] >= a2 ) /*0x1511a5*/
    {
      **(_DWORD **)(a1 + 12) = v16[6]; /*0x151219*/
      v16[6] = 0; /*0x15121e*/
      *(_DWORD *)(a1 + 4) = v16; /*0x151225*/
      *(_DWORD *)a1 = a2; /*0x15122b*/
      *(_DWORD *)(a1 + 12) = a1 + 8; /*0x151233*/
      v18 = *(_DWORD *)(a1 + 8); /*0x151239*/
      a3[1] = v18; /*0x15123f*/
      result = v18; /*0x151242*/
      if ( v18 ) /*0x151247*/
      {
        result = *(_DWORD *)(v18 + 16); /*0x151249*/
        *a3 = result; /*0x15124c*/
        a3[3] = a3 + 2; /*0x151254*/
        a3[5] = a3 + 4; /*0x15125d*/
      }
    }
    else
    {
      **(_DWORD **)(a1 + 12) = v16[6]; /*0x1511b0*/
      **(_DWORD **)(a1 + 20) = 0; /*0x1511b5*/
      v16[6] = *(_DWORD *)(a1 + 8); /*0x1511c1*/
      a3[1] = v16; /*0x1511c7*/
      *a3 = v16[4]; /*0x1511cd*/
      a3[3] = a3 + 2; /*0x1511d5*/
      a3[5] = a3 + 4; /*0x1511de*/
      v17 = *(_DWORD *)(a1 + 16); /*0x1511e7*/
      *(_DWORD *)(a1 + 4) = v17; /*0x1511ed*/
      result = v17; /*0x1511f0*/
      if ( v17 ) /*0x1511f5*/
      {
        result = *(_DWORD *)(v17 + 16); /*0x1511f7*/
        *(_DWORD *)a1 = result; /*0x1511fa*/
        *(_DWORD *)(a1 + 12) = a1 + 8; /*0x151202*/
        *(_DWORD *)(a1 + 20) = a1 + 16; /*0x15120b*/
      }
    }
  }
  return result; /*0x151263*/
}
