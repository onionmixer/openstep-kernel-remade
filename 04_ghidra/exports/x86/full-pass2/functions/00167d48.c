/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167d48 */

kern_return_t _thread_resume(thread_act_t target_act)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  kern_return_t kVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (target_act == 0) {
    kVar4 = 4;
  }
  else {
    kVar4 = 0;
    uVar5 = _splsched();
    piVar1 = (int *)(target_act + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(target_act + 0x8c);
    if (iVar2 < 1) {
      kVar4 = 5;
    }
    else {
      *(int *)(target_act + 0x8c) = iVar2 + -1;
      if ((iVar2 == 1) &&
         (iVar2 = *(int *)(target_act + 0x40), *(int *)(target_act + 0x40) = iVar2 + -1, iVar2 == 1)
         ) {
        uVar3 = *(uint *)(target_act + 0x4c);
        uVar6 = uVar3 & 0xffffffed;
        *(uint *)(target_act + 0x4c) = uVar6;
        if ((uVar3 & 5) == 0) {
          *(uint *)(target_act + 0x4c) = uVar6 | 4;
          _thread_setrun(target_act,1);
        }
      }
    }
    LOCK();
    *(undefined4 *)(target_act + 0x20) = 0;
    UNLOCK();
    _splx(uVar5);
  }
  return kVar4;
}

