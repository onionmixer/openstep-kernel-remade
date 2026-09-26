/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1421b8. */
int __cdecl sub_1421B8(unsigned int a1)
{
  int v1; // eax
  int v2; // edi
  int v4; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // edx
  int v10; // edx
  _DWORD *v11; // eax
  void *v12; // eax
  int v13; // [esp+Ch] [ebp-Ch]
  void *v14; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v15; // [esp+14h] [ebp-4h] BYREF

  while ( 1 ) /*0x1421d9*/
  {
    v1 = sub_1425A4(a1); /*0x1421d9*/
    v2 = v1; /*0x1421de*/
    if ( !v1 ) /*0x1421e5*/
      break; /*0x1421e5*/
    v13 = 0; /*0x1421eb*/
    if ( (*(_BYTE *)a1 & 1) != 0 ) /*0x1421f5*/
    {
      sub_14286C(a1); /*0x1421f8*/
      return 11; /*0x142202*/
    }
    v4 = *(_DWORD *)(v1 + 12); /*0x142208*/
    while ( *(_DWORD *)(v4 + 20) ) /*0x14220b*/
    {
      v5 = v13++; /*0x142211*/
      if ( v5 > 49 ) /*0x14221a*/
        break; /*0x14221a*/
      v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 20) + 20) + 12); /*0x142222*/
      if ( *(_DWORD *)(a1 + 12) == v4 ) /*0x142228*/
      {
        sub_14286C(a1); /*0x14222b*/
        return 78; /*0x142235*/
      }
    }
    *(_DWORD *)(a1 + 20) = v2; /*0x14223c*/
    sub_142754(v2, a1); /*0x142241*/
    *(_DWORD *)(*(_DWORD *)(a1 + 12) + 20) = a1; /*0x142249*/
    v6 = sleep(a1); /*0x142253*/
    *(_DWORD *)(*(_DWORD *)(a1 + 12) + 20) = 0; /*0x14225d*/
    if ( v6 ) /*0x142269*/
    {
      sub_142780(v2, a1); /*0x142271*/
      sub_14286C(a1); /*0x142277*/
      return 4; /*0x142281*/
    }
  }
  v15 = (_DWORD *)(*(_DWORD *)(a1 + 16) + 4); /*0x14228e*/
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 4); /*0x142294*/
  v8 = 1; /*0x142297*/
  while ( 2 ) /*0x14229c*/
  {
    v9 = sub_142600(v7, a1, 1, &v15, &v14); /*0x14229c*/
    if ( v9 ) /*0x1422b4*/
      v7 = *((_DWORD *)v14 + 5); /*0x1422b9*/
    switch ( v9 ) /*0x1422c5*/
    {
      case 0: /*0x1422c5*/
        if ( v8 ) /*0x1422e6*/
        {
          *v15 = a1; /*0x1422ef*/
          *(_DWORD *)(a1 + 20) = v14; /*0x1422f4*/
        }
        return 0; /*0x1422f7*/
      case 1: /*0x1422c5*/
        if ( *(_WORD *)(a1 + 2) == 1 && *((_WORD *)v14 + 1) == 2 ) /*0x14230b*/
          sub_14282C(v14); /*0x14230e*/
        *((_WORD *)v14 + 1) = *(_WORD *)(a1 + 2); /*0x14231d*/
        goto LABEL_22; /*0x142321*/
      case 2: /*0x1422c5*/
        if ( *((_WORD *)v14 + 1) == *(_WORD *)(a1 + 2) ) /*0x14232f*/
        {
LABEL_22:
          sub_14286C(a1); /*0x142331*/
        }
        else
        {
          if ( *((_DWORD *)v14 + 1) == *(_DWORD *)(a1 + 4) ) /*0x142342*/
          {
            *v15 = a1; /*0x142347*/
            *(_DWORD *)(a1 + 20) = v14; /*0x14234c*/
            *((_DWORD *)v14 + 1) = *(_DWORD *)(a1 + 8) + 1; /*0x142356*/
          }
          else
          {
            sub_1427B4(v14, a1); /*0x14235e*/
          }
          sub_14282C(v14); /*0x14236a*/
        }
        break; /*0x142337*/
      case 3: /*0x1422c5*/
        if ( *(_WORD *)(a1 + 2) == 1 && *((_WORD *)v14 + 1) == 2 ) /*0x14237f*/
        {
          sub_14282C(v14); /*0x142382*/
        }
        else
        {
          v10 = *(_DWORD *)(a1 + 24); /*0x14238c*/
          *(_DWORD *)(a1 + 24) = *((_DWORD *)v14 + 6); /*0x142395*/
          sub_142754(a1, v10); /*0x14239a*/
        }
        if ( v8 ) /*0x1423a4*/
        {
          *v15 = a1; /*0x1423a9*/
          *(_DWORD *)(a1 + 20) = *((_DWORD *)v14 + 5); /*0x1423b1*/
          v15 = (_DWORD *)(a1 + 20); /*0x1423b7*/
          v8 = 0; /*0x1423ba*/
        }
        else
        {
          *v15 = *((_DWORD *)v14 + 5); /*0x1423c9*/
        }
        sub_14286C(v14); /*0x1423cf*/
        continue; /*0x1423d7*/
      case 4: /*0x1422c5*/
        v11 = v14; /*0x1423dc*/
        *(_DWORD *)(a1 + 20) = *((_DWORD *)v14 + 5); /*0x1423e2*/
        v11[5] = a1; /*0x1423e5*/
        v11[2] = *(_DWORD *)(a1 + 4) - 1; /*0x1423ec*/
        v15 = (_DWORD *)(a1 + 20); /*0x1423f2*/
        sub_14282C(v11); /*0x1423f6*/
        v8 = 0; /*0x1423fb*/
        continue; /*0x142400*/
      case 5: /*0x1422c5*/
        if ( v8 ) /*0x14240a*/
        {
          *v15 = a1; /*0x14240f*/
          *(_DWORD *)(a1 + 20) = v14; /*0x142414*/
        }
        v12 = v14; /*0x142417*/
        *((_DWORD *)v14 + 1) = *(_DWORD *)(a1 + 8) + 1; /*0x14241e*/
        sub_14282C(v12); /*0x142422*/
        break; /*0x142422*/
      default:
        return 0;
    }
    return 0; /*0x14242c*/
  }
}
