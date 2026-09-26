/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188f4c. */
void __cdecl dma_xfer_done(int a1)
{
  char v1; // al

  v1 = *(_BYTE *)(a1 + 20); /*0x188f54*/
  if ( (v1 & 1) != 0 ) /*0x188f59*/
  {
    if ( (v1 & 2) != 0 ) /*0x188f5d*/
    {
      if ( (v1 & 8) != 0 ) /*0x188f67*/
        bcopy(*(const void **)(a1 + 12), *(void **)a1, *(_DWORD *)(a1 + 4)); /*0x188f71*/
      dma_buf_free(a1 + 12); /*0x188f7a*/
    }
    *(_BYTE *)(a1 + 20) &= 0xFCu; /*0x188f7f*/
  }
}
