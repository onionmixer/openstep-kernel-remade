/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15558c. */
kern_return_t __cdecl mach_port_get_set_status(
        ipc_space_inspect_t task,
        mach_port_name_t name,
        mach_port_name_array_t *members,
        mach_msg_type_number_t *membersCnt)
{
  kern_return_t i; // eax
  kern_return_t v6; // ebx
  int v7; // ebx
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  mach_msg_type_number_t v11; // eax
  _DWORD *j; // eax
  int v13; // ecx
  int v14; // ebx
  int v15; // eax
  mach_msg_type_number_t v16; // eax
  int v17; // ebx
  unsigned int v18; // [esp+Ch] [ebp-30h]
  _DWORD *v19; // [esp+14h] [ebp-28h]
  int v20; // [esp+18h] [ebp-24h]
  vm_address_t v21; // [esp+1Ch] [ebp-20h]
  unsigned int v22; // [esp+20h] [ebp-1Ch]
  vm_size_t size; // [esp+24h] [ebp-18h]
  vm_size_t v24; // [esp+28h] [ebp-14h]
  int v25; // [esp+2Ch] [ebp-10h] BYREF
  mach_msg_type_number_t v26; // [esp+30h] [ebp-Ch]
  int *v27; // [esp+34h] [ebp-8h] BYREF
  vm_address_t address; // [esp+38h] [ebp-4h] BYREF

  if ( !task ) /*0x155599*/
    return 16; /*0x15559b*/
  size = page_size; /*0x1555ae*/
  v19 = (_DWORD *)(task + 32); /*0x1555b7*/
  for ( i = vm_allocate(ipc_kernel_map, &address, page_size, 1); ; i = vm_allocate(ipc_kernel_map, &address, size, 1) ) /*0x1555cd*/
  {
    if ( i ) /*0x1555d9*/
      return 6; /*0x155791*/
    vm_map_pageable(ipc_kernel_map, address, address + size, 0); /*0x1555f2*/
    v6 = ipc_right_lookup_write(task, name, &v27); /*0x155608*/
    if ( v6 ) /*0x15560f*/
    {
      kmem_free(ipc_kernel_map, address, size); /*0x1557a7*/
      return v6; /*0x1557ae*/
    }
    if ( (*v27 & 0x1F0000) != 0x80000 ) /*0x155624*/
    {
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x1557b9*/
      kmem_free(ipc_kernel_map, address, size); /*0x1557cb*/
      return 17; /*0x1557d5*/
    }
    v20 = v27[1]; /*0x15562d*/
    v21 = address; /*0x155633*/
    v24 = size >> 2; /*0x15563c*/
    v26 = 0; /*0x15563f*/
    v22 = *(_DWORD *)(task + 24); /*0x15564f*/
    v18 = 0; /*0x155652*/
    if ( v22 ) /*0x15565b*/
    {
      v7 = *(_DWORD *)(task + 20); /*0x15565d*/
      do /*0x1556b0*/
      {
        if ( (*(_BYTE *)(v7 + 2) & 2) != 0 ) /*0x155664*/
        {
          v8 = *(_DWORD *)(v7 + 4); /*0x155666*/
          do /*0x15567e*/
          {
            while ( *(_DWORD *)v8 ) /*0x15566c*/
              ; /*0x15566e*/
          }
          while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x15567e*/
          v9 = *(_DWORD *)(v8 + 16); /*0x155680*/
          v10 = *(_DWORD *)(v8 + 48); /*0x155686*/
          _InterlockedExchange((volatile __int32 *)v8, 0); /*0x15568b*/
          if ( v20 == v10 ) /*0x155690*/
          {
            v11 = v26; /*0x155692*/
            if ( v24 > v26 ) /*0x155698*/
              *(_DWORD *)(v21 + 4 * v26) = v9; /*0x15569d*/
            v26 = v11 + 1; /*0x1556a1*/
          }
        }
        v7 += 16; /*0x1556a4*/
        ++v18; /*0x1556a7*/
      }
      while ( v18 < v22 ); /*0x1556b0*/
    }
    for ( j = (_DWORD *)ipc_splay_traverse_start((int)v19); j; j = ipc_splay_traverse_next(v19, 0) ) /*0x1556c0*/
    {
      if ( (*((_BYTE *)j + 2) & 2) != 0 ) /*0x1556c8*/
      {
        v13 = j[1]; /*0x1556ca*/
        do /*0x1556e2*/
        {
          while ( *(_DWORD *)v13 ) /*0x1556d0*/
            ; /*0x1556d2*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x1556e2*/
        v14 = *(_DWORD *)(v13 + 16); /*0x1556e4*/
        v15 = *(_DWORD *)(v13 + 48); /*0x1556e7*/
        _InterlockedExchange((volatile __int32 *)v13, 0); /*0x1556ec*/
        if ( v20 == v15 ) /*0x1556f1*/
        {
          v16 = v26; /*0x1556f3*/
          if ( v24 > v26 ) /*0x1556f9*/
            *(_DWORD *)(v21 + 4 * v26) = v14; /*0x1556fe*/
          v26 = v16 + 1; /*0x155702*/
        }
      }
    }
    ipc_splay_traverse_finish(v19); /*0x15571b*/
    _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x155728*/
    if ( v26 <= v24 ) /*0x155731*/
      break; /*0x155731*/
    kmem_free(ipc_kernel_map, address, size); /*0x155742*/
    size = page_size + (~page_mask & (page_mask + 4 * v26)); /*0x155762*/
  }
  if ( v26 ) /*0x155775*/
  {
    v17 = ~page_mask & (page_mask + 4 * v26); /*0x1557e4*/
    vm_map_pageable(ipc_kernel_map, address, v17 + address, 1); /*0x1557f7*/
    vm_move(ipc_kernel_map, address, ipc_soft_map, v17, 1, (int)&v25); /*0x155815*/
    if ( size != v17 ) /*0x155820*/
      kmem_free(ipc_kernel_map, v17 + address, size - v17); /*0x155835*/
  }
  else
  {
    v25 = 0; /*0x155777*/
    kmem_free(ipc_kernel_map, address, size); /*0x155786*/
  }
  *members = (mach_port_name_array_t)v25; /*0x155840*/
  *membersCnt = v26; /*0x155848*/
  return 0; /*0x15584f*/
}
