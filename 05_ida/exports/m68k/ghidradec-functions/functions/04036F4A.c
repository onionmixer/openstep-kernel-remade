
void sub_4036F4A(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = sub_4036D9E(param_1,param_2 + -1);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    *(undefined4 *)(param_1[1] + 0xc) = *param_1;
    param_1[1] = iVar1;
    *param_1 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  param_1[2] = param_2;
  return;
}
