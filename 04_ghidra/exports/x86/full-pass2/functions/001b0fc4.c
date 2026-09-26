/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0fc4 */

int FUN_001b0fc4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
  puVar1 = *(undefined4 **)(param_1 + 0x174);
  iVar4 = -0x2c2;
  while ((undefined4 *)(param_1 + 0x174) != puVar1) {
    uVar2 = *puVar1;
    puVar1 = (undefined4 *)puVar1[1];
    iVar3 = _objc_msgSend(uVar2,PTR_s_setCharValues_forParameter_count_001f9538,param_3,param_4,
                          param_5);
    if (iVar3 != -0x2c2) {
      iVar4 = iVar3;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
  if (iVar4 == -0x2c2) {
    local_c = param_1;
    local_8 = PTR_s_IODevice_001fa400;
    iVar4 = _objc_msgSendSuper(&local_c,PTR_s_setCharValues_forParameter_count_001f9538,param_3,
                               param_4,param_5);
  }
  return iVar4;
}

