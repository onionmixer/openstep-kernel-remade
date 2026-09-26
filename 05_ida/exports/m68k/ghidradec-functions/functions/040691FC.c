
void _SetAttenuation(uint param_1,int param_2)

{
  if ((param_1 & 1) != 0) {
    _vol_l = param_2;
    if (0x2b < param_2) {
      _vol_l = 0x2b;
    }
    if (_vol_l < 0) {
      _vol_l = 0;
    }
  }
  if ((param_1 & 2) != 0) {
    if (0x2b < param_2) {
      param_2 = 0x2b;
    }
    _vol_r = param_2;
    if (param_2 < 0) {
      _vol_r = 0;
    }
  }
  return;
}
