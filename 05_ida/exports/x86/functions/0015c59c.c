/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c59c. */
const section *__cdecl getsectbyname(const char *segname, const char *sectname)
{
  segment_command *v2; // edi
  const section *v3; // ebx
  int v4; // esi
  unsigned int i; // [esp+Ch] [ebp-4h]

  v2 = &stru_10001C; /*0x15c5a5*/
  for ( i = 0; ; ++i ) /*0x15c5aa*/
  {
    if ( i >= 7 ) /*0x15c62c*/
      return nullptr; /*0x15c62e*/
    if ( v2->cmd == 1 && !strncmp(v2->segname, segname, 0x10u) ) /*0x15c5c3*/
    {
      v3 = (const section *)&v2[1]; /*0x15c5d8*/
      v4 = 0; /*0x15c5db*/
      if ( v2->nsects ) /*0x15c5dd*/
        break; /*0x15c5dd*/
    }
LABEL_9:
    v2 = (segment_command *)((char *)v2 + v2->cmdsize); /*0x15c61d*/
  }
  while ( strncmp(v3->sectname, sectname, 0x10u) || strncmp(v3->segname, segname, 0x10u) ) /*0x15c60b*/
  {
    ++v3; /*0x15c614*/
    if ( v2->nsects <= ++v4 ) /*0x15c61b*/
      goto LABEL_9; /*0x15c61b*/
  }
  return v3; /*0x15c633*/
}
