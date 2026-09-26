
int _np_serial_cmd(int param_1,byte param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  word wVar4;
  int iVar5;
  uint uVar6;
  sword sVar7;
  int iVar8;
  undefined *puVar9;
  byte bStack_5;
  
  iVar8 = 3;
  _lock_write(param_1 + 0x10a);
loc_4072A46:
  do {
    iVar2 = _np_getgpi(param_1,&bStack_5);
    while( true ) {
      if (iVar2 == 0) goto loc_4072C5E;
      if ((bStack_5 & 2) == 0) break;
      iVar2 = 3;
      do {
        iVar5 = 0;
        do {
          _delay(0x32);
          _np_setgpout(param_1,4);
          _delay(0x32);
          _np_cleargpout(param_1,4);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 8);
        iVar5 = _np_getgpi(param_1,&bStack_5);
        if (iVar5 == 0) goto loc_4072C5E;
      } while (((bStack_5 & 0x12) == 0x12) && (iVar2 = iVar2 + -1, iVar2 != 0));
    }
    _np_setgpout(param_1,1);
    _delay(200);
    uVar6 = 7;
    do {
      _delay(0x32);
      if (((int)(uint)param_2 >> (uVar6 & 0x3f) & 1U) == 0) {
        bVar3 = *(byte *)(param_1 + 0x11a) & 0xfd;
      }
      else {
        bVar3 = *(byte *)(param_1 + 0x11a) | 2;
      }
      *(byte *)(param_1 + 0x11a) = bVar3;
      _np_setgpout(param_1,4);
      _delay(0x32);
      _np_cleargpout(param_1,4);
      wVar4 = (word)(uVar6 >> 0x10);
      sVar7 = (sword)uVar6 + -1;
      uVar6 = CONCAT22(wVar4,sVar7);
    } while ((sVar7 != -1) || (uVar6 = (uint)wVar4 * 0x10000 - 1, wVar4 != 0));
    _np_setmask(param_1,2);
    _delay(1000);
    _np_cleargpout(param_1,3);
    iVar2 = _np_getgpi(param_1,(byte *)(param_1 + 0x11b));
    if (iVar2 == 0) {
      _np_clearmask(param_1,2);
loc_4072E6E:
      iVar8 = 5;
      goto loc_4072ED0;
    }
    *(byte *)(param_1 + 0x104) = *(byte *)(param_1 + 0x104) & 0xfe;
    iVar2 = _hz;
    if (_hz < 0) {
      iVar2 = _hz + 1;
    }
    _timeout(_np_serial_timeout,param_1,iVar2 >> 1);
    if (((*(byte *)(param_1 + 0x104) & 1) == 0) && ((*(byte *)(param_1 + 0x11b) & 2) == 0)) {
      while ((*(byte *)(param_1 + 0x11b) & 0x10) != 0) {
        iVar2 = _hz;
        if (_hz < 0) {
          iVar2 = _hz + 3;
        }
        _np_gpinwait(param_1,iVar2 >> 2);
        if (((*(byte *)(param_1 + 0x104) & 1) != 0) || ((*(byte *)(param_1 + 0x11b) & 2) != 0))
        break;
      }
    }
    _untimeout(_np_serial_timeout,param_1);
    _np_clearmask(param_1,2);
    if ((*(byte *)(param_1 + 0x104) & 1) != 0) goto loc_4072C5E;
    if ((*(byte *)(param_1 + 0x11b) & 0x10) == 0) {
      iVar8 = 0x51;
      goto loc_4072ED0;
    }
    if ((*(byte *)(param_1 + 0x11b) & 2) == 0) goto loc_4072C5E;
    bVar3 = 0;
    bVar1 = false;
    iVar2 = 0;
    do {
      _delay(0x32);
      _np_setgpout(param_1,4);
      _delay(0x32);
      _np_cleargpout(param_1,4);
      iVar5 = _np_getgpi(param_1,&bStack_5);
      if (iVar5 == 0) goto loc_4072C5E;
      bVar3 = bVar3 << 1;
      if ((bStack_5 & 1) != 0) {
        bVar3 = bVar3 | 1;
        bVar1 = (bool)(bVar1 ^ 1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    _np_setmask(param_1,2);
    iVar2 = _np_getgpi(param_1,(byte *)(param_1 + 0x11b));
    if (iVar2 == 0) {
      _np_clearmask(param_1,2);
      goto loc_4072E6E;
    }
    _timeout(_np_serial_timeout,param_1,_hz / 0x14 + 1);
    *(byte *)(param_1 + 0x104) = *(byte *)(param_1 + 0x104) & 0xfe;
    if (((*(byte *)(param_1 + 0x104) & 1) == 0) && ((*(byte *)(param_1 + 0x11b) & 2) != 0)) {
      while ((*(byte *)(param_1 + 0x11b) & 0x10) != 0) {
        iVar2 = _hz / 0x14 + 1;
        if (iVar2 < 0) {
          iVar2 = _hz / 0x14 + 2;
        }
        _np_gpinwait(param_1,(iVar2 >> 1) + 1);
        if (((*(byte *)(param_1 + 0x104) & 1) != 0) || ((*(byte *)(param_1 + 0x11b) & 2) == 0))
        break;
      }
    }
    _untimeout(_np_serial_timeout,param_1);
    _np_clearmask(param_1,2);
    sVar7 = (sword)iVar8;
    wVar4 = (word)((uint)iVar8 >> 0x10);
    if ((*(byte *)(param_1 + 0x104) & 1) != 0) {
      iVar8 = CONCAT22(wVar4,sVar7 + -1);
      if (((sword)(sVar7 + -1) == -1) && (iVar8 = (uint)wVar4 * 0x10000 + -1, wVar4 == 0))
      goto loc_4072C5E;
      goto loc_4072A46;
    }
    if ((*(byte *)(param_1 + 0x11b) & 0x10) == 0) {
      iVar8 = 0x51;
      goto loc_4072ED0;
    }
    if ((*(byte *)(param_1 + 0x11b) & 2) != 0) goto loc_4072C5E;
    if (bVar1) {
      if (-1 < (char)bVar3) {
        *param_3 = bVar3;
        iVar8 = 0;
        goto loc_4072ED0;
      }
      iVar8 = CONCAT22(wVar4,sVar7 + -1);
      if (((sword)(sVar7 + -1) == -1) && (iVar8 = (uint)wVar4 * 0x10000 + -1, wVar4 == 0)) {
        if ((bVar3 & 0x40) == 0) {
          puVar9 = aNpDSerialComma_0;
        }
        else {
          puVar9 = aNpDSerialComma;
        }
        _printf(puVar9,(param_1 + -0x40c3a24) * 0x2b2e43db >> 2);
loc_4072C5E:
        iVar8 = 5;
loc_4072ED0:
        if (iVar8 == 5) {
          _np_setstate(param_1,1);
        }
        _lock_done(param_1 + 0x10a);
        return iVar8;
      }
    }
    else {
      iVar8 = CONCAT22(wVar4,sVar7 + -1);
      if (((sword)(sVar7 + -1) == -1) && (iVar8 = (uint)wVar4 * 0x10000 + -1, wVar4 == 0)) {
        _printf(aNpDSerialRetur,(param_1 + -0x40c3a24) * 0x2b2e43db >> 2);
        goto loc_4072E6E;
      }
    }
  } while( true );
}

