/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a910. */
void *__cdecl calloc(size_t __count, size_t __size)
{
  size_t v2; // esi
  int v3; // edx
  unsigned int i; // eax
  _DWORD *v5; // ebx
  void *v7; // [esp+8h] [ebp-4h] BYREF

  v2 = __size * __count + 8; /*0x15a91f*/
  v3 = 0; /*0x15a922*/
  i = v2; /*0x15a924*/
  if ( k_zone_maxsize >= v2 ) /*0x15a92c*/
  {
    for ( i = k_zone_elemsize[0]; i < v2; i = k_zone_elemsize[v3] ) /*0x15a935*/
      ++v3; /*0x15a938*/
  }
  if ( k_zone_maxsize < i ) /*0x15a94a*/
  {
    if ( kmem_alloc_wired(kalloc_map, &v7, i) ) /*0x15a970*/
      v7 = nullptr; /*0x15a97c*/
  }
  else
  {
    v7 = (void *)zalloc(k_zone[v3]); /*0x15a959*/
  }
  v5 = v7; /*0x15a983*/
  if ( !v7 ) /*0x15a988*/
    return nullptr; /*0x15a98a*/
  bzero(v7, v2); /*0x15a992*/
  *v5 = v2; /*0x15a997*/
  return v5 + 2; /*0x15a99f*/
}
