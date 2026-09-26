/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c6b4. */
char *getfakefvmseg()
{
  segment_command *v0; // ebx
  int v1; // esi
  char *result; // eax
  segment_command *v3; // edx
  int v4; // ecx
  segment_command *v5; // ebx

  v0 = &stru_10001C; /*0x15c6ba*/
  v1 = 0; /*0x15c6bf*/
  while ( v0->cmd != 1 || strncmp(v0->segname, _s1, 0x10u) ) /*0x15c6e6*/
  {
    v0 = (segment_command *)((char *)v0 + v0->cmdsize); /*0x15c6e8*/
    if ( (unsigned int)++v1 >= 7 ) /*0x15c6f2*/
    {
      v0 = nullptr; /*0x15c6f4*/
      break; /*0x15c6f4*/
    }
  }
  if ( !v0 && !strcmp(_s1, (const char *)(fvm_seg + 8)) ) /*0x15c708*/
    v0 = (segment_command *)fvm_seg; /*0x15c714*/
  result = (char *)v0; /*0x15c71a*/
  v3 = &stru_10001C; /*0x15c71c*/
  v4 = 0; /*0x15c721*/
  while ( v3->cmd != 9 ) /*0x15c733*/
  {
    v3 = (segment_command *)((char *)v3 + v3->cmdsize); /*0x15c735*/
    if ( (unsigned int)++v4 >= 7 ) /*0x15c73b*/
    {
      v5 = nullptr; /*0x15c73d*/
      goto LABEL_13; /*0x15c73d*/
    }
  }
  v5 = v3; /*0x15c748*/
LABEL_13:
  if ( !result ) /*0x15c741*/
  {
    if ( v5 ) /*0x15c74e*/
    {
      fvm_seg = (int)&unk_1DEE8C; /*0x15c754*/
      dword_1DEEA4 = *(_DWORD *)&v5->segname[4]; /*0x15c761*/
      dword_1DEEA8 = sub_15C7A4(dword_1DEEA4); /*0x15c76d*/
      result = strcpy(_dst, *(const char **)v5->segname); /*0x15c77b*/
      dword_1DEEE4 = dword_1DEEA4; /*0x15c786*/
      dword_1DEEE8 = dword_1DEEA8; /*0x15c792*/
    }
    else
    {
      return nullptr; /*0x15c750*/
    }
  }
  return result; /*0x15c79b*/
}
