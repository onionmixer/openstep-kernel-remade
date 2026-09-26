/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2a38 */

int FUN_001b2a38(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
  iVar1 = param_1 + 0x174;
  iVar2 = *(int *)(param_1 + 0x174);
  while (iVar2 != iVar1) {
    piVar3 = *(int **)(param_1 + 0x174);
    iVar2 = piVar3[1];
    iVar4 = piVar3[2];
    if (iVar1 == iVar2) {
      *(int *)(param_1 + 0x178) = iVar4;
    }
    else {
      *(int *)(iVar2 + 8) = iVar4;
    }
    if (iVar1 == iVar4) {
      *(int *)(param_1 + 0x174) = iVar2;
    }
    else {
      *(int *)(iVar4 + 4) = iVar2;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
    if (*piVar3 != 0) {
      _objc_msgSend(*piVar3,PTR_s_relinquishOwnership__001f9518,param_1);
    }
    _IOFree(piVar3,0xc);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
    iVar2 = *(int *)(param_1 + 0x174);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
  return param_1;
}

