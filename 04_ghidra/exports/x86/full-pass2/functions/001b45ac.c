/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b45ac */

void FUN_001b45ac(int param_1)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),PTR_s_lock_001f9220);
  uVar1 = *(undefined4 *)(param_1 + 0x4f4);
  *(undefined4 *)(param_1 + 0x4f4) = 0;
  if ((*(int *)(param_1 + 0x4ec) != 0) && (*(char *)(param_1 + 0x4fc) == '\x01')) {
    _IOFree(*(int *)(param_1 + 0x4ec),*(undefined4 *)(param_1 + 0x4f0));
    *(undefined4 *)(param_1 + 0x4ec) = 0;
  }
  _objc_msgSend(uVar1,PTR_s_unlock_001f9474);
  _objc_msgSend(uVar1,PTR_s_free_001f921c);
  local_c = param_1;
  local_8 = PTR_s_Object_001fa450;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

