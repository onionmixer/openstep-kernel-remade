/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10943c. */
int __cdecl sigsetmask(int a1)
{
  int *v1; // ebx
  int v2; // esi
  int v3; // edx
  unsigned int v4; // eax

  v1 = *(int **)(dword_1E875C + 36); /*0x109446*/
  v2 = *(_DWORD *)active_u; /*0x10944e*/
  splhigh(); /*0x109450*/
  *(_DWORD *)(dword_1E875C + 96) = *(_DWORD *)(v2 + 28); /*0x10945d*/
  v3 = *v1; /*0x109460*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x10946d*/
    v4 = v3 & 0xFFFEFEFF; /*0x109471*/
  else
    v4 = v3 & 0xFFFAFEFF; /*0x10947a*/
  *(_DWORD *)(v2 + 28) = v4; /*0x10947f*/
  return spl0(); /*0x10948a*/
}
