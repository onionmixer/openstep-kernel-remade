/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018024c */

void _IOSendInterrupt(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = _curipl();
  if (iVar2 < 7) {
    _KernLockAcquire(*(undefined4 *)(iVar1 + 0x30));
    if ((*(byte *)(iVar1 + 0x54) & 3) == 0) {
      *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 1;
      _KernLockRelease(*(undefined4 *)(iVar1 + 0x30));
      puVar3 = &DAT_001e0fd0;
      puVar4 = (undefined4 *)(iVar1 + 0x14);
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      *(undefined4 *)(iVar1 + 0x28) = param_3;
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x2c);
      iVar2 = _ipc_mqueue_send_interrupt(iVar1);
      if (iVar2 != 0) {
        _KernLockAcquire(*(undefined4 *)(iVar1 + 0x30));
        *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) & 0xfe | 2;
        _KernLockRelease(*(undefined4 *)(iVar1 + 0x30));
        _calloutEntryDispatch(iVar1 + 0x34);
      }
    }
    else {
      _KernLockRelease(*(undefined4 *)(iVar1 + 0x30));
    }
  }
  return;
}

