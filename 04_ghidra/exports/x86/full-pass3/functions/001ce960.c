/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ce960 */

void _objc_msgSend(int *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  if (((uint)param_1 & __objc_multithread_mask) == 0) {
    if (param_1 == (int *)0x0) {
      return;
    }
    iVar2 = 1;
    do {
      iVar3 = iVar2;
      LOCK();
      UNLOCK();
      bVar5 = _messageLock != 0;
      iVar2 = _messageLock;
      _messageLock = iVar3;
    } while (bVar5);
    uVar4 = param_2;
    while( true ) {
      uVar4 = uVar4 & **(uint **)(*param_1 + 0x20);
      puVar1 = (uint *)(*(uint **)(*param_1 + 0x20))[uVar4 + 2];
      if (puVar1 == (uint *)0x0) {
        UNRECOVERED_JUMPTABLE_00 = (code *)__class_lookupMethodAndLoadCache(*param_1,param_2);
        _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0x001cea5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
      if (param_2 == *puVar1) break;
      uVar4 = uVar4 + 1;
    }
    _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0x001cea27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar1[2])();
    return;
  }
  uVar4 = param_2;
  while( true ) {
    uVar4 = uVar4 & **(uint **)(*param_1 + 0x20);
    puVar1 = (uint *)(*(uint **)(*param_1 + 0x20))[uVar4 + 2];
    if (puVar1 == (uint *)0x0) {
      UNRECOVERED_JUMPTABLE_00 = (code *)__class_lookupMethodAndLoadCache(*param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x001ce9c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
    if (param_2 == *puVar1) break;
    uVar4 = uVar4 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x001ce995. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)puVar1[2])();
  return;
}

