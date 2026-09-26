/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166c48. */
kern_return_t __cdecl thread_create(task_t parent_task, thread_act_t *child_act)
{
  volatile __int32 *v3; // edx
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  volatile __int32 *v8; // edx
  int v9; // edx
  _DWORD *target_act; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( !parent_task ) /*0x166c56*/
    return 4; /*0x166c58*/
  target_act = (_DWORD *)zalloc(thread_zone); /*0x166c70*/
  if ( !target_act ) /*0x166c78*/
    return 6; /*0x166c7a*/
  qmemcpy(target_act, &thread_template, 0x18Cu); /*0x166c94*/
  target_act[3] = parent_task; /*0x166c96*/
  target_act[8] = 0; /*0x166c9c*/
  target_act[28] = sched_tick; /*0x166ca9*/
  thread_timeout_setup(target_act); /*0x166cad*/
  pcb_init(target_act); /*0x166cb6*/
  ipc_thread_init(target_act); /*0x166cbf*/
  target_act[33] = zalloc(u_thread_zone); /*0x166cd0*/
  uarea_zero((int)target_act); /*0x166cd7*/
  uarea_init((int)target_act); /*0x166cdd*/
  do /*0x166cfa*/
  {
    while ( *(_DWORD *)parent_task ) /*0x166ce8*/
      ; /*0x166cea*/
  }
  while ( _InterlockedExchange((volatile __int32 *)parent_task, 1) == 1 ); /*0x166cfa*/
  v11 = *(_DWORD *)(parent_task + 44); /*0x166cff*/
  pset_reference(v11); /*0x166d03*/
  _InterlockedExchange((volatile __int32 *)parent_task, 0); /*0x166d0d*/
  while ( 1 ) /*0x166d12*/
  {
    v3 = (volatile __int32 *)(v11 + 344); /*0x166d12*/
    do /*0x166d2a*/
    {
      while ( *v3 ) /*0x166d18*/
        ; /*0x166d1a*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x166d2a*/
    do /*0x166d3e*/
    {
      while ( *(_DWORD *)parent_task ) /*0x166d2c*/
        ; /*0x166d2e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)parent_task, 1) == 1 ); /*0x166d3e*/
    v4 = *(_DWORD **)(parent_task + 44); /*0x166d40*/
    if ( !v4[85] ) /*0x166d43*/
      v4 = &default_pset; /*0x166d4c*/
    if ( (_DWORD *)v11 == v4 ) /*0x166d54*/
      break; /*0x166d54*/
    pset_reference((int)v4); /*0x166d57*/
    _InterlockedExchange((volatile __int32 *)parent_task, 0); /*0x166d61*/
    _InterlockedExchange((volatile __int32 *)(v11 + 344), 0); /*0x166d68*/
    pset_deallocate(v11); /*0x166d6f*/
    v11 = (int)v4; /*0x166d74*/
  }
  target_act[20] = *(_DWORD *)(parent_task + 72); /*0x166d82*/
  v5 = *(_DWORD *)(v11 + 356); /*0x166d88*/
  if ( target_act[21] > v5 ) /*0x166d94*/
    target_act[21] = v5; /*0x166d96*/
  v6 = target_act[21]; /*0x166d9c*/
  if ( target_act[20] > v6 ) /*0x166da2*/
    target_act[20] = v6; /*0x166da4*/
  compute_priority(target_act, 1); /*0x166dad*/
  target_act[16] = *(_DWORD *)(parent_task + 24) + 1; /*0x166db9*/
  pset_add_thread((_DWORD *)v11, target_act); /*0x166dc1*/
  if ( *(_DWORD *)(v11 + 296) ) /*0x166dc9*/
    ++target_act[16]; /*0x166dd5*/
  ++*(_DWORD *)(parent_task + 4); /*0x166dd8*/
  v7 = splsched(); /*0x166de0*/
  v8 = (volatile __int32 *)(parent_task + 40); /*0x166de2*/
  do /*0x166dfa*/
  {
    while ( *v8 ) /*0x166de8*/
      ; /*0x166dea*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x166dfa*/
  ++*(_DWORD *)(parent_task + 36); /*0x166dfc*/
  v9 = *(_DWORD *)(parent_task + 32); /*0x166dff*/
  if ( parent_task + 28 == v9 ) /*0x166e07*/
    *(_DWORD *)(parent_task + 28) = target_act; /*0x166e0c*/
  else
    *(_DWORD *)(v9 + 16) = target_act; /*0x166e17*/
  target_act[5] = v9; /*0x166e1d*/
  target_act[4] = parent_task + 28; /*0x166e23*/
  *(_DWORD *)(parent_task + 32) = target_act; /*0x166e26*/
  _InterlockedExchange((volatile __int32 *)(parent_task + 40), 0); /*0x166e2b*/
  splx(v7); /*0x166e2f*/
  target_act[94] = 1; /*0x166e34*/
  if ( *(_DWORD *)(parent_task + 8) ) /*0x166e41*/
  {
    _InterlockedExchange((volatile __int32 *)parent_task, 0); /*0x166e72*/
    _InterlockedExchange((volatile __int32 *)(v11 + 344), 0); /*0x166e79*/
    ipc_thread_enable((int)target_act); /*0x166e83*/
    ++nthreads; /*0x166e88*/
    *child_act = (thread_act_t)target_act; /*0x166e91*/
    return 0; /*0x166e93*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)parent_task, 0); /*0x166e49*/
    _InterlockedExchange((volatile __int32 *)(v11 + 344), 0); /*0x166e50*/
    thread_terminate((thread_act_t)target_act); /*0x166e5a*/
    thread_deallocate(target_act); /*0x166e63*/
    return 5; /*0x166e68*/
  }
}
