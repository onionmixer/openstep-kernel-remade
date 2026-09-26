/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cff8. */
int __cdecl link(const char *a1, const char *a2)
{
  char v2; // dl
  int result; // eax

  v2 = vn_link(**(_DWORD **)(dword_1E875C + 36), *(_DWORD *)(*(_DWORD *)(dword_1E875C + 36) + 4), 0); /*0x11d011*/
  result = dword_1E875C; /*0x11d013*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x11d018*/
  return result; /*0x11d01d*/
}
