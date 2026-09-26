/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168a18. */
kern_return_t __cdecl thread_wire(host_priv_t host_priv, thread_act_t thread, boolean_t wired)
{
  int v4; // esi
  volatile __int32 *v5; // edx

  if ( !host_priv || !thread || active_threads != thread ) /*0x168a30*/
    return 4; /*0x168a32*/
  v4 = splsched(); /*0x168a41*/
  v5 = (volatile __int32 *)(thread + 32); /*0x168a43*/
  do /*0x168a5a*/
  {
    while ( *v5 ) /*0x168a48*/
      ; /*0x168a4a*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x168a5a*/
  if ( wired ) /*0x168a60*/
  {
    *(_DWORD *)(thread + 120) = 1; /*0x168a62*/
    if ( active_threads != thread ) /*0x168a6f*/
      panic(aStackPrivilege); /*0x168a76*/
    if ( !*(_DWORD *)(thread + 48) ) /*0x168a7e*/
      *(_DWORD *)(thread + 48) = active_stacks; /*0x168a8a*/
  }
  else
  {
    *(_DWORD *)(thread + 120) = 0; /*0x168a90*/
    *(_DWORD *)(thread + 48) = 0; /*0x168a97*/
  }
  _InterlockedExchange((volatile __int32 *)(thread + 32), 0); /*0x168aa0*/
  splx(v4); /*0x168aa4*/
  return 0; /*0x168aae*/
}
