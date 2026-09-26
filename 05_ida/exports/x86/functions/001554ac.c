/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1554ac. */
kern_return_t __cdecl mach_port_set_mscount(ipc_space_t task, mach_port_name_t name, mach_port_mscount_t mscount)
{
  kern_return_t result; // eax
  volatile __int32 *v4; // eax
  volatile __int32 *v5; // [esp+0h] [ebp-4h] BYREF

  if ( !task ) /*0x1554b7*/
    return 16; /*0x1554b9*/
  result = ipc_object_translate(task, name, 1, &v5); /*0x1554cf*/
  if ( !result ) /*0x1554d6*/
  {
    v4 = v5; /*0x1554d8*/
    *((_DWORD *)v5 + 6) = mscount; /*0x1554de*/
    _InterlockedExchange(v4, 0); /*0x1554e3*/
    return 0; /*0x1554e5*/
  }
  return result; /*0x1554be*/
}
