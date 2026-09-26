/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18980c. */
int __cdecl dma_buf_alloc(int **a1, vm_size_t a2)
{
  int *v2; // ebx
  int v3; // edi
  int *v4; // esi

  if ( a2 > 0x10000 ) /*0x18981a*/
    return 0; /*0x18981a*/
  v2 = &dma_buf_sm; /*0x18981c*/
  if ( page_size < a2 ) /*0x189827*/
    v2 = &dma_buf_lg; /*0x189829*/
  v3 = spldma(); /*0x189833*/
  v4 = (int *)v2[1]; /*0x189835*/
  if ( v4 ) /*0x18983a*/
  {
    v2[1] = *v4; /*0x18983e*/
    --v2[2]; /*0x189841*/
  }
  else
  {
    v4 = (int *)((int (*)(void))*v2)(); /*0x18984c*/
    if ( v4 ) /*0x189850*/
      ++v2[3]; /*0x189852*/
  }
  splx(v3); /*0x189856*/
  if ( !v4 ) /*0x18985d*/
    return 0; /*0x189870*/
  *a1 = v4; /*0x189862*/
  a1[1] = v2; /*0x189864*/
  return 1; /*0x189875*/
}
