
undefined4 _soreserve(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _sbreserve(param_1 + 0x38,param_2);
  if (iVar1 != 0) {
    iVar1 = _sbreserve(param_1 + 0x22,param_3);
    if (iVar1 != 0) {
      return 0;
    }
    _sbrelease(param_1 + 0x38);
  }
  return 0x37;
}

