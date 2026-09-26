
kern_return_t
_task_create(task_t target_task,ledger_array_t ledgers,mach_msg_type_number_t ledgersCnt,
            boolean_t inherit_memory,task_t *child_task)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  puVar3 = (undefined4 *)_zalloc(_task_zone);
  if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_task_create__no_memory_for_task_s_001dfb9a);
  }
  uVar4 = _zalloc(_u_task_zone);
  puVar3[0xe] = uVar4;
  _utask_zero(puVar3);
  puVar3[1] = 2;
  if ((undefined4 *)ledgersCnt == &_kernel_task) {
    puVar3[3] = _kernel_map;
  }
  else if (ledgers == (ledger_array_t)0x0) {
    uVar4 = _pmap_create(0,0,~_page_mask & 0xc0000000,1);
    uVar4 = _vm_map_create(uVar4);
    puVar3[3] = uVar4;
  }
  else {
    uVar4 = _vm_map_fork(*(undefined4 *)(target_task + 0xc));
    puVar3[3] = uVar4;
  }
  *puVar3 = 0;
  puVar3[8] = puVar3 + 7;
  puVar3[7] = puVar3 + 7;
  puVar3[10] = 0;
  puVar3[6] = 0;
  puVar3[2] = 1;
  puVar3[0x11] = 0;
  puVar3[9] = 0;
  puVar3[0x10] = 0;
  _pcb_common_init(puVar3);
  puVar3[0x14] = 0;
  _ipc_task_init(puVar3,target_task);
  puVar3[0x15] = 0;
  puVar3[0x16] = 0;
  puVar3[0x17] = 0;
  puVar3[0x18] = 0;
  if (target_task == 0) {
    puVar3[0x13] = 0;
    puVar5 = &_default_pset;
    _pset_reference(&_default_pset);
    puVar3[0x12] = 10;
  }
  else {
    puVar3[0x13] = *(undefined4 *)(target_task + 0x4c);
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar2 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar2 == 1);
    puVar5 = *(undefined **)(target_task + 0x2c);
    if (*(int *)(puVar5 + 0x154) == 0) {
      puVar5 = &_default_pset;
    }
    _pset_reference(puVar5);
    puVar3[0x12] = *(undefined4 *)(target_task + 0x48);
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
  }
  piVar1 = (int *)(puVar5 + 0x158);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _pset_add_task(puVar5,puVar3);
  LOCK();
  *(undefined4 *)(puVar5 + 0x158) = 0;
  UNLOCK();
  puVar3[0xc] = 1;
  puVar3[0xd] = 0;
  _ipc_task_enable(puVar3);
  *(undefined4 **)ledgersCnt = puVar3;
  return 0;
}

