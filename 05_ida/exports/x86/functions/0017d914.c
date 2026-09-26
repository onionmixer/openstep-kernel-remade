/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d914. */
int vswap_allocate()
{
  int *v0; // ebx
  int v1; // edi
  int i; // ecx
  int *j; // eax

  v0 = nullptr; /*0x17d91d*/
  v1 = 0; /*0x17d91f*/
  if ( dword_1E7290 <= 1 ) /*0x17d92a*/
  {
    if ( dword_1E7290 == 1 ) /*0x17d983*/
      return dword_1E7288; /*0x17d985*/
  }
  else
  {
    for ( i = 0; i <= 3; ++i ) /*0x17d92c*/
    {
      for ( j = (int *)dword_1E7288; j != &dword_1E7288; j = (int *)*j ) /*0x17d93a*/
      {
        if ( (i > 1 || j[11]) && ((i & 1) != 0 || *(_UNKNOWN **)(j[2] + 28) == &ufs_vnodeops) && j[6] > v1 ) /*0x17d964*/
        {
          v1 = j[6]; /*0x17d966*/
          v0 = j; /*0x17d968*/
        }
      }
      if ( v0 ) /*0x17d975*/
        break; /*0x17d975*/
    }
  }
  return (int)v0; /*0x17d990*/
}
