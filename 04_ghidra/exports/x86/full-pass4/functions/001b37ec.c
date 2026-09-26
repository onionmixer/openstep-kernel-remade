/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b37ec */

int FUN_001b37ec(int param_1)

{
  undefined4 uVar1;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IODevice_001fa428;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if (*(int *)(param_1 + 0x110) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x110),PTR_s_free_001f921c);
  }
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(param_1 + 0x110) = uVar1;
  return param_1;
}

