/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c754. */
kern_return_t __cdecl vm_machine_attribute(
        vm_map_t target_task,
        vm_address_t address,
        vm_size_t size,
        vm_machine_attribute_t attribute,
        vm_machine_attribute_val_t *value)
{
  if ( target_task ) /*0x17c75c*/
    return vm_map_machine_attribute((_DWORD *)target_task, address, size, attribute, (int)value); /*0x17c76f*/
  else
    return 4; /*0x17c778*/
}
