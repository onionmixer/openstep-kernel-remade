/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001574b0 */

void _exception_raise_continue_slow(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  mach_port_t task;
  mach_port_t thread;
  int *piVar6;
  int *piVar7;
  int iVar8;
  exception_data_t code;
  mach_msg_type_number_t codeCnt;
  
  iVar3 = _active_threads;
  piVar7 = *(int **)(_active_threads + 0xc4);
  piVar6 = piVar7 + 0x10;
  while (param_1 == 0x10004005) {
    while ((*(byte *)(iVar3 + 0x17c) & 3) != 0) {
      if ((piVar7 != (int *)0x0) && (piVar7 != (int *)0xffffffff)) {
        _ipc_object_release(piVar7);
      }
      *(undefined4 *)(iVar3 + 0xc4) = 0;
      piVar6 = (int *)0x0;
      _thread_halt_self_with_continuation(0);
      piVar7 = (int *)(iVar3 + 0xa8);
      do {
        do {
        } while (*piVar7 != 0);
        LOCK();
        iVar8 = *piVar7;
        *piVar7 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      piVar7 = *(int **)(iVar3 + 0xc0);
      *(int **)(iVar3 + 0xc4) = piVar7;
      if ((piVar7 != (int *)0x0) && (piVar7 != (int *)0xffffffff)) {
        _ipc_object_reference(piVar7);
        piVar6 = piVar7 + 0x10;
      }
      LOCK();
      *(undefined4 *)(iVar3 + 0xa8) = 0;
      UNLOCK();
    }
    if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) {
LAB_00157634:
      param_1 = 0x10004009;
      break;
    }
    do {
      do {
      } while (*piVar7 != 0);
      LOCK();
      iVar8 = *piVar7;
      *piVar7 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    if (-1 < piVar7[2]) {
      LOCK();
      *piVar7 = 0;
      UNLOCK();
      goto LAB_00157634;
    }
    do {
      do {
      } while (*piVar6 != 0);
      LOCK();
      iVar8 = *piVar6;
      *piVar6 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    LOCK();
    *piVar7 = 0;
    UNLOCK();
    pcVar5 = (code *)0x0;
    if (*(int *)(iVar3 + 0x38) != 0) {
      pcVar5 = _exception_raise_continue;
    }
    param_1 = _ipc_mqueue_receive(piVar6,0,0xffffffff,0,0,pcVar5,&param_2,&stack0x0000000c);
  }
  if ((piVar7 != (int *)0x0) && (piVar7 != (int *)0xffffffff)) {
    _ipc_object_release(piVar7);
  }
  if (param_1 == 0) {
    _ipc_port_release_sonce(piVar7);
    if ((((*(int *)(param_2 + 0x14) == 0x12) && (*(int *)(param_2 + 0x18) == 0x20)) &&
        (*(int *)(param_2 + 0x28) == 0x9c4)) && (*(int *)(param_2 + 0x2c) == _exc_code_proto)) {
      param_1 = *(int *)(param_2 + 0x30);
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
      param_1 = -0x12d;
    }
    if (param_1 != 0) goto LAB_0015767e;
  }
  else {
LAB_0015767e:
    if (param_1 != 0x10004009) goto LAB_00157699;
  }
  if (*(int *)(iVar3 + 0x38) == 0) {
    return;
  }
  _call_continuation(*(int *)(iVar3 + 0x38));
LAB_00157699:
  iVar4 = _active_threads;
  iVar8 = *(int *)(iVar3 + 200);
  if (iVar8 == 0) {
    bVar2 = *(byte *)(_active_threads + 0x17c);
    while ((bVar2 & 3) != 0) {
      _thread_halt_self();
      bVar2 = *(byte *)(iVar4 + 0x17c);
    }
    _task_terminate(*(task_t *)(iVar4 + 0xc));
    _thread_halt_self();
  }
  else {
    code = *(exception_data_t *)(iVar3 + 0xcc);
    codeCnt = *(mach_msg_type_number_t *)(iVar3 + 0xd0);
    iVar3 = *(int *)(_active_threads + 0xc);
    piVar6 = (int *)(iVar3 + 100);
    do {
      do {
      } while (*piVar6 != 0);
      LOCK();
      iVar1 = *piVar6;
      *piVar6 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar6 = *(int **)(iVar3 + 0x70);
    if ((piVar6 == (int *)0x0) || (piVar6 == (int *)0xffffffff)) {
      LOCK();
      *(undefined4 *)(iVar3 + 100) = 0;
      UNLOCK();
      _exception_no_server();
    }
    else {
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar1 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      *(undefined4 *)(iVar3 + 100) = 0;
      UNLOCK();
      if (piVar6[2] < 0) {
        piVar6[1] = piVar6[1] + 1;
        piVar6[7] = piVar6[7] + 1;
        LOCK();
        *piVar6 = 0;
        UNLOCK();
        *(undefined4 *)(iVar4 + 200) = 0;
        task = _retrieve_task_self_fast(iVar3);
        thread = _retrieve_thread_self_fast(iVar4);
        _exception_raise((mach_port_t)piVar6,thread,task,iVar8,code,codeCnt);
      }
      else {
        LOCK();
        *piVar6 = 0;
        UNLOCK();
        _exception_no_server();
      }
    }
  }
  return;
}

