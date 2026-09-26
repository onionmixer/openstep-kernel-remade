/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160e84 */

void _thread_quantum_update(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = _min_quantum;
  iVar5 = (&_processor_ptr)[param_1];
  DAT_001e977c = _min_quantum;
  if (param_4 != 2) {
    param_3 = *(int *)(iVar5 + 0x120) - param_3;
    *(int *)(iVar5 + 0x120) = param_3;
    if (param_3 < 1) {
      uVar2 = _splsched();
      piVar1 = (int *)(param_2 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (*(int *)(param_2 + 0x70) == _sched_tick) {
        if ((*(int *)(param_2 + 0x60) != 2) && (*(int *)(param_2 + 100) < 0)) {
          if (*(int *)(param_2 + 0x10c) == *(int *)(param_2 + 0xf8)) {
            iVar3 = *(int *)(param_2 + 0xf0) - *(int *)(param_2 + 0x108);
            *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0xf0);
          }
          else {
            iVar3 = _timer_delta(param_2 + 0xf0,param_2 + 0x108);
          }
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xe8)) {
            iVar4 = *(int *)(param_2 + 0xe0) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe0);
          }
          else {
            iVar4 = _timer_delta(param_2 + 0xe0,param_2 + 0x100);
          }
          *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + iVar3 + iVar4;
          iVar3 = (iVar3 + iVar4) * *(int *)(*(int *)(param_2 + 0x180) + 0x178) +
                  *(int *)(param_2 + 0x114);
          *(int *)(param_2 + 0x114) = iVar3;
          *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + iVar3;
          *(undefined4 *)(param_2 + 0x114) = 0;
          _compute_my_priority(param_2);
        }
      }
      else {
        _update_priority(param_2);
      }
      LOCK();
      *(undefined4 *)(param_2 + 0x20) = 0;
      UNLOCK();
      _splx(uVar2);
      *(undefined4 *)(iVar5 + 0x124) = 0;
      if (*(int *)(param_2 + 0x60) == 2) {
        *(int *)(iVar5 + 0x120) = *(int *)(iVar5 + 0x120) + *(int *)(param_2 + 0x5c);
      }
      else {
        *(int *)(iVar5 + 0x120) = *(int *)(iVar5 + 0x120) + iVar6;
      }
    }
    else {
      uVar2 = _splsched();
      piVar1 = (int *)(param_2 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if (*(int *)(param_2 + 0x70) == _sched_tick) {
        if ((*(int *)(param_2 + 0x60) != 2) && (*(int *)(param_2 + 100) < 0)) {
          if (*(int *)(param_2 + 0x10c) == *(int *)(param_2 + 0xf8)) {
            iVar5 = *(int *)(param_2 + 0xf0) - *(int *)(param_2 + 0x108);
            *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0xf0);
          }
          else {
            iVar5 = _timer_delta(param_2 + 0xf0,param_2 + 0x108);
          }
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xe8)) {
            iVar6 = *(int *)(param_2 + 0xe0) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe0);
          }
          else {
            iVar6 = _timer_delta(param_2 + 0xe0,param_2 + 0x100);
          }
          *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + iVar5 + iVar6;
          uVar7 = (iVar5 + iVar6) * *(int *)(*(int *)(param_2 + 0x180) + 0x178) +
                  *(int *)(param_2 + 0x114);
          *(uint *)(param_2 + 0x114) = uVar7;
          if (0x7ffffff < uVar7) {
            *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + uVar7;
            *(undefined4 *)(param_2 + 0x114) = 0;
            _compute_my_priority(param_2);
          }
        }
      }
      else {
        _update_priority(param_2);
      }
      LOCK();
      *(undefined4 *)(param_2 + 0x20) = 0;
      UNLOCK();
      _splx(uVar2);
    }
    _ast_check();
  }
  return;
}

