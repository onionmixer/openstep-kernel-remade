
int _xdrmbuf_inline(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 <= *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_2;
    iVar1 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1 + param_2;
  }
  return iVar1;
}
