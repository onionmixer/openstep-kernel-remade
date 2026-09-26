/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c6a4. */
kern_return_t __cdecl vm_protect(
        vm_map_t target_task,
        vm_address_t address,
        vm_size_t size,
        boolean_t set_maximum,
        vm_prot_t new_protection)
{
  if ( target_task ) /*0x17c6b1*/
    return vm_map_protect( /*0x17c6d0*/
             target_task,
             address & ~page_mask,
             ~page_mask & (page_mask + size + address),
             new_protection,
             set_maximum);
  else
    return 4; /*0x17c6d8*/
}
