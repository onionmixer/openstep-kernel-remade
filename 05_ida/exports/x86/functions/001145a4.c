/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1145a4. */
int *__cdecl m_pullup(int a1, int a2)
{
  int v2; // esi
  int *v3; // edi
  int v4; // ebx
  int v5; // ecx
  signed __int32 v6; // ebx
  __int16 v7; // ax
  int v8; // ebx
  int v9; // ebx
  int v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v2 = a1; /*0x1145ad*/
  if ( (unsigned int)(*(_DWORD *)(a1 + 4) + a2) <= 0x7C && *(_DWORD *)a1 ) /*0x1145bb*/
  {
    v3 = (int *)a1; /*0x1145c1*/
    v2 = *(_DWORD *)a1; /*0x1145c3*/
    a2 -= *(__int16 *)(a1 + 8); /*0x1145c9*/
  }
  else
  {
    if ( a2 > 112 ) /*0x1145d8*/
      goto LABEL_35; /*0x1145d8*/
    v4 = splimp(); /*0x1145e3*/
    v3 = (int *)mfree; /*0x1145e5*/
    if ( mfree ) /*0x1145ed*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x1145ef*/
        panic(aMget_3); /*0x1145fb*/
      *(_WORD *)(mfree + 10) = *(_WORD *)(a1 + 10); /*0x114607*/
      --word_1E917C[0]; /*0x11460b*/
      ++word_1E917C[*(__int16 *)(a1 + 10)]; /*0x114616*/
      mfree = *v3; /*0x114620*/
      *v3 = 0; /*0x114626*/
      v3[1] = 12; /*0x11462c*/
    }
    else
    {
      v3 = m_more(0, *(__int16 *)(a1 + 10)); /*0x114644*/
    }
    splx(v4); /*0x11464a*/
    if ( !v3 ) /*0x114654*/
      goto LABEL_35; /*0x114654*/
    *((_WORD *)v3 + 4) = 0; /*0x11465a*/
  }
  v16 = 124 - v3[1]; /*0x114668*/
  do /*0x114764*/
  {
    v5 = *((__int16 *)v3 + 4); /*0x114679*/
    v6 = v16 - v5; /*0x114680*/
    if ( v16 - v5 > a2 + 32 ) /*0x114684*/
      v6 = a2 + 32; /*0x114686*/
    if ( *(__int16 *)(v2 + 8) < v6 ) /*0x11468b*/
      v6 = *(__int16 *)(v2 + 8); /*0x11468d*/
    bcopy((const void *)(*(_DWORD *)(v2 + 4) + v2), (char *)v3 + v3[1] + v5, v6); /*0x11469f*/
    a2 -= v6; /*0x1146a4*/
    *((_WORD *)v3 + 4) += v6; /*0x1146a7*/
    v7 = *(_WORD *)(v2 + 8) - v6; /*0x1146af*/
    *(_WORD *)(v2 + 8) = v7; /*0x1146b2*/
    if ( v7 ) /*0x1146bc*/
    {
      *(_DWORD *)(v2 + 4) += v6; /*0x1146be*/
    }
    else
    {
      v15 = splimp(); /*0x1146cd*/
      if ( !*(_WORD *)(v2 + 10) ) /*0x1146d0*/
        panic(aMfree); /*0x1146dc*/
      --word_1E917C[*(__int16 *)(v2 + 10)]; /*0x1146e8*/
      ++word_1E917C[0]; /*0x1146f0*/
      *(_WORD *)(v2 + 10) = 0; /*0x1146f7*/
      if ( *(_DWORD *)(v2 + 4) > 0x7Fu ) /*0x114701*/
        mclput(v2); /*0x114704*/
      v8 = *(_DWORD *)v2; /*0x11470c*/
      *(_DWORD *)v2 = mfree; /*0x114714*/
      *(_DWORD *)(v2 + 4) = 0; /*0x114716*/
      *(_DWORD *)(v2 + 124) = 0; /*0x11471d*/
      mfree = v2; /*0x114724*/
      splx(v15); /*0x11472e*/
      if ( m_want ) /*0x11473d*/
      {
        m_want = 0; /*0x11473f*/
        wakeup((int)&mfree); /*0x11474e*/
      }
      v2 = v8; /*0x114756*/
    }
    if ( a2 <= 0 ) /*0x11475c*/
    {
      *v3 = v2; /*0x1147f4*/
      return v3; /*0x1147f8*/
    }
  }
  while ( v2 ); /*0x114764*/
  v9 = splimp(); /*0x11476f*/
  if ( !*((_WORD *)v3 + 5) ) /*0x114771*/
    panic(aMfree); /*0x11477d*/
  --word_1E917C[*((__int16 *)v3 + 5)]; /*0x114789*/
  ++word_1E917C[0]; /*0x114791*/
  *((_WORD *)v3 + 5) = 0; /*0x114798*/
  if ( (unsigned int)v3[1] > 0x7F ) /*0x1147a2*/
    mclput(v3); /*0x1147a5*/
  *v3 = mfree; /*0x1147b3*/
  v3[1] = 0; /*0x1147b5*/
  v3[31] = 0; /*0x1147bc*/
  mfree = (int)v3; /*0x1147c3*/
  splx(v9); /*0x1147ca*/
  if ( m_want ) /*0x1147d9*/
  {
    m_want = 0; /*0x1147db*/
    wakeup((int)&mfree); /*0x1147ea*/
  }
LABEL_35:
  v11 = v2; /*0x114800*/
  if ( v2 ) /*0x114804*/
  {
    v14 = splimp(); /*0x11480f*/
    do /*0x1148a2*/
    {
      v12 = splimp(); /*0x114819*/
      if ( !*(_WORD *)(v11 + 10) ) /*0x11481b*/
        panic(aMfree_0); /*0x114827*/
      --word_1E917C[*(__int16 *)(v11 + 10)]; /*0x114833*/
      ++word_1E917C[0]; /*0x11483b*/
      *(_WORD *)(v11 + 10) = 0; /*0x114842*/
      if ( *(_DWORD *)(v11 + 4) > 0x7Fu ) /*0x11484c*/
        mclput(v11); /*0x11484f*/
      v13 = *(_DWORD *)v11; /*0x114857*/
      *(_DWORD *)v11 = mfree; /*0x11485f*/
      *(_DWORD *)(v11 + 4) = 0; /*0x114861*/
      *(_DWORD *)(v11 + 124) = 0; /*0x114868*/
      mfree = v11; /*0x11486f*/
      splx(v12); /*0x114876*/
      if ( m_want ) /*0x114885*/
      {
        m_want = 0; /*0x114887*/
        wakeup((int)&mfree); /*0x114896*/
      }
      v11 = v13; /*0x11489e*/
    }
    while ( v13 ); /*0x1148a2*/
    splx(v14); /*0x1148ac*/
  }
  return nullptr; /*0x1148b6*/
}
