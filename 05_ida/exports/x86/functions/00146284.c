/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146284. */
unsigned int *__cdecl ipc_entry_dealloc(_DWORD *a1, unsigned int a2, int *a3)
{
  int v3; // ebx
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // ebx
  unsigned int *result; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // ebx
  unsigned int v10; // edx
  int v11; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-58h]
  int v15; // [esp+10h] [ebp-54h]
  _DWORD *v16; // [esp+20h] [ebp-44h]
  unsigned int v17; // [esp+28h] [ebp-3Ch]
  _DWORD *v18; // [esp+2Ch] [ebp-38h] BYREF
  int v19; // [esp+30h] [ebp-34h] BYREF
  unsigned int v20; // [esp+34h] [ebp-30h] BYREF
  _DWORD v21[5]; // [esp+38h] [ebp-2Ch] BYREF
  _BYTE v22[24]; // [esp+4Ch] [ebp-18h] BYREF

  v14 = a2 >> 8; /*0x146296*/
  v3 = a1[5]; /*0x14629c*/
  v17 = a1[6]; /*0x1462a2*/
  if ( a2 >> 8 < v17 && a3 == (int *)(v3 + 16 * v14) ) /*0x1462b8*/
  {
    if ( (*a3 & 0x800000) != 0 ) /*0x1462c5*/
    {
      v16 = a1 + 8; /*0x1462e0*/
      ipc_splay_tree_split(a1 + 8, (v14 + 1) << 8, &v20); /*0x1462e4*/
      ipc_splay_tree_split(&v20, v14 << 8, v22); /*0x1462fb*/
      ipc_splay_tree_pick(&v20, &v19, &v18); /*0x146312*/
      v4 = v18; /*0x146317*/
      v5 = *v18; /*0x14631a*/
      v15 = v19; /*0x14631f*/
      *a3 = *v18 | (v19 << 24); /*0x146329*/
      v6 = v4[1]; /*0x14632b*/
      a3[1] = v6; /*0x14632e*/
      a3[2] = v4[2]; /*0x146334*/
      if ( (v5 & 0x1F0000) == 0x10000 ) /*0x146346*/
      {
        ipc_hash_global_delete(a1, v6, v15, v4); /*0x146352*/
        ipc_hash_local_insert(a1, v6, v14); /*0x146361*/
      }
      ipc_splay_tree_delete(&v20, v19); /*0x146375*/
      --a1[14]; /*0x14637d*/
      if ( ipc_splay_tree_pick(&v20, &v19, &v18) ) /*0x14638c*/
      {
        *a3 |= 0x800000u; /*0x146398*/
        ipc_splay_tree_join(v16, &v20); /*0x1463a3*/
      }
      return (unsigned int *)ipc_splay_tree_join(v16, v22); /*0x1463b3*/
    }
    else
    {
      result = (unsigned int *)(*a3 & 0xFF000000); /*0x1463c0*/
      *a3 = (int)result; /*0x1463c5*/
      a3[2] = *(_DWORD *)(v3 + 8); /*0x1463ca*/
      *(_DWORD *)(v3 + 8) = v14; /*0x1463d0*/
    }
  }
  else
  {
    v8 = a1 + 8; /*0x1463e0*/
    ipc_splay_tree_delete(a1 + 8, a2); /*0x1463e4*/
    --a1[14]; /*0x1463ec*/
    if ( v14 >= v17 ) /*0x1463f8*/
    {
      result = (unsigned int *)a1[7]; /*0x14644f*/
      if ( *result > v14 ) /*0x146457*/
      {
        ipc_splay_tree_bounds(v8, a2, v21, &v20); /*0x146466*/
        v12 = a2 >> 8; /*0x14646e*/
        v13 = 0; /*0x146471*/
        if ( v21[0] != -1 && (result = (unsigned int *)(v21[0] >> 8), v21[0] >> 8 == v12) /*0x14648e*/
          || (result = (unsigned int *)v20) != nullptr && (result = (unsigned int *)(v20 >> 8), v20 >> 8 == v12) )
        {
          v13 = 1; /*0x146490*/
        }
        if ( !v13 ) /*0x146497*/
          --a1[15]; /*0x14649c*/
      }
    }
    else
    {
      v9 = (_DWORD *)(16 * v14 + v3); /*0x146400*/
      ipc_splay_tree_bounds(v8, a2, v21, &v20); /*0x14640f*/
      v10 = a2 >> 8; /*0x146417*/
      v11 = 0; /*0x14641a*/
      if ( v21[0] != -1 && (result = (unsigned int *)(v21[0] >> 8), v21[0] >> 8 == v10) /*0x146437*/
        || (result = (unsigned int *)v20) != nullptr && (result = (unsigned int *)(v20 >> 8), v20 >> 8 == v10) )
      {
        v11 = 1; /*0x146439*/
      }
      if ( !v11 ) /*0x146440*/
        *v9 &= ~0x800000u; /*0x146442*/
    }
  }
  return result; /*0x1464a2*/
}
