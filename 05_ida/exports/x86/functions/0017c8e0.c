/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c8e0. */
kern_return_t __cdecl vm_copy(
        vm_map_t target_task,
        vm_address_t source_address,
        vm_size_t size,
        vm_address_t dest_address)
{
  int v4; // ebx
  vm_address_t v6; // [esp+Ch] [ebp-4h]

  v4 = ~page_mask; /*0x17c8fa*/
  v6 = ~page_mask & (page_mask + source_address); /*0x17c8fe*/
  if ( v6 == source_address && (v4 & (page_mask + dest_address)) == dest_address && size == (v4 & (page_mask + size)) ) /*0x17c91a*/
    return vm_map_copy(target_task, target_task, v4 & (page_mask + dest_address), v4 & (page_mask + size), v6, 0, 0); /*0x17c933*/
  else
    return 4; /*0x17c91c*/
}
