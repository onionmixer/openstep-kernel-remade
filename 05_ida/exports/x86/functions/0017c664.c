/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c664. */
kern_return_t __cdecl vm_inherit(
        vm_map_t target_task,
        vm_address_t address,
        vm_size_t size,
        vm_inherit_t new_inheritance)
{
  if ( target_task ) /*0x17c671*/
    return vm_map_inherit(target_task, address & ~page_mask, ~page_mask & (page_mask + size + address), new_inheritance); /*0x17c68c*/
  else
    return 4; /*0x17c694*/
}
