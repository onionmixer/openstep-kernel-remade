/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d778. */
void vnode_pager_shutdown()
{
  int **v0; // ebx
  int *v1; // edx
  int *v2; // eax

  for ( ; (int *)dword_1E7288 != &dword_1E7288; --dword_1E7290 ) /*0x17d786*/
  {
    v0 = (int **)dword_1E7288; /*0x17d788*/
    vn_rele(*(_DWORD *)(dword_1E7288 + 8)); /*0x17d792*/
    v1 = *v0; /*0x17d79a*/
    v2 = v0[1]; /*0x17d79c*/
    if ( *v0 == &dword_1E7288 ) /*0x17d7a5*/
      dword_1E728C = (int)v0[1]; /*0x17d7a7*/
    else
      v1[1] = (int)v2; /*0x17d7b0*/
    if ( v2 == &dword_1E7288 ) /*0x17d7b8*/
      dword_1E7288 = (int)v1; /*0x17d7ba*/
    else
      *v2 = (int)v1; /*0x17d7c4*/
  }
}
