/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f7b4. */
void __cdecl pmap_reference(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx

  if ( a1 ) /*0x18f7bd*/
  {
    v1 = splvm(); /*0x18f7c4*/
    v2 = (volatile __int32 *)(a1 + 12); /*0x18f7c6*/
    do /*0x18f7de*/
    {
      while ( *v2 ) /*0x18f7cc*/
        ; /*0x18f7ce*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x18f7de*/
    ++*(_DWORD *)(a1 + 8); /*0x18f7e0*/
    _InterlockedExchange((volatile __int32 *)(a1 + 12), 0); /*0x18f7e5*/
    splx(v1); /*0x18f7e9*/
  }
}
