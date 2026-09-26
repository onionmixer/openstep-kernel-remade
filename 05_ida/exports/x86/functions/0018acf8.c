/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18acf8. */
int sub_18ACF8()
{
  int v0; // esi
  int v1; // eax
  int v2; // edx
  int v3; // ebx
  int result; // eax

  v0 = getlastaddr(); /*0x18ad08*/
  v1 = 0; /*0x18ad0a*/
  if ( MEMORY[0x11154] > 0 ) /*0x18ad14*/
  {
    v2 = 0; /*0x18ad18*/
    do /*0x18ad29*/
    {
      v0 += *(_DWORD *)(v2 + 69996); /*0x18ad1c*/
      v2 += 8; /*0x18ad23*/
      ++v1; /*0x18ad26*/
    }
    while ( v1 < MEMORY[0x11154] ); /*0x18ad29*/
  }
  if ( dword_1E760C ) /*0x18ad32*/
    v3 = dword_1E760C; /*0x18ad34*/
  else
    v3 = extmem; /*0x18ad38*/
  mem_size = v3 << 10; /*0x18ad41*/
  dword_1E7610 = ~page_mask & (page_mask + MEMORY[0x11138]); /*0x18ad5b*/
  result = ~page_mask & (cnvmem << 10); /*0x18ad68*/
  dword_1E7614 = result; /*0x18ad6a*/
  dword_1E7604 = ~page_mask & (v0 + page_mask); /*0x18ad73*/
  dword_1E7608 = ~page_mask & (v3 << 10); /*0x18ad7b*/
  return result; /*0x18ad84*/
}
