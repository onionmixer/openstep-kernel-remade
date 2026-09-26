/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a9a8. */
void *__cdecl realloc(void *__ptr, size_t __size)
{
  size_t *v2; // esi
  size_t v3; // esi
  int k; // edx
  unsigned int v5; // eax
  _DWORD *v6; // ebx
  size_t v7; // ecx
  int v8; // edx
  unsigned int i; // eax
  size_t v11; // ecx
  int v12; // edx
  unsigned int j; // eax
  size_t v14; // [esp-4h] [ebp-14h]
  void *v15; // [esp+Ch] [ebp-4h] BYREF

  v2 = (size_t *)((char *)__ptr - 8); /*0x15a9b4*/
  if ( __ptr ) /*0x15a9bb*/
  {
    v7 = __size + 8; /*0x15aa3f*/
    v8 = 0; /*0x15aa42*/
    i = __size + 8; /*0x15aa44*/
    if ( k_zone_maxsize < __size + 8 ) /*0x15aa4c*/
      goto LABEL_32; /*0x15aa4c*/
    for ( i = k_zone_elemsize[0]; i < v7; i = k_zone_elemsize[v8] ) /*0x15aa55*/
      ++v8; /*0x15aa58*/
    if ( k_zone_maxsize < i ) /*0x15aa6a*/
    {
LABEL_32:
      if ( kmem_alloc_wired(kalloc_map, &v15, i) ) /*0x15aa90*/
        v15 = nullptr; /*0x15aa9c*/
    }
    else
    {
      v15 = (void *)zalloc(k_zone[v8]); /*0x15aa79*/
    }
    v6 = v15; /*0x15aaa3*/
    if ( v15 ) /*0x15aaa8*/
    {
      *(_DWORD *)v15 = __size + 8; /*0x15aab6*/
      if ( __size >= *v2 ) /*0x15aabd*/
        v14 = *v2; /*0x15aac8*/
      else
        v14 = __size; /*0x15aac2*/
      bcopy(__ptr, v6 + 2, v14); /*0x15aad1*/
      v11 = *v2; /*0x15aad9*/
      v12 = 0; /*0x15aadb*/
      j = *v2; /*0x15aadd*/
      if ( k_zone_maxsize < *v2 ) /*0x15aae5*/
        goto LABEL_28; /*0x15aae5*/
      for ( j = k_zone_elemsize[0]; j < v11; j = k_zone_elemsize[v12] ) /*0x15aaee*/
        ++v12; /*0x15aaf0*/
      if ( k_zone_maxsize < j ) /*0x15ab02*/
LABEL_28:
        kmem_free(kalloc_map, v2, j); /*0x15ab1d*/
      else
        zfree(k_zone[v12], v2); /*0x15ab0d*/
      return v6 + 2; /*0x15ab12*/
    }
    return nullptr; /*0x15aaac*/
  }
  v3 = __size + 8; /*0x15a9c0*/
  k = 0; /*0x15a9c3*/
  v5 = __size + 8; /*0x15a9c5*/
  if ( k_zone_maxsize >= __size + 8 ) /*0x15a9cd*/
  {
    v5 = k_zone_elemsize[0]; /*0x15a9cf*/
    for ( k = 0; v5 < v3; v5 = k_zone_elemsize[k] ) /*0x15a9d9*/
      ++k; /*0x15a9dc*/
  }
  if ( k_zone_maxsize < v5 ) /*0x15a9ee*/
  {
    if ( kmem_alloc_wired(kalloc_map, &v15, v5) ) /*0x15aa14*/
      v15 = nullptr; /*0x15aa20*/
  }
  else
  {
    v15 = (void *)zalloc(k_zone[k]); /*0x15a9fd*/
  }
  v6 = v15; /*0x15aa27*/
  if ( !v15 ) /*0x15aa2c*/
    return nullptr; /*0x15aa2c*/
  bzero(v15, v3); /*0x15aa30*/
  *v6 = v3; /*0x15aa35*/
  return v6 + 2; /*0x15ab28*/
}
