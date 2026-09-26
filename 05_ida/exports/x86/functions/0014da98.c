/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14da98. */
int __cdecl ipc_pset_destroy(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // ecx
  int result; // eax

  *(_DWORD *)(a1 + 8) &= ~0x80000000; /*0x14da9f*/
  v1 = (volatile __int32 *)(a1 + 16); /*0x14daa6*/
  do /*0x14dabe*/
  {
    while ( *v1 ) /*0x14daac*/
      ; /*0x14daae*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x14dabe*/
  ipc_mqueue_changed(a1 + 16, 268451849); /*0x14dac9*/
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x14dad3*/
  v2 = *(_DWORD *)(a1 + 4) - 1; /*0x14dad9*/
  *(_DWORD *)(a1 + 4) = v2; /*0x14dadc*/
  result = v2; /*0x14dadf*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14dae2*/
  if ( !v2 ) /*0x14dae6*/
    return zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14dafa*/
  return result; /*0x14daff*/
}
