/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166094. */
int __cdecl task_hold(int a1)
{
  int i; // ebx
  thread_act_t v3; // [esp+Ch] [ebp-4h]

  v3 = active_threads; /*0x1660a6*/
  do /*0x1660be*/
  {
    while ( *(_DWORD *)a1 ) /*0x1660ac*/
      ; /*0x1660ae*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1660be*/
  if ( *(_DWORD *)(a1 + 8) ) /*0x1660c0*/
  {
    ++*(_DWORD *)(a1 + 24); /*0x1660d4*/
    for ( i = *(_DWORD *)(a1 + 28); a1 + 28 != i; i = *(_DWORD *)(i + 16) ) /*0x1660df*/
    {
      if ( v3 != i ) /*0x1660e7*/
        thread_hold(i); /*0x1660ea*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1660fb*/
    return 0; /*0x1660fd*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1660c8*/
    return 5; /*0x1660ca*/
  }
}
