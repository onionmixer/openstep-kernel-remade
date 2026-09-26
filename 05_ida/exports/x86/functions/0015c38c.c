/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c38c. */
const section *__cdecl getsectbynamefromheader(const mach_header *mhp, const char *segname, const char *sectname)
{
  const mach_header *v3; // edi
  const section *v4; // ebx
  int v5; // esi
  uint32_t i; // [esp+Ch] [ebp-4h]

  v3 = mhp + 1; /*0x15c398*/
  for ( i = 0; ; ++i ) /*0x15c39b*/
  {
    if ( mhp->ncmds <= i ) /*0x15c41c*/
      return nullptr; /*0x15c41e*/
    if ( v3->magic == 1 && (!strncmp((const char *)&v3->cpusubtype, segname, 0x10u) || mhp->filetype == 1) ) /*0x15c3c6*/
    {
      v4 = (const section *)&v3[2]; /*0x15c3c8*/
      v5 = 0; /*0x15c3cb*/
      if ( v3[1].sizeofcmds ) /*0x15c3cd*/
        break; /*0x15c3cd*/
    }
LABEL_10:
    v3 = (const mach_header *)((char *)v3 + v3->cputype); /*0x15c40d*/
  }
  while ( strncmp(v4->sectname, sectname, 0x10u) || strncmp(v4->segname, segname, 0x10u) ) /*0x15c3fb*/
  {
    ++v4; /*0x15c404*/
    if ( v3[1].sizeofcmds <= ++v5 ) /*0x15c40b*/
      goto LABEL_10; /*0x15c40b*/
  }
  return v4; /*0x15c423*/
}
