/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16727c. */
kern_return_t __cdecl thread_terminate(thread_act_t target_act)
{
  thread_act_t v1; // edi
  int v3; // ecx
  volatile __int32 *v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  volatile __int32 *v8; // edx
  volatile __int32 *v9; // edx
  volatile __int32 *v10; // edx
  volatile __int32 *v11; // edx

  v1 = active_threads; /*0x167285*/
  if ( !target_act ) /*0x16728d*/
    return 4; /*0x16728f*/
  ipc_thread_disable(target_act); /*0x16729d*/
  if ( target_act == v1 ) /*0x1672a7*/
  {
    v3 = splsched(); /*0x1672ae*/
    v4 = (volatile __int32 *)(target_act + 32); /*0x1672b0*/
    do /*0x1672c6*/
    {
      while ( *v4 ) /*0x1672b4*/
        ; /*0x1672b6*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1672c6*/
    if ( *(_DWORD *)(target_act + 376) ) /*0x1672c8*/
    {
      *(_DWORD *)(target_act + 376) = 0; /*0x1672d1*/
      *(_BYTE *)(target_act + 380) |= 2u; /*0x1672db*/
    }
    _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1672e4*/
    v5 = need_ast[0]; /*0x1672e7*/
    LOBYTE(v5) = LOBYTE(need_ast[0]) | 2; /*0x1672ec*/
    need_ast[0] = v5; /*0x1672ee*/
    splx(v3); /*0x1672f9*/
    return 0; /*0x1672fe*/
  }
  else
  {
    v6 = *(_DWORD *)(active_threads + 12); /*0x16730d*/
    do /*0x167322*/
    {
      while ( *(_DWORD *)v6 ) /*0x167310*/
        ; /*0x167312*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x167322*/
    v7 = splsched(); /*0x167329*/
    if ( target_act >= v1 ) /*0x16732d*/
    {
      v10 = (volatile __int32 *)(v1 + 32); /*0x167364*/
      do /*0x16737a*/
      {
        while ( *v10 ) /*0x167368*/
          ; /*0x16736a*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x16737a*/
      v11 = (volatile __int32 *)(target_act + 32); /*0x16737c*/
      do /*0x167392*/
      {
        while ( *v11 ) /*0x167380*/
          ; /*0x167382*/
      }
      while ( _InterlockedExchange(v11, 1) == 1 ); /*0x167392*/
    }
    else
    {
      v8 = (volatile __int32 *)(target_act + 32); /*0x16732f*/
      do /*0x167346*/
      {
        while ( *v8 ) /*0x167334*/
          ; /*0x167336*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x167346*/
      v9 = (volatile __int32 *)(v1 + 32); /*0x167348*/
      do /*0x16735e*/
      {
        while ( *v9 ) /*0x16734c*/
          ; /*0x16734e*/
      }
      while ( _InterlockedExchange(v9, 1) == 1 ); /*0x16735e*/
    }
    if ( *(_DWORD *)(v6 + 8) && *(_DWORD *)(v1 + 376) ) /*0x16739a*/
    {
      _InterlockedExchange((volatile __int32 *)(v1 + 32), 0); /*0x1673ca*/
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x1673cf*/
      if ( *(_DWORD *)(target_act + 376) ) /*0x1673d1*/
      {
        *(_DWORD *)(target_act + 376) = 0; /*0x1673ec*/
        _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1673f8*/
        splx(v7); /*0x1673fc*/
        thread_halt(target_act, 1); /*0x167404*/
        ipc_thread_terminate(target_act); /*0x16740a*/
        thread_deallocate(target_act); /*0x167410*/
        return 0; /*0x167415*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1673dc*/
        splx(v7); /*0x1673e0*/
        return 5; /*0x1673e5*/
      }
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(v1 + 32), 0); /*0x1673a5*/
      _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1673aa*/
      splx(v7); /*0x1673ae*/
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x1673b8*/
      thread_terminate(v1); /*0x1673bb*/
      return 5; /*0x1673c0*/
    }
  }
}
