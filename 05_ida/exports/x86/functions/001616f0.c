/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1616f0. */
void __cdecl pset_deallocate(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // ebx

  if ( a1 ) /*0x1616f9*/
  {
    v1 = (volatile __int32 *)(a1 + 328); /*0x1616fb*/
    do /*0x161716*/
    {
      while ( *v1 ) /*0x161704*/
        ; /*0x161706*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x161716*/
    v2 = *(_DWORD *)(a1 + 324) - 1; /*0x16171e*/
    *(_DWORD *)(a1 + 324) = v2; /*0x161721*/
    if ( v2 <= 0 ) /*0x16172a*/
      panic(aPsetDeallocate); /*0x16173d*/
    _InterlockedExchange((volatile __int32 *)(a1 + 328), 0); /*0x16172e*/
  }
}
