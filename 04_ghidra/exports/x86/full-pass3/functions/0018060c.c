/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018060c */

void FUN_0018060c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = _objc_msgSend(*(int *)(param_1 + 8),PTR_s_freeObjects_001f92ec,PTR_s_free_001f921c);
    _objc_msgSend(uVar1);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

