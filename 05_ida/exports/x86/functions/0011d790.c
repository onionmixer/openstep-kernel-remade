/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d790. */
int __cdecl stat(const char *a1, stat *a2)
{
  char v2; // dl
  int result; // eax

  v2 = stat1(*(int **)(dword_1E875C + 36), 1); /*0x11d7a3*/
  result = dword_1E875C; /*0x11d7a5*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x11d7aa*/
  return result; /*0x11d7af*/
}
