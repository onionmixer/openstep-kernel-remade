/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11499c. */
int *__cdecl mclgetx(int a1, int a2, int a3, __int16 a4, int a5)
{
  int v5; // esi
  int *v6; // ebx

  v5 = splimp(); /*0x1149a6*/
  v6 = (int *)mfree; /*0x1149a8*/
  if ( mfree ) /*0x1149b0*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x1149b2*/
      panic(aMget_4); /*0x1149be*/
    *(_WORD *)(mfree + 10) = 1; /*0x1149c6*/
    --word_1E917C[0]; /*0x1149cc*/
    ++word_1E917E; /*0x1149d3*/
    mfree = *v6; /*0x1149dc*/
    *v6 = 0; /*0x1149e2*/
    v6[1] = 12; /*0x1149e8*/
  }
  else
  {
    v6 = m_more(a5, 1); /*0x1149ff*/
  }
  splx(v5); /*0x114a05*/
  if ( !v6 ) /*0x114a0c*/
    return nullptr; /*0x114a3c*/
  v6[1] = a3 - (_DWORD)v6; /*0x114a13*/
  *((_WORD *)v6 + 4) = a4; /*0x114a1a*/
  *((_WORD *)v6 + 6) = 2; /*0x114a1e*/
  v6[4] = a1; /*0x114a27*/
  v6[5] = a2; /*0x114a2d*/
  v6[6] = 0; /*0x114a30*/
  return v6; /*0x114a41*/
}
