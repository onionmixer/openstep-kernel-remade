/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173e90. */
int __cdecl kmem_free(int a1, int a2, int a3)
{
  return vm_map_remove(a1, ~page_mask & a2, ~page_mask & (page_mask + a3 + a2)); /*0x173eb5*/
}
