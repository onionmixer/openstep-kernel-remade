/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b890. */
int __cdecl lock_read_to_write(int a1)
{
  volatile __int32 *v1; // edx
  __int16 v2; // ax
  char v3; // dl
  volatile __int32 *v5; // esi
  int v6; // edx
  int i; // edx
  volatile __int32 *v8; // edx
  char v9; // al

  v1 = (volatile __int32 *)(a1 + 8); /*0x15b898*/
  do /*0x15b8ae*/
  {
    while ( *v1 ) /*0x15b89c*/
      ; /*0x15b89e*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15b8ae*/
  --*(_WORD *)(a1 + 4); /*0x15b8b0*/
  if ( *(_DWORD *)a1 == active_threads ) /*0x15b8bb*/
  {
    v2 = *(_WORD *)(a1 + 6); /*0x15b8bd*/
    *(_WORD *)(a1 + 6) = ((v2 & 0xFFF0) + 16) | v2 & 0xF; /*0x15b8d1*/
LABEL_25:
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b99f*/
    return 0; /*0x15b9a4*/
  }
  v3 = *(_BYTE *)(a1 + 6); /*0x15b8dc*/
  if ( (v3 & 1) == 0 ) /*0x15b8e2*/
  {
    *(_BYTE *)(a1 + 6) = v3 | 1; /*0x15b917*/
    if ( *(_WORD *)(a1 + 4) ) /*0x15b91a*/
    {
      v5 = (volatile __int32 *)(a1 + 8); /*0x15b921*/
      do /*0x15b998*/
      {
        v6 = lock_wait_time; /*0x15b924*/
        if ( lock_wait_time > 0 ) /*0x15b92c*/
        {
          _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b930*/
          for ( i = v6 - 1; i > 0; --i ) /*0x15b936*/
          {
            if ( !*(_WORD *)(a1 + 4) ) /*0x15b938*/
              break; /*0x15b93f*/
          }
          v8 = (volatile __int32 *)(a1 + 8); /*0x15b946*/
          do /*0x15b95e*/
          {
            while ( *v8 ) /*0x15b94c*/
              ; /*0x15b94e*/
          }
          while ( _InterlockedExchange(v8, 1) == 1 ); /*0x15b95e*/
        }
        v9 = *(_BYTE *)(a1 + 6); /*0x15b960*/
        if ( (v9 & 8) != 0 ) /*0x15b965*/
        {
          if ( !*(_WORD *)(a1 + 4) ) /*0x15b96c*/
            goto LABEL_25; /*0x15b96c*/
          *(_BYTE *)(a1 + 6) = v9 | 4; /*0x15b970*/
          thread_sleep(a1, a1 + 8, 0); /*0x15b977*/
          do /*0x15b996*/
          {
            while ( *v5 ) /*0x15b984*/
              ; /*0x15b986*/
          }
          while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15b996*/
        }
      }
      while ( *(_WORD *)(a1 + 4) ); /*0x15b998*/
    }
    goto LABEL_25; /*0x15b99d*/
  }
  if ( (*(_DWORD *)(a1 + 4) & 0x4FFFF) == 0x40000 ) /*0x15b8f1*/
  {
    *(_BYTE *)(a1 + 6) = v3 & 0xFB; /*0x15b8f6*/
    thread_wakeup_prim(a1, 0, 0); /*0x15b8fe*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b905*/
  return 1; /*0x15b9a9*/
}
