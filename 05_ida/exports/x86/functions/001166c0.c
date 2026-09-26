/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1166c0. */
int __cdecl sbappendaddr(unsigned __int16 *a1, int *a2, int **a3, int a4)
{
  int **i; // ebx
  int v5; // eax
  int *v6; // ebx
  int v8; // eax
  __int16 v9; // ax
  int v10; // eax
  unsigned __int16 v11; // dx
  unsigned __int16 v12; // ax
  int v13; // eax
  int v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  v14 = 16; /*0x1166cc*/
  for ( i = a3; i; i = (int **)*i ) /*0x1166d8*/
    v14 += *((__int16 *)i + 4); /*0x1166e0*/
  if ( a4 ) /*0x1166ed*/
    v14 += *(__int16 *)(a4 + 8); /*0x1166f6*/
  v5 = a1[1] - *a1; /*0x11670e*/
  if ( v5 > a1[3] - a1[2] ) /*0x116712*/
    v5 = a1[3] - a1[2]; /*0x116714*/
  if ( v14 > v5 ) /*0x116719*/
    return 0; /*0x116719*/
  v15 = splimp(); /*0x116720*/
  v6 = (int *)mfree; /*0x116723*/
  if ( mfree ) /*0x11672b*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x11672d*/
      panic(aMget_6); /*0x116739*/
    *(_WORD *)(mfree + 10) = 8; /*0x116741*/
    --word_1E917C[0]; /*0x116747*/
    ++word_1E918C; /*0x11674e*/
    mfree = *v6; /*0x116757*/
    *v6 = 0; /*0x11675d*/
    v6[1] = 12; /*0x116763*/
  }
  else
  {
    v6 = m_more(0, 8); /*0x116775*/
  }
  splx(v15); /*0x11677e*/
  if ( !v6 ) /*0x116788*/
    return 0; /*0x11678c*/
  v8 = v6[1]; /*0x116794*/
  *(int *)((char *)v6 + v8) = *a2; /*0x11679c*/
  *(int *)((char *)v6 + v8 + 4) = a2[1]; /*0x1167a5*/
  *(int *)((char *)v6 + v8 + 8) = a2[2]; /*0x1167af*/
  *(int *)((char *)v6 + v8 + 12) = a2[3]; /*0x1167b9*/
  *((_WORD *)v6 + 4) = 16; /*0x1167bd*/
  if ( a4 ) /*0x1167c7*/
  {
    v9 = *(_WORD *)(a4 + 8); /*0x1167cc*/
    if ( v9 ) /*0x1167d3*/
    {
      v10 = m_copy((int *)a4, 0, v9); /*0x1167da*/
      *v6 = v10; /*0x1167df*/
      if ( !v10 ) /*0x1167e6*/
      {
        m_freem((int)v6); /*0x1167e9*/
        return 0; /*0x1167f0*/
      }
      *a1 += *(_WORD *)(v10 + 8); /*0x1167fc*/
      v11 = a1[2]; /*0x1167ff*/
      a1[2] = v11 + 128; /*0x11680a*/
      if ( *(_DWORD *)(*v6 + 4) > 0x7Cu ) /*0x116814*/
        a1[2] = v11 + 1152; /*0x11681b*/
    }
  }
  *a1 += *((_WORD *)v6 + 4); /*0x116823*/
  v12 = a1[2]; /*0x116826*/
  a1[2] = v12 + 128; /*0x116831*/
  if ( (unsigned int)v6[1] > 0x7C ) /*0x116839*/
    a1[2] = v12 + 1152; /*0x11683f*/
  v13 = *((_DWORD *)a1 + 3); /*0x116843*/
  if ( v13 ) /*0x116848*/
  {
    for ( ; *(_DWORD *)(v13 + 124); v13 = *(_DWORD *)(v13 + 124) ) /*0x11684a*/
      ; /*0x116850*/
    *(_DWORD *)(v13 + 124) = v6; /*0x116859*/
  }
  else
  {
    *((_DWORD *)a1 + 3) = v6; /*0x116860*/
  }
  if ( *v6 ) /*0x116863*/
    v6 = (int *)*v6; /*0x116869*/
  if ( a3 ) /*0x11686f*/
    sbcompress(a1, a3, v6); /*0x116877*/
  return 1; /*0x116884*/
}
