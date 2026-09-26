/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3d58. */
int __cdecl sub_1A3D58(unsigned int a1, int *a2)
{
  int *v2; // eax

  v2 = (int *)dword_1E866C; /*0x1a3d61*/
  if ( dword_1E8668 <= a1 ) /*0x1a3d6c*/
    return -704; /*0x1a3d6e*/
  while ( v2 != &dword_1E866C ) /*0x1a3d91*/
  {
    if ( v2[1] == a1 ) /*0x1a3d87*/
    {
      *a2 = *v2; /*0x1a3d7a*/
      return 0; /*0x1a3d81*/
    }
    v2 = (int *)v2[2]; /*0x1a3d89*/
  }
  return -727; /*0x1a3d75*/
}
