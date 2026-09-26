/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1679a8. */
int __cdecl thread_hold(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx

  v1 = splsched(); /*0x1679b4*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x1679b6*/
  do /*0x1679ce*/
  {
    while ( *v2 ) /*0x1679bc*/
      ; /*0x1679be*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1679ce*/
  ++*(_DWORD *)(a1 + 64); /*0x1679d0*/
  *(_BYTE *)(a1 + 76) |= 2u; /*0x1679d3*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1679d9*/
  return splx(v1); /*0x1679e2*/
}
