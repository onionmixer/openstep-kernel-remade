/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a45c. */
char *__cdecl tcp_template(int a1)
{
  int v1; // ebx
  char *v2; // edx
  int *v3; // eax

  v1 = *(_DWORD *)(a1 + 32); /*0x12a463*/
  v2 = *(char **)(a1 + 28); /*0x12a466*/
  if ( !v2 ) /*0x12a46b*/
  {
    v3 = m_get(0, 2); /*0x12a471*/
    if ( !v3 ) /*0x12a478*/
      return nullptr; /*0x12a47c*/
    v3[1] = 84; /*0x12a480*/
    *((_WORD *)v3 + 4) = 40; /*0x12a487*/
    v2 = (char *)v3 + v3[1]; /*0x12a48f*/
  }
  *((_DWORD *)v2 + 1) = 0; /*0x12a492*/
  *(_DWORD *)v2 = 0; /*0x12a499*/
  v2[8] = 0; /*0x12a49f*/
  v2[9] = 6; /*0x12a4a3*/
  *((_WORD *)v2 + 5) = __ROR2__(20, 8); /*0x12a4b0*/
  *((_DWORD *)v2 + 3) = *(_DWORD *)(v1 + 20); /*0x12a4b7*/
  *((_DWORD *)v2 + 4) = *(_DWORD *)(v1 + 12); /*0x12a4bd*/
  *((_WORD *)v2 + 10) = *(_WORD *)(v1 + 24); /*0x12a4c4*/
  *((_WORD *)v2 + 11) = *(_WORD *)(v1 + 16); /*0x12a4cc*/
  *((_DWORD *)v2 + 6) = 0; /*0x12a4d0*/
  *((_DWORD *)v2 + 7) = 0; /*0x12a4d7*/
  v2[32] = 80; /*0x12a4de*/
  v2[33] = 0; /*0x12a4e2*/
  *((_WORD *)v2 + 17) = 0; /*0x12a4e6*/
  *((_WORD *)v2 + 18) = 0; /*0x12a4ec*/
  *((_WORD *)v2 + 19) = 0; /*0x12a4f2*/
  return v2; /*0x12a4fa*/
}
