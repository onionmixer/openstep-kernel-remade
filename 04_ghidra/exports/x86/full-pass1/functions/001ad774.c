/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad774 */

undefined4 FUN_001ad774(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  *(undefined4 *)(param_3 + 0x28) = 0xffffffff;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_lock_001f9220);
  if ((*(byte *)(param_3 + 0x20) & 1) == 0) {
    piVar3 = (int *)(param_1 + 0x1b0);
  }
  else {
    piVar3 = (int *)(param_1 + 0x1a8);
  }
  if ((int *)*piVar3 == piVar3) {
    *piVar3 = param_3;
    piVar3[1] = param_3;
    *(int **)(param_3 + 0x2c) = piVar3;
    *(int **)(param_3 + 0x30) = piVar3;
  }
  else {
    iVar1 = piVar3[1];
    *(int *)(param_3 + 0x30) = iVar1;
    *(int **)(param_3 + 0x2c) = piVar3;
    piVar3[1] = param_3;
    *(int *)(iVar1 + 0x2c) = param_3;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlockWith__001f9224,1);
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),PTR_s_lockWhen__001f9218,1);
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),PTR_s_unlockWith__001f9224,0);
    uVar2 = *(undefined4 *)(param_3 + 0x28);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

