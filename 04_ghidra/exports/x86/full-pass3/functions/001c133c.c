/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c133c */

void FUN_001c133c(int param_1)

{
  undefined4 *puVar1;
  int local_c;
  undefined *local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  if (puVar1[1] != 0) {
    _IOFree(*puVar1,puVar1[1] << 2);
  }
  if (puVar1[3] != 0) {
    _IOFree(puVar1[2],puVar1[3] << 3);
  }
  _IOFree(puVar1,0x1c);
  local_c = param_1;
  local_8 = PTR_s_IODeviceDescription_001fa568;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

