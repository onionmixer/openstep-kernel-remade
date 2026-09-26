
void _stack_attach(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x28) = param_2;
  *(int *)(iVar1 + 0x38) = param_2 + 0xff4;
  *(int *)(iVar1 + 0x3c) = param_2 + 0xff4;
  *(code **)(iVar1 + 0x24) = __stack_attach;
  *(undefined4 *)(iVar1 + 0x28) = param_3;
  return;
}
