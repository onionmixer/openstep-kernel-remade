
kern_return_t
_thread_policy(thread_act_t thr_act,policy_t policy,policy_base_t base,
              mach_msg_type_number_t baseCnt,boolean_t set_limit)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if ((thr_act == 0) || (3 < policy - 1U)) {
    local_8 = 4;
  }
  else {
    uVar2 = _splsched();
    piVar1 = (int *)(thr_act + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (*(int *)(thr_act + 0x60) == policy) {
      if (policy == 2) {
        iVar3 = (int)base * 1000;
        if (iVar3 % _tick != 0) {
          iVar3 = iVar3 + _tick;
        }
        *(int *)(thr_act + 0x5c) = iVar3 / _tick;
      }
    }
    else if ((*(uint *)(*(int *)(thr_act + 0x180) + 0x168) & policy) == 0) {
      local_8 = 5;
    }
    else {
      *(policy_t *)(thr_act + 0x60) = policy;
      if (policy == 2) {
        iVar3 = (int)base * 1000;
        if (iVar3 % _tick != 0) {
          iVar3 = iVar3 + _tick;
        }
        *(int *)(thr_act + 0x5c) = iVar3 / _tick;
      }
      _compute_priority(thr_act,1);
    }
    LOCK();
    *(undefined4 *)(thr_act + 0x20) = 0;
    UNLOCK();
    _splx(uVar2);
  }
  return local_8;
}

