
void _psignal(int param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (0x20 < param_2) {
    return;
  }
  uVar3 = 1 << (param_2 - 1 & 0x3f);
  iVar1 = *(int *)(param_1 + 0x66);
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x48) != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x2b) & 0x10) == 0) {
    if ((((*(byte *)(param_1 + 0x16) & 0x40) == 0) || (uVar3 != 0x40000)) &&
       ((uVar3 & *(uint *)(param_1 + 0x20)) != 0)) {
      return;
    }
    if ((((*(byte *)(param_1 + 0x16) & 0x40) == 0) || (uVar3 != 0x40000)) &&
       ((uVar3 & *(uint *)(param_1 + 0x1c)) != 0)) {
      iVar5 = 3;
    }
    else {
      iVar5 = 0;
      if ((uVar3 & *(uint *)(param_1 + 0x24)) != 0) {
        iVar5 = 2;
      }
    }
  }
  else {
    iVar5 = 0;
  }
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x18) = uVar3 | *(uint *)(param_1 + 0x18);
    switch(param_2) {
    case :
      if (((*(byte *)(param_1 + 0x2b) & 0x10) == 0) && (iVar5 == 0)) goto loc_40090e8;
      break;
    case :
    case :
    case :
    case :
      *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xfb;
      break;
    case :
loc_40090e8:
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffccffff;
    }
  }
  iVar4 = _active_threads;
  if (iVar5 == 3) {
    return;
  }
  piVar6 = (int *)_active_threads;
  if (iVar1 != *(int *)(_active_threads + 0xc)) {
    piVar6 = *(int **)(iVar1 + 0x18);
    if (piVar6 == (int *)(iVar1 + 0x18)) {
      return;
    }
    _thread_reference(piVar6);
  }
  if ((param_2 == 9) && ('\0' < *(char *)(param_1 + 0x15))) {
    *(undefined *)(param_1 + 0x15) = 0;
    _thread_max_priority(piVar6,*(undefined4 *)((int)piVar6 + 0x178),10);
    _thread_priority(piVar6,10,0);
  }
  if ((*(byte *)(param_1 + 0x2b) & 0x10) == 0) {
    if (iVar5 == 0) {
      switch(param_2) {
      case :
        while (0 < *(int *)(iVar1 + 0x3c)) {
          _task_resume(iVar1);
        }
        *(undefined *)(param_1 + 0x13) = 3;
        iVar1 = *(int *)((int)piVar6 + 0x88);
        while (0 < iVar1) {
          _thread_resume(piVar6);
          iVar1 = *(int *)((int)piVar6 + 0x88);
        }
        _clear_wait(piVar6,3,0);
        if ((int *)iVar4 == piVar6) {
          return;
        }
        _mach_msg_abort_rpc(piVar6);
        _thread_deallocate(piVar6);
        return;
      :
        goto loc_400931E;
      case :
      case :
      case :
      case :
        *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
        break;
      case :
      case :
      case :
      case :
        if ((param_2 == 0x11) || (*(int *)(param_1 + 0x42) != _init_proc)) {
          if ((*(byte *)((int)piVar6 + 0x4b) & 4) == 0) {
            *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
            if (*(int *)(iVar1 + 0x3c) == 0) {
              *(uint *)(param_1 + 0x3a) = param_2;
              _psignal(*(undefined4 *)(param_1 + 0x42),0x14);
              _stop(param_1);
            }
          }
          else if (((param_1 == *_active_u) && (*(char *)(param_1 + 0x13) != '\x05')) &&
                  (_need_ast = _need_ast | 0x20, _need_ast != 0)) {
            pbVar2 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
            *pbVar2 = *pbVar2 | 0x10;
          }
        }
        else {
          _psignal(param_1,9);
          *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
        }
        break;
      case :
        _task_resume(iVar1);
        *(undefined *)(param_1 + 0x13) = 3;
      }
      goto loc_4009332;
    }
    if (param_2 == 0x13) {
      _task_resume(iVar1);
      *(undefined *)(param_1 + 0x13) = 3;
    }
  }
  else if (*(char *)(param_1 + 0x13) == '\x06') goto loc_4009332;
loc_400931E:
  _clear_wait(piVar6,2,1);
loc_4009332:
  if ((int *)iVar4 != piVar6) {
    _thread_deallocate_interrupt(piVar6);
  }
  return;
}
