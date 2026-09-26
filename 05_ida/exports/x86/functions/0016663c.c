/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16663c. */
kern_return_t __cdecl task_resume(task_t target_task)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // ebx

  if ( !target_task ) /*0x166647*/
    return 4; /*0x16664e*/
  v2 = 0; /*0x166654*/
  do /*0x16666a*/
  {
    while ( *(_DWORD *)target_task ) /*0x166658*/
      ; /*0x16665a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x16666a*/
  v3 = *(_DWORD *)(target_task + 68); /*0x16666c*/
  if ( v3 <= 0 ) /*0x166671*/
    goto LABEL_7; /*0x166671*/
  *(_DWORD *)(target_task + 68) = v3 - 1; /*0x166683*/
  if ( v3 == 1 ) /*0x166689*/
    v2 = 1; /*0x16668b*/
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x166692*/
  if ( v2 ) /*0x166696*/
  {
    do /*0x1666aa*/
    {
      while ( *(_DWORD *)target_task ) /*0x166698*/
        ; /*0x16669a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x1666aa*/
    if ( !*(_DWORD *)(target_task + 8) ) /*0x1666b0*/
    {
LABEL_7:
      _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x166673*/
      return 5; /*0x16667c*/
    }
    --*(_DWORD *)(target_task + 24); /*0x1666b2*/
    v4 = *(_DWORD *)(target_task + 28); /*0x1666b8*/
    if ( target_task + 28 != v4 ) /*0x1666bd*/
    {
      do /*0x1666d0*/
      {
        v5 = *(_DWORD *)(v4 + 16); /*0x1666c0*/
        thread_release(v4); /*0x1666c4*/
        v4 = v5; /*0x1666c9*/
      }
      while ( target_task + 28 != v5 ); /*0x1666d0*/
    }
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x1666d4*/
  }
  return 0; /*0x1666db*/
}
