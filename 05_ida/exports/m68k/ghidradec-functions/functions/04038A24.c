
undefined4 sub_4038A24(int param_1)

{
  int iVar1;
  int iStack_c;
  int *piStack_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  piStack_8 = (int *)(*(int *)(param_1 + 0x10) + 4);
loc_4038A42:
  iVar1 = sub_4038BEC(iVar1,param_1,1,&piStack_8,&iStack_c);
  if (iVar1 == 0) {
    return 0;
  }
  sub_4038E00(iStack_c);
  switch(iVar1) {
  case :
    *piStack_8 = *(int *)(iStack_c + 0x14);
    sub_4038E3A(iStack_c);
    return 0;
  case :
    if (*(int *)(iStack_c + 4) != *(int *)(param_1 + 4)) {
      sub_4038D6C(iStack_c,param_1);
      *(undefined4 *)(iStack_c + 0x14) = *(undefined4 *)(param_1 + 0x14);
      return 0;
    }
    break;
  case :
    *piStack_8 = *(int *)(iStack_c + 0x14);
    iVar1 = *(int *)(iStack_c + 0x14);
    sub_4038E3A(iStack_c);
    goto loc_4038A42;
  case :
    goto loc_4038af8;
  case :
    break;
  :
    return 0;
  }
  *(int *)(iStack_c + 4) = *(int *)(param_1 + 8) + 1;
  return 0;
loc_4038af8:
  *(int *)(iStack_c + 8) = *(int *)(param_1 + 4) + -1;
  piStack_8 = (int *)(iStack_c + 0x14);
  iVar1 = *piStack_8;
  goto loc_4038A42;
}
