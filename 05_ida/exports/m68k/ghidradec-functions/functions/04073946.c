
int _np_open_common(byte param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined uStack_5;
  
  iVar1 = 0;
  iVar2 = 0;
  if ((param_1 == 0) && (*(sword *)((&_np_dinfo)[(sword)(word)param_1] + 0x1a) != 0)) {
    if (param_3 == 0) {
      if ((DAT_40c3b2a._0_4_ & 2) != 0) {
        return 0x10;
      }
      DAT_40c3b2a._0_4_ = DAT_40c3b2a._0_4_ & 0xfffffecf | 2;
    }
    _lock_write(0x40c3b36);
    if (((DAT_40c3b2a._32_4_ == 0) || (DAT_40c3b2a._32_4_ == 7)) &&
       (iVar1 = _np_power_on(_np_softc), iVar1 != 0)) {
      _lock_done(0x40c3b36);
    }
    else {
      _lock_done(0x40c3b36);
      if ((param_3 == 0) && (DAT_40c3b2a._32_4_ != 1)) {
        do {
          iVar1 = _np_serial_cmd(_np_softc,0x4c,&uStack_5);
          if (iVar1 == 0) {
            if (DAT_40c3b2a[0x3c] != '\x01') {
              _np_cleargpout(_np_softc,0x40);
              _np_nap(_hz * 2,_np_softc);
              DAT_40c3b2a[0x3c] = '\x01';
            }
            break;
          }
          if (iVar1 != 5) {
            if (iVar1 == 0x51) {
              return 0;
            }
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 4);
      }
    }
    if ((iVar1 != 0) && (param_3 == 0)) {
      DAT_40c3b2a._0_4_ = DAT_40c3b2a._0_4_ & 0xfffffffd;
    }
  }
  else {
    iVar1 = 6;
  }
  return iVar1;
}
