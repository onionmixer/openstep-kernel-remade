/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151670. */
_DWORD *__cdecl ipc_splay_traverse_next(_DWORD *a1, int a2)
{
  _DWORD *v2; // edx
  int v3; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  _DWORD *v11; // edx
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  int *v14; // [esp+10h] [ebp-20h]
  _DWORD *v15; // [esp+14h] [ebp-1Ch]
  _DWORD *v16; // [esp+18h] [ebp-18h]
  int v17; // [esp+20h] [ebp-10h]
  int v18; // [esp+28h] [ebp-8h] BYREF
  _DWORD *v19; // [esp+2Ch] [ebp-4h]

  v2 = (_DWORD *)a1[2]; /*0x15167c*/
  v19 = v2; /*0x15167f*/
  v16 = (_DWORD *)a1[4]; /*0x151685*/
  if ( !a2 ) /*0x15168c*/
    goto LABEL_22; /*0x15168c*/
  v3 = v2[6]; /*0x151692*/
  if ( v3 ) /*0x151697*/
  {
    if ( !v2[7] ) /*0x151738*/
    {
      v19 = (_DWORD *)v2[6]; /*0x15173e*/
      zfree(ipc_tree_entry_zone, v2); /*0x151749*/
      goto LABEL_25; /*0x15174e*/
    }
    v15 = v2; /*0x151754*/
    v6 = (_DWORD *)v2[6]; /*0x151757*/
    v14 = &v18; /*0x15175c*/
    if ( *(_DWORD *)(v3 + 16) != -1 ) /*0x15176f*/
    {
      do /*0x15182f*/
      {
        v7 = (_DWORD *)v6[7]; /*0x1517d4*/
        if ( !v7 ) /*0x1517d9*/
          break; /*0x1517d9*/
        if ( v7[4] != -1 ) /*0x1517e5*/
        {
          if ( v7[7] ) /*0x1517e7*/
          {
            v8 = v6; /*0x1517ed*/
            v6 = (_DWORD *)v6[7]; /*0x1517ef*/
            v8[7] = v7[6]; /*0x1517f4*/
            v7[6] = v8; /*0x1517f7*/
          }
        }
        *v14 = (int)v6; /*0x1517fd*/
        v14 = v6 + 7; /*0x151802*/
        v6 = (_DWORD *)v6[7]; /*0x151805*/
      }
      while ( v6[4] != -1 ); /*0x15182f*/
    }
    v19 = v6; /*0x151835*/
    *v14 = v6[6]; /*0x151847*/
    v17 = v6[7]; /*0x15184f*/
    v6[6] = v18; /*0x151854*/
    v6[7] = v17; /*0x15185a*/
    v19[7] = v15[7]; /*0x151866*/
    zfree(ipc_tree_entry_zone, v15); /*0x151874*/
LABEL_22:
    v9 = v19; /*0x1518a4*/
    v10 = (_DWORD *)v19[7]; /*0x1518a7*/
    if ( v10 ) /*0x1518ac*/
    {
      v19[7] = v16; /*0x1518b1*/
      goto LABEL_24; /*0x1518b1*/
    }
    while ( 1 ) /*0x1518bc*/
    {
LABEL_25:
      if ( !v16 ) /*0x1518c0*/
      {
        a1[1] = v19; /*0x1518c8*/
        return nullptr; /*0x1518cd*/
      }
      v11 = v19; /*0x1518d0*/
      if ( v19[4] < v16[4] ) /*0x1518dc*/
        break; /*0x1518dc*/
      v19 = v16; /*0x1518f3*/
      v13 = v16; /*0x1518f6*/
      v16 = (_DWORD *)v16[7]; /*0x1518fc*/
      v13[7] = v11; /*0x1518ff*/
    }
    v19 = v16; /*0x1518de*/
    v12 = v16; /*0x1518e1*/
    v16 = (_DWORD *)v16[6]; /*0x1518e7*/
    v12[6] = v11; /*0x1518ea*/
    goto LABEL_21; /*0x1518ed*/
  }
  if ( v2[7] ) /*0x15169d*/
  {
    v19 = (_DWORD *)v2[7]; /*0x151720*/
    zfree(ipc_tree_entry_zone, v2); /*0x15172b*/
    while ( 1 ) /*0x15187c*/
    {
      v9 = v19; /*0x15187c*/
      v10 = (_DWORD *)v19[6]; /*0x15187f*/
      if ( !v10 ) /*0x151884*/
        break; /*0x151884*/
      v19[6] = v16; /*0x151889*/
LABEL_24:
      v16 = v9; /*0x1518b4*/
      v19 = v10; /*0x1518b7*/
    }
  }
  else
  {
    if ( !a1[4] ) /*0x151682*/
    {
      zfree(ipc_tree_entry_zone, v2); /*0x1516b0*/
      a1[1] = 0; /*0x1516b8*/
      return nullptr; /*0x1516c1*/
    }
    if ( v2[4] >= v16[4] ) /*0x1516d1*/
    {
      zfree(ipc_tree_entry_zone, v2); /*0x151700*/
      v19 = v16; /*0x151708*/
      v16 = (_DWORD *)v16[7]; /*0x151711*/
      v19[7] = 0; /*0x151714*/
      goto LABEL_25; /*0x15171b*/
    }
    zfree(ipc_tree_entry_zone, v2); /*0x1516db*/
    v5 = v16; /*0x1516e0*/
    v19 = v16; /*0x1516e3*/
    v16 = (_DWORD *)v16[6]; /*0x1516e9*/
    v5[6] = 0; /*0x1516ec*/
  }
LABEL_21:
  a1[2] = v19; /*0x151890*/
  a1[4] = v16; /*0x15189c*/
  return v19; /*0x151907*/
}
