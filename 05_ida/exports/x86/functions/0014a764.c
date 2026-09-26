/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a764. */
int __cdecl ipc_mqueue_send(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v7; // ecx
  thread_act_t v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  _DWORD *v12; // edx
  int v13; // edx
  _DWORD *v14; // eax
  _DWORD *v15; // edi
  int v16; // eax
  _DWORD *v17; // [esp+Ch] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 28); /*0x14a770*/
  do /*0x14a786*/
  {
    while ( *(_DWORD *)v4 ) /*0x14a774*/
      ; /*0x14a776*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14a786*/
  if ( *(_DWORD *)(v4 + 12) == ipc_space_kernel ) /*0x14a790*/
  {
    _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a794*/
    v5 = ipc_kobject_server(a1); /*0x14a79a*/
    if ( v5 ) /*0x14a7a4*/
      ipc_mqueue_send(v5, 0, 0, 0); /*0x14a7b0*/
    return 0; /*0x14a7b5*/
  }
  else
  {
    while ( 1 ) /*0x14a7bc*/
    {
      if ( *(int *)(v4 + 8) >= 0 ) /*0x14a7c0*/
      {
        v7 = *(_DWORD *)(v4 + 4) - 1; /*0x14a7c5*/
        *(_DWORD *)(v4 + 4) = v7; /*0x14a7c8*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a7ce*/
        if ( !v7 ) /*0x14a7d2*/
          zfree(ipc_object_zones[*(_WORD *)(v4 + 10) & 0x7FFF], v4); /*0x14a7e6*/
        *(_DWORD *)(a1 + 28) = 0; /*0x14a7f1*/
        ipc_kmsg_destroy((_DWORD *)a1); /*0x14a7f9*/
        return 0; /*0x14a7fe*/
      }
      if ( *(_DWORD *)(v4 + 56) < *(_DWORD *)(v4 + 60) || (a2 & 0x10000) != 0 || *(_BYTE *)(a1 + 20) == 18 ) /*0x14a821*/
        break; /*0x14a821*/
      v8 = active_threads; /*0x14a827*/
      if ( (a2 & 0x10) != 0 ) /*0x14a831*/
      {
        if ( !a3 ) /*0x14a837*/
        {
          _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a906*/
          return 268435460; /*0x14a90d*/
        }
        thread_will_wait_with_timeout(active_threads, a3); /*0x14a842*/
      }
      else
      {
        thread_will_wait(active_threads); /*0x14a84d*/
      }
      ipc_thread_enqueue(v4 + 76, v8); /*0x14a85a*/
      *(_DWORD *)(v8 + 152) = 268435457; /*0x14a85f*/
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a86e*/
      thread_block_with_continuation(0); /*0x14a872*/
      do /*0x14a88e*/
      {
        while ( *(_DWORD *)v4 ) /*0x14a87c*/
          ; /*0x14a87e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14a88e*/
      if ( *(_DWORD *)(v8 + 152) ) /*0x14a890*/
      {
        ipc_thread_rmqueue(v4 + 76, v8); /*0x14a8a2*/
        v9 = *(_DWORD *)(v8 + 68); /*0x14a8aa*/
        if ( v9 == 1 ) /*0x14a8b0*/
        {
          a3 = 0; /*0x14a8d0*/
        }
        else if ( v9 >= 1 && v9 <= 3 ) /*0x14a8bb*/
        {
          _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a8c3*/
          return 268435463; /*0x14a8ca*/
        }
      }
    }
    if ( (*(_BYTE *)(a1 + 23) & 0x40) != 0 ) /*0x14a8e3*/
    {
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a8e7*/
      ipc_kmsg_destroy((_DWORD *)a1); /*0x14a8ea*/
    }
    else
    {
      ++*(_DWORD *)(v4 + 56); /*0x14a8f4*/
      v10 = *(_DWORD *)(v4 + 48); /*0x14a8f7*/
      if ( v10 ) /*0x14a8fc*/
        v11 = v10 + 16; /*0x14a924*/
      else
        v11 = v4 + 64; /*0x14a8fe*/
      do /*0x14a93a*/
      {
        while ( *(_DWORD *)v11 ) /*0x14a928*/
          ; /*0x14a92a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x14a93a*/
      v17 = (_DWORD *)(v11 + 8); /*0x14a93f*/
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14a944*/
      while ( 1 ) /*0x14a94b*/
      {
        v12 = (_DWORD *)*v17; /*0x14a94b*/
        if ( !*v17 ) /*0x14a94b*/
          break; /*0x14a94b*/
        v15 = (_DWORD *)v12[36]; /*0x14a994*/
        if ( v15 == v12 ) /*0x14a99f*/
        {
          *v17 = 0; /*0x14a98b*/
        }
        else
        {
          v16 = v12[37]; /*0x14a9a1*/
          *v17 = v15; /*0x14a9aa*/
          v15[37] = v16; /*0x14a9ac*/
          *(_DWORD *)(v16 + 144) = v15; /*0x14a9b2*/
          v12[36] = v12; /*0x14a9b8*/
          v12[37] = v12; /*0x14a9be*/
        }
        if ( *(_DWORD *)(a1 + 24) <= v12[39] ) /*0x14a9d0*/
        {
          v12[38] = 0; /*0x14a9f8*/
          v12[39] = a1; /*0x14aa02*/
          v12[40] = (*(_DWORD *)(v4 + 52))++; /*0x14aa0b*/
          _InterlockedExchange((volatile __int32 *)v11, 0); /*0x14aa16*/
          if ( (a2 & 0x20000) != 0 ) /*0x14aa1c*/
            thread_go_and_switch(a4, v12); /*0x14a919*/
          else
            thread_go(v12); /*0x14aa23*/
          return 0; /*0x14aa23*/
        }
        v12[38] = 268451844; /*0x14a9d2*/
        v12[39] = *(_DWORD *)(a1 + 24); /*0x14a9e2*/
        thread_go(v12); /*0x14a9e9*/
      }
      v13 = *(_DWORD *)(v11 + 4); /*0x14a951*/
      if ( v13 ) /*0x14a956*/
      {
        v14 = *(_DWORD **)(v13 + 4); /*0x14a958*/
        *(_DWORD *)a1 = v13; /*0x14a95e*/
        *(_DWORD *)(a1 + 4) = v14; /*0x14a960*/
        *(_DWORD *)(v13 + 4) = a1; /*0x14a963*/
        *v14 = a1; /*0x14a966*/
      }
      else
      {
        *(_DWORD *)(v11 + 4) = a1; /*0x14a977*/
        *(_DWORD *)a1 = a1; /*0x14a97d*/
        *(_DWORD *)(a1 + 4) = a1; /*0x14a982*/
      }
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x14a96a*/
    }
    return 0; /*0x14aa28*/
  }
}
