/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c58bc. */
int __cdecl -[IOSVGADisplay selectMode:count:valid:](
        IOSVGADisplay *self,
        SEL a2,
        const $514E7C50D28E54AB164B6500F83867A3 *a3,
        int a4,
        const char *a5)
{
  id v5; // eax
  id v6; // eax
  void *v7; // ebx
  const char *v8; // ebx
  size_t v9; // edi
  const char *i; // ebx
  int v11; // eax
  const char *v12; // edx
  const char *v13; // ebx
  const char *v14; // ebx
  size_t v15; // edi
  const char *j; // ebx
  int v17; // eax
  const char *v18; // edx
  const char *v19; // ebx
  const char *v20; // ebx
  size_t v21; // edi
  const char *k; // ebx
  int v23; // eax
  const char *v24; // edx
  const char *v25; // ebx
  const char *v26; // ebx
  size_t v27; // edi
  const char *m; // ebx
  int v29; // eax
  const char *v30; // edx
  const char *v31; // ebx
  const char *v32; // ebx
  size_t v33; // edi
  const char *n; // ebx
  int v35; // eax
  const char *v36; // edx
  const char *v37; // ebx
  const char *v39; // ebx
  size_t v40; // edi
  const char *ii; // ebx
  int v42; // eax
  const char *v43; // edx
  const char *v44; // ebx
  const char *v45; // ebx
  size_t v46; // edi
  const char *jj; // ebx
  int v48; // eax
  const char *v49; // edx
  const char *v50; // ebx
  const char *v51; // ebx
  size_t v52; // edi
  const char *kk; // ebx
  int v54; // eax
  const char *v55; // edx
  const char *v56; // ebx
  const char *v57; // ebx
  size_t v58; // edi
  const char *mm; // ebx
  int v60; // eax
  const char *v61; // edx
  const char *v62; // ebx
  const char *v63; // ebx
  size_t v64; // edi
  const char *nn; // ebx
  int v66; // eax
  const char *v67; // edx
  const char *v68; // ebx
  int v69; // edi
  int v70; // eax
  const char *v71; // ebx
  char *__s1; // [esp+Ch] [ebp-24h]
  __int32 v73; // [esp+10h] [ebp-20h]
  int v74; // [esp+14h] [ebp-1Ch]
  int v75; // [esp+18h] [ebp-18h]
  __int32 v76; // [esp+1Ch] [ebp-14h]
  __int32 v77; // [esp+20h] [ebp-10h]
  __int32 v78; // [esp+24h] [ebp-Ch]
  char *v79; // [esp+28h] [ebp-8h] BYREF
  char *__endptr; // [esp+2Ch] [ebp-4h] BYREF

  v5 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c58d7*/
  v6 = objc_msgSend(v5, sel_configTable); /*0x1c58e0*/
  v7 = v6; /*0x1c58e5*/
  if ( !v6 ) /*0x1c58ec*/
    return -1; /*0x1c58ec*/
  __s1 = (char *)objc_msgSend(v6, sel_valueForStringKey_, "Display Mode"); /*0x1c5904*/
  if ( !__s1 ) /*0x1c590c*/
  {
    __s1 = (char *)objc_msgSend(v7, sel_valueForStringKey_, "DisplayMode"); /*0x1c5920*/
    if ( !__s1 ) /*0x1c5928*/
      return -1; /*0x1c5928*/
  }
  v78 = 0; /*0x1c592e*/
  v77 = 0; /*0x1c5935*/
  v8 = __s1; /*0x1c593c*/
  v9 = strlen("Width:"); /*0x1c5952*/
  if ( *__s1 ) /*0x1c5955*/
  {
    while ( strncmp(v8, "Width:", v9) ) /*0x1c596d*/
    {
      if ( !*++v8 ) /*0x1c5995*/
        goto LABEL_15; /*0x1c5998*/
    }
    for ( i = &v8[v9]; ; ++i ) /*0x1c596f*/
    {
      v11 = *i; /*0x1c597f*/
      if ( !*i || v11 != 32 && v11 != 9 ) /*0x1c597c*/
        break; /*0x1c597c*/
    }
    v12 = nullptr; /*0x1c5986*/
    if ( *i ) /*0x1c597f*/
      v12 = i; /*0x1c598c*/
    v13 = v12; /*0x1c598e*/
  }
  else
  {
LABEL_15:
    v13 = nullptr; /*0x1c599a*/
  }
  if ( v13 ) /*0x1c599e*/
    v78 = strtol(v13, nullptr, 10); /*0x1c59aa*/
  v14 = __s1; /*0x1c59b0*/
  v15 = strlen("Height:"); /*0x1c59c6*/
  if ( *__s1 ) /*0x1c59c9*/
  {
    while ( strncmp(v14, "Height:", v15) ) /*0x1c59e1*/
    {
      if ( !*++v14 ) /*0x1c5a09*/
        goto LABEL_29; /*0x1c5a0c*/
    }
    for ( j = &v14[v15]; ; ++j ) /*0x1c59e3*/
    {
      v17 = *j; /*0x1c59f3*/
      if ( !*j || v17 != 32 && v17 != 9 ) /*0x1c59f0*/
        break; /*0x1c59f0*/
    }
    v18 = nullptr; /*0x1c59fa*/
    if ( *j ) /*0x1c59f3*/
      v18 = j; /*0x1c5a00*/
    v19 = v18; /*0x1c5a02*/
  }
  else
  {
LABEL_29:
    v19 = nullptr; /*0x1c5a0e*/
  }
  if ( v19 ) /*0x1c5a12*/
    v77 = strtol(v19, nullptr, 10); /*0x1c5a1e*/
  v20 = __s1; /*0x1c5a24*/
  v21 = strlen("Refresh:"); /*0x1c5a3a*/
  if ( *__s1 ) /*0x1c5a3d*/
  {
    while ( strncmp(v20, "Refresh:", v21) ) /*0x1c5a55*/
    {
      if ( !*++v20 ) /*0x1c5a7d*/
        goto LABEL_43; /*0x1c5a80*/
    }
    for ( k = &v20[v21]; ; ++k ) /*0x1c5a57*/
    {
      v23 = *k; /*0x1c5a67*/
      if ( !*k || v23 != 32 && v23 != 9 ) /*0x1c5a64*/
        break; /*0x1c5a64*/
    }
    v24 = nullptr; /*0x1c5a6e*/
    if ( *k ) /*0x1c5a67*/
      v24 = k; /*0x1c5a74*/
    v25 = v24; /*0x1c5a76*/
  }
  else
  {
LABEL_43:
    v25 = nullptr; /*0x1c5a82*/
  }
  if ( !v25 ) /*0x1c5a86*/
    return -1; /*0x1c5a86*/
  v73 = strtol(v25, nullptr, 10); /*0x1c5a96*/
  v26 = __s1; /*0x1c5a99*/
  v27 = strlen("ColorSpace:"); /*0x1c5ab2*/
  if ( *__s1 ) /*0x1c5ab5*/
  {
    while ( strncmp(v26, "ColorSpace:", v27) ) /*0x1c5acd*/
    {
      if ( !*++v26 ) /*0x1c5af5*/
        goto LABEL_56; /*0x1c5af8*/
    }
    for ( m = &v26[v27]; ; ++m ) /*0x1c5acf*/
    {
      v29 = *m; /*0x1c5adf*/
      if ( !*m || v29 != 32 && v29 != 9 ) /*0x1c5adc*/
        break; /*0x1c5adc*/
    }
    v30 = nullptr; /*0x1c5ae6*/
    if ( *m ) /*0x1c5adf*/
      v30 = m; /*0x1c5aec*/
    v31 = v30; /*0x1c5aee*/
  }
  else
  {
LABEL_56:
    v31 = nullptr; /*0x1c5afa*/
  }
  if ( !v31 ) /*0x1c5afe*/
    return -1; /*0x1c5afe*/
  if ( !strncmp(v31, "BW:2", 4u) ) /*0x1c5b0c*/
  {
    v75 = 0; /*0x1c5b18*/
    v74 = 0; /*0x1c5b1f*/
  }
  else if ( !strncmp(v31, "BW:8", 4u) ) /*0x1c5b34*/
  {
    v75 = 1; /*0x1c5b40*/
    v74 = 1; /*0x1c5b47*/
  }
  else
  {
    if ( !strncmp(v31, "RGB:256/8", 9u) ) /*0x1c5b5c*/
    {
      v75 = 1; /*0x1c5b68*/
    }
    else if ( !strncmp(v31, "RGB:444/16", 0xAu) ) /*0x1c5b7c*/
    {
      v75 = 2; /*0x1c5b88*/
    }
    else if ( !strncmp(v31, "RGB:555/16", 0xAu) ) /*0x1c5b9c*/
    {
      v75 = 3; /*0x1c5ba8*/
    }
    else
    {
      if ( strncmp(v31, "RGB:888/32", 0xAu) ) /*0x1c5bbc*/
        return -1; /*0x1c5c70*/
      v75 = 4; /*0x1c5bcc*/
    }
    v74 = 2; /*0x1c5bd3*/
  }
  v32 = __s1; /*0x1c5bda*/
  v33 = strlen("Resolution:"); /*0x1c5bf0*/
  if ( *__s1 ) /*0x1c5bf3*/
  {
    while ( strncmp(v32, "Resolution:", v33) ) /*0x1c5c09*/
    {
      if ( !*++v32 ) /*0x1c5c31*/
        goto LABEL_82; /*0x1c5c34*/
    }
    for ( n = &v32[v33]; ; ++n ) /*0x1c5c0b*/
    {
      v35 = *n; /*0x1c5c1b*/
      if ( !*n || v35 != 32 && v35 != 9 ) /*0x1c5c18*/
        break; /*0x1c5c18*/
    }
    v36 = nullptr; /*0x1c5c22*/
    if ( *n ) /*0x1c5c1b*/
      v36 = n; /*0x1c5c28*/
    v37 = v36; /*0x1c5c2a*/
  }
  else
  {
LABEL_82:
    v37 = nullptr; /*0x1c5c36*/
  }
  if ( v37 ) /*0x1c5c3a*/
  {
    v78 = strtol(v37, &__endptr, 10); /*0x1c5c48*/
    v77 = strtol(__endptr + 1, nullptr, 10); /*0x1c5c59*/
  }
  if ( !v77 || !v78 ) /*0x1c5c69*/
    return -1; /*0x1c5c69*/
  v39 = __s1; /*0x1c5c78*/
  v40 = strlen("Screen:"); /*0x1c5c8e*/
  if ( *__s1 ) /*0x1c5c91*/
  {
    while ( strncmp(v39, "Screen:", v40) ) /*0x1c5ca9*/
    {
      if ( !*++v39 ) /*0x1c5cd1*/
        goto LABEL_99; /*0x1c5cd4*/
    }
    for ( ii = &v39[v40]; ; ++ii ) /*0x1c5cab*/
    {
      v42 = *ii; /*0x1c5cbb*/
      if ( !*ii || v42 != 32 && v42 != 9 ) /*0x1c5cb8*/
        break; /*0x1c5cb8*/
    }
    v43 = nullptr; /*0x1c5cc2*/
    if ( *ii ) /*0x1c5cbb*/
      v43 = ii; /*0x1c5cc8*/
    v44 = v43; /*0x1c5cca*/
  }
  else
  {
LABEL_99:
    v44 = nullptr; /*0x1c5cd6*/
  }
  if ( v44 ) /*0x1c5cda*/
  {
    strtol(v44, &v79, 10); /*0x1c5ce3*/
    v77 = strtol(v79 + 1, nullptr, 10); /*0x1c5cf6*/
  }
  v45 = __s1; /*0x1c5cfc*/
  v46 = strlen("Memory:"); /*0x1c5d12*/
  if ( *__s1 ) /*0x1c5d15*/
  {
    while ( strncmp(v45, "Memory:", v46) ) /*0x1c5d2d*/
    {
      if ( !*++v45 ) /*0x1c5d55*/
        goto LABEL_113; /*0x1c5d58*/
    }
    for ( jj = &v45[v46]; ; ++jj ) /*0x1c5d2f*/
    {
      v48 = *jj; /*0x1c5d3f*/
      if ( !*jj || v48 != 32 && v48 != 9 ) /*0x1c5d3c*/
        break; /*0x1c5d3c*/
    }
    v49 = nullptr; /*0x1c5d46*/
    if ( *jj ) /*0x1c5d3f*/
      v49 = jj; /*0x1c5d4c*/
    v50 = v49; /*0x1c5d4e*/
  }
  else
  {
LABEL_113:
    v50 = nullptr; /*0x1c5d5a*/
  }
  if ( v50 ) /*0x1c5d5e*/
    strtol(v50, nullptr, 10); /*0x1c5d65*/
  v51 = __s1; /*0x1c5d6d*/
  v52 = strlen("RAMDAC:"); /*0x1c5d83*/
  if ( *__s1 ) /*0x1c5d86*/
  {
    while ( strncmp(v51, "RAMDAC:", v52) ) /*0x1c5d9d*/
    {
      if ( !*++v51 ) /*0x1c5dc5*/
        goto LABEL_127; /*0x1c5dc8*/
    }
    for ( kk = &v51[v52]; ; ++kk ) /*0x1c5d9f*/
    {
      v54 = *kk; /*0x1c5daf*/
      if ( !*kk || v54 != 32 && v54 != 9 ) /*0x1c5dac*/
        break; /*0x1c5dac*/
    }
    v55 = nullptr; /*0x1c5db6*/
    if ( *kk ) /*0x1c5daf*/
      v55 = kk; /*0x1c5dbc*/
    v56 = v55; /*0x1c5dbe*/
  }
  else
  {
LABEL_127:
    v56 = nullptr; /*0x1c5dca*/
  }
  if ( v56 ) /*0x1c5dce*/
    strtol(v56, nullptr, 10); /*0x1c5dd5*/
  v57 = __s1; /*0x1c5ddd*/
  v58 = strlen("Sync:"); /*0x1c5df3*/
  if ( *__s1 ) /*0x1c5df6*/
  {
    while ( strncmp(v57, "Sync:", v58) ) /*0x1c5e0d*/
    {
      if ( !*++v57 ) /*0x1c5e35*/
        goto LABEL_141; /*0x1c5e38*/
    }
    for ( mm = &v57[v58]; ; ++mm ) /*0x1c5e0f*/
    {
      v60 = *mm; /*0x1c5e1f*/
      if ( !*mm || v60 != 32 && v60 != 9 ) /*0x1c5e1c*/
        break; /*0x1c5e1c*/
    }
    v61 = nullptr; /*0x1c5e26*/
    if ( *mm ) /*0x1c5e1f*/
      v61 = mm; /*0x1c5e2c*/
    v62 = v61; /*0x1c5e2e*/
  }
  else
  {
LABEL_141:
    v62 = nullptr; /*0x1c5e3a*/
  }
  if ( v62 ) /*0x1c5e3e*/
    strtol(v62, nullptr, 10); /*0x1c5e45*/
  v76 = 0; /*0x1c5e4d*/
  v63 = __s1; /*0x1c5e54*/
  v64 = strlen("Available:"); /*0x1c5e6a*/
  if ( *__s1 ) /*0x1c5e6d*/
  {
    while ( strncmp(v63, "Available:", v64) ) /*0x1c5e85*/
    {
      if ( !*++v63 ) /*0x1c5ead*/
        goto LABEL_155; /*0x1c5eb0*/
    }
    for ( nn = &v63[v64]; ; ++nn ) /*0x1c5e87*/
    {
      v66 = *nn; /*0x1c5e97*/
      if ( !*nn || v66 != 32 && v66 != 9 ) /*0x1c5e94*/
        break; /*0x1c5e94*/
    }
    v67 = nullptr; /*0x1c5e9e*/
    if ( *nn ) /*0x1c5e97*/
      v67 = nn; /*0x1c5ea4*/
    v68 = v67; /*0x1c5ea6*/
  }
  else
  {
LABEL_155:
    v68 = nullptr; /*0x1c5eb2*/
  }
  if ( v68 ) /*0x1c5eb6*/
    v76 = strtol(v68, nullptr, 10); /*0x1c5ec2*/
  v69 = 0; /*0x1c5ec8*/
  if ( a4 <= 0 )
  {
LABEL_177:
    IOLog((int)"Display: Requested mode is not available.\n");
    return -1; /*0x1c5fc5*/
  }
  else
  {
    v70 = 0; /*0x1c5ed3*/
    while ( a5 && !a5[v69] /*0x1c5f32*/
         || v76
         || a3[v70].var0 != v78
         || a3[v70].var1 != v77
         || a3[v70].var7 != v74
         || a3[v70].var6 != v75
         || a3[v70].var4 != v73 )
    {
      ++v70; /*0x1c5fac*/
      if ( a4 <= ++v69 ) /*0x1c5fb5*/
        goto LABEL_177; /*0x1c5fb5*/
    }
    switch ( v75 ) /*0x1c5f3d*/
    {
      case 0: /*0x1c5f3d*/
        v71 = "BW:2"; /*0x1c5f58*/
        break; /*0x1c5f5d*/
      case 1: /*0x1c5f3d*/
        v71 = "BW:8"; /*0x1c5f60*/
        if ( v74 == 2 ) /*0x1c5f69*/
          v71 = "RGB:256/8"; /*0x1c5f6b*/
        break; /*0x1c5f70*/
      case 2: /*0x1c5f3d*/
        v71 = "RGB:444/16"; /*0x1c5f74*/
        break; /*0x1c5f79*/
      case 3: /*0x1c5f3d*/
        v71 = "RGB:555/16"; /*0x1c5f7c*/
        break; /*0x1c5f81*/
      case 4: /*0x1c5f3d*/
        v71 = "RGB:888/32"; /*0x1c5f84*/
        break; /*0x1c5f84*/
    }
    IOLog((int)"Display: Mode selected: %d x %d @ %d Hz (%s)\n", v78, v77, v73, v71);
    return v69; /*0x1c5fa8*/
  }
}
