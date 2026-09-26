/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4070. */
void __cdecl +[IODevice unregisterClass:](id a1, SEL a2, id a3)
{
  int *v3; // eax
  int *v4; // ecx
  int *v5; // edx
  int *v6; // eax
  int *v7; // eax

  objc_msgSend(dword_1E8684, sel_lock); /*0x1a4086*/
  v3 = (int *)dword_1E867C; /*0x1a408b*/
  if ( (int *)dword_1E867C != &dword_1E867C ) /*0x1a4098*/
  {
    while ( (id)*v3 != a3 ) /*0x1a409e*/
    {
      v3 = (int *)v3[5]; /*0x1a40d0*/
      if ( v3 == &dword_1E867C ) /*0x1a40d8*/
        goto LABEL_9; /*0x1a40d8*/
    }
    v4 = (int *)v3[5]; /*0x1a40a0*/
    v5 = (int *)v3[6]; /*0x1a40a3*/
    v6 = &dword_1E867C; /*0x1a40a6*/
    if ( v4 != &dword_1E867C ) /*0x1a40b1*/
      v6 = v4 + 5; /*0x1a40b3*/
    v6[1] = (int)v5; /*0x1a40b6*/
    v7 = &dword_1E867C; /*0x1a40b9*/
    if ( v5 != &dword_1E867C ) /*0x1a40c4*/
      v7 = v5 + 5; /*0x1a40c6*/
    *v7 = (int)v4; /*0x1a40c9*/
  }
LABEL_9:
  objc_msgSend(dword_1E8684, sel_unlock); /*0x1a40da*/
}
