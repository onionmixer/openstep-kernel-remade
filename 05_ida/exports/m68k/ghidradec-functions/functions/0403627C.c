
int sub_403627C(int param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sword sVar6;
  int *piVar7;
  
  uVar4 = param_2[2] + param_2[1];
  if (*param_2 == 0) {
    if ((param_2[1] & 0x3ff) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirprepareentr);
    }
    if (*(int *)(*(int *)(param_1 + 0x4e) + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirblksizFsize);
    }
    iVar3 = _bmap(param_1,param_2[1] >> (*(uint *)(*(int *)(param_1 + 0x4e) + 0x50) & 0x3f),0,
                  (param_2[1] & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) + 0x400,0);
    if ((iVar3 < 1) || (*(char *)(dword_40B57D4 + 100) != '\0')) {
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        return 0x1c;
      }
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    *(uint *)(param_1 + 0x6e) = uVar4;
  }
  else {
    if (uVar4 <= *(uint *)(param_1 + 0x6e)) goto loc_4036346;
    *(uint *)(param_1 + 0x6e) = uVar4 + 0x3ff & 0xfffffc00;
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
loc_4036346:
  uVar4 = _blkatoff(param_1,param_2[1],param_2 + 4);
  param_2[3] = uVar4;
  if (uVar4 == 0) {
    iVar3 = (int)*(char *)(dword_40B57D4 + 100);
  }
  else {
    piVar2 = (int *)param_2[4];
    piVar7 = piVar2;
    if (*param_2 == 0) {
      _bzero(piVar2,0x400);
      *(undefined2 *)(piVar2 + 1) = 0x400;
    }
    else {
      if (2 < *param_2) {
                    /* WARNING: Subroutine does not return */
        _panic(aDirprepareentr_0);
      }
      iVar3 = (*(word *)((int)piVar2 + 6) + 4 & 0xfffffffc) + 8;
      iVar5 = (uint)*(word *)(piVar2 + 1) - iVar3;
      sVar6 = (sword)iVar5;
      uVar4 = (uint)*(word *)(piVar2 + 1);
      if ((int)uVar4 < (int)param_2[2]) {
        do {
          iVar1 = (int)piVar2 + uVar4;
          if (*piVar7 == 0) {
            iVar5 = iVar3 + iVar5;
          }
          else {
            *(sword *)(piVar7 + 1) = (sword)iVar3;
            piVar7 = (int *)(iVar3 + (int)piVar7);
          }
          iVar3 = (*(word *)(iVar1 + 6) + 4 & 0xfffffffc) + 8;
          iVar5 = ((uint)*(word *)(iVar1 + 4) - iVar3) + iVar5;
          sVar6 = (sword)iVar5;
          uVar4 = *(word *)(iVar1 + 4) + uVar4;
          _bcopy(iVar1,piVar7,iVar3);
        } while ((int)uVar4 < (int)param_2[2]);
      }
      if (*piVar7 == 0) {
        *(sword *)(piVar7 + 1) = (sword)iVar3 + sVar6;
      }
      else {
        *(sword *)(piVar7 + 1) = (sword)iVar3;
        piVar7 = (int *)(iVar3 + (int)piVar7);
        *(sword *)(piVar7 + 1) = sVar6;
      }
    }
    param_2[4] = (uint)piVar7;
    iVar3 = 0;
  }
  return iVar3;
}
