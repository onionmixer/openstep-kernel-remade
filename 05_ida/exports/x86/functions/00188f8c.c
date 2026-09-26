/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188f8c. */
void __cdecl dma_xfer_abort(int a1)
{
  char v1; // al

  v1 = *(_BYTE *)(a1 + 20); /*0x188f93*/
  if ( (v1 & 1) != 0 ) /*0x188f98*/
  {
    if ( (v1 & 2) != 0 ) /*0x188f9c*/
      dma_buf_free(a1 + 12); /*0x188fa2*/
    *(_BYTE *)(a1 + 20) &= 0xFCu; /*0x188fa7*/
  }
}
