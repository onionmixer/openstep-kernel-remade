/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0ddc. */
void __cdecl -[IODirectDevice abortDMABuffer:](IODirectDevice *self, SEL a2, void *a3)
{
  if ( (*((_BYTE *)a3 + 20) & 1) != 0 ) /*0x1c0de9*/
    dma_xfer_abort((int)a3); /*0x1c0dec*/
  IOFree((int)a3, 24); /*0x1c0df7*/
}
