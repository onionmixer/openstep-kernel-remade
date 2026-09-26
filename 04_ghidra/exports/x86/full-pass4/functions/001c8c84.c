/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8c84 */

void FUN_001c8c84(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_freeKeys_values__001f9318,FUN_001c8a78,FUN_001c8a78);
  _free(*(void **)(param_1 + 0x14));
  local_c = param_1;
  local_8 = PTR_s_Object_001fa680;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

