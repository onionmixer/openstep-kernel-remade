/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11aa3c. */
int getnewbuf_count()
{
  int v0; // ebx
  int v1; // eax
  int *v2; // ecx
  int *i; // edx

  v0 = 0; /*0x11aa40*/
  v1 = splbio(); /*0x11aa42*/
  v2 = (int *)&unk_1E87E8; /*0x11aa47*/
  if ( &unk_1E87E8 > (_UNKNOWN *)&bfreelist ) /*0x11aa52*/
  {
    do /*0x11aa6d*/
    {
      for ( i = (int *)v2[3]; i != v2; ++v0 ) /*0x11aa59*/
        i = (int *)i[3]; /*0x11aa5c*/
      v2 -= 17; /*0x11aa64*/
    }
    while ( v2 > &bfreelist ); /*0x11aa6d*/
  }
  splx(v1); /*0x11aa70*/
  return v0; /*0x11aa77*/
}
