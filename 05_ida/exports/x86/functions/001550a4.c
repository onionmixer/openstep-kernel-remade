/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1550a4. */
kern_return_t __cdecl mach_port_type(ipc_space_t task, mach_port_name_t name, mach_port_type_t *ptype)
{
  kern_return_t result; // eax
  kern_return_t v4; // edx
  _BYTE v5[4]; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  if ( !task ) /*0x1550b4*/
    return 16; /*0x1550b6*/
  result = ipc_right_lookup_write(task, name, &v6); /*0x1550c6*/
  if ( !result ) /*0x1550d2*/
  {
    v4 = ipc_right_info(task, name, v6, ptype, v5); /*0x1550e7*/
    if ( !v4 ) /*0x1550eb*/
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x1550ef*/
    return v4; /*0x1550f2*/
  }
  return result; /*0x1550f7*/
}
