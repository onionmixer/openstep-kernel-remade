
int _thread_policy(void *thread,int policy,int data)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if ((thread == (void *)0x0) || (3 < policy - 1U)) {
    local_8 = 4;
  }
  else {
    uVar2 = _splsched();
    piVar1 = (int *)((int)thread + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (*(int *)((int)thread + 0x60) == policy) {
      if (policy == 2) {
        iVar3 = data * 1000;
        if (iVar3 % _tick != 0) {
          iVar3 = iVar3 + _tick;
        }
        *(int *)((int)thread + 0x5c) = iVar3 / _tick;
      }
    }
    else if ((*(uint *)(*(int *)((int)thread + 0x180) + 0x168) & policy) == 0) {
      local_8 = 5;
    }
    else {
      *(int *)((int)thread + 0x60) = policy;
      if (policy == 2) {
        iVar3 = data * 1000;
        if (iVar3 % _tick != 0) {
          iVar3 = iVar3 + _tick;
        }
        *(int *)((int)thread + 0x5c) = iVar3 / _tick;
      }
      _compute_priority(thread,1);
    }
    LOCK();
    *(undefined4 *)((int)thread + 0x20) = 0;
    UNLOCK();
    _splx(uVar2);
  }
  return local_8;
}

