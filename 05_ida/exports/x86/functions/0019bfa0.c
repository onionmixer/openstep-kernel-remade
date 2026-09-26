/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19bfa0. */
void __cdecl sub_19BFA0(_DWORD *a1, char a2)
{
  int v2; // eax
  unsigned int v3; // edx
  int i; // eax
  int v5; // ebx
  int j; // ebx
  int v7; // eax
  int k; // ebx
  int m; // ebx
  int n; // ebx
  int v11; // eax
  int ii; // ebx
  unsigned __int8 *v13; // edi
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  unsigned int v17; // edx
  int v18; // ecx
  unsigned int v19; // edx
  _BYTE *v20; // edx
  int v21; // eax
  _WORD *v22; // edx
  int v23; // eax
  _DWORD *v24; // edx
  int v25; // eax
  int jj; // eax
  int v27; // eax
  int v28; // edx
  int v29; // eax
  int v30; // edi
  int kk; // ebx
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // edx
  int mm; // ebx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // edx
  _BYTE *v39; // edx
  int i2; // eax
  _WORD *v41; // edx
  int i1; // eax
  _DWORD *v43; // edx
  int nn; // eax
  int v45; // eax
  unsigned int v46; // eax
  int v47; // ecx
  int v48; // eax
  unsigned int v49; // edx
  int v50; // ecx
  int v51; // eax
  unsigned int v52; // edx
  int i3; // ebx
  int v54; // eax
  int v55; // ebx
  int v56; // eax
  unsigned int v57; // edx
  int v58; // ecx
  unsigned int v59; // edx
  _BYTE *v60; // edx
  int v61; // eax
  _WORD *v62; // edx
  int v63; // eax
  _DWORD *v64; // edx
  int v65; // eax
  int v66; // [esp+Ch] [ebp-2Ch]
  int v67; // [esp+Ch] [ebp-2Ch]
  int i4; // [esp+Ch] [ebp-2Ch]
  int v69; // [esp+14h] [ebp-24h]
  int v70; // [esp+18h] [ebp-20h]
  int v71; // [esp+1Ch] [ebp-1Ch]
  int __len; // [esp+20h] [ebp-18h]
  char *__dst; // [esp+24h] [ebp-14h]
  char *__src; // [esp+28h] [ebp-10h]
  int v75; // [esp+2Ch] [ebp-Ch]
  int v76; // [esp+30h] [ebp-8h]
  int v77; // [esp+34h] [ebp-4h]

  if ( *a1 == 2 ) /*0x19bfb2*/
    return; /*0x19bfb2*/
  v2 = a1[54]; /*0x19bfb8*/
  if ( v2 == 1 ) /*0x19bfc1*/
  {
    if ( a2 == 91 ) /*0x19bfeb*/
    {
      a1[54] = 2; /*0x19bfed*/
      return; /*0x19bff7*/
    }
    a1[54] = 0; /*0x19bffc*/
    goto LABEL_11; /*0x19bffc*/
  }
  if ( v2 ) /*0x19bfc3*/
  {
    if ( v2 != 2 ) /*0x19bfc8*/
      goto LABEL_74; /*0x19bfc8*/
LABEL_11:
    if ( (unsigned __int8)(a2 - 48) <= 9u ) /*0x19c00e*/
    {
      *(_BYTE *)a1[56] = 10 * *(_BYTE *)a1[56] + a2 - 48; /*0x19c020*/
      return; /*0x19c022*/
    }
    if ( a2 == 59 ) /*0x19c02b*/
    {
      v3 = a1[56]; /*0x19c033*/
      if ( v3 < (unsigned int)a1 + 223 ) /*0x19c03b*/
        a1[56] = v3 + 1; /*0x19c042*/
      return; /*0x19c048*/
    }
    for ( i = 0; i <= 2; ++i ) /*0x19c050*/
    {
      if ( !*((_BYTE *)a1 + i + 220) ) /*0x19c054*/
        *((_BYTE *)a1 + i + 220) = 1; /*0x19c05e*/
    }
    v5 = *(unsigned __int8 *)a1[56]; /*0x19c072*/
    sub_19BA18(a1); /*0x19c079*/
    switch ( a2 ) /*0x19c094*/
    {
      case 'A': /*0x19c094*/
        for ( j = v5 - 1; j != -1; --j ) /*0x19c154*/
        {
          v7 = a1[41]; /*0x19c15c*/
          if ( v7 ) /*0x19c164*/
            a1[41] = v7 - 1; /*0x19c167*/
        }
        goto LABEL_71; /*0x19c171*/
      case 'B': /*0x19c094*/
        for ( k = v5 - 1; k != -1; --k ) /*0x19c17c*/
          ++a1[41]; /*0x19c184*/
        goto LABEL_71; /*0x19c18e*/
      case 'C': /*0x19c094*/
        for ( m = v5 - 1; m != -1; --m ) /*0x19c19c*/
          ++a1[42]; /*0x19c1a4*/
        goto LABEL_71; /*0x19c1ae*/
      case 'D': /*0x19c094*/
        for ( n = v5 - 1; n != -1; --n ) /*0x19c1bc*/
        {
          v11 = a1[42]; /*0x19c1c4*/
          if ( v11 ) /*0x19c1cc*/
            a1[42] = v11 - 1; /*0x19c1cf*/
        }
        goto LABEL_71; /*0x19c1d9*/
      case 'E': /*0x19c094*/
        a1[42] = 0; /*0x19c1e0*/
        for ( ii = v5 - 1; ii != -1; --ii ) /*0x19c1ee*/
          ++a1[41]; /*0x19c1f4*/
        goto LABEL_71; /*0x19c1fe*/
      case 'H': /*0x19c094*/
      case 'f': /*0x19c094*/
        a1[42] = *(unsigned __int8 *)a1[56] - 1; /*0x19c212*/
        v13 = (unsigned __int8 *)(a1[56] - 1); /*0x19c21e*/
        a1[56] = v13; /*0x19c221*/
        a1[41] = *v13 - 1; /*0x19c22c*/
        --a1[56]; /*0x19c232*/
        goto LABEL_71; /*0x19c238*/
      case 'K': /*0x19c094*/
        v14 = 8 * a1[42]; /*0x19c246*/
        v15 = v14 + a1[35]; /*0x19c253*/
        v77 = a1[36] + 12 * a1[41]; /*0x19c267*/
        v76 = a1[38] - v14; /*0x19c272*/
        v66 = 0; /*0x19c275*/
        break; /*0x19c275*/
      case 'm': /*0x19c094*/
        a1[56] -= 2; /*0x19c374*/
        goto LABEL_71; /*0x19c374*/
      default:
        goto LABEL_71;
    }
    do /*0x19c36c*/
    {
      v16 = v77++; /*0x19c27c*/
      v17 = a1[7]; /*0x19c285*/
      if ( v17 > 3 ) /*0x19c28b*/
      {
        if ( v17 != 4 ) /*0x19c29f*/
LABEL_51:
          panic(aFbconsolePixel); /*0x19c2d4*/
        v75 = a1[6] + a1[4] * v16 + 4 * v15; /*0x19c2ce*/
      }
      else if ( v17 >= 2 ) /*0x19c290*/
      {
        v75 = a1[6] + a1[4] * v16 + 2 * v15; /*0x19c2be*/
      }
      else
      {
        if ( v17 != 1 ) /*0x19c295*/
          goto LABEL_51; /*0x19c295*/
        v75 = v15 + a1[6] + a1[4] * v16; /*0x19c2ad*/
      }
      v18 = a1[44]; /*0x19c2e1*/
      v19 = a1[7]; /*0x19c2ea*/
      if ( v19 > 3 ) /*0x19c2f0*/
      {
        if ( v19 != 4 ) /*0x19c303*/
LABEL_67:
          panic(aFbconsoleFillB); /*0x19c358*/
        v24 = (_DWORD *)v75; /*0x19c33c*/
        v25 = v76 - 1; /*0x19c33f*/
        if ( v76 ) /*0x19c343*/
        {
          do /*0x19c351*/
          {
            *v24++ = v18; /*0x19c348*/
            --v25; /*0x19c34d*/
          }
          while ( v25 != -1 ); /*0x19c351*/
        }
      }
      else if ( v19 >= 2 ) /*0x19c2f5*/
      {
        v22 = (_WORD *)v75; /*0x19c320*/
        v23 = v76 - 1; /*0x19c323*/
        if ( v76 ) /*0x19c327*/
        {
          do /*0x19c336*/
          {
            *v22++ = v18; /*0x19c32c*/
            --v23; /*0x19c332*/
          }
          while ( v23 != -1 ); /*0x19c336*/
        }
      }
      else
      {
        if ( v19 != 1 ) /*0x19c2fa*/
          goto LABEL_67; /*0x19c2fa*/
        v20 = (_BYTE *)v75; /*0x19c308*/
        v21 = v76 - 1; /*0x19c30b*/
        if ( v76 ) /*0x19c30f*/
        {
          do /*0x19c31b*/
          {
            *v20++ = v18; /*0x19c314*/
            --v21; /*0x19c317*/
          }
          while ( v21 != -1 ); /*0x19c31b*/
        }
      }
      ++v66; /*0x19c365*/
    }
    while ( v66 <= 11 ); /*0x19c36c*/
LABEL_71:
    a1[56] = (char *)a1 + 221; /*0x19c37b*/
    for ( jj = 2; jj >= 0; --jj ) /*0x19c387*/
      *((_BYTE *)a1 + jj + 220) = 0; /*0x19c38c*/
    a1[54] = 0; /*0x19c397*/
    goto LABEL_123; /*0x19c3a1*/
  }
  if ( a2 == 27 ) /*0x19bfd3*/
  {
    a1[54] = 1; /*0x19bfd9*/
    return; /*0x19bfe3*/
  }
LABEL_74:
  sub_19BA18(a1); /*0x19c3a8*/
  if ( a2 == 10 )
  {
    a1[42] = 0; /*0x19c408*/
    ++a1[41]; /*0x19c412*/
  }
  else
  {
    if ( a2 <= 10 )
    {
      if ( a2 == 8 ) /*0x19c3c1*/
      {
        v27 = a1[42]; /*0x19c420*/
        if ( v27 ) /*0x19c428*/
          a1[42] = v27 - 1; /*0x19c42f*/
        goto LABEL_123; /*0x19c435*/
      }
      if ( a2 == 9 )
      {
        v28 = a1[42]; /*0x19c43c*/
        v29 = v28 + (v28 < 0 ? 7 : 0);
        LOBYTE(v29) = v29 & 0xF8; /*0x19c44b*/
        v30 = 8 - (v28 - v29); /*0x19c456*/
        sub_19BA18(a1); /*0x19c45c*/
        for ( kk = 0; v30 > kk; ++kk ) /*0x19c468*/
          sub_19BFA0(a1, 32); /*0x19c46f*/
        sub_19BA18(a1); /*0x19c47e*/
        goto LABEL_123; /*0x19c486*/
      }
      goto LABEL_122; /*0x19c3c6*/
    }
    if ( a2 == 13 ) /*0x19c3d3*/
    {
      a1[42] = 0; /*0x19c3f8*/
    }
    else
    {
      if ( a2 <= 13 ) /*0x19c3d5*/
      {
        if ( a2 != 12 ) /*0x19c3da*/
        {
LABEL_122:
          sub_19BD3C(a1, a2); /*0x19c5b8*/
          goto LABEL_123; /*0x19c5bd*/
        }
        a1[42] = 0; /*0x19c48c*/
        a1[41] = 0; /*0x19c496*/
        v32 = a1[35]; /*0x19c4a0*/
        v33 = a1[36]; /*0x19c4a6*/
        v34 = a1[7]; /*0x19c4ac*/
        if ( v34 > 3 ) /*0x19c4b2*/
        {
          if ( v34 != 4 ) /*0x19c4c3*/
LABEL_101:
            panic(aFbconsolePixel); /*0x19c4f8*/
          v67 = a1[6] + a1[4] * v33 + 4 * v32; /*0x19c4f2*/
        }
        else if ( v34 >= 2 ) /*0x19c4b7*/
        {
          v67 = a1[6] + a1[4] * v33 + 2 * v32; /*0x19c4e2*/
        }
        else
        {
          if ( v34 != 1 ) /*0x19c4bc*/
            goto LABEL_101; /*0x19c4bc*/
          v67 = v32 + a1[6] + a1[4] * v33; /*0x19c4d1*/
        }
        for ( mm = 0; a1[40] > mm; ++mm ) /*0x19c50d*/
        {
          v36 = a1[44]; /*0x19c514*/
          v37 = a1[38]; /*0x19c51a*/
          v38 = a1[7]; /*0x19c520*/
          if ( v38 > 3 ) /*0x19c526*/
          {
            if ( v38 != 4 ) /*0x19c537*/
LABEL_118:
              panic(aFbconsoleFillB); /*0x19c58c*/
            v43 = (_DWORD *)v67; /*0x19c570*/
            for ( nn = v37 - 1; nn != -1; --nn ) /*0x19c577*/
              *v43++ = v36; /*0x19c57c*/
          }
          else if ( v38 >= 2 ) /*0x19c52b*/
          {
            v41 = (_WORD *)v67; /*0x19c554*/
            for ( i1 = v37 - 1; i1 != -1; --i1 ) /*0x19c55b*/
              *v41++ = v36; /*0x19c560*/
          }
          else
          {
            if ( v38 != 1 ) /*0x19c530*/
              goto LABEL_118; /*0x19c530*/
            v39 = (_BYTE *)v67; /*0x19c53c*/
            for ( i2 = v37 - 1; i2 != -1; --i2 ) /*0x19c543*/
              *v39++ = v36; /*0x19c548*/
          }
          v67 += a1[4]; /*0x19c59c*/
        }
        goto LABEL_123; /*0x19c5a6*/
      }
      if ( a2 != 127 ) /*0x19c3eb*/
        goto LABEL_122; /*0x19c3eb*/
      ++a1[42]; /*0x19c5b0*/
    }
  }
LABEL_123:
  if ( a1[42] >= a1[37] ) /*0x19c5d1*/
  {
    a1[42] = 0; /*0x19c5d3*/
    ++a1[41]; /*0x19c5dd*/
  }
  v45 = a1[39]; /*0x19c5e3*/
  if ( a1[41] >= v45 ) /*0x19c5ef*/
  {
    a1[41] = v45 - 1; /*0x19c5f6*/
    v46 = a1[7]; /*0x19c5fc*/
    if ( v46 > 3 ) /*0x19c602*/
    {
      if ( v46 != 4 ) /*0x19c613*/
LABEL_135:
        panic(aFbconsoleFbput); /*0x19c644*/
      __len = 4 * a1[38]; /*0x19c63d*/
    }
    else if ( v46 >= 2 ) /*0x19c607*/
    {
      __len = 2 * a1[38]; /*0x19c62c*/
    }
    else
    {
      if ( v46 != 1 ) /*0x19c60c*/
        goto LABEL_135; /*0x19c60c*/
      __len = a1[38]; /*0x19c61e*/
    }
    v47 = a1[35]; /*0x19c651*/
    v48 = a1[36] + 12; /*0x19c65d*/
    v49 = a1[7]; /*0x19c660*/
    if ( v49 > 3 ) /*0x19c666*/
    {
      if ( v49 != 4 ) /*0x19c677*/
LABEL_145:
        panic(aFbconsolePixel); /*0x19c6ac*/
      __src = (char *)(a1[6] + a1[4] * v48 + 4 * v47); /*0x19c6a6*/
    }
    else if ( v49 >= 2 ) /*0x19c66b*/
    {
      __src = (char *)(a1[6] + a1[4] * v48 + 2 * v47); /*0x19c696*/
    }
    else
    {
      if ( v49 != 1 ) /*0x19c670*/
        goto LABEL_145; /*0x19c670*/
      __src = (char *)(v47 + a1[6] + a1[4] * v48); /*0x19c685*/
    }
    v50 = a1[35]; /*0x19c6b9*/
    v51 = a1[36]; /*0x19c6bf*/
    v52 = a1[7]; /*0x19c6c5*/
    if ( v52 > 3 ) /*0x19c6cb*/
    {
      if ( v52 != 4 ) /*0x19c6df*/
LABEL_155:
        panic(aFbconsolePixel); /*0x19c714*/
      __dst = (char *)(a1[6] + a1[4] * v51 + 4 * v50); /*0x19c70e*/
    }
    else if ( v52 >= 2 ) /*0x19c6d0*/
    {
      __dst = (char *)(a1[6] + a1[4] * v51 + 2 * v50); /*0x19c6fe*/
    }
    else
    {
      if ( v52 != 1 ) /*0x19c6d5*/
        goto LABEL_155; /*0x19c6d5*/
      __dst = (char *)(v50 + a1[6] + a1[4] * v51); /*0x19c6ed*/
    }
    for ( i3 = 12; a1[40] > i3; ++i3 ) /*0x19c72c*/
    {
      memmove(__dst, __src, __len); /*0x19c73c*/
      v54 = a1[4]; /*0x19c741*/
      __src += v54; /*0x19c744*/
      __dst += v54; /*0x19c749*/
    }
    a1[42] = 0; /*0x19c758*/
    v55 = a1[35]; /*0x19c762*/
    v71 = a1[36] + 12 * a1[41]; /*0x19c77a*/
    v70 = a1[38]; /*0x19c783*/
    for ( i4 = 0; i4 <= 11; ++i4 ) /*0x19c786*/
    {
      v56 = v71++; /*0x19c790*/
      v57 = a1[7]; /*0x19c799*/
      if ( v57 > 3 ) /*0x19c79f*/
      {
        if ( v57 != 4 ) /*0x19c7b3*/
LABEL_168:
          panic(aFbconsolePixel); /*0x19c7e8*/
        v69 = a1[6] + a1[4] * v56 + 4 * v55; /*0x19c7e2*/
      }
      else if ( v57 >= 2 ) /*0x19c7a4*/
      {
        v69 = a1[6] + a1[4] * v56 + 2 * v55; /*0x19c7d2*/
      }
      else
      {
        if ( v57 != 1 ) /*0x19c7a9*/
          goto LABEL_168; /*0x19c7a9*/
        v69 = v55 + a1[6] + a1[4] * v56; /*0x19c7c1*/
      }
      v58 = a1[44]; /*0x19c7f5*/
      v59 = a1[7]; /*0x19c7fe*/
      if ( v59 > 3 ) /*0x19c804*/
      {
        if ( v59 != 4 ) /*0x19c817*/
LABEL_184:
          panic(aFbconsoleFillB); /*0x19c86c*/
        v64 = (_DWORD *)v69; /*0x19c850*/
        v65 = v70 - 1; /*0x19c853*/
        if ( v70 ) /*0x19c857*/
        {
          do /*0x19c865*/
          {
            *v64++ = v58; /*0x19c85c*/
            --v65; /*0x19c861*/
          }
          while ( v65 != -1 ); /*0x19c865*/
        }
      }
      else if ( v59 >= 2 ) /*0x19c809*/
      {
        v62 = (_WORD *)v69; /*0x19c834*/
        v63 = v70 - 1; /*0x19c837*/
        if ( v70 ) /*0x19c83b*/
        {
          do /*0x19c84a*/
          {
            *v62++ = v58; /*0x19c840*/
            --v63; /*0x19c846*/
          }
          while ( v63 != -1 ); /*0x19c84a*/
        }
      }
      else
      {
        if ( v59 != 1 ) /*0x19c80e*/
          goto LABEL_184; /*0x19c80e*/
        v60 = (_BYTE *)v69; /*0x19c81c*/
        v61 = v70 - 1; /*0x19c81f*/
        if ( v70 ) /*0x19c823*/
        {
          do /*0x19c82f*/
          {
            *v60++ = v58; /*0x19c828*/
            --v61; /*0x19c82b*/
          }
          while ( v61 != -1 ); /*0x19c82f*/
        }
      }
    }
  }
  sub_19BA18(a1); /*0x19c887*/
}
