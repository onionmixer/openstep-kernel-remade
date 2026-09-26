
int _nullmodem(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xffffffef;
    if (-1 < *(sword *)(iVar1 + 0x12)) {
      param_2 = 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x10;
  }
  return param_2;
}

