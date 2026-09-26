/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0db4. */
void __cdecl -[IODirectDevice freeDMABuffer:](IODirectDevice *self, SEL a2, void *a3)
{
  if ( (*((_BYTE *)a3 + 20) & 1) != 0 ) /*0x1c0dc1*/
    dma_xfer_done((int)a3); /*0x1c0dc4*/
  IOFree((int)a3, 24); /*0x1c0dcf*/
}
