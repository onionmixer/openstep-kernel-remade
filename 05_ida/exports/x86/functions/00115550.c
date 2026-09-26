/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115550. */
int __cdecl soreceive(int a1, int *a2, int a3, char a4, int *a5)
{
  int *v5; // ebx
  int v6; // esi
  int v7; // eax
  __int16 i; // ax
  __int16 v10; // ax
  __int16 v11; // ax
  int v12; // ebx
  __int16 v13; // ax
  int v14; // esi
  __int16 v15; // ax
  int v16; // esi
  int v17; // esi
  __int16 v18; // dx
  __int16 v19; // ax
  __int16 v20; // ax
  __int16 v21; // ax
  int (__cdecl *v22)(int); // eax
  __int16 v23; // ax
  int v24; // [esp+Ch] [ebp-1Ch]
  int v25; // [esp+10h] [ebp-18h]
  int v26; // [esp+14h] [ebp-14h]
  int v27; // [esp+18h] [ebp-10h]
  int v28; // [esp+1Ch] [ebp-Ch]
  int v29; // [esp+20h] [ebp-8h]
  int v30; // [esp+24h] [ebp-4h]
  int v31; // [esp+24h] [ebp-4h]

  v30 = 0; /*0x11555f*/
  v27 = *(_DWORD *)(a1 + 12); /*0x115569*/
  if ( a5 ) /*0x115570*/
    *a5 = 0; /*0x115575*/
  if ( a2 ) /*0x11557d*/
    *a2 = 0; /*0x11557f*/
  if ( (a4 & 1) != 0 ) /*0x11558b*/
  {
    v5 = m_get(1, 1); /*0x11559a*/
    v31 = (*(int (__cdecl **)(int, int, int *, int, _DWORD))(v27 + 28))(a1, 13, v5, a4 & 2, 0); /*0x1155b1*/
    if ( !v31 ) /*0x1155b9*/
    {
      do /*0x1155fd*/
      {
        v6 = *(_DWORD *)(a3 + 20); /*0x1155bf*/
        if ( v6 > *((__int16 *)v5 + 4) ) /*0x1155c8*/
          v6 = *((__int16 *)v5 + 4); /*0x1155ca*/
        v31 = uiomove((int)v5 + v5[1], v6, 0, (_DWORD *)a3); /*0x1155de*/
        v7 = m_free((int)v5); /*0x1155e2*/
        v5 = (int *)v7; /*0x1155e7*/
      }
      while ( *(_DWORD *)(a3 + 20) && !v31 && v7 ); /*0x1155fd*/
    }
    if ( v5 ) /*0x115601*/
      m_freem((int)v5); /*0x115604*/
    return v31; /*0x11560c*/
  }
  while ( 1 ) /*0x115614*/
  {
    for ( i = *(_WORD *)(a1 + 56); (i & 1) != 0; i = *(_WORD *)(a1 + 56) ) /*0x11561a*/
    {
      LOBYTE(i) = i | 2; /*0x115620*/
      *(_WORD *)(a1 + 56) = i; /*0x115622*/
      sleep(a1 + 56); /*0x115629*/
    }
    *(_BYTE *)(a1 + 56) |= 1u; /*0x115639*/
    v29 = splnet(); /*0x115642*/
    if ( *(_WORD *)(a1 + 36) ) /*0x115645*/
      break; /*0x115645*/
    if ( *(_WORD *)(a1 + 86) ) /*0x115650*/
    {
      v30 = *(unsigned __int16 *)(a1 + 86); /*0x11565e*/
      *(_WORD *)(a1 + 86) = 0; /*0x115661*/
      goto LABEL_119; /*0x115667*/
    }
    v10 = *(_WORD *)(a1 + 6); /*0x11566c*/
    if ( (v10 & 0x20) != 0 ) /*0x115672*/
      goto LABEL_119; /*0x115672*/
    if ( (v10 & 2) == 0 && (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 4) != 0 ) /*0x115683*/
    {
      v30 = 57; /*0x115685*/
      goto LABEL_119; /*0x11568c*/
    }
    if ( !*(_DWORD *)(a3 + 20) ) /*0x11569b*/
      goto LABEL_119; /*0x11569b*/
    if ( (*(_BYTE *)(a1 + 7) & 1) != 0 ) /*0x1156a5*/
    {
      v30 = 35; /*0x1156ae*/
      if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 && (*(_BYTE *)(a3 + 17) & 0x20) != 0 ) /*0x1156c3*/
        v30 = 11; /*0x1156c9*/
      goto LABEL_119; /*0x1156d0*/
    }
    v11 = *(_WORD *)(a1 + 56); /*0x1156d8*/
    *(_WORD *)(a1 + 56) = v11 & 0xFFFE; /*0x1156e1*/
    if ( (v11 & 2) != 0 ) /*0x1156e7*/
    {
      LOBYTE(v11) = v11 & 0xFC; /*0x1156e9*/
      *(_WORD *)(a1 + 56) = v11; /*0x1156eb*/
      wakeup(a1 + 56); /*0x1156f3*/
    }
    sbwait(a1 + 36); /*0x1156ff*/
    splx(v29); /*0x115708*/
  }
  ++*(_DWORD *)(active_u + 424); /*0x11571d*/
  v12 = *(_DWORD *)(a1 + 48); /*0x115723*/
  if ( !v12 ) /*0x115728*/
    panic(aReceive1); /*0x11572f*/
  v26 = *(_DWORD *)(v12 + 124); /*0x11573a*/
  if ( (*(_BYTE *)(v27 + 10) & 2) != 0 ) /*0x115744*/
  {
    if ( *(_WORD *)(v12 + 10) != 8 ) /*0x11574f*/
      panic(aReceive1a); /*0x115756*/
    if ( (a4 & 2) != 0 ) /*0x115764*/
    {
      if ( a2 ) /*0x115768*/
        *a2 = m_copy((int *)v12, 0, *(__int16 *)(v12 + 8)); /*0x115777*/
      v12 = *(_DWORD *)v12; /*0x11577c*/
    }
    else
    {
      *(_WORD *)(a1 + 36) -= *(_WORD *)(v12 + 8); /*0x115788*/
      v13 = *(_WORD *)(a1 + 40); /*0x11578c*/
      *(_WORD *)(a1 + 40) = v13 - 128; /*0x115796*/
      if ( *(_DWORD *)(v12 + 4) > 0x7Cu ) /*0x11579e*/
        *(_WORD *)(a1 + 40) = v13 - 1152; /*0x1157a4*/
      if ( a2 ) /*0x1157aa*/
      {
        *a2 = v12; /*0x1157ac*/
        v12 = *(_DWORD *)v12; /*0x1157ae*/
        *(_DWORD *)*a2 = 0; /*0x1157b2*/
        *(_DWORD *)(a1 + 48) = v12; /*0x1157b8*/
      }
      else
      {
        v14 = splimp(); /*0x1157c5*/
        if ( !*(_WORD *)(v12 + 10) ) /*0x1157c7*/
          panic(aMfree_1); /*0x1157d3*/
        --word_1E917C[*(__int16 *)(v12 + 10)]; /*0x1157df*/
        ++word_1E917C[0]; /*0x1157e7*/
        *(_WORD *)(v12 + 10) = 0; /*0x1157ee*/
        if ( *(_DWORD *)(v12 + 4) > 0x7Fu ) /*0x1157f8*/
          mclput(v12); /*0x1157fb*/
        *(_DWORD *)(a1 + 48) = *(_DWORD *)v12; /*0x115805*/
        *(_DWORD *)v12 = mfree; /*0x11580e*/
        *(_DWORD *)(v12 + 4) = 0; /*0x115810*/
        *(_DWORD *)(v12 + 124) = 0; /*0x115817*/
        mfree = v12; /*0x11581e*/
        splx(v14); /*0x115825*/
        if ( m_want ) /*0x115834*/
        {
          m_want = 0; /*0x115836*/
          wakeup((int)&mfree); /*0x115845*/
        }
        v12 = *(_DWORD *)(a1 + 48); /*0x11584d*/
      }
      if ( !v12 ) /*0x115852*/
        goto LABEL_74; /*0x115852*/
      *(_DWORD *)(v12 + 124) = v26; /*0x11585b*/
    }
  }
  if ( v12 && *(_WORD *)(v12 + 10) == 12 ) /*0x11586b*/
  {
    if ( (*(_BYTE *)(v27 + 10) & 0x10) == 0 ) /*0x115878*/
      panic(aReceive2); /*0x11587f*/
    if ( (a4 & 2) != 0 ) /*0x11588d*/
    {
      if ( a5 ) /*0x115893*/
        *a5 = m_copy((int *)v12, 0, *(__int16 *)(v12 + 8)); /*0x1158a5*/
      v12 = *(_DWORD *)v12; /*0x1158aa*/
    }
    else
    {
      *(_WORD *)(a1 + 36) -= *(_WORD *)(v12 + 8); /*0x1158b8*/
      v15 = *(_WORD *)(a1 + 40); /*0x1158bc*/
      *(_WORD *)(a1 + 40) = v15 - 128; /*0x1158c6*/
      if ( *(_DWORD *)(v12 + 4) > 0x7Cu ) /*0x1158ce*/
        *(_WORD *)(a1 + 40) = v15 - 1152; /*0x1158d4*/
      if ( a5 ) /*0x1158dc*/
      {
        *a5 = v12; /*0x1158e1*/
        *(_DWORD *)(a1 + 48) = *(_DWORD *)v12; /*0x1158e5*/
        *(_DWORD *)v12 = 0; /*0x1158e8*/
      }
      else
      {
        v16 = splimp(); /*0x1158f9*/
        if ( !*(_WORD *)(v12 + 10) ) /*0x1158fb*/
          panic(aMfree_2); /*0x115907*/
        --word_1E917C[*(__int16 *)(v12 + 10)]; /*0x115913*/
        ++word_1E917C[0]; /*0x11591b*/
        *(_WORD *)(v12 + 10) = 0; /*0x115922*/
        if ( *(_DWORD *)(v12 + 4) > 0x7Fu ) /*0x11592c*/
          mclput(v12); /*0x11592f*/
        *(_DWORD *)(a1 + 48) = *(_DWORD *)v12; /*0x115939*/
        *(_DWORD *)v12 = mfree; /*0x115942*/
        *(_DWORD *)(v12 + 4) = 0; /*0x115944*/
        *(_DWORD *)(v12 + 124) = 0; /*0x11594b*/
        mfree = v12; /*0x115952*/
        splx(v16); /*0x115959*/
        if ( m_want ) /*0x115968*/
        {
          m_want = 0; /*0x11596a*/
          wakeup((int)&mfree); /*0x115979*/
        }
      }
      v12 = *(_DWORD *)(a1 + 48); /*0x115981*/
      if ( v12 ) /*0x115986*/
        *(_DWORD *)(v12 + 124) = v26; /*0x11598b*/
    }
  }
