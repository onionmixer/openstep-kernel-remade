/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d020. */
int __cdecl rename(const char *__old, const char *__new)
{
  char v2; // dl
  int result; // eax

  v2 = vn_rename(**(_DWORD **)(dword_1E875C + 36), *(_DWORD *)(*(_DWORD *)(dword_1E875C + 36) + 4), 0); /*0x11d039*/
  result = dword_1E875C; /*0x11d03b*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x11d040*/
  return result; /*0x11d045*/
}
