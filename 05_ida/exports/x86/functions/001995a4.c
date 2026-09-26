/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1995a4. */
char __cdecl sub_1995A4(int a1, int a2, int a3, const char *a4, int a5, int a6)
{
  int v6; // edx
  int j; // ebx
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  int v10; // edi
  unsigned __int8 v11; // al
  unsigned __int8 v12; // al
  int v13; // ebx
  unsigned int v14; // ebx
  unsigned __int8 v15; // al
  int v16; // ebx
  unsigned int v17; // ebx
  unsigned __int8 v18; // al
  unsigned __int8 v19; // cl
  unsigned __int16 v20; // dx
  int v21; // edi
  int v22; // ebx
  unsigned __int8 v23; // al
  unsigned int v24; // ebx
  unsigned __int8 v25; // al
  int v26; // ebx
  _BYTE *v27; // ebx
  int v28; // ebx
  _BYTE *v29; // ebx
  int v30; // ebx
  _BYTE *v31; // ebx
  unsigned __int8 v32; // bl
  int v33; // ebx
  int v34; // ebx
  _BYTE *v35; // ebx
  int v36; // ebx
  _BYTE *v37; // ebx
  int v38; // ebx
  _BYTE *v39; // ebx
  int v40; // ebx
  _BYTE *v41; // ebx
  int v42; // ebx
  _BYTE *v43; // ebx
  int v45; // [esp+10h] [ebp-B0h]
  int v46; // [esp+14h] [ebp-ACh]
  int v47; // [esp+18h] [ebp-A8h]
  int k; // [esp+20h] [ebp-A0h]
  int v49; // [esp+20h] [ebp-A0h]
  int v50; // [esp+20h] [ebp-A0h]
  int i18; // [esp+20h] [ebp-A0h]
  int i19; // [esp+20h] [ebp-A0h]
  int m; // [esp+24h] [ebp-9Ch]
  int n; // [esp+24h] [ebp-9Ch]
  int jj; // [esp+24h] [ebp-9Ch]
  int kk; // [esp+24h] [ebp-9Ch]
  int nn; // [esp+24h] [ebp-9Ch]
  int i1; // [esp+24h] [ebp-9Ch]
  int i3; // [esp+24h] [ebp-9Ch]
  int i4; // [esp+24h] [ebp-9Ch]
  int i6; // [esp+24h] [ebp-9Ch]
  int i7; // [esp+24h] [ebp-9Ch]
  int i9; // [esp+24h] [ebp-9Ch]
  int i10; // [esp+24h] [ebp-9Ch]
  int i12; // [esp+24h] [ebp-9Ch]
  int i13; // [esp+24h] [ebp-9Ch]
  _BYTE *v67; // [esp+24h] [ebp-9Ch]
  int i20; // [esp+24h] [ebp-9Ch]
  unsigned __int8 v69; // [esp+28h] [ebp-98h]
  unsigned __int8 v70; // [esp+28h] [ebp-98h]
  int v71; // [esp+28h] [ebp-98h]
  unsigned __int8 v72; // [esp+28h] [ebp-98h]
  int v73; // [esp+28h] [ebp-98h]
  unsigned __int8 v74; // [esp+28h] [ebp-98h]
  int v75; // [esp+28h] [ebp-98h]
  int v76; // [esp+28h] [ebp-98h]
  _BYTE *v77; // [esp+28h] [ebp-98h]
  unsigned __int8 v78; // [esp+28h] [ebp-98h]
  unsigned __int8 v79; // [esp+28h] [ebp-98h]
  unsigned __int8 v80; // [esp+28h] [ebp-98h]
  int v81; // [esp+28h] [ebp-98h]
  unsigned __int8 v82; // [esp+28h] [ebp-98h]
  int v83; // [esp+28h] [ebp-98h]
  unsigned __int8 v84; // [esp+28h] [ebp-98h]
  int v85; // [esp+28h] [ebp-98h]
  unsigned __int8 v86; // [esp+2Ch] [ebp-94h]
  char *v87; // [esp+30h] [ebp-90h]
  char *v88; // [esp+30h] [ebp-90h]
  char *v89; // [esp+30h] [ebp-90h]
  int v90; // [esp+30h] [ebp-90h]
  _BYTE *v91; // [esp+30h] [ebp-90h]
  int v92; // [esp+30h] [ebp-90h]
  _BYTE *v93; // [esp+30h] [ebp-90h]
  int v94; // [esp+30h] [ebp-90h]
  _BYTE *v95; // [esp+30h] [ebp-90h]
  int v96; // [esp+30h] [ebp-90h]
  int i5; // [esp+30h] [ebp-90h]
  _BYTE *v98; // [esp+30h] [ebp-90h]
  _BYTE *v99; // [esp+30h] [ebp-90h]
  _BYTE *v100; // [esp+30h] [ebp-90h]
  int v101; // [esp+30h] [ebp-90h]
  int i17; // [esp+30h] [ebp-90h]
  int v103; // [esp+30h] [ebp-90h]
  _BYTE *v104; // [esp+30h] [ebp-90h]
  int i; // [esp+34h] [ebp-8Ch]
  int v106; // [esp+34h] [ebp-8Ch]
  int v107; // [esp+34h] [ebp-8Ch]
  int v108; // [esp+34h] [ebp-8Ch]
  int v109; // [esp+34h] [ebp-8Ch]
  int ii; // [esp+34h] [ebp-8Ch]
  int v111; // [esp+34h] [ebp-8Ch]
  int mm; // [esp+34h] [ebp-8Ch]
  int v113; // [esp+34h] [ebp-8Ch]
  int i2; // [esp+34h] [ebp-8Ch]
  int v115; // [esp+34h] [ebp-8Ch]
  _BYTE *v116; // [esp+34h] [ebp-8Ch]
  int i8; // [esp+34h] [ebp-8Ch]
  int i11; // [esp+34h] [ebp-8Ch]
  int v119; // [esp+34h] [ebp-8Ch]
  int i14; // [esp+34h] [ebp-8Ch]
  int v121; // [esp+34h] [ebp-8Ch]
  int i15; // [esp+34h] [ebp-8Ch]
  int i16; // [esp+34h] [ebp-8Ch]
  unsigned __int8 v124; // [esp+3Ch] [ebp-84h]
  unsigned __int8 v125; // [esp+40h] [ebp-80h]
  int v126; // [esp+44h] [ebp-7Ch]
  unsigned __int8 v127; // [esp+48h] [ebp-78h]
  unsigned __int8 v128; // [esp+4Ch] [ebp-74h]
  int v129; // [esp+50h] [ebp-70h]
  unsigned __int8 v130; // [esp+54h] [ebp-6Ch]
  unsigned __int8 v131; // [esp+58h] [ebp-68h]
  int v132; // [esp+5Ch] [ebp-64h]
  unsigned __int8 v133; // [esp+60h] [ebp-60h]
  unsigned __int8 v134; // [esp+64h] [ebp-5Ch]
  int v135; // [esp+68h] [ebp-58h]
  unsigned __int8 v136; // [esp+6Ch] [ebp-54h]
  unsigned __int8 v137; // [esp+70h] [ebp-50h]
  int v138; // [esp+74h] [ebp-4Ch]
  unsigned __int8 v139; // [esp+7Ch] [ebp-44h]
  unsigned __int8 v140; // [esp+80h] [ebp-40h]
  unsigned __int8 v141; // [esp+84h] [ebp-3Ch]
  unsigned __int8 v142; // [esp+88h] [ebp-38h]
  int v143; // [esp+8Ch] [ebp-34h]
  unsigned __int8 v144; // [esp+90h] [ebp-30h]
  unsigned __int8 v145; // [esp+94h] [ebp-2Ch]
  int v146; // [esp+98h] [ebp-28h]
  unsigned __int8 v147; // [esp+9Ch] [ebp-24h]
  unsigned __int8 v148; // [esp+A0h] [ebp-20h]
  int v149; // [esp+A4h] [ebp-1Ch]
  int v150; // [esp+A8h] [ebp-18h]
  int v151; // [esp+ACh] [ebp-14h]
  int v152; // [esp+B0h] [ebp-10h]
  char *v153; // [esp+B4h] [ebp-Ch]
  char *v154; // [esp+B4h] [ebp-Ch]
  signed int v155; // [esp+CCh] [ebp+Ch]
  int v156; // [esp+D0h] [ebp+10h]

  v155 = (a2 + (a2 < 0 ? 7 : 0)) & 0xFFFFFFF8;
  v156 = 12 * (a3 / 12); /*0x1995ea*/
  v6 = *(_DWORD *)(a1 + 4); /*0x1995f0*/
  if ( v155 > v6 - 6 ) /*0x199600*/
    v155 = v6 - 6; /*0x199602*/
  if ( v156 > *(_DWORD *)(a1 + 8) - 6 ) /*0x199611*/
    v156 = *(_DWORD *)(a1 + 8) - 6; /*0x199613*/
  *(_DWORD *)(a1 + 140) = (v6 - v155) / 2; /*0x199635*/
  *(_DWORD *)(a1 + 144) = (*(_DWORD *)(a1 + 8) - v156) / 2; /*0x199654*/
  *(_DWORD *)(a1 + 152) = v155; /*0x19965d*/
  *(_DWORD *)(a1 + 160) = v156; /*0x199666*/
  *(_DWORD *)(a1 + 140) &= 0xFFFFFFF8; /*0x19966c*/
  *(_DWORD *)(a1 + 148) = *(_DWORD *)(a1 + 152) / 8; /*0x199686*/
  *(_DWORD *)(a1 + 156) = *(_DWORD *)(a1 + 160) / 12; /*0x19969f*/
  *(_DWORD *)(a1 + 168) = 0; /*0x1996a5*/
  *(_DWORD *)(a1 + 192) = 0; /*0x1996af*/
  if ( a5 ) /*0x1996bd*/
  {
    if ( a6 ) /*0x1996c7*/
    {
      for ( i = 0; i <= 8; ++i ) /*0x1996cd*/
      {
        v69 = byte_1E467C[i]; /*0x1996ea*/
        __outbyte(0x3CEu, i); /*0x1996f7*/
        _InterlockedIncrement(&dword_1E8654); /*0x1996f8*/
        __outbyte(0x3CFu, v69); /*0x19970a*/
        _InterlockedIncrement(&dword_1E8654); /*0x19970b*/
      }
      if ( *(_DWORD *)(a1 + 256) ) /*0x199724*/
      {
        for ( j = 0; j <= 8; ++j ) /*0x199741*/
        {
          __outbyte(0x3CEu, j); /*0x19974b*/
          _InterlockedIncrement(&dword_1E8654); /*0x19974c*/
          v8 = __inbyte(0x3CFu); /*0x199758*/
          *(_BYTE *)(j + a1 + 230) = v8; /*0x19975f*/
        }
        __outbyte(0x3C4u, 2u); /*0x19976f*/
        _InterlockedIncrement(&dword_1E8654); /*0x199770*/
        v9 = __inbyte(0x3C5u); /*0x19977c*/
        *(_BYTE *)(a1 + 241) = v9; /*0x19977f*/
        *(_DWORD *)(a1 + 200) = v156 + 6; /*0x19978b*/
        v10 = v155 / 8 + 2; /*0x1997a0*/
        *(_DWORD *)(a1 + 204) = v10; /*0x1997a6*/
        *(_DWORD *)(a1 + 208) = *(_DWORD *)(a1 + 200) * v10; /*0x1997b6*/
        v153 = *(char **)(a1 + 196); /*0x1997c2*/
        __outbyte(0x3CEu, 5u); /*0x1997cc*/
        _InterlockedIncrement(&dword_1E8654); /*0x1997cd*/
        v11 = __inbyte(0x3CFu); /*0x1997d9*/
        __outbyte(0x3CEu, 5u); /*0x1997e6*/
        _InterlockedIncrement(&dword_1E8654); /*0x1997e7*/
        __outbyte(0x3CFu, v11 & 0xF7); /*0x1997f5*/
        _InterlockedIncrement(&dword_1E8654); /*0x1997f6*/
        __outbyte(0x3CEu, 4u); /*0x199804*/
        _InterlockedIncrement(&dword_1E8654); /*0x199805*/
        v12 = __inbyte(0x3CFu); /*0x199811*/
        __outbyte(0x3CEu, 4u); /*0x19981e*/
        _InterlockedIncrement(&dword_1E8654); /*0x19981f*/
        __outbyte(0x3CFu, v12 & 0xFC); /*0x19982d*/
        _InterlockedIncrement(&dword_1E8654); /*0x19982e*/
        v13 = (*(int *)(a1 + 140) >> 3) + *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16) * (*(_DWORD *)(a1 + 144) - 3) - 1; /*0x199854*/
        *(_DWORD *)(a1 + 212) = v13; /*0x199858*/
        v87 = (char *)v13; /*0x19985e*/
        v106 = *(_DWORD *)(a1 + 200); /*0x19986a*/
        if ( v106 ) /*0x199872*/
        {
          v14 = *(_DWORD *)(a1 + 204); /*0x199874*/
          v152 = *(_DWORD *)(a1 + 16); /*0x19987d*/
          do /*0x19989f*/
          {
            qmemcpy(v153, v87, v14); /*0x19988b*/
            v87 += v152; /*0x199890*/
            v153 += v14; /*0x199896*/
            --v106; /*0x199899*/
          }
          while ( v106 ); /*0x19989f*/
        }
        __outbyte(0x3CEu, 4u); /*0x1998a8*/
        _InterlockedIncrement(&dword_1E8654); /*0x1998a9*/
        v15 = __inbyte(0x3CFu); /*0x1998b5*/
        __outbyte(0x3CEu, 4u); /*0x1998c5*/
        _InterlockedIncrement(&dword_1E8654); /*0x1998c6*/
        __outbyte(0x3CFu, v15 & 0xFC | 1); /*0x1998d4*/
        _InterlockedIncrement(&dword_1E8654); /*0x1998d5*/
        v16 = (*(int *)(a1 + 140) >> 3) + *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16) * (*(_DWORD *)(a1 + 144) - 3) - 1; /*0x1998fb*/
        *(_DWORD *)(a1 + 212) = v16; /*0x1998ff*/
        v88 = (char *)v16; /*0x199905*/
        v107 = *(_DWORD *)(a1 + 200); /*0x199911*/
        if ( v107 ) /*0x199919*/
        {
          v17 = *(_DWORD *)(a1 + 204); /*0x19991b*/
          v151 = *(_DWORD *)(a1 + 16); /*0x199924*/
          do /*0x199947*/
          {
            qmemcpy(v153, v88, v17); /*0x199933*/
            v88 += v151; /*0x199938*/
            v153 += v17; /*0x19993e*/
            --v107; /*0x199941*/
          }
          while ( v107 ); /*0x199947*/
        }
        __outbyte(0x3CEu, 5u); /*0x199954*/
        _InterlockedIncrement(&dword_1E8654); /*0x199955*/
        v18 = __inbyte(0x3CFu); /*0x199961*/
        __outbyte(0x3CEu, 5u); /*0x19996e*/
        _InterlockedIncrement(&dword_1E8654); /*0x19996f*/
        __outbyte(0x3CFu, v18 & 0xFC); /*0x19997d*/
        _InterlockedIncrement(&dword_1E8654); /*0x19997e*/
        for ( k = 0; k <= 8; ++k ) /*0x19998e*/
        {
          v70 = *(_BYTE *)(k + a1 + 230); /*0x1999a7*/
          __outbyte(0x3CEu, k); /*0x1999b4*/
          _InterlockedIncrement(&dword_1E8654); /*0x1999b5*/
          __outbyte(0x3CFu, v70); /*0x1999c7*/
          _InterlockedIncrement(&dword_1E8654); /*0x1999c8*/
        }
        v19 = *(_BYTE *)(a1 + 241); /*0x1999de*/
        __outbyte(0x3C4u, 2u); /*0x1999e8*/
        _InterlockedIncrement(&dword_1E8654); /*0x1999e9*/
        v20 = 965; /*0x1999f0*/
      }
      else
      {
        *(_DWORD *)(a1 + 200) = v156 + 6; /*0x199a05*/
        v21 = v155 / 8 + 2; /*0x199a1a*/
        *(_DWORD *)(a1 + 204) = v21; /*0x199a20*/
        *(_DWORD *)(a1 + 208) = *(_DWORD *)(a1 + 200) * v21; /*0x199a30*/
        v154 = *(char **)(a1 + 196); /*0x199a3c*/
        v22 = (*(int *)(a1 + 140) >> 3) + *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16) * (*(_DWORD *)(a1 + 144) - 3) - 1; /*0x199a58*/
        *(_DWORD *)(a1 + 212) = v22; /*0x199a5c*/
        v89 = (char *)v22; /*0x199a62*/
        __outbyte(0x3CEu, 5u); /*0x199a6f*/
        _InterlockedIncrement(&dword_1E8654); /*0x199a70*/
        v23 = __inbyte(0x3CFu); /*0x199a7c*/
        __outbyte(0x3CEu, 5u); /*0x199a8c*/
        _InterlockedIncrement(&dword_1E8654); /*0x199a8d*/
        __outbyte(0x3CFu, v23 & 0xFC | 1); /*0x199a9b*/
        _InterlockedIncrement(&dword_1E8654); /*0x199a9c*/
        v108 = *(_DWORD *)(a1 + 200); /*0x199aac*/
        if ( v108 ) /*0x199ab4*/
        {
          v24 = *(_DWORD *)(a1 + 204); /*0x199ab9*/
          v150 = *(_DWORD *)(a1 + 16); /*0x199ac2*/
          do /*0x199ae7*/
          {
            qmemcpy(v154, v89, v24); /*0x199ad3*/
            v89 += v150; /*0x199ad8*/
            v154 += v24; /*0x199ade*/
            --v108; /*0x199ae1*/
          }
          while ( v108 ); /*0x199ae7*/
        }
        __outbyte(0x3CEu, 5u); /*0x199af0*/
        _InterlockedIncrement(&dword_1E8654); /*0x199af1*/
        v25 = __inbyte(0x3CFu); /*0x199afd*/
        v19 = v25 & 0xFC; /*0x199b00*/
        __outbyte(0x3CEu, 5u); /*0x199b0a*/
        _InterlockedIncrement(&dword_1E8654); /*0x199b0b*/
        v20 = 975; /*0x199b12*/
      }
      __outbyte(v20, v19); /*0x199b19*/
      _InterlockedIncrement(&dword_1E8654); /*0x199b1a*/
    }
    *(_DWORD *)(a1 + 164) = 0; /*0x199b24*/
    *(_DWORD *)(a1 + 192) = 0; /*0x199b2e*/
    v109 = *(_DWORD *)(a1 + 140) - 3; /*0x199b4a*/
    v26 = *(_DWORD *)(a1 + 144) - 3; /*0x199b56*/
    v90 = v109 + v155 + 6; /*0x199b60*/
    v149 = *(_DWORD *)(a1 + 16); /*0x199b69*/
    v86 = *(_BYTE *)(a1 + 180); /*0x199b72*/
    __outbyte(0x3CEu, 0); /*0x199b7f*/
    _InterlockedIncrement(&dword_1E8654); /*0x199b80*/
    __outbyte(0x3CFu, v86); /*0x199b92*/
    _InterlockedIncrement(&dword_1E8654); /*0x199b93*/
    __outbyte(0x3CEu, 8u); /*0x199ba1*/
    _InterlockedIncrement(&dword_1E8654); /*0x199ba2*/
    v148 = byte_1E4685[v109 & 7]; /*0x199bca*/
    v147 = byte_1E468D[v90 & 7]; /*0x199bdc*/
    v27 = (_BYTE *)((v109 >> 3) + *(_DWORD *)(a1 + 24) + v149 * v26); /*0x199be9*/
    v71 = (v90 >> 3) - (v109 >> 3) - 1; /*0x199bf4*/
    if ( v90 >> 3 == v109 >> 3 ) /*0x199bfd*/
    {
      __outbyte(0x3CFu, v148 & byte_1E468D[v90 & 7]); /*0x199c09*/
      _InterlockedIncrement(&dword_1E8654); /*0x199c0a*/
      for ( m = 0; m >= 0; --m ) /*0x199c11*/
      {
        *v27 = -1; /*0x199c27*/
        v27 += v149; /*0x199c2a*/
      }
    }
    else
    {
      for ( n = 0; n >= 0; --n ) /*0x199c3c*/
      {
        __outbyte(0x3CFu, v148); /*0x199c5b*/
        _InterlockedIncrement(&dword_1E8654); /*0x199c5c*/
        *v27 = -1; /*0x199c63*/
        v91 = v27 + 1; /*0x199c69*/
        __outbyte(0x3CFu, 0xFFu); /*0x199c71*/
        _InterlockedIncrement(&dword_1E8654); /*0x199c72*/
        for ( ii = v71 - 1; ii >= 0; --ii ) /*0x199c86*/
          *v91++ = -1; /*0x199c8e*/
        __outbyte(0x3CFu, v147); /*0x199ca8*/
        _InterlockedIncrement(&dword_1E8654); /*0x199ca9*/
        *v91 = -1; /*0x199cc7*/
        v27 += v149; /*0x199cca*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x199ce0*/
    _InterlockedIncrement(&dword_1E8654); /*0x199ce1*/
    v111 = *(_DWORD *)(a1 + 140) - 2; /*0x199cfd*/
    v28 = *(_DWORD *)(a1 + 144) - 2; /*0x199d0c*/
    v92 = v111 + v155 + 4; /*0x199d16*/
    v146 = *(_DWORD *)(a1 + 16); /*0x199d1f*/
    v72 = *(_BYTE *)(a1 + 176); /*0x199d28*/
    __outbyte(0x3CEu, 0); /*0x199d35*/
    _InterlockedIncrement(&dword_1E8654); /*0x199d36*/
    __outbyte(0x3CFu, v72); /*0x199d48*/
    _InterlockedIncrement(&dword_1E8654); /*0x199d49*/
    __outbyte(0x3CEu, 8u); /*0x199d57*/
    _InterlockedIncrement(&dword_1E8654); /*0x199d58*/
    v145 = byte_1E4685[v111 & 7]; /*0x199d86*/
    v144 = byte_1E468D[v92 & 7]; /*0x199d98*/
    v29 = (_BYTE *)((v111 >> 3) + *(_DWORD *)(a1 + 24) + v146 * v28); /*0x199da2*/
    v73 = (v92 >> 3) - (v111 >> 3) - 1; /*0x199db5*/
    if ( v92 >> 3 == v111 >> 3 ) /*0x199dbe*/
    {
      __outbyte(0x3CFu, v145 & byte_1E468D[v92 & 7]); /*0x199dca*/
      _InterlockedIncrement(&dword_1E8654); /*0x199dcb*/
      for ( jj = 1; jj >= 0; --jj ) /*0x199dd2*/
      {
        *v29 = -1; /*0x199de7*/
        v29 += v146; /*0x199dea*/
      }
    }
    else
    {
      for ( kk = 1; kk >= 0; --kk ) /*0x199dfc*/
      {
        __outbyte(0x3CFu, v145); /*0x199e1b*/
        _InterlockedIncrement(&dword_1E8654); /*0x199e1c*/
        *v29 = -1; /*0x199e23*/
        v93 = v29 + 1; /*0x199e29*/
        __outbyte(0x3CFu, 0xFFu); /*0x199e31*/
        _InterlockedIncrement(&dword_1E8654); /*0x199e32*/
        for ( mm = v73 - 1; mm >= 0; --mm ) /*0x199e46*/
          *v93++ = -1; /*0x199e4e*/
        __outbyte(0x3CFu, v144); /*0x199e68*/
        _InterlockedIncrement(&dword_1E8654); /*0x199e69*/
        *v93 = -1; /*0x199e87*/
        v29 += v146; /*0x199e8a*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x199ea0*/
    _InterlockedIncrement(&dword_1E8654); /*0x199ea1*/
    v113 = *(_DWORD *)(a1 + 140) - 2; /*0x199ebd*/
    v30 = *(_DWORD *)(a1 + 144) + v156; /*0x199ec9*/
    v94 = v113 + v155 + 4; /*0x199ed6*/
    v143 = *(_DWORD *)(a1 + 16); /*0x199edf*/
    v74 = *(_BYTE *)(a1 + 176); /*0x199ee8*/
    __outbyte(0x3CEu, 0); /*0x199ef5*/
    _InterlockedIncrement(&dword_1E8654); /*0x199ef6*/
    __outbyte(0x3CFu, v74); /*0x199f08*/
    _InterlockedIncrement(&dword_1E8654); /*0x199f09*/
    __outbyte(0x3CEu, 8u); /*0x199f17*/
    _InterlockedIncrement(&dword_1E8654); /*0x199f18*/
    v142 = byte_1E4685[v113 & 7]; /*0x199f46*/
    v141 = byte_1E468D[v94 & 7]; /*0x199f58*/
    v31 = (_BYTE *)((v113 >> 3) + *(_DWORD *)(a1 + 24) + v143 * v30); /*0x199f62*/
    v75 = (v94 >> 3) - (v113 >> 3) - 1; /*0x199f75*/
    if ( v94 >> 3 == v113 >> 3 ) /*0x199f7e*/
    {
      __outbyte(0x3CFu, v142 & byte_1E468D[v94 & 7]); /*0x199f8a*/
      _InterlockedIncrement(&dword_1E8654); /*0x199f8b*/
      for ( nn = 1; nn >= 0; --nn ) /*0x199f92*/
      {
        *v31 = -1; /*0x199fa7*/
        v31 += v143; /*0x199faa*/
      }
    }
    else
    {
      for ( i1 = 1; i1 >= 0; --i1 ) /*0x199fbc*/
      {
        __outbyte(0x3CFu, v142); /*0x199fdb*/
        _InterlockedIncrement(&dword_1E8654); /*0x199fdc*/
        *v31 = -1; /*0x199fe3*/
        v95 = v31 + 1; /*0x199fe9*/
        __outbyte(0x3CFu, 0xFFu); /*0x199ff1*/
        _InterlockedIncrement(&dword_1E8654); /*0x199ff2*/
        for ( i2 = v75 - 1; i2 >= 0; --i2 ) /*0x19a006*/
          *v95++ = -1; /*0x19a00e*/
        __outbyte(0x3CFu, v141); /*0x19a028*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a029*/
        *v95 = -1; /*0x19a047*/
        v31 += v143; /*0x19a04a*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a060*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a061*/
    v96 = *(_DWORD *)(a1 + 140) - 3; /*0x19a07a*/
    v115 = *(_DWORD *)(a1 + 144) + v156 + 2; /*0x19a08f*/
    v76 = v96 + v155 + 6; /*0x19a09c*/
    v49 = *(_DWORD *)(a1 + 16); /*0x19a0a5*/
    v32 = *(_BYTE *)(a1 + 180); /*0x19a0ab*/
    __outbyte(0x3CEu, 0); /*0x19a0b8*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a0b9*/
    __outbyte(0x3CFu, v32); /*0x19a0c7*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a0c8*/
    __outbyte(0x3CEu, 8u); /*0x19a0d6*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a0d7*/
    v140 = byte_1E4685[v96 & 7]; /*0x19a0ff*/
    v139 = byte_1E468D[v76 & 7]; /*0x19a111*/
    v116 = (_BYTE *)((v96 >> 3) + *(_DWORD *)(a1 + 24) + v49 * v115); /*0x19a12a*/
    v33 = (v76 >> 3) - (v96 >> 3) - 1; /*0x19a136*/
    if ( v76 >> 3 == v96 >> 3 ) /*0x19a13a*/
    {
      __outbyte(0x3CFu, byte_1E4685[v96 & 7] & v139); /*0x19a148*/
      _InterlockedIncrement(&dword_1E8654); /*0x19a149*/
      for ( i3 = 0; i3 >= 0; --i3 ) /*0x19a150*/
      {
        *v116 = -1; /*0x19a170*/
        v116 += v49; /*0x19a17b*/
      }
    }
    else
    {
      for ( i4 = 0; i4 >= 0; --i4 ) /*0x19a190*/
      {
        __outbyte(0x3CFu, v140); /*0x19a1b2*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a1b3*/
        *v116 = -1; /*0x19a1c0*/
        v77 = v116 + 1; /*0x19a1c4*/
        __outbyte(0x3CFu, 0xFFu); /*0x19a1cc*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a1cd*/
        for ( i5 = v33 - 1; i5 >= 0; --i5 ) /*0x19a1df*/
          *v77++ = -1; /*0x19a1ea*/
        __outbyte(0x3CFu, v139); /*0x19a204*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a205*/
        *v77 = -1; /*0x19a220*/
        v116 += v49; /*0x19a229*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a242*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a243*/
    v47 = *(_DWORD *)(a1 + 140); /*0x19a25c*/
    v34 = *(_DWORD *)(a1 + 144) - 3; /*0x19a274*/
    v138 = *(_DWORD *)(a1 + 16); /*0x19a289*/
    v78 = *(_BYTE *)(a1 + 180); /*0x19a292*/
    __outbyte(0x3CEu, 0); /*0x19a29f*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a2a0*/
    __outbyte(0x3CFu, v78); /*0x19a2b2*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a2b3*/
    __outbyte(0x3CEu, 8u); /*0x19a2c1*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a2c2*/
    v137 = byte_1E4685[((_BYTE)v47 - 3) & 7]; /*0x19a2f0*/
    v136 = byte_1E468D[((_BYTE)v47 - 2) & 7]; /*0x19a302*/
    v35 = (_BYTE *)(((v47 - 3) >> 3) + *(_DWORD *)(a1 + 24) + v138 * v34); /*0x19a30c*/
    if ( (v47 - 2) >> 3 == (v47 - 3) >> 3 ) /*0x19a328*/
    {
      __outbyte(0x3CFu, byte_1E4685[((_BYTE)v47 - 3) & 7] & byte_1E468D[((_BYTE)v47 - 2) & 7]); /*0x19a333*/
      _InterlockedIncrement(&dword_1E8654); /*0x19a334*/
      for ( i6 = v156 + 5; i6 >= 0; --i6 ) /*0x19a347*/
      {
        *v35 = -1; /*0x19a35b*/
        v35 += v138; /*0x19a35e*/
      }
    }
    else
    {
      for ( i7 = v156 + 5; i7 >= 0; --i7 ) /*0x19a37c*/
      {
        __outbyte(0x3CFu, v137); /*0x19a397*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a398*/
        *v35 = -1; /*0x19a39f*/
        v98 = v35 + 1; /*0x19a3a5*/
        __outbyte(0x3CFu, 0xFFu); /*0x19a3ad*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a3ae*/
        for ( i8 = ((v47 - 2) >> 3) - ((v47 - 3) >> 3) - 2; i8 >= 0; --i8 ) /*0x19a3c2*/
          *v98++ = -1; /*0x19a3ca*/
        __outbyte(0x3CFu, v136); /*0x19a3e4*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a3e5*/
        *v98 = -1; /*0x19a403*/
        v35 += v138; /*0x19a406*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a41c*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a41d*/
    v46 = *(_DWORD *)(a1 + 140); /*0x19a436*/
    v36 = *(_DWORD *)(a1 + 144) - 2; /*0x19a44e*/
    v135 = *(_DWORD *)(a1 + 16); /*0x19a454*/
    v79 = *(_BYTE *)(a1 + 176); /*0x19a45d*/
    __outbyte(0x3CEu, 0); /*0x19a46a*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a46b*/
    __outbyte(0x3CFu, v79); /*0x19a47d*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a47e*/
    __outbyte(0x3CEu, 8u); /*0x19a48c*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a48d*/
    v134 = byte_1E4685[((_BYTE)v46 - 2) & 7]; /*0x19a4bb*/
    v133 = byte_1E468D[v46 & 7]; /*0x19a4cd*/
    v37 = (_BYTE *)(((v46 - 2) >> 3) + *(_DWORD *)(a1 + 24) + v135 * v36); /*0x19a4d7*/
    if ( v46 >> 3 == (v46 - 2) >> 3 ) /*0x19a4f3*/
    {
      __outbyte(0x3CFu, byte_1E4685[((_BYTE)v46 - 2) & 7] & byte_1E468D[v46 & 7]); /*0x19a4fe*/
      _InterlockedIncrement(&dword_1E8654); /*0x19a4ff*/
      for ( i9 = v156 + 3; i9 >= 0; --i9 ) /*0x19a512*/
      {
        *v37 = -1; /*0x19a523*/
        v37 += v135; /*0x19a526*/
      }
    }
    else
    {
      for ( i10 = v156 + 3; i10 >= 0; --i10 ) /*0x19a544*/
      {
        __outbyte(0x3CFu, v134); /*0x19a55f*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a560*/
        *v37 = -1; /*0x19a567*/
        v99 = v37 + 1; /*0x19a56d*/
        __outbyte(0x3CFu, 0xFFu); /*0x19a575*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a576*/
        for ( i11 = (v46 >> 3) - ((v46 - 2) >> 3) - 2; i11 >= 0; --i11 ) /*0x19a58a*/
          *v99++ = -1; /*0x19a592*/
        __outbyte(0x3CFu, v133); /*0x19a5ac*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a5ad*/
        *v99 = -1; /*0x19a5cb*/
        v37 += v135; /*0x19a5ce*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a5e4*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a5e5*/
    v119 = *(_DWORD *)(a1 + 140) + v155; /*0x19a601*/
    v38 = *(_DWORD *)(a1 + 144) - 2; /*0x19a60d*/
    v132 = *(_DWORD *)(a1 + 16); /*0x19a61c*/
    v80 = *(_BYTE *)(a1 + 176); /*0x19a625*/
    __outbyte(0x3CEu, 0); /*0x19a632*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a633*/
    __outbyte(0x3CFu, v80); /*0x19a645*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a646*/
    __outbyte(0x3CEu, 8u); /*0x19a654*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a655*/
    v131 = byte_1E4685[v119 & 7]; /*0x19a67d*/
    v130 = byte_1E468D[((_BYTE)v119 + 2) & 7]; /*0x19a68f*/
    v39 = (_BYTE *)((v119 >> 3) + *(_DWORD *)(a1 + 24) + v132 * v38); /*0x19a69c*/
    v81 = ((v119 + 2) >> 3) - (v119 >> 3) - 1; /*0x19a6a9*/
    if ( (v119 + 2) >> 3 == v119 >> 3 ) /*0x19a6b2*/
    {
      __outbyte(0x3CFu, byte_1E4685[v119 & 7] & byte_1E468D[((_BYTE)v119 + 2) & 7]); /*0x19a6bd*/
      _InterlockedIncrement(&dword_1E8654); /*0x19a6be*/
      for ( i12 = v156 + 3; i12 >= 0; --i12 ) /*0x19a6d1*/
      {
        *v39 = -1; /*0x19a6e3*/
        v39 += v132; /*0x19a6e6*/
      }
    }
    else
    {
      for ( i13 = v156 + 3; i13 >= 0; --i13 ) /*0x19a704*/
      {
        __outbyte(0x3CFu, v131); /*0x19a71f*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a720*/
        *v39 = -1; /*0x19a727*/
        v100 = v39 + 1; /*0x19a72d*/
        __outbyte(0x3CFu, 0xFFu); /*0x19a735*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a736*/
        for ( i14 = v81 - 1; i14 >= 0; --i14 ) /*0x19a74a*/
          *v100++ = -1; /*0x19a752*/
        __outbyte(0x3CFu, v130); /*0x19a76c*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a76d*/
        *v100 = -1; /*0x19a78b*/
        v39 += v132; /*0x19a78e*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a7a4*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a7a5*/
    v121 = *(_DWORD *)(a1 + 140) + v155 + 2; /*0x19a7c4*/
    v40 = *(_DWORD *)(a1 + 144) - 3; /*0x19a7d0*/
    v101 = *(_DWORD *)(a1 + 140) + v155 + 3; /*0x19a7d4*/
    v129 = *(_DWORD *)(a1 + 16); /*0x19a7dd*/
    v82 = *(_BYTE *)(a1 + 180); /*0x19a7e6*/
    __outbyte(0x3CEu, 0); /*0x19a7f3*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a7f4*/
    __outbyte(0x3CFu, v82); /*0x19a806*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a807*/
    __outbyte(0x3CEu, 8u); /*0x19a815*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a816*/
    v128 = byte_1E4685[v121 & 7]; /*0x19a83e*/
    v127 = byte_1E468D[v101 & 7]; /*0x19a850*/
    v41 = (_BYTE *)((v121 >> 3) + *(_DWORD *)(a1 + 24) + v129 * v40); /*0x19a85d*/
    v83 = (v101 >> 3) - (v121 >> 3) - 1; /*0x19a86a*/
    if ( v101 >> 3 == v121 >> 3 ) /*0x19a873*/
    {
      __outbyte(0x3CFu, byte_1E4685[v121 & 7] & byte_1E468D[v101 & 7]); /*0x19a87e*/
      _InterlockedIncrement(&dword_1E8654); /*0x19a87f*/
      for ( i15 = v156 + 5; i15 >= 0; --i15 ) /*0x19a892*/
      {
        *v41 = -1; /*0x19a8a3*/
        v41 += v129; /*0x19a8a6*/
      }
    }
    else
    {
      for ( i16 = v156 + 5; i16 >= 0; --i16 ) /*0x19a8c4*/
      {
        __outbyte(0x3CFu, v128); /*0x19a8df*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a8e0*/
        *v41 = -1; /*0x19a8e7*/
        v67 = v41 + 1; /*0x19a8ed*/
        __outbyte(0x3CFu, 0xFFu); /*0x19a8f5*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a8f6*/
        for ( i17 = v83 - 1; i17 >= 0; --i17 ) /*0x19a90a*/
          *v67++ = -1; /*0x19a912*/
        __outbyte(0x3CFu, v127); /*0x19a92c*/
        _InterlockedIncrement(&dword_1E8654); /*0x19a92d*/
        *v67 = -1; /*0x19a94b*/
        v41 += v129; /*0x19a94e*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19a964*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a965*/
    v45 = *(_DWORD *)(a1 + 140); /*0x19a97e*/
    v42 = *(_DWORD *)(a1 + 144); /*0x19a987*/
    v50 = *(_DWORD *)(a1 + 160); /*0x19a993*/
    v103 = *(_DWORD *)(a1 + 152) + v45; /*0x19a99f*/
    v126 = *(_DWORD *)(a1 + 16); /*0x19a9a8*/
    v84 = *(_BYTE *)(a1 + 176); /*0x19a9b1*/
    __outbyte(0x3CEu, 0); /*0x19a9be*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a9bf*/
    __outbyte(0x3CFu, v84); /*0x19a9d1*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a9d2*/
    __outbyte(0x3CEu, 8u); /*0x19a9e0*/
    _InterlockedIncrement(&dword_1E8654); /*0x19a9e1*/
    v125 = byte_1E4685[v45 & 7]; /*0x19aa0f*/
    v124 = byte_1E468D[v103 & 7]; /*0x19aa21*/
    v43 = (_BYTE *)((v45 >> 3) + *(_DWORD *)(a1 + 24) + v126 * v42); /*0x19aa2e*/
    v85 = (v103 >> 3) - (v45 >> 3) - 1; /*0x19aa41*/
    if ( v103 >> 3 == v45 >> 3 ) /*0x19aa4a*/
    {
      __outbyte(0x3CFu, v125 & byte_1E468D[v103 & 7]); /*0x19aa56*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aa57*/
      for ( i18 = v50 - 1; i18 >= 0; --i18 ) /*0x19aa64*/
      {
        *v43 = -1; /*0x19aa77*/
        v43 += v126; /*0x19aa7a*/
      }
    }
    else
    {
      for ( i19 = v50 - 1; i19 >= 0; --i19 ) /*0x19aa92*/
      {
        __outbyte(0x3CFu, v125); /*0x19aaab*/
        _InterlockedIncrement(&dword_1E8654); /*0x19aaac*/
        *v43 = -1; /*0x19aab3*/
        v104 = v43 + 1; /*0x19aab9*/
        __outbyte(0x3CFu, 0xFFu); /*0x19aac1*/
        _InterlockedIncrement(&dword_1E8654); /*0x19aac2*/
        for ( i20 = v85 - 1; i20 >= 0; --i20 ) /*0x19aad6*/
          *v104++ = -1; /*0x19aade*/
        __outbyte(0x3CFu, v124); /*0x19aafb*/
        _InterlockedIncrement(&dword_1E8654); /*0x19aafc*/
        *v104 = -1; /*0x19ab1a*/
        v43 += v126; /*0x19ab1d*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19ab33*/
    _InterlockedIncrement(&dword_1E8654); /*0x19ab34*/
    sub_197CA0(a1); /*0x19ab3f*/
    return sub_198ADC(a1, a4); /*0x19ab4c*/
  }
  else
  {
    *(_DWORD *)(a1 + 164) = *(_DWORD *)(a1 + 156) - 1; /*0x19ab5e*/
    sub_198ADC(a1, a4); /*0x19ab69*/
    return sub_198098(a1, 10); /*0x19ab74*/
  }
}
