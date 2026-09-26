
void _calloutDispatchDelayed(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar5 = dword_40B4DB8;
  if (dword_40AFF2C != 0) {
    if ((int **)dword_40B4DB8 == &dword_40B4DB8) {
                    /* WARNING: Subroutine does not return */
      _panic(aInternalentrya);
    }
    *(int ***)(*dword_40B4DB8 + 4) = &dword_40B4DB8;
    piVar6 = dword_40B4DB8 + 2;
    dword_40B4DB8 = (int *)*dword_40B4DB8;
    *piVar6 = param_1;
    piVar5[3] = param_2;
    piVar5[4] = 0;
    piVar5[5] = param_3;
    piVar5[6] = param_4;
    for (piVar6 = dword_40B4DC8; (int **)piVar6 != &dword_40B4DC8; piVar6 = (int *)*piVar6) {
      uVar1 = piVar5[5];
      uVar2 = piVar5[6];
      uVar3 = piVar6[5];
      uVar4 = piVar6[6];
      if (uVar1 < uVar3 || uVar2 < uVar4 && uVar1 == uVar3) break;
      if (uVar1 == (uVar2 < uVar4) + uVar3 && uVar2 == uVar4) goto loc_4054390;
    }
    piVar6 = (int *)piVar6[1];
loc_4054390:
    *piVar5 = *piVar6;
    piVar5[1] = (int)piVar6;
    *(int **)(*piVar6 + 4) = piVar5;
    *piVar6 = (int)piVar5;
    piVar5[7] = 2;
    if (piVar5 == dword_40B4DC8) {
      sub_4053F9C(piVar5);
    }
  }
  return;
}
