/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135544. */
_DWORD *__cdecl clntkudp_init(int a1, _DWORD *a2, int a3, _WORD *a4)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(a1 + 8); /*0x135551*/
  result[4] = a3; /*0x135557*/
  result[6] = *a2; /*0x13555c*/
  result[7] = a2[1]; /*0x135562*/
  result[8] = a2[2]; /*0x135568*/
  result[9] = a2[3]; /*0x13556e*/
  result[29] = a4; /*0x135571*/
  ++*a4; /*0x135574*/
  *result &= 0x18u; /*0x135577*/
  return result; /*0x13557a*/
}
