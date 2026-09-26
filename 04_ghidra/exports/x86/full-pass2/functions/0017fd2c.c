/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017fd2c */

int FUN_0017fd2c(int param_1)

{
  int iVar1;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_acquire_001f92b8);
  if (*(int *)(param_1 + 0x18) < 1) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_acquire_001f92b8);
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)(param_1 + 0x20) = iVar1 + 1;
    if (iVar1 + 1 < 0) {
      *(int *)(param_1 + 0x20) = iVar1;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_release_001f92bc);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_release_001f92bc);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_free_001f921c);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_free_001f921c);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_free_001f921c);
    local_c = param_1;
    local_8 = PTR_s_KernBusItem_001f9f50;
    param_1 = _objc_msgSendSuper(&local_c,PTR_s_dealloc_001f9268);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s_release_001f92bc);
  }
  return param_1;
}

