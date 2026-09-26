/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ce0cc. */
int __cdecl objc_registerModule(mach_header *mhp, void (__cdecl *a2)(Class, int))
{
  int v2; // ebx
  int v3; // esi
  char *v5; // esi
  uint32_t v6; // edi
  uint32_t j; // ebx
  SEL v8; // eax
  unsigned int *v9; // edi
  unsigned int m; // esi
  const char **v11; // ebx
  SEL v12; // eax
  unsigned int *v13; // edi
  unsigned int n; // esi
  const char **v15; // ebx
  SEL v16; // eax
  int v17; // ebx
  int v18; // ebx
  int *v19; // edi
  unsigned int ii; // esi
  const char **v21; // ebx
  SEL v22; // eax
  unsigned int jj; // esi
  const char **v24; // ebx
  SEL v25; // eax
  int v26; // ebx
  int v27; // ebx
  int v28; // edi
  unsigned int kk; // esi
  const char **v30; // ebx
  SEL v31; // eax
  int v32; // edi
  unsigned int mm; // esi
  const char **v34; // ebx
  SEL v35; // eax
  unsigned int *v36; // eax
  unsigned int v37; // esi
  unsigned int v38; // edi
  unsigned int nn; // ebx
  SEL v40; // eax
  char *v41; // esi
  uint32_t i1; // ebx
  int v43; // ebx
  int v44; // ebx
  Class Class; // eax
  int v46; // [esp-4h] [ebp-3Ch]
  int v47; // [esp+10h] [ebp-28h]
  int v48; // [esp+14h] [ebp-24h]
  int v49; // [esp+18h] [ebp-20h]
  uint32_t k; // [esp+1Ch] [ebp-1Ch]
  char *v51; // [esp+20h] [ebp-18h]
  int v52; // [esp+24h] [ebp-14h]
  int v53; // [esp+24h] [ebp-14h]
  int v54; // [esp+24h] [ebp-14h]
  int v55; // [esp+24h] [ebp-14h]
  int v56; // [esp+24h] [ebp-14h]
  int v57; // [esp+24h] [ebp-14h]
  int *v58; // [esp+28h] [ebp-10h]
  char *v59; // [esp+2Ch] [ebp-Ch]
  int *v60; // [esp+2Ch] [ebp-Ch]
  int *v61; // [esp+2Ch] [ebp-Ch]
  int *v62; // [esp+2Ch] [ebp-Ch]
  int *v63; // [esp+2Ch] [ebp-Ch]
  int *v64; // [esp+2Ch] [ebp-Ch]
  int *v65; // [esp+2Ch] [ebp-Ch]
  uint32_t i; // [esp+30h] [ebp-8h] BYREF
  uint32_t size; // [esp+34h] [ebp-4h] BYREF

  v2 = 0; /*0x1ce0d5*/
  v59 = getsectdatafromheader(mhp, "__OBJC", "__module_info", &size); /*0x1ce0ee*/
  v58 = (int *)v59; /*0x1ce0f1*/
  for ( i = size; v59; v59 += *((_DWORD *)v59 + 1) ) /*0x1ce101*/
  {
    if ( !i ) /*0x1ce108*/
      break; /*0x1ce108*/
    v3 = *((_DWORD *)v59 + 3); /*0x1ce110*/
    v52 = 0; /*0x1ce112*/
    if ( *(_WORD *)(v3 + 8) ) /*0x1ce119*/
    {
      do /*0x1ce149*/
      {
        if ( objc_lookUpClass(*(const char **)(v3 + 4 * v52 + 12)) ) /*0x1ce128*/
          v2 = 1; /*0x1ce134*/
        ++v52; /*0x1ce139*/
        v3 = *((_DWORD *)v59 + 3); /*0x1ce13f*/
      }
      while ( v52 < *(unsigned __int16 *)(v3 + 8) ); /*0x1ce149*/
    }
    i -= *((_DWORD *)v59 + 1); /*0x1ce151*/
  }
  if ( v2 ) /*0x1ce163*/
    return 1; /*0x1ce165*/
  _objc_addHeader(mhp); /*0x1ce176*/
  sub_1CE058(mhp); /*0x1ce17f*/
  v5 = getsectdatafromheader(mhp, "__OBJC", "__message_refs", &i); /*0x1ce19b*/
  if ( v5 ) /*0x1ce1a2*/
  {
    v6 = i >> 2; /*0x1ce1a7*/
    for ( j = 0; j < v6; ++j ) /*0x1ce1a7*/
    {
      v8 = sel_registerName(*(const char **)&v5[4 * j]); /*0x1ce1b4*/
      if ( *(SEL *)&v5[4 * j] != v8 ) /*0x1ce1bf*/
        *(_DWORD *)&v5[4 * j] = v8; /*0x1ce1c1*/
    }
  }
  v51 = getsectdatafromheader(mhp, "__OBJC", "__protocol", &i); /*0x1ce1e0*/
  if ( v51 ) /*0x1ce1e8*/
  {
    for ( k = 0; k < i / 0x14; ++k ) /*0x1ce1ee*/
    {
      if ( *(_DWORD *)&v51[20 * k + 12] ) /*0x1ce204*/
      {
        v9 = *(unsigned int **)&v51[20 * k + 12]; /*0x1ce20b*/
        for ( m = 0; *v9 > m; ++m ) /*0x1ce211*/
        {
          v11 = (const char **)&v9[2 * m + 1]; /*0x1ce218*/
          v12 = sel_registerName(*v11); /*0x1ce21f*/
          if ( *v11 != v12 ) /*0x1ce229*/
            *v11 = v12; /*0x1ce22b*/
        }
      }
      if ( *(_DWORD *)&v51[20 * k + 16] ) /*0x1ce23e*/
      {
        v13 = *(unsigned int **)&v51[20 * k + 16]; /*0x1ce245*/
        for ( n = 0; *v13 > n; ++n ) /*0x1ce24b*/
        {
          v15 = (const char **)&v13[2 * n + 1]; /*0x1ce250*/
          v16 = sel_registerName(*v15); /*0x1ce257*/
          if ( *v15 != v16 ) /*0x1ce261*/
            *v15 = v16; /*0x1ce263*/
        }
      }
    }
    +[Protocol _fixup:numElements:](aProtocol_0, sel__fixup_numElements_, v51, i / 0x14); /*0x1ce2a1*/
  }
  v60 = v58; /*0x1ce2ac*/
  for ( i = size; v60; v60 = (int *)((char *)v60 + v60[1]) ) /*0x1ce2b9*/
  {
    if ( !i ) /*0x1ce2c0*/
      break; /*0x1ce2c0*/
    v17 = v60[3]; /*0x1ce2c8*/
    v53 = 0; /*0x1ce2ca*/
    if ( *(_WORD *)(v17 + 8) ) /*0x1ce2d1*/
    {
      do /*0x1ce2f8*/
      {
        objc_addClass(*(Class *)(v17 + 4 * v53++ + 12)); /*0x1ce2e0*/
        v17 = v60[3]; /*0x1ce2ee*/
      }
      while ( v53 < *(unsigned __int16 *)(v17 + 8) ); /*0x1ce2f8*/
    }
    i -= v60[1]; /*0x1ce300*/
  }
  v61 = v58; /*0x1ce313*/
  for ( i = size; v61; v61 = (int *)((char *)v61 + v61[1]) ) /*0x1ce320*/
  {
    if ( !i ) /*0x1ce32c*/
      break; /*0x1ce32c*/
    v18 = v61[3]; /*0x1ce338*/
    v54 = 0; /*0x1ce33a*/
    if ( *(_WORD *)(v18 + 8) ) /*0x1ce341*/
    {
      do /*0x1ce43d*/
      {
        v19 = *(int **)(v18 + 4 * v54 + 12); /*0x1ce34f*/
        if ( v19[7] ) /*0x1ce353*/
        {
          v49 = v19[7]; /*0x1ce35c*/
          for ( ii = 0; *(_DWORD *)(v49 + 4) > ii; ++ii ) /*0x1ce361*/
          {
            v21 = (const char **)(v49 + 12 * ii + 8); /*0x1ce36e*/
            v22 = sel_registerName(*v21); /*0x1ce375*/
            if ( *v21 != v22 ) /*0x1ce37f*/
              *v21 = v22; /*0x1ce381*/
          }
        }
        if ( *(_DWORD *)(*v19 + 28) ) /*0x1ce38e*/
        {
          v48 = *(_DWORD *)(*v19 + 28); /*0x1ce397*/
          for ( jj = 0; *(_DWORD *)(v48 + 4) > jj; ++jj ) /*0x1ce39c*/
          {
            v24 = (const char **)(v48 + 12 * jj + 8); /*0x1ce3aa*/
            v25 = sel_registerName(*v24); /*0x1ce3b1*/
            if ( *v24 != v25 ) /*0x1ce3bb*/
              *v24 = v25; /*0x1ce3bd*/
          }
        }
        _class_install_relationships(v19, *v61); /*0x1ce3cf*/
        if ( (unsigned int)(*(_DWORD *)(*v19 + 12) - 3) <= 1 && v19[9] ) /*0x1ce3e4*/
        {
          v19[9] -= 4; /*0x1ce3ea*/
          *(_DWORD *)(*v19 + 36) -= 4; /*0x1ce3f0*/
        }
        if ( *(_DWORD *)(*v19 + 12) == 3 && v19[9] ) /*0x1ce3fc*/
        {
          _objc_inform("Unable to install protocols by name...\n"); /*0x1ce407*/
          _objc_inform("Class %s must be recompiled.\n", (const char *)v19[2]); /*0x1ce415*/
          v19[9] = 0; /*0x1ce41a*/
          *(_DWORD *)(*v19 + 36) = 0; /*0x1ce423*/
        }
        ++v54; /*0x1ce42d*/
        v18 = v61[3]; /*0x1ce433*/
      }
      while ( v54 < *(unsigned __int16 *)(v18 + 8) ); /*0x1ce43d*/
    }
    i -= v61[1]; /*0x1ce449*/
  }
  v62 = v58; /*0x1ce460*/
  for ( i = size; v62; v62 = (int *)((char *)v62 + v62[1]) ) /*0x1ce46d*/
  {
    if ( !i ) /*0x1ce478*/
      break; /*0x1ce478*/
    v26 = v62[3]; /*0x1ce484*/
    v55 = *(unsigned __int16 *)(v26 + 8); /*0x1ce48a*/
    if ( v55 < v55 + *(unsigned __int16 *)(v26 + 10) ) /*0x1ce495*/
    {
      do /*0x1ce53c*/
      {
        v27 = *(_DWORD *)(v26 + 4 * v55 + 12); /*0x1ce49f*/
        v47 = v27; /*0x1ce4a3*/
        if ( *(_DWORD *)(v27 + 8) ) /*0x1ce4a6*/
        {
          v28 = *(_DWORD *)(v27 + 8); /*0x1ce4ac*/
          for ( kk = 0; *(_DWORD *)(v28 + 4) > kk; ++kk ) /*0x1ce4b1*/
          {
            v30 = (const char **)(v28 + 12 * kk + 8); /*0x1ce4bb*/
            v31 = sel_registerName(*v30); /*0x1ce4c2*/
            if ( *v30 != v31 ) /*0x1ce4cc*/
              *v30 = v31; /*0x1ce4ce*/
          }
        }
        if ( *(_DWORD *)(v47 + 12) ) /*0x1ce4d9*/
        {
          v32 = *(_DWORD *)(v47 + 12); /*0x1ce4df*/
          for ( mm = 0; *(_DWORD *)(v32 + 4) > mm; ++mm ) /*0x1ce4e4*/
          {
            v34 = (const char **)(v32 + 12 * mm + 8); /*0x1ce4ef*/
            v35 = sel_registerName(*v34); /*0x1ce4f6*/
            if ( *v34 != v35 ) /*0x1ce500*/
              *v34 = v35; /*0x1ce502*/
          }
        }
        _objc_add_category(*(_DWORD *)(v62[3] + 4 * v55++ + 12), *v62); /*0x1ce51e*/
        v26 = v62[3]; /*0x1ce52c*/
      }
      while ( v55 < *(unsigned __int16 *)(v26 + 10) + *(unsigned __int16 *)(v26 + 8) ); /*0x1ce53c*/
    }
    i -= v62[1]; /*0x1ce548*/
  }
  v63 = v58; /*0x1ce55f*/
  for ( i = size; v63; v63 = (int *)((char *)v63 + v63[1]) ) /*0x1ce56c*/
  {
    if ( !i ) /*0x1ce574*/
      break; /*0x1ce574*/
    if ( *v63 == 1 ) /*0x1ce57c*/
    {
      v36 = (unsigned int *)v63[3]; /*0x1ce57e*/
      v37 = v36[1]; /*0x1ce581*/
      v38 = *v36; /*0x1ce584*/
      for ( nn = 0; nn < v38; ++nn ) /*0x1ce584*/
      {
        v40 = sel_registerName(*(const char **)(v37 + 4 * nn)); /*0x1ce590*/
        if ( *(SEL *)(v37 + 4 * nn) != v40 ) /*0x1ce59b*/
          *(_DWORD *)(v37 + 4 * nn) = v40; /*0x1ce59d*/
      }
    }
    i -= v63[1]; /*0x1ce5ab*/
  }
  v41 = getsectdatafromheader(mhp, "__OBJC", "__cls_refs", &i); /*0x1ce5d2*/
  if ( v41 ) /*0x1ce5d9*/
  {
    for ( i1 = 0; i1 < i >> 2; ++i1 ) /*0x1ce5db*/
      *(_DWORD *)&v41[4 * i1] = objc_getClass(*(const char **)&v41[4 * i1]); /*0x1ce5e9*/
  }
  v64 = v58; /*0x1ce5fd*/
  for ( i = size; v64; v64 = (int *)((char *)v64 + v64[1]) ) /*0x1ce60a*/
  {
    if ( !i ) /*0x1ce610*/
      break; /*0x1ce610*/
    v43 = v64[3]; /*0x1ce618*/
    v56 = 0; /*0x1ce61a*/
    if ( *(_WORD *)(v43 + 8) ) /*0x1ce621*/
    {
      do /*0x1ce66a*/
      {
        if ( a2 ) /*0x1ce62c*/
          a2(*(Class *)(v43 + 4 * v56 + 12), 0); /*0x1ce63b*/
        sub_1CDF50(*(int **)(v64[3] + 4 * v56++ + 12), (int)mhp); /*0x1ce652*/
        v43 = v64[3]; /*0x1ce660*/
      }
      while ( v56 < *(unsigned __int16 *)(v43 + 8) ); /*0x1ce66a*/
    }
    i -= v64[1]; /*0x1ce672*/
  }
  v65 = v58; /*0x1ce685*/
  for ( i = size; v65; v65 = (int *)((char *)v65 + v65[1]) ) /*0x1ce692*/
  {
    if ( !i ) /*0x1ce69c*/
      break; /*0x1ce69c*/
    v44 = v65[3]; /*0x1ce6a8*/
    v57 = *(unsigned __int16 *)(v44 + 8); /*0x1ce6ae*/
    if ( v57 < v57 + *(unsigned __int16 *)(v44 + 10) ) /*0x1ce6b9*/
    {
      do /*0x1ce718*/
      {
        if ( a2 ) /*0x1ce6c0*/
        {
          v46 = *(_DWORD *)(v44 + 4 * v57 + 12); /*0x1ce6cb*/
          Class = objc_getClass(*(const char **)(v46 + 4)); /*0x1ce6d7*/
          a2(Class, v46); /*0x1ce6e3*/
        }
        sub_1CDF90(*(_DWORD *)(v65[3] + 4 * v57++ + 12), (int)mhp); /*0x1ce6fa*/
        v44 = v65[3]; /*0x1ce708*/
      }
      while ( v57 < *(unsigned __int16 *)(v44 + 10) + *(unsigned __int16 *)(v44 + 8) ); /*0x1ce718*/
    }
    i -= v65[1]; /*0x1ce720*/
  }
  return 0; /*0x1ce739*/
}
