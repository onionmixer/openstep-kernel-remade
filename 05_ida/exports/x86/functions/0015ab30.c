/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ab30. */
void __cdecl free(void *a1)
{
  char *v1; // ebx
  unsigned int v2; // ecx
  int v3; // edx
  unsigned int i; // eax

  if ( a1 ) /*0x15ab3a*/
  {
    v1 = (char *)a1 - 8; /*0x15ab3c*/
    v2 = *((_DWORD *)a1 - 2); /*0x15ab3f*/
    v3 = 0; /*0x15ab42*/
    i = v2; /*0x15ab44*/
    if ( k_zone_maxsize < v2 ) /*0x15ab4c*/
      goto LABEL_7; /*0x15ab4c*/
    for ( i = k_zone_elemsize[0]; i < v2; i = k_zone_elemsize[v3] ) /*0x15ab55*/
      ++v3; /*0x15ab58*/
    if ( k_zone_maxsize < i ) /*0x15ab6a*/
LABEL_7:
      kmem_free(kalloc_map, v1, i); /*0x15ab85*/
    else
      zfree(k_zone[v3], v1); /*0x15ab75*/
  }
}
