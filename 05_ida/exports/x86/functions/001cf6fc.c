/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf6fc. */
int __cdecl sub_1CF6FC(_DWORD *a1, _DWORD *a2)
{
  if ( a1[3] ) /*0x1cf705*/
  {
    if ( !a2[3] ) /*0x1cf70b*/
      return -1; /*0x1cf719*/
  }
  else if ( !a2[3] ) /*0x1cf720*/
  {
    return a2[5] - a1[5]; /*0x1cf720*/
  }
  if ( !a1[3] ) /*0x1cf722*/
    return 1; /*0x1cf730*/
  return a2[5] - a1[5]; /*0x1cf718*/
}
