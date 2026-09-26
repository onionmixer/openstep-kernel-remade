/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aabbc */

void FUN_001aabbc(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_lock_001f9220);
  iVar2 = _objc_msgSend(param_1,PTR_s_searchMulti__001f9b48,param_3);
  if ((iVar2 != 0) &&
     ((iVar1 = *(int *)(iVar2 + 0x10), iVar1 < 1 ||
      (*(int *)(iVar2 + 0x10) = iVar1 + -1, iVar1 == 1 || iVar1 + -1 < 0)))) {
    iVar1 = *(int *)(iVar2 + 8);
    piVar4 = *(int **)(iVar2 + 0xc);
    iVar3 = iVar1;
    if (param_1 + 0x144 != iVar1) {
      iVar3 = iVar1 + 8;
    }
    *(int **)(iVar3 + 4) = piVar4;
    if ((int *)(param_1 + 0x144) != piVar4) {
      piVar4 = piVar4 + 2;
    }
    *piVar4 = iVar1;
    _IOFree(iVar2,0x14);
    *(undefined4 *)(param_1 + 0x13c) = *param_3;
    *(undefined2 *)(param_1 + 0x140) = *(undefined2 *)(param_3 + 1);
    _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_send__001f9b4c,8);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_unlock_001f9474);
  return;
}

