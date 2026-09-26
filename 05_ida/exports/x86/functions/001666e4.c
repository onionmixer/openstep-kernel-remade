/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1666e4. */
kern_return_t __cdecl task_info(
        task_name_t target_task,
        task_flavor_t flavor,
        task_info_t task_info_out,
        mach_msg_type_number_t *task_info_outCnt)
{
  volatile __int32 *v4; // ecx
  vm_map_t v5; // eax
  int i; // esi
  volatile __int32 *v7; // edx
  int v8; // eax
  int v9; // eax
  int v11; // [esp+Ch] [ebp-18h]
  volatile __int32 *v12; // [esp+10h] [ebp-14h]
  _DWORD v13[2]; // [esp+14h] [ebp-10h] BYREF
  _DWORD v14[2]; // [esp+1Ch] [ebp-8h] BYREF

  v4 = (volatile __int32 *)target_task; /*0x1666ed*/
  if ( !target_task ) /*0x1666f8*/
    return 4; /*0x1666f8*/
  if ( flavor == 1 ) /*0x166701*/
  {
    if ( *task_info_outCnt > 7 ) /*0x16671a*/
    {
      if ( kernel_task == target_task ) /*0x166726*/
        v5 = kernel_map; /*0x166730*/
      else
        v5 = *(_DWORD *)(target_task + 12); /*0x166728*/
      task_info_out[2] = *(_DWORD *)(v5 + 40); /*0x166738*/
      task_info_out[3] = page_size * *(_DWORD *)(*(_DWORD *)(v5 + 36) + 16); /*0x166748*/
      do /*0x16675e*/
      {
        while ( *(_DWORD *)target_task ) /*0x16674c*/
          ; /*0x16674e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x16675e*/
      task_info_out[1] = *(_DWORD *)(target_task + 72); /*0x166763*/
      *task_info_out = *(_DWORD *)(target_task + 68); /*0x166769*/
      task_info_out[4] = *(_DWORD *)(target_task + 84); /*0x16676e*/
      task_info_out[5] = *(_DWORD *)(target_task + 88); /*0x166774*/
      task_info_out[6] = *(_DWORD *)(target_task + 92); /*0x16677a*/
      task_info_out[7] = *(_DWORD *)(target_task + 96); /*0x166780*/
      _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x166785*/
      *task_info_outCnt = 8; /*0x16678a*/
      return 0; /*0x166790*/
    }
    return 4; /*0x166895*/
  }
  if ( flavor != 3 || *task_info_outCnt <= 3 ) /*0x16679e*/
    return 4; /*0x16679e*/
  *task_info_out = 0; /*0x1667a6*/
  task_info_out[1] = 0; /*0x1667ac*/
  task_info_out[2] = 0; /*0x1667b3*/
  task_info_out[3] = 0; /*0x1667ba*/
  do /*0x1667d6*/
  {
    while ( *(_DWORD *)target_task ) /*0x1667c4*/
      ; /*0x1667c6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x1667d6*/
  for ( i = *(_DWORD *)(target_task + 28); v4 + 7 != (volatile __int32 *)i; i = *(_DWORD *)(i + 16) ) /*0x1667d8*/
  {
    v12 = v4; /*0x1667e0*/
    v11 = splsched(); /*0x1667e8*/
    v7 = (volatile __int32 *)(i + 32); /*0x1667eb*/
    do /*0x166806*/
    {
      while ( *v7 ) /*0x1667f4*/
        ; /*0x1667f6*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x166806*/
    thread_read_times(i, v14, v13); /*0x166814*/
    _InterlockedExchange((volatile __int32 *)(i + 32), 0); /*0x16681e*/
    splx(v11); /*0x166825*/
    task_info_out[1] += v14[1]; /*0x16682d*/
    *task_info_out += v14[0]; /*0x166833*/
    v8 = task_info_out[1]; /*0x166835*/
    v4 = v12; /*0x16683b*/
    if ( v8 > 999999 ) /*0x166843*/
    {
      task_info_out[1] = v8 - 1000000; /*0x16684a*/
      ++*task_info_out; /*0x16684d*/
    }
    task_info_out[3] += v13[1]; /*0x166852*/
    task_info_out[2] += v13[0]; /*0x166858*/
    v9 = task_info_out[3]; /*0x16685b*/
    if ( v9 > 999999 ) /*0x166863*/
    {
      task_info_out[3] = v9 - 1000000; /*0x16686a*/
      ++task_info_out[2]; /*0x16686d*/
    }
  }
  _InterlockedExchange(v4, 0); /*0x166880*/
  *task_info_outCnt = 4; /*0x166885*/
  return 0; /*0x16689d*/
}
