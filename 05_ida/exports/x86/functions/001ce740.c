/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ce740. */
int __cdecl objc_unregisterModule(mach_header *mhp, void (__cdecl *a2)(Class, int))
{
  char *v2; // edi
  int v3; // ebx
  Class Class; // eax
  char *v5; // edi
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // edi
  int v9; // ebx
  char *v10; // edi
  int v11; // edx
  int v12; // ebx
  char *v13; // eax
  char *v14; // eax
  int v16; // [esp-4h] [ebp-28h]
  int v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+Ch] [ebp-18h]
  int v19; // [esp+10h] [ebp-14h]
  int *v20; // [esp+10h] [ebp-14h]
  uint32_t i; // [esp+14h] [ebp-10h]
  uint32_t j; // [esp+14h] [ebp-10h]
  uint32_t v23; // [esp+14h] [ebp-10h]
  uint32_t k; // [esp+14h] [ebp-10h]
  char *v25; // [esp+18h] [ebp-Ch]
  uint32_t v26; // [esp+1Ch] [ebp-8h] BYREF
  uint32_t size; // [esp+20h] [ebp-4h] BYREF

  v2 = getsectdatafromheader(mhp, "__OBJC", "__module_info", &size); /*0x1ce760*/
  v25 = v2; /*0x1ce762*/
  for ( i = size; v2; v2 += *((_DWORD *)v2 + 1) ) /*0x1ce770*/
  {
    if ( !i ) /*0x1ce778*/
      break; /*0x1ce778*/
    v17 = *((_DWORD *)v2 + 3); /*0x1ce77d*/
    v3 = *(unsigned __int16 *)(v17 + 8); /*0x1ce780*/
    if ( v3 < v3 + *(unsigned __int16 *)(v17 + 10) ) /*0x1ce78c*/
    {
      do /*0x1ce7d5*/
      {
        v19 = *(_DWORD *)(v17 + 4 * v3 + 12); /*0x1ce797*/
        if ( a2 ) /*0x1ce79e*/
        {
          v16 = *(_DWORD *)(v17 + 4 * v3 + 12); /*0x1ce7a0*/
          Class = objc_getClass(*(const char **)(v16 + 4)); /*0x1ce7a5*/
          a2(Class, v16); /*0x1ce7b1*/
        }
        sub_1CE014(v19); /*0x1ce7ba*/
        ++v3; /*0x1ce7c2*/
        v17 = *((_DWORD *)v2 + 3); /*0x1ce7c6*/
      }
      while ( v3 < *(unsigned __int16 *)(v17 + 10) + *(unsigned __int16 *)(v17 + 8) ); /*0x1ce7d5*/
    }
    i -= *((_DWORD *)v2 + 1); /*0x1ce7da*/
  }
  v5 = v25; /*0x1ce7e2*/
  for ( j = size; v5; v5 += *((_DWORD *)v5 + 1) ) /*0x1ce7ed*/
  {
    if ( !j ) /*0x1ce7f4*/
      break; /*0x1ce7f4*/
    v6 = *((_DWORD *)v5 + 3); /*0x1ce7f9*/
    v7 = 0; /*0x1ce7fb*/
    if ( *(_WORD *)(v6 + 8) ) /*0x1ce7fd*/
    {
      do /*0x1ce835*/
      {
        v20 = *(int **)(v6 + 4 * v7 + 12); /*0x1ce808*/
        if ( a2 ) /*0x1ce80f*/
          a2((Class)v20, 0); /*0x1ce81a*/
        sub_1CDFD8(v20); /*0x1ce823*/
        ++v7; /*0x1ce82b*/
        v6 = *((_DWORD *)v5 + 3); /*0x1ce82c*/
      }
      while ( v7 < *(unsigned __int16 *)(v6 + 8) ); /*0x1ce835*/
    }
    j -= *((_DWORD *)v5 + 1); /*0x1ce83a*/
  }
  v8 = v25; /*0x1ce842*/
  v23 = size; /*0x1ce848*/
  if ( v25 ) /*0x1ce84d*/
  {
    do /*0x1ce89d*/
    {
      if ( !v23 ) /*0x1ce854*/
        break; /*0x1ce854*/
      v18 = v8[3]; /*0x1ce859*/
      v9 = *(unsigned __int16 *)(v18 + 8); /*0x1ce85c*/
      if ( v9 < v9 + *(unsigned __int16 *)(v18 + 10) ) /*0x1ce868*/
      {
        do /*0x1ce892*/
        {
          _objc_remove_category(*(_DWORD *)(v18 + 4 * v9++ + 12), *v8); /*0x1ce877*/
          v18 = v8[3]; /*0x1ce883*/
        }
        while ( v9 < *(unsigned __int16 *)(v18 + 10) + *(unsigned __int16 *)(v18 + 8) ); /*0x1ce892*/
      }
      v23 -= v8[1]; /*0x1ce897*/
      v8 = (_DWORD *)((char *)v8 + v8[1]); /*0x1ce89a*/
    }
    while ( v8 ); /*0x1ce89d*/
  }
  v10 = v25; /*0x1ce89f*/
  for ( k = size; v10; v10 += *((_DWORD *)v10 + 1) ) /*0x1ce8aa*/
  {
    if ( !k ) /*0x1ce8b0*/
      break; /*0x1ce8b0*/
    v11 = *((_DWORD *)v10 + 3); /*0x1ce8b5*/
    v12 = 0; /*0x1ce8b7*/
    if ( *(_WORD *)(v11 + 8) ) /*0x1ce8b9*/
    {
      do /*0x1ce8d7*/
      {
        _objc_removeClass(*(void **)(v11 + 4 * v12++ + 12)); /*0x1ce8c5*/
        v11 = *((_DWORD *)v10 + 3); /*0x1ce8ce*/
      }
      while ( v12 < *(unsigned __int16 *)(v11 + 8) ); /*0x1ce8d7*/
    }
    k -= *((_DWORD *)v10 + 1); /*0x1ce8dc*/
  }
  v13 = getsectdatafromheader(mhp, "__OBJC", "__meth_var_names", &v26); /*0x1ce8f6*/
  if ( v13 ) /*0x1ce902*/
    _sel_unloadSelectors(v13, &v13[v26]); /*0x1ce909*/
  v14 = getsectdatafromheader(mhp, "__OBJC", "__selector_strs", &v26); /*0x1ce923*/
  if ( v14 ) /*0x1ce92f*/
    _sel_unloadSelectors(v14, &v14[v26]); /*0x1ce936*/
  return _objc_removeHeader(mhp); /*0x1ce94a*/
}
