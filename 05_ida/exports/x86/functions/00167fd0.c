/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167fd0. */
kern_return_t __cdecl thread_set_state(
        thread_act_t target_act,
        thread_state_flavor_t flavor,
        thread_state_t new_state,
        mach_msg_type_number_t new_stateCnt)
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

  if ( !target_act || active_threads == target_act ) /*0x167fe6*/
    return 4; /*0x167fe8*/
  v6 = splsched(); /*0x16800d*/
  v7 = (volatile __int32 *)(target_act + 32); /*0x16800f*/
  do /*0x168026*/
  {
    while ( *v7 ) /*0x168014*/
      ; /*0x168016*/
  }
  while ( _InterlockedExchange(v7, 1) == 1 ); /*0x168026*/
  ++*(_DWORD *)(target_act + 64); /*0x168028*/
  *(_BYTE *)(target_act + 76) |= 2u; /*0x16802b*/
  v8 = (volatile __int32 *)(target_act + 32); /*0x16802f*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x168034*/
  splx(v6); /*0x168038*/
  if ( active_threads == target_act ) /*0x168046*/
    panic(aThreadDowait); /*0x16804d*/
  v5 = 0; /*0x168055*/
  v15 = splsched(); /*0x16805c*/
  do /*0x168076*/
  {
    while ( *v8 ) /*0x168064*/
      ; /*0x168066*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x168076*/
  v9 = (volatile __int32 *)(target_act + 32); /*0x168078*/
  while ( 2 ) /*0x16808e*/
  {
    switch ( *(_DWORD *)(target_act + 76) & 0xF ) /*0x16808e*/
    {
      case 6: /*0x16808e*/
        if ( !rem_runq((_DWORD *)target_act) ) /*0x1680d1*/
          goto LABEL_16; /*0x1680db*/
        *(_DWORD *)(target_act + 76) &= ~4u; /*0x167ff4*/
        v5 = *(_DWORD *)(target_act + 72); /*0x167ff8*/
        *(_DWORD *)(target_act + 72) = 0; /*0x167ffb*/
        break; /*0x168002*/
      case 7: /*0x16808e*/
      case 0xB: /*0x16808e*/
      case 0xE: /*0x16808e*/
      case 0xF: /*0x16808e*/
LABEL_16:
        *(_DWORD *)(target_act + 72) = 1; /*0x1680e1*/
        thread_sleep(target_act + 72, (volatile __int32 *)(target_act + 32), 1); /*0x1680ef*/
        do /*0x16810e*/
        {
          while ( *v9 ) /*0x1680fc*/
            ; /*0x1680fe*/
        }
        while ( _InterlockedExchange(v9, 1) == 1 ); /*0x16810e*/
        continue; /*0x16810e*/
      default:
        goto LABEL_20;
    }
    break;
  }
LABEL_20:
  v10 = (volatile __int32 *)(target_act + 32); /*0x168118*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x16811d*/
  splx(v15); /*0x168124*/
  if ( v5 ) /*0x16812e*/
    thread_wakeup_prim(target_act + 72, 0, 0); /*0x168138*/
  v16 = thread_setstatus(target_act, flavor, new_state, new_stateCnt); /*0x168152*/
  v11 = splsched(); /*0x16815d*/
  do /*0x168176*/
  {
    while ( *v10 ) /*0x168164*/
      ; /*0x168166*/
  }
  while ( _InterlockedExchange(v10, 1) == 1 ); /*0x168176*/
  v12 = *(_DWORD *)(target_act + 64); /*0x168178*/
  *(_DWORD *)(target_act + 64) = v12 - 1; /*0x16817e*/
  if ( v12 == 1 ) /*0x168184*/
  {
    v13 = *(_DWORD *)(target_act + 76); /*0x168186*/
    v14 = v13; /*0x168189*/
    LOBYTE(v14) = v13 & 0xED; /*0x16818b*/
    *(_DWORD *)(target_act + 76) = v14; /*0x16818e*/
    if ( (v13 & 5) == 0 ) /*0x168193*/
    {
      LOBYTE(v14) = v13 & 0xE9 | 4; /*0x168195*/
      *(_DWORD *)(target_act + 76) = v14; /*0x168198*/
      thread_setrun((char **)target_act, 1); /*0x16819e*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1681a8*/
  splx(v11); /*0x1681ac*/
  return v16; /*0x1681b7*/
}
