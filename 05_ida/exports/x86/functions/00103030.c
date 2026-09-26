/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103030. */
unsigned int cinit()
{
  _DWORD *v0; // ecx
  unsigned int result; // eax

  v0 = (_DWORD *)(cfree + 63); /*0x10303c*/
  LOBYTE(v0) = (cfree + 63) & 0xC0; /*0x10303e*/
  for ( result = cfree + (nclist << 6) - 64; (unsigned int)v0 < result; v0 += 16 ) /*0x103055*/
  {
    *v0 = cfreelist; /*0x10305e*/
    cfreelist = (int)v0; /*0x103060*/
    cfreecount += 52; /*0x103066*/
  }
  return result; /*0x103074*/
}
