/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18adf0. */
void *__cdecl alloc_pages(int a1)
{
  void *result; // eax

  if ( pmap_initialized ) /*0x18adfe*/
    panic(aAllocPages); /*0x18ae05*/
  result = dword_1F6E74; /*0x18ae18*/
  dword_1F6E74 = (char *)dword_1F6E74 + (~page_mask & (page_mask + a1)); /*0x18ae1f*/
  return result; /*0x18ae25*/
}
