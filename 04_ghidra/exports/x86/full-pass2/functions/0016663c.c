/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016663c */

kern_return_t _task_resume(task_t target_task)

{
  int iVar1;
  int iVar2;
  kern_return_t kVar3;
  
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
  if (iVar1 < 1) {
LAB_00166673:
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    kVar3 = 5;
  }
  else {
    *(int *)(target_task + 0x44) = iVar1 + -1;
    LOCK();
    *(undefined4 *)target_task = 0;
    UNLOCK();
    if (iVar1 == 1) {
      do {
        do {
        } while (*(int *)target_task != 0);
        LOCK();
        iVar1 = *(int *)target_task;
        *(undefined4 *)target_task = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if (*(int *)(target_task + 8) == 0) goto LAB_00166673;
      *(int *)(target_task + 0x18) = *(int *)(target_task + 0x18) + -1;
      iVar1 = *(int *)(target_task + 0x1c);
      while (target_task + 0x1c != iVar1) {
        iVar2 = *(int *)(iVar1 + 0x10);
        _thread_release(iVar1);
        iVar1 = iVar2;
      }
      LOCK();
      *(undefined4 *)target_task = 0;
      UNLOCK();
    }
    kVar3 = 0;
  }
  return kVar3;
}

