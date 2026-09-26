/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab494 */

void FUN_001ab494(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_clearTimeout_001f9b50);
  if (*(int *)(param_1 + 0x154) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x154),PTR_s_send__001f9b4c,4);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x154),PTR_s_free_001f921c);
  }
  if (*(int *)(param_1 + 0x150) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x150),PTR_s_free_001f921c);
  }
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa310;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

