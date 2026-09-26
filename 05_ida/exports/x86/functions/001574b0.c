/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1574b0. */
kern_return_t exception_raise_continue_slow(int a1, ...)
{
  int v1; // eax
  thread_act_t v2; // esi
  int v3; // ebx
  volatile __int32 *v4; // edi
  volatile __int32 *v5; // edx
  int v6; // eax
  int (*v7)(); // eax
  unsigned int *v8; // edx
  int v9; // ebx
  kern_return_t result; // eax
  mach_msg_type_number_t v11; // edi
  thread_act_t v12; // esi
  volatile __int32 *v13; // edx
  mach_port_t v14; // ebx
  mach_port_t thread_self_fast; // eax
  thread_act_t v16; // ebx
  mach_port_t task_self_fast; // [esp-10h] [ebp-2Ch]
  int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  exception_data_type_t *code; // [esp+14h] [ebp-8h]
  exception_type_t exception; // [esp+18h] [ebp-4h]
  unsigned int *v22; // [esp+28h] [ebp+Ch] BYREF
  va_list va; // [esp+28h] [ebp+Ch]
  va_list va1; // [esp+2Ch] [ebp+10h] BYREF

  va_start(va1, a1);
  va_start(va, a1);
  v22 = va_arg(va1, unsigned int *); /*0x1574b0*/
  v1 = a1; /*0x1574b9*/
  v2 = active_threads; /*0x1574bc*/
  v3 = *(_DWORD *)(active_threads + 196); /*0x1574c2*/
  v4 = (volatile __int32 *)(v3 + 64); /*0x1574c8*/
  if ( a1 == 268451845 ) /*0x1574d0*/
  {
    while ( 1 ) /*0x15754e*/
    {
      while ( (*(_BYTE *)(v2 + 380) & 3) != 0 ) /*0x15754e*/
      {
        if ( v3 && v3 != -1 ) /*0x1574df*/
          ipc_object_release(v3); /*0x1574e2*/
        *(_DWORD *)(v2 + 196) = 0; /*0x1574ea*/
        v4 = nullptr; /*0x1574f4*/
        thread_halt_self_with_continuation(0); /*0x1574f8*/
        v5 = (volatile __int32 *)(v2 + 168); /*0x1574fd*/
        do /*0x15751a*/
        {
          while ( *v5 ) /*0x157508*/
            ; /*0x15750a*/
        }
        while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15751a*/
        v6 = *(_DWORD *)(v2 + 192); /*0x15751c*/
        *(_DWORD *)(v2 + 196) = v6; /*0x157522*/
        v3 = v6; /*0x157528*/
        if ( v6 && v6 != -1 ) /*0x157531*/
        {
          ipc_object_reference(v6); /*0x157534*/
          v4 = (volatile __int32 *)(v3 + 64); /*0x157539*/
        }
        _InterlockedExchange((volatile __int32 *)(v2 + 168), 0); /*0x157541*/
      }
      if ( !v3 || v3 == -1 ) /*0x15755b*/
        break; /*0x15755b*/
      do /*0x157576*/
      {
        while ( *(_DWORD *)v3 ) /*0x157564*/
          ; /*0x157566*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x157576*/
      if ( *(int *)(v3 + 8) >= 0 ) /*0x15757c*/
      {
        _InterlockedExchange((volatile __int32 *)v3, 0); /*0x157632*/
        break; /*0x157632*/
      }
      do /*0x157596*/
      {
        while ( *v4 ) /*0x157584*/
          ; /*0x157586*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x157596*/
      _InterlockedExchange((volatile __int32 *)v3, 0); /*0x15759a*/
      v7 = nullptr; /*0x1575a4*/
      if ( *(_DWORD *)(v2 + 56) ) /*0x1575a6*/
        v7 = exception_raise_continue; /*0x1575ac*/
      v1 = ipc_mqueue_receive((int)v4, 0, 0xFFFFFFFF, 0, 0, (int)v7, (unsigned int *)va, (int *)va1); /*0x1575bb*/
      if ( v1 != 268451845 ) /*0x1575c8*/
        goto LABEL_24; /*0x1575c8*/
    }
    v1 = 268451849; /*0x157634*/
  }
LABEL_24:
  if ( v3 && v3 != -1 ) /*0x1575d5*/
  {
    v19 = v1; /*0x1575d8*/
    ipc_object_release(v3); /*0x1575db*/
    v1 = v19; /*0x1575e3*/
  }
  if ( !v1 ) /*0x1575e8*/
  {
    ipc_port_release_sonce(v3); /*0x1575ef*/
    v8 = v22; /*0x1575f4*/
    if ( v22[5] == 18 && v22[6] == 32 && v22[10] == 2500 && v22[11] == exc_code_proto ) /*0x157617*/
    {
      v9 = v22[12]; /*0x15763c*/
      if ( v22[2] != 256 || ipc_kmsg_cache ) /*0x15764f*/
      {
        if ( (int)v22[2] > 0 ) /*0x15766d*/
          kfree((int)v22, v22[2]); /*0x15765e*/
        else
          ipc_kmsg_free((int)v22); /*0x157670*/
      }
      else
      {
        ipc_kmsg_cache = (int)v22; /*0x157651*/
      }
      v1 = v9; /*0x157678*/
    }
    else
    {
      v22[7] = 0; /*0x157619*/
      ipc_kmsg_destroy(v8); /*0x157621*/
      v1 = -301; /*0x157626*/
    }
    if ( !v1 ) /*0x15767c*/
      goto LABEL_44; /*0x15767c*/
  }
  if ( v1 == 268451849 ) /*0x157683*/
  {
LABEL_44:
    result = *(_DWORD *)(v2 + 56); /*0x157685*/
    if ( !result ) /*0x15768a*/
      return result; /*0x15768a*/
    call_continuation(*(_DWORD *)(v2 + 56)); /*0x157691*/
  }
  if ( *(_DWORD *)(v2 + 200) ) /*0x157699*/
  {
    exception = *(_DWORD *)(v2 + 200); /*0x1576a7*/
    code = *(exception_data_type_t **)(v2 + 204); /*0x1576b0*/
    v11 = *(_DWORD *)(v2 + 208); /*0x1576b3*/
    v12 = active_threads; /*0x1576b9*/
    v18 = *(_DWORD *)(active_threads + 12); /*0x1576c2*/
    v13 = (volatile __int32 *)(v18 + 100); /*0x1576c7*/
    do /*0x1576de*/
    {
      while ( *v13 ) /*0x1576cc*/
        ; /*0x1576ce*/
    }
    while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1576de*/
    v14 = *(_DWORD *)(v18 + 112); /*0x1576e3*/
    if ( v14 && v14 != -1 ) /*0x1576ed*/
    {
      do /*0x157716*/
      {
        while ( *(_DWORD *)v14 ) /*0x157704*/
          ; /*0x157706*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v14, 1) == 1 ); /*0x157716*/
      _InterlockedExchange((volatile __int32 *)(v18 + 100), 0); /*0x15771d*/
      if ( *(int *)(v14 + 8) < 0 ) /*0x157724*/
      {
        ++*(_DWORD *)(v14 + 4); /*0x157734*/
        ++*(_DWORD *)(v14 + 28); /*0x157737*/
        _InterlockedExchange((volatile __int32 *)v14, 0); /*0x15773c*/
        *(_DWORD *)(v12 + 200) = 0; /*0x15773e*/
        task_self_fast = retrieve_task_self_fast(v18); /*0x15775d*/
        thread_self_fast = retrieve_thread_self_fast(v12); /*0x15775f*/
        return exception_raise(v14, thread_self_fast, task_self_fast, exception, code, v11); /*0x157769*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)v14, 0); /*0x157728*/
        return exception_no_server(); /*0x15772a*/
      }
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(v18 + 100), 0); /*0x1576f4*/
      return exception_no_server(); /*0x1576f7*/
    }
  }
  else
  {
    v16 = active_threads; /*0x157770*/
    while ( (*(_BYTE *)(v16 + 380) & 3) != 0 ) /*0x15777d*/
      thread_halt_self(); /*0x157780*/
    task_terminate(*(_DWORD *)(v16 + 12)); /*0x157792*/
    return thread_halt_self(); /*0x157797*/
  }
}
