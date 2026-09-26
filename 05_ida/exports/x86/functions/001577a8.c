/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1577a8. */
int __cdecl exception_raise_continue_fast(int a1, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // esi
  thread_act_t v6; // esi
  int v7; // ecx
  volatile __int32 *v8; // edx
  mach_port_t v9; // ebx
  mach_port_t thread_self_fast; // eax
  thread_act_t v11; // ebx
  mach_port_t task_self_fast; // [esp-10h] [ebp-28h]
  mach_msg_type_number_t codeCnt; // [esp+Ch] [ebp-Ch]
  exception_data_type_t *code; // [esp+10h] [ebp-8h]
  exception_type_t exception; // [esp+14h] [ebp-4h]

  v2 = (_DWORD *)active_threads; /*0x1577b7*/
  --*(_DWORD *)(a1 + 32); /*0x1577bd*/
  *(_DWORD *)(a1 + 4) -= 2; /*0x1577c0*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1577c6*/
  if ( a2[5] == 18 && a2[6] == 32 && a2[10] == 2500 && a2[11] == exc_code_proto ) /*0x1577e5*/
  {
    v4 = a2[12]; /*0x157800*/
    if ( a2[2] != 256 || ipc_kmsg_cache ) /*0x157813*/
    {
      if ( (int)a2[2] > 0 ) /*0x157831*/
        kfree((int)a2, a2[2]); /*0x157822*/
      else
        ipc_kmsg_free((int)a2); /*0x157834*/
    }
    else
    {
      ipc_kmsg_cache = (int)a2; /*0x157815*/
    }
    v3 = v4; /*0x15783c*/
  }
  else
  {
    a2[7] = 0; /*0x1577e7*/
    ipc_kmsg_destroy(a2); /*0x1577ef*/
    v3 = -301; /*0x1577f4*/
  }
  if ( v3 ) /*0x157840*/
  {
    if ( v2[50] ) /*0x15785c*/
    {
      exception = v2[50]; /*0x15786a*/
      code = (exception_data_type_t *)v2[51]; /*0x157873*/
      codeCnt = v2[52]; /*0x15787c*/
      v6 = active_threads; /*0x15787f*/
      v7 = *(_DWORD *)(active_threads + 12); /*0x157885*/
      v8 = (volatile __int32 *)(v7 + 100); /*0x157888*/
      do /*0x15789e*/
      {
        while ( *v8 ) /*0x15788c*/
          ; /*0x15788e*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x15789e*/
      v9 = *(_DWORD *)(v7 + 112); /*0x1578a0*/
      if ( v9 && v9 != -1 ) /*0x1578aa*/
      {
        do /*0x1578ca*/
        {
          while ( *(_DWORD *)v9 ) /*0x1578b8*/
            ; /*0x1578ba*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v9, 1) == 1 ); /*0x1578ca*/
        _InterlockedExchange((volatile __int32 *)(v7 + 100), 0); /*0x1578ce*/
        if ( *(int *)(v9 + 8) < 0 ) /*0x1578d5*/
        {
          ++*(_DWORD *)(v9 + 4); /*0x1578e4*/
          ++*(_DWORD *)(v9 + 28); /*0x1578e7*/
          _InterlockedExchange((volatile __int32 *)v9, 0); /*0x1578ec*/
          *(_DWORD *)(v6 + 200) = 0; /*0x1578ee*/
          task_self_fast = retrieve_task_self_fast(v7); /*0x15790d*/
          thread_self_fast = retrieve_thread_self_fast(v6); /*0x15790f*/
          exception_raise(v9, thread_self_fast, task_self_fast, exception, code, codeCnt); /*0x157919*/
        }
        else
        {
          _InterlockedExchange((volatile __int32 *)v9, 0); /*0x1578d9*/
          exception_no_server(); /*0x1578db*/
        }
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)(v7 + 100), 0); /*0x1578ae*/
        exception_no_server(); /*0x1578b1*/
      }
    }
    v11 = active_threads; /*0x157921*/
    while ( (*(_BYTE *)(v11 + 380) & 3) != 0 ) /*0x15792e*/
      thread_halt_self(); /*0x157930*/
    task_terminate(*(_DWORD *)(v11 + 12)); /*0x157942*/
    return thread_halt_self(); /*0x157947*/
  }
  else
  {
    if ( v2[14] ) /*0x157842*/
      call_continuation(v2[14]); /*0x15784a*/
    return thread_exception_return(); /*0x157852*/
  }
}
