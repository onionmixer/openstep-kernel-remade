/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc6ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _NXMapRemove(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_a4;
  undefined1 *local_98;
  int local_94;
  uint local_90;
  undefined1 local_84 [128];
  
  iVar2 = param_1[3];
  uVar3 = (**(code **)*param_1)(param_1,param_2);
  uVar3 = (uVar3 + (uVar3 & 0xffff ^ uVar3 >> 0x10) * 0xfff1) % (uint)param_1[2];
  piVar1 = (int *)(iVar2 + uVar3 * 8);
  local_90 = 1;
  local_a4 = 0;
  local_94 = 0;
  if (*piVar1 != -1) {
    _DAT_001e55a0 = _DAT_001e55a0 + 1;
    if (param_2 == *piVar1) {
      iVar4 = 1;
    }
    else {
      iVar4 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
    }
    uVar7 = uVar3;
    if (iVar4 != 0) {
      local_a4 = 1;
      local_94 = piVar1[1];
    }
    while( true ) {
      uVar6 = uVar7 + 1;
      uVar7 = 0;
      if (uVar6 < (uint)param_1[2]) {
        uVar7 = uVar6;
      }
      if ((uVar3 == uVar7) || (piVar1 = (int *)(iVar2 + uVar7 * 8), *piVar1 == -1)) break;
      if (param_2 == *piVar1) {
        iVar4 = 1;
      }
      else {
        iVar4 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
      }
      if (iVar4 != 0) {
        local_a4 = local_a4 + 1;
        local_94 = piVar1[1];
      }
      local_90 = local_90 + 1;
    }
    if (local_a4 != 0) {
      if (local_a4 != 1) {
        __NXLogError("**** NXMapRemove: incorrect table\n");
      }
      if (local_90 < 0x11) {
        local_98 = local_84;
      }
      else {
        local_98 = _malloc(local_90 * 8 - 8);
      }
      iVar4 = 0;
      uVar7 = local_90;
      while (uVar7 = uVar7 - 1, uVar7 != 0xffffffff) {
        piVar1 = (int *)(iVar2 + uVar3 * 8);
        if (param_2 == *piVar1) {
          iVar5 = 1;
        }
        else {
          iVar5 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
        }
        if (iVar5 == 0) {
          iVar5 = piVar1[1];
          *(int *)(local_98 + iVar4 * 8) = *piVar1;
          *(int *)(local_98 + iVar4 * 8 + 4) = iVar5;
          iVar4 = iVar4 + 1;
        }
        *piVar1 = -1;
        piVar1[1] = 0;
        uVar6 = uVar3 + 1;
        uVar3 = 0;
        if (uVar6 < (uint)param_1[2]) {
          uVar3 = uVar6;
        }
      }
      param_1[1] = param_1[1] - local_90;
      if (iVar4 != local_90 - 1) {
        __NXLogError("**** NXMapRemove: bug\n");
      }
      while (iVar4 = iVar4 + -1, iVar4 != -1) {
        _NXMapInsert(param_1,*(undefined4 *)(local_98 + iVar4 * 8),
                     *(undefined4 *)(local_98 + iVar4 * 8 + 4));
      }
      if (local_90 < 0x11) {
        return local_94;
      }
      _free(local_98);
      return local_94;
    }
  }
  return 0;
}

