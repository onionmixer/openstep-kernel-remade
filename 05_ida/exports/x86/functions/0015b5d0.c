/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b5d0. */
__int32 __cdecl lock_write(int a1)
{
  volatile __int32 *v1; // edx
  __int16 v2; // ax
  volatile __int32 *v3; // esi
  int v4; // edx
  int i; // edx
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // esi
  int v8; // edx
  int j; // edx
  volatile __int32 *v10; // edx
  char v11; // al

  v1 = (volatile __int32 *)(a1 + 8); /*0x15b5d8*/
  do /*0x15b5ee*/
  {
    while ( *v1 ) /*0x15b5dc*/
      ; /*0x15b5de*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15b5ee*/
  if ( *(_DWORD *)a1 == active_threads ) /*0x15b5f7*/
  {
    v2 = *(_WORD *)(a1 + 6); /*0x15b5f9*/
    *(_WORD *)(a1 + 6) = ((v2 & 0xFFF0) + 16) | v2 & 0xF; /*0x15b60d*/
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 6) & 2) != 0 ) /*0x15b61c*/
    {
      v3 = (volatile __int32 *)(a1 + 8); /*0x15b61e*/
      do /*0x15b698*/
      {
        v4 = lock_wait_time; /*0x15b624*/
        if ( lock_wait_time > 0 ) /*0x15b62c*/
        {
          _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b630*/
          for ( i = v4 - 1; i > 0; --i ) /*0x15b636*/
          {
            if ( (*(_BYTE *)(a1 + 6) & 2) == 0 ) /*0x15b642*/
              break; /*0x15b642*/
          }
          v6 = (volatile __int32 *)(a1 + 8); /*0x15b649*/
          do /*0x15b65e*/
          {
            while ( *v6 ) /*0x15b64c*/
              ; /*0x15b64e*/
          }
          while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15b65e*/
        }
        if ( (*(_BYTE *)(a1 + 6) & 0xA) == 0xA ) /*0x15b669*/
        {
          *(_BYTE *)(a1 + 6) |= 4u; /*0x15b66e*/
          thread_sleep(a1, a1 + 8, 0); /*0x15b675*/
          do /*0x15b692*/
          {
            while ( *v3 ) /*0x15b680*/
              ; /*0x15b682*/
          }
          while ( _InterlockedExchange(v3, 1) == 1 ); /*0x15b692*/
        }
      }
      while ( (*(_BYTE *)(a1 + 6) & 2) != 0 ); /*0x15b698*/
    }
    *(_BYTE *)(a1 + 6) |= 2u; /*0x15b69a*/
    if ( (*(_DWORD *)(a1 + 4) & 0x1FFFF) != 0 ) /*0x15b6a5*/
    {
      v7 = (volatile __int32 *)(a1 + 8); /*0x15b6ab*/
      do /*0x15b72b*/
      {
        v8 = lock_wait_time; /*0x15b6b0*/
        if ( lock_wait_time > 0 ) /*0x15b6b8*/
        {
          _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b6bc*/
          for ( j = v8 - 1; j > 0; --j ) /*0x15b6c2*/
          {
            if ( (*(_DWORD *)(a1 + 4) & 0x1FFFF) == 0 ) /*0x15b6ce*/
              break; /*0x15b6ce*/
          }
          v10 = (volatile __int32 *)(a1 + 8); /*0x15b6d5*/
          do /*0x15b6ea*/
          {
            while ( *v10 ) /*0x15b6d8*/
              ; /*0x15b6da*/
          }
          while ( _InterlockedExchange(v10, 1) == 1 ); /*0x15b6ea*/
        }
        v11 = *(_BYTE *)(a1 + 6); /*0x15b6ec*/
        if ( (v11 & 8) != 0 ) /*0x15b6f1*/
        {
          if ( (*(_DWORD *)(a1 + 4) & 0x1FFFF) == 0 ) /*0x15b6fa*/
            return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b6fa*/
          *(_BYTE *)(a1 + 6) = v11 | 4; /*0x15b6fe*/
          thread_sleep(a1, a1 + 8, 0); /*0x15b705*/
          do /*0x15b722*/
          {
            while ( *v7 ) /*0x15b710*/
              ; /*0x15b712*/
          }
          while ( _InterlockedExchange(v7, 1) == 1 ); /*0x15b722*/
        }
      }
      while ( (*(_DWORD *)(a1 + 4) & 0x1FFFF) != 0 ); /*0x15b72b*/
    }
  }
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b735*/
}
