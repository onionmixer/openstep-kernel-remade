/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155a44. */
kern_return_t __cdecl mach_port_extract_right(
        ipc_space_t task,
        mach_port_name_t name,
        mach_msg_type_name_t msgt_name,
        mach_port_t *poly,
        mach_msg_type_name_t *polyPoly)
{
  kern_return_t v6; // ebx

  if ( !task ) /*0x155a55*/
    return 16; /*0x155a57*/
  if ( msgt_name - 16 > 5 ) /*0x155a66*/
    return 18; /*0x155a68*/
  v6 = ipc_object_copyin(task, name, msgt_name, (int)poly); /*0x155a7f*/
  if ( !v6 ) /*0x155a86*/
    *polyPoly = ipc_object_copyin_type(msgt_name); /*0x155a8e*/
  return v6; /*0x155a95*/
}
