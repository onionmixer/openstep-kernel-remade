/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14073c. */
int ihinit()
{
  int *v0; // eax
  int i; // edx
  int result; // eax

  v0 = &ihead; /*0x14073f*/
  for ( i = 511; i >= 0; --i ) /*0x140744*/
  {
    *v0 = (int)v0; /*0x14074c*/
    v0[1] = (int)v0; /*0x14074e*/
    v0 += 2; /*0x140751*/
  }
  ifreeh = 0; /*0x140757*/
  ifreet = 0; /*0x140761*/
  inode_list = 0; /*0x14076b*/
  result = zinit(232, 2320000, 0, 0, aInodeStructure); /*0x140788*/
  inode_zone = result; /*0x14078d*/
  return result; /*0x140794*/
}
