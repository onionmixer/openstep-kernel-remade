/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0b70 */

void FUN_001b0b70(int param_1)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_evClose_token__001f9a44,*(undefined4 *)(param_1 + 0x134),
                *(undefined4 *)(param_1 + 0x114));
  uVar1 = _task_self(*(undefined4 *)(param_1 + 0x134));
  _port_deallocate_EXTERNAL(uVar1);
  uVar1 = _task_self(*(undefined4 *)(param_1 + 0x138));
  _port_deallocate_EXTERNAL(uVar1);
  uVar1 = _task_self(*(undefined4 *)(param_1 + 0x13c));
  _port_deallocate_EXTERNAL(uVar1);
  uVar1 = _task_self(*(undefined4 *)(param_1 + 0x148));
  _port_set_deallocate_EXTERNAL(uVar1);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_free_001f921c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_free_001f921c);
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa400;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

