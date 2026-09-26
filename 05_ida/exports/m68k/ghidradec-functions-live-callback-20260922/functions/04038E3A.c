
void sub_4038E3A(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + 8);
  *piVar1 = *piVar1 + -1;
  _kfree(param_1,0x1c);
  return;
}

