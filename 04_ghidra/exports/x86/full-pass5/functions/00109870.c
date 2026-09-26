/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109870 */

void _psignal(uint param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  task_t target_task;
  thread_act_t tVar3;
  undefined4 uVar4;
  uint uVar5;
  thread_act_t target_act;
  int local_c;
  
  if ((char *)0x20 < param_2) {
    return;
  }
  uVar5 = 1 << ((char)param_2 - 1U & 0x1f);
  target_task = *(task_t *)(param_1 + 0x68);
  if (target_task == 0) {
    return;
  }
  if (*(int *)(target_task + 0x50) != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x28) & 0x10) == 0) {
    if ((((*(byte *)(param_1 + 0x16) & 2) == 0) || (uVar5 != 0x40000)) &&
       ((*(uint *)(param_1 + 0x20) & uVar5) != 0)) {
      return;
    }
    if ((((*(byte *)(param_1 + 0x16) & 2) == 0) || (uVar5 != 0x40000)) &&
       ((*(uint *)(param_1 + 0x1c) & uVar5) != 0)) {
      local_c = 3;
    }
    else {
      local_c = 0;
      if ((*(uint *)(param_1 + 0x24) & uVar5) != 0) {
        local_c = 2;
      }
    }
  }
  else {
    local_c = 0;
  }
  if (param_2 != (char *)0x0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | uVar5;
    switch(param_2) {
    case (char *)0xf:
      if (((*(byte *)(param_1 + 0x28) & 0x10) == 0) && (local_c == 0))
      goto switchD_00109925_caseD_13;
      break;
    case (char *)0x11:
    case (char *)0x12:
    case (char *)0x15:
    case (char *)0x16:
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffbffff;
      break;
    case (char *)0x13:
switchD_00109925_caseD_13:
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffccffff;
    }
  }
  if (local_c == 3) {
    return;
  }
  uVar4 = _splhigh();
  tVar3 = _active_threads;
  target_act = _active_threads;
  if (*(task_t *)(_active_threads + 0xc) != target_task) {
    piVar1 = (int *)(target_task + 0x28);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    target_act = *(thread_act_t *)(target_task + 0x1c);
    if (target_task + 0x1c == target_act) {
      LOCK();
      *(undefined4 *)(target_task + 0x28) = 0;
      UNLOCK();
      _splx(uVar4);
      return;
    }
    _thread_reference(target_act);
    LOCK();
    *(undefined4 *)(target_task + 0x28) = 0;
    UNLOCK();
  }
  if ((param_2 == (char *)0x9) && ('\0' < *(char *)(param_1 + 0x15))) {
    *(undefined1 *)(param_1 + 0x15) = 0;
    _thread_max_priority(target_act,*(undefined4 *)(target_act + 0x180),10);
    _thread_priority(target_act,10,0);
  }
  if ((*(byte *)(param_1 + 0x28) & 0x10) == 0) {
    if (local_c == 0) {
      switch(param_2) {
      case (char *)0x9:
        while (0 < *(int *)(target_task + 0x44)) {
          _task_resume(target_task);
        }
        *(undefined1 *)(param_1 + 0x13) = 3;
        iVar2 = *(int *)(target_act + 0x8c);
        while (0 < iVar2) {
          _thread_resume(target_act);
          iVar2 = *(int *)(target_act + 0x8c);
        }
        _clear_wait(target_act,3,0);
        _splx(uVar4);
        if (tVar3 == target_act) {
          return;
        }
        _mach_msg_abort_rpc(target_act);
        _thread_deallocate(target_act);
        return;
      default:
        goto switchD_00109a4b_caseD_a;
      case (char *)0x10:
      case (char *)0x14:
      case (char *)0x17:
      case (char *)0x1c:
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~uVar5;
        break;
      case (char *)0x11:
      case (char *)0x12:
      case (char *)0x15:
      case (char *)0x16:
        if ((param_2 == (char *)0x11) || (*(int *)(param_1 + 0x44) != _init_proc)) {
          if ((*(byte *)(target_act + 0x4c) & 4) == 0) {
            *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~uVar5;
            if (*(int *)(target_task + 0x44) == 0) {
              *(char **)(param_1 + 0x3c) = param_2;
              _psignal(*(uint *)(param_1 + 0x44),(char *)0x14);
              _stop(param_1);
            }
          }
          else if ((*_active_u == param_1) && (*(char *)(param_1 + 0x13) != '\x05')) {
            _need_ast = _need_ast | 0x20;
          }
        }
        else {
          _psignal(param_1,(char *)0x9);
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~uVar5;
        }
        break;
      case (char *)0x13:
        _task_resume(target_task);
        *(undefined1 *)(param_1 + 0x13) = 3;
      }
      goto LAB_00109bb1;
    }
    if (param_2 == (char *)0x13) {
      _task_resume(target_task);
      *(undefined1 *)(param_1 + 0x13) = 3;
    }
  }
  else if (*(char *)(param_1 + 0x13) == '\x06') goto LAB_00109bb1;
switchD_00109a4b_caseD_a:
  _clear_wait(target_act,2,1);
LAB_00109bb1:
  _splx(uVar4);
  if (tVar3 != target_act) {
    _thread_deallocate_interrupt(target_act);
  }
  return;
}

