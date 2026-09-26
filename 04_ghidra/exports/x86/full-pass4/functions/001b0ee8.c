/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0ee8 */

int FUN_001b0ee8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_10;
  undefined *local_c;
  undefined4 local_8;
  
  local_8 = *param_5;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
  puVar3 = *(undefined4 **)(param_1 + 0x174);
  do {
    iVar2 = -0x2c2;
    if ((undefined4 *)(param_1 + 0x174) == puVar3) break;
    uVar1 = *puVar3;
    puVar3 = (undefined4 *)puVar3[1];
    iVar2 = _objc_msgSend(uVar1,PTR_s_getCharValues_forParameter_count_001f9530,param_3,param_4,
                          &local_8);
  } while (iVar2 == -0x2c2);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
  if (iVar2 == -0x2c2) {
    local_10 = param_1;
    local_c = PTR_s_IODevice_001fa400;
    iVar2 = _objc_msgSendSuper(&local_10,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                               param_4,&local_8);
  }
  *param_5 = local_8;
  return iVar2;
}

