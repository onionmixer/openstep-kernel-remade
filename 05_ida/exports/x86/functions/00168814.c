/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168814. */
int __cdecl thread_set_own_priority(int a1)
{
  thread_act_t v1; // ebx
  int v2; // edi
  volatile __int32 *v3; // edx

  v1 = active_threads; /*0x16881d*/
  v2 = splsched(); /*0x168828*/
  v3 = (volatile __int32 *)(v1 + 32); /*0x16882a*/
  do /*0x168842*/
  {
    while ( *v3 ) /*0x168830*/
      ; /*0x168832*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x168842*/
  if ( *(_DWORD *)(v1 + 84) > a1 ) /*0x168847*/
    *(_DWORD *)(v1 + 84) = a1; /*0x168849*/
  *(_DWORD *)(v1 + 80) = a1; /*0x16884c*/
  compute_priority((_DWORD *)v1, 1); /*0x168852*/
  _InterlockedExchange((volatile __int32 *)(v1 + 32), 0); /*0x16885c*/
  return splx(v2); /*0x168868*/
}
