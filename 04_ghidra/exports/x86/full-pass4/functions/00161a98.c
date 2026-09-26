/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161a98 */

kern_return_t _processor_set_policy_enable(processor_set_t processor_set,int policy)

{
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  
  if ((processor_set == 0) || (3 < policy - 1U)) {
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
    *(uint *)(processor_set + 0x168) = *(uint *)(processor_set + 0x168) | policy;
    LOCK();
    *(undefined4 *)(processor_set + 0x158) = 0;
    UNLOCK();
    kVar3 = 0;
  }
  return kVar3;
}

