/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae74c */

void FUN_001ae74c(int param_1)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_lastReadyState_001f9c70);
  if ((*(int *)(param_1 + 0x1b0) == param_1 + 0x1b0) &&
     (((*(int *)(param_1 + 0x1a8) == param_1 + 0x1a8 || (iVar1 - 2U < 2)) ||
      (*(char *)(param_1 + 0x1c8) != '\0')))) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlockWith__001f9224,iVar1);
  if (iVar1 == 1) {
    _thread_block();
  }
  return;
}

