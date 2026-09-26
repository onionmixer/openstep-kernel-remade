/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bae8. */
int __cdecl lock_try_read_to_write(int a1)
{
  volatile __int32 *v1; // edx
  __int16 v2; // ax
  char v3; // al
  __int16 v5; // ax
  volatile __int32 *v6; // ebx

  v1 = (volatile __int32 *)(a1 + 8); /*0x15baf0*/
  do /*0x15bb06*/
  {
    while ( *v1 ) /*0x15baf4*/
      ; /*0x15baf6*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15bb06*/
  if ( *(_DWORD *)a1 == active_threads ) /*0x15bb0f*/
  {
    --*(_WORD *)(a1 + 4); /*0x15bb11*/
    v2 = *(_WORD *)(a1 + 6); /*0x15bb15*/
    *(_WORD *)(a1 + 6) = ((v2 & 0xFFF0) + 16) | v2 & 0xF; /*0x15bb29*/
  }
  else
  {
    v3 = *(_BYTE *)(a1 + 6); /*0x15bb30*/
    if ( (v3 & 1) != 0 ) /*0x15bb35*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15bb39*/
      return 0; /*0x15bb3e*/
    }
    *(_BYTE *)(a1 + 6) = v3 | 1; /*0x15bb42*/
    v5 = *(_WORD *)(a1 + 4); /*0x15bb45*/
    *(_WORD *)(a1 + 4) = v5 - 1; /*0x15bb4d*/
    if ( v5 != 1 ) /*0x15bb55*/
    {
      v6 = (volatile __int32 *)(a1 + 8); /*0x15bb57*/
      do /*0x15bb80*/
      {
        *(_BYTE *)(a1 + 6) |= 4u; /*0x15bb5c*/
        thread_sleep(a1, a1 + 8, 0); /*0x15bb64*/
        do /*0x15bb7e*/
        {
          while ( *v6 ) /*0x15bb6c*/
            ; /*0x15bb6e*/
        }
        while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15bb7e*/
      }
      while ( *(_WORD *)(a1 + 4) ); /*0x15bb80*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15bb89*/
  return 1; /*0x15bb94*/
}
