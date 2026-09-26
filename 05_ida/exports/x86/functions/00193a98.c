/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193a98. */
void *startup_early()
{
  unsigned int v0; // ebx
  void *result; // eax

  cfree = (int)dword_1F6E74; /*0x193aab*/
  ncache = (int)dword_1F6E74 + 64 * nclist; /*0x193abb*/
  if ( !nbuf ) /*0x193ad3*/
  {
    nbuf = (mem_size / 0x32u) >> page_shift; /*0x193aed*/
    if ( nbuf > 255 ) /*0x193af7*/
      nbuf = 255; /*0x193af9*/
  }
  if ( nbuf <= 15 ) /*0x193b0a*/
    nbuf = 16; /*0x193b0c*/
  bufpages = nbuf * (0x2000 / page_size); /*0x193b2c*/
  buf = ncache + 72 * ncsize; /*0x193b31*/
  v0 = ncache + 72 * ncsize + 68 * nbuf; /*0x193b3e*/
  if ( !nmfsbuf ) /*0x193b48*/
    nmfsbuf = nbuf / 2; /*0x193b53*/
  bzero(dword_1F6E74, v0 - (_DWORD)dword_1F6E74); /*0x193b5e*/
  result = (void *)pmap_resident_extract((_DWORD *)kernel_pmap, v0); /*0x193b6b*/
  dword_1F6E74 = result; /*0x193b70*/
  return result; /*0x193b76*/
}
