/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188edc. */
int __cdecl dma_xfer(int a1, _DWORD *a2)
{
  char v2; // al
  char v4; // al
  void *v5; // esi

  v2 = *(_BYTE *)(a1 + 20); /*0x188eeb*/
  if ( (v2 & 0x10) == 0 || *(_DWORD *)a1 <= 0xFFFFFFu || (v2 & 2) != 0 ) /*0x188efc*/
  {
    *a2 = *(_DWORD *)a1; /*0x188f36*/
  }
  else
  {
    if ( !dma_buf_alloc((int **)(a1 + 12), *(_DWORD *)(a1 + 4)) ) /*0x188f03*/
      return 0; /*0x188f11*/
    v4 = *(_BYTE *)(a1 + 20) | 2; /*0x188f17*/
    *(_BYTE *)(a1 + 20) = v4; /*0x188f19*/
    v5 = *(void **)(a1 + 12); /*0x188f1c*/
    if ( (v4 & 8) == 0 ) /*0x188f21*/
      bcopy(*(const void **)a1, v5, *(_DWORD *)(a1 + 4)); /*0x188f2b*/
    *a2 = v5; /*0x188f30*/
  }
  *(_BYTE *)(a1 + 20) |= 1u; /*0x188f38*/
  return 1; /*0x188f44*/
}
