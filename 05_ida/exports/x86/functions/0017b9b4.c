/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b9b4. */
int __cdecl vm_page_copy(int a1, int a2)
{
  return pmap_copy_page(*(_DWORD *)(a1 + 36), *(_DWORD *)(a2 + 36)); /*0x17b9cc*/
}
