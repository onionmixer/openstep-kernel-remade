/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f8c0 */

void FUN_0019f8c0(int param_1)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x124);
  _objc_msgSend(uVar1,PTR_s_lock_001f9220);
  DAT_001e488c = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),PTR_s_free_001f921c);
  }
  if (*(int *)(param_1 + 300) != 0) {
    _objc_msgSend(*(int *)(param_1 + 300),PTR_s_relinquishOwnership__001f9518,param_1);
  }
  _objc_msgSend(uVar1,PTR_s_unlock_001f9474);
  _objc_msgSend(uVar1,PTR_s_free_001f921c);
  local_c = param_1;
  local_8 = PTR_s_IOEventSource_001fa040;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

