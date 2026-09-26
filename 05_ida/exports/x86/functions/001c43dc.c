/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c43dc. */
int __cdecl -[IOFrameBufferDisplay selectMode:count:valid:modeString:](
        IOFrameBufferDisplay *self,
        SEL a2,
        const $514E7C50D28E54AB164B6500F83867A3 *a3,
        int a4,
        const char *a5,
        const char *a6)
{
  id v6; // eax
  id v7; // eax
  void *v8; // ebx
  const char *v10; // ebx
  size_t v11; // edi
  const char *i; // ebx
  int v13; // eax
  const char *v14; // edx
  const char *v15; // ebx
  const char *v16; // ebx
  size_t v17; // edi
  const char *j; // ebx
  int v19; // eax
  const char *v20; // edx
  const char *v21; // ebx
  const char *v22; // ebx
  size_t v23; // edi
  const char *k; // ebx
  int v25; // eax
  const char *v26; // edx
  const char *v27; // ebx
  const char *v28; // ebx
  size_t v29; // edi
  const char *m; // ebx
  int v31; // eax
  const char *v32; // edx
  const char *v33; // ebx
  const char *v34; // ebx
  size_t v35; // edi
  const char *n; // ebx
  int v37; // eax
  const char *v38; // edx
  const char *v39; // ebx
  const char *v40; // ebx
  size_t v41; // edi
  const char *ii; // ebx
  int v43; // eax
  const char *v44; // edx
  const char *v45; // ebx
  const char *v46; // ebx
  size_t v47; // edi
  const char *jj; // ebx
  int v49; // eax
  const char *v50; // edx
  const char *v51; // ebx
  const char *v52; // ebx
  size_t v53; // edi
  const char *kk; // ebx
  int v55; // eax
  const char *v56; // edx
  const char *v57; // ebx
  const char *v58; // ebx
  size_t v59; // edi
  const char *mm; // ebx
  int v61; // eax
  const char *v62; // edx
  const char *v63; // ebx
  const char *v64; // ebx
  size_t v65; // edi
  const char *nn; // ebx
  int v67; // eax
  const char *v68; // edx
  const char *v69; // ebx
  int v70; // edi
  int v71; // eax
  const char *v72; // ebx
  char *__s1; // [esp+Ch] [ebp-24h]
  __int32 v74; // [esp+10h] [ebp-20h]
  int v75; // [esp+14h] [ebp-1Ch]
  int v76; // [esp+18h] [ebp-18h]
  __int32 v77; // [esp+1Ch] [ebp-14h]
  __int32 v78; // [esp+20h] [ebp-10h]
  __int32 v79; // [esp+24h] [ebp-Ch]
  char *v80; // [esp+28h] [ebp-8h] BYREF
  char *__endptr; // [esp+2Ch] [ebp-4h] BYREF

  self->_displayModeCount = a4; /*0x1c43ee*/
  self->_displayModes = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)a3; /*0x1c43f7*/
  if ( a6 ) /*0x1c43ff*/
  {
    __s1 = (char *)a6; /*0x1c446c*/
  }
  else
  {
    v6 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c4413*/
    v7 = objc_msgSend(v6, sel_configTable); /*0x1c441c*/
    v8 = v7; /*0x1c4421*/
    if ( !v7 ) /*0x1c4428*/
      return -1; /*0x1c4428*/
    __s1 = (char *)objc_msgSend(v7, sel_valueForStringKey_, "Display Mode"); /*0x1c443c*/
    if ( !__s1 ) /*0x1c4444*/
    {
      __s1 = (char *)objc_msgSend(v8, sel_valueForStringKey_, "DisplayMode"); /*0x1c4458*/
      if ( !__s1 ) /*0x1c4460*/
        return -1; /*0x1c4460*/
    }
  }
  v79 = 0; /*0x1c446f*/
  v78 = 0; /*0x1c4476*/
  v10 = __s1; /*0x1c447d*/
  v11 = strlen("Width:"); /*0x1c4493*/
  if ( *__s1 ) /*0x1c4496*/
  {
    while ( strncmp(v10, "Width:", v11) ) /*0x1c44ad*/
    {
      if ( !*++v10 ) /*0x1c44d5*/
        goto LABEL_18; /*0x1c44d8*/
    }
    for ( i = &v10[v11]; ; ++i ) /*0x1c44af*/
    {
      v13 = *i; /*0x1c44bf*/
      if ( !*i || v13 != 32 && v13 != 9 ) /*0x1c44bc*/
        break; /*0x1c44bc*/
    }
    v14 = nullptr; /*0x1c44c6*/
    if ( *i ) /*0x1c44bf*/
      v14 = i; /*0x1c44cc*/
    v15 = v14; /*0x1c44ce*/
  }
  else
  {
LABEL_18:
    v15 = nullptr; /*0x1c44da*/
  }
  if ( v15 ) /*0x1c44de*/
    v79 = strtol(v15, nullptr, 10); /*0x1c44ea*/
  v16 = __s1; /*0x1c44f0*/
  v17 = strlen("Height:"); /*0x1c4506*/
  if ( *__s1 ) /*0x1c4509*/
  {
    while ( strncmp(v16, "Height:", v17) ) /*0x1c4521*/
    {
      if ( !*++v16 ) /*0x1c4549*/
        goto LABEL_32; /*0x1c454c*/
    }
    for ( j = &v16[v17]; ; ++j ) /*0x1c4523*/
    {
      v19 = *j; /*0x1c4533*/
      if ( !*j || v19 != 32 && v19 != 9 ) /*0x1c4530*/
        break; /*0x1c4530*/
    }
    v20 = nullptr; /*0x1c453a*/
    if ( *j ) /*0x1c4533*/
      v20 = j; /*0x1c4540*/
    v21 = v20; /*0x1c4542*/
  }
  else
  {
LABEL_32:
    v21 = nullptr; /*0x1c454e*/
  }
  if ( v21 ) /*0x1c4552*/
    v78 = strtol(v21, nullptr, 10); /*0x1c455e*/
  v22 = __s1; /*0x1c4564*/
  v23 = strlen("Refresh:"); /*0x1c457a*/
  if ( *__s1 ) /*0x1c457d*/
  {
    while ( strncmp(v22, "Refresh:", v23) ) /*0x1c4595*/
    {
      if ( !*++v22 ) /*0x1c45bd*/
        goto LABEL_46; /*0x1c45c0*/
    }
    for ( k = &v22[v23]; ; ++k ) /*0x1c4597*/
    {
      v25 = *k; /*0x1c45a7*/
      if ( !*k || v25 != 32 && v25 != 9 ) /*0x1c45a4*/
        break; /*0x1c45a4*/
    }
    v26 = nullptr; /*0x1c45ae*/
    if ( *k ) /*0x1c45a7*/
      v26 = k; /*0x1c45b4*/
    v27 = v26; /*0x1c45b6*/
  }
  else
  {
LABEL_46:
    v27 = nullptr; /*0x1c45c2*/
  }
  if ( !v27 ) /*0x1c45c6*/
    return -1; /*0x1c45c6*/
  v74 = strtol(v27, nullptr, 10); /*0x1c45d6*/
  v28 = __s1; /*0x1c45d9*/
  v29 = strlen("ColorSpace:"); /*0x1c45f2*/
  if ( *__s1 ) /*0x1c45f5*/
  {
    while ( strncmp(v28, "ColorSpace:", v29) ) /*0x1c460d*/
    {
      if ( !*++v28 ) /*0x1c4635*/
        goto LABEL_59; /*0x1c4638*/
    }
    for ( m = &v28[v29]; ; ++m ) /*0x1c460f*/
    {
      v31 = *m; /*0x1c461f*/
      if ( !*m || v31 != 32 && v31 != 9 ) /*0x1c461c*/
        break; /*0x1c461c*/
    }
    v32 = nullptr; /*0x1c4626*/
    if ( *m ) /*0x1c461f*/
      v32 = m; /*0x1c462c*/
    v33 = v32; /*0x1c462e*/
  }
  else
  {
LABEL_59:
    v33 = nullptr; /*0x1c463a*/
  }
  if ( !v33 ) /*0x1c463e*/
    return -1; /*0x1c463e*/
  if ( !strncmp(v33, "BW:2", 4u) ) /*0x1c464c*/
  {
    v76 = 0; /*0x1c4658*/
    v75 = 0; /*0x1c465f*/
  }
  else if ( !strncmp(v33, "BW:8", 4u) ) /*0x1c4674*/
  {
    v76 = 1; /*0x1c4680*/
    v75 = 1; /*0x1c4687*/
  }
  else
  {
    if ( !strncmp(v33, "RGB:256/8", 9u) ) /*0x1c469c*/
    {
      v76 = 1; /*0x1c46a8*/
    }
    else if ( !strncmp(v33, "RGB:444/16", 0xAu) ) /*0x1c46bc*/
    {
      v76 = 2; /*0x1c46c8*/
    }
    else if ( !strncmp(v33, "RGB:555/16", 0xAu) ) /*0x1c46dc*/
    {
      v76 = 3; /*0x1c46e8*/
    }
    else
    {
      if ( strncmp(v33, "RGB:888/32", 0xAu) ) /*0x1c46fc*/
        return -1; /*0x1c4467*/
      v76 = 4; /*0x1c470c*/
    }
    v75 = 2; /*0x1c4713*/
  }
  v34 = __s1; /*0x1c471a*/
  v35 = strlen("Resolution:"); /*0x1c4730*/
  if ( *__s1 ) /*0x1c4733*/
  {
    while ( strncmp(v34, "Resolution:", v35) ) /*0x1c4749*/
    {
      if ( !*++v34 ) /*0x1c4771*/
        goto LABEL_85; /*0x1c4774*/
    }
    for ( n = &v34[v35]; ; ++n ) /*0x1c474b*/
    {
      v37 = *n; /*0x1c475b*/
      if ( !*n || v37 != 32 && v37 != 9 ) /*0x1c4758*/
        break; /*0x1c4758*/
    }
    v38 = nullptr; /*0x1c4762*/
    if ( *n ) /*0x1c475b*/
      v38 = n; /*0x1c4768*/
    v39 = v38; /*0x1c476a*/
  }
  else
  {
LABEL_85:
    v39 = nullptr; /*0x1c4776*/
  }
  if ( v39 ) /*0x1c477a*/
  {
    v79 = strtol(v39, &__endptr, 10); /*0x1c4788*/
    v78 = strtol(__endptr + 1, nullptr, 10); /*0x1c4799*/
  }
  if ( !v78 || !v79 ) /*0x1c47ad*/
    return -1; /*0x1c47ad*/
  v40 = __s1; /*0x1c47b3*/
  v41 = strlen("Screen:"); /*0x1c47c9*/
  if ( *__s1 ) /*0x1c47cc*/
  {
    while ( strncmp(v40, "Screen:", v41) ) /*0x1c47e5*/
    {
      if ( !*++v40 ) /*0x1c480d*/
        goto LABEL_101; /*0x1c4810*/
    }
    for ( ii = &v40[v41]; ; ++ii ) /*0x1c47e7*/
    {
      v43 = *ii; /*0x1c47f7*/
      if ( !*ii || v43 != 32 && v43 != 9 ) /*0x1c47f4*/
        break; /*0x1c47f4*/
    }
    v44 = nullptr; /*0x1c47fe*/
    if ( *ii ) /*0x1c47f7*/
      v44 = ii; /*0x1c4804*/
    v45 = v44; /*0x1c4806*/
  }
  else
  {
LABEL_101:
    v45 = nullptr; /*0x1c4812*/
  }
  if ( v45 ) /*0x1c4816*/
  {
    strtol(v45, &v80, 10); /*0x1c481f*/
    strtol(v80 + 1, nullptr, 10); /*0x1c482d*/
  }
  v46 = __s1; /*0x1c4835*/
  v47 = strlen("Memory:"); /*0x1c484b*/
  if ( *__s1 ) /*0x1c484e*/
  {
    while ( strncmp(v46, "Memory:", v47) ) /*0x1c4865*/
    {
      if ( !*++v46 ) /*0x1c488d*/
        goto LABEL_115; /*0x1c4890*/
    }
    for ( jj = &v46[v47]; ; ++jj ) /*0x1c4867*/
    {
      v49 = *jj; /*0x1c4877*/
      if ( !*jj || v49 != 32 && v49 != 9 ) /*0x1c4874*/
        break; /*0x1c4874*/
    }
    v50 = nullptr; /*0x1c487e*/
    if ( *jj ) /*0x1c4877*/
      v50 = jj; /*0x1c4884*/
    v51 = v50; /*0x1c4886*/
  }
  else
  {
LABEL_115:
    v51 = nullptr; /*0x1c4892*/
  }
  if ( v51 ) /*0x1c4896*/
    strtol(v51, nullptr, 10); /*0x1c489d*/
  v52 = __s1; /*0x1c48a5*/
  v53 = strlen("RAMDAC:"); /*0x1c48bb*/
  if ( *__s1 ) /*0x1c48be*/
  {
    while ( strncmp(v52, "RAMDAC:", v53) ) /*0x1c48d5*/
    {
      if ( !*++v52 ) /*0x1c48fd*/
        goto LABEL_129; /*0x1c4900*/
    }
    for ( kk = &v52[v53]; ; ++kk ) /*0x1c48d7*/
    {
      v55 = *kk; /*0x1c48e7*/
      if ( !*kk || v55 != 32 && v55 != 9 ) /*0x1c48e4*/
        break; /*0x1c48e4*/
    }
    v56 = nullptr; /*0x1c48ee*/
    if ( *kk ) /*0x1c48e7*/
      v56 = kk; /*0x1c48f4*/
    v57 = v56; /*0x1c48f6*/
  }
  else
  {
LABEL_129:
    v57 = nullptr; /*0x1c4902*/
  }
  if ( v57 ) /*0x1c4906*/
    strtol(v57, nullptr, 10); /*0x1c490d*/
  v58 = __s1; /*0x1c4915*/
  v59 = strlen("Sync:"); /*0x1c492b*/
  if ( *__s1 ) /*0x1c492e*/
  {
    while ( strncmp(v58, "Sync:", v59) ) /*0x1c4945*/
    {
      if ( !*++v58 ) /*0x1c496d*/
        goto LABEL_143; /*0x1c4970*/
    }
    for ( mm = &v58[v59]; ; ++mm ) /*0x1c4947*/
    {
      v61 = *mm; /*0x1c4957*/
      if ( !*mm || v61 != 32 && v61 != 9 ) /*0x1c4954*/
        break; /*0x1c4954*/
    }
    v62 = nullptr; /*0x1c495e*/
    if ( *mm ) /*0x1c4957*/
      v62 = mm; /*0x1c4964*/
    v63 = v62; /*0x1c4966*/
  }
  else
  {
LABEL_143:
    v63 = nullptr; /*0x1c4972*/
  }
  if ( v63 ) /*0x1c4976*/
    strtol(v63, nullptr, 10); /*0x1c497d*/
  v77 = 0; /*0x1c4985*/
  v64 = __s1; /*0x1c498c*/
  v65 = strlen("Available:"); /*0x1c49a2*/
  if ( *__s1 ) /*0x1c49a5*/
  {
    while ( strncmp(v64, "Available:", v65) ) /*0x1c49bd*/
    {
      if ( !*++v64 ) /*0x1c49e5*/
        goto LABEL_157; /*0x1c49e8*/
    }
    for ( nn = &v64[v65]; ; ++nn ) /*0x1c49bf*/
    {
      v67 = *nn; /*0x1c49cf*/
      if ( !*nn || v67 != 32 && v67 != 9 ) /*0x1c49cc*/
        break; /*0x1c49cc*/
    }
    v68 = nullptr; /*0x1c49d6*/
    if ( *nn ) /*0x1c49cf*/
      v68 = nn; /*0x1c49dc*/
    v69 = v68; /*0x1c49de*/
  }
  else
  {
LABEL_157:
    v69 = nullptr; /*0x1c49ea*/
  }
  if ( v69 ) /*0x1c49ee*/
    v77 = strtol(v69, nullptr, 10); /*0x1c49fa*/
  v70 = 0; /*0x1c4a00*/
  if ( a4 <= 0 )
  {
LABEL_179:
    IOLog((int)"Display: Requested mode is not available.\n");
    return -1; /*0x1c4b0d*/
  }
  else
  {
    v71 = 0; /*0x1c4a0b*/
    while ( a5 && !a5[v70] /*0x1c4a6a*/
         || v77
         || a3[v71].var0 != v79
         || a3[v71].var1 != v78
         || a3[v71].var7 != v75
         || a3[v71].var6 != v76
         || a3[v71].var4 != v74 )
    {
      ++v71; /*0x1c4af4*/
      if ( a4 <= ++v70 ) /*0x1c4afd*/
        goto LABEL_179; /*0x1c4afd*/
    }
    switch ( v76 ) /*0x1c4a79*/
    {
      case 0: /*0x1c4a79*/
        v72 = "BW:2"; /*0x1c4a94*/
        break; /*0x1c4a99*/
      case 1: /*0x1c4a79*/
        v72 = "BW:8"; /*0x1c4a9c*/
        if ( v75 == 2 ) /*0x1c4aa5*/
          v72 = "RGB:256/8"; /*0x1c4aa7*/
        break; /*0x1c4aac*/
      case 2: /*0x1c4a79*/
        v72 = "RGB:444/16"; /*0x1c4ab0*/
        break; /*0x1c4ab5*/
      case 3: /*0x1c4a79*/
        v72 = "RGB:555/16"; /*0x1c4ab8*/
        break; /*0x1c4abd*/
      case 4: /*0x1c4a79*/
        v72 = "RGB:888/32"; /*0x1c4ac0*/
        break; /*0x1c4ac0*/
    }
    IOLog((int)"Display: Mode selected: %d x %d @ %d Hz (%s)\n", v79, v78, v74, v72);
    self->_currentDisplayMode = v70; /*0x1c4ae7*/
    return v70; /*0x1c4aed*/
  }
}
