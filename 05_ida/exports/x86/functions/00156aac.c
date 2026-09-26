/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156aac. */
kern_return_t __cdecl exception_from_kernel(
        exception_type_t exception,
        exception_data_t code,
        mach_msg_type_number_t codeCnt)
{
  _DWORD *v3; // edi
  thread_act_t v4; // esi
  volatile __int32 *v5; // ebx
  mach_port_t v6; // ebx
  kern_return_t result; // eax
  mach_port_t thread_self_fast; // eax
  mach_port_t task_self_fast; // [esp-10h] [ebp-30h]
  int v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]

  v3 = (_DWORD *)active_threads; /*0x156ab8*/
  v13 = *(_DWORD *)(active_threads + 56); /*0x156ac1*/
  v12 = *(_DWORD *)(active_threads + 200); /*0x156aca*/
  v11 = *(_DWORD *)(active_threads + 204); /*0x156ad3*/
  v10 = *(_DWORD *)(active_threads + 208); /*0x156adc*/
  v4 = active_threads; /*0x156adf*/
  if ( !exception ) /*0x156ae3*/
    panic(aException); /*0x156aed*/
  *(_DWORD *)(active_threads + 56) = 0; /*0x156af8*/
  v5 = v3 + 42; /*0x156aff*/
  do /*0x156b1a*/
  {
    while ( *v5 ) /*0x156b08*/
      ; /*0x156b0a*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x156b1a*/
  v6 = *(_DWORD *)(v4 + 180); /*0x156b1c*/
  if ( v6 && v6 != -1 ) /*0x156b29*/
  {
    do /*0x156b4a*/
    {
      while ( *(_DWORD *)v6 ) /*0x156b38*/
        ; /*0x156b3a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x156b4a*/
    _InterlockedExchange((volatile __int32 *)(v4 + 168), 0); /*0x156b4e*/
    if ( *(int *)(v6 + 8) < 0 ) /*0x156b58*/
    {
      ++*(_DWORD *)(v6 + 4); /*0x156b70*/
      ++*(_DWORD *)(v6 + 28); /*0x156b73*/
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x156b78*/
      *(_DWORD *)(v4 + 200) = exception; /*0x156b7a*/
      *(_DWORD *)(v4 + 204) = code; /*0x156b83*/
      *(_DWORD *)(v4 + 208) = codeCnt; /*0x156b8c*/
      task_self_fast = retrieve_task_self_fast(*(_DWORD *)(v4 + 12)); /*0x156ba4*/
      thread_self_fast = retrieve_thread_self_fast(v4); /*0x156ba6*/
      result = exception_raise(v6, thread_self_fast, task_self_fast, exception, code, codeCnt); /*0x156bb0*/
      goto LABEL_15; /*0x156bb0*/
    }
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x156b5c*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(v4 + 168), 0); /*0x156b2d*/
  }
  result = exception_try_task(exception, code, codeCnt); /*0x156b67*/
LABEL_15:
  v3[14] = v13; /*0x156bb5*/
  v3[50] = v12; /*0x156bbe*/
  v3[51] = v11; /*0x156bc7*/
  v3[52] = v10; /*0x156bd0*/
  return result; /*0x156bd9*/
}
