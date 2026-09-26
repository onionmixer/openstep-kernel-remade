/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c948. */
int __cdecl fatfile_getarch(int a1, int a2, _DWORD *a3)
{
  unsigned __int32 v3; // edi
  unsigned int v4; // edx
  unsigned int *v6; // esi
  int v7; // edx
  unsigned int *v8; // ebx
  unsigned __int32 v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h] BYREF

  v13 = vnode_pager_setup(a1, 0, 1); /*0x15c961*/
  v3 = _byteswap_ulong(*(_DWORD *)(a2 + 4)); /*0x15c96c*/
  v15 = v3; /*0x15c96e*/
  v4 = 20 * v3 + 8; /*0x15c974*/
  if ( *(_DWORD *)(*(_DWORD *)a1 + 20) < v4 ) /*0x15c980*/
    return 2; /*0x15c980*/
  v16 = ~page_mask & (page_mask + v4); /*0x15c98d*/
  if ( !v16 ) /*0x15c990*/
    return 2; /*0x15c992*/
  v17 = 0; /*0x15c99c*/
  if ( vm_allocate_with_pager(kernel_map, &v17, v16, 1, v13, 0) ) /*0x15c9ba*/
    return 5; /*0x15c9c6*/
  v6 = nullptr; /*0x15c9d0*/
  v7 = 0; /*0x15c9d2*/
  v8 = (unsigned int *)(v17 + 8); /*0x15c9d7*/
  v9 = v3 - 1; /*0x15c9da*/
  if ( v15 > 0 ) /*0x15c9df*/
  {
    do /*0x15ca14*/
    {
      if ( dword_1E8E04 == _byteswap_ulong(*v8) ) /*0x15c9ee*/
      {
        v14 = v7; /*0x15c9f6*/
        v10 = grade_cpu_subtype(_byteswap_ulong(v8[1])); /*0x15c9f9*/
        v7 = v14; /*0x15ca01*/
        if ( v10 > v14 ) /*0x15ca06*/
        {
          v7 = v10; /*0x15ca08*/
          v6 = v8; /*0x15ca0a*/
        }
      }
      v8 += 5; /*0x15ca0c*/
      v11 = v9--; /*0x15ca0f*/
    }
    while ( v11 > 0 ); /*0x15ca14*/
  }
  if ( v6 ) /*0x15ca18*/
  {
    *a3 = _byteswap_ulong(*v6); /*0x15ca2b*/
    a3[1] = _byteswap_ulong(v6[1]); /*0x15ca32*/
    a3[2] = _byteswap_ulong(v6[2]); /*0x15ca3a*/
    a3[3] = _byteswap_ulong(v6[3]); /*0x15ca42*/
    a3[4] = _byteswap_ulong(v6[4]); /*0x15ca4a*/
    v12 = 0; /*0x15ca4d*/
  }
  else
  {
    v12 = 1; /*0x15ca1a*/
  }
  vm_map_remove(kernel_map, v17, v17 + v16); /*0x15ca60*/
  return v12; /*0x15ca6a*/
}
