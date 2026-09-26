
undefined4 sub_4038B30(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = sub_4038B8C(param_1);
  if (iVar1 == 0) {
    *param_2 = 3;
  }
  else {
    *param_2 = *(undefined2 *)(iVar1 + 2);
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(iVar1 + 4);
    if (*(int *)(iVar1 + 8) == -1) {
      *(undefined4 *)(param_2 + 4) = 0;
    }
    else {
      *(int *)(param_2 + 4) = (*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4)) + 1;
    }
    *(undefined4 *)(param_2 + 6) = **(undefined4 **)(iVar1 + 0xc);
  }
  return 0;
}
