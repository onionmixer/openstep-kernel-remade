/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179d44. */
int vm_pageout_scan()
{
  int v0; // edx
  int v1; // ebx
  int v2; // edx
  int v3; // esi
  char v4; // al
  int v5; // esi
  int v6; // edi
  char v7; // al
  int v8; // esi
  _DWORD *v9; // eax
  volatile __int32 *v10; // edx
  char v11; // al
  int i; // ebx
  _BOOL4 v14; // [esp+Ch] [ebp-14h]
  _DWORD *v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  v16 = 0; /*0x179d4d*/
  v0 = splimp(); /*0x179d59*/
  do /*0x179d75*/
  {
    while ( vm_page_queue_free_lock ) /*0x179d63*/
      ; /*0x179d61*/
  }
  while ( _InterlockedExchange(&vm_page_queue_free_lock, 1) == 1 ); /*0x179d75*/
  v17 = 0; /*0x179d77*/
  if ( vm_page_free_count > vm_page_free_min ) /*0x179d89*/
  {
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x179dbe*/
    splx(v0); /*0x179dc5*/
  }
  else
  {
    v17 = 1; /*0x179d8b*/
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x179d90*/
    splx(v0); /*0x179d97*/
    pmap_update(); /*0x179d9c*/
  }
  do /*0x179de9*/
  {
    while ( vm_page_queue_lock ) /*0x179dd7*/
      ; /*0x179dd5*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179de9*/
  v1 = vm_page_queue_inactive; /*0x179deb*/
  while ( v17 && (int *)v1 != &vm_page_queue_inactive ) /*0x179e01*/
  {
    v2 = splimp(); /*0x179e0c*/
    do /*0x179e29*/
    {
      while ( vm_page_queue_free_lock ) /*0x179e17*/
        ; /*0x179e15*/
    }
    while ( _InterlockedExchange(&vm_page_queue_free_lock, 1) == 1 ); /*0x179e29*/
    if ( vm_page_free_count >= vm_page_free_target ) /*0x179e36*/
    {
      _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x179da6*/
      splx(v2); /*0x179dad*/
      break; /*0x179db5*/
    }
    _InterlockedExchange(&vm_page_queue_free_lock, 0); /*0x179e3e*/
    splx(v2); /*0x179e45*/
    if ( pmap_is_referenced(*(_DWORD *)(v1 + 36)) ) /*0x179e4e*/
    {
      v3 = *(_DWORD *)v1; /*0x179e5a*/
      vm_page_activate(v1); /*0x179e5d*/
      ++dword_1F6508; /*0x179e62*/
      v1 = v3; /*0x179e68*/
    }
    else
    {
      v4 = *(_BYTE *)(v1 + 30); /*0x179e70*/
      if ( (v4 & 0x20) != 0 ) /*0x179e75*/
      {
        v5 = *(_DWORD *)v1; /*0x179e7b*/
        v6 = *(_DWORD *)(v1 + 20); /*0x179e7d*/
        if ( _InterlockedExchange((volatile __int32 *)(v6 + 16), 1) != 1 ) /*0x179e88*/
        {
          v16 = 1; /*0x179e98*/
          *(_BYTE *)(v1 + 32) |= 1u; /*0x179e9f*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x179ea5*/
          pmap_remove_all(*(_DWORD *)(v1 + 36)); /*0x179eaf*/
          do /*0x179ed1*/
          {
            while ( vm_page_queue_lock ) /*0x179ebf*/
              ; /*0x179ebd*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179ed1*/
          v7 = *(_BYTE *)(v1 + 32); /*0x179ed3*/
          *(_BYTE *)(v1 + 32) = v7 & 0xFE; /*0x179edb*/
          if ( (v7 & 2) != 0 ) /*0x179ee0*/
          {
            *(_BYTE *)(v1 + 32) = v7 & 0xFC; /*0x179ee4*/
            thread_wakeup_prim(v1, 0, 0); /*0x179eec*/
          }
          v8 = *(_DWORD *)v1; /*0x179ef4*/
          vm_page_addfree(v1); /*0x179ef7*/
          goto LABEL_46; /*0x179eff*/
        }
        v1 = v5; /*0x179e8f*/
      }
      else if ( (v4 & 4) != 0 && (v6 = *(_DWORD *)(v1 + 20), _InterlockedExchange((volatile __int32 *)(v6 + 16), 1) ^ 1) ) /*0x179f17*/
      {
        *(_BYTE *)(v1 + 32) |= 1u; /*0x179f22*/
        ++dword_1F6510; /*0x179f26*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x179f2e*/
        v16 = 1; /*0x179f34*/
        pmap_remove_all(*(_DWORD *)(v1 + 36)); /*0x179f3f*/
        vm_object_collapse(v6); /*0x179f45*/
        ++*(_WORD *)(v6 + 68); /*0x179f4a*/
        _InterlockedExchange((volatile __int32 *)(v6 + 16), 0); /*0x179f53*/
        thread_wakeup_prim((int)&vm_page_free_count, 0, 0); /*0x179f5f*/
        v9 = *(_DWORD **)(v6 + 40); /*0x179f64*/
        if ( !v9 ) /*0x179f6c*/
        {
          v9 = (_DWORD *)vm_pager_allocate(*(_DWORD *)(v6 + 20)); /*0x179f72*/
          if ( v9 ) /*0x179f7c*/
          {
            v15 = v9; /*0x179f84*/
            vm_object_setpager(v6, (int)v9, 0); /*0x179f87*/
            v9 = v15; /*0x179f8f*/
          }
        }
        v14 = 0; /*0x179f92*/
        if ( v9 ) /*0x179f9b*/
          v14 = vm_pager_put(v9, v1) == 0; /*0x179fab*/
        v10 = (volatile __int32 *)(v6 + 16); /*0x179fb2*/
        do /*0x179fca*/
        {
          while ( *v10 ) /*0x179fb8*/
            ; /*0x179fba*/
        }
        while ( _InterlockedExchange(v10, 1) == 1 ); /*0x179fca*/
        do /*0x179fe5*/
        {
          while ( vm_page_queue_lock ) /*0x179fd3*/
            ; /*0x179fd1*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179fe5*/
        v8 = *(_DWORD *)v1; /*0x179fe7*/
        if ( v14 ) /*0x179fed*/
          *(_BYTE *)(v1 + 30) &= ~4u; /*0x179fef*/
        else
          vm_page_activate(v1); /*0x179ff9*/
        pmap_clear_reference(*(_DWORD *)(v1 + 36)); /*0x17a005*/
        v11 = *(_BYTE *)(v1 + 32); /*0x17a00a*/
        *(_BYTE *)(v1 + 32) = v11 & 0xFE; /*0x17a012*/
        if ( (v11 & 2) != 0 ) /*0x17a01a*/
        {
          *(_BYTE *)(v1 + 32) = v11 & 0xFC; /*0x17a01e*/
          thread_wakeup_prim(v1, 0, 0); /*0x17a026*/
        }
        --*(_WORD *)(v6 + 68); /*0x17a02e*/
        thread_wakeup_prim(v6, 0, 0); /*0x17a037*/
LABEL_46:
        _InterlockedExchange((volatile __int32 *)(v6 + 16), 0); /*0x17a03f*/
        v1 = v8; /*0x17a044*/
      }
      else
      {
        v1 = *(_DWORD *)v1; /*0x17a04c*/
      }
    }
  }
  for ( i = vm_page_inactive_target - vm_page_inactive_count - vm_page_free_count; i > 0; --i ) /*0x17a068*/
  {
    if ( (int *)vm_page_queue_active == &vm_page_queue_active ) /*0x17a076*/
      break; /*0x17a076*/
    v16 = 1; /*0x17a078*/
    vm_page_deactivate(vm_page_queue_active); /*0x17a080*/
  }
  _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17a08f*/
  return v16; /*0x17a09b*/
}
