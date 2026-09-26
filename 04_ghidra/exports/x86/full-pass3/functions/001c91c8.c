/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c91c8 */

undefined4 FUN_001c91c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  void *local_14;
  undefined4 *local_10;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar6 = FUN_001c8938(*(undefined4 *)(param_1 + 8),param_3,*(undefined4 *)(param_1 + 0x10));
  iVar3 = *(int *)(iVar2 + iVar6 * 8);
  puVar4 = *(undefined4 **)(iVar2 + 4 + iVar6 * 8);
  iVar9 = iVar3 + -1;
  if (iVar9 != -1) {
    local_10 = puVar4;
    do {
      iVar7 = FUN_001c89c8(*(undefined4 *)(param_1 + 8),param_3,*local_10);
      if (iVar7 != 0) {
        uVar5 = local_10[1];
        if (iVar3 == 1) {
          local_14 = (void *)0x0;
        }
        else {
          iVar7 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c);
          uVar8 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,(iVar3 + -1) * 8);
          local_14 = (void *)(**(code **)(iVar7 + 4))(uVar8);
        }
        if (iVar3 + -1 != iVar9) {
          _memmove(local_14,puVar4,(iVar3 - iVar9) * 8 - 8);
        }
        if (iVar9 != 0) {
          _memmove((void *)((int)local_14 + iVar9 * -8 + iVar3 * 8 + -8),
                   puVar4 + iVar3 * 2 + iVar9 * -2,iVar9 * 8);
        }
        _free(puVar4);
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        piVar1 = (int *)(iVar2 + iVar6 * 8);
        *piVar1 = *piVar1 + -1;
        *(void **)(iVar2 + 4 + iVar6 * 8) = local_14;
        return uVar5;
      }
      local_10 = local_10 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != -1);
  }
  return 0;
}

