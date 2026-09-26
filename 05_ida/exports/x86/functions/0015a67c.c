/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a67c. */
void kalloc_init()
{
  int v0; // esi
  char *v1; // edi
  unsigned int v2; // ebx

  kalloc_map = kernel_map; /*0x15a688*/
  v0 = 0; /*0x15a68e*/
  v1 = byte_1E5A98; /*0x15a690*/
  do /*0x15a6df*/
  {
    v2 = k_zone_elemsize[v0]; /*0x15a698*/
    if ( page_size <= v2 ) /*0x15a6a5*/
      break; /*0x15a6a5*/
    sprintf(v1, "kalloc.%d", k_zone_elemsize[v0]); /*0x15a6ae*/
    k_zone[v0] = zinit(v2, &dword_100000, page_size, 0, v1); /*0x15a6c8*/
    k_zone_maxsize = v2; /*0x15a6cf*/
    v1 += 16; /*0x15a6d8*/
    ++v0; /*0x15a6db*/
  }
  while ( v0 <= 15 ); /*0x15a6df*/
}
