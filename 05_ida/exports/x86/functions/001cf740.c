/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf740. */
_DWORD *__cdecl _objc_headerVector(_DWORD *a1)
{
  int v2; // ebx
  int zone; // ebx
  int v4; // eax
  _DWORD *v5; // edi
  size_t i; // ebx
  int v7; // esi
  int v8; // eax
  size_t v9; // [esp-4h] [ebp-18h]
  uint32_t v10; // [esp+10h] [ebp-4h] BYREF

  if ( dword_1E55F8 ) /*0x1cf750*/
    return dword_1E55F8; /*0x1cf752*/
  v2 = 0; /*0x1cf75c*/
  if ( *a1 ) /*0x1cf761*/
  {
    do /*0x1cf772*/
    {
      ++_nel; /*0x1cf768*/
      ++v2; /*0x1cf76e*/
    }
    while ( a1[v2] ); /*0x1cf772*/
  }
  zone = _objc_create_zone(); /*0x1cf77d*/
  v9 = 24 * _nel; /*0x1cf78a*/
  v4 = _objc_create_zone(); /*0x1cf78b*/
  v5 = (_DWORD *)(*(int (__cdecl **)(int, size_t))(zone + 4))(v4, v9); /*0x1cf796*/
  if ( !v5 ) /*0x1cf79d*/
    _objc_fatal("unable to allocate module vector"); /*0x1cf7a4*/
  for ( i = 0; _nel > i; ++i ) /*0x1cf7b4*/
  {
    v7 = 6 * i; /*0x1cf7c3*/
    v5[v7] = a1[i]; /*0x1cf7d0*/
    v5[v7 + 4] = 0; /*0x1cf7d3*/
    v5[v7 + 1] = getsectdatafromheader((const mach_header *)a1[i], "__OBJC", "__module_info", &v10); /*0x1cf7f5*/
    v5[v7 + 2] = v10 >> 4; /*0x1cf7ff*/
    v5[v7 + 3] = getsectdatafromheader((const mach_header *)a1[i], "__OBJC", "__runtime_setup", &v10); /*0x1cf81d*/
    v8 = sub_1CF6B0(a1[i]); /*0x1cf82b*/
    if ( v8 ) /*0x1cf835*/
      v5[v7 + 5] = *(_DWORD *)(v8 + 36); /*0x1cf83a*/
    else
      v5[6 * i + 5] = 0; /*0x1cf843*/
  }
  qsort(v5, _nel, 0x18u, (int (__cdecl *)(const void *, const void *))sub_1CF6FC); /*0x1cf867*/
  return v5; /*0x1cf871*/
}
