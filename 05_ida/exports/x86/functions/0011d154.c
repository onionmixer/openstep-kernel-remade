/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d154. */
int __cdecl unlink(const char *a1)
{
  char v1; // dl
  int result; // eax

  v1 = vn_remove(**(_DWORD **)(dword_1E875C + 36), 0, 0); /*0x11d16b*/
  result = dword_1E875C; /*0x11d16d*/
  *(_BYTE *)(dword_1E875C + 104) = v1; /*0x11d172*/
  return result; /*0x11d177*/
}
