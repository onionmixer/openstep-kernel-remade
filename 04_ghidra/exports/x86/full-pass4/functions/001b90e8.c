/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b90e8 */

undefined4 FUN_001b90e8(int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
  iVar2 = *(int *)(param_1 + 0x2c);
  if (param_1 + 0x2c == iVar2) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    uVar1 = 0;
  }
  else {
    do {
      *(undefined4 *)(iVar2 + 0x34) = 1;
      *(int *)(iVar2 + 0x38) = (int)param_3;
      iVar2 = *(int *)(iVar2 + 0x3c);
    } while (param_1 + 0x2c != iVar2);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    uVar1 = 1;
  }
  return uVar1;
}

