/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1668a4. */
int __cdecl task_suspend_nowait(int a1)
{
  int v2; // edx
  int v3; // eax
  int i; // ebx
  thread_act_t v5; // [esp+Ch] [ebp-4h]

  if ( !a1 ) /*0x1668b2*/
    return 4; /*0x1668b9*/
  v2 = 0; /*0x1668c0*/
  do /*0x1668d6*/
  {
    while ( *(_DWORD *)a1 ) /*0x1668c4*/
      ; /*0x1668c6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1668d6*/
  v3 = *(_DWORD *)(a1 + 68); /*0x1668d8*/
  *(_DWORD *)(a1 + 68) = v3 + 1; /*0x1668de*/
  if ( !v3 ) /*0x1668e3*/
    v2 = 1; /*0x1668e5*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1668ec*/
  if ( v2 ) /*0x1668f0*/
  {
    v5 = active_threads; /*0x1668f8*/
    do /*0x16690e*/
    {
      while ( *(_DWORD *)a1 ) /*0x1668fc*/
        ; /*0x1668fe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16690e*/
    if ( !*(_DWORD *)(a1 + 8) ) /*0x166910*/
    {
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x166918*/
      return 5; /*0x16694d*/
    }
    ++*(_DWORD *)(a1 + 24); /*0x16691c*/
    for ( i = *(_DWORD *)(a1 + 28); a1 + 28 != i; i = *(_DWORD *)(i + 16) ) /*0x166927*/
    {
      if ( v5 != i ) /*0x16692f*/
        thread_hold(i); /*0x166932*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x166943*/
    if ( *(_DWORD *)(active_threads + 12) == a1 ) /*0x166958*/
      thread_hold(active_threads); /*0x16695b*/
  }
  return 0; /*0x166965*/
}
