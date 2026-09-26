/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16649c. */
kern_return_t __cdecl task_suspend(task_t target_task)
{
  int v2; // edx
  int v3; // eax
  int i; // ebx
  _DWORD *v5; // edi
  _DWORD *v6; // ebx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // [esp+Ch] [ebp-10h]
  thread_act_t v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  thread_act_t v12; // [esp+18h] [ebp-4h]

  if ( !target_task ) /*0x1664aa*/
    return 4; /*0x1664b1*/
  v2 = 0; /*0x1664b8*/
  do /*0x1664ce*/
  {
    while ( *(_DWORD *)target_task ) /*0x1664bc*/
      ; /*0x1664be*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x1664ce*/
  v3 = *(_DWORD *)(target_task + 68); /*0x1664d0*/
  *(_DWORD *)(target_task + 68) = v3 + 1; /*0x1664d6*/
  if ( !v3 ) /*0x1664db*/
    v2 = 1; /*0x1664dd*/
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x1664e4*/
  if ( v2 ) /*0x1664e8*/
  {
    v12 = active_threads; /*0x1664f4*/
    do /*0x16650a*/
    {
      while ( *(_DWORD *)target_task ) /*0x1664f8*/
        ; /*0x1664fa*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x16650a*/
    if ( !*(_DWORD *)(target_task + 8) ) /*0x16650c*/
    {
      _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x166514*/
      return 5; /*0x1665f8*/
    }
    ++*(_DWORD *)(target_task + 24); /*0x16651c*/
    for ( i = *(_DWORD *)(target_task + 28); target_task + 28 != i; i = *(_DWORD *)(i + 16) ) /*0x166527*/
    {
      if ( v12 != i ) /*0x16652f*/
        thread_hold(i); /*0x166532*/
    }
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x166543*/
    v11 = 0; /*0x166554*/
    v10 = active_threads; /*0x166561*/
    v9 = (_DWORD *)(target_task + 28); /*0x166567*/
    v5 = nullptr; /*0x16656a*/
    do /*0x16657e*/
    {
      while ( *(_DWORD *)target_task ) /*0x16656c*/
        ; /*0x16656e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x16657e*/
    v6 = (_DWORD *)*v9; /*0x166583*/
    if ( v9 != (_DWORD *)*v9 ) /*0x166587*/
    {
      while ( *(_DWORD *)(target_task + 8) ) /*0x166590*/
      {
        if ( (_DWORD *)v10 != v6 ) /*0x166595*/
        {
          thread_reference(v6); /*0x166598*/
          _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x1665a2*/
          if ( v5 ) /*0x1665a6*/
            thread_deallocate(v5); /*0x1665a9*/
          thread_dowait(v6, 1); /*0x1665b4*/
          v5 = v6; /*0x1665b9*/
          do /*0x1665d2*/
          {
            while ( *(_DWORD *)target_task ) /*0x1665c0*/
              ; /*0x1665c2*/
          }
          while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x1665d2*/
        }
        v6 = (_DWORD *)v6[4]; /*0x1665d4*/
        if ( v9 == v6 ) /*0x1665da*/
          goto LABEL_31; /*0x1665da*/
      }
      v11 = 5; /*0x166548*/
    }
LABEL_31:
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x1665dc*/
    if ( v5 ) /*0x1665e2*/
      thread_deallocate(v5); /*0x1665e5*/
    if ( v11 ) /*0x1665f1*/
      return 5; /*0x1665f1*/
    if ( *(_DWORD *)(active_threads + 12) == target_task ) /*0x166604*/
    {
      thread_hold(active_threads); /*0x166607*/
      v7 = splsched(); /*0x166611*/
      v8 = need_ast[0]; /*0x166616*/
      LOBYTE(v8) = LOBYTE(need_ast[0]) | 4; /*0x16661b*/
      need_ast[0] = v8; /*0x16661d*/
      splx(v7); /*0x166628*/
    }
  }
  return 0; /*0x166632*/
}
