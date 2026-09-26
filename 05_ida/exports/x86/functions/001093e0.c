/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1093e0. */
int __cdecl sigblock(int a1)
{
  int *v1; // ebx
  int v2; // esi
  int v3; // edx
  unsigned int v4; // eax

  v1 = *(int **)(dword_1E875C + 36); /*0x1093eb*/
  v2 = *(_DWORD *)active_u; /*0x1093f3*/
  splhigh(); /*0x1093f5*/
  *(_DWORD *)(dword_1E875C + 96) = *(_DWORD *)(v2 + 28); /*0x109402*/
  v3 = *v1; /*0x109405*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x109415*/
    v4 = v3 & 0xFFFEFEFF; /*0x109419*/
  else
    v4 = v3 & 0xFFFAFEFF; /*0x109422*/
  *(_DWORD *)(v2 + 28) |= v4; /*0x109429*/
  return spl0(); /*0x109434*/
}
