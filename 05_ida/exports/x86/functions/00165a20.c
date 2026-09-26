/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165a20. */
kern_return_t __cdecl task_create(
        task_t target_task,
        ledger_array_t ledgers,
        mach_msg_type_number_t ledgersCnt,
        boolean_t inherit_memory,
        task_t *child_task)
{
  _DWORD *v5; // ebx
  int v6; // eax
  char *v7; // esi
  volatile __int32 *v8; // edx
  int v10; // [esp-Ch] [ebp-18h]
  unsigned int v11; // [esp-8h] [ebp-14h]

  v5 = (_DWORD *)zalloc(task_zone); /*0x165a35*/
  if ( !v5 ) /*0x165a3c*/
    panic(aTaskCreateNoMe); /*0x165a43*/
  v5[14] = zalloc(u_task_zone); /*0x165a57*/
  utask_zero((int)v5); /*0x165a5b*/
  v5[1] = 2; /*0x165a60*/
  if ( (task_t *)ledgersCnt == &kernel_task ) /*0x165a71*/
  {
    v5[3] = kernel_map; /*0x165a79*/
  }
  else if ( ledgers ) /*0x165a84*/
  {
    v5[3] = vm_map_fork(*(_DWORD *)(target_task + 12)); /*0x165a8f*/
  }
  else
  {
    v11 = ~page_mask & 0xC0000000; /*0x165aab*/
    v10 = ~page_mask & page_mask; /*0x165aae*/
    v6 = pmap_create(0); /*0x165ab1*/
    v5[3] = vm_map_create(v6, v10, v11, 1); /*0x165abf*/
  }
  *v5 = 0; /*0x165ac5*/
  v5[8] = v5 + 7; /*0x165ace*/
  v5[7] = v5 + 7; /*0x165ad1*/
  v5[10] = 0; /*0x165ad4*/
  v5[6] = 0; /*0x165adb*/
  v5[2] = 1; /*0x165ae2*/
  v5[17] = 0; /*0x165ae9*/
  v5[9] = 0; /*0x165af0*/
  v5[16] = 0; /*0x165af7*/
  pcb_common_init(v5); /*0x165aff*/
  v5[20] = 0; /*0x165b04*/
  ipc_task_init(v5, target_task); /*0x165b0d*/
  v5[21] = 0; /*0x165b12*/
  v5[22] = 0; /*0x165b19*/
  v5[23] = 0; /*0x165b20*/
  v5[24] = 0; /*0x165b27*/
  if ( target_task ) /*0x165b33*/
  {
    v5[19] = *(_DWORD *)(target_task + 76); /*0x165b38*/
    do /*0x165b4e*/
    {
      while ( *(_DWORD *)target_task ) /*0x165b3c*/
        ; /*0x165b3e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)target_task, 1) == 1 ); /*0x165b4e*/
    v7 = *(char **)(target_task + 44); /*0x165b50*/
    if ( !*((_DWORD *)v7 + 85) ) /*0x165b53*/
      v7 = (char *)&default_pset; /*0x165b5c*/
    pset_reference((int)v7); /*0x165b62*/
    v5[18] = *(_DWORD *)(target_task + 72); /*0x165b6a*/
    _InterlockedExchange((volatile __int32 *)target_task, 0); /*0x165b72*/
  }
  else
  {
    v5[19] = 0; /*0x165b78*/
    v7 = (char *)&default_pset; /*0x165b7f*/
    pset_reference((int)&default_pset); /*0x165b89*/
    v5[18] = 10; /*0x165b8e*/
  }
  v8 = (volatile __int32 *)(v7 + 344); /*0x165b98*/
  do /*0x165bb2*/
  {
    while ( *v8 ) /*0x165ba0*/
      ; /*0x165ba2*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x165bb2*/
  pset_add_task(v7, v5); /*0x165bb6*/
  _InterlockedExchange((volatile __int32 *)v7 + 86, 0); /*0x165bc0*/
  v5[12] = 1; /*0x165bc6*/
  v5[13] = 0; /*0x165bcd*/
  ipc_task_enable((int)v5); /*0x165bd5*/
  *(_DWORD *)ledgersCnt = v5; /*0x165bdd*/
  return 0; /*0x165be4*/
}
