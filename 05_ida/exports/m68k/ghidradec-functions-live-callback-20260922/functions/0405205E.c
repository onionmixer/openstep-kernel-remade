
undefined4 _task_terminate(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = _active_threads;
  if (param_1 == 0) {
    return 4;
  }
  piVar4 = (int *)(param_1 + 0x18);
  if (*(int *)(_active_threads + 0xc) == param_1) {
    if (*(int *)(param_1 + 4) == 0) {
      return 5;
    }
    if (*(int *)(_active_threads + 0x170) != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      piVar2 = *(int **)(iVar5 + 0x10);
      piVar3 = *(int **)(iVar5 + 0x14);
      if (piVar2 == piVar4) {
        *(int **)(param_1 + 0x1c) = piVar3;
      }
      else {
        piVar2[5] = (int)piVar3;
      }
      if (piVar3 == piVar4) {
        *piVar4 = (int)piVar2;
      }
      else {
        piVar3[4] = (int)piVar2;
      }
      _ipc_thread_disable(iVar5);
      _ipc_thread_terminate(iVar5);
loc_405211C:
      _ipc_task_disable(param_1);
      _task_hold(param_1);
      _task_dowait(param_1,1);
      while (piVar4 != (int *)*piVar4) {
        iVar1 = *piVar4;
        _thread_reference(iVar1);
        _thread_force_terminate(iVar1);
        _thread_deallocate(iVar1);
        _thread_block_with_continuation(0);
      }
      _ipc_task_terminate(param_1);
      _task_deallocate(param_1);
      if (param_1 == *(int *)(iVar5 + 0xc)) {
        piVar2 = *(int **)(param_1 + 0x1c);
        if (piVar2 == piVar4) {
          *piVar4 = iVar5;
        }
        else {
          piVar2[4] = iVar5;
        }
        *(int **)(iVar5 + 0x14) = piVar2;
        *(int **)(iVar5 + 0x10) = piVar4;
        *(int *)(param_1 + 0x1c) = iVar5;
        _thread_terminate(iVar5);
      }
      return 0;
    }
  }
  else if ((*(int *)(*(int *)(_active_threads + 0xc) + 4) != 0) &&
          (*(int *)(_active_threads + 0x170) != 0)) {
    if (*(int *)(param_1 + 4) == 0) {
      return 5;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    goto loc_405211C;
  }
  _thread_terminate(_active_threads);
  return 5;
}

