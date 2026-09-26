/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a338. */
__int32 __cdecl vm_policy_apply(int a1, int a2, int a3)
{
  __int32 result; // eax
  int v4; // edx
  char v5; // al
  int *v6; // edx
  int *v7; // eax
  int v8; // edx
  int *v9; // eax
  int v10; // edx
  int v11; // eax

  result = 0; /*0x17a346*/
  if ( *(__int16 *)(a1 + 24) > 2 ) /*0x17a34d*/
  {
    v4 = *(_DWORD *)(a1 + 40); /*0x17a34f*/
    if ( v4 ) /*0x17a354*/
    {
      if ( !*(_DWORD *)v4 ) /*0x17a356*/
        result = (*(_BYTE *)(v4 + 12) & 1) == 0; /*0x17a360*/
    }
  }
  if ( (a3 & 2) != 0 || !result ) /*0x17a36a*/
  {
    do /*0x17a389*/
    {
      while ( vm_page_queue_lock ) /*0x17a377*/
        ; /*0x17a375*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17a389*/
    if ( a3 ) /*0x17a38d*/
    {
      if ( a3 == 1 && (*(_BYTE *)(a2 + 30) & 2) != 0 ) /*0x17a4d4*/
        vm_page_deactivate(a2); /*0x17a4d7*/
    }
    else
    {
      if ( (*(_BYTE *)(a2 + 30) & 0x20) == 0 || pmap_is_modified(*(_DWORD *)(a2 + 36)) ) /*0x17a3c2*/
      {
        if ( (*(_BYTE *)(a2 + 30) & 2) != 0 ) /*0x17a4b8*/
          vm_page_deactivate(a2); /*0x17a4bb*/
      }
      else
      {
        vm_page_remove(a2); /*0x17a3d3*/
        v5 = *(_BYTE *)(a2 + 30); /*0x17a3d8*/
        if ( (v5 & 8) == 0 ) /*0x17a3e0*/
        {
          if ( (v5 & 2) != 0 ) /*0x17a3e8*/
          {
            v6 = *(int **)a2; /*0x17a3ea*/
            v7 = *(int **)(a2 + 4); /*0x17a3ec*/
            if ( *(int **)a2 == &vm_page_queue_active ) /*0x17a3f5*/
              dword_1F6E44 = *(_DWORD *)(a2 + 4); /*0x17a3f7*/
            else
              v6[1] = (int)v7; /*0x17a400*/
            if ( v7 == &vm_page_queue_active ) /*0x17a408*/
              vm_page_queue_active = (int)v6; /*0x17a3a0*/
            else
              *v7 = (int)v6; /*0x17a40a*/
            *(_BYTE *)(a2 + 30) &= ~2u; /*0x17a40c*/
            --vm_page_active_count; /*0x17a410*/
          }
          if ( (*(_BYTE *)(a2 + 30) & 1) != 0 ) /*0x17a41a*/
          {
            v8 = *(_DWORD *)a2; /*0x17a41c*/
            v9 = *(int **)(a2 + 4); /*0x17a41e*/
            if ( *(int **)a2 == &vm_page_queue_inactive ) /*0x17a427*/
              dword_1F64E4 = *(_DWORD *)(a2 + 4); /*0x17a429*/
            else
              *(_DWORD *)(v8 + 4) = v9; /*0x17a430*/
            if ( v9 == &vm_page_queue_inactive ) /*0x17a438*/
              vm_page_queue_inactive = v8; /*0x17a3a8*/
            else
              *v9 = v8; /*0x17a43e*/
            *(_BYTE *)(a2 + 30) &= ~1u; /*0x17a440*/
            --vm_page_inactive_count; /*0x17a444*/
          }
          if ( (*(_BYTE *)(a2 + 32) & 8) == 0 ) /*0x17a44e*/
          {
            v10 = splimp(); /*0x17a455*/
            do /*0x17a471*/
            {
              while ( vm_page_queue_free_lock ) /*0x17a45f*/
                ; /*0x17a45d*/
            }
            while ( _InterlockedExchange(&vm_page_queue_free_lock, 1) == 1 ); /*0x17a471*/
            v11 = vm_page_queue_free; /*0x17a473*/
            if ( (int *)vm_page_queue_free == &vm_page_queue_free ) /*0x17a47d*/
              dword_1F6E4C = a2; /*0x17a47f*/
            else
              *(_DWORD *)(vm_page_queue_free + 4) = a2; /*0x17a488*/
            *(_DWORD *)a2 = v11; /*0x17a48b*/
            *(_DWORD *)(a2 + 4) = &vm_page_queue_free; /*0x17a48d*/
            vm_page_queue_free = a2; /*0x17a494*/
            *(_BYTE *)(a2 + 30) |= 8u; /*0x17a49a*/
            ++vm_page_free_count; /*0x17a49e*/
            _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x17a4a6*/
            splx(v10); /*0x17a4ad*/
          }
        }
      }
      pmap_remove_all(*(_DWORD *)(a2 + 36)); /*0x17a4c7*/
    }
    return _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17a4de*/
  }
  return result; /*0x17a4e7*/
}
