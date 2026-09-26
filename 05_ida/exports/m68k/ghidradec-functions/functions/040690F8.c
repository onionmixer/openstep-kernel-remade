
int _SetCurBrightness(int param_1)

{
  sword sVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (0x3d < param_1) {
    param_1 = 0x3d;
  }
  sVar1 = sRam040c36ca;
  if (_evOpenCalled == 0) {
    _vidSetBrightness(param_1);
  }
  else {
    while (sVar1 = sVar1 + -1, sVar1 != -1) {
      _evdispatch(4,(int)sVar1,param_1);
    }
  }
  return param_1;
}
