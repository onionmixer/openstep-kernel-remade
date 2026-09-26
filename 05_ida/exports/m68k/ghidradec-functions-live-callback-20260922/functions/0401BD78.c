
void _if_down(int param_1)

{
  int iVar1;
  
  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xffbe;
  for (iVar1 = *(int *)(param_1 + 0x16); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
    _pfctlinput(0,iVar1);
  }
  _if_qflush(param_1 + 0x1a);
  return;
}

