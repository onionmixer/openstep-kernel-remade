/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106e58. */
int smmap()
{
  char v0; // dl
  int result; // eax
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // eax
  int (*v5)(); // esi
  signed int v6; // ebx
  int v7; // esi
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  char v11; // bl
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // eax
  vm_size_t size; // [esp+Ch] [ebp-2Ch]
  vm_size_t sizea; // [esp+Ch] [ebp-2Ch]
  __int16 v18; // [esp+18h] [ebp-20h]
  vm_address_t v19; // [esp+1Ch] [ebp-1Ch]
  vm_address_t v20; // [esp+20h] [ebp-18h]
  vm_map_t target_task; // [esp+24h] [ebp-14h]
  vm_address_t *v22; // [esp+28h] [ebp-10h]
  int v23; // [esp+2Ch] [ebp-Ch] BYREF
  vm_address_t address; // [esp+30h] [ebp-8h] BYREF
  int v25; // [esp+34h] [ebp-4h] BYREF

  v22 = *(vm_address_t **)(dword_1E875C + 36); /*0x106e69*/
  address = *v22; /*0x106e6e*/
  size = v22[1]; /*0x106e77*/
  v20 = v22[5]; /*0x106e80*/
  v19 = v22[2]; /*0x106e89*/
  v0 = getvnodefp(v22[4], &v25); /*0x106e9c*/
  result = dword_1E875C; /*0x106e9e*/
  *(_BYTE *)(dword_1E875C + 104) = v0; /*0x106ea3*/
  if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x106eaf*/
    return result; /*0x106eb3*/
  if ( *(_WORD *)(v25 + 12) != 1 /*0x106eef*/
    || (v2 = *(_DWORD **)(v25 + 24),
        address &= ~page_mask,
        result = ~page_mask & (size + page_mask),
        sizea = result,
        (v19 & 2) != 0)
    && (*(_BYTE *)(v25 + 8) & 2) == 0 )
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x106ef1*/
    return result; /*0x106ef5*/
  }
  if ( (v19 & 1) != 0 && (*(_BYTE *)(v25 + 8) & 1) == 0 ) /*0x106f0b*/
    goto LABEL_37; /*0x106f0b*/
  target_task = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12); /*0x106f1c*/
  if ( !vm_map_check_protection(target_task, address, address + result, 3) ) /*0x106f2f*/
    goto LABEL_37; /*0x106f39*/
  v3 = v2[10]; /*0x106f3f*/
  if ( v3 == 4 || v3 == 9 ) /*0x106f4a*/
  {
    v4 = v2[12]; /*0x106f50*/
    v18 = *(_WORD *)(v4 + 66); /*0x106f57*/
    v5 = funcs_106FAE[11 * *(unsigned __int8 *)(v4 + 67)]; /*0x106f65*/
    if ( v5 == nulldev || (char *)v5 == (char *)nodev || !v5 ) /*0x106f86*/
      goto LABEL_37; /*0x106f86*/
    v6 = 0; /*0x106f8c*/
    if ( (int)v22[1] > 0 ) /*0x106f94*/
    {
      while ( ((int (__cdecl *)(_DWORD))v5)(v18) != -1 ) /*0x106fb6*/
      {
        v6 += page_size; /*0x106fbc*/
        if ( (int)v22[1] <= v6 ) /*0x106fc8*/
          goto LABEL_17; /*0x106fc8*/
      }
      goto LABEL_37; /*0x106fb6*/
    }
LABEL_17:
    if ( v22[3] != 1 || vm_deallocate(target_task, address, sizea) ) /*0x106fe3*/
    {
LABEL_37:
      result = dword_1E875C; /*0x10719e*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1071a3*/
      return result; /*0x1071a7*/
    }
    v7 = vm_object_special(v18, v5, v19, v20, sizea); /*0x10700c*/
    if ( vm_map_find(target_task, v7, 0, &address, sizea, 0) ) /*0x10701f*/
    {
      vm_object_deallocate(v7); /*0x107032*/
      goto LABEL_37; /*0x107037*/
    }
    goto LABEL_32; /*0x10702b*/
  }
  if ( v3 != 1 ) /*0x10703f*/
    goto LABEL_37; /*0x10703f*/
  v8 = vnode_pager_setup((int)v2, 0, 0); /*0x10704f*/
  v9 = *v2; /*0x107051*/
  if ( !*(_DWORD *)(*v2 + 48) ) /*0x107056*/
  {
    ++**(_WORD **)(active_u + 28); /*0x107064*/
    *(_DWORD *)(v9 + 48) = *(_DWORD *)(active_u + 28); /*0x10706f*/
  }
  if ( v22[3] == 1 ) /*0x107079*/
  {
    vm_deallocate(target_task, address, sizea); /*0x107087*/
    v10 = vm_allocate_with_pager(target_task, &address, sizea, 0, v8, v20); /*0x10709f*/
    v11 = v10; /*0x1070a4*/
    if ( v10 ) /*0x1070ab*/
      goto LABEL_30; /*0x1070ab*/
  }
  else
  {
    v12 = pmap_create(sizea); /*0x1070bd*/
    v13 = vm_map_create(v12, 0, sizea, 1); /*0x1070cb*/
    v23 = 0; /*0x1070cd*/
    v14 = vm_allocate_with_pager(v13, &v23, sizea, 0, v8, v20); /*0x1070e4*/
    v11 = v14; /*0x1070e9*/
    if ( v14 || (v15 = vm_map_copy(target_task, v13, address, sizea, 0, 0, 0), v11 = v15, v15) ) /*0x107111*/
    {
      vm_map_deallocate(v13); /*0x107114*/
LABEL_30:
      result = dword_1E875C; /*0x107119*/
      *(_BYTE *)(dword_1E875C + 104) = v11; /*0x10711e*/
      return result; /*0x107121*/
    }
    vm_map_deallocate(v13); /*0x107129*/
  }
LABEL_32:
  if ( (v19 & 2) == 0 && vm_protect(target_task, address, sizea, 0, 1) /*0x10717f*/
    || v22[3] == 1 && vm_inherit(target_task, address, sizea, 0) )
  {
    vm_deallocate(target_task, address, sizea); /*0x107199*/
    goto LABEL_37; /*0x107199*/
  }
  result = v22[4]; /*0x1071ba*/
  *(_BYTE *)(result + *(_DWORD *)(active_u + 340)) |= 2u; /*0x1071bd*/
  return result; /*0x1071c4*/
}
