
void _exception_raise_continue_fast(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  mach_port_t task;
  mach_port_t thread;
  exception_data_t code;
  mach_msg_type_number_t codeCnt;
  
  iVar4 = _active_threads;
  param_1[8] = param_1[8] + -1;
  param_1[1] = param_1[1] + -2;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if ((((*(int *)(param_2 + 0x14) == 0x12) && (*(int *)(param_2 + 0x18) == 0x20)) &&
      (*(int *)(param_2 + 0x28) == 0x9c4)) && (*(int *)(param_2 + 0x2c) == _exc_code_proto)) {
    iVar6 = *(int *)(param_2 + 0x30);
    if ((*(int *)(param_2 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
      _ipc_kmsg_cache = param_2;
    }
    else if (*(int *)(param_2 + 8) < 1) {
      _ipc_kmsg_free(param_2);
    }
    else {
      _kfree(param_2,*(int *)(param_2 + 8));
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0;
    _ipc_kmsg_destroy(param_2);
    iVar6 = -0x12d;
  }
  iVar5 = _active_threads;
  if (iVar6 == 0) {
    if (*(int *)(iVar4 + 0x38) != 0) {
      _call_continuation(*(int *)(iVar4 + 0x38));
    }
    _thread_exception_return();
  }
  else {
    iVar6 = *(int *)(iVar4 + 200);
    if (iVar6 != 0) {
      code = *(exception_data_t *)(iVar4 + 0xcc);
      codeCnt = *(mach_msg_type_number_t *)(iVar4 + 0xd0);
      iVar4 = *(int *)(_active_threads + 0xc);
      piVar1 = (int *)(iVar4 + 100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      piVar1 = *(int **)(iVar4 + 0x70);
      if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
        LOCK();
        *(undefined4 *)(iVar4 + 100) = 0;
        UNLOCK();
        _exception_no_server();
      }
      else {
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        LOCK();
        *(undefined4 *)(iVar4 + 100) = 0;
        UNLOCK();
        if (piVar1[2] < 0) {
          piVar1[1] = piVar1[1] + 1;
          piVar1[7] = piVar1[7] + 1;
          LOCK();
          *piVar1 = 0;
          UNLOCK();
          *(undefined4 *)(iVar5 + 200) = 0;
          task = _retrieve_task_self_fast(iVar4);
          thread = _retrieve_thread_self_fast(iVar5);
          _exception_raise((mach_port_t)piVar1,thread,task,iVar6,code,codeCnt);
        }
        else {
          LOCK();
          *piVar1 = 0;
          UNLOCK();
          _exception_no_server();
        }
      }
    }
    iVar4 = _active_threads;
    bVar3 = *(byte *)(_active_threads + 0x17c);
    while ((bVar3 & 3) != 0) {
      _thread_halt_self();
      bVar3 = *(byte *)(iVar4 + 0x17c);
    }
    _task_terminate(*(task_t *)(iVar4 + 0xc));
    _thread_halt_self();
  }
  return;
}

