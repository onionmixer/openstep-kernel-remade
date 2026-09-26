/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1893e0. */
int __cdecl is_dma_done(int a1)
{
  unsigned int v1; // ebx
  unsigned __int16 v2; // dx
  unsigned __int8 v3; // al
  int v4; // eax

  v1 = a1; /*0x1893e4*/
  us_spin(1); /*0x1893e9*/
  if ( a1 > 3 ) /*0x1893f1*/
    v2 = word_1E18A0; /*0x1893fc*/
  else
    v2 = _dma_chip_port; /*0x1893f3*/
  v3 = __inbyte(v2); /*0x189403*/
  if ( a1 <= 3 ) /*0x189407*/
  {
    v4 = prev_tcstatus0 | v3 & 0xF; /*0x18941f*/
    prev_tcstatus0 = v4; /*0x189425*/
  }
  else
  {
    v1 = a1 - 4; /*0x189409*/
    v4 = prev_tcstatus1 | v3 & 0xF; /*0x18940f*/
    prev_tcstatus1 = v4; /*0x189415*/
  }
  return _bittest(&v4, v1); /*0x189435*/
}
