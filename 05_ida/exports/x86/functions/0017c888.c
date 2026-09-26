/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c888. */
kern_return_t __cdecl vm_write(
        vm_map_t target_task,
        vm_address_t address,
        vm_offset_t data,
        mach_msg_type_number_t dataCnt)
{
  int v4; // ebx

  v4 = ~page_mask; /*0x17c89f*/
  if ( (~page_mask & (page_mask + address)) == address && (v4 & (page_mask + dataCnt)) == dataCnt ) /*0x17c8b0*/
    return vm_map_copy( /*0x17c8d1*/
             target_task,
             ipc_soft_map,
             ~page_mask & (page_mask + address),
             v4 & (page_mask + dataCnt),
             data,
             0,
             1);
  else
    return 4; /*0x17c8b2*/
}
