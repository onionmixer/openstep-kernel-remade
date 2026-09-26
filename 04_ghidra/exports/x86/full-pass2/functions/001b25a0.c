/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b25a0 */

void FUN_001b25a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_3 < 4) {
    iVar1 = param_3;
  }
  *(int *)(*(int *)(param_1 + 0x168) + 0x1c) = iVar1;
  _objc_msgSend(param_1,PTR_s_moveCursor_001f9988);
  return;
}

