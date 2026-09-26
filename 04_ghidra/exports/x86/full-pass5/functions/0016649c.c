/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016649c */

kern_return_t _task_suspend(task_t target_task)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  kern_return_t kVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int local_c;
  
  if (target_task == 0) {
    return 4;
  }
  do {
    do {
    } while (*(int *)target_task != 0);
    LOCK();
    iVar1 = *(int *)target_task;
    *(undefined4 *)target_task = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = *(int *)(target_task + 0x44);
  *(int *)(target_task + 0x44) = iVar1 + 1;
  LOCK();
  *(undefined4 *)target_task = 0;
  puVar6 = _active_threads;
  UNLOCK();
  if (iVar1 == 0) {
    do {
      do {
      } while (*(int *)target_task != 0);
      LOCK();
      iVar1 = *(int *)target_task;
      *(undefined4 *)target_task = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (*(int *)(target_task + 8) == 0) {
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
    }
    else {
      *(int *)(target_task + 0x18) = *(int *)(target_task + 0x18) + 1;
      for (puVar2 = *(undefined4 **)(target_task + 0x1c);
          (undefined4 *)(target_task + 0x1c) != puVar2; puVar2 = (undefined4 *)puVar2[4]) {
        if (puVar6 != puVar2) {
          _thread_hold(puVar2);
        }
      }
      LOCK();
      *(undefined4 *)target_task = 0;
      puVar2 = _active_threads;
      UNLOCK();
      local_c = 0;
      puVar6 = (undefined4 *)0x0;
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar1 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar1 == 1);
      for (puVar3 = *(undefined4 **)(target_task + 0x1c);
          (undefined4 *)(target_task + 0x1c) != puVar3; puVar3 = (undefined4 *)puVar3[4]) {
        if (*(int *)(target_task + 8) == 0) {
          local_c = 5;
          break;
        }
        if (puVar2 != puVar3) {
          _thread_reference(puVar3);
          LOCK();
          *(undefined4 *)target_task = 0;
          UNLOCK();
          if (puVar6 != (undefined4 *)0x0) {
            _thread_deallocate(puVar6);
          }
          _thread_dowait(puVar3,1);
          do {
            do {
            } while (*(int *)target_task != 0);
            LOCK();
            iVar1 = *(int *)target_task;
            *(undefined4 *)target_task = 1;
            UNLOCK();
            puVar6 = puVar3;
          } while (iVar1 == 1);
        }
      }
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
      if (puVar6 != (undefined4 *)0x0) {
        _thread_deallocate(puVar6);
      }
      if (local_c == 0) {
        if (_active_threads[3] == target_task) {
          _thread_hold(_active_threads);
          uVar5 = _splsched();
          _need_ast = _need_ast | 4;
          _splx(uVar5);
        }
        goto LAB_0016662d;
      }
    }
    kVar4 = 5;
  }
  else {
LAB_0016662d:
    kVar4 = 0;
  }
  return kVar4;
}

