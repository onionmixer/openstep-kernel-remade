/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159e08. */
kern_return_t __cdecl task_set_special_port(task_t task, int which_port, mach_port_t special_port)
{
  int v4; // ecx
  volatile __int32 *v5; // edx
  int v6; // edx
  int *v7; // ecx
  volatile __int32 *v8; // edx

  if ( !task ) /*0x159e18*/
    return 4; /*0x159e18*/
  if ( which_port == 2 ) /*0x159e27*/
  {
    v4 = *(_DWORD *)(task + 136); /*0x159e40*/
    v5 = (volatile __int32 *)(v4 + 8); /*0x159e46*/
    do /*0x159e5e*/
    {
      while ( *v5 ) /*0x159e4c*/
        ; /*0x159e4e*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x159e5e*/
    if ( !*(_DWORD *)(v4 + 12) ) /*0x159e60*/
    {
      _InterlockedExchange((volatile __int32 *)(v4 + 8), 0); /*0x159e68*/
      return 5; /*0x159e70*/
    }
    v6 = *(_DWORD *)(v4 + 68); /*0x159e74*/
    *(_DWORD *)(v4 + 68) = special_port; /*0x159e77*/
    _InterlockedExchange((volatile __int32 *)(v4 + 8), 0); /*0x159e7c*/
  }
  else
  {
    if ( which_port > 2 ) /*0x159e29*/
    {
      if ( which_port == 3 ) /*0x159e37*/
      {
        v7 = (int *)(task + 112); /*0x159e8c*/
      }
      else
      {
        if ( which_port != 4 ) /*0x159e3c*/
          return 4; /*0x159e3c*/
        v7 = (int *)(task + 116); /*0x159e94*/
      }
    }
    else
    {
      if ( which_port != 1 ) /*0x159e2e*/
        return 4; /*0x159e1f*/
      v7 = (int *)(task + 108); /*0x159e84*/
    }
    v8 = (volatile __int32 *)(task + 100); /*0x159e97*/
    do /*0x159eae*/
    {
      while ( *v8 ) /*0x159e9c*/
        ; /*0x159e9e*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x159eae*/
    if ( !*(_DWORD *)(task + 104) ) /*0x159eb0*/
    {
      _InterlockedExchange((volatile __int32 *)(task + 100), 0); /*0x159eb8*/
      return 5; /*0x159ec0*/
    }
    v6 = *v7; /*0x159ec4*/
    *v7 = special_port; /*0x159ec6*/
    _InterlockedExchange((volatile __int32 *)(task + 100), 0); /*0x159eca*/
  }
  if ( v6 ) /*0x159ecf*/
  {
    if ( v6 != -1 ) /*0x159ed4*/
      ipc_port_release_send(v6); /*0x159ed7*/
  }
  return 0; /*0x159ee1*/
}
