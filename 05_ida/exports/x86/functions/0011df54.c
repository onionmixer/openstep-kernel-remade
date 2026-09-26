/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11df54. */
__int16 __cdecl vn_rele(int a1)
{
  __int16 result; // ax

  if ( !*(_WORD *)(a1 + 6) ) /*0x11df5b*/
    panic(aVnRele); /*0x11df67*/
  result = *(_WORD *)(a1 + 6); /*0x11df6f*/
  *(_WORD *)(a1 + 6) = result - 1; /*0x11df77*/
  if ( result == 1 ) /*0x11df7f*/
    return (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)(a1 + 28) + 76))(a1, *(_DWORD *)(active_u + 28)); /*0x11df92*/
  return result; /*0x11df94*/
}
