/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16174c. */
__int32 __cdecl pset_reference(int a1)
{
  volatile __int32 *v1; // edx

  v1 = (volatile __int32 *)(a1 + 328); /*0x161752*/
  do /*0x16176a*/
  {
    while ( *v1 ) /*0x161758*/
      ; /*0x16175a*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x16176a*/
  ++*(_DWORD *)(a1 + 324); /*0x16176c*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 328), 0); /*0x16177c*/
}
