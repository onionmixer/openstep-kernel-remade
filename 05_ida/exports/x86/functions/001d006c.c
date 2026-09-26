/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d006c. */
BOOL __cdecl sel_isMapped(SEL sel)
{
  _DWORD *v2; // ecx
  int v3; // edx
  int **v4; // eax

  if ( !sel ) /*0x1d0076*/
    return 0; /*0x1d0076*/
  v2 = off_1E5640; /*0x1d0084*/
  if ( !off_1E5640 ) /*0x1d008c*/
    return 0; /*0x1d00d0*/
  while ( v2[3] > (unsigned int)sel || v2[4] <= (unsigned int)sel ) /*0x1d0098*/
  {
    if ( v2 == (_DWORD *)&unk_1E5624 ) /*0x1d00a0*/
    {
      v3 = 0; /*0x1d00a2*/
      if ( dword_1E5628 ) /*0x1d00aa*/
      {
        while ( 1 ) /*0x1d00b0*/
        {
          v4 = *(int ***)(v2[5] + 4 * v3); /*0x1d00b0*/
          if ( v4 ) /*0x1d00b5*/
            break; /*0x1d00b5*/
LABEL_12:
          if ( v2[1] <= (unsigned int)++v3 ) /*0x1d00c7*/
            goto LABEL_13; /*0x1d00c7*/
        }
        while ( v4[1] != (int *)sel ) /*0x1d00bb*/
        {
          v4 = (int **)*v4; /*0x1d00bd*/
          if ( !v4 ) /*0x1d00c1*/
            goto LABEL_12; /*0x1d00c1*/
        }
        return 1; /*0x1d00bb*/
      }
    }
LABEL_13:
    v2 = (_DWORD *)v2[6]; /*0x1d00c9*/
    if ( !v2 ) /*0x1d00ce*/
      return 0; /*0x1d00ce*/
  }
  return 1; /*0x1d00d5*/
}
