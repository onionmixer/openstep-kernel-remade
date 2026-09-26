/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc4d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _NXMapInsert(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint local_20;
  
  while( true ) {
    iVar2 = param_1[3];
    uVar4 = (**(code **)*param_1)(param_1,param_2);
    uVar4 = (uVar4 + (uVar4 & 0xffff ^ uVar4 >> 0x10) * 0xfff1) % (uint)param_1[2];
    piVar1 = (int *)(iVar2 + uVar4 * 8);
    if (param_2 == -1) break;
    _DAT_001e5594 = _DAT_001e5594 + 1;
    if (*piVar1 == -1) {
      _DAT_001e5598 = _DAT_001e5598 + 1;
      *piVar1 = param_2;
      piVar1[1] = param_3;
      param_1[1] = param_1[1] + 1;
      return 0;
    }
    if (param_2 == *piVar1) {
      iVar5 = 1;
    }
    else {
      iVar5 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
    }
    if (iVar5 != 0) {
      iVar2 = piVar1[1];
      _DAT_001e5598 = _DAT_001e5598 + 1;
      if (param_3 != iVar2) {
        piVar1[1] = param_3;
        return iVar2;
      }
      return iVar2;
    }
    local_20 = uVar4;
    if (param_1[2] != param_1[1]) goto LAB_001cc5e0;
    FUN_001cc3f8(param_1);
  }
  pcVar7 = "*** NXMapInsert: invalid key: -1\n";
LAB_001cc6d9:
  __NXLogError(pcVar7);
  return 0;
LAB_001cc5e0:
  while( true ) {
    uVar6 = 0;
    if (local_20 + 1 < (uint)param_1[2]) {
      uVar6 = local_20 + 1;
    }
    if (uVar6 == uVar4) break;
    _DAT_001e559c = _DAT_001e559c + 1;
    piVar1 = (int *)(iVar2 + uVar6 * 8);
    if (*piVar1 == -1) {
      while (param_2 != -1) {
        piVar1 = (int *)(iVar2 + uVar4 * 8);
        iVar5 = *piVar1;
        iVar3 = piVar1[1];
        *piVar1 = param_2;
        piVar1[1] = param_3;
        uVar6 = uVar4 + 1;
        uVar4 = 0;
        param_3 = iVar3;
        param_2 = iVar5;
        if (uVar6 < (uint)param_1[2]) {
          uVar4 = uVar6;
        }
      }
      param_1[1] = param_1[1] + 1;
      if ((uint)(param_1[1] * 4) < (uint)(param_1[2] * 3) || param_1[1] * 4 + param_1[2] * -3 == 0)
      {
        return 0;
      }
      FUN_001cc3f8(param_1);
      return 0;
    }
    if (param_2 == *piVar1) {
      iVar5 = 1;
    }
    else {
      iVar5 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
    }
    local_20 = uVar6;
    if (iVar5 != 0) {
      iVar2 = piVar1[1];
      if (param_3 != iVar2) {
        piVar1[1] = param_3;
        return iVar2;
      }
      return iVar2;
    }
  }
  pcVar7 = "**** NXMapInsert: bug\n";
  goto LAB_001cc6d9;
}

