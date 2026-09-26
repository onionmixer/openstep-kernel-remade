
int _rtioctl(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 + 0x7fcf8df6U < 2) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      iVar1 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else {
      iVar1 = _rtrequest(param_1,param_2);
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}

