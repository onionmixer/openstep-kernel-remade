/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3e30. */
int __cdecl sub_1A3E30(int a1, int **a2)
{
  int *v2; // eax

  objc_msgSend(dword_1E8684, sel_lock); /*0x1a3e49*/
  v2 = (int *)dword_1E867C; /*0x1a3e4e*/
  if ( (int *)dword_1E867C == &dword_1E867C ) /*0x1a3e5b*/
  {
LABEL_5:
    objc_msgSend(dword_1E8684, sel_unlock); /*0x1a3e8a*/
    return -727; /*0x1a3e9d*/
  }
  else
  {
    while ( *v2 != a1 ) /*0x1a3e62*/
    {
      v2 = (int *)v2[5]; /*0x1a3e80*/
      if ( v2 == &dword_1E867C ) /*0x1a3e88*/
        goto LABEL_5; /*0x1a3e88*/
    }
    *a2 = v2; /*0x1a3e64*/
    objc_msgSend(dword_1E8684, sel_unlock); /*0x1a3e74*/
    return 0; /*0x1a3e79*/
  }
}
