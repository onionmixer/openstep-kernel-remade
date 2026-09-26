/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cea70 */

void _objc_msgSendSuper(int param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (__objc_multithread_mask == 0) {
    iVar3 = 1;
    do {
      iVar4 = iVar3;
      LOCK();
      UNLOCK();
      bVar6 = _messageLock != 0;
      iVar3 = _messageLock;
      _messageLock = iVar4;
    } while (bVar6);
    puVar1 = *(uint **)(*(int *)(param_1 + 4) + 0x20);
    uVar5 = param_2;
    while( true ) {
      uVar5 = uVar5 & *puVar1;
      puVar2 = (uint *)puVar1[uVar5 + 2];
      if (puVar2 == (uint *)0x0) {
        UNRECOVERED_JUMPTABLE_00 =
             (code *)__class_lookupMethodAndLoadCache(*(undefined4 *)(param_1 + 4),param_2);
        _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0x001ceb94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
      if (param_2 == *puVar2) break;
      uVar5 = uVar5 + 1;
    }
    _messageLock = 0;
                    /* WARNING: Could not recover jumptable at 0x001ceb52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar2[2])();
    return;
  }
  puVar1 = *(uint **)(*(int *)(param_1 + 4) + 0x20);
  uVar5 = param_2;
  while( true ) {
    uVar5 = uVar5 & *puVar1;
    puVar2 = (uint *)puVar1[uVar5 + 2];
    if (puVar2 == (uint *)0x0) {
      UNRECOVERED_JUMPTABLE_00 =
           (code *)__class_lookupMethodAndLoadCache(*(undefined4 *)(param_1 + 4),param_2);
                    /* WARNING: Could not recover jumptable at 0x001ceaea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
    if (param_2 == *puVar2) break;
    uVar5 = uVar5 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x001ceab3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)puVar2[2])();
  return;
}

