/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166234. */
int __cdecl task_halt(volatile __int32 *a1)
{
  _DWORD *v1; // esi
  _DWORD *i; // ebx
  thread_act_t v4; // [esp+Ch] [ebp-8h]
  _DWORD *v5; // [esp+10h] [ebp-4h]

  v4 = active_threads; /*0x166246*/
  v5 = a1 + 7; /*0x16624c*/
  v1 = nullptr; /*0x16624f*/
  do /*0x166266*/
  {
    while ( *a1 ) /*0x166254*/
      ; /*0x166256*/
  }
  while ( _InterlockedExchange(a1, 1) == 1 ); /*0x166266*/
  for ( i = (_DWORD *)*v5; v5 != i; i = (_DWORD *)i[4] ) /*0x16626f*/
  {
    if ( (_DWORD *)v4 != i ) /*0x166277*/
    {
      thread_reference(i); /*0x16627a*/
      _InterlockedExchange(a1, 0); /*0x166284*/
      if ( v1 ) /*0x166288*/
        thread_deallocate(v1); /*0x16628b*/
      thread_halt(i, 1); /*0x166296*/
      v1 = i; /*0x16629b*/
      do /*0x1662b2*/
      {
        while ( *a1 ) /*0x1662a0*/
          ; /*0x1662a2*/
      }
      while ( _InterlockedExchange(a1, 1) == 1 ); /*0x1662b2*/
    }
  }
  _InterlockedExchange(a1, 0); /*0x1662be*/
  if ( v1 ) /*0x1662c2*/
    thread_deallocate(v1); /*0x1662c5*/
  return 0; /*0x1662cf*/
}
