/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c044. */
int __cdecl igmp_sendreport(_DWORD *a1)
{
  int v1; // ebx
  int *v2; // esi
  int result; // eax
  int v4; // ebx
  int *v5; // edi
  char *v6; // ebx
  char *v7; // eax
  char *v8; // ecx

  v1 = splimp(); /*0x12c052*/
  v2 = (int *)mfree; /*0x12c054*/
  if ( mfree ) /*0x12c05c*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x12c05e*/
      panic(aMget_13); /*0x12c06a*/
    *(_WORD *)(mfree + 10) = 2; /*0x12c072*/
    --word_1E917C[0]; /*0x12c078*/
    ++word_1E9180; /*0x12c07f*/
    mfree = *v2; /*0x12c088*/
    *v2 = 0; /*0x12c08e*/
    v2[1] = 12; /*0x12c094*/
  }
  else
  {
    v2 = m_more(0, 2); /*0x12c0a9*/
  }
  result = splx(v1); /*0x12c0af*/
  if ( v2 ) /*0x12c0b9*/
  {
    v4 = splimp(); /*0x12c0c4*/
    v5 = (int *)mfree; /*0x12c0c6*/
    if ( mfree ) /*0x12c0ce*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x12c0d0*/
        panic(aMget_14); /*0x12c0dc*/
      *(_WORD *)(mfree + 10) = 14; /*0x12c0e4*/
      --word_1E917C[0]; /*0x12c0ea*/
      ++word_1E9198; /*0x12c0f1*/
      mfree = *v5; /*0x12c0fa*/
      *v5 = 0; /*0x12c100*/
      v5[1] = 12; /*0x12c106*/
    }
    else
    {
      v5 = m_more(0, 14); /*0x12c119*/
    }
    splx(v4); /*0x12c11f*/
    if ( v5 ) /*0x12c129*/
    {
      v2[1] = 116; /*0x12c138*/
      *((_WORD *)v2 + 4) = 8; /*0x12c13f*/
      v6 = (char *)v2 + v2[1]; /*0x12c147*/
      *v6 = 18; /*0x12c14a*/
      v6[1] = 0; /*0x12c14d*/
      *((_DWORD *)v6 + 1) = *a1; /*0x12c156*/
      *((_WORD *)v6 + 1) = 0; /*0x12c159*/
      *((_WORD *)v6 + 1) = in_cksum(v2, 8); /*0x12c167*/
      v2[1] -= 20; /*0x12c16b*/
      *((_WORD *)v2 + 4) += 20; /*0x12c16f*/
      v7 = (char *)v2 + v2[1]; /*0x12c176*/
      v7[1] = 0; /*0x12c179*/
      *((_WORD *)v7 + 1) = 28; /*0x12c17d*/
      *((_WORD *)v7 + 3) = 0; /*0x12c183*/
      v7[9] = 2; /*0x12c189*/
      *((_DWORD *)v7 + 3) = 0; /*0x12c18d*/
      *((_DWORD *)v7 + 4) = *((_DWORD *)v6 + 1); /*0x12c197*/
      v8 = (char *)v5 + v5[1]; /*0x12c19c*/
      *(_DWORD *)v8 = a1[1]; /*0x12c1a5*/
      v8[4] = 1; /*0x12c1a7*/
      v8[5] = ip_mrouter != 0; /*0x12c1b8*/
      ip_output((int)v2, 0, nullptr, 2, (int)v5); /*0x12c1c3*/
      result = m_free((int)v5); /*0x12c1c9*/
      ++dword_1EEE90; /*0x12c1ce*/
    }
    else
    {
      return m_free((int)v2); /*0x12c12c*/
    }
  }
  return result; /*0x12c1d7*/
}
