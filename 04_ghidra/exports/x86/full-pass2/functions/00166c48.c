/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166c48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

kern_return_t _thread_create(task_t parent_task,thread_act_t *child_act)

{
  kern_return_t kVar1;
  undefined4 *target_act;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined *local_8;
  
  if (parent_task == 0) {
    kVar1 = 4;
  }
  else {
    target_act = (undefined4 *)_zalloc(_thread_zone);
    if (target_act == (undefined4 *)0x0) {
      kVar1 = 6;
    }
    else {
      puVar5 = &_thread_template;
      puVar7 = target_act;
      for (iVar3 = 99; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      target_act[3] = parent_task;
      target_act[8] = 0;
      target_act[0x1c] = _sched_tick;
      _thread_timeout_setup(target_act);
      _pcb_init(target_act);
      _ipc_thread_init(target_act);
      uVar2 = _zalloc(_u_thread_zone);
      target_act[0x21] = uVar2;
      _uarea_zero(target_act);
      _uarea_init(target_act);
      do {
        do {
        } while (*(int *)parent_task != 0);
        LOCK();
        iVar3 = *(int *)parent_task;
        *(undefined4 *)parent_task = 1;
        UNLOCK();
      } while (iVar3 == 1);
      local_8 = *(undefined **)(parent_task + 0x2c);
      _pset_reference(local_8);
      LOCK();
      *(undefined4 *)parent_task = 0;
      UNLOCK();
      while( true ) {
        piVar4 = (int *)(local_8 + 0x158);
        do {
          do {
          } while (*piVar4 != 0);
          LOCK();
          iVar3 = *piVar4;
          *piVar4 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        do {
          do {
          } while (*(int *)parent_task != 0);
          LOCK();
          iVar3 = *(int *)parent_task;
          *(undefined4 *)parent_task = 1;
          UNLOCK();
        } while (iVar3 == 1);
        puVar6 = *(undefined **)(parent_task + 0x2c);
        if (*(int *)(puVar6 + 0x154) == 0) {
          puVar6 = &_default_pset;
        }
        if (local_8 == puVar6) break;
        _pset_reference(puVar6);
        LOCK();
        *(undefined4 *)parent_task = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(local_8 + 0x158) = 0;
        UNLOCK();
        _pset_deallocate(local_8);
        local_8 = puVar6;
      }
      target_act[0x14] = *(undefined4 *)(parent_task + 0x48);
      if (*(int *)(local_8 + 0x164) < (int)target_act[0x15]) {
        target_act[0x15] = *(int *)(local_8 + 0x164);
      }
      if ((int)target_act[0x15] < (int)target_act[0x14]) {
        target_act[0x14] = target_act[0x15];
      }
      _compute_priority(target_act,1);
      target_act[0x10] = *(int *)(parent_task + 0x18) + 1;
      _pset_add_thread(local_8,target_act);
      if (*(int *)(local_8 + 0x128) != 0) {
        target_act[0x10] = target_act[0x10] + 1;
      }
      *(int *)(parent_task + 4) = *(int *)(parent_task + 4) + 1;
      uVar2 = _splsched();
      piVar4 = (int *)(parent_task + 0x28);
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar3 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *(int *)(parent_task + 0x24) = *(int *)(parent_task + 0x24) + 1;
      iVar3 = *(int *)(parent_task + 0x20);
      if (parent_task + 0x1c == iVar3) {
        *(undefined4 **)(parent_task + 0x1c) = target_act;
      }
      else {
        *(undefined4 **)(iVar3 + 0x10) = target_act;
      }
      target_act[5] = iVar3;
      target_act[4] = parent_task + 0x1c;
      *(undefined4 **)(parent_task + 0x20) = target_act;
      LOCK();
      *(undefined4 *)(parent_task + 0x28) = 0;
      UNLOCK();
      _splx(uVar2);
      target_act[0x5e] = 1;
      if (*(int *)(parent_task + 8) == 0) {
        LOCK();
        *(undefined4 *)parent_task = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(local_8 + 0x158) = 0;
        UNLOCK();
        _thread_terminate((thread_act_t)target_act);
        _thread_deallocate(target_act);
        kVar1 = 5;
      }
      else {
        LOCK();
        *(undefined4 *)parent_task = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(local_8 + 0x158) = 0;
        UNLOCK();
        _ipc_thread_enable(target_act);
        __nthreads = __nthreads + 1;
        *child_act = (thread_act_t)target_act;
        kVar1 = 0;
      }
    }
  }
  return kVar1;
}

