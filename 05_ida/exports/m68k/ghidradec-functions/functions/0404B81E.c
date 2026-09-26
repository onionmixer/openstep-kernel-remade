
int _nextsect(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _firstsect(param_1);
  if ((uint)((param_2 - iVar1) * -0xf0f0f0f >> 2) < *(int *)(param_1 + 0x30) - 1U) {
    param_2 = param_2 + 0x44;
  }
  else {
    param_2 = 0;
  }
  return param_2;
}
