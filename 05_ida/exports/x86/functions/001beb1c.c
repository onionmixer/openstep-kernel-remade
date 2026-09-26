/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1beb1c. */
int __cdecl _compar(const void *a1, const void *a2)
{
  __int16 v2; // cx
  __int16 v3; // ax

  v2 = *(_WORD *)(*(_DWORD *)a1 + 2); /*0x1beb29*/
  v3 = *(_WORD *)(*(_DWORD *)a2 + 2); /*0x1beb2d*/
  if ( v2 > v3 ) /*0x1beb34*/
    return 1; /*0x1beb36*/
  if ( v2 == v3 ) /*0x1beb43*/
    return 0; /*0x1beb50*/
  return -1; /*0x1beb3d*/
}
