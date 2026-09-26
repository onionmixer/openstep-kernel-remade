
undefined4 sub_403878C(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iStack_c;
  int *piStack_8;
  
  uVar6 = 0x23;
  if (*(sword *)(param_1 + 2) == 2) {
    uVar6 = 0x28;
  }
  while (iVar3 = sub_4038B8C(param_1), iVar3 != 0) {
    if ((*(byte *)(param_1 + 1) & 1) != 0) {
      sub_4038E3A(param_1);
      return 0xb;
    }
    iVar4 = *(int *)(iVar3 + 0xc);
    iVar5 = 0;
    while ((*(int *)(iVar4 + 0x12) != 0 && (iVar5 < 0x32))) {
      iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x12) + 0x14) + 0xc);
      iVar5 = iVar5 + 1;
      if (iVar4 == *(int *)(param_1 + 0xc)) {
        sub_4038E3A(param_1);
        return 0x4e;
      }
    }
    *(int *)(param_1 + 0x14) = iVar3;
    sub_4038D12(iVar3,param_1);
    *(int *)(*(int *)(param_1 + 0xc) + 0x12) = param_1;
    iVar4 = _sleep(param_1,uVar6 | 0x100);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x12) = 0;
    if (iVar4 != 0) {
      sub_4038D40(iVar3,param_1);
      sub_4038E3A(param_1);
      return 4;
    }
  }
  piStack_8 = (int *)(*(int *)(param_1 + 0x10) + 4);
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  bVar2 = true;
loc_4038866:
  iVar3 = sub_4038BEC(uVar7,param_1,1,&piStack_8,&iStack_c);
  if (iVar3 != 0) {
    uVar7 = *(undefined4 *)(iStack_c + 0x14);
  }
  switch(iVar3) {
  case :
    if (!bVar2) {
      return 0;
    }
    *piStack_8 = param_1;
    *(int *)(param_1 + 0x14) = iStack_c;
    return 0;
  case :
    if ((*(sword *)(param_1 + 2) == 1) && (*(sword *)(iStack_c + 2) == 2)) {
      sub_4038E00(iStack_c);
    }
    *(undefined2 *)(iStack_c + 2) = *(undefined2 *)(param_1 + 2);
    break;
  case :
    if (*(sword *)(param_1 + 2) != *(sword *)(iStack_c + 2)) {
      if (*(int *)(iStack_c + 4) == *(int *)(param_1 + 4)) {
        *piStack_8 = param_1;
        *(int *)(param_1 + 0x14) = iStack_c;
        *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
      }
      else {
        sub_4038D6C(iStack_c,param_1);
      }
      goto loc_4038A12;
    }
    break;
  case :
    if ((*(sword *)(param_1 + 2) == 1) && (*(sword *)(iStack_c + 2) == 2)) {
      sub_4038E00(iStack_c);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iStack_c + 0x18);
      sub_4038D12(param_1,uVar1);
    }
    if (bVar2) {
      *piStack_8 = param_1;
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iStack_c + 0x14);
      piStack_8 = (int *)(param_1 + 0x14);
      bVar2 = false;
    }
    else {
      *piStack_8 = *(int *)(iStack_c + 0x14);
    }
    sub_4038E3A(iStack_c);
    goto loc_4038866;
  case :
    goto loc_40389c2;
  case :
    if (bVar2) {
      *piStack_8 = param_1;
      *(int *)(param_1 + 0x14) = iStack_c;
    }
    *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
loc_4038A12:
    sub_4038E00(iStack_c);
    return 0;
  :
    return 0;
  }
  sub_4038E3A(param_1);
  return 0;
loc_40389c2:
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iStack_c + 0x14);
  *(int *)(iStack_c + 0x14) = param_1;
  *(int *)(iStack_c + 8) = *(int *)(param_1 + 4) + -1;
  piStack_8 = (int *)(param_1 + 0x14);
  sub_4038E00(iStack_c);
  bVar2 = false;
  goto loc_4038866;
}
