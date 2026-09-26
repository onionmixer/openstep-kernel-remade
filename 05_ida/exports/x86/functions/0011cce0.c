/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cce0. */
int open(const char *a1, int a2, ...)
{
  int *v2; // ebx
  int posix_proc; // esi
  char v4; // dl
  int result; // eax

  v2 = *(int **)(dword_1E875C + 36); /*0x11ccea*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x11ccfe*/
  *(_BYTE *)(posix_proc + 24) = (2 * ((v2[1] & 0x10) != 0)) | *(_BYTE *)(posix_proc + 24) & 0xFD; /*0x11cd14*/
  v4 = copen(*v2, v2[1] + 1, v2[2]); /*0x11cd28*/
  result = dword_1E875C; /*0x11cd2a*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11cd2f*/
  *(_BYTE *)(posix_proc + 24) &= ~2u; /*0x11cd32*/
  return result; /*0x11cd39*/
}
