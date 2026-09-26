/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a824. */
int __cdecl kfree(int a1, unsigned int a2)
{
  int v2; // edx
  unsigned int i; // eax

  v2 = 0; /*0x15a82f*/
  i = a2; /*0x15a831*/
  if ( k_zone_maxsize < a2 ) /*0x15a839*/
    return kmem_free(kalloc_map, a1, i); /*0x15a839*/
  for ( i = k_zone_elemsize[0]; i < a2; i = k_zone_elemsize[v2] ) /*0x15a842*/
    ++v2; /*0x15a844*/
  if ( k_zone_maxsize < i ) /*0x15a856*/
    return kmem_free(kalloc_map, a1, i); /*0x15a871*/
  else
    return zfree(k_zone[v2], a1); /*0x15a861*/
}
