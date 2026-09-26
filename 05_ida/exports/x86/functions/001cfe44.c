/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cfe44. */
void _objcInit()
{
  _DWORD *v0; // eax
  void *v1; // esi
  size_t i; // ebx
  size_t j; // ebx
  size_t k; // edi
  int *m; // esi
  int v6; // edx
  int v7; // ebx
  size_t n; // edi
  size_t ii; // edi
  int v10; // [esp+Ch] [ebp-4h]

  dword_1E5600 = sub_1CF3C0(); /*0x1cfe52*/
  v0 = getmachheaders(); /*0x1cfe57*/
  v1 = v0; /*0x1cfe5c*/
  if ( v0 ) /*0x1cfe60*/
  {
    dword_1E55F8 = _objc_headerVector(v0); /*0x1cfe68*/
    for ( i = 0; _nel > i; ++i ) /*0x1cfe78*/
      sub_1CF9F4((_DWORD *)dword_1E55F8 + 6 * i); /*0x1cfe89*/
    for ( j = 0; _nel > j; ++j ) /*0x1cfea2*/
      sub_1CFFC0((char *)dword_1E55F8 + 24 * j); /*0x1cfeb1*/
    free(v1); /*0x1cfec3*/
  }
  for ( k = 0; _nel > k; ++k ) /*0x1cfed3*/
  {
    v10 = *((_DWORD *)dword_1E55F8 + 6 * k + 2); /*0x1cfeec*/
    for ( m = *((int **)dword_1E55F8 + 6 * k + 1); v10; m += 4 ) /*0x1cfef5*/
    {
      v6 = m[3]; /*0x1cfefb*/
      v7 = 0; /*0x1cfefd*/
      if ( *(_WORD *)(v6 + 8) ) /*0x1cfeff*/
      {
        do /*0x1cff22*/
        {
          _class_install_relationships(*(int **)(v6 + 4 * v7++ + 12), *m); /*0x1cff10*/
          v6 = m[3]; /*0x1cff19*/
        }
        while ( v7 < *(unsigned __int16 *)(v6 + 8) ); /*0x1cff22*/
      }
      --v10; /*0x1cff24*/
    }
    sub_1CF4FC((int)dword_1E55F8 + 24 * k); /*0x1cff43*/
    sub_1CF570((int)dword_1E55F8 + 24 * k); /*0x1cff4f*/
  }
  for ( n = 0; _nel > n; ++n ) /*0x1cff6c*/
    sub_1CF5C0((int)dword_1E55F8 + 24 * n); /*0x1cff7d*/
  for ( ii = 0; _nel > ii; ++ii ) /*0x1cff96*/
    sub_1CFD28((int)dword_1E55F8 + 24 * ii); /*0x1cffa5*/
}
