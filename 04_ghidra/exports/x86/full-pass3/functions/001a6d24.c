/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6d24 */

void FUN_001a6d24(int param_1)

{
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_unregisterUnixDisk__001f9c3c,*(undefined4 *)(param_1 + 0x1a4));
  local_c = param_1;
  local_8 = PTR_s_IOLogicalDisk_001fa158;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

