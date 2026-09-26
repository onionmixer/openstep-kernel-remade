/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167de0. */
kern_return_t __cdecl thread_get_state(
        thread_act_t target_act,
        thread_state_flavor_t flavor,
        thread_state_t old_state,
        mach_msg_type_number_t *old_stateCnt)
{
  int v5; // edi
  int v6; // edi
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // esi
  volatile __int32 *v9; // esi
  volatile __int32 *v10; // esi
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // [esp+Ch] [ebp-8h]
  kern_return_t v16; // [esp+10h] [ebp-4h]

  if ( !target_act || active_threads == target_act ) /*0x167df6*/
    return 4; /*0x167df8*/
  v6 = splsched(); /*0x167e1d*/
  v7 = (volatile __int32 *)(target_act + 32); /*0x167e1f*/
  do /*0x167e36*/
  {
    while ( *v7 ) /*0x167e24*/
      ; /*0x167e26*/
  }
  while ( _InterlockedExchange(v7, 1) == 1 ); /*0x167e36*/
  ++*(_DWORD *)(target_act + 64); /*0x167e38*/
  *(_BYTE *)(target_act + 76) |= 2u; /*0x167e3b*/
  v8 = (volatile __int32 *)(target_act + 32); /*0x167e3f*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167e44*/
  splx(v6); /*0x167e48*/
  if ( active_threads == target_act ) /*0x167e56*/
    panic(aThreadDowait); /*0x167e5d*/
  v5 = 0; /*0x167e65*/
  v15 = splsched(); /*0x167e6c*/
  do /*0x167e86*/
  {
    while ( *v8 ) /*0x167e74*/
      ; /*0x167e76*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x167e86*/
  v9 = (volatile __int32 *)(target_act + 32); /*0x167e88*/
  while ( 2 ) /*0x167e9e*/
  {
    switch ( *(_DWORD *)(target_act + 76) & 0xF ) /*0x167e9e*/
    {
      case 6: /*0x167e9e*/
        if ( !rem_runq((_DWORD *)target_act) ) /*0x167ee1*/
          goto LABEL_16; /*0x167eeb*/
        *(_DWORD *)(target_act + 76) &= ~4u; /*0x167e04*/
        v5 = *(_DWORD *)(target_act + 72); /*0x167e08*/
        *(_DWORD *)(target_act + 72) = 0; /*0x167e0b*/
        break; /*0x167e12*/
      case 7: /*0x167e9e*/
      case 0xB: /*0x167e9e*/
      case 0xE: /*0x167e9e*/
      case 0xF: /*0x167e9e*/
LABEL_16:
        *(_DWORD *)(target_act + 72) = 1; /*0x167ef1*/
        thread_sleep(target_act + 72, (volatile __int32 *)(target_act + 32), 1); /*0x167eff*/
        do /*0x167f1e*/
        {
          while ( *v9 ) /*0x167f0c*/
            ; /*0x167f0e*/
        }
        while ( _InterlockedExchange(v9, 1) == 1 ); /*0x167f1e*/
        continue; /*0x167f1e*/
      default:
        goto LABEL_20;
    }
    break;
  }
LABEL_20:
  v10 = (volatile __int32 *)(target_act + 32); /*0x167f28*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167f2d*/
  splx(v15); /*0x167f34*/
  if ( v5 ) /*0x167f3e*/
    thread_wakeup_prim(target_act + 72, 0, 0); /*0x167f48*/
  v16 = thread_getstatus(target_act, flavor, old_state, old_stateCnt); /*0x167f62*/
  v11 = splsched(); /*0x167f6d*/
  do /*0x167f86*/
  {
    while ( *v10 ) /*0x167f74*/
      ; /*0x167f76*/
  }
  while ( _InterlockedExchange(v10, 1) == 1 ); /*0x167f86*/
  v12 = *(_DWORD *)(target_act + 64); /*0x167f88*/
  *(_DWORD *)(target_act + 64) = v12 - 1; /*0x167f8e*/
  if ( v12 == 1 ) /*0x167f94*/
  {
    v13 = *(_DWORD *)(target_act + 76); /*0x167f96*/
    v14 = v13; /*0x167f99*/
    LOBYTE(v14) = v13 & 0xED; /*0x167f9b*/
    *(_DWORD *)(target_act + 76) = v14; /*0x167f9e*/
    if ( (v13 & 5) == 0 ) /*0x167fa3*/
    {
      LOBYTE(v14) = v13 & 0xE9 | 4; /*0x167fa5*/
      *(_DWORD *)(target_act + 76) = v14; /*0x167fa8*/
      thread_setrun((char **)target_act, 1); /*0x167fae*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167fb8*/
  splx(v11); /*0x167fbc*/
  return v16; /*0x167fc7*/
}
