/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c2fc. */
unsigned int getlastaddr()
{
  unsigned int v0; // esi
  segment_command *v1; // edx
  unsigned int i; // ebx

  v0 = 0; /*0x15c301*/
  v1 = &stru_10001C; /*0x15c303*/
  for ( i = 0; i < 7; ++i ) /*0x15c308*/
  {
    if ( v1->cmd == 1 && v1->vmsize + v1->vmaddr > v0 ) /*0x15c321*/
      v0 = v1->vmsize + v1->vmaddr; /*0x15c323*/
    v1 = (segment_command *)((char *)v1 + v1->cmdsize); /*0x15c325*/
  }
  return v0; /*0x15c332*/
}
