/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fc80. */
unsigned int __cdecl rlock(unsigned int a1)
{
  unsigned int result; // eax
  __int16 v2; // dx

  while ( 1 ) /*0x12fca8*/
  {
    v2 = *(_WORD *)(a1 + 96); /*0x12fca8*/
    if ( (v2 & 1) == 0 ) /*0x12fcaf*/
      break; /*0x12fcaf*/
    result = active_threads; /*0x12fc8c*/
    if ( *(_DWORD *)(a1 + 104) == active_threads ) /*0x12fc94*/
      break; /*0x12fc94*/
    LOBYTE(v2) = v2 | 2; /*0x12fc96*/
    *(_WORD *)(a1 + 96) = v2; /*0x12fc99*/
    result = sleep(a1); /*0x12fca0*/
  }
  *(_DWORD *)(a1 + 104) = active_threads; /*0x12fcb7*/
  ++*(_WORD *)(a1 + 108); /*0x12fcba*/
  *(_BYTE *)(a1 + 96) |= 1u; /*0x12fcbe*/
  return result; /*0x12fcc2*/
}
