
int sub_402C364(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  sword sVar5;
  uint uVar6;
  int iVar7;
  undefined auStack_3e [58];
  
  piVar1 = (int *)param_1[0x10];
  iVar2 = *(int *)((int)piVar1 + 0x2e);
  iVar4 = (**(code **)(piVar1[7] + 0x80))(piVar1);
  if ((*param_1 & 1) == 0) {
    sVar5 = *(sword *)(iVar2 + 0x60);
    if (sVar5 == 0) {
      uVar6 = *(int *)(iVar2 + 0x90) - iVar4 * param_1[9];
      if (param_1[5] < uVar6) {
        uVar6 = param_1[5];
      }
      if ((int)uVar6 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aDoBioWriteCoun);
      }
      sVar5 = _nfswrite(piVar1,param_1[8],param_1[9] * iVar4,uVar6,*(undefined4 *)(iVar2 + 0x6c));
      *(sword *)(param_1 + 7) = sVar5;
      iVar7 = (int)sVar5;
      if ((*param_1 & 0x100) != 0) {
        *(sword *)(iVar2 + 0x60) = sVar5;
      }
    }
    else {
      *(sword *)(param_1 + 7) = sVar5;
      iVar7 = (int)sVar5;
    }
loc_402C46A:
    if (iVar7 == 0) goto loc_402C48A;
  }
  else {
    puVar3 = param_1 + 10;
    sVar5 = sub_402B07A(piVar1,param_1[8],iVar4 * param_1[9],param_1[5],puVar3,
                        *(undefined4 *)(iVar2 + 0x6c),auStack_3e);
    *(sword *)(param_1 + 7) = sVar5;
    iVar7 = (int)sVar5;
    if (iVar7 == 0) {
      uVar6 = *puVar3;
      if (uVar6 != 0) {
        _bzero(param_1[8] + (param_1[5] - uVar6),uVar6);
      }
      if ((*puVar3 != param_1[5]) || (iVar4 * param_1[9] < *(uint *)(iVar2 + 0x90)))
      goto loc_402C46A;
      iVar7 = -0x62;
    }
  }
  if (iVar7 != -0x62) {
    *param_1 = *param_1 | 4;
    iVar2 = *piVar1;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) == 0)) {
      *(int *)(iVar2 + 0x30) = iVar7;
    }
  }
loc_402C48A:
  _biodone(param_1);
  return iVar7;
}

