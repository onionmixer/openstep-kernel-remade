/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159234. */
int __cdecl thread_will_wait_with_timeout(int a1, int a2)
{
  unsigned int v2; // esi
  int v3; // edi
  volatile __int32 *v4; // edx

  v2 = (hz * a2 + 999) / 0x3E8u; /*0x159255*/
  v3 = splsched(); /*0x15925c*/
  v4 = (volatile __int32 *)(a1 + 32); /*0x15925e*/
  do /*0x159276*/
  {
    while ( *v4 ) /*0x159264*/
      ; /*0x159266*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x159276*/
  *(_BYTE *)(a1 + 76) |= 1u; /*0x159278*/
  if ( v2 || !a2 ) /*0x159284*/
    set_timeout(a1 + 280, v2); /*0x15928e*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x159298*/
  return splx(v3); /*0x1592a4*/
}
