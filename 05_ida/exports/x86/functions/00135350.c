/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135350. */
_DWORD *__cdecl clntkudp_interruptable(int a1, int a2)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(a1 + 8); /*0x135356*/
  if ( a2 ) /*0x13535d*/
    *result |= 0x800u; /*0x13535f*/
  else
    *result &= ~0x800u; /*0x13536c*/
  return result; /*0x135367*/
}
