/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185a8c. */
int __cdecl kdp_getstate(_DWORD *a1)
{
  unsigned __int16 *v1; // eax
  int result; // eax

  v1 = (unsigned __int16 *)dword_1F66AC; /*0x185a95*/
  qmemcpy(a1, &unk_1D13F4, 0x40u); /*0x185aa9*/
  *a1 = *((_DWORD *)v1 + 11); /*0x185aae*/
  a1[1] = *((_DWORD *)v1 + 8); /*0x185ab3*/
  a1[2] = *((_DWORD *)v1 + 10); /*0x185ab9*/
  a1[3] = *((_DWORD *)v1 + 9); /*0x185abf*/
  a1[4] = *((_DWORD *)v1 + 4); /*0x185ac5*/
  a1[5] = *((_DWORD *)v1 + 5); /*0x185acb*/
  a1[6] = *((_DWORD *)v1 + 6); /*0x185ad1*/
  a1[7] = v1 + 34; /*0x185ad7*/
  a1[8] = v1[36]; /*0x185ade*/
  a1[9] = *((_DWORD *)v1 + 16); /*0x185ae4*/
  a1[10] = *((_DWORD *)v1 + 14); /*0x185aea*/
  a1[11] = v1[30]; /*0x185af1*/
  a1[12] = v1[6]; /*0x185af8*/
  a1[13] = v1[4]; /*0x185aff*/
  a1[14] = v1[2]; /*0x185b06*/
  result = *v1; /*0x185b09*/
  a1[15] = result; /*0x185b0c*/
  return result; /*0x185b12*/
}
