/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab854 */

undefined4 FUN_001ab854(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(byte *)(param_1 + 0x128) & 1) == 0) {
    uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x154),PTR_s_send__001f9b4c,1);
  }
  return uVar1;
}

