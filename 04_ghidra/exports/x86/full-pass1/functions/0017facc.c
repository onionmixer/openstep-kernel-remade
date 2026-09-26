/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017facc */

undefined1 _KernBusInterruptDispatch(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  pcVar1 = *(code **)(param_1 + 0x28);
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x1c));
  puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  iVar4 = *(int *)(param_1 + 0x18);
  while (0 < iVar4) {
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    (*pcVar1)(uVar2,param_2);
    iVar4 = iVar4 + -1;
  }
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
  uVar3 = 0;
  if ((0 < *(int *)(param_1 + 0x18)) && (*(int *)(param_1 + 0x20) == 0)) {
    uVar3 = 1;
  }
  _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  _KernLockRelease(*(undefined4 *)(param_1 + 0x1c));
  return uVar3;
}

