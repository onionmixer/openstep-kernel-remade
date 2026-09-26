/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165cc0. */
kern_return_t __cdecl task_terminate(task_t target_task)
{
  thread_act_t v2; // edi
  volatile __int32 *v3; // edx
  volatile __int32 *v4; // edx
  thread_act_t *v5; // edx
  thread_act_t *v6; // eax
  volatile __int32 *v7; // edx
  thread_act_t v8; // ebx
  int v9; // ecx
  volatile __int32 *v10; // edx
  volatile __int32 *v11; // edx
  thread_act_t *v12; // eax
  task_t v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+10h] [ebp-8h]
  thread_act_t *v18; // [esp+14h] [ebp-4h]

  if ( !target_task ) /*0x165cce*/
    return 4; /*0x165cd5*/
  v18 = (thread_act_t *)(target_task + 28); /*0x165cdf*/
  v13 = *(_DWORD *)(active_threads + 12); /*0x165cea*/
  v2 = active_threads; /*0x165ced*/
  if ( target_task == v13 ) /*0x165cf1*/
  {
    do /*0x165d0a*/
    {
      while ( *(_DWORD *)target_task ) /*0x165cf8*/
        ; /*0x165cfa*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165d0a*/
    if ( *(_DWORD *)(target_task + 8) ) /*0x165d0c*/
    {
      v15 = splsched(); /*0x165d1b*/
      v3 = (volatile __int32 *)(target_task + 40); /*0x165d1e*/
      do /*0x165d36*/
      {
        while ( *v3 ) /*0x165d24*/
          ; /*0x165d26*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x165d36*/
      v4 = (volatile __int32 *)(v2 + 32); /*0x165d38*/
      do /*0x165d4e*/
      {
        while ( *v4 ) /*0x165d3c*/
          ; /*0x165d3e*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x165d4e*/
      if ( !*(_DWORD *)(v2 + 376) ) /*0x165d50*/
      {
        _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x165d5b*/
        _InterlockedExchange((volatile __int32 *)(target_task + 40), 0); /*0x165d60*/
        splx(v15); /*0x165d67*/
        _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165d71*/
        thread_terminate(v2); /*0x165d74*/
        return 5; /*0x165d7e*/
      }
      *(_DWORD *)(target_task + 8) = 0; /*0x165d8c*/
      v5 = *(thread_act_t **)(v2 + 16); /*0x165d93*/
      v6 = *(thread_act_t **)(v2 + 20); /*0x165d96*/
      if ( v18 == v5 ) /*0x165d9c*/
        *(_DWORD *)(target_task + 32) = v6; /*0x165da1*/
      else
        v5[5] = (thread_act_t)v6; /*0x165da8*/
      if ( v18 == v6 ) /*0x165dae*/
        *v18 = (thread_act_t)v5; /*0x165d87*/
      else
        v6[4] = (thread_act_t)v5; /*0x165db0*/
      _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x165db5*/
      _InterlockedExchange((volatile __int32 *)(target_task + 40), 0); /*0x165dba*/
      splx(v15); /*0x165dc1*/
      _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165dcb*/
      ipc_thread_disable(v2); /*0x165dce*/
      ipc_thread_terminate(v2); /*0x165dd4*/
      goto LABEL_41; /*0x165ddc*/
    }
LABEL_39:
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165eca*/
    return 5; /*0x165ed3*/
  }
  if ( v13 <= target_task ) /*0x165de7*/
  {
    do /*0x165e34*/
    {
      while ( *(_DWORD *)v13 ) /*0x165e1f*/
        ; /*0x165e21*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x165e34*/
    do /*0x165e4a*/
    {
      while ( *(_DWORD *)target_task ) /*0x165e38*/
        ; /*0x165e3a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165e4a*/
  }
  else
  {
    do /*0x165dfe*/
    {
      while ( *(_DWORD *)target_task ) /*0x165dec*/
        ; /*0x165dee*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165dfe*/
    do /*0x165e18*/
    {
      while ( *(_DWORD *)v13 ) /*0x165e03*/
        ; /*0x165e05*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x165e18*/
  }
  v16 = splsched(); /*0x165e51*/
  v7 = (volatile __int32 *)(v2 + 32); /*0x165e54*/
  do /*0x165e6a*/
  {
    while ( *v7 ) /*0x165e58*/
      ; /*0x165e5a*/
  }
  while ( _InterlockedExchange(v7, 1) == 1 ); /*0x165e6a*/
  if ( !*(_DWORD *)(v13 + 8) || !*(_DWORD *)(v2 + 376) ) /*0x165e75*/
  {
    _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x165e80*/
    splx(v16); /*0x165e87*/
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165e91*/
    _InterlockedExchange((volatile __int32 *)v13, 0); /*0x165e98*/
    thread_terminate(v2); /*0x165e9b*/
    return 5; /*0x165ea5*/
  }
  _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x165eae*/
  splx(v16); /*0x165eb5*/
  _InterlockedExchange((volatile __int32 *)v13, 0); /*0x165ec2*/
  if ( !*(_DWORD *)(target_task + 8) ) /*0x165ec4*/
    goto LABEL_39; /*0x165ec8*/
  *(_DWORD *)(target_task + 8) = 0; /*0x165ed8*/
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165ee1*/
LABEL_41:
  ipc_task_disable(target_task); /*0x165ee3*/
  task_hold(target_task); /*0x165eea*/
  task_dowait(target_task, 1); /*0x165ef2*/
  do /*0x165f0e*/
  {
    while ( *(_DWORD *)target_task ) /*0x165efc*/
      ; /*0x165efe*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165f0e*/
  while ( (thread_act_t *)*v18 != v18 ) /*0x165f18*/
  {
    v8 = *v18; /*0x165f1f*/
    thread_reference(*v18); /*0x165f22*/
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165f2c*/
    thread_force_terminate(v8); /*0x165f2f*/
    thread_deallocate(v8); /*0x165f35*/
    thread_block_with_continuation(0); /*0x165f3c*/
    do /*0x165f56*/
    {
      while ( *(_DWORD *)target_task ) /*0x165f44*/
        ; /*0x165f46*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165f56*/
  }
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165f64*/
  ipc_task_terminate(target_task); /*0x165f67*/
  do /*0x165f8a*/
  {
    while ( *(_DWORD *)target_task ) /*0x165f78*/
      ; /*0x165f7a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165f8a*/
  v9 = *(_DWORD *)(target_task + 4) - 1; /*0x165f8f*/
  *(_DWORD *)(target_task + 4) = v9; /*0x165f92*/
  _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165f98*/
  if ( !v9 ) /*0x165f9c*/
  {
    v14 = *(_DWORD *)(target_task + 44); /*0x165fa1*/
    v10 = (volatile __int32 *)(v14 + 344); /*0x165fa6*/
    do /*0x165fbe*/
    {
      while ( *v10 ) /*0x165fac*/
        ; /*0x165fae*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x165fbe*/
    pset_remove_task((_DWORD *)v14, (_DWORD *)target_task); /*0x165fc5*/
    _InterlockedExchange((volatile __int32 *)(v14 + 344), 0); /*0x165fd2*/
    pset_deallocate(v14); /*0x165fd9*/
    vm_map_deallocate(*(_DWORD *)(target_task + 12)); /*0x165fe2*/
    ipc_space_release(*(_DWORD *)(target_task + 136)); /*0x165fee*/
    pcb_common_terminate(target_task); /*0x165ff4*/
    utask_free(*(int **)(target_task + 56)); /*0x165ffd*/
    zfree(task_zone, target_task); /*0x16600a*/
  }
  if ( *(_DWORD *)(v2 + 12) == target_task ) /*0x166015*/
  {
    do /*0x16602a*/
    {
      while ( *(_DWORD *)target_task ) /*0x166018*/
        ; /*0x16601a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x16602a*/
    v17 = splsched(); /*0x166031*/
    v11 = (volatile __int32 *)(target_task + 40); /*0x166034*/
    do /*0x16604a*/
    {
      while ( *v11 ) /*0x166038*/
        ; /*0x16603a*/
    }
    while ( _InterlockedExchange(v11, 1) == 1 ); /*0x16604a*/
    v12 = *(thread_act_t **)(target_task + 32); /*0x16604f*/
    if ( v18 == v12 ) /*0x166054*/
      *v18 = v2; /*0x166056*/
    else
      v12[4] = v2; /*0x16605c*/
    *(_DWORD *)(v2 + 20) = v12; /*0x16605f*/
    *(_DWORD *)(v2 + 16) = v18; /*0x166065*/
    *(_DWORD *)(target_task + 32) = v2; /*0x166068*/
    _InterlockedExchange((volatile __int32 *)(target_task + 40), 0); /*0x16606d*/
    splx(v17); /*0x166074*/
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x16607e*/
    thread_terminate(v2); /*0x166081*/
  }
  return 0; /*0x16608b*/
}
