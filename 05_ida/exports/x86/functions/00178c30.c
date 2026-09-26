/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178c30. */
void __cdecl vm_object_reference(int a1)
{
  volatile __int32 *v1; // edx

  if ( a1 ) /*0x178c38*/
  {
    v1 = (volatile __int32 *)(a1 + 16); /*0x178c3a*/
    do /*0x178c52*/
    {
      while ( *v1 ) /*0x178c40*/
        ; /*0x178c42*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x178c52*/
    ++*(_WORD *)(a1 + 24); /*0x178c54*/
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x178c5a*/
  }
}
