/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16848c. */
thread_act_t __cdecl kernel_thread(task_t parent_task, int a2, int a3)
{
  thread_act_t v3; // eax
  thread_act_t v4; // eax
  thread_act_t v5; // ebx
  int v6; // esi
  volatile __int32 *v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edx
  thread_act_t child_act; // [esp+8h] [ebp-4h] BYREF

  thread_create(parent_task, &child_act); /*0x1684a2*/
  thread_deallocate(child_act); /*0x1684ab*/
  v3 = child_act; /*0x1684b0*/
  *(_DWORD *)(child_act + 52) = a2; /*0x1684b6*/
  *(_DWORD *)(v3 + 196) = a3; /*0x1684b9*/
  thread_doswapin(v3); /*0x1684c0*/
  v4 = child_act; /*0x1684c5*/
  *(_DWORD *)(child_act + 84) = 31; /*0x1684c8*/
  *(_DWORD *)(v4 + 80) = 24; /*0x1684cf*/
  *(_DWORD *)(v4 + 88) = 24; /*0x1684d6*/
  v5 = v4; /*0x1684dd*/
  if ( v4 ) /*0x1684e4*/
  {
    v6 = splsched(); /*0x1684eb*/
    v7 = (volatile __int32 *)(v5 + 32); /*0x1684ed*/
    do /*0x168502*/
    {
      while ( *v7 ) /*0x1684f0*/
        ; /*0x1684f2*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x168502*/
    v8 = *(_DWORD *)(v5 + 140); /*0x168504*/
    if ( v8 > 0 ) /*0x16850c*/
    {
      *(_DWORD *)(v5 + 140) = v8 - 1; /*0x168511*/
      if ( v8 == 1 ) /*0x16851a*/
      {
        v9 = *(_DWORD *)(v5 + 64); /*0x16851c*/
        *(_DWORD *)(v5 + 64) = v9 - 1; /*0x168522*/
        if ( v9 == 1 ) /*0x168528*/
        {
          v10 = *(_DWORD *)(v5 + 76); /*0x16852a*/
          v11 = v10; /*0x16852d*/
          LOBYTE(v11) = v10 & 0xED; /*0x16852f*/
          *(_DWORD *)(v5 + 76) = v11; /*0x168532*/
          if ( (v10 & 5) == 0 ) /*0x168537*/
          {
            LOBYTE(v11) = v10 & 0xE9 | 4; /*0x168539*/
            *(_DWORD *)(v5 + 76) = v11; /*0x16853c*/
            thread_setrun((char **)v5, 1); /*0x168542*/
          }
        }
      }
    }
    _InterlockedExchange((volatile __int32 *)(v5 + 32), 0); /*0x16854c*/
    splx(v6); /*0x168550*/
  }
  return child_act; /*0x16855b*/
}
