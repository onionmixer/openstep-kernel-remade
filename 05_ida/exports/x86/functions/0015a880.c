/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a880. */
void *__cdecl malloc(size_t __size)
{
  size_t v1; // esi
  int v2; // edx
  unsigned int i; // eax
  _DWORD *v4; // ebx
  void *v6; // [esp+8h] [ebp-4h] BYREF

  v1 = __size + 8; /*0x15a88b*/
  v2 = 0; /*0x15a88e*/
  i = __size + 8; /*0x15a890*/
  if ( k_zone_maxsize >= __size + 8 ) /*0x15a898*/
  {
    for ( i = k_zone_elemsize[0]; i < v1; i = k_zone_elemsize[v2] ) /*0x15a8a1*/
      ++v2; /*0x15a8a4*/
  }
  if ( k_zone_maxsize < i ) /*0x15a8b6*/
  {
    if ( kmem_alloc_wired(kalloc_map, &v6, i) ) /*0x15a8dc*/
      v6 = nullptr; /*0x15a8e8*/
  }
  else
  {
    v6 = (void *)zalloc(k_zone[v2]); /*0x15a8c5*/
  }
  v4 = v6; /*0x15a8ef*/
  if ( !v6 ) /*0x15a8f4*/
    return nullptr; /*0x15a904*/
  bzero(v6, v1); /*0x15a8f8*/
  *v4 = v1; /*0x15a8fd*/
  return v4 + 2; /*0x15a909*/
}
