/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1553a4. */
kern_return_t __cdecl mach_port_mod_refs(
        ipc_space_t task,
        mach_port_name_t name,
        mach_port_right_t right,
        mach_port_delta_t delta)
{
  kern_return_t result; // eax
  int *v5; // [esp+Ch] [ebp-4h] BYREF

  if ( !task ) /*0x1553b8*/
    return 16; /*0x1553ba*/
  if ( right > 4 ) /*0x1553c7*/
    return 18; /*0x1553c9*/
  result = ipc_right_lookup_write(task, name, &v5); /*0x1553d6*/
  if ( !result ) /*0x1553e0*/
    return ipc_right_delta(task, name, (int)v5, right, delta); /*0x1553ed*/
  return result; /*0x1553f5*/
}
