/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d17c. */
int __cdecl rmdir(const char *a1)
{
  char v1; // dl
  int result; // eax

  v1 = vn_remove(**(_DWORD **)(dword_1E875C + 36), 0, 1); /*0x11d193*/
  result = dword_1E875C; /*0x11d195*/
  *(_BYTE *)(dword_1E875C + 104) = v1; /*0x11d19a*/
  return result; /*0x11d19f*/
}
