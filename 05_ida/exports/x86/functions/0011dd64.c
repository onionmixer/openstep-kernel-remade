/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dd64. */
mode_t __cdecl umask(mode_t a1)
{
  _WORD *v1; // ecx
  mode_t result; // ax

  v1 = *(_WORD **)(dword_1E875C + 36); /*0x11dd6d*/
  *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(active_u + 366); /*0x11dd7c*/
  result = active_u; /*0x11dd7f*/
  LOWORD(v1) = *v1; /*0x11dd84*/
  BYTE1(v1) &= 0xFu; /*0x11dd87*/
  *(_WORD *)(active_u + 366) = (_WORD)v1; /*0x11dd8a*/
  return result; /*0x11dd93*/
}
