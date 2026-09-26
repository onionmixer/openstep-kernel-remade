/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1898ec. */
void *sub_1898EC()
{
  void *v0; // eax
  void *v1; // ebx

  v0 = (void *)alloc_cnvmem(0x10000, 0x10000); /*0x1898fa*/
  v1 = v0; /*0x1898ff*/
  if ( v0 ) /*0x189906*/
    bzero(v0, 0x10000u); /*0x18990e*/
  return v1; /*0x189915*/
}
