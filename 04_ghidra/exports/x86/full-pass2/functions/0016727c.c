/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016727c */

kern_return_t _thread_terminate(thread_act_t target_act)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint target_act_00;
  kern_return_t kVar4;
  undefined4 uVar5;
  
  target_act_00 = _active_threads;
  if (target_act == 0) {
    kVar4 = 4;
  }
  else {
    _ipc_thread_disable(target_act);
    if (target_act == target_act_00) {
      uVar5 = _splsched();
      piVar1 = (int *)(target_act + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (*(int *)(target_act + 0x178) != 0) {
        *(undefined4 *)(target_act + 0x178) = 0;
        *(byte *)(target_act + 0x17c) = *(byte *)(target_act + 0x17c) | 2;
      }
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      _need_ast = _need_ast | 2;
      _splx(uVar5);
      kVar4 = 0;
    }
    else {
      piVar1 = *(int **)(_active_threads + 0xc);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      uVar5 = _splsched();
      if (target_act < target_act_00) {
        piVar2 = (int *)(target_act + 0x20);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        piVar2 = (int *)(target_act_00 + 0x20);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
      }
      else {
        piVar2 = (int *)(target_act_00 + 0x20);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        piVar2 = (int *)(target_act + 0x20);
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
      }
      if ((piVar1[2] == 0) || (*(int *)(target_act_00 + 0x178) == 0)) {
        LOCK();
        *(undefined4 *)(target_act_00 + 0x20) = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(target_act + 0x20) = 0;
        UNLOCK();
        _splx(uVar5);
        LOCK();
        *piVar1 = 0;
        UNLOCK();
        _thread_terminate(target_act_00);
        kVar4 = 5;
      }
      else {
        LOCK();
        *(undefined4 *)(target_act_00 + 0x20) = 0;
        UNLOCK();
        LOCK();
        *piVar1 = 0;
        UNLOCK();
        if (*(int *)(target_act + 0x178) == 0) {
          LOCK();
          *(undefined4 *)(target_act + 0x20) = 0;
          UNLOCK();
          _splx(uVar5);
          kVar4 = 5;
        }
        else {
          *(undefined4 *)(target_act + 0x178) = 0;
          LOCK();
          *(undefined4 *)(target_act + 0x20) = 0;
          UNLOCK();
          _splx(uVar5);
          _thread_halt(target_act,1);
          _ipc_thread_terminate(target_act);
          _thread_deallocate(target_act);
          kVar4 = 0;
        }
      }
    }
  }
  return kVar4;
}

