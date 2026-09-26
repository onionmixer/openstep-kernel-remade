
kern_return_t
_processor_set_policy_disable(processor_set_t processor_set,int policy,boolean_t change_threads)

{
  int *piVar1;
  int iVar2;
  void *thread;
  kern_return_t kVar3;
  
  if (((processor_set == 0) || (policy == 1)) || (3 < policy - 1U)) {
    kVar3 = 4;
  }
  else {
    piVar1 = (int *)(processor_set + 0x158);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (((policy & *(uint *)(processor_set + 0x168)) != 0) &&
       (*(uint *)(processor_set + 0x168) = *(uint *)(processor_set + 0x168) & ~policy,
       change_threads != 0)) {
      for (thread = *(void **)(processor_set + 0x138); (void *)(processor_set + 0x138) != thread;
          thread = *(void **)((int)thread + 0x18)) {
        if (*(int *)((int)thread + 0x60) == policy) {
          _thread_policy(thread,1,0);
        }
      }
    }
    LOCK();
    *(undefined4 *)(processor_set + 0x158) = 0;
    UNLOCK();
    kVar3 = 0;
  }
  return kVar3;
}

