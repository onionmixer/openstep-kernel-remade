/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac298 */

/* Entry confirmed from original binary metadata: IODisk(kernelDiskMethods)
   completeTransfer:withStatus:actualLength: */

void FUN_001ac298(undefined4 param_1,undefined4 param_2,byte *param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  
  if (param_4 != 0) {
    *param_3 = *param_3 | 4;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s_errnoFromReturn__001f93b4,param_4);
  *(undefined2 *)(param_3 + 0x1c) = uVar1;
  *(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x14) - param_5;
  _biodone(param_3);
  return;
}

