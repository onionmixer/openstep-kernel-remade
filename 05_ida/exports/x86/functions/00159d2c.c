/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159d2c. */
kern_return_t __cdecl task_get_special_port(task_inspect_t task, int which_port, mach_port_t *special_port)
{
  int v4; // ebx
  volatile __int32 *v5; // edx
  mach_port_t v6; // edx
  int *v7; // ecx
  volatile __int32 *v8; // edx

  if ( !task ) /*0x159d3d*/
    return 4; /*0x159d3d*/
  if ( which_port == 2 ) /*0x159d4f*/
  {
    v4 = *(_DWORD *)(task + 136); /*0x159d68*/
    v5 = (volatile __int32 *)(v4 + 8); /*0x159d6e*/
    do /*0x159d86*/
    {
      while ( *v5 ) /*0x159d74*/
        ; /*0x159d76*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x159d86*/
    if ( *(_DWORD *)(v4 + 12) ) /*0x159d88*/
    {
      v6 = ipc_port_copy_send(*(_DWORD *)(v4 + 68)); /*0x159da1*/
      _InterlockedExchange((volatile __int32 *)(v4 + 8), 0); /*0x159da5*/
LABEL_24:
      *special_port = v6; /*0x159ded*/
      return 0; /*0x159df1*/
    }
    _InterlockedExchange((volatile __int32 *)(v4 + 8), 0); /*0x159d90*/
  }
  else
  {
    if ( which_port > 2 ) /*0x159d51*/
    {
      if ( which_port == 3 ) /*0x159d5f*/
      {
        v7 = (int *)(task + 112); /*0x159db4*/
      }
      else
      {
        if ( which_port != 4 ) /*0x159d64*/
          return 4; /*0x159d64*/
        v7 = (int *)(task + 116); /*0x159dbc*/
      }
    }
    else
    {
      if ( which_port != 1 ) /*0x159d56*/
        return 4; /*0x159d44*/
      v7 = (int *)(task + 108); /*0x159dac*/
    }
    v8 = (volatile __int32 *)(task + 100); /*0x159dbf*/
    do /*0x159dd6*/
    {
      while ( *v8 ) /*0x159dc4*/
        ; /*0x159dc6*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x159dd6*/
    if ( *(_DWORD *)(task + 104) ) /*0x159dd8*/
    {
      v6 = ipc_port_copy_send(*v7); /*0x159de6*/
      _InterlockedExchange((volatile __int32 *)(task + 100), 0); /*0x159dea*/
      goto LABEL_24; /*0x159dea*/
    }
    _InterlockedExchange((volatile __int32 *)(task + 100), 0); /*0x159df6*/
  }
  return 5; /*0x159e01*/
}
