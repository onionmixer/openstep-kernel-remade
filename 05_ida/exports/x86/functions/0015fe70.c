/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15fe70. */
__int32 __cdecl vmp_push_all(__int32 a1)
{
  __int32 result; // eax
  int v2; // esi
  volatile __int32 *v3; // edx
  int i; // ebx
  char v5; // al
  volatile __int32 *v6; // edx
  int *v7; // edx
  int *v8; // eax
  int v9; // edi
  volatile __int32 *v10; // edx
  char v11; // al

  result = a1; /*0x15fe76*/
  *(_BYTE *)(a1 + 56) &= ~2u; /*0x15fe79*/
  v2 = *(_DWORD *)(a1 + 36); /*0x15fe7d*/
  if ( v2 ) /*0x15fe82*/
  {
    do /*0x15fea1*/
    {
      while ( vm_page_queue_lock ) /*0x15fe8f*/
        ; /*0x15fe8d*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fea1*/
    v3 = (volatile __int32 *)(v2 + 16); /*0x15fea3*/
    do /*0x15feba*/
    {
      while ( *v3 ) /*0x15fea8*/
        ; /*0x15feaa*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x15feba*/
LABEL_7:
    for ( i = *(_DWORD *)v2; v2 != i; i = *(_DWORD *)(i + 8) ) /*0x15fec0*/
    {
      if ( (*(_BYTE *)(i + 33) & 8) == 0 ) /*0x15fecc*/
      {
        v5 = *(_BYTE *)(i + 32); /*0x15fed2*/
        if ( (v5 & 1) != 0 ) /*0x15fed7*/
        {
          *(_BYTE *)(i + 32) = v5 | 2; /*0x15fedb*/
          assert_wait(i, 0); /*0x15fee1*/
          _InterlockedExchange((volatile __int32 *)(v2 + 16), 0); /*0x15feeb*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fef0*/
          thread_block(); /*0x15fef6*/
          do /*0x15ff15*/
          {
            while ( vm_page_queue_lock ) /*0x15ff03*/
              ; /*0x15ff01*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15ff15*/
          v6 = (volatile __int32 *)(v2 + 16); /*0x15ff17*/
          do /*0x15ff2e*/
          {
            while ( *v6 ) /*0x15ff1c*/
              ; /*0x15ff1e*/
          }
          while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15ff2e*/
          goto LABEL_7; /*0x15ff2e*/
        }
        if ( (*(_BYTE *)(i + 30) & 2) == 0 ) /*0x15ff40*/
          vm_page_activate(i); /*0x15ff43*/
        vm_page_deactivate(i); /*0x15ff4c*/
        v7 = *(int **)i; /*0x15ff54*/
        v8 = *(int **)(i + 4); /*0x15ff56*/
        if ( *(int **)i == &vm_page_queue_inactive ) /*0x15ff5f*/
          dword_1F64E4 = *(_DWORD *)(i + 4); /*0x15ff61*/
        else
          v7[1] = (int)v8; /*0x15ff68*/
        if ( v8 == &vm_page_queue_inactive ) /*0x15ff70*/
          vm_page_queue_inactive = (int)v7; /*0x15ff34*/
        else
          *v8 = (int)v7; /*0x15ff72*/
        *(_BYTE *)(i + 30) &= ~1u; /*0x15ff74*/
        --vm_page_inactive_count; /*0x15ff78*/
        *(_BYTE *)(i + 32) |= 1u; /*0x15ff7e*/
        if ( (*(_BYTE *)(i + 30) & 4) != 0 ) /*0x15ff86*/
        {
          pmap_remove_all(*(_DWORD *)(i + 36)); /*0x15ff8c*/
          ++*(_WORD *)(v2 + 68); /*0x15ff91*/
          _InterlockedExchange((volatile __int32 *)(v2 + 16), 0); /*0x15ff9a*/
          _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15ff9f*/
          v9 = vnode_pageout(i); /*0x15ffab*/
          do /*0x15ffc9*/
          {
            while ( vm_page_queue_lock ) /*0x15ffb7*/
              ; /*0x15ffb5*/
          }
          while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15ffc9*/
          v10 = (volatile __int32 *)(v2 + 16); /*0x15ffcb*/
          do /*0x15ffe2*/
          {
            while ( *v10 ) /*0x15ffd0*/
              ; /*0x15ffd2*/
          }
          while ( _InterlockedExchange(v10, 1) == 1 ); /*0x15ffe2*/
          --*(_WORD *)(v2 + 68); /*0x15ffe4*/
          if ( !v9 ) /*0x15ffea*/
            *(_BYTE *)(i + 30) &= ~4u; /*0x15ffec*/
        }
        vm_page_activate(i); /*0x15fff1*/
        v11 = *(_BYTE *)(i + 32); /*0x15fff6*/
        *(_BYTE *)(i + 32) = v11 & 0xFE; /*0x15fffe*/
        if ( (v11 & 2) != 0 ) /*0x160006*/
        {
          *(_BYTE *)(i + 32) = v11 & 0xFC; /*0x16000a*/
          thread_wakeup_prim(i, 0, 0); /*0x160012*/
        }
      }
    }
    _InterlockedExchange((volatile __int32 *)(v2 + 16), 0); /*0x160025*/
    return _InterlockedExchange(&vm_page_queue_lock, 0); /*0x16002c*/
  }
  return result; /*0x160035*/
}
