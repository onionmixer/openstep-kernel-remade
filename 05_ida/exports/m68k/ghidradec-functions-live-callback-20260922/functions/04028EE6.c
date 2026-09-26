
uint _setdirmode(int param_1,uint param_2)

{
  param_2 = param_2 & 0xfffffbff;
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x80) & 4) != 0) {
    param_2 = param_2 | 0x400;
  }
  return param_2;
}

