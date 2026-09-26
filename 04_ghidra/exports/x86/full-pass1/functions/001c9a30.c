/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9a30 */

undefined4 FUN_001c9a30(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_removeObjectAt__001f9d28,*(int *)(param_1 + 8) + -1);
    return uVar1;
  }
  return 0;
}

