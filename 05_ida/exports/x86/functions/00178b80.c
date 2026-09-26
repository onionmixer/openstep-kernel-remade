/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178b80. */
int __cdecl vm_object_allocate(int a1)
{
  int v1; // esi

  v1 = zalloc(vm_object_zone); /*0x178b94*/
  _vm_object_allocate(a1, v1); /*0x178b98*/
  return v1; /*0x178ba2*/
}
