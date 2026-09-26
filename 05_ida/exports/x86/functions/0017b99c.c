/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b99c. */
int __cdecl vm_page_zero_fill(int a1)
{
  pmap_zero_page(*(_DWORD *)(a1 + 36)); /*0x17b9a6*/
  return 1; /*0x17b9b2*/
}
