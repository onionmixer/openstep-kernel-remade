/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165cc0 */

kern_return_t _task_terminate(task_t target_task)

{
  thread_act_t *ptVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  thread_act_t *ptVar5;
  thread_act_t *ptVar6;
  thread_act_t tVar7;
  thread_act_t target_act;
  undefined4 uVar8;
  int *piVar9;
  
  target_act = _active_threads;
  if (target_task == 0) {
    return 4;
  }
  ptVar1 = (thread_act_t *)(target_task + 0x1c);
  piVar9 = *(int **)(_active_threads + 0xc);
  if ((int *)target_task == piVar9) {
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar3 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (*(int *)(target_task + 8) == 0) {
LAB_00165eca:
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      return 5;
    }
    uVar8 = _splsched();
    piVar9 = (int *)(target_task + 0x28);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar3 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    piVar9 = (int *)(target_act + 0x20);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar3 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (*(int *)(target_act + 0x178) == 0) {
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(target_task + 0x28) = 0;
      UNLOCK();
      _splx(uVar8);
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      _thread_terminate(target_act);
      return 5;
    }
    *(undefined4 *)(target_task + 8) = 0;
    ptVar5 = *(thread_act_t **)(target_act + 0x10);
    ptVar6 = *(thread_act_t **)(target_act + 0x14);
    if (ptVar1 == ptVar5) {
      *(thread_act_t **)(target_task + 0x20) = ptVar6;
    }
    else {
      ptVar5[5] = (thread_act_t)ptVar6;
    }
    if (ptVar1 == ptVar6) {
      *ptVar1 = (thread_act_t)ptVar5;
    }
    else {
      ptVar6[4] = (thread_act_t)ptVar5;
    }
    LOCK();
    *(undefined4 *)(target_act + 0x20) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(target_task + 0x28) = 0;
    UNLOCK();
    _splx(uVar8);
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    _ipc_thread_disable(target_act);
    _ipc_thread_terminate(target_act);
  }
  else {
    if (target_task < piVar9) {
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar3 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar3 == 1);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar3 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar3 == 1);
    }
    else {
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar3 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar3 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar3 == 1);
    }
    uVar8 = _splsched();
    piVar2 = (int *)(target_act + 0x20);
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar3 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if ((piVar9[2] == 0) || (*(int *)(target_act + 0x178) == 0)) {
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      _splx(uVar8);
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      LOCK();
      *piVar9 = 0;
      UNLOCK();
      _thread_terminate(target_act);
      return 5;
    }
    LOCK();
    *(undefined4 *)(target_act + 0x20) = 0;
    UNLOCK();
    _splx(uVar8);
    LOCK();
    *piVar9 = 0;
    UNLOCK();
    if (*(int *)(target_task + 8) == 0) goto LAB_00165eca;
    *(undefined4 *)(target_task + 8) = 0;
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
  }
  _ipc_task_disable(target_task);
  _task_hold(target_task);
  _task_dowait(target_task,1);
  do {
    do {
    } while (*(int *)target_task != 0);
    LOCK();
    iVar3 = *(int *)target_task;
    *(undefined4 *)target_task = 1;
    UNLOCK();
  } while (iVar3 == 1);
  ptVar5 = (thread_act_t *)*ptVar1;
  while (ptVar5 != ptVar1) {
    tVar7 = *ptVar1;
    _thread_reference(tVar7);
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    _thread_force_terminate(tVar7);
    _thread_deallocate(tVar7);
    _thread_block_with_continuation(0);
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar3 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar3 == 1);
    ptVar5 = (thread_act_t *)*ptVar1;
  }
  LOCK();
  *(undefined4 *)target_task = 0;
  UNLOCK();
  _ipc_task_terminate(target_task);
  if (target_task != 0) {
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar3 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar3 == 1);
    iVar3 = *(int *)(target_task + 4);
    *(int *)(target_task + 4) = iVar3 + -1;
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    if (iVar3 == 1) {
      iVar3 = *(int *)(target_task + 0x2c);
      piVar9 = (int *)(iVar3 + 0x158);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar4 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      _pset_remove_task(iVar3,target_task);
      LOCK();
      *(undefined4 *)(iVar3 + 0x158) = 0;
      UNLOCK();
      _pset_deallocate(iVar3);
      _vm_map_deallocate(*(undefined4 *)(target_task + 0xc));
      _ipc_space_release(*(undefined4 *)(target_task + 0x88));
      _pcb_common_terminate(target_task);
      _utask_free(*(undefined4 *)(target_task + 0x38));
      _zfree(_task_zone,target_task);
    }
  }
  if (*(task_t *)(target_act + 0xc) == target_task) {
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar3 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar3 == 1);
    uVar8 = _splsched();
    piVar9 = (int *)(target_task + 0x28);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar3 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    ptVar5 = *(thread_act_t **)(target_task + 0x20);
    if (ptVar1 == ptVar5) {
      *ptVar1 = target_act;
    }
    else {
      ptVar5[4] = target_act;
    }
    *(thread_act_t **)(target_act + 0x14) = ptVar5;
    *(thread_act_t **)(target_act + 0x10) = ptVar1;
    *(thread_act_t *)(target_task + 0x20) = target_act;
    LOCK();
    *(undefined4 *)(target_task + 0x28) = 0;
    UNLOCK();
    _splx(uVar8);
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    _thread_terminate(target_act);
  }
  return 0;
}

