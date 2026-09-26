/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161aec */

kern_return_t
_processor_set_policy_disable(processor_set_t processor_set,int policy,boolean_t change_threads)

{
  int *piVar1;
  int iVar2;
  thread_act_t thr_act;
  kern_return_t kVar3;
  mach_msg_type_number_t unaff_EBX;
  boolean_t unaff_ESI;
  
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
      for (thr_act = *(thread_act_t *)(processor_set + 0x138); processor_set + 0x138 != thr_act;
          thr_act = *(thread_act_t *)(thr_act + 0x18)) {
        if (*(int *)(thr_act + 0x60) == policy) {
          _thread_policy(thr_act,1,(policy_base_t)0x0,unaff_EBX,unaff_ESI);
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

