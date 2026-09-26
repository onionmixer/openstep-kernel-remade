/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1554f0. */
kern_return_t __cdecl mach_port_set_seqno(ipc_space_t task, mach_port_name_t name, mach_port_seqno_t seqno)
{
  kern_return_t result; // eax
  volatile __int32 *v4; // [esp+0h] [ebp-4h] BYREF

  if ( !task ) /*0x1554fb*/
    return 16; /*0x1554fd*/
  result = ipc_object_translate(task, name, 1, &v4); /*0x155513*/
  if ( !result ) /*0x15551d*/
  {
    ipc_port_set_seqno((int)v4, seqno); /*0x155527*/
    _InterlockedExchange(v4, 0); /*0x155531*/
    return 0; /*0x155533*/
  }
  return result; /*0x155502*/
}
