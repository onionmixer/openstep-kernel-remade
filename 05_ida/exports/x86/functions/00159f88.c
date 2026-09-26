/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159f88. */
kern_return_t __cdecl thread_set_special_port(thread_act_t thr_act, int which_port, mach_port_t special_port)
{
  int *v4; // ecx
  volatile __int32 *v5; // edx
  int v6; // edx

  if ( !thr_act ) /*0x159f95*/
    return 4; /*0x159f95*/
  if ( which_port == 2 ) /*0x159fa7*/
  {
    v4 = (int *)(thr_act + 184); /*0x159fbc*/
  }
  else if ( which_port > 2 ) /*0x159fa9*/
  {
    if ( which_port != 3 ) /*0x159fb7*/
      return 4; /*0x159fb7*/
    v4 = (int *)(thr_act + 180); /*0x159fcc*/
  }
  else
  {
    if ( which_port != 1 ) /*0x159fae*/
      return 4; /*0x159f9c*/
    v4 = (int *)(thr_act + 176); /*0x159fc4*/
  }
  v5 = (volatile __int32 *)(thr_act + 168); /*0x159fd2*/
  do /*0x159fea*/
  {
    while ( *v5 ) /*0x159fd8*/
      ; /*0x159fda*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x159fea*/
  if ( *(_DWORD *)(thr_act + 172) ) /*0x159fec*/
  {
    v6 = *v4; /*0x15a004*/
    *v4 = special_port; /*0x15a009*/
    _InterlockedExchange((volatile __int32 *)(thr_act + 168), 0); /*0x15a00d*/
    if ( v6 ) /*0x15a015*/
    {
      if ( v6 != -1 ) /*0x15a01a*/
        ipc_port_release_send(v6); /*0x15a01d*/
    }
    return 0; /*0x15a022*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(thr_act + 168), 0); /*0x159ff7*/
    return 5; /*0x159ffd*/
  }
}
