/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19c898. */
int __cdecl sub_19C898(_DWORD *a1, const char *a2)
{
  unsigned int v2; // kr04_4
  int result; // eax
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  _BYTE *v8; // edx
  int v9; // eax
  _WORD *v10; // edx
  int v11; // eax
  _DWORD *v12; // edx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // edx
  _BYTE *v21; // edx
  int v22; // eax
  _WORD *v23; // edx
  int v24; // eax
  _DWORD *v25; // edx
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // edx
  _BYTE *v31; // edx
  int v32; // eax
  _WORD *v33; // edx
  int v34; // eax
  _DWORD *v35; // edx
  int v36; // eax
  int v37; // ebx
  int v38; // eax
  unsigned int v39; // edx
  unsigned int v40; // eax
  _BYTE *v41; // edx
  int ii; // eax
  _WORD *v43; // edx
  int n; // eax
  _DWORD *v45; // edx
  int m; // eax
  int v47; // ebx
  int v48; // eax
  unsigned int v49; // edx
  unsigned int v50; // eax
  _BYTE *v51; // edx
  int mm; // eax
  _WORD *v53; // edx
  int kk; // eax
  _DWORD *v55; // edx
  int jj; // eax
  int v57; // ebx
  int v58; // eax
  unsigned int v59; // edx
  unsigned int v60; // edx
  _BYTE *v61; // edx
  int v62; // eax
  _WORD *v63; // edx
  int v64; // eax
  _DWORD *v65; // edx
  int v66; // eax
  int v67; // ebx
  int v68; // eax
  unsigned int v69; // edx
  unsigned int v70; // edx
  _BYTE *v71; // edx
  int v72; // eax
  _WORD *v73; // edx
  int v74; // eax
  _DWORD *v75; // edx
  int v76; // eax
  char v77; // [esp-4h] [ebp-90h]
  int v78; // [esp+Ch] [ebp-80h]
  int v79; // [esp+Ch] [ebp-80h]
  int v80; // [esp+Ch] [ebp-80h]
  int v81; // [esp+Ch] [ebp-80h]
  int v82; // [esp+Ch] [ebp-80h]
  int v83; // [esp+Ch] [ebp-80h]
  int i1; // [esp+Ch] [ebp-80h]
  int v85; // [esp+10h] [ebp-7Ch]
  int v86; // [esp+10h] [ebp-7Ch]
  int v87; // [esp+10h] [ebp-7Ch]
  int v88; // [esp+18h] [ebp-74h]
  int v89; // [esp+1Ch] [ebp-70h]
  int v90; // [esp+20h] [ebp-6Ch]
  int v91; // [esp+24h] [ebp-68h]
  int v92; // [esp+28h] [ebp-64h]
  int v93; // [esp+2Ch] [ebp-60h]
  int nn; // [esp+30h] [ebp-5Ch]
  int v95; // [esp+34h] [ebp-58h]
  int v96; // [esp+38h] [ebp-54h]
  int v97; // [esp+3Ch] [ebp-50h]
  int v98; // [esp+40h] [ebp-4Ch]
  int v99; // [esp+44h] [ebp-48h]
  int v100; // [esp+48h] [ebp-44h]
  int v101; // [esp+4Ch] [ebp-40h]
  int k; // [esp+50h] [ebp-3Ch]
  int v103; // [esp+54h] [ebp-38h]
  int v104; // [esp+58h] [ebp-34h]
  int v105; // [esp+5Ch] [ebp-30h]
  int j; // [esp+60h] [ebp-2Ch]
  int v107; // [esp+64h] [ebp-28h]
  int v108; // [esp+68h] [ebp-24h]
  int v109; // [esp+6Ch] [ebp-20h]
  int i; // [esp+70h] [ebp-1Ch]
  int v111; // [esp+74h] [ebp-18h]
  int v112; // [esp+78h] [ebp-14h]
  int v113; // [esp+7Ch] [ebp-10h]
  int v114; // [esp+7Ch] [ebp-10h]
  int v115; // [esp+84h] [ebp-8h]
  int v116; // [esp+88h] [ebp-4h]

  v116 = a1[41]; /*0x19c8ad*/
  v115 = a1[42]; /*0x19c8b6*/
  v2 = strlen(a2) + 1; /*0x19c8c6*/
  if ( v2 == 1 || a1[37] < (signed int)(v2 - 1) ) /*0x19c8d8*/
    return IOLog(aConsoleIllegal_0); /*0x19c8e3*/
  sub_19BA18(a1); /*0x19c8f1*/
  if ( a1[48] ) /*0x19c8f9*/
  {
    a1[36] -= 24; /*0x19c902*/
    a1[39] += 2; /*0x19c909*/
    a1[40] += 24; /*0x19c910*/
    v116 += 2; /*0x19c917*/
  }
  a1[41] = 0; /*0x19c91b*/
  v78 = a1[35]; /*0x19c92b*/
  v112 = a1[36]; /*0x19c934*/
  v111 = 8 * a1[37]; /*0x19c940*/
  v4 = a1[45]; /*0x19c943*/
  for ( i = 21; i != -1; --i ) /*0x19c949*/
  {
    v5 = v112++; /*0x19c950*/
    v6 = a1[7]; /*0x19c959*/
    if ( v6 > 3 ) /*0x19c95f*/
    {
      if ( v6 != 4 ) /*0x19c973*/
LABEL_16:
        panic(aFbconsolePixel); /*0x19c9b0*/
      v109 = a1[6] + a1[4] * v5 + 4 * v78; /*0x19c9a9*/
    }
    else if ( v6 >= 2 ) /*0x19c964*/
    {
      v109 = a1[6] + a1[4] * v5 + 2 * v78; /*0x19c995*/
    }
    else
    {
      if ( v6 != 1 ) /*0x19c969*/
        goto LABEL_16; /*0x19c969*/
      v109 = v78 + a1[6] + a1[4] * v5; /*0x19c982*/
    }
    v7 = a1[7]; /*0x19c9c0*/
    if ( v7 > 3 ) /*0x19c9c6*/
    {
      if ( v7 != 4 ) /*0x19c9d7*/
LABEL_32:
        panic(aFbconsoleFillB); /*0x19ca2c*/
      v12 = (_DWORD *)v109; /*0x19ca10*/
      v13 = v111 - 1; /*0x19ca13*/
      if ( v111 ) /*0x19ca17*/
      {
        do /*0x19ca25*/
        {
          *v12++ = v4; /*0x19ca1c*/
          --v13; /*0x19ca21*/
        }
        while ( v13 != -1 ); /*0x19ca25*/
      }
    }
    else if ( v7 >= 2 ) /*0x19c9cb*/
    {
      v10 = (_WORD *)v109; /*0x19c9f4*/
      v11 = v111 - 1; /*0x19c9f7*/
      if ( v111 ) /*0x19c9fb*/
      {
        do /*0x19ca0a*/
        {
          *v10++ = v4; /*0x19ca00*/
          --v11; /*0x19ca06*/
        }
        while ( v11 != -1 ); /*0x19ca0a*/
      }
    }
    else
    {
      if ( v7 != 1 ) /*0x19c9d0*/
        goto LABEL_32; /*0x19c9d0*/
      v8 = (_BYTE *)v109; /*0x19c9dc*/
      v9 = v111 - 1; /*0x19c9df*/
      if ( v111 ) /*0x19c9e3*/
      {
        do /*0x19c9ef*/
        {
          *v8++ = v4; /*0x19c9e8*/
          --v9; /*0x19c9eb*/
        }
        while ( v9 != -1 ); /*0x19c9ef*/
      }
    }
  }
  v14 = a1[36]; /*0x19ca46*/
  a1[36] = v14 + 6; /*0x19ca4f*/
  a1[42] = (int)(a1[37] - (v2 - 1)) / 2; /*0x19ca67*/
  sub_19BA18(a1); /*0x19ca6e*/
  v15 = a1[45]; /*0x19ca76*/
  a1[45] = a1[44]; /*0x19ca82*/
  a1[44] = v15; /*0x19ca88*/
  while ( *a2 ) /*0x19caaa*/
  {
    v77 = *a2++; /*0x19ca96*/
    sub_19BFA0(a1, v77); /*0x19ca9c*/
  }
  v16 = a1[45]; /*0x19caac*/
  a1[45] = a1[44]; /*0x19cab8*/
  a1[44] = v16; /*0x19cabe*/
  sub_19BA18(a1); /*0x19cac5*/
  a1[36] = v14; /*0x19caca*/
  v79 = a1[35] - 2; /*0x19cad9*/
  v108 = v14 - 2; /*0x19cadf*/
  v107 = a1[38] + 4; /*0x19caeb*/
  v17 = a1[47]; /*0x19caee*/
  for ( j = 1; j != -1; --j ) /*0x19caf7*/
  {
    v18 = v108++; /*0x19cb00*/
    v19 = a1[7]; /*0x19cb09*/
    if ( v19 > 3 ) /*0x19cb0f*/
    {
      if ( v19 != 4 ) /*0x19cb23*/
LABEL_47:
        panic(aFbconsolePixel); /*0x19cb60*/
      v105 = a1[6] + a1[4] * v18 + 4 * v79; /*0x19cb59*/
    }
    else if ( v19 >= 2 ) /*0x19cb14*/
    {
      v105 = a1[6] + a1[4] * v18 + 2 * v79; /*0x19cb45*/
    }
    else
    {
      if ( v19 != 1 ) /*0x19cb19*/
        goto LABEL_47; /*0x19cb19*/
      v105 = v79 + a1[6] + a1[4] * v18; /*0x19cb32*/
    }
    v20 = a1[7]; /*0x19cb70*/
    if ( v20 > 3 ) /*0x19cb76*/
    {
      if ( v20 != 4 ) /*0x19cb87*/
LABEL_63:
        panic(aFbconsoleFillB); /*0x19cbdc*/
      v25 = (_DWORD *)v105; /*0x19cbc0*/
      v26 = v107 - 1; /*0x19cbc3*/
      if ( v107 ) /*0x19cbc7*/
      {
        do /*0x19cbd5*/
        {
          *v25++ = v17; /*0x19cbcc*/
          --v26; /*0x19cbd1*/
        }
        while ( v26 != -1 ); /*0x19cbd5*/
      }
    }
    else if ( v20 >= 2 ) /*0x19cb7b*/
    {
      v23 = (_WORD *)v105; /*0x19cba4*/
      v24 = v107 - 1; /*0x19cba7*/
      if ( v107 ) /*0x19cbab*/
      {
        do /*0x19cbba*/
        {
          *v23++ = v17; /*0x19cbb0*/
          --v24; /*0x19cbb6*/
        }
        while ( v24 != -1 ); /*0x19cbba*/
      }
    }
    else
    {
      if ( v20 != 1 ) /*0x19cb80*/
        goto LABEL_63; /*0x19cb80*/
      v21 = (_BYTE *)v105; /*0x19cb8c*/
      v22 = v107 - 1; /*0x19cb8f*/
      if ( v107 ) /*0x19cb93*/
      {
        do /*0x19cb9f*/
        {
          *v21++ = v17; /*0x19cb98*/
          --v22; /*0x19cb9b*/
        }
        while ( v22 != -1 ); /*0x19cb9f*/
      }
    }
  }
  v80 = a1[35] - 2; /*0x19cbff*/
  v104 = a1[36] + 19; /*0x19cc0b*/
  v103 = a1[38] + 4; /*0x19cc17*/
  v27 = a1[46]; /*0x19cc1a*/
  for ( k = 1; k != -1; --k ) /*0x19cc20*/
  {
    v28 = v104++; /*0x19cc28*/
    v29 = a1[7]; /*0x19cc31*/
    if ( v29 > 3 ) /*0x19cc37*/
    {
      if ( v29 != 4 ) /*0x19cc4b*/
LABEL_75:
        panic(aFbconsolePixel); /*0x19cc88*/
      v101 = a1[6] + a1[4] * v28 + 4 * v80; /*0x19cc81*/
    }
    else if ( v29 >= 2 ) /*0x19cc3c*/
    {
      v101 = a1[6] + a1[4] * v28 + 2 * v80; /*0x19cc6d*/
    }
    else
    {
      if ( v29 != 1 ) /*0x19cc41*/
        goto LABEL_75; /*0x19cc41*/
      v101 = v80 + a1[6] + a1[4] * v28; /*0x19cc5a*/
    }
    v30 = a1[7]; /*0x19cc98*/
    if ( v30 > 3 ) /*0x19cc9e*/
    {
      if ( v30 != 4 ) /*0x19ccaf*/
LABEL_91:
        panic(aFbconsoleFillB); /*0x19cd04*/
      v35 = (_DWORD *)v101; /*0x19cce8*/
      v36 = v103 - 1; /*0x19cceb*/
      if ( v103 ) /*0x19ccef*/
      {
        do /*0x19ccfd*/
        {
          *v35++ = v27; /*0x19ccf4*/
          --v36; /*0x19ccf9*/
        }
        while ( v36 != -1 ); /*0x19ccfd*/
      }
    }
    else if ( v30 >= 2 ) /*0x19cca3*/
    {
      v33 = (_WORD *)v101; /*0x19cccc*/
      v34 = v103 - 1; /*0x19cccf*/
      if ( v103 ) /*0x19ccd3*/
      {
        do /*0x19cce2*/
        {
          *v33++ = v27; /*0x19ccd8*/
          --v34; /*0x19ccde*/
        }
        while ( v34 != -1 ); /*0x19cce2*/
      }
    }
    else
    {
      if ( v30 != 1 ) /*0x19cca8*/
        goto LABEL_91; /*0x19cca8*/
      v31 = (_BYTE *)v101; /*0x19ccb4*/
      v32 = v103 - 1; /*0x19ccb7*/
      if ( v103 ) /*0x19ccbb*/
      {
        do /*0x19ccc7*/
        {
          *v31++ = v27; /*0x19ccc0*/
          --v32; /*0x19ccc3*/
        }
        while ( v32 != -1 ); /*0x19ccc7*/
      }
    }
  }
  v113 = 0; /*0x19cd1e*/
  v88 = 23; /*0x19cd25*/
  do /*0x19ce55*/
  {
    v37 = a1[35] + v113 - 2; /*0x19cd3e*/
    v100 = a1[36] + v113 - 2; /*0x19cd44*/
    v85 = a1[47]; /*0x19cd4d*/
    v81 = v88 - 1; /*0x19cd54*/
    if ( v88 ) /*0x19cd5a*/
    {
      do /*0x19ce44*/
      {
        v38 = v100++; /*0x19cd60*/
        v39 = a1[7]; /*0x19cd69*/
        if ( v39 > 3 ) /*0x19cd6f*/
        {
          if ( v39 != 4 ) /*0x19cd83*/
LABEL_104:
            panic(aFbconsolePixel); /*0x19cdb8*/
          v99 = a1[6] + a1[4] * v38 + 4 * v37; /*0x19cdb2*/
        }
        else if ( v39 >= 2 ) /*0x19cd74*/
        {
          v99 = a1[6] + a1[4] * v38 + 2 * v37; /*0x19cda2*/
        }
        else
        {
          if ( v39 != 1 ) /*0x19cd79*/
            goto LABEL_104; /*0x19cd79*/
          v99 = v37 + a1[6] + a1[4] * v38; /*0x19cd91*/
        }
        v40 = a1[7]; /*0x19cdc5*/
        if ( v40 > 3 ) /*0x19cdcb*/
        {
          if ( v40 != 4 ) /*0x19cddf*/
LABEL_120:
            panic(aFbconsoleFillB); /*0x19ce30*/
          v45 = (_DWORD *)v99; /*0x19ce18*/
          for ( m = 0; m != -1; --m ) /*0x19ce1b*/
            *v45++ = v85; /*0x19ce23*/
        }
        else if ( v40 >= 2 ) /*0x19cdd0*/
        {
          v43 = (_WORD *)v99; /*0x19cdfc*/
          for ( n = 0; n != -1; --n ) /*0x19cdff*/
            *v43++ = v85; /*0x19ce08*/
        }
        else
        {
          if ( v40 != 1 ) /*0x19cdd5*/
            goto LABEL_120; /*0x19cdd5*/
          v41 = (_BYTE *)v99; /*0x19cde4*/
          for ( ii = 0; ii != -1; --ii ) /*0x19cde7*/
            *v41++ = v85; /*0x19cdef*/
        }
        --v81; /*0x19ce3d*/
      }
      while ( v81 != -1 ); /*0x19ce44*/
    }
    v88 -= 2; /*0x19ce4a*/
    ++v113; /*0x19ce4e*/
  }
  while ( v113 <= 1 ); /*0x19ce55*/
  v114 = 1; /*0x19ce5b*/
  v89 = 21; /*0x19ce62*/
  do /*0x19cf99*/
  {
    v47 = v114 + a1[38] + a1[35] - 1; /*0x19ce7b*/
    v98 = a1[36] - v114; /*0x19ce87*/
    v86 = a1[46]; /*0x19ce90*/
    v82 = v89 - 1; /*0x19ce97*/
    if ( v89 ) /*0x19ce9d*/
    {
      do /*0x19cf88*/
      {
        v48 = v98++; /*0x19cea4*/
        v49 = a1[7]; /*0x19cead*/
        if ( v49 > 3 ) /*0x19ceb3*/
        {
          if ( v49 != 4 ) /*0x19cec7*/
LABEL_134:
            panic(aFbconsolePixel); /*0x19cefc*/
          v97 = a1[6] + a1[4] * v48 + 4 * v47; /*0x19cef6*/
        }
        else if ( v49 >= 2 ) /*0x19ceb8*/
        {
          v97 = a1[6] + a1[4] * v48 + 2 * v47; /*0x19cee6*/
        }
        else
        {
          if ( v49 != 1 ) /*0x19cebd*/
            goto LABEL_134; /*0x19cebd*/
          v97 = v47 + a1[6] + a1[4] * v48; /*0x19ced5*/
        }
        v50 = a1[7]; /*0x19cf09*/
        if ( v50 > 3 ) /*0x19cf0f*/
        {
          if ( v50 != 4 ) /*0x19cf23*/
LABEL_150:
            panic(aFbconsoleFillB); /*0x19cf74*/
          v55 = (_DWORD *)v97; /*0x19cf5c*/
          for ( jj = 0; jj != -1; --jj ) /*0x19cf5f*/
            *v55++ = v86; /*0x19cf67*/
        }
        else if ( v50 >= 2 ) /*0x19cf14*/
        {
          v53 = (_WORD *)v97; /*0x19cf40*/
          for ( kk = 0; kk != -1; --kk ) /*0x19cf43*/
            *v53++ = v86; /*0x19cf4c*/
        }
        else
        {
          if ( v50 != 1 ) /*0x19cf19*/
            goto LABEL_150; /*0x19cf19*/
          v51 = (_BYTE *)v97; /*0x19cf28*/
          for ( mm = 0; mm != -1; --mm ) /*0x19cf2b*/
            *v51++ = v86; /*0x19cf33*/
        }
        --v82; /*0x19cf81*/
      }
      while ( v82 != -1 ); /*0x19cf88*/
    }
    v89 += 2; /*0x19cf8e*/
    ++v114; /*0x19cf92*/
  }
  while ( v114 <= 2 ); /*0x19cf99*/
  v83 = a1[35] - 3; /*0x19cfa8*/
  v96 = a1[36] + 21; /*0x19cfb4*/
  v95 = a1[38] + 6; /*0x19cfc0*/
  v57 = a1[45]; /*0x19cfc3*/
  for ( nn = 0; nn != -1; --nn ) /*0x19cfc9*/
  {
    v58 = v96++; /*0x19cfd0*/
    v59 = a1[7]; /*0x19cfd9*/
    if ( v59 > 3 ) /*0x19cfdf*/
    {
      if ( v59 != 4 ) /*0x19cff3*/
LABEL_163:
        panic(aFbconsolePixel); /*0x19d030*/
      v93 = a1[6] + a1[4] * v58 + 4 * v83; /*0x19d029*/
    }
    else if ( v59 >= 2 ) /*0x19cfe4*/
    {
      v93 = a1[6] + a1[4] * v58 + 2 * v83; /*0x19d015*/
    }
    else
    {
      if ( v59 != 1 ) /*0x19cfe9*/
        goto LABEL_163; /*0x19cfe9*/
      v93 = v83 + a1[6] + a1[4] * v58; /*0x19d002*/
    }
    v60 = a1[7]; /*0x19d040*/
    if ( v60 > 3 ) /*0x19d046*/
    {
      if ( v60 != 4 ) /*0x19d057*/
LABEL_179:
        panic(aFbconsoleFillB); /*0x19d0ac*/
      v65 = (_DWORD *)v93; /*0x19d090*/
      v66 = v95 - 1; /*0x19d093*/
      if ( v95 ) /*0x19d097*/
      {
        do /*0x19d0a5*/
        {
          *v65++ = v57; /*0x19d09c*/
          --v66; /*0x19d0a1*/
        }
        while ( v66 != -1 ); /*0x19d0a5*/
      }
    }
    else if ( v60 >= 2 ) /*0x19d04b*/
    {
      v63 = (_WORD *)v93; /*0x19d074*/
      v64 = v95 - 1; /*0x19d077*/
      if ( v95 ) /*0x19d07b*/
      {
        do /*0x19d08a*/
        {
          *v63++ = v57; /*0x19d080*/
          --v64; /*0x19d086*/
        }
        while ( v64 != -1 ); /*0x19d08a*/
      }
    }
    else
    {
      if ( v60 != 1 ) /*0x19d050*/
        goto LABEL_179; /*0x19d050*/
      v61 = (_BYTE *)v93; /*0x19d05c*/
      v62 = v95 - 1; /*0x19d05f*/
      if ( v95 ) /*0x19d063*/
      {
        do /*0x19d06f*/
        {
          *v61++ = v57; /*0x19d068*/
          --v62; /*0x19d06b*/
        }
        while ( v62 != -1 ); /*0x19d06f*/
      }
    }
  }
  a1[36] += 24; /*0x19d0c6*/
  a1[39] -= 2; /*0x19d0cd*/
  a1[40] -= 24; /*0x19d0d4*/
  a1[42] = v115; /*0x19d0de*/
  if ( v116 <= 0 ) /*0x19d0e8*/
  {
    v67 = a1[35] + 8 * v115; /*0x19d105*/
    v92 = a1[36] + 12 * a1[41]; /*0x19d11a*/
    v91 = a1[38] - 8 * v115; /*0x19d129*/
    for ( i1 = 0; i1 <= 11; ++i1 ) /*0x19d12c*/
    {
      v68 = v92++; /*0x19d134*/
      v69 = a1[7]; /*0x19d13d*/
      if ( v69 > 3 ) /*0x19d143*/
      {
        if ( v69 != 4 ) /*0x19d157*/
LABEL_193:
          panic(aFbconsolePixel); /*0x19d18c*/
        v90 = a1[6] + a1[4] * v68 + 4 * v67; /*0x19d186*/
      }
      else if ( v69 >= 2 ) /*0x19d148*/
      {
        v90 = a1[6] + a1[4] * v68 + 2 * v67; /*0x19d176*/
      }
      else
      {
        if ( v69 != 1 ) /*0x19d14d*/
          goto LABEL_193; /*0x19d14d*/
        v90 = v67 + a1[6] + a1[4] * v68; /*0x19d165*/
      }
      v87 = a1[44]; /*0x19d19f*/
      v70 = a1[7]; /*0x19d1a5*/
      if ( v70 > 3 ) /*0x19d1ab*/
      {
        if ( v70 != 4 ) /*0x19d1bf*/
LABEL_209:
          panic(aFbconsoleFillB); /*0x19d21c*/
        v75 = (_DWORD *)v90; /*0x19d200*/
        v76 = v91 - 1; /*0x19d203*/
        if ( v91 ) /*0x19d207*/
        {
          do /*0x19d218*/
          {
            *v75++ = v87; /*0x19d20f*/
            --v76; /*0x19d214*/
          }
          while ( v76 != -1 ); /*0x19d218*/
        }
      }
      else if ( v70 >= 2 ) /*0x19d1b0*/
      {
        v73 = (_WORD *)v90; /*0x19d1e0*/
        v74 = v91 - 1; /*0x19d1e3*/
        if ( v91 ) /*0x19d1e7*/
        {
          do /*0x19d1fa*/
          {
            *v73++ = v87; /*0x19d1f0*/
            --v74; /*0x19d1f6*/
          }
          while ( v74 != -1 ); /*0x19d1fa*/
        }
      }
      else
      {
        if ( v70 != 1 ) /*0x19d1b5*/
          goto LABEL_209; /*0x19d1b5*/
        v71 = (_BYTE *)v90; /*0x19d1c4*/
        v72 = v91 - 1; /*0x19d1c7*/
        if ( v91 ) /*0x19d1cb*/
        {
          do /*0x19d1da*/
          {
            *v71++ = v87; /*0x19d1d3*/
            --v72; /*0x19d1d6*/
          }
          while ( v72 != -1 ); /*0x19d1da*/
        }
      }
    }
  }
  else
  {
    a1[41] = v116 - 2; /*0x19d0f0*/
  }
  result = sub_19BA18(a1); /*0x19d237*/
  a1[48] = 1; /*0x19d23c*/
  return result; /*0x19d24c*/
}
