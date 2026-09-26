/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1898bc. */
void *sub_1898BC()
{
  void *v0; // eax
  void *v1; // ebx

  v0 = (void *)alloc_cnvmem(page_size, page_size); /*0x1898c8*/
  v1 = v0; /*0x1898cd*/
  if ( v0 ) /*0x1898d4*/
    bzero(v0, page_size); /*0x1898de*/
  return v1; /*0x1898e5*/
}
