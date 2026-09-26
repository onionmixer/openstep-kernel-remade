/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a75c. */
int __cdecl kalloc(unsigned int a1)
{
  int v1; // edx
  unsigned int i; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v1 = 0; /*0x15a766*/
  i = a1; /*0x15a768*/
  if ( k_zone_maxsize < a1 ) /*0x15a770*/
    goto LABEL_11; /*0x15a770*/
  for ( i = k_zone_elemsize[0]; i < a1; i = k_zone_elemsize[v1] ) /*0x15a779*/
    ++v1; /*0x15a77c*/
  if ( k_zone_maxsize >= i ) /*0x15a78e*/
    return zalloc(k_zone[v1]); /*0x15a79d*/
LABEL_11:
  if ( kmem_alloc_wired(kalloc_map, &v4, i) ) /*0x15a7b0*/
    return 0; /*0x15a7b9*/
  return v4; /*0x15a7c3*/
}
