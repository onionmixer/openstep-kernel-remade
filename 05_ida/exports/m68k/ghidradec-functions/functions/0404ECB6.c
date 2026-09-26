
void _thread_quantum_update(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = _min_quantum;
  iVar4 = (&_processor_ptr)[param_1];
  dword_40B67A4 = _min_quantum;
  if (param_4 != 2) {
    param_3 = *(int *)(iVar4 + 0x11c) - param_3;
    *(int *)(iVar4 + 0x11c) = param_3;
    if (param_3 < 1) {
      if (*(int *)(param_2 + 0x6c) == _sched_tick) {
        if ((*(int *)(param_2 + 0x5c) != 2) && (*(int *)(param_2 + 0x60) < 0)) {
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xf0)) {
            iVar2 = *(int *)(param_2 + 0xe8) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe8);
          }
          else {
            iVar2 = _timer_delta(param_2 + 0xe8,param_2 + 0x100);
          }
          if (*(int *)(param_2 + 0xfc) == *(int *)(param_2 + 0xe0)) {
            iVar3 = *(int *)(param_2 + 0xd8) - *(int *)(param_2 + 0xf8);
            *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xd8);
          }
          else {
            iVar3 = _timer_delta(param_2 + 0xd8,param_2 + 0xf8);
          }
          *(int *)(param_2 + 0x108) = iVar3 + iVar2 + *(int *)(param_2 + 0x108);
          iVar2 = *(int *)(param_2 + 0x10c) +
                  *(int *)(*(int *)(param_2 + 0x178) + 0x168) * (iVar3 + iVar2);
          *(int *)(param_2 + 0x10c) = iVar2;
          *(int *)(param_2 + 0x68) = iVar2 + *(int *)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0x10c) = 0;
          _compute_my_priority(param_2);
        }
      }
      else {
        _update_priority(param_2);
      }
      *(undefined4 *)(iVar4 + 0x120) = 0;
      if (*(int *)(param_2 + 0x5c) == 2) {
        *(int *)(iVar4 + 0x11c) = *(int *)(param_2 + 0x58) + *(int *)(iVar4 + 0x11c);
      }
      else {
        *(int *)(iVar4 + 0x11c) = iVar5 + *(int *)(iVar4 + 0x11c);
      }
    }
    else if (*(int *)(param_2 + 0x6c) == _sched_tick) {
      if ((*(int *)(param_2 + 0x5c) != 2) && (*(int *)(param_2 + 0x60) < 0)) {
        if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xf0)) {
          iVar4 = *(int *)(param_2 + 0xe8) - *(int *)(param_2 + 0x100);
          *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe8);
        }
        else {
          iVar4 = _timer_delta(param_2 + 0xe8,param_2 + 0x100);
        }
        if (*(int *)(param_2 + 0xfc) == *(int *)(param_2 + 0xe0)) {
          iVar5 = *(int *)(param_2 + 0xd8) - *(int *)(param_2 + 0xf8);
          *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xd8);
        }
        else {
          iVar5 = _timer_delta(param_2 + 0xd8,param_2 + 0xf8);
        }
        *(int *)(param_2 + 0x108) = iVar5 + iVar4 + *(int *)(param_2 + 0x108);
        uVar1 = *(int *)(param_2 + 0x10c) +
                *(int *)(*(int *)(param_2 + 0x178) + 0x168) * (iVar5 + iVar4);
        *(uint *)(param_2 + 0x10c) = uVar1;
        if (0x7ffffff < uVar1) {
          *(int *)(param_2 + 0x68) = uVar1 + *(int *)(param_2 + 0x68);
          *(undefined4 *)(param_2 + 0x10c) = 0;
          _compute_my_priority(param_2);
        }
      }
    }
    else {
      _update_priority(param_2);
    }
    _ast_check();
  }
  return;
}
