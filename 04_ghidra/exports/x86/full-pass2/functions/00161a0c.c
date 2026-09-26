/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161a0c */

kern_return_t
_processor_set_max_priority(processor_set_t processor_set,int max_priority,boolean_t change_threads)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  
  if ((processor_set == 0) || (0x1f < (uint)max_priority)) {
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
    *(int *)(processor_set + 0x164) = max_priority;
    if (change_threads != 0) {
      for (iVar2 = *(int *)(processor_set + 0x138); processor_set + 0x138 != iVar2;
          iVar2 = *(int *)(iVar2 + 0x18)) {
        if (*(int *)(iVar2 + 0x54) < max_priority) {
          _thread_max_priority(iVar2,processor_set,max_priority);
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

