/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155250. */
kern_return_t __cdecl mach_port_destroy(ipc_space_t task, mach_port_name_t name)
{
  kern_return_t result; // eax
  int *v3; // [esp+8h] [ebp-4h] BYREF

  if ( !task ) /*0x155260*/
    return 16; /*0x155262*/
  result = ipc_right_lookup_write(task, name, &v3); /*0x155272*/
  if ( !result ) /*0x15527c*/
    return ipc_right_destroy(task, name, (int)v3); /*0x155284*/
  return result; /*0x15528c*/
}
