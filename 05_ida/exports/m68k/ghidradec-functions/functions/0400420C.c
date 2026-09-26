
undefined4 _fgetown(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(sword *)(param_1 + 0xc) == 2) {
    *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x16) + 0x54);
    uVar1 = 0;
  }
  else {
    uVar1 = _fioctl(param_1,0x40047477,param_2);
    *param_2 = -*param_2;
  }
  return uVar1;
}
