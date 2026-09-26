/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f124 */

int FUN_0017f124(int param_1)

{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 0x1c)) {
    return param_1;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar1 + -1;
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__destroyRange__001f9274,param_1);
    return iVar1;
  }
  return 0;
}

