/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ff44 */

int FUN_0017ff44(int param_1)

{
  int iVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_acquire_001f92b8);
  iVar1 = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = iVar1 + 1;
  if (iVar1 + 1 < 0) {
    *(int *)(param_1 + 0x20) = iVar1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x24),PTR_s_release_001f92bc);
  return param_1;
}

