/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1551d0. */
kern_return_t __cdecl mach_port_allocate(ipc_space_t task, mach_port_right_t right, mach_port_name_t *name)
{
  kern_return_t v4; // ecx
  volatile __int32 *v5; // eax
  volatile __int32 *v6; // [esp+0h] [ebp-8h] BYREF
  volatile __int32 *v7; // [esp+4h] [ebp-4h] BYREF

  if ( !task ) /*0x1551e1*/
    return 16; /*0x1551eb*/
  if ( right == 3 ) /*0x1551ef*/
  {
    v4 = ipc_pset_alloc(task, name, &v6); /*0x155227*/
    if ( !v4 ) /*0x15522b*/
    {
      v5 = v6; /*0x15522d*/
      goto LABEL_13; /*0x15522d*/
    }
  }
  else if ( right > 3 ) /*0x1551f1*/
  {
    if ( right != 4 ) /*0x1551ff*/
      return 18; /*0x1551ff*/
    return ipc_object_alloc_dead(task, name); /*0x15523f*/
  }
  else
  {
    if ( right != 1 ) /*0x1551f6*/
      return 18; /*0x155244*/
    v4 = ipc_port_alloc(task, name, &v7); /*0x15520f*/
    if ( !v4 ) /*0x155213*/
    {
      v5 = v7; /*0x155215*/
LABEL_13:
      _InterlockedExchange(v5, 0); /*0x155230*/
    }
  }
  return v4; /*0x1551e8*/
}
