/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cacdc. */
unsigned int *__cdecl _NXRemoveHandler(int a1)
{
  unsigned int *result; // eax

  result = (unsigned int *)&unk_1E551C; /*0x1cace2*/
  if ( !&unk_1E551C ) /*0x1cace9*/
    return sub_1CAA08(a1, 0); /*0x1cad03*/
  while ( *result != a1 ) /*0x1cacee*/
  {
    result = (unsigned int *)result[5]; /*0x1cacfc*/
    if ( !result ) /*0x1cad01*/
      return sub_1CAA08(a1, 0); /*0x1cad01*/
  }
  *result = *(_DWORD *)(a1 + 72); /*0x1cacf3*/
  return result; /*0x1cacf7*/
}
