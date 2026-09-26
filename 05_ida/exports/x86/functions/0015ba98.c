/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ba98. */
int __cdecl lock_try_read(int a1)
{
  volatile __int32 *v1; // edx

  v1 = (volatile __int32 *)(a1 + 8); /*0x15ba9e*/
  do /*0x15bab6*/
  {
    while ( *v1 ) /*0x15baa4*/
      ; /*0x15baa6*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15bab6*/
  if ( *(_DWORD *)a1 == active_threads || (*(_BYTE *)(a1 + 6) & 3) == 0 ) /*0x15bad8*/
  {
    ++*(_WORD *)(a1 + 4); /*0x15bac1*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15bac7*/
    return 1; /*0x15baca*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15badc*/
    return 0; /*0x15badf*/
  }
}
