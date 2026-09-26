/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c20d8 */

void FUN_001c20d8(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int local_c;
  undefined *local_8;
  
  puVar1 = *(uint **)(param_1 + 0x24);
  if (puVar1[1] != 0) {
    uVar2 = 0;
    if (*puVar1 != 0) {
      do {
        _objc_msgSend(*(undefined4 *)(puVar1[1] + uVar2 * 4),PTR_s_free_001f921c);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *puVar1);
    }
    _IOFree(puVar1[1],*puVar1 * 4);
  }
  _IOFree(puVar1,8);
  local_c = param_1;
  local_8 = PTR_s_IOEISADeviceDescription_001fa5b8;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

