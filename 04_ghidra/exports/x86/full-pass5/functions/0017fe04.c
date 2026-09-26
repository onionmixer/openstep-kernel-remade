/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017fe04 */

int FUN_0017fe04(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_acquire_001f92b8);
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_indexOf__001f92c0,param_3);
  if (iVar1 == -1) {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_addObject__001f92c4,param_3);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_acquire_001f92b8);
  iVar1 = 0;
  if ((0 < *(int *)(param_1 + 0x18)) && (*(int *)(param_1 + 0x20) == 0)) {
    iVar1 = param_1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_release_001f92bc);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_release_001f92bc);
  return iVar1;
}

