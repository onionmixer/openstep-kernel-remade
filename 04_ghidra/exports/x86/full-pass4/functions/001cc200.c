/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _NXMapMember(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = param_1[3];
  uVar2 = (**(code **)*param_1)(param_1,param_2);
  uVar2 = ((uVar2 & 0xffff ^ uVar2 >> 0x10) * 0xfff1 + uVar2) % (uint)param_1[2];
  piVar1 = (int *)(iVar4 + uVar2 * 8);
  if (*piVar1 == -1) {
LAB_001cc2e8:
    iVar4 = -1;
  }
  else {
    _DAT_001e5580 = _DAT_001e5580 + 1;
    if (param_2 == *piVar1) {
      iVar3 = 1;
    }
    else {
      iVar3 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
    }
    uVar5 = uVar2;
    if (iVar3 == 0) {
      do {
        uVar6 = 0;
        if (uVar5 + 1 < (uint)param_1[2]) {
          uVar6 = uVar5 + 1;
        }
        if (uVar2 == uVar6) goto LAB_001cc2e8;
        _DAT_001e5588 = _DAT_001e5588 + 1;
        piVar1 = (int *)(iVar4 + uVar6 * 8);
        if (*piVar1 == -1) goto LAB_001cc2e8;
        if (*piVar1 == param_2) {
          iVar3 = 1;
        }
        else {
          iVar3 = (**(code **)(*param_1 + 4))(param_1,*piVar1,param_2);
        }
        uVar5 = uVar6;
      } while (iVar3 == 0);
      *param_3 = piVar1[1];
      iVar4 = *piVar1;
    }
    else {
      *param_3 = piVar1[1];
      _DAT_001e5584 = _DAT_001e5584 + 1;
      iVar4 = *piVar1;
    }
  }
  return iVar4;
}

