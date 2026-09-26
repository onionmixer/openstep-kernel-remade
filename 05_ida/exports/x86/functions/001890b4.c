/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1890b4. */
int __cdecl get_dma_xfer_width(unsigned int a1)
{
  int v1; // eax

  v1 = (unsigned __int8)dma_assigned_bits; /*0x1890ba*/
  if ( _bittest(&v1, a1) ) /*0x1890c1*/
    return ((unsigned __int8)byte_1F74F1[2 * a1] >> 2) & 3; /*0x1890d0*/
  else
    return -1; /*0x1890d8*/
}
