/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0404 */

int FUN_001a0404(int param_1)

{
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  *(undefined4 *)(param_1 + 0x144) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  _objc_msgSend(param_1,PTR_s_setPointerScaling_data__001f9544,5,&DAT_001d58bc);
  return param_1;
}

