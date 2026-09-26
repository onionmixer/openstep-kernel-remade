/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c620. */
kern_return_t __cdecl vm_deallocate(vm_map_t target_task, vm_address_t address, vm_size_t size)
{
  if ( !target_task ) /*0x17c62f*/
    return 4; /*0x17c631*/
  if ( size ) /*0x17c63a*/
    return vm_map_remove((_DWORD *)target_task, address & ~page_mask, ~page_mask & (page_mask + size + address)); /*0x17c64f*/
  return 0; /*0x17c65a*/
}
