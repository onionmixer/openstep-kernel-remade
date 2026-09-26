/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1094a0. */
int __cdecl sigpause(int a1)
{
  int *v1; // edx
  int v2; // ecx
  int v3; // edx
  unsigned int v4; // eax

  v1 = *(int **)(dword_1E875C + 36); /*0x1094a9*/
  v2 = *(_DWORD *)active_u; /*0x1094b1*/
  *(_DWORD *)(active_u + 324) = *(_DWORD *)(*(_DWORD *)active_u + 28); /*0x1094b6*/
  *(_DWORD *)(v2 + 40) |= 0x200u; /*0x1094bc*/
  v3 = *v1; /*0x1094c3*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x1094d0*/
    v4 = v3 & 0xFFFEFEFF; /*0x1094d4*/
  else
    v4 = v3 & 0xFFFAFEFF; /*0x1094de*/
  *(_DWORD *)(v2 + 28) = v4; /*0x1094e3*/
  return sleep_with_continuation(&active_u); /*0x1094f7*/
}
