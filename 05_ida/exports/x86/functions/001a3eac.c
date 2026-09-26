/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3eac. */
int __cdecl sub_1A3EAC(unsigned int a1, int **a2)
{
  int *v3; // eax

  if ( dword_1E8678 < a1 ) /*0x1a3ebb*/
    return -704; /*0x1a3ebd*/
  v3 = (int *)dword_1E867C; /*0x1a3ed0*/
  if ( (int *)dword_1E867C == &dword_1E867C ) /*0x1a3eda*/
    return -727; /*0x1a3eeb*/
  while ( v3[1] != a1 ) /*0x1a3edf*/
  {
    v3 = (int *)v3[5]; /*0x1a3ee1*/
    if ( v3 == &dword_1E867C ) /*0x1a3ee9*/
      return -727; /*0x1a3ee9*/
  }
  *a2 = v3; /*0x1a3ec8*/
  return 0; /*0x1a3ec4*/
}
