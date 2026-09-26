/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8f94 */

undefined4 FUN_001c8f94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int local_18;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar5 = FUN_001c8938(*(undefined4 *)(param_1 + 8),param_3,*(undefined4 *)(param_1 + 0x10));
  iVar3 = *(int *)(iVar2 + iVar5 * 8);
  puVar4 = *(undefined4 **)(iVar2 + 4 + iVar5 * 8);
  puVar8 = puVar4;
  local_18 = iVar3;
  while( true ) {
    local_18 = local_18 + -1;
    if (local_18 == -1) {
      iVar6 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c);
      uVar7 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,(iVar3 + 1) * 8);
      puVar8 = (undefined4 *)(**(code **)(iVar6 + 4))(uVar7);
      if (iVar3 != 0) {
        _memmove(puVar8 + 2,puVar4,iVar3 << 3);
      }
      *puVar8 = param_3;
      puVar8[1] = param_4;
      if (iVar3 != 0) {
        _free(puVar4);
      }
      piVar1 = (int *)(iVar2 + iVar5 * 8);
      *piVar1 = *piVar1 + 1;
      *(undefined4 **)(iVar2 + 4 + iVar5 * 8) = puVar8;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      return 0;
    }
    iVar6 = FUN_001c89c8(*(undefined4 *)(param_1 + 8),param_3,*puVar8);
    if (iVar6 != 0) break;
    puVar8 = puVar8 + 2;
  }
  uVar7 = puVar8[1];
  *puVar8 = param_3;
  puVar8[1] = param_4;
  return uVar7;
}

