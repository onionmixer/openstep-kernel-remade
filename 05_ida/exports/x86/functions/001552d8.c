/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1552d8. */
kern_return_t __cdecl mach_port_get_refs(
        ipc_space_t task,
        mach_port_name_t name,
        mach_port_right_t right,
        mach_port_urefs_t *refs)
{
  kern_return_t result; // eax
  mach_port_urefs_t v5; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  int *v7; // [esp+14h] [ebp-4h] BYREF

  if ( !task ) /*0x1552e9*/
    return 16; /*0x1552eb*/
  if ( right > 4 ) /*0x1552fb*/
    return 18; /*0x1552fd*/
  result = ipc_right_lookup_write(task, name, &v7); /*0x155311*/
  if ( !result ) /*0x15531d*/
  {
    result = ipc_right_info(task, name, v7, &v6, &v5); /*0x155330*/
    if ( !result ) /*0x15533c*/
    {
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x155340*/
      if ( ((1 << (right + 16)) & v6) != 0 ) /*0x155350*/
      {
        if ( right <= 3 && right ) /*0x15535a*/
          *refs = 1; /*0x15536b*/
        else
          *refs = v5; /*0x15537a*/
      }
      else
      {
        *refs = 0; /*0x15538f*/
      }
      return 0; /*0x155395*/
    }
  }
  return result; /*0x15539a*/
}
