
uint _nextc(int *param_1,int param_2)

{
  uint uVar1;
  
  if ((*param_1 == 0) || (uVar1 = param_2 + 1, uVar1 == param_1[2])) {
    uVar1 = 0;
  }
  else if ((uVar1 & 0x3f) == 0) {
    uVar1 = *(int *)(param_2 + -0x3f) + 0xc;
  }
  return uVar1;
}
