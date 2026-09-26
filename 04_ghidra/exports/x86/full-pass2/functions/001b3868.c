/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3868 */

void FUN_001b3868(int param_1)

{
  int local_c;
  undefined *local_8;
  
  if (*(int *)(param_1 + 0x110) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x110),PTR_s_free_001f921c);
  }
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa428;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

