/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167b98. */
kern_return_t __cdecl thread_suspend(thread_act_t target_act)
{
  int v2; // edi
  volatile __int32 *v3; // edx
  int v4; // eax
  volatile __int32 *v5; // esi
  int v6; // eax
  int v7; // edi
  volatile __int32 *v8; // esi
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( !target_act ) /*0x167ba6*/
    return 4; /*0x167ba8*/
  v2 = 0; /*0x167bb4*/
  v9 = splsched(); /*0x167bbb*/
  v3 = (volatile __int32 *)(target_act + 32); /*0x167bbe*/
  do /*0x167bd6*/
  {
    while ( *v3 ) /*0x167bc4*/
      ; /*0x167bc6*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x167bd6*/
  v4 = *(_DWORD *)(target_act + 140); /*0x167bd8*/
  *(_DWORD *)(target_act + 140) = v4 + 1; /*0x167be1*/
  if ( !v4 ) /*0x167be9*/
  {
    v2 = 1; /*0x167beb*/
    ++*(_DWORD *)(target_act + 64); /*0x167bf0*/
    *(_BYTE *)(target_act + 76) |= 2u; /*0x167bf3*/
  }
  v5 = (volatile __int32 *)(target_act + 32); /*0x167bf7*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167bfc*/
  splx(v9); /*0x167c03*/
  if ( v2 ) /*0x167c0d*/
  {
    if ( active_threads == target_act ) /*0x167c19*/
    {
      v10 = splsched(); /*0x167c20*/
      v6 = need_ast[0]; /*0x167c23*/
      LOBYTE(v6) = LOBYTE(need_ast[0]) | 4; /*0x167c28*/
      need_ast[0] = v6; /*0x167c2a*/
      splx(v10); /*0x167c38*/
    }
    else
    {
      v7 = 0; /*0x167c58*/
      v11 = splsched(); /*0x167c5f*/
      do /*0x167c76*/
      {
        while ( *v5 ) /*0x167c64*/
          ; /*0x167c66*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x167c76*/
      v8 = (volatile __int32 *)(target_act + 32); /*0x167c78*/
      while ( 2 ) /*0x167c8e*/
      {
        switch ( *(_DWORD *)(target_act + 76) & 0xF ) /*0x167c8e*/
        {
          case 6: /*0x167c8e*/
            if ( !rem_runq((_DWORD *)target_act) ) /*0x167cd1*/
              goto LABEL_18; /*0x167cdb*/
            *(_DWORD *)(target_act + 76) &= ~4u; /*0x167c44*/
            v7 = *(_DWORD *)(target_act + 72); /*0x167c48*/
            *(_DWORD *)(target_act + 72) = 0; /*0x167c4b*/
            break; /*0x167c52*/
          case 7: /*0x167c8e*/
          case 0xB: /*0x167c8e*/
          case 0xE: /*0x167c8e*/
          case 0xF: /*0x167c8e*/
LABEL_18:
            *(_DWORD *)(target_act + 72) = 1; /*0x167ce1*/
            thread_sleep(target_act + 72, (volatile __int32 *)(target_act + 32), 1); /*0x167cef*/
            do /*0x167d0e*/
            {
              while ( *v8 ) /*0x167cfc*/
                ; /*0x167cfe*/
            }
            while ( _InterlockedExchange(v8, 1) == 1 ); /*0x167d0e*/
            continue; /*0x167d0e*/
          default:
            goto LABEL_22;
        }
        break;
      }
LABEL_22:
      _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167d18*/
      splx(v11); /*0x167d21*/
      if ( v7 ) /*0x167d2b*/
        thread_wakeup_prim(target_act + 72, 0, 0); /*0x167d35*/
    }
  }
  return 0; /*0x167d3f*/
}
