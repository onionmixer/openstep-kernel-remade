/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bd48. */
int logopen()
{
  unsigned int v1; // eax
  unsigned int i; // edx

  if ( log_open ) /*0x10bd52*/
    return 16; /*0x10bd54*/
  dword_1E97C4 = 0; /*0x10bd60*/
  dword_1E97C8 = *(__int16 *)(*(_DWORD *)active_u + 46); /*0x10bd75*/
  dword_1E97CC = calloutEntryAllocate(sub_10BF90, 0); /*0x10bd86*/
  log_open = 1; /*0x10bd8b*/
  v1 = pmsgbuf; /*0x10bd95*/
  if ( *(_DWORD *)pmsgbuf != 405601 ) /*0x10bda0*/
  {
    *(_DWORD *)pmsgbuf = 405601; /*0x10bda2*/
    *(_DWORD *)(v1 + 8) = 0; /*0x10bda8*/
    *(_DWORD *)(v1 + 4) = 0; /*0x10bdaf*/
    for ( i = 0; i <= 0xFF3; ++i ) /*0x10bdb6*/
      *(_BYTE *)(i + pmsgbuf + 12) = 0; /*0x10bdbd*/
  }
  return 0; /*0x10bd5b*/
}
