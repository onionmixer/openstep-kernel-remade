/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x198adc. */
int __cdecl sub_198ADC(int a1, const char *a2)
{
  unsigned int v2; // ecx
  int result; // eax
  int v4; // ebx
  int v5; // edi
  unsigned __int8 v6; // cl
  _BYTE *v7; // ebx
  int v8; // ecx
  int i; // esi
  int j; // esi
  int v11; // ebx
  int v12; // edi
  unsigned __int8 v13; // cl
  _BYTE *v14; // ebx
  int v15; // ecx
  int m; // esi
  int n; // esi
  int v18; // ebx
  int v19; // edi
  unsigned __int8 v20; // cl
  _BYTE *v21; // ebx
  int v22; // ecx
  int jj; // esi
  int kk; // esi
  int v25; // edi
  unsigned __int8 v26; // bl
  int v27; // ebx
  int nn; // esi
  int i1; // esi
  _BYTE *v30; // ecx
  int v31; // edi
  int v32; // ebx
  unsigned __int8 v33; // cl
  _BYTE *v34; // ebx
  int v35; // ecx
  int i3; // esi
  int i4; // esi
  int v38; // ebx
  int v39; // edi
  unsigned __int8 v40; // cl
  _BYTE *v41; // ebx
  int v42; // ecx
  int i6; // esi
  int i7; // esi
  int v45; // ecx
  int v46; // ebx
  int v47; // ecx
  int v48; // edi
  int v49; // esi
  char v50; // bl
  char v51; // cl
  int i9; // esi
  int i10; // esi
  _BYTE *v54; // ebx
  int i11; // ecx
  char v56; // [esp-4h] [ebp-7Ch]
  int v57; // [esp+14h] [ebp-64h]
  _BYTE *v58; // [esp+18h] [ebp-60h]
  int v59; // [esp+18h] [ebp-60h]
  _BYTE *v60; // [esp+18h] [ebp-60h]
  int v61; // [esp+18h] [ebp-60h]
  _BYTE *v62; // [esp+18h] [ebp-60h]
  int v63; // [esp+18h] [ebp-60h]
  _BYTE *v64; // [esp+18h] [ebp-60h]
  int v65; // [esp+18h] [ebp-60h]
  _BYTE *v66; // [esp+18h] [ebp-60h]
  int v67; // [esp+18h] [ebp-60h]
  _BYTE *v68; // [esp+18h] [ebp-60h]
  int v69; // [esp+18h] [ebp-60h]
  _BYTE *v70; // [esp+18h] [ebp-60h]
  int v71; // [esp+1Ch] [ebp-5Ch]
  int k; // [esp+1Ch] [ebp-5Ch]
  int v73; // [esp+1Ch] [ebp-5Ch]
  int v74; // [esp+1Ch] [ebp-5Ch]
  int v75; // [esp+1Ch] [ebp-5Ch]
  int ii; // [esp+1Ch] [ebp-5Ch]
  int v77; // [esp+1Ch] [ebp-5Ch]
  int mm; // [esp+1Ch] [ebp-5Ch]
  int v79; // [esp+1Ch] [ebp-5Ch]
  int i2; // [esp+1Ch] [ebp-5Ch]
  int v81; // [esp+1Ch] [ebp-5Ch]
  int i5; // [esp+1Ch] [ebp-5Ch]
  int v83; // [esp+1Ch] [ebp-5Ch]
  int i8; // [esp+1Ch] [ebp-5Ch]
  unsigned __int8 v85; // [esp+1Ch] [ebp-5Ch]
  int v86; // [esp+1Ch] [ebp-5Ch]
  int v87; // [esp+1Ch] [ebp-5Ch]
  int v88; // [esp+20h] [ebp-58h]
  int v89; // [esp+24h] [ebp-54h]
  unsigned __int8 v90; // [esp+28h] [ebp-50h]
  unsigned __int8 v91; // [esp+2Ch] [ebp-4Ch]
  unsigned __int8 v92; // [esp+30h] [ebp-48h]
  unsigned __int8 v93; // [esp+34h] [ebp-44h]
  unsigned __int8 v94; // [esp+38h] [ebp-40h]
  unsigned __int8 v95; // [esp+3Ch] [ebp-3Ch]
  int v96; // [esp+40h] [ebp-38h]
  unsigned __int8 v97; // [esp+44h] [ebp-34h]
  unsigned __int8 v98; // [esp+48h] [ebp-30h]
  int v99; // [esp+4Ch] [ebp-2Ch]
  unsigned __int8 v100; // [esp+50h] [ebp-28h]
  unsigned __int8 v101; // [esp+54h] [ebp-24h]
  unsigned __int8 v102; // [esp+58h] [ebp-20h]
  unsigned __int8 v103; // [esp+5Ch] [ebp-1Ch]
  unsigned __int8 v104; // [esp+60h] [ebp-18h]
  unsigned __int8 v105; // [esp+64h] [ebp-14h]
  unsigned int v106; // [esp+68h] [ebp-10h]
  int v107; // [esp+6Ch] [ebp-Ch]
  int v108; // [esp+70h] [ebp-8h]

  v108 = *(_DWORD *)(a1 + 164); /*0x198aee*/
  v107 = *(_DWORD *)(a1 + 168); /*0x198afa*/
  v2 = strlen(a2) + 1; /*0x198b0a*/
  v106 = v2 - 1; /*0x198b11*/
  if ( v2 == 1 || *(_DWORD *)(a1 + 148) < (signed int)(v2 - 1) ) /*0x198b1f*/
    return IOLog(aConsoleIllegal); /*0x198b2a*/
  sub_197CA0(a1); /*0x198b38*/
  if ( *(_DWORD *)(a1 + 192) ) /*0x198b43*/
  {
    *(_DWORD *)(a1 + 144) -= 24; /*0x198b4c*/
    *(_DWORD *)(a1 + 156) += 2; /*0x198b53*/
    *(_DWORD *)(a1 + 160) += 24; /*0x198b5a*/
    v108 += 2; /*0x198b61*/
  }
  *(_DWORD *)(a1 + 164) = 0; /*0x198b68*/
  v57 = *(_DWORD *)(a1 + 140); /*0x198b78*/
  v4 = *(_DWORD *)(a1 + 144); /*0x198b7b*/
  v71 = 8 * *(_DWORD *)(a1 + 148) + v57; /*0x198b93*/
  v5 = *(_DWORD *)(a1 + 16); /*0x198b99*/
  v6 = *(_BYTE *)(a1 + 180); /*0x198b9c*/
  __outbyte(0x3CEu, 0); /*0x198ba9*/
  _InterlockedIncrement(&dword_1E8654); /*0x198baa*/
  __outbyte(0x3CFu, v6); /*0x198bb8*/
  _InterlockedIncrement(&dword_1E8654); /*0x198bb9*/
  __outbyte(0x3CEu, 8u); /*0x198bc7*/
  _InterlockedIncrement(&dword_1E8654); /*0x198bc8*/
  v105 = byte_1E4685[v57 & 7]; /*0x198be7*/
  v104 = byte_1E468D[v71 & 7]; /*0x198bf6*/
  v7 = (_BYTE *)((v57 >> 3) + *(_DWORD *)(a1 + 24) + v5 * v4); /*0x198c02*/
  v8 = (v71 >> 3) - (v57 >> 3) - 1; /*0x198c06*/
  if ( v71 >> 3 == v57 >> 3 ) /*0x198c0a*/
  {
    __outbyte(0x3CFu, v105 & byte_1E468D[v71 & 7]); /*0x198c16*/
    _InterlockedIncrement(&dword_1E8654); /*0x198c17*/
    for ( i = 21; i >= 0; --i ) /*0x198c1e*/
    {
      *v7 = -1; /*0x198c29*/
      v7 += v5; /*0x198c2c*/
    }
  }
  else
  {
    for ( j = 21; j >= 0; --j ) /*0x198c34*/
    {
      __outbyte(0x3CFu, v105); /*0x198c49*/
      _InterlockedIncrement(&dword_1E8654); /*0x198c4a*/
      *v7 = -1; /*0x198c51*/
      v58 = v7 + 1; /*0x198c57*/
      __outbyte(0x3CFu, 0xFFu); /*0x198c5c*/
      _InterlockedIncrement(&dword_1E8654); /*0x198c5d*/
      for ( k = v8 - 1; k >= 0; --k ) /*0x198c6c*/
        *v58++ = -1; /*0x198c73*/
      __outbyte(0x3CFu, v104); /*0x198c87*/
      _InterlockedIncrement(&dword_1E8654); /*0x198c88*/
      *v58 = -1; /*0x198c9a*/
      v7 += v5; /*0x198c9d*/
    }
  }
  __outbyte(0x3CFu, 0xFFu); /*0x198ca9*/
  _InterlockedIncrement(&dword_1E8654); /*0x198caa*/
  v11 = *(_DWORD *)(a1 + 144); /*0x198cb4*/
  *(_DWORD *)(a1 + 144) = v11 + 6; /*0x198cbd*/
  *(_DWORD *)(a1 + 168) = (int)(*(_DWORD *)(a1 + 148) - v106) / 2; /*0x198cdc*/
  sub_197CA0(a1); /*0x198ce3*/
  v73 = *(_DWORD *)(a1 + 180); /*0x198cf4*/
  *(_DWORD *)(a1 + 180) = *(_DWORD *)(a1 + 176); /*0x198d00*/
  *(_DWORD *)(a1 + 176) = v73; /*0x198d09*/
  while ( *a2 ) /*0x198d12*/
  {
    v56 = *a2++; /*0x198d1e*/
    sub_198098(a1, v56); /*0x198d26*/
  }
  v74 = *(_DWORD *)(a1 + 180); /*0x198d3f*/
  *(_DWORD *)(a1 + 180) = *(_DWORD *)(a1 + 176); /*0x198d4b*/
  *(_DWORD *)(a1 + 176) = v74; /*0x198d54*/
  sub_197CA0(a1); /*0x198d5b*/
  *(_DWORD *)(a1 + 144) = v11; /*0x198d63*/
  v59 = *(_DWORD *)(a1 + 140) - 2; /*0x198d72*/
  v75 = *(_DWORD *)(a1 + 152) + 4 + v59; /*0x198d86*/
  v12 = *(_DWORD *)(a1 + 16); /*0x198d8c*/
  v13 = *(_BYTE *)(a1 + 188); /*0x198d8f*/
  __outbyte(0x3CEu, 0); /*0x198d9c*/
  _InterlockedIncrement(&dword_1E8654); /*0x198d9d*/
  __outbyte(0x3CFu, v13); /*0x198dab*/
  _InterlockedIncrement(&dword_1E8654); /*0x198dac*/
  __outbyte(0x3CEu, 8u); /*0x198dba*/
  _InterlockedIncrement(&dword_1E8654); /*0x198dbb*/
  v103 = byte_1E4685[v59 & 7]; /*0x198dda*/
  v102 = byte_1E468D[v75 & 7]; /*0x198de9*/
  v14 = (_BYTE *)((v59 >> 3) + *(_DWORD *)(a1 + 24) + v12 * (v11 - 2)); /*0x198df5*/
  v15 = (v75 >> 3) - (v59 >> 3) - 1; /*0x198df9*/
  if ( v75 >> 3 == v59 >> 3 ) /*0x198dfd*/
  {
    __outbyte(0x3CFu, v103 & byte_1E468D[v75 & 7]); /*0x198e09*/
    _InterlockedIncrement(&dword_1E8654); /*0x198e0a*/
    for ( m = 1; m >= 0; --m ) /*0x198e11*/
    {
      *v14 = -1; /*0x198e1d*/
      v14 += v12; /*0x198e20*/
    }
  }
  else
  {
    for ( n = 1; n >= 0; --n ) /*0x198e28*/
    {
      __outbyte(0x3CFu, v103); /*0x198e3d*/
      _InterlockedIncrement(&dword_1E8654); /*0x198e3e*/
      *v14 = -1; /*0x198e45*/
      v60 = v14 + 1; /*0x198e4b*/
      __outbyte(0x3CFu, 0xFFu); /*0x198e50*/
      _InterlockedIncrement(&dword_1E8654); /*0x198e51*/
      for ( ii = v15 - 1; ii >= 0; --ii ) /*0x198e60*/
        *v60++ = -1; /*0x198e67*/
      __outbyte(0x3CFu, v102); /*0x198e7b*/
      _InterlockedIncrement(&dword_1E8654); /*0x198e7c*/
      *v60 = -1; /*0x198e8e*/
      v14 += v12; /*0x198e91*/
    }
  }
  __outbyte(0x3CFu, 0xFFu); /*0x198e9d*/
  _InterlockedIncrement(&dword_1E8654); /*0x198e9e*/
  v61 = *(_DWORD *)(a1 + 140) - 2; /*0x198eb1*/
  v18 = *(_DWORD *)(a1 + 144) + 19; /*0x198ebd*/
  v77 = *(_DWORD *)(a1 + 152) + 4 + v61; /*0x198ece*/
  v19 = *(_DWORD *)(a1 + 16); /*0x198ed4*/
  v20 = *(_BYTE *)(a1 + 184); /*0x198ed7*/
  __outbyte(0x3CEu, 0); /*0x198ee4*/
  _InterlockedIncrement(&dword_1E8654); /*0x198ee5*/
  __outbyte(0x3CFu, v20); /*0x198ef3*/
  _InterlockedIncrement(&dword_1E8654); /*0x198ef4*/
  __outbyte(0x3CEu, 8u); /*0x198f02*/
  _InterlockedIncrement(&dword_1E8654); /*0x198f03*/
  v101 = byte_1E4685[v61 & 7]; /*0x198f22*/
  v100 = byte_1E468D[v77 & 7]; /*0x198f31*/
  v21 = (_BYTE *)((v61 >> 3) + *(_DWORD *)(a1 + 24) + v19 * v18); /*0x198f3d*/
  v22 = (v77 >> 3) - (v61 >> 3) - 1; /*0x198f41*/
  if ( v77 >> 3 == v61 >> 3 ) /*0x198f45*/
  {
    __outbyte(0x3CFu, v101 & byte_1E468D[v77 & 7]); /*0x198f51*/
    _InterlockedIncrement(&dword_1E8654); /*0x198f52*/
    for ( jj = 1; jj >= 0; --jj ) /*0x198f59*/
    {
      *v21 = -1; /*0x198f65*/
      v21 += v19; /*0x198f68*/
    }
  }
  else
  {
    for ( kk = 1; kk >= 0; --kk ) /*0x198f70*/
    {
      __outbyte(0x3CFu, v101); /*0x198f85*/
      _InterlockedIncrement(&dword_1E8654); /*0x198f86*/
      *v21 = -1; /*0x198f8d*/
      v62 = v21 + 1; /*0x198f93*/
      __outbyte(0x3CFu, 0xFFu); /*0x198f98*/
      _InterlockedIncrement(&dword_1E8654); /*0x198f99*/
      for ( mm = v22 - 1; mm >= 0; --mm ) /*0x198fa8*/
        *v62++ = -1; /*0x198faf*/
      __outbyte(0x3CFu, v100); /*0x198fc3*/
      _InterlockedIncrement(&dword_1E8654); /*0x198fc4*/
      *v62 = -1; /*0x198fd6*/
      v21 += v19; /*0x198fd9*/
    }
  }
  __outbyte(0x3CFu, 0xFFu); /*0x198fe5*/
  _InterlockedIncrement(&dword_1E8654); /*0x198fe6*/
  v25 = 0; /*0x198fed*/
  v88 = 23; /*0x198fef*/
  do /*0x199151*/
  {
    v79 = *(_DWORD *)(a1 + 140) + v25 - 2; /*0x199006*/
    v63 = *(_DWORD *)(a1 + 144) + v25 - 2; /*0x199014*/
    v99 = *(_DWORD *)(a1 + 16); /*0x19901e*/
    v26 = *(_BYTE *)(a1 + 188); /*0x199024*/
    __outbyte(0x3CEu, 0); /*0x199031*/
    _InterlockedIncrement(&dword_1E8654); /*0x199032*/
    __outbyte(0x3CFu, v26); /*0x199040*/
    _InterlockedIncrement(&dword_1E8654); /*0x199041*/
    __outbyte(0x3CEu, 8u); /*0x19904f*/
    _InterlockedIncrement(&dword_1E8654); /*0x199050*/
    v98 = byte_1E4685[v79 & 7]; /*0x19906e*/
    v97 = byte_1E468D[(v79 + 1) & 7]; /*0x19907a*/
    v64 = (_BYTE *)((v79 >> 3) + *(_DWORD *)(a1 + 24) + v99 * v63); /*0x19908c*/
    v27 = ((v79 + 1) >> 3) - (v79 >> 3) - 1; /*0x199091*/
    if ( (v79 + 1) >> 3 == v79 >> 3 ) /*0x19908f*/
    {
      __outbyte(0x3CFu, v98 & byte_1E468D[(v79 + 1) & 7]); /*0x1990a1*/
      _InterlockedIncrement(&dword_1E8654); /*0x1990a2*/
      for ( nn = v88 - 1; nn >= 0; --nn ) /*0x1990ad*/
      {
        *v64 = -1; /*0x1990bf*/
        v64 += v99; /*0x1990c7*/
      }
    }
    else
    {
      for ( i1 = v88 - 1; i1 >= 0; --i1 ) /*0x1990d4*/
      {
        __outbyte(0x3CFu, v98); /*0x1990e8*/
        _InterlockedIncrement(&dword_1E8654); /*0x1990e9*/
        *v64 = -1; /*0x1990f3*/
        v30 = v64 + 1; /*0x1990f9*/
        __outbyte(0x3CFu, 0xFFu); /*0x1990fc*/
        _InterlockedIncrement(&dword_1E8654); /*0x1990fd*/
        for ( i2 = v27 - 1; i2 >= 0; --i2 ) /*0x19910c*/
          *v30++ = -1; /*0x199110*/
        __outbyte(0x3CFu, v97); /*0x199121*/
        _InterlockedIncrement(&dword_1E8654); /*0x199122*/
        *v30 = -1; /*0x19912e*/
        v64 += v99; /*0x199134*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x199141*/
    _InterlockedIncrement(&dword_1E8654); /*0x199142*/
    v88 -= 2; /*0x199149*/
    ++v25; /*0x19914d*/
  }
  while ( v25 <= 1 ); /*0x199151*/
  v31 = 1; /*0x199157*/
  v89 = 21; /*0x19915c*/
  do /*0x1992b2*/
  {
    v32 = *(_DWORD *)(a1 + 144) - v31; /*0x19916d*/
    v81 = v31 + *(_DWORD *)(a1 + 152) + *(_DWORD *)(a1 + 140) - 1; /*0x19917f*/
    v65 = v31 + *(_DWORD *)(a1 + 152) + *(_DWORD *)(a1 + 140); /*0x199183*/
    v96 = *(_DWORD *)(a1 + 16); /*0x199189*/
    v33 = *(_BYTE *)(a1 + 184); /*0x19918c*/
    __outbyte(0x3CEu, 0); /*0x199199*/
    _InterlockedIncrement(&dword_1E8654); /*0x19919a*/
    __outbyte(0x3CFu, v33); /*0x1991a8*/
    _InterlockedIncrement(&dword_1E8654); /*0x1991a9*/
    __outbyte(0x3CEu, 8u); /*0x1991b7*/
    _InterlockedIncrement(&dword_1E8654); /*0x1991b8*/
    v95 = byte_1E4685[v81 & 7]; /*0x1991d7*/
    v94 = byte_1E468D[v65 & 7]; /*0x1991e6*/
    v34 = (_BYTE *)((v81 >> 3) + *(_DWORD *)(a1 + 24) + v96 * v32); /*0x1991f3*/
    v35 = (v65 >> 3) - (v81 >> 3) - 1; /*0x1991f7*/
    if ( v65 >> 3 == v81 >> 3 ) /*0x1991fb*/
    {
      __outbyte(0x3CFu, v95 & byte_1E468D[v65 & 7]); /*0x199207*/
      _InterlockedIncrement(&dword_1E8654); /*0x199208*/
      for ( i3 = v89 - 1; i3 >= 0; --i3 ) /*0x199213*/
      {
        *v34 = -1; /*0x199221*/
        v34 += v96; /*0x199224*/
      }
    }
    else
    {
      for ( i4 = v89 - 1; i4 >= 0; --i4 ) /*0x199230*/
      {
        __outbyte(0x3CFu, v95); /*0x199241*/
        _InterlockedIncrement(&dword_1E8654); /*0x199242*/
        *v34 = -1; /*0x199249*/
        v66 = v34 + 1; /*0x19924f*/
        __outbyte(0x3CFu, 0xFFu); /*0x199254*/
        _InterlockedIncrement(&dword_1E8654); /*0x199255*/
        for ( i5 = v35 - 1; i5 >= 0; --i5 ) /*0x199264*/
          *v66++ = -1; /*0x19926b*/
        __outbyte(0x3CFu, v94); /*0x19927f*/
        _InterlockedIncrement(&dword_1E8654); /*0x199280*/
        *v66 = -1; /*0x199292*/
        v34 += v96; /*0x199295*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x1992a2*/
    _InterlockedIncrement(&dword_1E8654); /*0x1992a3*/
    v89 += 2; /*0x1992aa*/
    ++v31; /*0x1992ae*/
  }
  while ( v31 <= 2 ); /*0x1992b2*/
  v67 = *(_DWORD *)(a1 + 140) - 3; /*0x1992c4*/
  v38 = *(_DWORD *)(a1 + 144) + 21; /*0x1992d0*/
  v83 = *(_DWORD *)(a1 + 152) + 6 + v67; /*0x1992e1*/
  v39 = *(_DWORD *)(a1 + 16); /*0x1992e7*/
  v40 = *(_BYTE *)(a1 + 180); /*0x1992ea*/
  __outbyte(0x3CEu, 0); /*0x1992f7*/
  _InterlockedIncrement(&dword_1E8654); /*0x1992f8*/
  __outbyte(0x3CFu, v40); /*0x199306*/
  _InterlockedIncrement(&dword_1E8654); /*0x199307*/
  __outbyte(0x3CEu, 8u); /*0x199315*/
  _InterlockedIncrement(&dword_1E8654); /*0x199316*/
  v93 = byte_1E4685[v67 & 7]; /*0x199335*/
  v92 = byte_1E468D[v83 & 7]; /*0x199344*/
  v41 = (_BYTE *)((v67 >> 3) + *(_DWORD *)(a1 + 24) + v39 * v38); /*0x199350*/
  v42 = (v83 >> 3) - (v67 >> 3) - 1; /*0x199354*/
  if ( v83 >> 3 == v67 >> 3 ) /*0x199358*/
  {
    __outbyte(0x3CFu, v93 & byte_1E468D[v83 & 7]); /*0x199364*/
    _InterlockedIncrement(&dword_1E8654); /*0x199365*/
    for ( i6 = 0; i6 >= 0; --i6 ) /*0x19936c*/
    {
      *v41 = -1; /*0x199375*/
      v41 += v39; /*0x199378*/
    }
  }
  else
  {
    for ( i7 = 0; i7 >= 0; --i7 ) /*0x199380*/
    {
      __outbyte(0x3CFu, v93); /*0x199391*/
      _InterlockedIncrement(&dword_1E8654); /*0x199392*/
      *v41 = -1; /*0x199399*/
      v68 = v41 + 1; /*0x19939f*/
      __outbyte(0x3CFu, 0xFFu); /*0x1993a4*/
      _InterlockedIncrement(&dword_1E8654); /*0x1993a5*/
      for ( i8 = v42 - 1; i8 >= 0; --i8 ) /*0x1993b4*/
        *v68++ = -1; /*0x1993bb*/
      __outbyte(0x3CFu, v92); /*0x1993cf*/
      _InterlockedIncrement(&dword_1E8654); /*0x1993d0*/
      *v68 = -1; /*0x1993e2*/
      v41 += v39; /*0x1993e5*/
    }
  }
  __outbyte(0x3CFu, 0xFFu); /*0x1993f1*/
  _InterlockedIncrement(&dword_1E8654); /*0x1993f2*/
  *(_DWORD *)(a1 + 144) += 24; /*0x1993fc*/
  *(_DWORD *)(a1 + 156) -= 2; /*0x199403*/
  *(_DWORD *)(a1 + 160) -= 24; /*0x19940a*/
  *(_DWORD *)(a1 + 168) = v107; /*0x199414*/
  if ( v108 <= 0 ) /*0x19941e*/
  {
    v45 = *(_DWORD *)(a1 + 140); /*0x199437*/
    v46 = v45 + 8 * v107; /*0x199440*/
    v69 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x19945b*/
    v47 = *(_DWORD *)(a1 + 152) + v45; /*0x199461*/
    v48 = *(_DWORD *)(a1 + 16); /*0x199467*/
    v85 = *(_BYTE *)(a1 + 176); /*0x199470*/
    __outbyte(0x3CEu, 0); /*0x19947a*/
    _InterlockedIncrement(&dword_1E8654); /*0x19947b*/
    __outbyte(0x3CFu, v85); /*0x19948a*/
    _InterlockedIncrement(&dword_1E8654); /*0x19948b*/
    __outbyte(0x3CEu, 8u); /*0x199499*/
    _InterlockedIncrement(&dword_1E8654); /*0x19949a*/
    v49 = v46 >> 3; /*0x1994a3*/
    v86 = v47 >> 3; /*0x1994ab*/
    v50 = byte_1E4685[v46 & 7]; /*0x1994b1*/
    v91 = v50; /*0x1994b7*/
    v51 = byte_1E468D[v47 & 7]; /*0x1994bd*/
    v90 = v51; /*0x1994c3*/
    v70 = (_BYTE *)(v49 + *(_DWORD *)(a1 + 24) + v48 * v69); /*0x1994d4*/
    v87 = v86 - v49 - 1; /*0x1994dd*/
    if ( v87 == -1 ) /*0x1994e3*/
    {
      __outbyte(0x3CFu, v50 & v51); /*0x1994ee*/
      _InterlockedIncrement(&dword_1E8654); /*0x1994ef*/
      for ( i9 = 11; i9 >= 0; --i9 ) /*0x1994f6*/
      {
        *v70 = -1; /*0x199507*/
        v70 += v48; /*0x19950c*/
      }
    }
    else
    {
      for ( i10 = 11; i10 >= 0; --i10 ) /*0x199514*/
      {
        __outbyte(0x3CFu, v91); /*0x19952c*/
        _InterlockedIncrement(&dword_1E8654); /*0x19952d*/
        *v70 = -1; /*0x199537*/
        v54 = v70 + 1; /*0x19953d*/
        __outbyte(0x3CFu, 0xFFu); /*0x199540*/
        _InterlockedIncrement(&dword_1E8654); /*0x199541*/
        for ( i11 = v87 - 1; i11 >= 0; --i11 ) /*0x19954c*/
          *v54++ = -1; /*0x199550*/
        __outbyte(0x3CFu, v90); /*0x19955f*/
        _InterlockedIncrement(&dword_1E8654); /*0x199560*/
        *v54 = -1; /*0x19956c*/
        v70 += v48; /*0x19956f*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19957c*/
    _InterlockedIncrement(&dword_1E8654); /*0x19957d*/
  }
  else
  {
    *(_DWORD *)(a1 + 164) = v108 - 2; /*0x199426*/
  }
  LOBYTE(result) = sub_197CA0(a1); /*0x199588*/
  *(_DWORD *)(a1 + 192) = 1; /*0x199590*/
  return result; /*0x19959d*/
}
