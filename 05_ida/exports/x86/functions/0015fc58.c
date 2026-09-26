/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15fc58. */
__int32 __cdecl vmp_push(__int32 a1)
{
  __int32 result; // eax
  char v2; // dl
  int v3; // edi
  int v4; // edx
  int v5; // esi
  volatile __int32 *v6; // ebx
  unsigned int v7; // edi
  int v8; // eax
  int v9; // ebx
  char v10; // al
  volatile __int32 *v11; // edx
  int *v12; // edx
  int *v13; // eax
  volatile __int32 *v14; // edx
  char v15; // al
  int v16; // [esp+Ch] [ebp-8h]
  unsigned int v17; // [esp+10h] [ebp-4h]

  result = a1; /*0x15fc61*/
  v2 = *(_BYTE *)(a1 + 56); /*0x15fc64*/
  if ( (v2 & 2) != 0 ) /*0x15fc6a*/
  {
    *(_BYTE *)(a1 + 56) = v2 & 0xFD; /*0x15fc73*/
    v3 = *(_DWORD *)(a1 + 16); /*0x15fc76*/
    v4 = *(_DWORD *)(a1 + 12); /*0x15fc79*/
    v5 = *(_DWORD *)(a1 + 36); /*0x15fc7c*/
    if ( v5 ) /*0x15fc81*/
    {
      do /*0x15fca1*/
      {
        while ( vm_page_queue_lock ) /*0x15fc8f*/
          ; /*0x15fc8d*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fca1*/
      v6 = (volatile __int32 *)(v5 + 16); /*0x15fca3*/
      do /*0x15fcba*/
      {
        while ( *v6 ) /*0x15fca8*/
          ; /*0x15fcaa*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15fcba*/
      v17 = ~page_mask & (page_mask + v3 + v4); /*0x15fcc9*/
      v7 = ~page_mask & v3; /*0x15fccc*/
      while ( v17 > v7 ) /*0x15fcd0*/
      {
        v8 = vm_page_lookup(v5, v7); /*0x15fcda*/
        v9 = v8; /*0x15fcdf*/
        if ( v8 && (*(_BYTE *)(v8 + 33) & 8) == 0 ) /*0x15fcf0*/
        {
          v10 = *(_BYTE *)(v8 + 32); /*0x15fcf6*/
          if ( (v10 & 1) != 0 ) /*0x15fcfb*/
          {
            *(_BYTE *)(v9 + 32) = v10 | 2; /*0x15fcff*/
            assert_wait(v9, 0); /*0x15fd05*/
            _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x15fd0f*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fd14*/
            thread_block(); /*0x15fd1a*/
            do /*0x15fd39*/
            {
              while ( vm_page_queue_lock ) /*0x15fd27*/
                ; /*0x15fd25*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fd39*/
            v11 = (volatile __int32 *)(v5 + 16); /*0x15fd3b*/
            do /*0x15fd52*/
            {
              while ( *v11 ) /*0x15fd40*/
                ; /*0x15fd42*/
            }
            while ( _InterlockedExchange(v11, 1) == 1 ); /*0x15fd52*/
            continue; /*0x15fd52*/
          }
          if ( (*(_BYTE *)(v9 + 30) & 2) == 0 ) /*0x15fd68*/
            vm_page_activate(v9); /*0x15fd6b*/
          vm_page_deactivate(v9); /*0x15fd74*/
          v12 = *(int **)v9; /*0x15fd7c*/
          v13 = *(int **)(v9 + 4); /*0x15fd7e*/
          if ( *(int **)v9 == &vm_page_queue_inactive ) /*0x15fd87*/
            dword_1F64E4 = *(_DWORD *)(v9 + 4); /*0x15fd89*/
          else
            v12[1] = (int)v13; /*0x15fd90*/
          if ( v13 == &vm_page_queue_inactive ) /*0x15fd98*/
            vm_page_queue_inactive = (int)v12; /*0x15fd5c*/
          else
            *v13 = (int)v12; /*0x15fd9a*/
          *(_BYTE *)(v9 + 30) &= ~1u; /*0x15fd9c*/
          --vm_page_inactive_count; /*0x15fda0*/
          *(_BYTE *)(v9 + 32) |= 1u; /*0x15fda6*/
          if ( (*(_BYTE *)(v9 + 30) & 4) != 0 ) /*0x15fdae*/
          {
            pmap_remove_all(*(_DWORD *)(v9 + 36)); /*0x15fdb4*/
            ++*(_WORD *)(v5 + 68); /*0x15fdb9*/
            _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x15fdc2*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fdc7*/
            v16 = vnode_pageout(v9); /*0x15fdd3*/
            do /*0x15fdf5*/
            {
              while ( vm_page_queue_lock ) /*0x15fde3*/
                ; /*0x15fde1*/
            }
            while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fdf5*/
            v14 = (volatile __int32 *)(v5 + 16); /*0x15fdf7*/
            do /*0x15fe0e*/
            {
              while ( *v14 ) /*0x15fdfc*/
                ; /*0x15fdfe*/
            }
            while ( _InterlockedExchange(v14, 1) == 1 ); /*0x15fe0e*/
            --*(_WORD *)(v5 + 68); /*0x15fe10*/
            if ( !v16 ) /*0x15fe18*/
              *(_BYTE *)(v9 + 30) &= ~4u; /*0x15fe1a*/
          }
          vm_page_activate(v9); /*0x15fe1f*/
          v15 = *(_BYTE *)(v9 + 32); /*0x15fe24*/
          *(_BYTE *)(v9 + 32) = v15 & 0xFE; /*0x15fe2c*/
          if ( (v15 & 2) != 0 ) /*0x15fe34*/
          {
            *(_BYTE *)(v9 + 32) = v15 & 0xFC; /*0x15fe38*/
            thread_wakeup_prim(v9, 0, 0); /*0x15fe40*/
          }
        }
        v7 += page_size; /*0x15fe48*/
      }
      _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x15fe57*/
      return _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fe5e*/
    }
  }
  return result; /*0x15fe67*/
}
