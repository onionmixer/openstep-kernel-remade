/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163450. */
int __cdecl thread_bind(int a1, int a2)
{
  int v2; // ecx
  volatile __int32 *v3; // edx

  v2 = splsched(); /*0x16345d*/
  v3 = (volatile __int32 *)(a1 + 32); /*0x16345f*/
  do /*0x163476*/
  {
    while ( *v3 ) /*0x163464*/
      ; /*0x163466*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x163476*/
  *(_DWORD *)(a1 + 388) = a2; /*0x16347b*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163483*/
  return splx(v2); /*0x16348f*/
}
