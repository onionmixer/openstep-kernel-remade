/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b7d0. */
__int32 __cdecl lock_read(int a1)
{
  volatile __int32 *v1; // edx
  volatile __int32 *v2; // esi
  int v3; // edx
  int i; // edx
  volatile __int32 *v5; // edx
  char v6; // al

  v1 = (volatile __int32 *)(a1 + 8); /*0x15b7d8*/
  do /*0x15b7ee*/
  {
    while ( *v1 ) /*0x15b7dc*/
      ; /*0x15b7de*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15b7ee*/
  if ( *(_DWORD *)a1 != active_threads && (*(_BYTE *)(a1 + 6) & 3) != 0 ) /*0x15b801*/
  {
    v2 = (volatile __int32 *)(a1 + 8); /*0x15b803*/
    do /*0x15b87c*/
    {
      v3 = lock_wait_time; /*0x15b808*/
      if ( lock_wait_time > 0 ) /*0x15b810*/
      {
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b814*/
        for ( i = v3 - 1; i > 0; --i ) /*0x15b81a*/
        {
          if ( (*(_BYTE *)(a1 + 6) & 3) == 0 ) /*0x15b826*/
            break; /*0x15b826*/
        }
        v5 = (volatile __int32 *)(a1 + 8); /*0x15b82d*/
        do /*0x15b842*/
        {
          while ( *v5 ) /*0x15b830*/
            ; /*0x15b832*/
        }
        while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15b842*/
      }
      v6 = *(_BYTE *)(a1 + 6); /*0x15b844*/
      if ( (v6 & 8) != 0 ) /*0x15b849*/
      {
        if ( (v6 & 3) == 0 ) /*0x15b84d*/
          break; /*0x15b84d*/
        *(_BYTE *)(a1 + 6) = v6 | 4; /*0x15b851*/
        thread_sleep(a1, a1 + 8, 0); /*0x15b858*/
        do /*0x15b876*/
        {
          while ( *v2 ) /*0x15b864*/
            ; /*0x15b866*/
        }
        while ( _InterlockedExchange(v2, 1) == 1 ); /*0x15b876*/
      }
    }
    while ( (*(_BYTE *)(a1 + 6) & 3) != 0 ); /*0x15b87c*/
  }
  ++*(_WORD *)(a1 + 4); /*0x15b87e*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b88a*/
}
