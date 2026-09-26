/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae984 */

bool FUN_001ae984(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_lock_001f9220);
  bVar1 = *(int *)(param_1 + 0x130) == 0;
  if (bVar1) {
    *(byte *)(param_1 + 0x11c) = *(byte *)(param_1 + 0x11c) & 0xfe;
    *(undefined4 *)(param_1 + 0x130) = param_3;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_unlock_001f9474);
  return !bVar1;
}

