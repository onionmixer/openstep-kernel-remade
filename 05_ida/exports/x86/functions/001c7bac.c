/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c7bac. */
id __cdecl -[IOVPCodeDisplay getVPCodeFilename:count:](IOVPCodeDisplay *self, SEL a2, char *__dst, unsigned int *a4)
{
  id v4; // eax
  const char *v5; // ebx
  size_t v6; // edi
  const char *i; // ebx
  int v8; // eax
  const char *v9; // edx
  const char *v10; // ebx
  const char *v11; // ebx
  size_t v12; // edi
  const char *j; // ebx
  int v14; // eax
  const char *v15; // edx
  const char *v16; // ebx
  const char *v17; // ebx
  size_t v18; // edi
  const char *k; // ebx
  int v20; // eax
  const char *v21; // edx
  const char *v22; // ebx
  const char *v23; // ebx
  size_t v24; // edi
  const char *m; // ebx
  int v26; // eax
  const char *v27; // edx
  const char *v28; // ebx
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // ebx
  unsigned int v32; // edi
  const char *v34; // eax
  char *__s1; // [esp+Ch] [ebp-114h]
  __int32 v36; // [esp+10h] [ebp-110h]
  __int32 v37; // [esp+14h] [ebp-10Ch]
  __int32 v38; // [esp+18h] [ebp-108h]
  id v39; // [esp+1Ch] [ebp-104h]
  char v40[256]; // [esp+20h] [ebp-100h] BYREF

  v4 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c7bca*/
  v39 = objc_msgSend(v4, sel_configTable); /*0x1c7bd8*/
  if ( !v39 ) /*0x1c7be3*/
    return nullptr; /*0x1c7be3*/
  __s1 = (char *)objc_msgSend(v39, sel_valueForStringKey_, "Display Mode"); /*0x1c7c01*/
  v5 = __s1; /*0x1c7c07*/
  v6 = strlen("Width:"); /*0x1c7c23*/
  if ( *__s1 ) /*0x1c7c26*/
  {
    while ( strncmp(v5, "Width:", v6) ) /*0x1c7c3d*/
    {
      if ( !*++v5 ) /*0x1c7c65*/
        goto LABEL_13; /*0x1c7c68*/
    }
    for ( i = &v5[v6]; ; ++i ) /*0x1c7c3f*/
    {
      v8 = *i; /*0x1c7c4f*/
      if ( !*i || v8 != 32 && v8 != 9 ) /*0x1c7c4c*/
        break; /*0x1c7c4c*/
    }
    v9 = nullptr; /*0x1c7c56*/
    if ( *i ) /*0x1c7c4f*/
      v9 = i; /*0x1c7c5c*/
    v10 = v9; /*0x1c7c5e*/
  }
  else
  {
LABEL_13:
    v10 = nullptr; /*0x1c7c6a*/
  }
  if ( !v10 ) /*0x1c7c6e*/
    return nullptr; /*0x1c7c6e*/
  v38 = strtol(v10, nullptr, 10); /*0x1c7c7e*/
  v11 = __s1; /*0x1c7c84*/
  v12 = strlen("Height:"); /*0x1c7ca0*/
  if ( *__s1 ) /*0x1c7ca3*/
  {
    while ( strncmp(v11, "Height:", v12) ) /*0x1c7cb9*/
    {
      if ( !*++v11 ) /*0x1c7ce1*/
        goto LABEL_26; /*0x1c7ce4*/
    }
    for ( j = &v11[v12]; ; ++j ) /*0x1c7cbb*/
    {
      v14 = *j; /*0x1c7ccb*/
      if ( !*j || v14 != 32 && v14 != 9 ) /*0x1c7cc8*/
        break; /*0x1c7cc8*/
    }
    v15 = nullptr; /*0x1c7cd2*/
    if ( *j ) /*0x1c7ccb*/
      v15 = j; /*0x1c7cd8*/
    v16 = v15; /*0x1c7cda*/
  }
  else
  {
LABEL_26:
    v16 = nullptr; /*0x1c7ce6*/
  }
  if ( !v16 ) /*0x1c7cea*/
    return nullptr; /*0x1c7cea*/
  v37 = strtol(v16, nullptr, 10); /*0x1c7cfa*/
  v17 = __s1; /*0x1c7d00*/
  v18 = strlen("Refresh:"); /*0x1c7d1c*/
  if ( *__s1 ) /*0x1c7d1f*/
  {
    while ( strncmp(v17, "Refresh:", v18) ) /*0x1c7d35*/
    {
      if ( !*++v17 ) /*0x1c7d5d*/
        goto LABEL_39; /*0x1c7d60*/
    }
    for ( k = &v17[v18]; ; ++k ) /*0x1c7d37*/
    {
      v20 = *k; /*0x1c7d47*/
      if ( !*k || v20 != 32 && v20 != 9 ) /*0x1c7d44*/
        break; /*0x1c7d44*/
    }
    v21 = nullptr; /*0x1c7d4e*/
    if ( *k ) /*0x1c7d47*/
      v21 = k; /*0x1c7d54*/
    v22 = v21; /*0x1c7d56*/
  }
  else
  {
LABEL_39:
    v22 = nullptr; /*0x1c7d62*/
  }
  if ( !v22 ) /*0x1c7d66*/
    return nullptr; /*0x1c7d66*/
  v36 = strtol(v22, nullptr, 10); /*0x1c7d76*/
  v23 = __s1; /*0x1c7d7c*/
  v24 = strlen("ColorSpace:"); /*0x1c7d98*/
  if ( *__s1 ) /*0x1c7d9b*/
  {
    while ( strncmp(v23, "ColorSpace:", v24) ) /*0x1c7db1*/
    {
      if ( !*++v23 ) /*0x1c7dd9*/
        goto LABEL_52; /*0x1c7ddc*/
    }
    for ( m = &v23[v24]; ; ++m ) /*0x1c7db3*/
    {
      v26 = *m; /*0x1c7dc3*/
      if ( !*m || v26 != 32 && v26 != 9 ) /*0x1c7dc0*/
        break; /*0x1c7dc0*/
    }
    v27 = nullptr; /*0x1c7dca*/
    if ( *m ) /*0x1c7dc3*/
      v27 = m; /*0x1c7dd0*/
    v28 = v27; /*0x1c7dd2*/
  }
  else
  {
LABEL_52:
    v28 = nullptr; /*0x1c7dde*/
  }
  if ( !v28 ) /*0x1c7de2*/
    return nullptr; /*0x1c7de2*/
  if ( !strncmp(v28, "BW:2", 4u) ) /*0x1c7df0*/
  {
    v29 = "BW:2"; /*0x1c7dfc*/
  }
  else if ( !strncmp(v28, "BW:8", 4u) ) /*0x1c7e0c*/
  {
    v29 = "BW:8"; /*0x1c7e18*/
  }
  else if ( !strncmp(v28, "RGB:444/16", 0xAu) ) /*0x1c7e28*/
  {
    v29 = "RGB:444/16"; /*0x1c7e34*/
  }
  else if ( !strncmp(v28, "RGB:555/16", 0xAu) ) /*0x1c7e44*/
  {
    v29 = "RGB:555/16"; /*0x1c7e50*/
  }
  else
  {
    if ( strncmp(v28, "RGB:888/32", 0xAu) ) /*0x1c7e60*/
      return nullptr; /*0x1c7f03*/
    v29 = "RGB:888/32"; /*0x1c7e70*/
  }
  sprintf(v40, "[%d x %d x %s @ %d]", v38, v37, v29, v36); /*0x1c7e97*/
  if ( self->_debug )
  {
    v30 = -[IODevice name](self, sel_name); /*0x1c7eb7*/
    IOLog((int)"%s: Searching for key `%s'.\n", v30, v40);
  }
  v31 = (const char *)objc_msgSend(v39, sel_valueForStringKey_, v40); /*0x1c7ee1*/
  if ( !v31 ) /*0x1c7ee8*/
    return nullptr; /*0x1c7ee8*/
  v32 = strlen(v31) + 1; /*0x1c7ef4*/
  if ( *a4 < v32 ) /*0x1c7eff*/
    return nullptr; /*0x1c7eff*/
  if ( self->_debug )
  {
    v34 = -[IODevice name](self, sel_name); /*0x1c7f20*/
    IOLog((int)"%s: Using vpcode from `%s'.\n", v34, v31);
  }
  *a4 = v32; /*0x1c7f39*/
  strcpy(__dst, v31); /*0x1c7f40*/
  return self; /*0x1c7f4e*/
}
