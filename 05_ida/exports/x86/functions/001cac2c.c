/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cac2c. */
unsigned int *__cdecl _NXRemoveAltHandler(int a1)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // ecx
  unsigned int *result; // eax

  v1 = &unk_1E551C; /*0x1cac33*/
  if ( !&unk_1E551C ) /*0x1cac3a*/
    return sub_1CAA08(a1, 1); /*0x1cac8b*/
  while ( *v1 != a1 ) /*0x1cac52*/
  {
    v1 = (_DWORD *)v1[5]; /*0x1cac84*/
    if ( !v1 ) /*0x1cac89*/
      return sub_1CAA08(a1, 1); /*0x1cac89*/
  }
  v2 = (_DWORD *)(v1[1] + 12 * ((a1 - 1) / 2)); /*0x1cac56*/
  result = (unsigned int *)((4 * ((a1 - 1) / 2)) >> 2); /*0x1cac77*/
  v1[3] = result; /*0x1cac7a*/
  *v1 = *v2; /*0x1cac7f*/
  return result; /*0x1cac93*/
}
