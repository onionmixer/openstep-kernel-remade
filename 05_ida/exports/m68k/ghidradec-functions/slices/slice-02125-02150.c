/* GHIDRADEC_FUNCTION index=2125 start=0x407288e */

byte _np_setgpout(int *param_1,byte param_2)

{
  int iVar1;
  uint in_D0;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  *(byte *)((int)param_1 + 0x11a) = param_2 | *(byte *)((int)param_1 + 0x11a);
  cVar2 = (in_D0 & 0x100) != 0;
  iVar1 = *param_1;
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _np_send(iVar1,0xc4,(uint)(byte)~*(byte *)((int)param_1 + 0x11a) << 0x18);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=2126 start=0x40728d8 */

byte _np_cleargpout(int *param_1,byte param_2)

{
  int iVar1;
  uint in_D0;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  *(byte *)((int)param_1 + 0x11a) = ~param_2 & *(byte *)((int)param_1 + 0x11a);
  cVar2 = (in_D0 & 0x100) != 0;
  iVar1 = *param_1;
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _np_send(iVar1,0xc4,(uint)(byte)~*(byte *)((int)param_1 + 0x11a) << 0x18);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=2127 start=0x4072924 */

undefined4 _np_getgpi(undefined4 *param_1,byte *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  sword sVar6;
  int iVar7;
  byte abStack_c [4];
  int iStack_8;
  
  uVar1 = *param_1;
  bVar2 = false;
  iVar7 = 2;
  do {
    uVar5 = 5;
    while( true ) {
      do {
        _np_send(uVar1,4,0);
        iVar4 = 0;
        do {
          iVar3 = _np_recv(uVar1,&iStack_8,abStack_c);
          if ((iVar3 != 0) && (iStack_8 == 0xc4)) {
            bVar2 = true;
            goto loc_407299C;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x28);
      } while ((!bVar2) &&
              (sVar6 = (sword)uVar5 + -1, uVar5 = CONCAT22((sword)(uVar5 >> 0x10),sVar6),
              sVar6 != -1));
      if (bVar2) break;
      uVar5 = (uVar5 & 0xffff0000) - 1;
      if ((int)uVar5 < 0) {
        return 0;
      }
    }
loc_407299C:
    *param_2 = ~abStack_c[0] & 0x3f;
    if ((~abStack_c[0] & 0x10) != 0) {
      return 1;
    }
    if ((*(int *)((int)param_1 + 0x126) == 1) || (iVar7 = iVar7 + -1, iVar7 < 1)) {
      if (*(int *)((int)param_1 + 0x126) != 1) {
        if (*(int *)((int)param_1 + 0x126) == 4) {
          _np_printing_shutdown(param_1);
        }
        _np_setstate(param_1,1);
      }
      return 1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2128 start=0x40729fa */

void _np_serial_timeout(int param_1)

{
  *(byte *)(param_1 + 0x104) = *(byte *)(param_1 + 0x104) | 1;
  _thread_wakeup_prim(param_1 + 0x11b,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2129 start=0x4072a20 */

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
/* GHIDRADEC_FUNCTION index=2130 start=0x4072efa */

byte _np_setstate(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  *(uint *)(param_1 + 0x126) = param_2;
  cVar4 = 1 < param_2;
  if (param_2 == 1) {
    cVar1 = param_1 < 0;
    cVar2 = param_1 == 0;
    cVar3 = '\0';
    bVar5 = 0;
    _callout_dispatch(4,_np_init_printer,param_1);
    goto loc_4072FB6;
  }
  if (param_2 != 0) {
    cVar4 = 2 < param_2;
    if (param_2 == 2) {
      cVar1 = *(int *)(param_1 + 0x11e) < 0;
      cVar3 = '\0';
      cVar2 = '\x01';
      bVar5 = 0;
      if (*(int *)(param_1 + 0x11e) != 0) {
        _selwakeup(*(undefined4 *)(param_1 + 0x11e),*(uint *)(param_1 + 0x106) & 0x40);
        *(uint *)(param_1 + 0x106) = *(uint *)(param_1 + 0x106) & 0xffffffbf;
        _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x11e));
        *(undefined4 *)(param_1 + 0x11e) = 0;
        cVar1 = '\0';
        cVar2 = '\x01';
        cVar3 = '\0';
        bVar5 = 0;
      }
      goto loc_4072FB6;
    }
    cVar4 = 6 < param_2;
    cVar3 = SBORROW4(6,param_2);
    cVar1 = (int)(6 - param_2) < 0;
    cVar2 = param_2 == 6;
    bVar5 = cVar4;
    if (!(bool)cVar2) goto loc_4072FB6;
  }
  cVar1 = *(int *)(param_1 + 0x122) < 0;
  cVar3 = '\0';
  cVar2 = '\x01';
  bVar5 = 0;
  if (*(int *)(param_1 + 0x122) != 0) {
    _selwakeup(*(undefined4 *)(param_1 + 0x122),*(uint *)(param_1 + 0x106) & 0x80);
    *(uint *)(param_1 + 0x106) = *(uint *)(param_1 + 0x106) & 0xffffff7f;
    _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x11e));
    *(undefined4 *)(param_1 + 0x122) = 0;
    cVar1 = '\0';
    cVar2 = '\x01';
    cVar3 = '\0';
    bVar5 = 0;
  }
loc_4072FB6:
  _wakeup(param_1 + 0x126);
  return cVar4 << 4 | cVar1 << 3 | cVar2 << 2 | cVar3 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=2131 start=0x4072fce */

undefined4 _np_setstate_rdyerr(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _np_getgpi(param_1,(byte *)(param_1 + 0x11b));
  if (iVar1 == 0) {
    _np_power_off(param_1);
    uVar2 = 5;
  }
  else {
    if ((*(byte *)(param_1 + 0x11b) & 8) == 0) {
      uVar2 = 6;
    }
    else {
      uVar2 = 2;
    }
    _np_setstate(param_1,uVar2);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2132 start=0x407302e */

undefined4 _np_power_on(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar1 = *param_1;
  if (*(int *)((int)param_1 + 0x126) == 7) {
    do {
      _sleep((int *)((int)param_1 + 0x126),0x14);
    } while (*(int *)((int)param_1 + 0x126) == 7);
  }
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xfd;
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) | 2;
  *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 0x80;
  _np_nap(_hz * 3,param_1);
  _np_send(iVar1,0xff,0xffffffff);
  _delay(10);
  do {
    iVar2 = _np_recv(iVar1,&iStack_8,auStack_c);
  } while (iVar2 != 0);
  _np_send(iVar1,4,0);
  iVar2 = 0x28;
  do {
    iVar3 = _np_recv(iVar1,&iStack_8,auStack_c);
    if ((iVar3 != 0) && (iStack_8 == 0xc4)) break;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  if (iVar2 < 1) {
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0x7f;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xfd;
    uVar4 = 0x13;
  }
  else {
    param_1[0x3f] = 0;
    _install_scanned_intr(0xb32,_np_dev_intr,param_1);
    _np_setstate(param_1,1);
    uVar4 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2133 start=0x4073178 */

byte _np_power_off(int *param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar5 = 7 < *(uint *)((int)param_1 + 0x126);
  if (*(uint *)((int)param_1 + 0x126) == 7) {
    _uninstall_scanned_intr(0xb32);
    *(byte *)(*param_1 + 1) = *(byte *)(*param_1 + 1) & 0x7f;
    *(byte *)(*param_1 + 2) = *(byte *)(*param_1 + 2) & 0xfd;
    _np_setstate(param_1,0);
    uVar1 = *(uint *)((int)param_1 + 0x106) & 0xfffffffe;
    *(uint *)((int)param_1 + 0x106) = uVar1;
    cVar2 = (int)uVar1 < 0;
    cVar3 = uVar1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
  }
  else {
    cVar2 = *(int *)((int)param_1 + 0x126) < 0;
    cVar3 = *(int *)((int)param_1 + 0x126) == 0;
    cVar4 = '\0';
    bVar6 = 0;
    if (!(bool)cVar3) {
      _np_setstate(param_1,7);
      cVar2 = (int)param_1 < 0;
      cVar3 = param_1 == (int *)0x0;
      cVar4 = '\0';
      bVar6 = 0;
      _timeout(_np_power_off,param_1,_hz * 5);
    }
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=2134 start=0x4073210 */

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
/* GHIDRADEC_FUNCTION index=2135 start=0x4073448 */

uint _np_printing_timeout(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar5 = 4 < *(uint *)(param_1 + 0x126);
  if (*(uint *)(param_1 + 0x126) == 4) {
    _np_printing_shutdown(param_1);
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
    _np_setstate(param_1,9);
    uVar1 = (uint)(byte)(cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6);
  }
  else {
    uVar1 = _printf(aNpDSpuriousPri,(param_1 + -0x40c3a24) * 0x2b2e43db >> 2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2136 start=0x40734b2 */

byte _np_printing_shutdown(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  pbVar1 = (byte *)*param_1;
  uVar2 = *(uint *)((int)param_1 + 0x126);
  if (uVar2 == 4) {
    _untimeout(_np_printing_timeout,param_1);
    cVar3 = '\0';
    _np_send(pbVar1,7,0);
    _dma_abort(param_1 + 1);
    *pbVar1 = *pbVar1 & 0x7f;
    cVar4 = (int)param_1 < 0;
    cVar5 = param_1 == (undefined4 *)0x0;
    cVar6 = '\0';
    bVar7 = 0;
    _np_setstate(param_1,5);
    bVar7 = cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
  }
  else {
    bVar7 = (4 < uVar2) << 4 | ((int)(4 - uVar2) < 0) << 3 | SBORROW4(4,uVar2) << 1 | 4 < uVar2;
  }
  return bVar7;
}
/* GHIDRADEC_FUNCTION index=2137 start=0x4073532 */

undefined4 _np_startdata(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = *param_1;
  uVar2 = *(uint *)((int)param_1 + 0x126);
  if (uVar2 == 3) {
    _np_cleargpout(param_1,0x30);
    iVar4 = param_1[0x3f];
    _np_send(uVar3,199,(int)**(char **)(iVar4 + 4));
    if (_dma_chip == 0x139) {
      piVar1 = (int *)(iVar4 + 4);
      *piVar1 = *piVar1 + 4;
    }
    _dma_start(param_1 + 1,param_1[0x3f],0);
    _lpr_csr_or(0x20);
    _lpr_csr_or(0x80);
    _lpr_csr_or(0x20);
    if (_dma_chip != 0x139) {
      iVar4 = 0;
      do {
        _lpr_csr_or(1);
        _delay(1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
    _np_setstate(param_1,4);
    if (*(char *)((int)param_1 + 0x142) == '\0') {
      uVar5 = 0x3f;
    }
    else {
      uVar5 = 0x2f;
    }
    _np_send(uVar3,uVar5,0);
    uVar3 = _timeout(_np_printing_timeout,param_1,_hz * 0xf);
  }
  else {
    uVar3 = CONCAT22((sword)(uVar2 >> 0x10),
                     (word)(byte)((3 < uVar2) << 4 | ((int)(3 - uVar2) < 0) << 3 |
                                  SBORROW4(3,uVar2) << 1 | 3 < uVar2));
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2138 start=0x4073642 */

undefined4 _np_wait_printer_ready(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _np_getgpi(param_1,param_1 + 0x11b);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else if (*(int *)(param_1 + 0x126) != 2) {
    do {
      if ((*(int *)(param_1 + 0x126) == 6) && ((*(uint *)(param_1 + 0x106) & 0x100) != 0)) {
        return 0x51;
      }
      if ((*(int *)(param_1 + 0x126) == 0) || (*(int *)(param_1 + 0x126) == 7)) {
        return 0x50;
      }
      if ((*(uint *)(param_1 + 0x106) & 0x100) != 0) {
        return 0x23;
      }
      _sleep((int *)(param_1 + 0x126),0x28);
    } while (*(int *)(param_1 + 0x126) != 2);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2139 start=0x40736de */

undefined4 _np_dev_intr(int *param_1)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  
  puVar1 = (uint *)*param_1;
  if ((*puVar1 & 0x20000000) != 0) {
    if (((*(int *)((int)param_1 + 0x126) == 4) &&
        (*(int *)((int)param_1 + 0x12a) != *(int *)(param_1[8] + 0x4000))) &&
       (*(int *)((int)param_1 + 0x12a) != *(int *)(param_1[8] + 0x4008))) {
      _np_printing_shutdown(param_1);
      _np_setstate(param_1,8);
    }
    else if (*(int *)((int)param_1 + 0x126) == 4) {
      _np_printing_shutdown(param_1);
    }
    _lpr_csr_or(0x20);
  }
  if ((*puVar1 & 0x2000000) != 0) {
    _printf(aNpDSpuriousDma,(int)(param_1 + -0x1030e89) * 0x2b2e43db >> 2);
    _lpr_csr_or(2);
  }
  if (((*puVar1 & 0x20000) == 0) && ((*puVar1 & 0x40000) == 0)) {
    return 0;
  }
  if ((*puVar1 & 0x20000) != 0) {
    *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 2;
  }
  cVar2 = (char)*puVar1;
  if (cVar2 != -0x3c) {
    if (cVar2 == -0x3a) {
      return 0;
    }
    _printf(aNpDSpuriousPac,(int)(param_1 + -0x1030e89) * 0x2b2e43db >> 2,cVar2);
    return 0;
  }
  *(byte *)((int)param_1 + 0x11b) = ~(byte)(puVar1[1] >> 0x18) & 0x3f;
  if (((*(byte *)((int)param_1 + 0x11b) & 0x10) == 0) && (*(int *)((int)param_1 + 0x126) != 1)) {
    if (*(int *)((int)param_1 + 0x126) == 4) {
      _np_printing_shutdown(param_1);
    }
    uVar3 = 1;
  }
  else if (*(int *)((int)param_1 + 0x126) == 2) {
    if ((*(byte *)((int)param_1 + 0x11b) & 8) != 0) goto loc_4073880;
    uVar3 = 6;
  }
  else {
    if ((*(int *)((int)param_1 + 0x126) != 6) || ((*(byte *)((int)param_1 + 0x11b) & 8) == 0))
    goto loc_4073880;
    uVar3 = 2;
  }
  _np_setstate(param_1,uVar3);
loc_4073880:
  _thread_wakeup_prim((int)param_1 + 0x11b,0,0);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2140 start=0x407389a */

undefined4 _np_dma_intr(int param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x126) == 4) {
    _np_printing_shutdown(param_1);
  }
  cVar2 = '\0';
  uVar1 = *(uint *)(param_1 + 0x30);
  bVar3 = (uVar1 & 0x4000) == 0;
  if (!bVar3) {
    uVar1 = (param_1 + -0x40c3a24) * 0x2b2e43db;
    cVar2 = (uVar1 >> 1 & 1) != 0;
    _printf(aNpDDmaErrorFlu,(int)uVar1 >> 2);
    uVar1 = *(uint *)(param_1 + 0x30) & 0xffffbfff;
    *(uint *)(param_1 + 0x30) = uVar1;
    bVar3 = uVar1 == 0;
  }
  return CONCAT22((sword)(uVar1 >> 0x10),
                  (word)(byte)(cVar2 << 4 | ((int)uVar1 < 0) << 3 | bVar3 << 2));
}
/* GHIDRADEC_FUNCTION index=2141 start=0x4073910 */

void _np_open(sword param_1,undefined4 param_2)

{
  _np_open_common((int)param_1,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2142 start=0x407392a */

void _nps_open(sword param_1,undefined4 param_2)

{
  _np_open_common((int)param_1,param_2,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2143 start=0x4073946 */

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
/* GHIDRADEC_FUNCTION index=2144 start=0x4073aa6 */

undefined4 _np_close(byte param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (sword)(word)param_1 * 0x14c;
  iVar1 = *(int *)(DAT_40c3b2a + iVar3 + 0x18);
  iVar2 = *(int *)(DAT_40c3b2a + iVar3 + 0x1c);
  *(uint *)(DAT_40c3b2a + iVar3) = *(uint *)(DAT_40c3b2a + iVar3) & 0xfffffffd;
  *(undefined4 *)(DAT_40c3b2a + iVar3 + 0x18) = 0;
  *(undefined4 *)(DAT_40c3b2a + iVar3 + 0x1c) = 0;
  if (iVar1 != 0) {
    _thread_deallocate(iVar1);
  }
  if (iVar2 != 0) {
    _thread_deallocate(iVar2);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2145 start=0x4073b10 */

void _np_ioctl(sword param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_4073B56((int)param_1,param_2,param_3,param_4,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2146 start=0x4073b32 */

void _nps_ioctl(sword param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_4073B56((int)param_1,param_2,param_3,param_4,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2147 start=0x4073bda */

int _np_ioctl_common(byte param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 unaff_A6;
  byte **ppbVar8;
  byte *pbStack_28;
  byte bStack_6;
  byte bStack_5;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_4 = (undefined2)((uint)unaff_A6 >> 0x10);
  uStack_2 = (undefined2)unaff_A6;
  iVar3 = (sword)(word)param_1 * 0x14c;
  pbVar7 = _np_softc + iVar3;
  iVar5 = 0;
  if (param_2 == -0x7ffb9982) {
    if (*param_3 == 0) {
      *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) & 0xfffffeff;
      return 0;
    }
    *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) | 0x100;
    return 0;
  }
  if (param_2 < -0x7ffb9981) {
    if (param_2 == -0x7ffb9983) {
      return 0;
    }
loc_407411C:
    return 6;
  }
  if (param_2 != -0x3fed8fff) {
    return 6;
  }
  if (param_5 != 0) {
    sVar1 = *(sword *)param_3;
    if (sVar1 == 4) {
      return 6;
    }
    if (sVar1 < 5) {
      if ((sVar1 < 3) && (-1 < sVar1)) {
        return 6;
      }
    }
    else if (sVar1 == 6) {
      return 6;
    }
  }
  if (*(sword *)param_3 == 0) {
    if (*(int *)((int)param_3 + 2) == 0) {
      pbStack_28 = (byte *)(iVar3 + 0x40c3b36);
      _lock_write();
      if ((*(int *)(_np_softc + iVar3 + 0x126) != 2) && (*(int *)(_np_softc + iVar3 + 0x126) != 6))
      {
        piVar2 = (int *)(_np_softc + iVar3 + 0x126);
        while (*(int *)(_np_softc + iVar3 + 0x126) != 0) {
          pbStack_28 = (byte *)0x28;
          _sleep(piVar2);
          if ((*piVar2 == 2) || (*piVar2 == 6)) break;
        }
      }
      ppbVar8 = &pbStack_28;
      pbStack_28 = pbVar7;
      _np_power_off();
    }
    else {
      pbStack_28 = (byte *)(iVar3 + 0x40c3b36);
      _lock_write();
      ppbVar8 = (byte **)&stack0xffffffdc;
      if ((*(int *)(_np_softc + iVar3 + 0x126) == 0) || (*(int *)(_np_softc + iVar3 + 0x126) == 7))
      {
        pbStack_28 = pbVar7;
        iVar5 = _np_power_on();
        ppbVar8 = (byte **)&stack0xffffffdc;
      }
    }
    *(int *)((int)ppbVar8 + -4) = iVar3 + 0x40c3b36;
    *(undefined4 *)((int)ppbVar8 + -8) = 0x4073cfe;
    _lock_done();
    return iVar5;
  }
  if ((*(int *)(_np_softc + iVar3 + 0x126) == 0) || (*(int *)(_np_softc + iVar3 + 0x126) == 7)) {
    return 0x50;
  }
  switch(*(undefined2 *)param_3) {
  case :
    if ((((0x1ff < *(uint *)((int)param_3 + 2)) || (0x7e < *(int *)((int)param_3 + 10) - 1U)) ||
        (*(int *)((int)param_3 + 6) < 1)) || (*(int *)((int)param_3 + 0xe) < 1)) goto loc_4073DAA;
    *(uint *)(_np_softc + iVar3 + 0x132) = *(uint *)((int)param_3 + 2);
    *(undefined4 *)(_np_softc + iVar3 + 0x13a) = *(undefined4 *)((int)param_3 + 10);
    *(undefined4 *)(_np_softc + iVar3 + 0x13e) = *(undefined4 *)((int)param_3 + 0xe);
    *(undefined4 *)(_np_softc + iVar3 + 0x136) = *(undefined4 *)((int)param_3 + 6);
    uVar4 = *(uint *)(_np_softc + iVar3 + 0x106);
    uVar6 = 1;
    goto loc_40740C8;
  case :
    if (*(byte *)((int)param_3 + 2) < 2) {
      _np_softc[iVar3 + 0x143] = *(byte *)((int)param_3 + 2);
      return 0;
    }
loc_4073DAA:
    iVar5 = 0x16;
    break;
  case :
    *(undefined4 *)((int)param_3 + 2) = 0;
    *(undefined4 *)((int)param_3 + 6) = 0;
    if (*(int *)(_np_softc + iVar3 + 0x126) == 1) {
      do {
        pbStack_28 = (byte *)0x28;
        _sleep(_np_softc + iVar3 + 0x126);
      } while (*(int *)(_np_softc + iVar3 + 0x126) == 1);
    }
    if ((*(int *)(_np_softc + iVar3 + 0x126) == 3) || (*(int *)(_np_softc + iVar3 + 0x126) == 4)) {
loc_407408C:
      *(undefined4 *)((int)param_3 + 2) = 1;
      return 0;
    }
    pbStack_28 = &bStack_5;
    iVar5 = _np_serial_cmd(pbVar7,1);
    if (iVar5 == 0) {
      if ((bStack_5 & 0x20) != 0) {
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 1;
      }
      if ((bStack_5 & 0x10) != 0) {
        pbStack_28 = &bStack_6;
        iVar5 = _np_serial_cmd(pbVar7,0x1f);
        if (iVar5 != 0) goto loc_4073F34;
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 2;
        *(uint *)((int)param_3 + 6) =
             (CONCAT22(CONCAT11(bStack_6,bStack_5),uStack_4) & 0x7fffffff) >> 0x19;
      }
      if ((bStack_5 & 8) != 0) {
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 4;
      }
      if ((bStack_5 & 2) == 0) {
loc_4073F20:
        pbStack_28 = &bStack_5;
        iVar5 = _np_serial_cmd(pbVar7,0x1f);
        if (iVar5 == 0) {
          if ((bStack_5 & 4) != 0) {
            *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x80;
          }
          if ((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) != 0) {
            *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x200;
            return 0;
          }
          return 0;
        }
      }
      else {
        pbStack_28 = &bStack_5;
        iVar5 = _np_serial_cmd(pbVar7,2);
        if (iVar5 == 0) {
          if ((bStack_5 & 0x40) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 8;
          }
          if ((bStack_5 & 0x10) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x10;
          }
          if ((bStack_5 & 8) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x20;
          }
          if ((bStack_5 & 4) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x40;
          }
          pbStack_28 = &bStack_5;
          iVar5 = _np_serial_cmd(pbVar7,4);
          if (iVar5 == 0) {
            if ((bStack_5 & 0x70) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x100;
            }
            if ((bStack_5 & 0x40) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x500;
            }
            if ((bStack_5 & 0x20) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x900;
            }
            if ((bStack_5 & 0x10) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x1100;
            }
            goto loc_4073F20;
          }
        }
      }
    }
loc_4073F34:
    if (iVar5 == 0x51) {
      *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x40;
      iVar5 = 0;
    }
    break;
  case :
    if (*(int *)(_np_softc + iVar3 + 0x126) != 1) {
      pbStack_28 = &bStack_5;
      iVar5 = _np_serial_cmd(pbVar7,0x5d);
      if ((iVar5 != 0) && (iVar5 == 0x51)) {
        iVar5 = 0;
      }
    }
    break;
  case :
    do {
      if (*(int *)(_np_softc + iVar3 + 0x126) == 1) {
        do {
          pbStack_28 = (byte *)0x28;
          _sleep(_np_softc + iVar3 + 0x126);
        } while (*(int *)(_np_softc + iVar3 + 0x126) == 1);
      }
      pbStack_28 = &bStack_5;
      iVar5 = _np_serial_cmd(pbVar7,0xb);
      if (iVar5 == 0) {
        switch(bStack_5) {
        case :
          *(undefined4 *)((int)param_3 + 2) = 0;
          return 0;
        case :
          goto loc_407408C;
        :
          return 5;
        case :
          *(undefined4 *)((int)param_3 + 2) = 2;
          return 0;
        case :
          *(undefined4 *)((int)param_3 + 2) = 3;
          return 0;
        case :
          *(undefined4 *)((int)param_3 + 2) = 4;
          return 0;
        }
      }
    } while (iVar5 == 0x51);
    break;
  case :
    if (((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) != 0) || (*(int *)((int)param_3 + 2) == 0)) {
      if ((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) == 0) {
        return 0;
      }
      if (*(int *)((int)param_3 + 2) == 0) {
        *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) | 0x20;
        *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) & 0xffffffef;
        return 0;
      }
      return 0;
    }
    uVar4 = *(uint *)(_np_softc + iVar3 + 0x106);
    uVar6 = 0x30;
loc_40740C8:
    *(uint *)(_np_softc + iVar3 + 0x106) = uVar6 | uVar4;
    break;
  :
    goto loc_407411C;
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=2148 start=0x4074128 */

void _np_select(sword param_1,undefined4 param_2)

{
  _np_select_common((int)param_1,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2149 start=0x4074142 */

void _nps_select(sword param_1,undefined4 param_2)

{
  _np_select_common((int)param_1,param_2,1);
  return;
}

