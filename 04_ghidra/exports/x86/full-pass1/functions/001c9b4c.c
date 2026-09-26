/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9b4c */

int FUN_001c9b4c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 = iVar1 + -1, iVar1 != -1) {
    _objc_msgSend(*(undefined4 *)(*(int *)(param_1 + 4) + iVar1 * 4),PTR_s_perform_with__001f923c,
                  param_3,param_4);
  }
  return param_1;
}

