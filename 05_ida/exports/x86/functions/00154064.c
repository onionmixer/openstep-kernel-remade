/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154064. */
int __cdecl mach_msg_interrupt(_DWORD *a1)
{
  int v1; // ebx

  v1 = a1[55]; /*0x15406c*/
  do /*0x154086*/
  {
    while ( *(_DWORD *)v1 ) /*0x154074*/
      ; /*0x154076*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x154086*/
  if ( a1[38] == 268451841 ) /*0x154092*/
  {
    ipc_thread_rmqueue((_DWORD *)(v1 + 8), (int)a1); /*0x154099*/
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x1540a3*/
    ipc_object_release(a1[54]); /*0x1540ac*/
    thread_set_syscall_return(a1, 268451845); /*0x1540b7*/
    a1[13] = thread_exception_return; /*0x1540bc*/
    return 1; /*0x1540c3*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x1540ce*/
    return 0; /*0x1540d0*/
  }
}
