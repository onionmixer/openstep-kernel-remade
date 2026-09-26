/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc3f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001cc3f8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int local_10;
  
  piVar1 = *(int **)(param_1 + 0xc);
  local_10 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 8) + 1;
  *(undefined4 *)(param_1 + 4) = 0;
  iVar3 = _NXZoneFromPtr(param_1);
  iVar6 = *(int *)(param_1 + 8);
  puVar4 = (undefined4 *)(**(code **)(iVar3 + 4))(iVar3,iVar6 * 8);
  puVar5 = puVar4;
  while (iVar6 = iVar6 + -1, iVar6 != -1) {
    *puVar5 = 0xffffffff;
    puVar5[1] = 0;
    puVar5 = puVar5 + 2;
  }
  *(undefined4 **)(param_1 + 0xc) = puVar4;
  _DAT_001e558c = _DAT_001e558c + 1;
  _DAT_001e5590 = _DAT_001e5590 + *(int *)(param_1 + 4);
  piVar7 = piVar1;
  while (local_10 = local_10 + -1, local_10 != -1) {
    if (*piVar7 != -1) {
      _NXMapInsert(param_1,*piVar7,piVar7[1]);
    }
    piVar7 = piVar7 + 2;
  }
  if (*(int *)(param_1 + 4) != iVar2) {
    __NXLogError(
                "*** maptable: count differs after rehashing; probably indicates a broken invariant: there are x and y such as isEqual(x, y) is TRUE but hash(x) != hash (y)\n"
                );
  }
  _free(piVar1);
  return;
}

