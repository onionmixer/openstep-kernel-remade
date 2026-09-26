/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1747a8. */
void __cdecl vm_map_reference(int a1)
{
  volatile __int32 *v1; // edx

  if ( a1 ) /*0x1747b0*/
  {
    v1 = (volatile __int32 *)(a1 + 52); /*0x1747b2*/
    do /*0x1747ca*/
    {
      while ( *v1 ) /*0x1747b8*/
        ; /*0x1747ba*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1747ca*/
    ++*(_DWORD *)(a1 + 48); /*0x1747cc*/
    _InterlockedExchange((volatile __int32 *)(a1 + 52), 0); /*0x1747d1*/
  }
}
