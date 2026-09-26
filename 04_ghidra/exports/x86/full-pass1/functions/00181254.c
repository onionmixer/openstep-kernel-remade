/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181254 */

void FUN_00181254(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_freeKeys_values__001f9318,FUN_00181a08,
                FUN_00181a10);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_free_001f921c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_freeKeys_values__001f9318,FUN_00181a08,
                FUN_00181a38);
  _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_free_001f921c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_free_001f921c);
  local_c = param_1;
  local_8 = PTR_s_Object_001f9fc8;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

