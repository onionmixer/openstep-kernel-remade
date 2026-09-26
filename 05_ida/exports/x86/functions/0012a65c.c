/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a65c. */
_DWORD *__cdecl tcp_newtcpcb(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ebx

  v1 = (_DWORD *)kalloc(0x6Cu); /*0x12a666*/
  v2 = v1; /*0x12a66b*/
  if ( !v1 ) /*0x12a672*/
    return nullptr; /*0x12a674*/
  bzero(v1, 0x6Cu); /*0x12a67b*/
  v2[1] = v2; /*0x12a680*/
  *v2 = v2; /*0x12a683*/
  *((_WORD *)v2 + 12) = tcp_mssdflt; /*0x12a68c*/
  *((_BYTE *)v2 + 27) = 0; /*0x12a690*/
  v2[8] = a1; /*0x12a694*/
  *((_WORD *)v2 + 48) = 0; /*0x12a697*/
  *((_WORD *)v2 + 49) = 8 * tcp_rttdflt; /*0x12a6a8*/
  *((_WORD *)v2 + 50) = 2; /*0x12a6ac*/
  *((_WORD *)v2 + 10) = 12; /*0x12a6b2*/
  *((_WORD *)v2 + 42) = -1; /*0x12a6b8*/
  *((_WORD *)v2 + 43) = -1; /*0x12a6be*/
  *(_DWORD *)(a1 + 32) = v2; /*0x12a6c4*/
  return v2; /*0x12a6cc*/
}
