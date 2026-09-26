/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aaf84 */

void FUN_001aaf84(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_free_001f921c);
  _port_release(*(undefined4 *)(param_1 + 4));
  local_c = param_1;
  local_8 = PTR_s_Object_001fa338;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

