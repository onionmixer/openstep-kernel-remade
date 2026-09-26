/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191428. */
int __cdecl pmap_zero_page(_DWORD *a1)
{
  return page_set(a1, 0, page_size); /*0x19143f*/
}
