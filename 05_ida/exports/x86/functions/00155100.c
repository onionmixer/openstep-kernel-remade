/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155100. */
kern_return_t __cdecl mach_port_rename(ipc_space_t task, mach_port_name_t old_name, mach_port_name_t new_name)
{
  if ( !task ) /*0x15510b*/
    return 16; /*0x15510d*/
  if ( new_name && new_name != -1 ) /*0x15511f*/
    return ipc_object_rename(task, old_name, new_name); /*0x155132*/
  return 18; /*0x155114*/
}
