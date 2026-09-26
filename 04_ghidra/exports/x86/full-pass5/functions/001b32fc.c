/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b32fc */

undefined4 FUN_001b32fc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0xc);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return uVar1;
}

