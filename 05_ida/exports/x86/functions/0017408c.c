/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17408c. */
int __cdecl kmem_init(int a1, int a2)
{
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = pmap_kernel(); /*0x17409e*/
  kernel_map = vm_map_create(v2, 0, a2, 0); /*0x1740ab*/
  v4 = 0; /*0x1740b1*/
  return vm_map_find(kernel_map, 0, 0, &v4, a1, 0); /*0x1740c9*/
}
