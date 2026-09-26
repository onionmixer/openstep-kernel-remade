/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151cbc. */
kern_return_t __cdecl mach_port_get_srights(ipc_space_t task, mach_port_name_t name, mach_port_rights_t *srights)
{
  kern_return_t result; // eax
  mach_port_rights_t v4; // edx
  volatile __int32 *v5; // [esp+8h] [ebp-4h] BYREF

  if ( !task ) /*0x151ccc*/
    return 16; /*0x151cce*/
  result = ipc_object_translate(task, name, 1, &v5); /*0x151ce3*/
  if ( !result ) /*0x151cea*/
  {
    v4 = *((_DWORD *)v5 + 7); /*0x151cef*/
    _InterlockedExchange(v5, 0); /*0x151cf4*/
    *srights = v4; /*0x151cf6*/
    return 0; /*0x151cf8*/
  }
  return result; /*0x151cfd*/
}
