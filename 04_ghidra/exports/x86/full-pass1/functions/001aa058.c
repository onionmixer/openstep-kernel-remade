/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa058 */

void FUN_001aa058(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_condition_001f9b60);
  if (iVar1 == 2) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_lock_001f9220);
    *(undefined4 *)(param_1 + 0x10) = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_unlockWith__001f9224,1);
  }
  return;
}

