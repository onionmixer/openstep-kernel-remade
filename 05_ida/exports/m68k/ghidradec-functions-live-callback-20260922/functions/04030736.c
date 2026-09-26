
bool _xdrmbuf_setpos(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = param_2 + *(int *)(*(int *)(param_1 + 0x10) + 4) + *(int *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc);
  if (param_2 <= iVar1) {
    *(int *)(param_1 + 0xc) = param_2;
    *(int *)(param_1 + 0x14) = iVar1 - param_2;
  }
  return param_2 <= iVar1;
}

