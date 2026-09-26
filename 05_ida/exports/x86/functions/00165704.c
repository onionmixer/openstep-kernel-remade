/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165704. */
kern_return_t __cdecl thread_depress_abort(thread_act_t thread)
{
  int v2; // esi
  volatile __int32 *v3; // edx

  if ( !thread ) /*0x16570e*/
    return 4; /*0x165710*/
  v2 = splsched(); /*0x16571d*/
  v3 = (volatile __int32 *)(thread + 32); /*0x16571f*/
  do /*0x165736*/
  {
    while ( *v3 ) /*0x165724*/
      ; /*0x165726*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x165736*/
  if ( *(int *)(thread + 100) >= 0 ) /*0x16573c*/
  {
    if ( *(_DWORD *)(thread + 372) ) /*0x16573e*/
      reset_timeout(thread + 328); /*0x16574e*/
    *(_DWORD *)(thread + 80) = *(_DWORD *)(thread + 100); /*0x165759*/
    *(_DWORD *)(thread + 100) = -1; /*0x16575c*/
    compute_priority((_DWORD *)thread, 0); /*0x165766*/
  }
  _InterlockedExchange((volatile __int32 *)(thread + 32), 0); /*0x165770*/
  splx(v2); /*0x165774*/
  return 0; /*0x16577e*/
}
