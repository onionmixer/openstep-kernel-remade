
void _snd_device_init(int param_1)

{
  bool bVar1;
  undefined2 uStack_24;
  undefined uStack_22;
  byte bStack_21;
  
  if ((param_1 == 0) && (_vol_r == 0xffffffff)) {
    _nvram_check(&uStack_24);
    _vol_r = (CONCAT31(CONCAT21(uStack_24,uStack_22),bStack_21) & 0x3ffffff) >> 0x14;
    _vol_l = (CONCAT11(uStack_22,bStack_21) & 0x3ff) >> 4;
    dword_40B5088 = 0xffffffff;
    dword_40B508C = 0xffffffff;
    _gpflags = 0;
    bVar1 = (bStack_21 & 8) == 0;
    if (!bVar1) {
      _gpflags = 0x10;
    }
    dword_40B5080 = (uint)bVar1;
    bVar1 = (bStack_21 & 4) == 0;
    if (!bVar1) {
      _gpflags = _gpflags | 8;
    }
    dword_40B5084 = (uint)bVar1;
    sub_40800CC();
  }
  return;
}
