/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b73c. */
__int32 __cdecl lock_done(int a1)
{
  volatile __int32 *v1; // edx
  __int16 v2; // ax
  char v3; // al
  char v4; // al

  v1 = (volatile __int32 *)(a1 + 8); /*0x15b743*/
  do /*0x15b75a*/
  {
    while ( *v1 ) /*0x15b748*/
      ; /*0x15b74a*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15b75a*/
  v2 = *(_WORD *)(a1 + 4); /*0x15b75c*/
  if ( v2 ) /*0x15b763*/
  {
    *(_WORD *)(a1 + 4) = v2 - 1; /*0x15b767*/
  }
  else if ( (*(_WORD *)(a1 + 6) & 0xFFF0) != 0 ) /*0x15b778*/
  {
    *(_WORD *)(a1 + 6) = ((*(_WORD *)(a1 + 6) & 0xFFF0) - 16) | *(_WORD *)(a1 + 6) & 0xF; /*0x15b78b*/
  }
  else
  {
    v3 = *(_BYTE *)(a1 + 6); /*0x15b794*/
    if ( (v3 & 1) != 0 ) /*0x15b799*/
      v4 = v3 & 0xFE; /*0x15b79b*/
    else
      v4 = v3 & 0xFD; /*0x15b7a0*/
    *(_BYTE *)(a1 + 6) = v4; /*0x15b7a2*/
  }
  if ( (*(_DWORD *)(a1 + 4) & 0x4FFFF) == 0x40000 ) /*0x15b7b2*/
  {
    *(_BYTE *)(a1 + 6) &= ~4u; /*0x15b7b4*/
    thread_wakeup_prim(a1, 0, 0); /*0x15b7bd*/
  }
  return _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15b7c7*/
}
