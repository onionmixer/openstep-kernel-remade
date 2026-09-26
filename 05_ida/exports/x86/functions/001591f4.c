/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1591f4. */
int __cdecl thread_will_wait(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx

  v1 = splsched(); /*0x159200*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x159202*/
  do /*0x15921a*/
  {
    while ( *v2 ) /*0x159208*/
      ; /*0x15920a*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x15921a*/
  *(_BYTE *)(a1 + 76) |= 1u; /*0x15921c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x159222*/
  return splx(v1); /*0x15922b*/
}
