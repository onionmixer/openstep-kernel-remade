/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c5b8. */
kern_return_t __cdecl vm_allocate(vm_map_t target_task, vm_address_t *address, vm_size_t size, int flags)
{
  if ( !target_task ) /*0x17c5cc*/
    return 4; /*0x17c5ce*/
  if ( size ) /*0x17c5da*/
  {
    if ( flags ) /*0x17c5ea*/
      *address = *(_DWORD *)(target_task + 20); /*0x17c5ef*/
    else
      *address &= ~page_mask; /*0x17c5fb*/
    return vm_map_find(target_task, 0, 0, address, ~page_mask & (page_mask + size), flags); /*0x17c610*/
  }
  else
  {
    *address = 0; /*0x17c5dc*/
    return 0; /*0x17c5e2*/
  }
}
