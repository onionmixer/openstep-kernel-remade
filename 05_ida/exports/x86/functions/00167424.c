/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167424. */
void __cdecl thread_force_terminate(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v3; // ebx

  ipc_thread_disable(a1); /*0x16742d*/
  v1 = splsched(); /*0x167437*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x167439*/
  do /*0x167452*/
  {
    while ( *v2 ) /*0x167440*/
      ; /*0x167442*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x167452*/
  v3 = *(_DWORD *)(a1 + 376); /*0x167454*/
  *(_DWORD *)(a1 + 376) = 0; /*0x16745a*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167466*/
  splx(v1); /*0x16746a*/
  thread_halt(a1, 1); /*0x167472*/
  ipc_thread_terminate(a1); /*0x167478*/
  if ( v3 ) /*0x167482*/
    thread_deallocate(a1); /*0x167485*/
}
