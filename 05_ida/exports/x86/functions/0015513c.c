/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15513c. */
kern_return_t __cdecl mach_port_allocate_name(ipc_space_t task, mach_port_right_t right, mach_port_name_t name)
{
  kern_return_t v4; // ecx
  volatile __int32 *v5; // eax
  volatile __int32 *v6; // [esp+0h] [ebp-8h] BYREF
  volatile __int32 *v7; // [esp+4h] [ebp-4h] BYREF

  if ( !task ) /*0x15514d*/
    return 16; /*0x155157*/
  if ( !name || name == -1 ) /*0x15515f*/
    return 18; /*0x155169*/
  if ( right == 3 ) /*0x15516f*/
  {
    v4 = ipc_pset_alloc_name(task, name, &v6); /*0x1551a7*/
    if ( !v4 ) /*0x1551ab*/
    {
      v5 = v6; /*0x1551ad*/
      goto LABEL_16; /*0x1551ad*/
    }
  }
  else if ( right > 3 ) /*0x155171*/
  {
    if ( right != 4 ) /*0x15517f*/
      return 18; /*0x15517f*/
    return ipc_object_alloc_dead_name(task, name); /*0x1551bf*/
  }
  else
  {
    if ( right != 1 ) /*0x155176*/
      return 18; /*0x1551c4*/
    v4 = ipc_port_alloc_name(task, name, &v7); /*0x15518f*/
    if ( !v4 ) /*0x155193*/
    {
      v5 = v7; /*0x155195*/
LABEL_16:
      _InterlockedExchange(v5, 0); /*0x1551b0*/
    }
  }
  return v4; /*0x155154*/
}
