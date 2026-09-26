/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b81b8 */

undefined4 FUN_001b81b8(int param_1)

{
  undefined4 uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  return uVar1;
}

