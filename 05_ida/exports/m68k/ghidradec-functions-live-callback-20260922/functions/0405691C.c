
int sub_405691C(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_2 + 0x4b4);
  iVar4 = -200;
  if (param_2 == 0) {
    return -0x12f;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == *(int *)(param_2 + 0x4ac)) {
    iVar4 = -0x12f;
  }
  else {
    if (iVar1 != *(int *)(param_2 + 0x4b0)) {
      iVar2 = 0;
      iVar3 = param_2;
      do {
        if (iVar1 == *(int *)(iVar3 + 0x18c)) break;
        iVar3 = iVar3 + 0x10;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x32);
      if (iVar2 == 0x32) goto loc_4056990;
      *(int *)(param_2 + 0x4b0) = iVar1;
      *(int *)(param_2 + 0x4b4) = iVar2;
    }
    iVar4 = sub_40568A0(param_1,param_2 + iVar2 * 0x10 + 0x18c);
  }
loc_4056990:
  if (iVar4 == -200) {
    *(undefined4 *)(param_2 + 0x4ac) = *(undefined4 *)(param_1 + 0xc);
    iVar4 = -0x12f;
  }
  return iVar4;
}

