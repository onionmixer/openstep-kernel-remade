/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188268. */
int __cdecl dma_deassign_chan(int a1)
{
  int result; // eax

  dma_mask_chan(a1); /*0x188270*/
  result = __ROL4__(-2, a1); /*0x18827c*/
  dma_assigned_bits &= result; /*0x18827e*/
  return result; /*0x188284*/
}
