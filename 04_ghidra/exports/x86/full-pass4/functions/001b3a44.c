/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3a44 */

undefined4 FUN_001b3a44(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if ((*(int *)(param_1 + 0x10c) == 0) || (*(int *)(param_1 + 0x10c) == param_3)) {
    *(int *)(param_1 + 0x10c) = param_3;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffd2b;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return uVar1;
}

