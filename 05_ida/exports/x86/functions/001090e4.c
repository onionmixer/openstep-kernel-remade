/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1090e4. */
void fd_shutdown()
{
  int v0; // ebx
  int *v1; // esi

  v0 = file_list; /*0x1090e9*/
  if ( (int *)file_list != &file_list ) /*0x1090f5*/
  {
    do /*0x10911c*/
    {
      v1 = *(int **)v0; /*0x1090f8*/
      while ( *(__int16 *)(v0 + 14) > 0 ) /*0x1090ff*/
        closef(v0); /*0x109105*/
      v0 = (int)v1; /*0x109114*/
    }
    while ( v1 != &file_list ); /*0x10911c*/
  }
}
