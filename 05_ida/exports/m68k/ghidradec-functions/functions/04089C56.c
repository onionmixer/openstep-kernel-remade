
void sub_4089C56(void)

{
  uint uVar1;
  undefined uStack_24;
  uint uStack_23;
  
  if (_evOpenCalled == 0) {
    _nvram_check(&uStack_24);
    uVar1 = (uStack_23 & 0xfffffff) >> 0x16;
  }
  else if ((_autoDimmed == 0) ||
          (uVar1 = _dimmedBrightness, (int)_curBright <= (int)_dimmedBrightness)) {
    uVar1 = _curBright;
  }
  _vidSetBrightness(uVar1);
  return;
}
