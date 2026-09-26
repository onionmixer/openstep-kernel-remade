/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a6ec. */
int __cdecl kalloc_noblock(unsigned int a1)
{
  int v1; // edx
  unsigned int i; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v1 = 0; /*0x15a6f6*/
  i = a1; /*0x15a6f8*/
  if ( k_zone_maxsize < a1 ) /*0x15a700*/
    goto LABEL_11; /*0x15a700*/
  for ( i = k_zone_elemsize[0]; i < a1; i = k_zone_elemsize[v1] ) /*0x15a709*/
    ++v1; /*0x15a70c*/
  if ( k_zone_maxsize >= i ) /*0x15a71e*/
    return zalloc_noblock(k_zone[v1]); /*0x15a72d*/
LABEL_11:
  if ( kmem_alloc_zone(kalloc_map, &v4, i, 0) ) /*0x15a742*/
    return 0; /*0x15a74b*/
  return v4; /*0x15a755*/
}
