/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c534. */
const segment_command *__cdecl getsegbyname(const char *segname)
{
  segment_command *v1; // ebx
  int v2; // esi

  v1 = &stru_10001C; /*0x15c53d*/
  v2 = 0; /*0x15c542*/
  while ( v1->cmd != 1 || strncmp(v1->segname, segname, 0x10u) ) /*0x15c562*/
  {
    v1 = (segment_command *)((char *)v1 + v1->cmdsize); /*0x15c564*/
    if ( (unsigned int)++v2 >= 7 ) /*0x15c56e*/
    {
      v1 = nullptr; /*0x15c570*/
      break; /*0x15c570*/
    }
  }
  if ( !v1 && !strcmp(segname, (const char *)(fvm_seg + 8)) ) /*0x15c580*/
    return (const segment_command *)fvm_seg; /*0x15c589*/
  return v1; /*0x15c594*/
}
