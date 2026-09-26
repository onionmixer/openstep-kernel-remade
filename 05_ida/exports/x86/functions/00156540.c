/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156540. */
kern_return_t __cdecl port_set_status(
        ipc_space_inspect_t task,
        mach_port_name_t name,
        mach_port_name_array_t *members,
        mach_msg_type_number_t *membersCnt)
{
  kern_return_t result; // eax

  result = mach_port_get_set_status(task, name, members, membersCnt); /*0x156553*/
  if ( result ) /*0x15655a*/
  {
    if ( result != 6 ) /*0x15655f*/
      return 4; /*0x156561*/
  }
  return result; /*0x156568*/
}
