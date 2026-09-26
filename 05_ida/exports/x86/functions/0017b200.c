/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b200. */
int __cdecl vm_page_alloc_sequential(int a1, unsigned int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // edx
  int v10; // edx
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // edx
  int v18; // edx
  _DWORD *i; // ebx
  int v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]

  v3 = splimp(); /*0x17b20e*/
  do /*0x17b229*/
  {
    while ( vm_page_queue_free_lock ) /*0x17b217*/
      ; /*0x17b215*/
  }
  while ( _InterlockedExchange(&vm_page_queue_free_lock, 1) == 1 ); /*0x17b229*/
  if ( (int *)vm_page_queue_free == &vm_page_queue_free /*0x17b25e*/
    || vm_page_free_count < vm_page_free_reserved && !*(_DWORD *)(active_threads + 120) )
  {
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x17b239*/
    splx(v3); /*0x17b240*/
    return 0; /*0x17b245*/
  }
  else
  {
    v21 = vm_page_queue_free; /*0x17b282*/
    v5 = *(_DWORD *)vm_page_queue_free; /*0x17b285*/
    if ( *(int **)vm_page_queue_free == &vm_page_queue_free ) /*0x17b28c*/
      dword_1F6E4C = (int)&vm_page_queue_free; /*0x17b28e*/
    else
      *(_DWORD *)(v5 + 4) = &vm_page_queue_free; /*0x17b29c*/
    vm_page_queue_free = v5; /*0x17b2a3*/
    *(_BYTE *)(v21 + 30) &= ~8u; /*0x17b2ab*/
    --vm_page_free_count; /*0x17b2af*/
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x17b2b7*/
    splx(v3); /*0x17b2be*/
    if ( (*(_BYTE *)(v21 + 32) & 4) != 0 ) /*0x17b2ca*/
    {
      v6 = vm_page_buckets + 8 * (vm_page_hash_mask & (*(_DWORD *)(v21 + 20) + (*(_DWORD *)(v21 + 24) >> page_shift))); /*0x17b2ea*/
      v7 = splimp(); /*0x17b2f2*/
      do /*0x17b306*/
      {
        while ( *(_DWORD *)v6 ) /*0x17b2f4*/
          ; /*0x17b2f6*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x17b306*/
      v8 = *(_DWORD *)(v6 + 4); /*0x17b308*/
      if ( v21 == v8 ) /*0x17b30e*/
      {
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v21 + 16); /*0x17b316*/
      }
      else
      {
        do /*0x17b329*/
        {
          v9 = (_DWORD *)(v8 + 16); /*0x17b320*/
          v8 = *(_DWORD *)(v8 + 16); /*0x17b323*/
        }
        while ( v21 != v8 ); /*0x17b329*/
        *v9 = *(_DWORD *)(v8 + 16); /*0x17b32e*/
      }
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x17b332*/
      splx(v7); /*0x17b335*/
      v10 = *(_DWORD *)(v21 + 8); /*0x17b340*/
      v11 = *(_DWORD **)(v21 + 12); /*0x17b343*/
      if ( *(_DWORD *)(v21 + 20) == v10 ) /*0x17b349*/
        *(_DWORD *)(v10 + 4) = v11; /*0x17b34b*/
      else
        *(_DWORD *)(v10 + 12) = v11; /*0x17b350*/
      if ( *(_DWORD **)(v21 + 20) == v11 ) /*0x17b359*/
        *v11 = v10; /*0x17b31c*/
      else
        v11[2] = v10; /*0x17b35b*/
      --*(_WORD *)(*(_DWORD *)(v21 + 20) + 26); /*0x17b364*/
      *(_BYTE *)(v21 + 32) &= ~4u; /*0x17b368*/
    }
    v12 = *(_DWORD *)(v21 + 36); /*0x17b36f*/
    qmemcpy((void *)v21, &vm_page_template, 0x30u); /*0x17b384*/
    *(_DWORD *)(v21 + 36) = v12; /*0x17b386*/
    if ( (*(_BYTE *)(v21 + 32) & 4) != 0 ) /*0x17b390*/
      panic(aVmPageInsert); /*0x17b397*/
    *(_DWORD *)(v21 + 20) = a1; /*0x17b3a5*/
    *(_DWORD *)(v21 + 24) = a2; /*0x17b3ab*/
    v13 = vm_page_buckets + 8 * (vm_page_hash_mask & (a1 + (a2 >> page_shift))); /*0x17b3c8*/
    v14 = splimp(); /*0x17b3d0*/
    do /*0x17b3e6*/
    {
      while ( *(_DWORD *)v13 ) /*0x17b3d4*/
        ; /*0x17b3d6*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x17b3e6*/
    *(_DWORD *)(v21 + 16) = *(_DWORD *)(v13 + 4); /*0x17b3ee*/
    *(_DWORD *)(v13 + 4) = v21; /*0x17b3f1*/
    _InterlockedExchange((volatile __int32 *)v13, 0); /*0x17b3f6*/
    splx(v14); /*0x17b3f9*/
    v15 = *(_DWORD *)(a1 + 4); /*0x17b404*/
    if ( a1 == v15 ) /*0x17b409*/
      *(_DWORD *)a1 = v21; /*0x17b40e*/
    else
      *(_DWORD *)(v15 + 8) = v21; /*0x17b417*/
    *(_DWORD *)(v21 + 12) = v15; /*0x17b41d*/
    *(_DWORD *)(v21 + 8) = a1; /*0x17b423*/
    *(_DWORD *)(a1 + 4) = v21; /*0x17b426*/
    *(_BYTE *)(v21 + 32) |= 4u; /*0x17b429*/
    ++*(_WORD *)(a1 + 26); /*0x17b42d*/
    if ( vm_page_free_min > vm_page_free_count /*0x17b451*/
      || vm_page_free_target > vm_page_free_count && vm_page_inactive_count < vm_page_inactive_target )
    {
      thread_wakeup_prim((int)&vm_pages_needed, 0, 0); /*0x17b45c*/
    }
    if ( (*(_BYTE *)(a1 + 72) & 3) != 0 && a3 ) /*0x17b475*/
    {
      v16 = *(_DWORD *)(a1 + 84); /*0x17b47b*/
      v17 = a2 - v16; /*0x17b481*/
      if ( (int)(a2 - v16) < 0 ) /*0x17b483*/
        v17 = v16 - a2; /*0x17b485*/
      if ( page_size == v17 ) /*0x17b48d*/
      {
        v22 = *(_DWORD *)(a1 + 84); /*0x17b493*/
        v20 = vm_page_buckets + 8 * (vm_page_hash_mask & (a1 + (v16 >> page_shift))); /*0x17b4b0*/
        v18 = splimp(); /*0x17b4b8*/
        do /*0x17b4d2*/
        {
          while ( *(_DWORD *)v20 ) /*0x17b4c0*/
            ; /*0x17b4c2*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v20, 1) == 1 ); /*0x17b4d2*/
        for ( i = *(_DWORD **)(v20 + 4); i; i = (_DWORD *)i[4] ) /*0x17b4d9*/
        {
          if ( i[5] == a1 && i[6] == v22 ) /*0x17b4ea*/
            break; /*0x17b4ea*/
        }
        _InterlockedExchange((volatile __int32 *)v20, 0); /*0x17b4f5*/
        splx(v18); /*0x17b4f8*/
        if ( i ) /*0x17b504*/
          vm_policy_apply(a1, (int)i, *(_WORD *)(a1 + 72) == 2); /*0x17b522*/
      }
    }
    *(_DWORD *)(a1 + 84) = a2; /*0x17b52d*/
    return v21; /*0x17b530*/
  }
}
