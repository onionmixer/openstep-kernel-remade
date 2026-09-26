/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150d74. */
_DWORD *__cdecl ipc_splay_tree_delete(int a1, unsigned int a2)
{
  _DWORD *v2; // edx
  _DWORD *v3; // edx
  _DWORD *v4; // ebx
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  unsigned int v10; // ecx
  _DWORD *v11; // edx
  _DWORD *v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // ecx
  _DWORD *result; // eax
  _DWORD *v16; // [esp+Ch] [ebp-20h]
  _DWORD *v17; // [esp+Ch] [ebp-20h]
  _DWORD *v18; // [esp+10h] [ebp-1Ch]
  int v19; // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]
  _DWORD *v21; // [esp+28h] [ebp-4h]

  v20 = *(_DWORD **)(a1 + 4); /*0x150d83*/
  if ( *(_DWORD *)a1 != a2 ) /*0x150d8b*/
  {
    v2 = *(_DWORD **)(a1 + 20); /*0x150d94*/
    **(_DWORD **)(a1 + 12) = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 24); /*0x150d9a*/
    *v2 = v20[7]; /*0x150da2*/
    v20[6] = *(_DWORD *)(a1 + 8); /*0x150daa*/
    v20[7] = *(_DWORD *)(a1 + 16); /*0x150db3*/
    v3 = v20; /*0x150db6*/
    v16 = (_DWORD *)(a1 + 8); /*0x150dbe*/
    v18 = (_DWORD *)(a1 + 16); /*0x150dd0*/
    while ( 1 ) /*0x150e81*/
    {
      v10 = v3[4]; /*0x150e81*/
      if ( a2 == v10 ) /*0x150e87*/
        break; /*0x150e87*/
      if ( a2 >= v10 ) /*0x150de7*/
      {
        v7 = (_DWORD *)v3[7]; /*0x150e38*/
        if ( !v7 ) /*0x150e3d*/
          break; /*0x150e3d*/
        v8 = v7[4]; /*0x150e3f*/
        if ( a2 > v8 && v7[7] ) /*0x150e47*/
        {
          v9 = v3; /*0x150e4d*/
          v3 = (_DWORD *)v3[7]; /*0x150e4f*/
          v9[7] = v7[6]; /*0x150e54*/
          v7[6] = v9; /*0x150e57*/
        }
        *v16 = v3; /*0x150e5d*/
        v16 = v3 + 7; /*0x150e62*/
        v3 = (_DWORD *)v3[7]; /*0x150e65*/
        if ( a2 < v8 && v7[6] ) /*0x150e6d*/
        {
          *v18 = v3; /*0x150e76*/
          v18 = v3 + 6; /*0x150e7b*/
          v3 = (_DWORD *)v3[6]; /*0x150e7e*/
        }
      }
      else
      {
        v4 = (_DWORD *)v3[6]; /*0x150de9*/
        if ( !v4 ) /*0x150dee*/
          break; /*0x150dee*/
        v5 = v4[4]; /*0x150df4*/
        if ( a2 < v5 && v4[6] ) /*0x150dfc*/
        {
          v6 = v3; /*0x150e02*/
          v3 = (_DWORD *)v3[6]; /*0x150e04*/
          v6[6] = v4[7]; /*0x150e09*/
          v4[7] = v6; /*0x150e0c*/
        }
        *v18 = v3; /*0x150e12*/
        v18 = v3 + 6; /*0x150e17*/
        v3 = (_DWORD *)v3[6]; /*0x150e1a*/
        if ( a2 > v5 && v4[7] ) /*0x150e22*/
        {
          *v16 = v3; /*0x150e2b*/
          v16 = v3 + 7; /*0x150e30*/
          v3 = (_DWORD *)v3[7]; /*0x150e33*/
        }
      }
    }
    v20 = v3; /*0x150e8d*/
    *(_DWORD *)(a1 + 12) = v16; /*0x150e96*/
    *(_DWORD *)(a1 + 20) = v18; /*0x150e9e*/
  }
  **(_DWORD **)(a1 + 12) = v20[6]; /*0x150eac*/
  **(_DWORD **)(a1 + 20) = v20[7]; /*0x150eb7*/
  zfree(ipc_tree_entry_zone, v20); /*0x150ec4*/
  v21 = *(_DWORD **)(a1 + 8); /*0x150ecf*/
  v19 = *(_DWORD *)(a1 + 16); /*0x150ed8*/
  if ( v21 ) /*0x150ee0*/
  {
    if ( v19 ) /*0x150ef0*/
    {
      v11 = *(_DWORD **)(a1 + 8); /*0x150ef6*/
      v17 = (_DWORD *)(a1 + 8); /*0x150efe*/
      if ( v21[4] != -1 ) /*0x150f26*/
      {
        do /*0x150fe3*/
        {
          v12 = (_DWORD *)v11[7]; /*0x150f88*/
          if ( !v12 ) /*0x150f8d*/
            break; /*0x150f8d*/
          if ( v12[4] != -1 && v12[7] ) /*0x150f9b*/
          {
            v13 = v11; /*0x150fa1*/
            v11 = (_DWORD *)v11[7]; /*0x150fa3*/
            v13[7] = v12[6]; /*0x150fa8*/
            v12[6] = v13; /*0x150fab*/
          }
          *v17 = v11; /*0x150fb1*/
          v17 = v11 + 7; /*0x150fb6*/
          v11 = (_DWORD *)v11[7]; /*0x150fb9*/
        }
        while ( v11[4] != -1 ); /*0x150fe3*/
      }
      v21 = v11; /*0x150fe9*/
      *(_DWORD *)(a1 + 12) = v17; /*0x150ff2*/
      *(_DWORD *)(a1 + 20) = a1 + 16; /*0x150ffa*/
      v14 = *(_DWORD **)(a1 + 20); /*0x151005*/
      **(_DWORD **)(a1 + 12) = v11[6]; /*0x15100b*/
      *v14 = v11[7]; /*0x151010*/
      v11[6] = *(_DWORD *)(a1 + 8); /*0x151018*/
      v11[7] = *(_DWORD *)(a1 + 16); /*0x151021*/
      v11[7] = v19; /*0x15102a*/
    }
  }
  else
  {
    v21 = *(_DWORD **)(a1 + 16); /*0x150ee2*/
  }
  *(_DWORD *)(a1 + 4) = v21; /*0x151033*/
  result = v21; /*0x151036*/
  if ( v21 ) /*0x15103b*/
  {
    result = (_DWORD *)v21[4]; /*0x15103d*/
    *(_DWORD *)a1 = result; /*0x151040*/
    *(_DWORD *)(a1 + 12) = a1 + 8; /*0x151048*/
    *(_DWORD *)(a1 + 20) = a1 + 16; /*0x151051*/
  }
  return result; /*0x151057*/
}
