/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19d254. */
void __cdecl sub_19D254(_DWORD *a1, int a2, int a3, const char *a4, int a5, int a6)
{
  int v6; // esi
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // eax
  int v10; // eax
  int v11; // esi
  unsigned int v12; // edx
  int v13; // ebx
  char *v14; // esi
  int i; // ebx
  int v16; // esi
  int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // edx
  _BYTE *v20; // edx
  _WORD *v21; // edx
  _DWORD *v22; // edx
  int v23; // esi
  int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  _BYTE *v27; // edx
  _WORD *v28; // edx
  _DWORD *v29; // edx
  int v30; // esi
  int v31; // ebx
  unsigned int v32; // edx
  unsigned int v33; // edx
  _BYTE *v34; // edx
  _WORD *v35; // edx
  _DWORD *v36; // edx
  int v37; // esi
  int v38; // ebx
  unsigned int v39; // edx
  unsigned int v40; // edx
  _BYTE *v41; // edx
  _WORD *v42; // edx
  _DWORD *v43; // edx
  int v44; // esi
  int v45; // ebx
  unsigned int v46; // edx
  unsigned int v47; // edx
  _BYTE *v48; // edx
  _WORD *v49; // edx
  _DWORD *v50; // edx
  int v51; // esi
  int v52; // ebx
  unsigned int v53; // edx
  unsigned int v54; // edx
  _BYTE *v55; // edx
  _WORD *v56; // edx
  _DWORD *v57; // edx
  int v58; // esi
  int v59; // ebx
  unsigned int v60; // edx
  unsigned int v61; // edx
  _BYTE *v62; // edx
  _WORD *v63; // edx
  _DWORD *v64; // edx
  int v65; // ebx
  int v66; // esi
  unsigned int v67; // edx
  unsigned int v68; // edx
  _BYTE *v69; // edx
  _WORD *v70; // edx
  _DWORD *v71; // edx
  int v72; // esi
  int v73; // ebx
  unsigned int v74; // edx
  int i8; // ebx
  int v76; // esi
  unsigned int v77; // edx
  _BYTE *v78; // edx
  int i11; // esi
  _WORD *v80; // edx
  int i10; // esi
  _DWORD *v82; // edx
  int i9; // esi
  int v84; // [esp+Ch] [ebp-80h]
  int v85; // [esp+Ch] [ebp-80h]
  int v86; // [esp+Ch] [ebp-80h]
  int v87; // [esp+Ch] [ebp-80h]
  int v88; // [esp+Ch] [ebp-80h]
  int v89; // [esp+Ch] [ebp-80h]
  int v90; // [esp+Ch] [ebp-80h]
  int v91; // [esp+Ch] [ebp-80h]
  int v92; // [esp+Ch] [ebp-80h]
  int v93; // [esp+Ch] [ebp-80h]
  int v94; // [esp+Ch] [ebp-80h]
  int v95; // [esp+Ch] [ebp-80h]
  int v96; // [esp+Ch] [ebp-80h]
  int v97; // [esp+Ch] [ebp-80h]
  int v98; // [esp+Ch] [ebp-80h]
  int v99; // [esp+Ch] [ebp-80h]
  int v100; // [esp+Ch] [ebp-80h]
  int v101; // [esp+Ch] [ebp-80h]
  int kk; // [esp+Ch] [ebp-80h]
  int jj; // [esp+Ch] [ebp-80h]
  int ii; // [esp+Ch] [ebp-80h]
  int v105; // [esp+Ch] [ebp-80h]
  int i1; // [esp+Ch] [ebp-80h]
  int nn; // [esp+Ch] [ebp-80h]
  int mm; // [esp+Ch] [ebp-80h]
  int v109; // [esp+Ch] [ebp-80h]
  int i4; // [esp+Ch] [ebp-80h]
  int i3; // [esp+Ch] [ebp-80h]
  int i2; // [esp+Ch] [ebp-80h]
  int v113; // [esp+Ch] [ebp-80h]
  int v114; // [esp+Ch] [ebp-80h]
  int v115; // [esp+10h] [ebp-7Ch]
  int v116; // [esp+10h] [ebp-7Ch]
  int i7; // [esp+10h] [ebp-7Ch]
  int i6; // [esp+10h] [ebp-7Ch]
  int i5; // [esp+10h] [ebp-7Ch]
  int v120; // [esp+18h] [ebp-74h]
  int v121; // [esp+1Ch] [ebp-70h]
  int v122; // [esp+20h] [ebp-6Ch]
  int v123; // [esp+24h] [ebp-68h]
  int v124; // [esp+28h] [ebp-64h]
  int v125; // [esp+2Ch] [ebp-60h]
  int v126; // [esp+30h] [ebp-5Ch]
  int v127; // [esp+34h] [ebp-58h]
  int v128; // [esp+38h] [ebp-54h]
  int v129; // [esp+3Ch] [ebp-50h]
  int v130; // [esp+40h] [ebp-4Ch]
  int v131; // [esp+44h] [ebp-48h]
  int v132; // [esp+48h] [ebp-44h]
  int n; // [esp+4Ch] [ebp-40h]
  int v134; // [esp+54h] [ebp-38h]
  int v135; // [esp+58h] [ebp-34h]
  int m; // [esp+5Ch] [ebp-30h]
  int v137; // [esp+64h] [ebp-28h]
  int v138; // [esp+68h] [ebp-24h]
  int k; // [esp+6Ch] [ebp-20h]
  int v140; // [esp+74h] [ebp-18h]
  int v141; // [esp+78h] [ebp-14h]
  int j; // [esp+7Ch] [ebp-10h]
  int v143; // [esp+84h] [ebp-8h]
  char *__dst; // [esp+88h] [ebp-4h]
  signed int v145; // [esp+98h] [ebp+Ch]
  int v146; // [esp+9Ch] [ebp+10h]

  v145 = (a2 + (a2 < 0 ? 7 : 0)) & 0xFFFFFFF8;
  v146 = 12 * (a3 / 12); /*0x19d28b*/
  v6 = a1[1]; /*0x19d28e*/
  if ( v145 > v6 - 6 ) /*0x19d297*/
    v145 = v6 - 6; /*0x19d299*/
  if ( v146 > a1[2] - 6 ) /*0x19d2a5*/
    v146 = a1[2] - 6; /*0x19d2a7*/
  a1[35] = (v6 - v145) / 2; /*0x19d2bb*/
  a1[36] = (a1[2] - v146) / 2; /*0x19d2d2*/
  a1[38] = v145; /*0x19d2db*/
  a1[40] = v146; /*0x19d2e4*/
  a1[35] &= 0xFFFFFFF8; /*0x19d2ea*/
  a1[37] = a1[38] / 8; /*0x19d301*/
  a1[39] = a1[40] / 12; /*0x19d319*/
  a1[42] = 0; /*0x19d31f*/
  a1[48] = 0; /*0x19d329*/
  if ( a5 ) /*0x19d337*/
  {
    if ( a6 ) /*0x19d341*/
    {
      v7 = 0; /*0x19d347*/
      v8 = a1[7]; /*0x19d349*/
      if ( v8 > 3 ) /*0x19d34f*/
      {
        if ( v8 == 4 ) /*0x19d363*/
          v7 = 4; /*0x19d378*/
      }
      else if ( v8 >= 2 ) /*0x19d354*/
      {
        v7 = 2; /*0x19d370*/
      }
      else if ( v8 == 1 ) /*0x19d359*/
      {
        v7 = 1; /*0x19d368*/
      }
      a1[50] = v146 + 6; /*0x19d383*/
      v115 = (v145 + 6) * v7; /*0x19d392*/
      a1[51] = v115; /*0x19d395*/
      v9 = a1[50] * v115; /*0x19d39e*/
      a1[52] = v9; /*0x19d3a5*/
      v10 = IOMalloc(v9); /*0x19d3ac*/
      a1[49] = v10; /*0x19d3b3*/
      __dst = (char *)v10; /*0x19d3b9*/
      v84 = a1[35] - 3; /*0x19d3c5*/
      v11 = a1[36] - 3; /*0x19d3ce*/
      v12 = a1[7]; /*0x19d3d4*/
      if ( v12 > 3 ) /*0x19d3da*/
      {
        if ( v12 != 4 ) /*0x19d3eb*/
LABEL_25:
          panic(aFbconsolePixel); /*0x19d428*/
        v13 = a1[6] + a1[4] * v11 + 4 * v84; /*0x19d420*/
      }
      else if ( v12 >= 2 ) /*0x19d3df*/
      {
        v13 = a1[6] + a1[4] * v11 + 2 * v84; /*0x19d40c*/
      }
      else
      {
        if ( v12 != 1 ) /*0x19d3e4*/
          goto LABEL_25; /*0x19d3e4*/
        v13 = a1[6] + a1[4] * v11 + v84; /*0x19d3fc*/
      }
      a1[53] = v13; /*0x19d435*/
      v14 = (char *)v13; /*0x19d43b*/
      for ( i = a1[50]; i; --i ) /*0x19d445*/
      {
        memmove(__dst, v14, a1[51]); /*0x19d454*/
        v14 += a1[4]; /*0x19d459*/
        __dst += a1[51]; /*0x19d462*/
      }
    }
    a1[41] = 0; /*0x19d46b*/
    a1[48] = 0; /*0x19d475*/
    v16 = a1[35] - 3; /*0x19d485*/
    v143 = a1[36] - 3; /*0x19d491*/
    v17 = a1[45]; /*0x19d49d*/
    for ( j = 0; j != -1; --j ) /*0x19d4a3*/
    {
      v85 = v143++; /*0x19d4af*/
      v18 = a1[7]; /*0x19d4b8*/
      if ( v18 > 3 ) /*0x19d4be*/
      {
        if ( v18 != 4 ) /*0x19d4cf*/
LABEL_38:
          panic(aFbconsolePixel); /*0x19d510*/
        v141 = a1[6] + a1[4] * v85 + 4 * v16; /*0x19d509*/
      }
      else if ( v18 >= 2 ) /*0x19d4c3*/
      {
        v141 = a1[6] + a1[4] * v85 + 2 * v16; /*0x19d4f5*/
      }
      else
      {
        if ( v18 != 1 ) /*0x19d4c8*/
          goto LABEL_38; /*0x19d4c8*/
        v141 = v16 + a1[6] + a1[4] * v85; /*0x19d4e0*/
      }
      v19 = a1[7]; /*0x19d523*/
      if ( v19 > 3 ) /*0x19d529*/
      {
        if ( v19 != 4 ) /*0x19d53b*/
LABEL_54:
          panic(aFbconsoleFillB); /*0x19d598*/
        v22 = (_DWORD *)v141; /*0x19d57c*/
        v88 = v145 + 5; /*0x19d57f*/
        if ( v145 != -6 ) /*0x19d586*/
        {
          do /*0x19d594*/
          {
            *v22++ = v17; /*0x19d588*/
            --v88; /*0x19d58d*/
          }
          while ( v88 != -1 ); /*0x19d594*/
        }
      }
      else if ( v19 >= 2 ) /*0x19d52e*/
      {
        v21 = (_WORD *)v141; /*0x19d55c*/
        v87 = v145 + 5; /*0x19d55f*/
        if ( v145 != -6 ) /*0x19d566*/
        {
          do /*0x19d575*/
          {
            *v21++ = v17; /*0x19d568*/
            --v87; /*0x19d56e*/
          }
          while ( v87 != -1 ); /*0x19d575*/
        }
      }
      else
      {
        if ( v19 != 1 ) /*0x19d533*/
          goto LABEL_54; /*0x19d533*/
        v20 = (_BYTE *)v141; /*0x19d540*/
        v86 = v145 + 5; /*0x19d543*/
        if ( v145 != -6 ) /*0x19d54a*/
        {
          do /*0x19d556*/
          {
            *v20++ = v17; /*0x19d54c*/
            --v86; /*0x19d54f*/
          }
          while ( v86 != -1 ); /*0x19d556*/
        }
      }
    }
    v23 = a1[35] - 2; /*0x19d5b8*/
    v140 = a1[36] - 2; /*0x19d5c4*/
    v24 = a1[44]; /*0x19d5d0*/
    for ( k = 1; k != -1; --k ) /*0x19d5d6*/
    {
      v89 = v140++; /*0x19d5e3*/
      v25 = a1[7]; /*0x19d5ec*/
      if ( v25 > 3 ) /*0x19d5f2*/
      {
        if ( v25 != 4 ) /*0x19d603*/
LABEL_66:
          panic(aFbconsolePixel); /*0x19d644*/
        v138 = a1[6] + a1[4] * v89 + 4 * v23; /*0x19d63d*/
      }
      else if ( v25 >= 2 ) /*0x19d5f7*/
      {
        v138 = a1[6] + a1[4] * v89 + 2 * v23; /*0x19d629*/
      }
      else
      {
        if ( v25 != 1 ) /*0x19d5fc*/
          goto LABEL_66; /*0x19d5fc*/
        v138 = v23 + a1[6] + a1[4] * v89; /*0x19d614*/
      }
      v26 = a1[7]; /*0x19d657*/
      if ( v26 > 3 ) /*0x19d65d*/
      {
        if ( v26 != 4 ) /*0x19d66f*/
LABEL_82:
          panic(aFbconsoleFillB); /*0x19d6cc*/
        v29 = (_DWORD *)v138; /*0x19d6b0*/
        v92 = v145 + 3; /*0x19d6b3*/
        if ( v145 != -4 ) /*0x19d6ba*/
        {
          do /*0x19d6c8*/
          {
            *v29++ = v24; /*0x19d6bc*/
            --v92; /*0x19d6c1*/
          }
          while ( v92 != -1 ); /*0x19d6c8*/
        }
      }
      else if ( v26 >= 2 ) /*0x19d662*/
      {
        v28 = (_WORD *)v138; /*0x19d690*/
        v91 = v145 + 3; /*0x19d693*/
        if ( v145 != -4 ) /*0x19d69a*/
        {
          do /*0x19d6a9*/
          {
            *v28++ = v24; /*0x19d69c*/
            --v91; /*0x19d6a2*/
          }
          while ( v91 != -1 ); /*0x19d6a9*/
        }
      }
      else
      {
        if ( v26 != 1 ) /*0x19d667*/
          goto LABEL_82; /*0x19d667*/
        v27 = (_BYTE *)v138; /*0x19d674*/
        v90 = v145 + 3; /*0x19d677*/
        if ( v145 != -4 ) /*0x19d67e*/
        {
          do /*0x19d68a*/
          {
            *v27++ = v24; /*0x19d680*/
            --v90; /*0x19d683*/
          }
          while ( v90 != -1 ); /*0x19d68a*/
        }
      }
    }
    v30 = a1[35] - 2; /*0x19d6ec*/
    v137 = a1[36] + v146; /*0x19d6f8*/
    v31 = a1[44]; /*0x19d704*/
    for ( m = 1; m != -1; --m ) /*0x19d70a*/
    {
      v93 = v137++; /*0x19d717*/
      v32 = a1[7]; /*0x19d720*/
      if ( v32 > 3 ) /*0x19d726*/
      {
        if ( v32 != 4 ) /*0x19d737*/
LABEL_94:
          panic(aFbconsolePixel); /*0x19d778*/
        v135 = a1[6] + a1[4] * v93 + 4 * v30; /*0x19d771*/
      }
      else if ( v32 >= 2 ) /*0x19d72b*/
      {
        v135 = a1[6] + a1[4] * v93 + 2 * v30; /*0x19d75d*/
      }
      else
      {
        if ( v32 != 1 ) /*0x19d730*/
          goto LABEL_94; /*0x19d730*/
        v135 = v30 + a1[6] + a1[4] * v93; /*0x19d748*/
      }
      v33 = a1[7]; /*0x19d78b*/
      if ( v33 > 3 ) /*0x19d791*/
      {
        if ( v33 != 4 ) /*0x19d7a3*/
LABEL_110:
          panic(aFbconsoleFillB); /*0x19d800*/
        v36 = (_DWORD *)v135; /*0x19d7e4*/
        v96 = v145 + 3; /*0x19d7e7*/
        if ( v145 != -4 ) /*0x19d7ee*/
        {
          do /*0x19d7fc*/
          {
            *v36++ = v31; /*0x19d7f0*/
            --v96; /*0x19d7f5*/
          }
          while ( v96 != -1 ); /*0x19d7fc*/
        }
      }
      else if ( v33 >= 2 ) /*0x19d796*/
      {
        v35 = (_WORD *)v135; /*0x19d7c4*/
        v95 = v145 + 3; /*0x19d7c7*/
        if ( v145 != -4 ) /*0x19d7ce*/
        {
          do /*0x19d7dd*/
          {
            *v35++ = v31; /*0x19d7d0*/
            --v95; /*0x19d7d6*/
          }
          while ( v95 != -1 ); /*0x19d7dd*/
        }
      }
      else
      {
        if ( v33 != 1 ) /*0x19d79b*/
          goto LABEL_110; /*0x19d79b*/
        v34 = (_BYTE *)v135; /*0x19d7a8*/
        v94 = v145 + 3; /*0x19d7ab*/
        if ( v145 != -4 ) /*0x19d7b2*/
        {
          do /*0x19d7be*/
          {
            *v34++ = v31; /*0x19d7b4*/
            --v94; /*0x19d7b7*/
          }
          while ( v94 != -1 ); /*0x19d7be*/
        }
      }
    }
    v37 = a1[35] - 3; /*0x19d829*/
    v134 = a1[36] + v146 + 2; /*0x19d82f*/
    v38 = a1[45]; /*0x19d83b*/
    for ( n = 0; n != -1; --n ) /*0x19d841*/
    {
      v97 = v134++; /*0x19d84b*/
      v39 = a1[7]; /*0x19d854*/
      if ( v39 > 3 ) /*0x19d85a*/
      {
        if ( v39 != 4 ) /*0x19d86b*/
LABEL_122:
          panic(aFbconsolePixel); /*0x19d8ac*/
        v132 = a1[6] + a1[4] * v97 + 4 * v37; /*0x19d8a5*/
      }
      else if ( v39 >= 2 ) /*0x19d85f*/
      {
        v132 = a1[6] + a1[4] * v97 + 2 * v37; /*0x19d891*/
      }
      else
      {
        if ( v39 != 1 ) /*0x19d864*/
          goto LABEL_122; /*0x19d864*/
        v132 = v37 + a1[6] + a1[4] * v97; /*0x19d87c*/
      }
      v40 = a1[7]; /*0x19d8bf*/
      if ( v40 > 3 ) /*0x19d8c5*/
      {
        if ( v40 != 4 ) /*0x19d8d7*/
LABEL_138:
          panic(aFbconsoleFillB); /*0x19d934*/
        v43 = (_DWORD *)v132; /*0x19d918*/
        v100 = v145 + 5; /*0x19d91b*/
        if ( v145 != -6 ) /*0x19d922*/
        {
          do /*0x19d930*/
          {
            *v43++ = v38; /*0x19d924*/
            --v100; /*0x19d929*/
          }
          while ( v100 != -1 ); /*0x19d930*/
        }
      }
      else if ( v40 >= 2 ) /*0x19d8ca*/
      {
        v42 = (_WORD *)v132; /*0x19d8f8*/
        v99 = v145 + 5; /*0x19d8fb*/
        if ( v145 != -6 ) /*0x19d902*/
        {
          do /*0x19d911*/
          {
            *v42++ = v38; /*0x19d904*/
            --v99; /*0x19d90a*/
          }
          while ( v99 != -1 ); /*0x19d911*/
        }
      }
      else
      {
        if ( v40 != 1 ) /*0x19d8cf*/
          goto LABEL_138; /*0x19d8cf*/
        v41 = (_BYTE *)v132; /*0x19d8dc*/
        v98 = v145 + 5; /*0x19d8df*/
        if ( v145 != -6 ) /*0x19d8e6*/
        {
          do /*0x19d8f2*/
          {
            *v41++ = v38; /*0x19d8e8*/
            --v98; /*0x19d8eb*/
          }
          while ( v98 != -1 ); /*0x19d8f2*/
        }
      }
    }
    v44 = a1[35] - 3; /*0x19d954*/
    v131 = a1[36] - 3; /*0x19d960*/
    v45 = a1[45]; /*0x19d963*/
    v130 = v146 + 5; /*0x19d96f*/
    if ( v146 != -6 ) /*0x19d975*/
    {
      do /*0x19da78*/
      {
        v101 = v131++; /*0x19d97f*/
        v46 = a1[7]; /*0x19d988*/
        if ( v46 > 3 ) /*0x19d98e*/
        {
          if ( v46 != 4 ) /*0x19d99f*/
LABEL_150:
            panic(aFbconsolePixel); /*0x19d9e0*/
          v129 = a1[6] + a1[4] * v101 + 4 * v44; /*0x19d9d9*/
        }
        else if ( v46 >= 2 ) /*0x19d993*/
        {
          v129 = a1[6] + a1[4] * v101 + 2 * v44; /*0x19d9c5*/
        }
        else
        {
          if ( v46 != 1 ) /*0x19d998*/
            goto LABEL_150; /*0x19d998*/
          v129 = v44 + a1[6] + a1[4] * v101; /*0x19d9b0*/
        }
        v47 = a1[7]; /*0x19d9ed*/
        if ( v47 > 3 ) /*0x19d9f3*/
        {
          if ( v47 != 4 ) /*0x19da07*/
LABEL_166:
            panic(aFbconsoleFillB); /*0x19da64*/
          v50 = (_DWORD *)v129; /*0x19da48*/
          for ( ii = 0; ii != -1; --ii ) /*0x19da4b*/
            *v50++ = v45; /*0x19da54*/
        }
        else if ( v47 >= 2 ) /*0x19d9f8*/
        {
          v49 = (_WORD *)v129; /*0x19da28*/
          for ( jj = 0; jj != -1; --jj ) /*0x19da2b*/
            *v49++ = v45; /*0x19da34*/
        }
        else
        {
          if ( v47 != 1 ) /*0x19d9fd*/
            goto LABEL_166; /*0x19d9fd*/
          v48 = (_BYTE *)v129; /*0x19da0c*/
          for ( kk = 0; kk != -1; --kk ) /*0x19da0f*/
            *v48++ = v45; /*0x19da18*/
        }
        --v130; /*0x19da71*/
      }
      while ( v130 != -1 ); /*0x19da78*/
    }
    v51 = a1[35] - 2; /*0x19da84*/
    v128 = a1[36] - 2; /*0x19da90*/
    v52 = a1[44]; /*0x19da93*/
    v127 = v146 + 3; /*0x19da9f*/
    if ( v146 != -4 ) /*0x19daa5*/
    {
      do /*0x19dba8*/
      {
        v105 = v128++; /*0x19daaf*/
        v53 = a1[7]; /*0x19dab8*/
        if ( v53 > 3 ) /*0x19dabe*/
        {
          if ( v53 != 4 ) /*0x19dacf*/
LABEL_178:
            panic(aFbconsolePixel); /*0x19db10*/
          v126 = a1[6] + a1[4] * v105 + 4 * v51; /*0x19db09*/
        }
        else if ( v53 >= 2 ) /*0x19dac3*/
        {
          v126 = a1[6] + a1[4] * v105 + 2 * v51; /*0x19daf5*/
        }
        else
        {
          if ( v53 != 1 ) /*0x19dac8*/
            goto LABEL_178; /*0x19dac8*/
          v126 = v51 + a1[6] + a1[4] * v105; /*0x19dae0*/
        }
        v54 = a1[7]; /*0x19db1d*/
        if ( v54 > 3 ) /*0x19db23*/
        {
          if ( v54 != 4 ) /*0x19db37*/
LABEL_194:
            panic(aFbconsoleFillB); /*0x19db94*/
          v57 = (_DWORD *)v126; /*0x19db78*/
          for ( mm = 1; mm != -1; --mm ) /*0x19db7b*/
            *v57++ = v52; /*0x19db84*/
        }
        else if ( v54 >= 2 ) /*0x19db28*/
        {
          v56 = (_WORD *)v126; /*0x19db58*/
          for ( nn = 1; nn != -1; --nn ) /*0x19db5b*/
            *v56++ = v52; /*0x19db64*/
        }
        else
        {
          if ( v54 != 1 ) /*0x19db2d*/
            goto LABEL_194; /*0x19db2d*/
          v55 = (_BYTE *)v126; /*0x19db3c*/
          for ( i1 = 1; i1 != -1; --i1 ) /*0x19db3f*/
            *v55++ = v52; /*0x19db48*/
        }
        --v127; /*0x19dba1*/
      }
      while ( v127 != -1 ); /*0x19dba8*/
    }
    v58 = a1[35] + v145; /*0x19dbb1*/
    v125 = a1[36] - 2; /*0x19dbc0*/
    v59 = a1[44]; /*0x19dbc3*/
    v124 = v146 + 3; /*0x19dbcf*/
    if ( v146 != -4 ) /*0x19dbd5*/
    {
      do /*0x19dcd8*/
      {
        v109 = v125++; /*0x19dbdf*/
        v60 = a1[7]; /*0x19dbe8*/
        if ( v60 > 3 ) /*0x19dbee*/
        {
          if ( v60 != 4 ) /*0x19dbff*/
LABEL_206:
            panic(aFbconsolePixel); /*0x19dc40*/
          v123 = a1[6] + a1[4] * v109 + 4 * v58; /*0x19dc39*/
        }
        else if ( v60 >= 2 ) /*0x19dbf3*/
        {
          v123 = a1[6] + a1[4] * v109 + 2 * v58; /*0x19dc25*/
        }
        else
        {
          if ( v60 != 1 ) /*0x19dbf8*/
            goto LABEL_206; /*0x19dbf8*/
          v123 = v58 + a1[6] + a1[4] * v109; /*0x19dc10*/
        }
        v61 = a1[7]; /*0x19dc4d*/
        if ( v61 > 3 ) /*0x19dc53*/
        {
          if ( v61 != 4 ) /*0x19dc67*/
LABEL_222:
            panic(aFbconsoleFillB); /*0x19dcc4*/
          v64 = (_DWORD *)v123; /*0x19dca8*/
          for ( i2 = 1; i2 != -1; --i2 ) /*0x19dcab*/
            *v64++ = v59; /*0x19dcb4*/
        }
        else if ( v61 >= 2 ) /*0x19dc58*/
        {
          v63 = (_WORD *)v123; /*0x19dc88*/
          for ( i3 = 1; i3 != -1; --i3 ) /*0x19dc8b*/
            *v63++ = v59; /*0x19dc94*/
        }
        else
        {
          if ( v61 != 1 ) /*0x19dc5d*/
            goto LABEL_222; /*0x19dc5d*/
          v62 = (_BYTE *)v123; /*0x19dc6c*/
          for ( i4 = 1; i4 != -1; --i4 ) /*0x19dc6f*/
            *v62++ = v59; /*0x19dc78*/
        }
        --v124; /*0x19dcd1*/
      }
      while ( v124 != -1 ); /*0x19dcd8*/
    }
    v65 = a1[35] + v145 + 2; /*0x19dce7*/
    v122 = a1[36] - 3; /*0x19dcf3*/
    v113 = a1[45]; /*0x19dcfc*/
    v66 = v146 + 5; /*0x19dd02*/
    if ( v146 != -6 ) /*0x19dd08*/
    {
      do /*0x19de15*/
      {
        v116 = v122++; /*0x19dd13*/
        v67 = a1[7]; /*0x19dd1c*/
        if ( v67 > 3 ) /*0x19dd22*/
        {
          if ( v67 != 4 ) /*0x19dd33*/
LABEL_234:
            panic(aFbconsolePixel); /*0x19dd74*/
          v121 = a1[6] + a1[4] * v116 + 4 * v65; /*0x19dd6d*/
        }
        else if ( v67 >= 2 ) /*0x19dd27*/
        {
          v121 = a1[6] + a1[4] * v116 + 2 * v65; /*0x19dd59*/
        }
        else
        {
          if ( v67 != 1 ) /*0x19dd2c*/
            goto LABEL_234; /*0x19dd2c*/
          v121 = v65 + a1[6] + a1[4] * v116; /*0x19dd44*/
        }
        v68 = a1[7]; /*0x19dd81*/
        if ( v68 > 3 ) /*0x19dd87*/
        {
          if ( v68 != 4 ) /*0x19dd9b*/
LABEL_250:
            panic(aFbconsoleFillB); /*0x19de04*/
          v71 = (_DWORD *)v121; /*0x19dde4*/
          for ( i5 = 0; i5 != -1; --i5 ) /*0x19dde7*/
            *v71++ = v113; /*0x19ddf3*/
        }
        else if ( v68 >= 2 ) /*0x19dd8c*/
        {
          v70 = (_WORD *)v121; /*0x19ddc0*/
          for ( i6 = 0; i6 != -1; --i6 ) /*0x19ddc3*/
            *v70++ = v113; /*0x19ddd0*/
        }
        else
        {
          if ( v68 != 1 ) /*0x19dd91*/
            goto LABEL_250; /*0x19dd91*/
          v69 = (_BYTE *)v121; /*0x19dda0*/
          for ( i7 = 0; i7 != -1; --i7 ) /*0x19dda3*/
            *v69++ = v113; /*0x19ddaf*/
        }
        --v66; /*0x19de11*/
      }
      while ( v66 != -1 ); /*0x19de15*/
    }
    v72 = a1[35]; /*0x19de1b*/
    v73 = a1[36]; /*0x19de21*/
    v74 = a1[7]; /*0x19de27*/
    if ( v74 > 3 ) /*0x19de2d*/
    {
      if ( v74 != 4 ) /*0x19de3f*/
LABEL_261:
        panic(aFbconsolePixel); /*0x19de7c*/
      v120 = a1[6] + a1[4] * v73 + 4 * v72; /*0x19de74*/
    }
    else if ( v74 >= 2 ) /*0x19de32*/
    {
      v120 = a1[6] + a1[4] * v73 + 2 * v72; /*0x19de60*/
    }
    else
    {
      if ( v74 != 1 ) /*0x19de37*/
        goto LABEL_261; /*0x19de37*/
      v120 = v72 + a1[6] + a1[4] * v73; /*0x19de4f*/
    }
    for ( i8 = 0; a1[40] > i8; ++i8 ) /*0x19de91*/
    {
      v114 = a1[44]; /*0x19de9e*/
      v76 = a1[38]; /*0x19dea1*/
      v77 = a1[7]; /*0x19dea7*/
      if ( v77 > 3 ) /*0x19dead*/
      {
        if ( v77 != 4 ) /*0x19debf*/
LABEL_278:
          panic(aFbconsoleFillB); /*0x19df1c*/
        v82 = (_DWORD *)v120; /*0x19df00*/
        for ( i9 = v76 - 1; i9 != -1; --i9 ) /*0x19df07*/
          *v82++ = v114; /*0x19df0f*/
      }
      else if ( v77 >= 2 ) /*0x19deb2*/
      {
        v80 = (_WORD *)v120; /*0x19dee0*/
        for ( i10 = v76 - 1; i10 != -1; --i10 ) /*0x19dee7*/
          *v80++ = v114; /*0x19def0*/
      }
      else
      {
        if ( v77 != 1 ) /*0x19deb7*/
          goto LABEL_278; /*0x19deb7*/
        v78 = (_BYTE *)v120; /*0x19dec4*/
        for ( i11 = v76 - 1; i11 != -1; --i11 ) /*0x19decb*/
          *v78++ = v114; /*0x19ded3*/
      }
      v120 += a1[4]; /*0x19df2c*/
    }
    sub_19BA18(a1); /*0x19df3d*/
    sub_19C898(a1, a4); /*0x19df47*/
  }
  else
  {
    a1[41] = a1[39] - 1; /*0x19df57*/
    sub_19C898(a1, a4); /*0x19df62*/
    sub_19BFA0(a1, 10); /*0x19df6a*/
  }
}
