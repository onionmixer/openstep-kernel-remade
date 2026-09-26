/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135c24. */
int __cdecl clntkudp_error(int a1, _DWORD *a2)
{
  _DWORD *v2; // eax
  int result; // eax

  v2 = *(_DWORD **)(a1 + 8); /*0x135c2d*/
  *a2 = v2[10]; /*0x135c33*/
  a2[1] = v2[11]; /*0x135c38*/
  result = v2[12]; /*0x135c3b*/
  a2[2] = result; /*0x135c3e*/
  return result; /*0x135c43*/
}
