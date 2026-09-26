/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165610. */
int __cdecl thread_depress_priority(int a1, int a2)
{
  unsigned int v2; // esi
  int v3; // edi
  volatile __int32 *v4; // edx

  v2 = (hz * a2 + 999) / 0x3E8u; /*0x165631*/
  v3 = splsched(); /*0x165638*/
  v4 = (volatile __int32 *)(a1 + 32); /*0x16563a*/
  do /*0x165652*/
  {
    while ( *v4 ) /*0x165640*/
      ; /*0x165642*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x165652*/
  if ( *(_DWORD *)(a1 + 372) ) /*0x165654*/
    reset_timeout(a1 + 328); /*0x165664*/
  *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 80); /*0x16566f*/
  *(_DWORD *)(a1 + 80) = 0; /*0x165672*/
  *(_DWORD *)(a1 + 88) = 0; /*0x165679*/
  if ( v2 ) /*0x165682*/
    set_timeout(a1 + 328, v2); /*0x16568c*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x165696*/
  return splx(v3); /*0x1656a2*/
}
