
undefined4 _np_init_printer(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined uStack_5;
  
  uVar1 = *(uint *)(param_1 + 0x126);
  if (uVar1 == 1) {
    iVar2 = _np_getgpi(param_1,param_1 + 0x11b);
    if (iVar2 != 0) {
      do {
        *(undefined *)(param_1 + 0x11a) = 0;
        _np_setgpout(param_1,0);
        *(undefined *)(param_1 + 0x11c) = 0;
        _np_setmask(param_1,0);
        iVar2 = _hz;
        if (_hz < 0) {
          iVar2 = _hz + 1;
        }
        _np_nap(iVar2 >> 1,param_1);
        _np_setmask(param_1,0x10);
        _timeout(_np_serial_timeout,param_1,_hz * 2);
        *(byte *)(param_1 + 0x104) = *(byte *)(param_1 + 0x104) & 0xfe;
        while (((*(byte *)(param_1 + 0x11b) & 0x10) == 0 && ((*(byte *)(param_1 + 0x104) & 1) == 0))
              ) {
          _np_gpinwait(param_1,_hz);
        }
        _untimeout(_np_serial_timeout,param_1);
        _np_clearmask(param_1,0x10);
        if ((*(byte *)(param_1 + 0x104) & 1) != 0) break;
        _np_nap((_hz * 0x19) / 10,param_1);
        iVar2 = _np_getgpi(param_1,(byte *)(param_1 + 0x11b));
        if ((iVar2 == 0) || ((*(byte *)(param_1 + 0x11b) & 0x10) == 0)) break;
        _np_setgpout(param_1,8);
        _np_nap((_hz * 0x19) / 10,param_1);
        iVar2 = _np_serial_cmd(param_1,0x40,&uStack_5);
        if ((iVar2 == 0) &&
           ((_np_setmask(param_1,0x18), (*(uint *)(param_1 + 0x106) & 0x10) == 0 ||
            (iVar2 = _np_serial_cmd(param_1,0x4f,&uStack_5), iVar2 == 0)))) {
          *(uint *)(param_1 + 0x106) = *(uint *)(param_1 + 0x106) & 0xffffffdf;
          *(undefined *)(param_1 + 0x142) = 1;
          iVar2 = _np_setstate_rdyerr(param_1);
          if (iVar2 == 0) {
            return 0;
          }
          break;
        }
      } while (iVar2 == 0x51);
    }
    _lock_write(param_1 + 0x112);
    _np_power_off(param_1);
    uVar3 = _lock_done(param_1 + 0x112);
  }
  else {
    uVar3 = CONCAT22((sword)(uVar1 >> 0x10),
                     (word)(byte)((1 < uVar1) << 4 | ((int)(1 - uVar1) < 0) << 3 |
                                  SBORROW4(1,uVar1) << 1 | 1 < uVar1));
  }
  return uVar3;
}
