/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1569c0. */
kern_return_t __cdecl exception(exception_type_t exceptiona, exception_data_t code, mach_msg_type_number_t codeCnt)
{
  thread_act_t v3; // esi
  volatile __int32 *v4; // ebx
  mach_port_t v5; // ebx
  mach_port_t thread_self_fast; // eax
  mach_port_t task_self_fast; // [esp-10h] [ebp-20h]

  v3 = active_threads; /*0x1569cf*/
  if ( !exceptiona ) /*0x1569d7*/
    panic(aException); /*0x1569e1*/
  *(_DWORD *)(active_threads + 56) = thread_exception_return; /*0x1569ec*/
  v4 = (volatile __int32 *)(v3 + 168); /*0x1569f3*/
  do /*0x156a0e*/
  {
    while ( *v4 ) /*0x1569fc*/
      ; /*0x1569fe*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x156a0e*/
  v5 = *(_DWORD *)(v3 + 180); /*0x156a10*/
  if ( !v5 || v5 == -1 ) /*0x156a1d*/
  {
    _InterlockedExchange((volatile __int32 *)(v3 + 168), 0); /*0x156a21*/
    return exception_try_task(exceptiona, code, codeCnt); /*0x156a5d*/
  }
  do /*0x156a3e*/
  {
    while ( *(_DWORD *)v5 ) /*0x156a2c*/
      ; /*0x156a2e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v5, 1) == 1 ); /*0x156a3e*/
  _InterlockedExchange((volatile __int32 *)(v3 + 168), 0); /*0x156a42*/
  if ( *(int *)(v5 + 8) >= 0 ) /*0x156a4c*/
  {
    _InterlockedExchange((volatile __int32 *)v5, 0); /*0x156a50*/
    return exception_try_task(exceptiona, code, codeCnt); /*0x156a50*/
  }
  ++*(_DWORD *)(v5 + 4); /*0x156a60*/
  ++*(_DWORD *)(v5 + 28); /*0x156a63*/
  _InterlockedExchange((volatile __int32 *)v5, 0); /*0x156a68*/
  *(_DWORD *)(v3 + 200) = exceptiona; /*0x156a6a*/
  *(_DWORD *)(v3 + 204) = code; /*0x156a73*/
  *(_DWORD *)(v3 + 208) = codeCnt; /*0x156a79*/
  task_self_fast = retrieve_task_self_fast(*(_DWORD *)(v3 + 12)); /*0x156a8e*/
  thread_self_fast = retrieve_thread_self_fast(v3); /*0x156a90*/
  return exception_raise(v5, thread_self_fast, task_self_fast, exceptiona, code, codeCnt); /*0x156aa2*/
}
