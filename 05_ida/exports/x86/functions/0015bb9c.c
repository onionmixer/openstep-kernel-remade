/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bb9c. */
__int32 __cdecl lock_set_recursive(int a1)
{
  volatile __int32 *v1; // edx

  v1 = (volatile __int32 *)(a1 + 8); /*0x15bba3*/
  do /*0x15bbba*/
  {
    while ( *v1 ) /*0x15bba8*/
      ; /*0x15bbaa*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15bbba*/
  if ( (*(_BYTE *)(a1 + 6) & 2) == 0 ) /*0x15bbc0*/
    panic(aLockSetRecursi); /*0x15bbc7*/
  *(_DWORD *)a1 = active_threads; /*0x15bbd2*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15bbd9*/
}
