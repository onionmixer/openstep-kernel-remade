/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17bacc. */
int __cdecl sub_17BACC(int a1, int a2)
{
  volatile __int32 *v3; // ebx
  volatile __int32 *v4; // edi
  char v5; // al
  _DWORD *v6; // [esp+Ch] [ebp-8h]
  _BOOL4 v7; // [esp+10h] [ebp-4h]

  v6 = *(_DWORD **)(a1 + 40); /*0x17bade*/
  do /*0x17bafd*/
  {
    while ( vm_page_queue_lock ) /*0x17baeb*/
      ; /*0x17bae9*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17bafd*/
  if ( (*(_BYTE *)(a2 + 30) & 0x20) == 0 || pmap_is_modified(*(_DWORD *)(a2 + 36)) ) /*0x17bb09*/
  {
    if ( (*(_BYTE *)(a2 + 32) & 1) != 0 ) /*0x17bb28*/
    {
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17bb2c*/
      *(_BYTE *)(a2 + 32) |= 2u; /*0x17bb32*/
      assert_wait(a2, 0); /*0x17bb39*/
      v3 = (volatile __int32 *)(a1 + 16); /*0x17bb3e*/
      _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x17bb46*/
      thread_block(); /*0x17bb49*/
      do /*0x17bb62*/
      {
        while ( *v3 ) /*0x17bb50*/
          ; /*0x17bb52*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x17bb62*/
      return 2; /*0x17bb64*/
    }
    else
    {
      ++*(_WORD *)(a1 + 68); /*0x17bb70*/
      *(_BYTE *)(a2 + 32) |= 1u; /*0x17bb74*/
      if ( (*(_BYTE *)(a2 + 30) & 1) != 0 ) /*0x17bb7c*/
        vm_page_activate(a2); /*0x17bb7f*/
      vm_page_deactivate(a2); /*0x17bb88*/
      pmap_remove_all(*(_DWORD *)(a2 + 36)); /*0x17bb91*/
      ++dword_1F6510; /*0x17bb96*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17bba1*/
      if ( v6 ) /*0x17bbab*/
      {
        v4 = (volatile __int32 *)(a1 + 16); /*0x17bbbc*/
        _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x17bbc1*/
        v7 = vm_pager_put(v6, a2) != 0; /*0x17bbdc*/
        do /*0x17bbfa*/
        {
          while ( *v4 ) /*0x17bbe8*/
            ; /*0x17bbea*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x17bbfa*/
        do /*0x17bc15*/
        {
          while ( vm_page_queue_lock ) /*0x17bc03*/
            ; /*0x17bc01*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x17bc15*/
        v5 = *(_BYTE *)(a2 + 32); /*0x17bc17*/
        *(_BYTE *)(a2 + 32) = v5 & 0xFE; /*0x17bc1f*/
        if ( (v5 & 2) != 0 ) /*0x17bc24*/
        {
          *(_BYTE *)(a2 + 32) = v5 & 0xFC; /*0x17bc28*/
          thread_wakeup_prim(a2, 0, 0); /*0x17bc30*/
        }
        --*(_WORD *)(a1 + 68); /*0x17bc35*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17bc3b*/
        return v7; /*0x17bc41*/
      }
      else
      {
        --*(_WORD *)(a1 + 68); /*0x17bbad*/
        return 1; /*0x17bbb1*/
      }
    }
  }
  else
  {
    _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17bb17*/
    return 0; /*0x17bb1d*/
  }
}
