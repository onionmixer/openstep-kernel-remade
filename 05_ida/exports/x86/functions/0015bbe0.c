/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bbe0. */
__int32 __cdecl lock_clear_recursive(int a1)
{
  volatile __int32 *v1; // edx

  v1 = (volatile __int32 *)(a1 + 8); /*0x15bbe7*/
  do /*0x15bbfe*/
  {
    while ( *v1 ) /*0x15bbec*/
      ; /*0x15bbee*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15bbfe*/
  if ( *(_DWORD *)a1 != active_threads ) /*0x15bc07*/
    panic(aLockClearRecur); /*0x15bc0e*/
  if ( (*(_WORD *)(a1 + 6) & 0xFFF0) == 0 ) /*0x15bc19*/
    *(_DWORD *)a1 = -1; /*0x15bc1b*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15bc26*/
}
