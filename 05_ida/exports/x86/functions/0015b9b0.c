/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b9b0. */
__int32 __cdecl lock_write_to_read(int a1)
{
  volatile __int32 *v1; // edx
  char v2; // al
  char v3; // al
  char v4; // al

  v1 = (volatile __int32 *)(a1 + 8); /*0x15b9b7*/
  do /*0x15b9ce*/
  {
    while ( *v1 ) /*0x15b9bc*/
      ; /*0x15b9be*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15b9ce*/
  ++*(_WORD *)(a1 + 4); /*0x15b9d0*/
  if ( (*(_WORD *)(a1 + 6) & 0xFFF0) != 0 ) /*0x15b9dc*/
  {
    *(_WORD *)(a1 + 6) = ((*(_WORD *)(a1 + 6) & 0xFFF0) - 16) | *(_WORD *)(a1 + 6) & 0xF; /*0x15b9ef*/
  }
  else
  {
    v2 = *(_BYTE *)(a1 + 6); /*0x15b9f8*/
    if ( (v2 & 1) != 0 ) /*0x15b9fd*/
      v3 = v2 & 0xFE; /*0x15b9ff*/
    else
      v3 = v2 & 0xFD; /*0x15ba04*/
    *(_BYTE *)(a1 + 6) = v3; /*0x15ba06*/
  }
  v4 = *(_BYTE *)(a1 + 6); /*0x15ba09*/
  if ( (v4 & 4) != 0 ) /*0x15ba0e*/
  {
    *(_BYTE *)(a1 + 6) = v4 & 0xFB; /*0x15ba12*/
    thread_wakeup_prim(a1, 0, 0); /*0x15ba1a*/
  }
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15ba24*/
}
