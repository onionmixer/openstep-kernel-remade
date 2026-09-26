/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150a48. */
_DWORD *__cdecl ipc_splay_tree_lookup(int a1, unsigned int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  _DWORD *v4; // edx
  _DWORD *v5; // ebx
  unsigned int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // ebx
  unsigned int v9; // ecx
  _DWORD *v10; // eax
  unsigned int v11; // ecx
  _DWORD *v13; // [esp+Ch] [ebp-14h]
  _DWORD *v14; // [esp+10h] [ebp-10h]
  _DWORD *v15; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 4); /*0x150a54*/
  v15 = v2; /*0x150a57*/
  if ( v2 ) /*0x150a5c*/
  {
    if ( *(_DWORD *)a1 != a2 ) /*0x150a67*/
    {
      v3 = *(_DWORD **)(a1 + 20); /*0x150a70*/
      **(_DWORD **)(a1 + 12) = v2[6]; /*0x150a76*/
      *v3 = v2[7]; /*0x150a7e*/
      v2[6] = *(_DWORD *)(a1 + 8); /*0x150a86*/
      v2[7] = *(_DWORD *)(a1 + 16); /*0x150a8f*/
      v4 = v2; /*0x150a92*/
      v13 = (_DWORD *)(a1 + 8); /*0x150a9a*/
      v14 = (_DWORD *)(a1 + 16); /*0x150aac*/
      while ( 1 ) /*0x150b5d*/
      {
        v11 = v4[4]; /*0x150b5d*/
        if ( a2 == v11 ) /*0x150b63*/
          break; /*0x150b63*/
        if ( a2 >= v11 ) /*0x150ac3*/
        {
          v8 = (_DWORD *)v4[7]; /*0x150b14*/
          if ( !v8 ) /*0x150b19*/
            break; /*0x150b19*/
          v9 = v8[4]; /*0x150b1b*/
          if ( a2 > v9 && v8[7] ) /*0x150b23*/
          {
            v10 = v4; /*0x150b29*/
            v4 = (_DWORD *)v4[7]; /*0x150b2b*/
            v10[7] = v8[6]; /*0x150b30*/
            v8[6] = v10; /*0x150b33*/
          }
          *v13 = v4; /*0x150b39*/
          v13 = v4 + 7; /*0x150b3e*/
          v4 = (_DWORD *)v4[7]; /*0x150b41*/
          if ( a2 < v9 && v8[6] ) /*0x150b49*/
          {
            *v14 = v4; /*0x150b52*/
            v14 = v4 + 6; /*0x150b57*/
            v4 = (_DWORD *)v4[6]; /*0x150b5a*/
          }
        }
        else
        {
          v5 = (_DWORD *)v4[6]; /*0x150ac5*/
          if ( !v5 ) /*0x150aca*/
            break; /*0x150aca*/
          v6 = v5[4]; /*0x150ad0*/
          if ( a2 < v6 && v5[6] ) /*0x150ad8*/
          {
            v7 = v4; /*0x150ade*/
            v4 = (_DWORD *)v4[6]; /*0x150ae0*/
            v7[6] = v5[7]; /*0x150ae5*/
            v5[7] = v7; /*0x150ae8*/
          }
          *v14 = v4; /*0x150aee*/
          v14 = v4 + 6; /*0x150af3*/
          v4 = (_DWORD *)v4[6]; /*0x150af6*/
          if ( a2 > v6 && v5[7] ) /*0x150afe*/
          {
            *v13 = v4; /*0x150b07*/
            v13 = v4 + 7; /*0x150b0c*/
            v4 = (_DWORD *)v4[7]; /*0x150b0f*/
          }
        }
      }
      v15 = v4; /*0x150b69*/
      *(_DWORD *)(a1 + 12) = v13; /*0x150b72*/
      *(_DWORD *)(a1 + 20) = v14; /*0x150b7a*/
      *(_DWORD *)a1 = a2; /*0x150b82*/
      *(_DWORD *)(a1 + 4) = v4; /*0x150b87*/
    }
    if ( v15[4] != a2 ) /*0x150b93*/
      return nullptr; /*0x150b95*/
  }
  return v15; /*0x150ba2*/
}
