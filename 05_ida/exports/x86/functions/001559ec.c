/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1559ec. */
kern_return_t __cdecl mach_port_insert_right(
        ipc_space_t task,
        mach_port_name_t name,
        mach_port_t poly,
        mach_msg_type_name_t polyPoly)
{
  if ( !task ) /*0x1559ff*/
    return 16; /*0x155a01*/
  if ( !name || name == -1 || polyPoly - 16 > 2 ) /*0x155a17*/
    return 18; /*0x155a19*/
  if ( poly && poly != -1 ) /*0x155a27*/
    return ipc_object_copyout_name(task, poly, polyPoly, 0, name); /*0x155a36*/
  return 20; /*0x155a3e*/
}
