/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156be0. */
kern_return_t __cdecl exception_try_task(
        exception_type_t exception,
        exception_data_t code,
        mach_msg_type_number_t codeCnt)
{
  thread_act_t v3; // esi
  int v4; // ecx
  volatile __int32 *v5; // edx
  mach_port_t v6; // ebx
  mach_port_t thread_self_fast; // eax
  mach_port_t task_self_fast; // [esp-10h] [ebp-1Ch]

  v3 = active_threads; /*0x156be6*/
  v4 = *(_DWORD *)(active_threads + 12); /*0x156bec*/
  v5 = (volatile __int32 *)(v4 + 100); /*0x156bef*/
  do /*0x156c06*/
  {
    while ( *v5 ) /*0x156bf4*/
      ; /*0x156bf6*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x156c06*/
  v6 = *(_DWORD *)(v4 + 112); /*0x156c08*/
  if ( v6 && v6 != -1 ) /*0x156c12*/
  {
    do /*0x156c32*/
    {
      while ( *(_DWORD *)v6 ) /*0x156c20*/
        ; /*0x156c22*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x156c32*/
    _InterlockedExchange((volatile __int32 *)(v4 + 100), 0); /*0x156c36*/
    if ( *(int *)(v6 + 8) < 0 ) /*0x156c3d*/
    {
      ++*(_DWORD *)(v6 + 4); /*0x156c4c*/
      ++*(_DWORD *)(v6 + 28); /*0x156c4f*/
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x156c54*/
      *(_DWORD *)(v3 + 200) = 0; /*0x156c56*/
      task_self_fast = retrieve_task_self_fast(v4); /*0x156c75*/
      thread_self_fast = retrieve_thread_self_fast(v3); /*0x156c77*/
      return exception_raise(v6, thread_self_fast, task_self_fast, exception, code, codeCnt); /*0x156c81*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x156c41*/
      return exception_no_server(); /*0x156c43*/
    }
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(v4 + 100), 0); /*0x156c16*/
    return exception_no_server(); /*0x156c19*/
  }
}
