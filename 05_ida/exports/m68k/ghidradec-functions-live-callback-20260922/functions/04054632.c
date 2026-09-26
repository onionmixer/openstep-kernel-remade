
undefined4
_calloutEntryDispatchWithArgumentDelayed(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 extraout_D0u;
  uint in_D0;
  uint uVar6;
  int *piVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  uVar6 = in_D0 & 0xffff0000;
  uVar5 = (undefined2)(in_D0 >> 0x10);
  cVar8 = '\0';
  cVar11 = '\0';
  cVar9 = param_1[7] < 0;
  cVar10 = '\0';
  bVar12 = 0;
  if (param_1[7] == 0) {
    param_1[3] = param_2;
    param_1[5] = param_3;
    param_1[6] = param_4;
    for (piVar7 = dword_40B4DC8; uVar5 = (undefined2)(uVar6 >> 0x10),
        (int **)piVar7 != &dword_40B4DC8; piVar7 = (int *)*piVar7) {
      uVar1 = param_1[5];
      uVar2 = param_1[6];
      uVar3 = piVar7[5];
      uVar4 = piVar7[6];
      uVar6 = uVar1 - ((uVar2 < uVar4) + uVar3);
      uVar5 = (undefined2)(uVar6 >> 0x10);
      if (uVar1 < uVar3 || uVar2 < uVar4 && uVar1 == uVar3) break;
      if (uVar1 == (uVar2 < uVar4) + uVar3 && uVar2 == uVar4) goto loc_405469A;
    }
    piVar7 = (int *)piVar7[1];
loc_405469A:
    *param_1 = *piVar7;
    param_1[1] = (int)piVar7;
    *(int **)(*piVar7 + 4) = param_1;
    *piVar7 = (int)param_1;
    param_1[7] = 2;
    cVar8 = param_1 < dword_40B4DC8;
    cVar11 = SBORROW4((int)param_1,(int)dword_40B4DC8);
    cVar9 = (int)param_1 - (int)dword_40B4DC8 < 0;
    cVar10 = '\0';
    bVar12 = cVar8;
    if (param_1 == dword_40B4DC8) {
      cVar9 = (int)param_1 < 0;
      cVar10 = param_1 == (int *)0x0;
      cVar11 = '\0';
      bVar12 = 0;
      sub_4053F9C(param_1);
      uVar5 = extraout_D0u;
    }
  }
  return CONCAT22(uVar5,(word)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12));
}

