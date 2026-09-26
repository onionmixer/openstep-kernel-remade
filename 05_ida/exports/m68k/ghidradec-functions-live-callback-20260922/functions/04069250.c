
void _DoSoundKey(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = (uint)*(byte *)(_curMapping + 0x2ce);
  iVar2 = 1;
  if (uVar1 == param_1) {
    iVar2 = -1;
  }
  if ((param_3 & 0x100000) == 0) {
    param_3 = param_3 & 0x60;
    if (param_3 == 0x20) {
      iVar2 = iVar2 + _vol_l;
      uVar3 = 1;
    }
    else {
      if ((param_3 < 0x21) || (param_3 != 0x40)) {
        _SetAttenuation(1,iVar2 + _vol_l);
      }
      iVar2 = iVar2 + _vol_r;
      uVar3 = 2;
    }
  }
  else {
    if ((param_3 & 0x80000) == 0) {
      if (uVar1 == param_1) {
        _gpflags = _gpflags ^ 8;
      }
      else {
        _gpflags = _gpflags ^ 0x10;
      }
      goto loc_4069352;
    }
    iVar2 = _vol_l;
    if (uVar1 == param_1) {
      if (_vol_r <= _vol_l) {
        iVar2 = _vol_r;
      }
      uVar3 = 3;
    }
    else {
      if (_vol_l <= _vol_r) {
        iVar2 = _vol_r;
      }
      uVar3 = 3;
    }
  }
  _SetAttenuation(uVar3,iVar2);
loc_4069352:
  _snd_device_vol_set();
  return;
}

