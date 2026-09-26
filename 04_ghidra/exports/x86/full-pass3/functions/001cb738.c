/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb738 */

int _NXHashInsertIfAbsent(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  uVar1 = (**(code **)*param_1)(param_1[4],param_2);
  piVar6 = (int *)((uVar1 % (uint)param_1[2]) * 8 + param_1[3]);
  iVar3 = *piVar6;
  uVar2 = _NXZoneFromPtr(param_1);
  if (iVar3 == 0) {
    *piVar6 = *piVar6 + 1;
    piVar6[1] = param_2;
    param_1[1] = param_1[1] + 1;
    return param_2;
  }
  if (iVar3 == 1) {
    if ((piVar6[1] == param_2) ||
       (iVar3 = (**(code **)(*param_1 + 4))(param_1[4],param_2,piVar6[1]), iVar3 != 0)) {
      return piVar6[1];
    }
    piVar4 = (int *)_NXZoneCalloc(uVar2,2,4);
    piVar4[1] = piVar6[1];
    *piVar4 = param_2;
    *piVar6 = *piVar6 + 1;
    piVar6[1] = (int)piVar4;
    param_1[1] = param_1[1] + 1;
    if ((uint)param_1[1] <= (uint)param_1[2]) {
      return param_2;
    }
  }
  else {
    piVar4 = (int *)piVar6[1];
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      if ((*piVar4 == param_2) ||
         (iVar5 = (**(code **)(*param_1 + 4))(param_1[4],param_2,*piVar4), iVar5 != 0)) {
        return *piVar4;
      }
      piVar4 = piVar4 + 1;
    }
    piVar4 = (int *)_NXZoneCalloc(uVar2,*piVar6 + 1,4);
    if (*piVar6 != 0) {
      _memmove(piVar4 + 1,(void *)piVar6[1],*piVar6 * 4);
    }
    *piVar4 = param_2;
    _free((void *)piVar6[1]);
    *piVar6 = *piVar6 + 1;
    piVar6[1] = (int)piVar4;
    param_1[1] = param_1[1] + 1;
    if ((uint)param_1[1] <= (uint)param_1[2]) {
      return param_2;
    }
  }
  FUN_001cb504(param_1);
  return param_2;
}

