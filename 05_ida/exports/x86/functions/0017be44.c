/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17be44. */
thread_act_t __cdecl procdup(int a1, int a2)
{
  kern_return_t v2; // eax
  task_t v3; // edx
  kern_return_t v4; // eax
  mach_msg_type_number_t v5; // edx
  thread_act_t v6; // edx
  thread_act_t v7; // edx
  boolean_t v9; // [esp+0h] [ebp-14h]
  task_t *v10; // [esp+4h] [ebp-10h]
  thread_act_t child_act; // [esp+Ch] [ebp-8h] BYREF
  mach_msg_type_number_t ledgersCnt; // [esp+10h] [ebp-4h] BYREF

  v2 = task_create( /*0x17be6b*/
         *(_DWORD *)(a2 + 104),
         (ledger_array_t)(kernel_task != *(_DWORD *)(a2 + 104)),
         (mach_msg_type_number_t)&ledgersCnt,
         v9,
         v10);
  if ( v2 )
    printf("fork/procdup: task_create failed. Code: 0x%x\n", v2);
  *(_DWORD *)(a1 + 104) = ledgersCnt; /*0x17be88*/
  task_deallocate(ledgersCnt); /*0x17be8f*/
  v3 = ledgersCnt; /*0x17be94*/
  *(_DWORD *)(ledgersCnt + 60) = a1; /*0x17be97*/
  v4 = thread_create(v3, &child_act); /*0x17be9f*/
  if ( v4 )
    printf("fork/procdup: thread_create failed. Code: 0x%x\n", v4);
  thread_deallocate(child_act); /*0x17bebd*/
  compute_priority((_DWORD *)child_act, 0); /*0x17bec8*/
  bcopy(*(const void **)(*(_DWORD *)(a2 + 104) + 56), *(void **)(ledgersCnt + 56), 0x298u); /*0x17bee0*/
  bzero((void *)(*(_DWORD *)(ledgersCnt + 56) + 584), 0x18u); /*0x17bef3*/
  v5 = ledgersCnt; /*0x17bef8*/
  *(_DWORD *)(*(_DWORD *)(ledgersCnt + 56) + 348) = 0; /*0x17befe*/
  expand_fdlist(*(_DWORD *)(v5 + 56), *(_DWORD *)(*(_DWORD *)(v5 + 56) + 344)); /*0x17bf16*/
  bcopy( /*0x17bf40*/
    *(const void **)(*(_DWORD *)(*(_DWORD *)(a2 + 104) + 56) + 336),
    *(void **)(*(_DWORD *)(ledgersCnt + 56) + 336),
    4 * (*(_DWORD *)(*(_DWORD *)(ledgersCnt + 56) + 344) + 1));
  bcopy( /*0x17bf67*/
    *(const void **)(*(_DWORD *)(*(_DWORD *)(a2 + 104) + 56) + 340),
    *(void **)(*(_DWORD *)(ledgersCnt + 56) + 340),
    *(_DWORD *)(*(_DWORD *)(ledgersCnt + 56) + 344) + 1);
  v6 = child_act; /*0x17bf6c*/
  **(_DWORD **)(*(_DWORD *)(child_act + 12) + 56) = a1; /*0x17bf75*/
  bzero((void *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 56) + 368), 0x48u); /*0x17bf88*/
  bzero((void *)(*(_DWORD *)(*(_DWORD *)(child_act + 12) + 56) + 440), 0x48u); /*0x17bf9e*/
  v7 = child_act; /*0x17bfa3*/
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(child_act + 12) + 56) + 44) = 0; /*0x17bfac*/
  return v7; /*0x17bfb8*/
}
