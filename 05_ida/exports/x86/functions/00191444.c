/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191444. */
unsigned int __cdecl pmap_copy_page(const void *a1, void *a2)
{
  return page_copy(a2, a1, page_size); /*0x19145d*/
}
