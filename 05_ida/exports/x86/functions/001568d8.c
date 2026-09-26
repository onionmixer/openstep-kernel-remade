/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1568d8. */
kern_return_t __cdecl exception_with_continuation(
        exception_type_t exception,
        exception_data_t code,
        mach_msg_type_number_t codeCnt,
        int a4)
{
  thread_act_t v4; // esi
  volatile __int32 *v5; // ebx
  mach_port_t v6; // ebx
  mach_port_t thread_self_fast; // eax
  mach_port_t task_self_fast; // [esp-10h] [ebp-20h]

  v4 = active_threads; /*0x1568e7*/
  if ( !exception ) /*0x1568ef*/
    panic(aException); /*0x1568f9*/
  *(_DWORD *)(active_threads + 56) = a4; /*0x156907*/
  v5 = (volatile __int32 *)(v4 + 168); /*0x15690a*/
  do /*0x156922*/
  {
    while ( *v5 ) /*0x156910*/
      ; /*0x156912*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x156922*/
  v6 = *(_DWORD *)(v4 + 180); /*0x156924*/
  if ( !v6 || v6 == -1 ) /*0x156931*/
  {
    _InterlockedExchange((volatile __int32 *)(v4 + 168), 0); /*0x156935*/
    return exception_try_task(exception, code, codeCnt); /*0x156971*/
  }
  do /*0x156952*/
  {
    while ( *(_DWORD *)v6 ) /*0x156940*/
      ; /*0x156942*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x156952*/
  _InterlockedExchange((volatile __int32 *)(v4 + 168), 0); /*0x156956*/
  if ( *(int *)(v6 + 8) >= 0 ) /*0x156960*/
  {
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x156964*/
    return exception_try_task(exception, code, codeCnt); /*0x156964*/
  }
  ++*(_DWORD *)(v6 + 4); /*0x156974*/
  ++*(_DWORD *)(v6 + 28); /*0x156977*/
  _InterlockedExchange((volatile __int32 *)v6, 0); /*0x15697c*/
  *(_DWORD *)(v4 + 200) = exception; /*0x15697e*/
  *(_DWORD *)(v4 + 204) = code; /*0x156987*/
  *(_DWORD *)(v4 + 208) = codeCnt; /*0x15698d*/
  task_self_fast = retrieve_task_self_fast(*(_DWORD *)(v4 + 12)); /*0x1569a2*/
  thread_self_fast = retrieve_thread_self_fast(v4); /*0x1569a4*/
  return exception_raise(v6, thread_self_fast, task_self_fast, exception, code, codeCnt); /*0x1569b6*/
}
