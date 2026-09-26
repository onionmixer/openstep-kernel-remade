
void sub_407BC86(int *param_1,undefined param_2,undefined param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 0x10) + 8);
  *(undefined *)((int)param_1 + 0x221) = param_2;
  *(undefined *)(param_1 + 0x88) = param_3;
  *(undefined *)((int)param_1 + 0x21f) = 1;
  *(undefined *)(iVar1 + 3) = 0x1a;
  return;
}