LABEL_74:
  v25 = 0; /*0x11598e*/
  v28 = 0; /*0x115995*/
  while ( v12 && *(int *)(a3 + 20) > 0 && !v30 ) /*0x115b54*/
  {
    if ( (unsigned __int16)(*(_WORD *)(v12 + 10) - 1) > 1u ) /*0x1159ae*/
      panic(aReceive3); /*0x1159b5*/
    v17 = *(_DWORD *)(a3 + 20); /*0x1159c0*/
    *(_BYTE *)(a1 + 6) &= ~0x40u; /*0x1159c3*/
    if ( *(_WORD *)(a1 + 88) && v17 > *(unsigned __int16 *)(a1 + 88) - v28 ) /*0x1159da*/
      v17 = *(unsigned __int16 *)(a1 + 88) - v28; /*0x1159dc*/
    if ( v17 > *(__int16 *)(v12 + 8) - v25 ) /*0x1159e7*/
      v17 = *(__int16 *)(v12 + 8) - v25; /*0x1159e9*/
    splx(v29); /*0x1159ef*/
    v30 = uiomove(v25 + *(_DWORD *)(v12 + 4) + v12, v17, 0, (_DWORD *)a3); /*0x115a09*/
    v29 = splnet(); /*0x115a11*/
    v18 = *(_WORD *)(v12 + 8); /*0x115a14*/
    if ( v17 == v18 - v25 ) /*0x115a23*/
    {
      if ( (a4 & 2) != 0 ) /*0x115a2d*/
      {
        v12 = *(_DWORD *)v12; /*0x115a2f*/
        v25 = 0; /*0x115a31*/
      }
      else
      {
        v26 = *(_DWORD *)(v12 + 124); /*0x115a43*/
        *(_WORD *)(a1 + 36) -= v18; /*0x115a46*/
        v19 = *(_WORD *)(a1 + 40); /*0x115a4a*/
        *(_WORD *)(a1 + 40) = v19 - 128; /*0x115a54*/
        if ( *(_DWORD *)(v12 + 4) > 0x7Cu ) /*0x115a5c*/
          *(_WORD *)(a1 + 40) = v19 - 1152; /*0x115a62*/
        v24 = splimp(); /*0x115a6b*/
        if ( !*(_WORD *)(v12 + 10) ) /*0x115a6e*/
          panic(aMfree_3); /*0x115a7a*/
        --word_1E917C[*(__int16 *)(v12 + 10)]; /*0x115a86*/
        ++word_1E917C[0]; /*0x115a8e*/
        *(_WORD *)(v12 + 10) = 0; /*0x115a95*/
        if ( *(_DWORD *)(v12 + 4) > 0x7Fu ) /*0x115a9f*/
          mclput(v12); /*0x115aa2*/
        *(_DWORD *)(a1 + 48) = *(_DWORD *)v12; /*0x115aac*/
        *(_DWORD *)v12 = mfree; /*0x115ab5*/
        *(_DWORD *)(v12 + 4) = 0; /*0x115ab7*/
        *(_DWORD *)(v12 + 124) = 0; /*0x115abe*/
        mfree = v12; /*0x115ac5*/
        splx(v24); /*0x115acf*/
        if ( m_want ) /*0x115ade*/
        {
          m_want = 0; /*0x115ae0*/
          wakeup((int)&mfree); /*0x115aef*/
        }
        v12 = *(_DWORD *)(a1 + 48); /*0x115af7*/
        if ( v12 ) /*0x115afc*/
          *(_DWORD *)(v12 + 124) = v26; /*0x115b01*/
      }
    }
    else if ( (a4 & 2) != 0 ) /*0x115b0c*/
    {
      v25 += v17; /*0x115b0e*/
    }
    else
    {
      *(_DWORD *)(v12 + 4) += v17; /*0x115b14*/
      *(_WORD *)(v12 + 8) -= v17; /*0x115b17*/
      *(_WORD *)(a1 + 36) -= v17; /*0x115b1b*/
    }
    v20 = *(_WORD *)(a1 + 88); /*0x115b1f*/
    if ( v20 ) /*0x115b26*/
    {
      if ( (a4 & 2) != 0 ) /*0x115b2c*/
      {
        v28 += v17; /*0x115b40*/
      }
      else
      {
        v21 = v20 - v17; /*0x115b2e*/
        *(_WORD *)(a1 + 88) = v21; /*0x115b31*/
        if ( !v21 ) /*0x115b35*/
        {
          *(_BYTE *)(a1 + 6) |= 0x40u; /*0x115b37*/
          break; /*0x115b3b*/
        }
      }
    }
  }
  if ( (a4 & 2) == 0 ) /*0x115b60*/
  {
    if ( v12 ) /*0x115b64*/
    {
      if ( (*(_BYTE *)(v27 + 10) & 1) != 0 ) /*0x115b77*/
        sbdroprecord(a1 + 36); /*0x115b7d*/
    }
    else
    {
      *(_DWORD *)(a1 + 48) = v26; /*0x115b69*/
    }
    if ( (*(_BYTE *)(v27 + 10) & 8) != 0 && *(_DWORD *)(a1 + 8) ) /*0x115b8e*/
      (*(void (__cdecl **)(int, int, _DWORD, _DWORD, _DWORD))(v27 + 28))(a1, 8, 0, 0, 0); /*0x115ba0*/
    if ( !v30 ) /*0x115ba9*/
    {
      if ( a5 ) /*0x115baf*/
      {
        if ( *a5 ) /*0x115bb4*/
        {
          v22 = *(int (__cdecl **)(int))(*(_DWORD *)(v27 + 4) + 12); /*0x115bc0*/
          if ( v22 ) /*0x115bc5*/
            v30 = v22(*a5); /*0x115bca*/
        }
      }
    }
  }
LABEL_119:
  v23 = *(_WORD *)(a1 + 56); /*0x115bd0*/
  *(_WORD *)(a1 + 56) = v23 & 0xFFFE; /*0x115bd9*/
  if ( (v23 & 2) != 0 ) /*0x115bdf*/
  {
    LOBYTE(v23) = v23 & 0xFC; /*0x115be1*/
    *(_WORD *)(a1 + 56) = v23; /*0x115be3*/
    wakeup(a1 + 56); /*0x115beb*/
  }
  splx(v29); /*0x115bf7*/
  return v30; /*0x115c02*/
}
