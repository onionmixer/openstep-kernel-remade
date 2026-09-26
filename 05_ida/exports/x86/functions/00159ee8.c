/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159ee8. */
kern_return_t __cdecl thread_get_special_port(thread_act_t thr_act, int which_port, mach_port_t *special_port)
{
  int *v4; // ecx
  volatile __int32 *v5; // edx
  mach_port_t v6; // eax

  if ( !thr_act ) /*0x159ef8*/
    return 4; /*0x159ef8*/
  if ( which_port == 2 ) /*0x159f07*/
  {
    v4 = (int *)(thr_act + 184); /*0x159f1c*/
  }
  else if ( which_port > 2 ) /*0x159f09*/
  {
    if ( which_port != 3 ) /*0x159f17*/
      return 4; /*0x159f17*/
    v4 = (int *)(thr_act + 180); /*0x159f2c*/
  }
  else
  {
    if ( which_port != 1 ) /*0x159f0e*/
      return 4; /*0x159eff*/
    v4 = (int *)(thr_act + 176); /*0x159f24*/
  }
  v5 = (volatile __int32 *)(thr_act + 168); /*0x159f32*/
  do /*0x159f4a*/
  {
    while ( *v5 ) /*0x159f38*/
      ; /*0x159f3a*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x159f4a*/
  if ( *(_DWORD *)(thr_act + 172) ) /*0x159f4c*/
  {
    v6 = ipc_port_copy_send(*v4); /*0x159f58*/
    _InterlockedExchange((volatile __int32 *)(thr_act + 168), 0); /*0x159f61*/
    *special_port = v6; /*0x159f67*/
    return 0; /*0x159f69*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(thr_act + 168), 0); /*0x159f72*/
    return 5; /*0x159f78*/
  }
}
