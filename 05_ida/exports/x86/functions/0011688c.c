/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11688c. */
int __cdecl sbappendrights(unsigned __int16 *a1, int **a2, int a3)
{
  int v3; // ebx
  int **i; // edx
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // edx
  unsigned __int16 v11; // ax
  int v12; // eax

  v3 = 0; /*0x116898*/
  if ( !a3 ) /*0x11689e*/
    panic(aSbappendrights); /*0x1168a5*/
  for ( i = a2; i; i = (int **)*i ) /*0x1168b2*/
    v3 += *((__int16 *)i + 4); /*0x1168b8*/
  v5 = *(__int16 *)(a3 + 8); /*0x1168c3*/
  v6 = v5 + v3; /*0x1168c7*/
  v7 = a1[1] - *a1; /*0x1168df*/
  if ( a1[3] - a1[2] < v7 ) /*0x1168e4*/
    v7 = a1[3] - a1[2]; /*0x1168e6*/
  if ( v6 > v7 ) /*0x1168eb*/
    return 0; /*0x1168eb*/
  v8 = m_copy((int *)a3, 0, v5); /*0x1168f4*/
  v9 = v8; /*0x1168f9*/
  if ( !v8 ) /*0x116900*/
    return 0; /*0x116902*/
  *a1 += *(_WORD *)(v8 + 8); /*0x11690c*/
  v11 = a1[2]; /*0x11690f*/
  a1[2] = v11 + 128; /*0x11691a*/
  if ( *(_DWORD *)(v9 + 4) > 0x7Cu ) /*0x116922*/
    a1[2] = v11 + 1152; /*0x116928*/
  v12 = *((_DWORD *)a1 + 3); /*0x11692c*/
  if ( v12 ) /*0x116931*/
  {
    for ( ; *(_DWORD *)(v12 + 124); v12 = *(_DWORD *)(v12 + 124) ) /*0x116933*/
      ; /*0x11693c*/
    *(_DWORD *)(v12 + 124) = v9; /*0x116945*/
  }
  else
  {
    *((_DWORD *)a1 + 3) = v9; /*0x11694c*/
  }
  if ( a2 ) /*0x116953*/
    sbcompress(a1, a2, v9); /*0x11695b*/
  return 1; /*0x116968*/
}
