/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a93e8. */
int __cdecl IOUnmapPhysicalFromIOTask(vm_address_t address, vm_size_t size)
{
  vm_map_t v2; // eax

  v2 = _io_vm_task_self(); /*0x1a93f3*/
  vm_deallocate(v2, address, size); /*0x1a93f9*/
  return 0; /*0x1a9402*/
}
