/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1656ac. */
int __cdecl thread_depress_timeout(int a1)
{
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // eax

  v1 = splsched(); /*0x1656b9*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x1656bb*/
  do /*0x1656d2*/
  {
    while ( *v2 ) /*0x1656c0*/
      ; /*0x1656c2*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1656d2*/
  v3 = *(_DWORD *)(a1 + 100); /*0x1656d4*/
  if ( v3 >= 0 ) /*0x1656d9*/
  {
    *(_DWORD *)(a1 + 80) = v3; /*0x1656db*/
    *(_DWORD *)(a1 + 100) = -1; /*0x1656de*/
    compute_priority((_DWORD *)a1, 0); /*0x1656e8*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1656f2*/
  return splx(v1); /*0x1656fe*/
}
