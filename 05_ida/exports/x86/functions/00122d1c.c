/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122d1c. */
int __cdecl arpioctl(int a1, int a2)
{
  int v2; // ebx
  unsigned int v4; // ecx
  char *v5; // esi
  int i; // eax
  char *v7; // esi
  char *v8; // ebx
  char *v9; // edx
  char v10; // al
  int v11; // esi
  char *v12; // ebx
  char *v13; // edx
  char v14; // al
  int v15; // ebx
  int v16; // ebx
  int v17; // [esp+10h] [ebp-28h]
  char *v18; // [esp+10h] [ebp-28h]
  int v19; // [esp+10h] [ebp-28h]
  int v20; // [esp+10h] [ebp-28h]
  int v21; // [esp+14h] [ebp-24h]
  int v22; // [esp+14h] [ebp-24h]
  int v23; // [esp+18h] [ebp-20h]
  int v24; // [esp+28h] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-Ch]

  v2 = 0; /*0x122d2b*/
  if ( *(_WORD *)a2 != 2 || *(_WORD *)(a2 + 16) ) /*0x122d33*/
    return 47; /*0x122d3f*/
  v25 = splimp(); /*0x122d4f*/
  v4 = *(_DWORD *)(a2 + 4); /*0x122d52*/
  v5 = (char *)&arptab + 180 * (v4 % 0x13); /*0x122d6c*/
  for ( i = 0; i <= 8; ++i ) /*0x122d73*/
  {
    if ( *(_DWORD *)v5 == v4 ) /*0x122d7a*/
      break; /*0x122d7a*/
    v5 += 20; /*0x122d7d*/
  }
  if ( i > 8 ) /*0x122d88*/
    v5 = nullptr; /*0x122d8a*/
  if ( v5 ) /*0x122d8e*/
    goto LABEL_14; /*0x122d8e*/
  if ( a1 != -2145097442 ) /*0x122d97*/
  {
    splx(v25); /*0x122d9d*/
    return 6; /*0x122da7*/
  }
  v2 = ifa_ifwithnet((_WORD *)a2); /*0x122db5*/
  if ( v2 ) /*0x122dbc*/
  {
LABEL_14:
    if ( a1 == -2145097440 ) /*0x122ddb*/
    {
      v16 = splimp(); /*0x1230c9*/
      if ( *((_DWORD *)v5 + 3) ) /*0x1230cb*/
        m_freem(*((_DWORD *)v5 + 3)); /*0x1230d3*/
      *((_DWORD *)v5 + 3) = 0; /*0x1230db*/
      v5[11] = 0; /*0x1230e2*/
      v5[10] = 0; /*0x1230e6*/
      *(_DWORD *)v5 = 0; /*0x1230ea*/
      splx(v16); /*0x1230f1*/
    }
    else if ( a1 > -2145097440 ) /*0x122de1*/
    {
      if ( a1 == -1071355617 ) /*0x122dfb*/
      {
        bcopy(v5 + 4, (void *)(a2 + 18), 6u); /*0x123109*/
        *(_DWORD *)(a2 + 32) = (unsigned __int8)v5[11]; /*0x123115*/
      }
    }
    else if ( a1 == -2145097442 ) /*0x122dea*/
    {
      if ( !v5 ) /*0x122e0a*/
      {
        v24 = *(_DWORD *)(v2 + 32); /*0x122e13*/
        v17 = -1; /*0x122e1f*/
        v7 = nullptr; /*0x122e26*/
        if ( dword_1DBA20 ) /*0x122e2f*/
        {
          dword_1DBA20 = 0; /*0x122e31*/
          timeout((int)arptimer); /*0x122e49*/
        }
        v8 = (char *)&arptab + 180 * (*(_DWORD *)(a2 + 4) % 0x13u); /*0x122e69*/
        v21 = 0; /*0x122e70*/
        v9 = v8; /*0x122e77*/
        do /*0x122eaa*/
        {
          v10 = v9[11]; /*0x122e7c*/
          if ( !v10 ) /*0x122e81*/
            goto LABEL_34; /*0x122e81*/
          if ( (v10 & 4) == 0 && (!v7 || v17 < (unsigned __int8)v9[10]) ) /*0x122e92*/
          {
            v17 = (unsigned __int8)v9[10]; /*0x122e98*/
            v7 = v9; /*0x122e9b*/
          }
          ++v21; /*0x122e9d*/
          v9 += 20; /*0x122ea0*/
          v8 += 20; /*0x122ea3*/
        }
        while ( v21 <= 8 ); /*0x122eaa*/
        if ( !v7 ) /*0x122eae*/
          goto LABEL_35; /*0x122eae*/
        v8 = v7; /*0x122eb0*/
        v11 = splimp(); /*0x122eb7*/
        if ( *((_DWORD *)v8 + 3) ) /*0x122eb9*/
          m_freem(*((_DWORD *)v8 + 3)); /*0x122ec1*/
        *((_DWORD *)v8 + 3) = 0; /*0x122ec9*/
        v8[11] = 0; /*0x122ed0*/
        v8[10] = 0; /*0x122ed4*/
        *(_DWORD *)v8 = 0; /*0x122ed8*/
        splx(v11); /*0x122edf*/
LABEL_34:
        *(_DWORD *)v8 = *(_DWORD *)(a2 + 4); /*0x122eec*/
        v8[11] = 1; /*0x122eee*/
        *((_DWORD *)v8 + 4) = v24; /*0x122ef5*/
        v5 = v8; /*0x122ef8*/
        if ( !v8 ) /*0x122efc*/
        {
LABEL_35:
          splx(v25); /*0x122f02*/
          return 49; /*0x122f0c*/
        }
        if ( (*(_BYTE *)(a2 + 32) & 4) != 0 ) /*0x122f1b*/
        {
          v23 = -1; /*0x122f30*/
          v18 = nullptr; /*0x122f37*/
          if ( dword_1DBA20 ) /*0x122f45*/
          {
            dword_1DBA20 = 0; /*0x122f47*/
            timeout((int)arptimer); /*0x122f5f*/
          }
          v12 = (char *)&arptab + 180 * (*(_DWORD *)(a2 + 4) % 0x13u); /*0x122f7f*/
          v22 = 0; /*0x122f86*/
          v13 = v12; /*0x122f8d*/
          do /*0x122fc1*/
          {
            v14 = v13[11]; /*0x122f90*/
            if ( !v14 ) /*0x122f95*/
              goto LABEL_50; /*0x122f95*/
            if ( (v14 & 4) == 0 && (!v18 || v23 < (unsigned __int8)v13[10]) ) /*0x122fa8*/
            {
              v23 = (unsigned __int8)v13[10]; /*0x122fae*/
              v18 = v13; /*0x122fb1*/
            }
            ++v22; /*0x122fb4*/
            v13 += 20; /*0x122fb7*/
            v12 += 20; /*0x122fba*/
          }
          while ( v22 <= 8 ); /*0x122fc1*/
          if ( !v18 ) /*0x122fc7*/
            goto LABEL_51; /*0x122fc7*/
          v12 = v18; /*0x122fc9*/
          v19 = splimp(); /*0x122fd1*/
          if ( *((_DWORD *)v12 + 3) ) /*0x122fd4*/
            m_freem(*((_DWORD *)v12 + 3)); /*0x122fdc*/
          *((_DWORD *)v12 + 3) = 0; /*0x122fe4*/
          v12[11] = 0; /*0x122feb*/
          v12[10] = 0; /*0x122fef*/
          *(_DWORD *)v12 = 0; /*0x122ff3*/
          splx(v19); /*0x122ffd*/
LABEL_50:
          *(_DWORD *)v12 = *(_DWORD *)(a2 + 4); /*0x12300a*/
          v12[11] = 1; /*0x12300c*/
          *((_DWORD *)v12 + 4) = v24; /*0x123013*/
          if ( !v12 ) /*0x123018*/
          {
LABEL_51:
            v15 = splimp(); /*0x12301f*/
            if ( *((_DWORD *)v5 + 3) ) /*0x123021*/
              m_freem(*((_DWORD *)v5 + 3)); /*0x123029*/
            *((_DWORD *)v5 + 3) = 0; /*0x123031*/
            v5[11] = 0; /*0x123038*/
            v5[10] = 0; /*0x12303c*/
            *(_DWORD *)v5 = 0; /*0x123040*/
            splx(v15); /*0x123047*/
            splx(v25); /*0x123053*/
            return 49; /*0x12305d*/
          }
          v20 = splimp(); /*0x123069*/
          if ( *((_DWORD *)v12 + 3) ) /*0x12306c*/
            m_freem(*((_DWORD *)v12 + 3)); /*0x123074*/
          *((_DWORD *)v12 + 3) = 0; /*0x12307c*/
          v12[11] = 0; /*0x123083*/
          v12[10] = 0; /*0x123087*/
          *(_DWORD *)v12 = 0; /*0x12308b*/
          splx(v20); /*0x123095*/
        }
      }
      bcopy((const void *)(a2 + 18), v5 + 4, 6u); /*0x1230aa*/
      v5[11] = *(_BYTE *)(a2 + 32) & 0x1C | 3; /*0x1230b9*/
      v5[10] = 0; /*0x1230bc*/
    }
    splx(v25); /*0x12311f*/
    return 0; /*0x123124*/
  }
  else
  {
    splx(v25); /*0x122dc2*/
    return 51; /*0x122dc7*/
  }
}
