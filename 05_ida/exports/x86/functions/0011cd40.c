/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cd40. */
int __cdecl creat(const char *a1, mode_t a2)
{
  char v2; // dl
  int result; // eax

  v2 = copen(**(_DWORD **)(dword_1E875C + 36), 0x602u, *(_DWORD *)(*(_DWORD *)(dword_1E875C + 36) + 4)); /*0x11cd5c*/
  result = dword_1E875C; /*0x11cd5e*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x11cd63*/
  return result; /*0x11cd68*/
}
