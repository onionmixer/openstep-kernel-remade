/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154bec. */
kern_return_t __cdecl mach_port_names(
        ipc_space_t task,
        mach_port_name_array_t *names,
        mach_msg_type_number_t *namesCnt,
        mach_port_type_array_t *types,
        mach_msg_type_number_t *typesCnt)
{
  volatile __int32 *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // edx
  int v11; // edx
  mach_msg_type_number_t v12; // eax
  unsigned int *v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // edx
  int v17; // edx
  mach_msg_type_number_t v18; // eax
  int v19; // esi
  vm_size_t v20; // [esp+Ch] [ebp-3Ch]
  _BOOL4 v21; // [esp+Ch] [ebp-3Ch]
  _BOOL4 v22; // [esp+Ch] [ebp-3Ch]
  unsigned int *v23; // [esp+10h] [ebp-38h]
  unsigned int v24; // [esp+10h] [ebp-38h]
  int v25; // [esp+14h] [ebp-34h]
  int v26; // [esp+18h] [ebp-30h]
  vm_size_t size; // [esp+1Ch] [ebp-2Ch]
  vm_address_t v28; // [esp+20h] [ebp-28h]
  vm_address_t v29; // [esp+24h] [ebp-24h]
  int v30; // [esp+28h] [ebp-20h]
  int v31; // [esp+2Ch] [ebp-1Ch]
  unsigned int v32; // [esp+30h] [ebp-18h]
  int v33; // [esp+34h] [ebp-14h] BYREF
  int v34; // [esp+38h] [ebp-10h] BYREF
  mach_msg_type_number_t v35; // [esp+3Ch] [ebp-Ch]
  vm_address_t v36; // [esp+40h] [ebp-8h] BYREF
  vm_address_t address; // [esp+44h] [ebp-4h] BYREF

  if ( !task ) /*0x154bf9*/
    return 16; /*0x154bf9*/
  size = 0; /*0x154c08*/
  v6 = (volatile __int32 *)(task + 8); /*0x154c12*/
  while ( 1 ) /*0x154c2a*/
  {
    do /*0x154c2a*/
    {
      while ( *v6 ) /*0x154c18*/
        ; /*0x154c1a*/
    }
    while ( _InterlockedExchange(v6, 1) == 1 ); /*0x154c2a*/
    if ( !*(_DWORD *)(task + 12) ) /*0x154c2f*/
    {
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x154c37*/
      if ( size ) /*0x154c3e*/
      {
        kmem_free(ipc_kernel_map, address, size); /*0x154c4f*/
        kmem_free(ipc_kernel_map, v36, size); /*0x154c63*/
      }
      return 16; /*0x154c00*/
    }
    v20 = ~page_mask & (page_mask + 4 * (*(_DWORD *)(task + 56) + *(_DWORD *)(task + 24))); /*0x154c81*/
    if ( v20 <= size ) /*0x154c89*/
      break; /*0x154c89*/
    _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x154c91*/
    if ( size ) /*0x154c96*/
    {
      kmem_free(ipc_kernel_map, address, size); /*0x154ca4*/
      kmem_free(ipc_kernel_map, v36, size); /*0x154cb8*/
    }
    size = v20; /*0x154cc3*/
    if ( vm_allocate(ipc_kernel_map, &address, v20, 1) ) /*0x154cd7*/
      return 6; /*0x154fa5*/
    if ( vm_allocate(ipc_kernel_map, &v36, v20, 1) ) /*0x154cf5*/
    {
      kmem_free(ipc_kernel_map, address, v20); /*0x154fbb*/
      return 6; /*0x154fc5*/
    }
    vm_map_pageable(ipc_kernel_map, address, address + v20, 0); /*0x154d18*/
    vm_map_pageable(ipc_kernel_map, v36, v36 + v20, 0); /*0x154d30*/
  }
  v29 = address; /*0x154d43*/
  v28 = v36; /*0x154d49*/
  v35 = 0; /*0x154d4c*/
  v30 = ipc_port_timestamp(); /*0x154d58*/
  v32 = *(_DWORD *)(task + 24); /*0x154d64*/
  v31 = 0; /*0x154d67*/
  if ( v32 ) /*0x154d71*/
  {
    v25 = 0; /*0x154d77*/
    v23 = *(unsigned int **)(task + 20); /*0x154d7e*/
    while ( 1 ) /*0x154d87*/
    {
      v7 = *v23; /*0x154d87*/
      if ( (*v23 & 0x1F0000) != 0 ) /*0x154d8f*/
      {
        v26 = v25 | HIBYTE(v7); /*0x154d9d*/
        v8 = *v23; /*0x154da0*/
        v9 = v23[2]; /*0x154da2*/
        if ( (v7 & 0x50000) == 0 ) /*0x154dab*/
          goto LABEL_29; /*0x154dab*/
        v10 = v23[1]; /*0x154dad*/
        do /*0x154dc2*/
        {
          while ( *(_DWORD *)v10 ) /*0x154db0*/
            ; /*0x154db2*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ); /*0x154dc2*/
        v21 = 0; /*0x154dc4*/
        if ( *(int *)(v10 + 8) >= 0 ) /*0x154dcf*/
          v21 = *(_DWORD *)(v10 + 12) - v30 < 0; /*0x154dd9*/
        _InterlockedExchange((volatile __int32 *)v10, 0); /*0x154dde*/
        if ( !v21 ) /*0x154de4*/
          goto LABEL_29; /*0x154de4*/
        if ( (v8 & 0x400000) == 0 ) /*0x154dec*/
          break; /*0x154dec*/
      }
LABEL_36:
      v25 += 256; /*0x154e4a*/
      v23 += 4; /*0x154e51*/
      if ( ++v31 >= v32 ) /*0x154e5e*/
        goto LABEL_37; /*0x154e5e*/
    }
    v8 = v8 & 0xFFC0FFFF | 0x100000; /*0x154df4*/
    if ( v9 ) /*0x154dfc*/
      ++v8; /*0x154dfe*/
    v9 = 0; /*0x154dff*/
LABEL_29:
    v11 = v8 & 0x1F0000; /*0x154e01*/
    if ( (v8 & 0x400000) != 0 ) /*0x154e0f*/
    {
      v11 |= 0x20000000u; /*0x154e11*/
    }
    else if ( v9 ) /*0x154e1e*/
    {
      v11 |= 0x80000000; /*0x154e20*/
    }
    if ( (v8 & 0x200000) != 0 ) /*0x154e2c*/
      v11 |= 0x40000000u; /*0x154e2e*/
    v12 = v35; /*0x154e34*/
    *(_DWORD *)(v29 + 4 * v35) = v26; /*0x154e3d*/
    *(_DWORD *)(v28 + 4 * v12) = v11; /*0x154e43*/
    v35 = v12 + 1; /*0x154e47*/
    goto LABEL_36; /*0x154e47*/
  }
LABEL_37:
  v13 = (unsigned int *)ipc_splay_traverse_start(task + 32); /*0x154e64*/
  if ( v13 ) /*0x154e75*/
  {
    while ( 1 ) /*0x154e7f*/
    {
      v24 = v13[4]; /*0x154e7f*/
      v14 = *v13; /*0x154e82*/
      v15 = v13[2]; /*0x154e84*/
      if ( (*v13 & 0x50000) == 0 ) /*0x154e8d*/
        goto LABEL_49; /*0x154e8d*/
      v16 = v13[1]; /*0x154e8f*/
      do /*0x154ea6*/
      {
        while ( *(_DWORD *)v16 ) /*0x154e94*/
          ; /*0x154e96*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v16, 1) == 1 ); /*0x154ea6*/
      v22 = 0; /*0x154ea8*/
      if ( *(int *)(v16 + 8) >= 0 ) /*0x154eb3*/
        v22 = *(_DWORD *)(v16 + 12) - v30 < 0; /*0x154ebd*/
      _InterlockedExchange((volatile __int32 *)v16, 0); /*0x154ec2*/
      if ( !v22 ) /*0x154ec8*/
        goto LABEL_49; /*0x154ec8*/
      if ( (v14 & 0x400000) == 0 ) /*0x154ed0*/
        break; /*0x154ed0*/
LABEL_56:
      v13 = ipc_splay_traverse_next((_DWORD *)(task + 32), 0); /*0x154f2e*/
      if ( !v13 ) /*0x154f41*/
        goto LABEL_57; /*0x154f41*/
    }
    v14 = v14 & 0xFFC0FFFF | 0x100000; /*0x154ed8*/
    if ( v15 ) /*0x154ee0*/
      ++v14; /*0x154ee2*/
    v15 = 0; /*0x154ee3*/
LABEL_49:
    v17 = v14 & 0x1F0000; /*0x154ee5*/
    if ( (v14 & 0x400000) != 0 ) /*0x154ef3*/
    {
      v17 |= 0x20000000u; /*0x154ef5*/
    }
    else if ( v15 ) /*0x154f02*/
    {
      v17 |= 0x80000000; /*0x154f04*/
    }
    if ( (v14 & 0x200000) != 0 ) /*0x154f10*/
      v17 |= 0x40000000u; /*0x154f12*/
    v18 = v35; /*0x154f18*/
    *(_DWORD *)(v29 + 4 * v35) = v24; /*0x154f21*/
    *(_DWORD *)(v28 + 4 * v18) = v17; /*0x154f27*/
    v35 = v18 + 1; /*0x154f2b*/
    goto LABEL_56; /*0x154f2b*/
  }
LABEL_57:
  ipc_splay_traverse_finish((_DWORD *)(task + 32)); /*0x154f47*/
  _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x154f5b*/
  if ( v35 ) /*0x154f63*/
  {
    v19 = ~page_mask & (page_mask + 4 * v35); /*0x154fd8*/
    vm_map_pageable(ipc_kernel_map, address, v19 + address, 1); /*0x154feb*/
    vm_map_pageable(ipc_kernel_map, v36, v19 + v36, 1); /*0x155001*/
    vm_move(ipc_kernel_map, address, ipc_soft_map, v19, 1, (int)&v34); /*0x155022*/
    vm_move(ipc_kernel_map, v36, ipc_soft_map, v19, 1, (int)&v33); /*0x155040*/
    if ( size != v19 ) /*0x15504b*/
    {
      kmem_free(ipc_kernel_map, v19 + address, size - v19); /*0x155060*/
      kmem_free(ipc_kernel_map, v19 + v36, size - v19); /*0x155073*/
    }
  }
  else
  {
    v34 = 0; /*0x154f65*/
    v33 = 0; /*0x154f6c*/
    if ( size ) /*0x154f77*/
    {
      kmem_free(ipc_kernel_map, address, size); /*0x154f8c*/
      kmem_free(ipc_kernel_map, v36, size); /*0x154f99*/
    }
  }
  *names = (mach_port_name_array_t)v34; /*0x15507e*/
  *namesCnt = v35; /*0x155086*/
  *types = (mach_port_type_array_t)v33; /*0x15508e*/
  *typesCnt = v35; /*0x155096*/
  return 0; /*0x15509d*/
}
