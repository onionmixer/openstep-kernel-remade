
int _hzto(int *param_1)

{
  int iVar1;
  int iStack_c;
  int iStack_8;
  
  _getthetime(&iStack_c);
  iStack_c = *param_1 - iStack_c;
  if (iStack_c < 0x20c0b4) {
    iVar1 = ((param_1[1] - iStack_8) / 1000 + iStack_c * 1000) / (_tick / 1000);
  }
  else {
    iVar1 = 0x7fffffff;
    if (iStack_c <= 0x7fffffff / _hz) {
      iVar1 = _hz * iStack_c;
    }
  }
  return iVar1;
}
