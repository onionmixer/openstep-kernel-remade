/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188234. */
int __cdecl dma_assign_chan(unsigned int a1)
{
  int v1; // eax

  v1 = (unsigned __int8)dma_assigned_bits; /*0x188240*/
  if ( _bittest(&v1, a1) ) /*0x188246*/
    return 0; /*0x188260*/
  dma_assigned_bits |= 1 << a1; /*0x188251*/
  return 1; /*0x18825e*/
}
