/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167238. */
void __cdecl thread_reference(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx

  if ( a1 ) /*0x167241*/
  {
    v1 = splsched(); /*0x167248*/
    v2 = (volatile __int32 *)(a1 + 32); /*0x16724a*/
    do /*0x167262*/
    {
      while ( *v2 ) /*0x167250*/
        ; /*0x167252*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x167262*/
    ++*(_DWORD *)(a1 + 36); /*0x167264*/
    _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167269*/
    splx(v1); /*0x16726d*/
  }
}
