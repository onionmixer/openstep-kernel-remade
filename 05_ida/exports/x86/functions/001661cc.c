/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1661cc. */
int __cdecl task_release(int a1)
{
  int v2; // eax
  int v3; // ebx

  do /*0x1661ea*/
  {
    while ( *(_DWORD *)a1 ) /*0x1661d8*/
      ; /*0x1661da*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1661ea*/
  if ( *(_DWORD *)(a1 + 8) ) /*0x1661ec*/
  {
    --*(_DWORD *)(a1 + 24); /*0x166200*/
    v2 = *(_DWORD *)(a1 + 28); /*0x166206*/
    if ( a1 + 28 != v2 ) /*0x16620b*/
    {
      do /*0x166220*/
      {
        v3 = *(_DWORD *)(v2 + 16); /*0x166210*/
        thread_release(v2); /*0x166214*/
        v2 = v3; /*0x166219*/
      }
      while ( a1 + 28 != v3 ); /*0x166220*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x166224*/
    return 0; /*0x166226*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1661f4*/
    return 5; /*0x1661f6*/
  }
}
