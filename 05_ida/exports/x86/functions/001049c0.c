/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1049c0. */
int __cdecl free_file(int **a1)
{
  int *v1; // edx
  int *v2; // eax

  v1 = *a1; /*0x1049c7*/
  v2 = a1[1]; /*0x1049c9*/
  if ( *a1 == &file_list ) /*0x1049d2*/
    dword_1E89DC = (int)a1[1]; /*0x1049d4*/
  else
    v1[1] = (int)v2; /*0x1049dc*/
  if ( v2 == &file_list ) /*0x1049e4*/
    file_list = (int)v1; /*0x1049e6*/
  else
    *v2 = (int)v1; /*0x1049f0*/
  return zfree(file_zone, a1); /*0x1049ff*/
}
