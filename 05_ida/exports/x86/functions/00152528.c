/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x152528. */
kern_return_t __cdecl mach_port_kernel_object(
        ipc_space_inspect_t task,
        mach_port_name_t name,
        unsigned int *object_type,
        unsigned int *object_addr)
{
  kern_return_t result; // eax
  int v5; // edx
  int *v6; // [esp+Ch] [ebp-4h] BYREF

  result = ipc_right_lookup_write(task, name, &v6); /*0x152543*/
  if ( !result ) /*0x15254a*/
  {
    if ( (*((_BYTE *)v6 + 2) & 3) != 0 ) /*0x152553*/
    {
      v5 = v6[1]; /*0x15255c*/
      do /*0x152572*/
      {
        while ( *(_DWORD *)v5 ) /*0x152560*/
          ; /*0x152562*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v5, 1) == 1 ); /*0x152572*/
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x152576*/
      if ( *(int *)(v5 + 8) < 0 ) /*0x15257e*/
      {
        *object_type = (unsigned __int16)*(_DWORD *)(v5 + 8); /*0x152585*/
        *object_addr = *(_DWORD *)(v5 + 20); /*0x15258a*/
        _InterlockedExchange((volatile __int32 *)v5, 0); /*0x15258e*/
        return 0; /*0x152592*/
      }
      _InterlockedExchange((volatile __int32 *)v5, 0); /*0x152596*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x152557*/
    }
    return 17; /*0x152598*/
  }
  return result; /*0x1525a0*/
}
