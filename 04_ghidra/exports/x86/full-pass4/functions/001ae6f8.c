/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae6f8 */

void FUN_001ae6f8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),PTR_s_unlockWith__001f9224,1);
  }
  else {
    _objc_msgSend(param_1,PTR_s_completeTransfer_withStatus_actu_001f9a64,*(int *)(param_3 + 0x18),
                  *(undefined4 *)(param_3 + 0x28),*(undefined4 *)(param_3 + 0x24));
    _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,param_3);
  }
  return;
}

