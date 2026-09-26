/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb8ac */

int _NXHashRemove(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  
  uVar1 = (**(code **)*param_1)(param_1[4],param_2);
  piVar7 = (int *)((uVar1 % (uint)param_1[2]) * 8 + param_1[3]);
  iVar3 = *piVar7;
  uVar2 = _NXZoneFromPtr(param_1);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      if ((piVar7[1] == param_2) ||
         (iVar3 = (**(code **)(*param_1 + 4))(param_1[4],param_2,piVar7[1]), iVar3 != 0)) {
        iVar3 = piVar7[1];
        param_1[1] = param_1[1] + -1;
        *piVar7 = *piVar7 + -1;
        piVar7[1] = 0;
        return iVar3;
      }
    }
    else {
      piVar6 = (int *)piVar7[1];
      if (iVar3 == 2) {
        if ((*piVar6 == param_2) ||
           (iVar3 = (**(code **)(*param_1 + 4))(param_1[4],param_2,*piVar6), iVar3 != 0)) {
          piVar7[1] = piVar6[1];
          param_2 = *piVar6;
        }
        else {
          if ((piVar6[1] != param_2) &&
             (iVar3 = (**(code **)(*param_1 + 4))(param_1[4],param_2,piVar6[1]), iVar3 == 0)) {
            return 0;
          }
          piVar7[1] = *piVar6;
          param_2 = piVar6[1];
        }
        _free(piVar6);
        param_1[1] = param_1[1] + -1;
        *piVar7 = *piVar7 + -1;
        return param_2;
      }
      while (iVar3 = iVar3 + -1, iVar3 != -1) {
        if ((*piVar6 == param_2) ||
           (iVar4 = (**(code **)(*param_1 + 4))(param_1[4],param_2,*piVar6), iVar4 != 0)) {
          iVar4 = *piVar6;
          if (*piVar7 == 1) {
            pvVar5 = (void *)0x0;
          }
          else {
            pvVar5 = (void *)_NXZoneCalloc(uVar2,*piVar7 + -1,4);
          }
          if (*piVar7 + -1 != iVar3) {
            _memmove(pvVar5,(void *)piVar7[1],(*piVar7 - iVar3) * 4 - 4);
          }
          if (iVar3 != 0) {
            _memmove((void *)((int)pvVar5 + iVar3 * -4 + *piVar7 * 4 + -4),
                     (void *)(*piVar7 * 4 + piVar7[1] + iVar3 * -4),iVar3 * 4);
          }
          _free((void *)piVar7[1]);
          param_1[1] = param_1[1] + -1;
          *piVar7 = *piVar7 + -1;
          piVar7[1] = (int)pvVar5;
          return iVar4;
        }
        piVar6 = piVar6 + 1;
      }
    }
  }
  return 0;
}

