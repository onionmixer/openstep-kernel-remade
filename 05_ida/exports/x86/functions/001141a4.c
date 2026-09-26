/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1141a4. */
int __cdecl m_copy(int *a1, int a2, int a3)
{
  int v4; // edi
  int v5; // eax
  int *v6; // ebx
  __int16 v7; // dx
  int v9; // ebx
  int v10; // edi
  int v11; // esi
  int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int *v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h] BYREF

  v4 = a2; /*0x1141b0*/
  if ( a3 ) /*0x1141b7*/
  {
    if ( a2 < 0 || a3 < 0 ) /*0x1141c5*/
      panic(aMCopy); /*0x1141cc*/
    while ( v4 > 0 ) /*0x1141f7*/
    {
      if ( !a1 ) /*0x1141da*/
        panic(aMCopy_0); /*0x1141e1*/
      v5 = *((__int16 *)a1 + 4); /*0x1141e9*/
      if ( v4 < v5 ) /*0x1141ef*/
        break; /*0x1141ef*/
      v4 -= v5; /*0x1141f1*/
      a1 = (int *)*a1; /*0x1141f3*/
    }
    v14 = &v15; /*0x1141fc*/
    v15 = 0; /*0x1141ff*/
    while ( 1 ) /*0x114210*/
    {
      if ( !a1 ) /*0x114212*/
      {
        if ( a3 != 1000000000 ) /*0x11421b*/
          panic(aMCopy_1); /*0x114226*/
        return v15; /*0x11431b*/
      }
      v13 = splimp(); /*0x114235*/
      v6 = (int *)mfree; /*0x114238*/
      if ( mfree ) /*0x114240*/
      {
        if ( *(_WORD *)(mfree + 10) ) /*0x114242*/
          panic(aMget_2); /*0x11424e*/
        *(_WORD *)(mfree + 10) = *((_WORD *)a1 + 5); /*0x11425a*/
        --word_1E917C[0]; /*0x11425e*/
        ++word_1E917C[*((__int16 *)a1 + 5)]; /*0x114269*/
        mfree = *v6; /*0x114273*/
        *v6 = 0; /*0x114279*/
        v6[1] = 12; /*0x11427f*/
      }
      else
      {
        v6 = m_more(0, *((__int16 *)a1 + 5)); /*0x114294*/
      }
      splx(v13); /*0x11429d*/
      *v14 = (int)v6; /*0x1142a5*/
      if ( !v6 ) /*0x1142ac*/
        break; /*0x1142ac*/
      v7 = a3; /*0x1142b4*/
      if ( a3 > *((__int16 *)a1 + 4) - v4 ) /*0x1142b9*/
        v7 = *((_WORD *)a1 + 4) - v4; /*0x1142bb*/
      *((_WORD *)v6 + 4) = v7; /*0x1142bd*/
      if ( (unsigned int)a1[1] <= 0x7C || v7 <= 112 ) /*0x1142cb*/
      {
        bcopy((char *)a1 + a1[1] + v4, (char *)v6 + v6[1], *((__int16 *)v6 + 4)); /*0x1142ef*/
      }
      else
      {
        mcldup(a1, v6, v4); /*0x1142d0*/
        v6[1] += v4; /*0x1142d5*/
      }
      if ( a3 != 1000000000 ) /*0x1142fe*/
        a3 -= *((__int16 *)v6 + 4); /*0x114304*/
      v4 = 0; /*0x114307*/
      a1 = (int *)*a1; /*0x114309*/
      v14 = v6; /*0x11430b*/
      if ( a3 <= 0 ) /*0x114312*/
        return v15; /*0x114312*/
    }
    v9 = v15; /*0x114320*/
    if ( v15 ) /*0x114325*/
    {
      v12 = splimp(); /*0x114330*/
      do /*0x1143c2*/
      {
        v10 = splimp(); /*0x114339*/
        if ( !*(_WORD *)(v9 + 10) ) /*0x11433b*/
          panic(aMfree_0); /*0x114347*/
        --word_1E917C[*(__int16 *)(v9 + 10)]; /*0x114353*/
        ++word_1E917C[0]; /*0x11435b*/
        *(_WORD *)(v9 + 10) = 0; /*0x114362*/
        if ( *(_DWORD *)(v9 + 4) > 0x7Fu ) /*0x11436c*/
          mclput(v9); /*0x11436f*/
        v11 = *(_DWORD *)v9; /*0x114377*/
        *(_DWORD *)v9 = mfree; /*0x11437f*/
        *(_DWORD *)(v9 + 4) = 0; /*0x114381*/
        *(_DWORD *)(v9 + 124) = 0; /*0x114388*/
        mfree = v9; /*0x11438f*/
        splx(v10); /*0x114396*/
        if ( m_want ) /*0x1143a5*/
        {
          m_want = 0; /*0x1143a7*/
          wakeup((int)&mfree); /*0x1143b6*/
        }
        v9 = v11; /*0x1143be*/
      }
      while ( v11 ); /*0x1143c2*/
      splx(v12); /*0x1143cc*/
    }
  }
  return 0; /*0x1143d6*/
}
