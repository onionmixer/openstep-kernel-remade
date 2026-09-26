/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155294. */
kern_return_t __cdecl mach_port_deallocate(ipc_space_t task, mach_port_name_t name)
{
  kern_return_t result; // eax
  int *v3; // [esp+8h] [ebp-4h] BYREF

  if ( !task ) /*0x1552a4*/
    return 16; /*0x1552a6*/
  result = ipc_right_lookup_write(task, name, &v3); /*0x1552b6*/
  if ( !result ) /*0x1552c0*/
    return ipc_right_dealloc(task, name, (int)v3); /*0x1552c8*/
  return result; /*0x1552d0*/
}
