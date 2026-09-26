/* GHIDRADEC_FUNCTION index=2050 start=0x406e526 */

void _ts_diff(uint *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = _ts_greater(param_2,param_1);
  puVar2 = param_1;
  if (iVar1 != 0) {
    puVar2 = param_2;
    param_2 = param_1;
  }
  if (*puVar2 < *param_2) {
    puVar2[1] = puVar2[1] - 1;
  }
  *param_3 = *puVar2 - *param_2;
  param_3[1] = puVar2[1] - param_2[1];
  return;
}
/* GHIDRADEC_FUNCTION index=2051 start=0x406e574 */

int _ts_greater(uint *param_1,uint *param_2)

{
  bool bVar1;
  
  bVar1 = param_2[1] < param_1[1];
  if (param_2[1] == param_1[1]) {
    bVar1 = *param_2 < *param_1;
  }
  return -(int)(char)-bVar1;
}
/* GHIDRADEC_FUNCTION index=2052 start=0x406e59e */

void _ts_add(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_2 + uVar1;
  *param_1 = uVar2;
  if (uVar2 < uVar1) {
    param_1[1] = param_1[1] + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2053 start=0x406e5bc */

void _fc_thread_timer(void)

{
  int iVar1;
  int iVar2;
  
  if ((_kernel_task == 0) || (_fc_thread_init != 0)) {
    _timeout(_fc_thread_timer,0,_hz);
  }
  else {
    _kernel_thread_noblock(_kernel_task,_volume_check);
    iVar2 = 0;
    iVar1 = 0;
    do {
      if ((*(uint *)(DAT_40c3784 + iVar1) & 2) == 0) {
        _kernel_thread_noblock(_kernel_task,_fc_thread);
      }
      iVar1 = iVar1 + 0x262;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
    _fc_thread_init = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2054 start=0x406e640 */

undefined4 _fd_thread_block(uint *param_1,uint param_2)

{
  uint uVar1;
  
  while( true ) {
    uVar1 = param_2 & *param_1;
    if (uVar1 != 0) break;
    _assert_wait(param_1,0);
    _thread_block();
  }
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar1 < 0) << 3));
}
/* GHIDRADEC_FUNCTION index=2055 start=0x406e68c */

void _fd_set_density_info(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _fd_density_info;
  iVar1 = _fd_density_info._0_4_;
  while ((iVar1 != 0 && (param_2 != *(int *)puVar2))) {
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    iVar1 = *(int *)puVar2;
  }
  *(int *)(param_1 + 0x17a) = *(int *)puVar2;
  *(int *)(param_1 + 0x17e) = *(int *)((int)puVar2 + 4);
  *(int *)(param_1 + 0x182) = *(int *)((int)puVar2 + 8);
  _fd_set_sector_size(param_1,*(undefined4 *)(param_1 + 0x186));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffe;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2056 start=0x406e6e0 */

undefined4 _fd_set_sector_size(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)_fd_get_sectsize_info(*(undefined4 *)(param_1 + 0x17a));
  if (*piVar1 != 0) {
    do {
      if (param_2 == *piVar1) break;
      piVar1 = piVar1 + 3;
    } while (*piVar1 != 0);
    if (*piVar1 != 0) {
      *(int *)(param_1 + 0x186) = *piVar1;
      *(int *)(param_1 + 0x18a) = piVar1[1];
      *(int *)(param_1 + 0x18e) = piVar1[2];
      *(uint *)(param_1 + 0x192) =
           *(int *)(param_1 + 0x16e) * *(int *)(param_1 + 0x18c) * (uint)*(byte *)(param_1 + 0x16c);
      *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd | 1;
      return 0;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2057 start=0x406e758 */

undefined (*) [84] _fd_get_sectsize_info(int param_1)

{
  undefined (**ppauVar1) [84];
  int *piVar2;
  
  piVar2 = &_fd_density_sectsize;
  if (off_40B13A2 != (undefined (*) [84])0x0) {
    ppauVar1 = &off_40B13A2;
    do {
      if (param_1 == *piVar2) {
        return *ppauVar1;
      }
      ppauVar1 = ppauVar1 + 2;
      piVar2 = piVar2 + 2;
    } while (*ppauVar1 != (undefined (*) [84])0x0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aFdSectsizeInfo);
}
/* GHIDRADEC_FUNCTION index=2058 start=0x406e794 */

void _fd_setbratio(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = *(uint *)(iVar1 + 0x5c);
  uVar3 = *(uint *)(param_1 + 0x186);
  if ((uVar2 < uVar3) || (uVar2 % uVar3 != 0)) {
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd;
    _printf(aFsBlockNotMult);
    _printf(aFsBlockDDevBlo,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(param_1 + 0x186));
  }
  else {
    *(uint *)(param_1 + 0x196) = uVar2 / uVar3;
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (iVar5 = (int)*(sword *)(*(int *)(param_1 + 0xc) + 0xc), -1 < iVar5)) {
      if (*(int *)(iVar1 + 0x6c) < 0x3c) {
        iVar4 = 0x3c;
      }
      else {
        iVar4 = *(int *)(iVar1 + 0x6c) / 0x3c;
      }
      *(int *)(_dk_bps + iVar5 * 4) = iVar4 * *(int *)(iVar1 + 100) * *(int *)(iVar1 + 0x5c);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2059 start=0x406e83c */

void _volume_check(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined7 *puVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int iStack_1e;
  int iStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  uint uStack_e;
  undefined4 uStack_a;
  byte abStack_6 [2];
  
  iVar5 = _fd_new_fv(9);
  _vol_check_alive = 1;
  unk_40C375C = iVar5;
  puVar3 = _vol_abort_q;
  do {
    while ((undefined4 **)puVar3 != &_vol_abort_q) {
      puVar1 = (undefined4 *)*puVar3;
      puVar2 = (undefined4 *)puVar3[1];
      puVar4 = puVar2;
      if ((undefined4 **)puVar1 != &_vol_abort_q) {
        puVar1[1] = puVar2;
        puVar4 = dword_40C39D8;
      }
      dword_40C39D8 = puVar4;
      *puVar2 = puVar1;
      iVar10 = puVar3[2];
      if ((*(uint *)(iVar10 + 0x124) & 8) != 0) {
        iVar6 = *(int *)(iVar10 + 8);
        *(uint *)(iVar10 + 0x124) = *(uint *)(iVar10 + 0x124) & 0xfffffff7 | 0x10;
        *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar10 + 8);
        (&DAT_40c370c)[iVar6 * 10] = 0;
        *(undefined4 *)(iVar10 + 8) = 1;
        _fd_basic_cmd(iVar5,0x81);
      }
      _kfree(puVar3,0x14);
      puVar3 = puVar1;
    }
    sub_406EF08();
    puVar9 = &_fd_drive;
    iVar10 = 0;
    piVar11 = &DAT_40c370c;
    do {
      if ((*(byte *)((int)puVar9 + 0x23) & 1) == 0) break;
      if (*(int *)((int)puVar9 + 0xc) == 0) {
        *(int *)(iVar5 + 4) = iVar10;
        iVar6 = _fd_get_status(iVar5,abStack_6);
        if ((iVar6 == 0) && ((abStack_6[0] & 0xc0) != 0)) {
          *(undefined4 *)(iVar5 + 0x176) = 0;
          *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)((int)puVar9 + 0x14);
          iVar6 = _fd_attach_com(iVar5);
          if (iVar6 == 0) {
            iVar6 = *piVar11;
            if (iVar6 == 0) {
              iVar6 = 0;
              piVar12 = (int *)_fd_volume_p;
              do {
                iVar13 = *piVar12;
                if ((iVar13 != 0) && (iVar7 = sub_406ECF4(iVar5,iVar13), iVar7 == 0)) {
                  *(undefined4 *)(iVar13 + 0x176) = *(undefined4 *)(iVar5 + 0x176);
                  sub_406EC7C(iVar13,puVar9,iVar5);
                  goto loc_406EAE4;
                }
                piVar12 = piVar12 + 1;
                iVar6 = iVar6 + 1;
              } while (iVar6 < 8);
              iVar6 = 0;
              piVar12 = (int *)_fd_volume_p;
              do {
                if (*piVar12 == 0) {
                  uVar8 = _fd_new_fv(iVar6);
                  *(undefined4 *)(_fd_volume_p + iVar6 * 4) = uVar8;
                  _fd_assign_dv(uVar8,iVar10);
                  sub_406EEB4(iVar5,uVar8);
                  _volume_notify(uVar8);
                  goto loc_406EAE4;
                }
                piVar12 = piVar12 + 1;
                iVar6 = iVar6 + 1;
              } while (iVar6 < 8);
              _printf(aFdVolumeCheckN);
              _fd_basic_cmd(iVar5,2);
            }
            else if ((*(byte *)(iVar6 + 0x127) & 4) == 0) {
              iVar13 = sub_406ECF4(iVar5,iVar6);
              if (iVar13 == 0) {
                *(undefined4 *)(*piVar11 + 0x176) = *(undefined4 *)(iVar5 + 0x176);
                sub_406EC7C(*piVar11,puVar9,iVar5);
              }
              else {
                _fd_basic_cmd(iVar5,2);
                if ((*(byte *)(iVar6 + 0x127) & 8) != 0) {
                  _vol_panel_remove(*(undefined4 *)(iVar6 + 0x138));
                  sub_406EFD6(iVar6,1);
                }
              }
            }
            else {
              iVar13 = 0;
              do {
                if ((*(int *)(_fd_volume_p + iVar13 * 4) != 0) &&
                   (iVar7 = sub_406ECF4(iVar5,*(int *)(_fd_volume_p + iVar13 * 4)), iVar7 == 0)) {
                  _fd_basic_cmd(iVar5,2);
                  if ((*(byte *)(iVar6 + 0x127) & 8) != 0) {
                    _vol_panel_remove(*(undefined4 *)(iVar6 + 0x138));
                    sub_406EFD6(iVar6,1);
                  }
                  goto loc_406EAE4;
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 < 8);
              sub_406EEB4(iVar5,iVar6);
              sub_406EC7C(iVar6,puVar9,iVar5);
            }
          }
        }
      }
loc_406EAE4:
      iVar10 = iVar10 + 1;
      piVar11 = piVar11 + 10;
      puVar9 = puVar9 + 5;
    } while (iVar10 < 1);
    puVar9 = &_fd_drive;
    iVar10 = 0;
    do {
      if (((*(uint *)(puVar9 + 4) & 7) == 3) && (*(int *)((int)puVar9 + 0xc) != 0)) {
        uStack_e = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l)
                   & 0xfffff;
        if ((((uStack_e ^ *_event_middle) & 0x80000) != 0) &&
           (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
          *_event_high = *_event_high + 1;
        }
        uStack_a = *_event_high;
        uStack_e = *_event_middle | uStack_e;
        uStack_16 = *(undefined4 *)(puVar9 + 3);
        uStack_12 = *(undefined4 *)((int)puVar9 + 0x1c);
        _ts_add(&uStack_16,2000000);
        iVar6 = _ts_greater(&uStack_e,&uStack_16);
        if (iVar6 != 0) {
          *(int *)(iVar5 + 4) = iVar10;
          _fd_basic_cmd(iVar5,4);
        }
      }
      iVar10 = iVar10 + 1;
      puVar9 = puVar9 + 5;
    } while (iVar10 < 1);
    if (_vol_check_delay < 1000000) {
      iStack_1e = 0;
      iStack_1a = _vol_check_delay;
    }
    else {
      iStack_1e = _vol_check_delay / 1000000;
      iStack_1a = _vol_check_delay % 1000000;
    }
    _vol_check_event = 0;
    _us_timeout(_vol_check_timeout,0,&iStack_1e,0);
    _fd_thread_block(&_vol_check_event,0xff,&_vol_check_lock);
    puVar3 = _vol_abort_q;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2060 start=0x406ed7a */

void _volume_notify(int param_1)

{
  word wVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined auStack_5e [6];
  undefined auStack_58 [20];
  undefined auStack_44 [64];
  
  auStack_44[0] = 0;
  if ((*(uint *)(param_1 + 0x176) & 1) == 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 1;
    if ((*(uint *)(param_1 + 0x176) & 2) != 0) {
      uVar5 = 0;
    }
  }
  uVar4 = 1;
  if (*(int *)(param_1 + 0x172) != 0) {
    do {
      iVar2 = sub_406EE4E(uVar4);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x3ff;
      }
      _sprintf(auStack_58,&aD,iVar2 >> 10);
      _strcat(auStack_44,auStack_58);
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(uint *)(param_1 + 0x172));
  }
  _sprintf(auStack_5e,&aFdD,*(undefined4 *)(param_1 + 0x10));
  uVar3 = 1;
  if ((*(byte *)(param_1 + 0x179) & 4) != 0) {
    uVar3 = 3;
  }
  wVar1 = (sword)*(undefined4 *)(param_1 + 0x10) << 3;
  _vol_notify_dev((int)(sword)(wVar1 | (sword)_fd_blk_major << 8),
                  (int)(sword)(wVar1 | (sword)_fd_raw_major << 8),auStack_44,uVar5,auStack_5e,uVar3)
  ;
  return;
}
/* GHIDRADEC_FUNCTION index=2061 start=0x406ee78 */

byte _vol_check_timeout(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = _vol_check_alive < '\0';
  cVar3 = _vol_check_alive == '\0';
  if (!(bool)cVar3) {
    _vol_check_event = 1;
    cVar2 = '\0';
    cVar3 = '\x01';
    cVar4 = '\0';
    bVar5 = 0;
    _thread_wakeup_prim(&_vol_check_event,0,0);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=2062 start=0x406f0fe */

void _kminit(void)

{
  int iVar1;
  undefined uStack_24;
  uint uStack_23;
  
  _km_select_console();
  _kminit2();
  word_40B68E0 = 0x32;
  word_40B68E4 = 0xf;
  iVar1 = dword_40B6944 + -400;
  if (iVar1 < 0) {
    iVar1 = dword_40B6944 + -0x181;
  }
  word_40B68DE = (undefined2)(iVar1 >> 4);
  _km_color = dword_40B6954;
  dword_40C3A10 = dword_40B6958;
  dword_40C3A14 = dword_40B695C;
  dword_40C3A18 = dword_40B6960;
  _evinit();
  _nvram_check(&uStack_24);
  _curBright = (uStack_23 & 0xfffffff) >> 0x16;
  unk_40B6904 = unk_40B6904 | 1;
  word_40B6906 = 0;
  word_40B6938 = 0;
  dword_40B68E8 = 0;
  dword_40B68EC = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2063 start=0x406f1a8 */

void _kminit2(void)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined2 *puVar4;
  
  dword_40B68F4 = dword_40B6954;
  dword_40B68F0 = dword_40B6960;
  word_40B68DA = 0;
  word_40B68D8 = 0;
  dword_40B68FA = &DAT_40b6900;
  iVar2 = 2;
  puVar4 = &unk_40B6902;
  do {
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + -1;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2064 start=0x406f1f0 */

undefined4 _kmopen(sword param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 & 0xa0000000) == 0) {
loc_406F2A4:
    if ((unk_40B6904 & 1) == 0) {
      _kminit();
    }
    if (1 < (byte)param_1) {
      return 6;
    }
    dword_40B6830 = 0;
    dword_40B6820 = _kmstart;
    byte_40B6841 = '\x02';
    if ((dword_40B683A & 4) == 0) {
      _ttychars(_cons);
      dword_40B6836 = 0x140700d8;
      byte_40B6848 = 0x7f;
      byte_40B6844 = 0xd;
      byte_40B6843 = 0xd;
      dword_40B683A = dword_40B683A | 0x10;
    }
    else if (((char)dword_40B683A < '\0') && (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0))
    goto loc_406F306;
    uVar2 = (*(code *)(&_linesw)[byte_40B6841 * 0xc])((int)param_1,_cons);
    DAT_40b6858._0_2_ = word_40B68E0;
    DAT_40b6856._0_2_ = word_40B68E4;
    DAT_40b6858._2_2_ = uRam040b6946;
    DAT_40b6858._4_2_ = word_40B694E;
  }
  else {
    if ((unk_40B6904 & 8) != 0) {
      if (word_40B6938 != 0) {
        word_40B6938 = word_40B6938 + 1;
      }
      goto loc_406F2A4;
    }
    if ((int)param_2 < 0) {
      _kmpopup(_mach_title,0,0,0,0);
      _kmioctl(0,0x20006b03,0,0);
loc_406F28E:
      word_40B6938 = word_40B6938 + 1;
      goto loc_406F2A4;
    }
    iVar1 = _suser();
    if (iVar1 == 0) {
      return 0xd;
    }
    if (_eventsOpen == 0) {
      _alert_lock_screen(1);
      _kmpopup(_mach_title,1,0x3c,8,1);
      goto loc_406F28E;
    }
loc_406F306:
    uVar2 = 0x10;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2065 start=0x406f38a */

undefined4 _kmclose(void)

{
  (**(code **)(unk_40AE4B0 + byte_40B6841 * 0x30))(_cons);
  _ttyclose(_cons);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2066 start=0x406f3c8 */

void _kmread(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(DAT_40ae4b4 + byte_40B6841 * 0x30))(_cons,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2067 start=0x406f3f8 */

void _kmwrite(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(DAT_40ae4b8 + byte_40B6841 * 0x30))(_cons,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2068 start=0x406f428 */

void _kmselect(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(DAT_40ae4d4 + byte_40B6841 * 0x30))(_cons,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2069 start=0x406f458 */

void _kmstart(int param_1)

{
  if (((*(uint *)(param_1 + 0x3e) & 0x121) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x20;
    if ((int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2) <
        *(int *)(param_1 + 0x18)) {
      _callout_dispatch(0,_kmoutput,param_1);
    }
    else {
      _timeout(_kmoutput,param_1,_hz / 0x1e);
    }
  }
  else if (*(int *)(param_1 + 0x18) <=
           (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
    if ((*(uint *)(param_1 + 0x3e) & 0x40) != 0) {
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x3e) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xefff;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2070 start=0x406f542 */

byte _kmoutput(int param_1)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  undefined4 uVar12;
  byte abStack_54 [80];
  
  iVar2 = _ttynty(param_1);
  uVar4 = 0xffffffff;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      if ((((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
          ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0)) &&
         ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
        uVar12 = 0x80;
      }
      else {
        uVar12 = 0;
      }
      uVar3 = _ndqb(param_1 + 0x18,uVar12);
      if (uVar3 == 0) goto loc_406F5FC;
      uVar4 = 0x50;
      if (uVar3 < 0x50) {
        uVar4 = uVar3;
      }
      _q_to_b(param_1 + 0x18,abStack_54,uVar4);
      for (pbVar6 = abStack_54; pbVar6 < abStack_54 + uVar4; pbVar6 = pbVar6 + 1) {
        _kmpaint(*pbVar6 & 0x7f);
      }
    } while (0 < *(int *)(param_1 + 0x18));
  }
  if (uVar4 == 0) {
loc_406F5FC:
    uVar4 = _getc(param_1 + 0x18);
    _timeout(_ttrstrt,param_1,uVar4 & 0x7f);
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 1;
  }
  else if (0 < *(int *)(param_1 + 0x18)) {
    _callout_dispatch(0,_kmoutput,param_1);
  }
  uVar4 = *(uint *)(param_1 + 0x3e);
  *(uint *)(param_1 + 0x3e) = uVar4 & 0xffffffdf;
  uVar5 = (uint)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  uVar3 = *(uint *)(param_1 + 0x18);
  cVar10 = uVar5 < uVar3;
  bVar9 = SBORROW4(uVar5,uVar3);
  bVar7 = (int)(uVar5 - uVar3) < 0;
  bVar8 = uVar5 == uVar3;
  bVar11 = (bool)cVar10;
  if ((int)uVar3 <= (int)uVar5) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x3e) = uVar4 & 0xffffff9f;
      _wakeup(param_1 + 0x18);
    }
    iVar2 = *(int *)(param_1 + 0x2c);
    bVar7 = iVar2 < 0;
    bVar8 = iVar2 == 0;
    bVar9 = false;
    bVar11 = false;
    if (!bVar8) {
      _selwakeup(iVar2,*(uint *)(param_1 + 0x3e) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      bVar9 = false;
      bVar11 = false;
      wVar1 = *(word *)(param_1 + 0x40) & 0xefff;
      *(word *)(param_1 + 0x40) = wVar1;
      bVar7 = (int)((uint)wVar1 << 0x10) < 0;
      bVar8 = wVar1 == 0;
    }
  }
  return cVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 | bVar11;
}
/* GHIDRADEC_FUNCTION index=2071 start=0x406f6b6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _kmpopup(char *param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  word wVar7;
  uint uVar6;
  sword sVar10;
  uint uVar8;
  int iVar9;
  sword sVar12;
  uint uVar11;
  undefined2 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  undefined *puVar20;
  undefined2 *puVar21;
  uint *puVar22;
  undefined *puVar23;
  uint *puVar24;
  int iVar25;
  
  iVar17 = _mon_global;
  *(word *)(unk_40B6908 + word_40B6906 * 2) = unk_40B6904;
  *(undefined **)(unk_40B6918 + word_40B6906 * 4) = _cons_tp;
  wVar7 = *(word *)(unk_40B6908 + word_40B6906 * 2);
  if ((*(byte *)(iVar17 + 4) & 8) != 0) {
    wVar7 = wVar7 | 0x400;
  }
  *(word *)(unk_40B6908 + word_40B6906 * 2) = wVar7;
  word_40B6906 = word_40B6906 + 1;
  if ((*(byte *)(iVar17 + 4) & 8) != 0) {
    _vidSuspendAnimation();
  }
  sVar10 = (sword)param_3;
  sVar12 = (sword)param_4;
  word_40B68E0 = sVar10;
  word_40B68E4 = sVar12;
  if (((_eventsOpen == 0) && (param_5 == 0)) && ((*(byte *)(&word_40B6906 + word_40B6906) & 4) == 0)
     ) {
    if (param_3 == 0) {
      word_40B68E0 = 100;
    }
    if (param_4 == 0) {
      word_40B68E4 = 0x30;
    }
    dword_40B68E8 = (uint *)0x0;
    goto loc_406F8E8;
  }
  if ((unk_40B6904 & 0x10) == 0) {
    if (param_3 == 0) {
      word_40B68E0 = 0x32;
    }
    if (param_4 == 0) {
      word_40B68E4 = 0xf;
    }
    iVar17 = (word_40B68E4 * 0xc + 0x1e) * ((uint)((word_40B68E0 + 3) * 0x20) / _km_coni);
    if (iVar17 - dword_40B6990 != 0 && dword_40B6990 <= iVar17) {
      if ((_mb_map != 0) &&
         (dword_40B68E8 = (uint *)_kmem_mb_alloc(_mb_map,iVar17), dword_40B68E8 != (uint *)0x0)) {
        word_40B68E2 = word_40B68E0;
        word_40B68E6 = word_40B68E4;
        unk_40B6904 = unk_40B6904 | 0x10;
        dword_40B68EC = dword_40B68E8;
        goto loc_406F8E8;
      }
      if (dword_40B6990 < iVar17) {
        if (dword_40B6990 * 3 < iVar17) {
          word_40B68E0 = (sword)((word_40B68E0 * 3) / 5);
        }
        word_40B68E4 = (sword)(dword_40B6990 /
                              (int)(((uint)((word_40B68E0 + 3) * 0x20) / _km_coni) * 0xc));
      }
    }
    dword_40B68E8 = dword_40B698C;
    goto loc_406F8E8;
  }
  if (dword_40B68E8 == (uint *)0x0) {
    dword_40B68E8 = dword_40B68EC;
  }
  word_40B68E0 = word_40B68E2;
  if (param_3 == 0) {
    if (0x4f < word_40B68E2) goto loc_406F7A8;
  }
  else if (param_3 <= word_40B68E2) {
loc_406F7A8:
    word_40B68E0 = 0x50;
    if (param_3 != 0) {
      word_40B68E0 = sVar10;
    }
  }
  word_40B68E4 = word_40B68E6;
  if (param_4 == 0) {
    if (word_40B68E6 < 0x28) goto loc_406F8E8;
  }
  else if (word_40B68E6 < param_4) goto loc_406F8E8;
  word_40B68E4 = 0x28;
  if (param_4 != 0) {
    word_40B68E4 = sVar12;
  }
loc_406F8E8:
  uVar5 = dword_40B6960;
  uVar4 = dword_40B695C;
  uVar3 = dword_40B6958;
  uVar6 = dword_40B6954;
  iVar17 = dword_40B6944 + word_40B68E0 * -8;
  if (iVar17 < 0) {
    iVar17 = iVar17 + 0xf;
  }
  word_40B68DE = (sword)(iVar17 >> 4);
  word_40B68DC = (sword)((_unk_40B694C + 0x1a + word_40B68E4 * -0xc) / 0x18);
  unk_40B6904 = unk_40B6904 | 8;
  _cons_tp = _cons;
  uVar16 = dword_40B6954;
  if (param_2 == 1) {
    uVar16 = dword_40B6958;
  }
  dword_40B1BBE = 0;
  _km_begin_access();
  if (param_2 == 2) {
    _km_clear_screen();
  }
  iVar17 = dword_40B6980 + (uint)((int)word_40B68DE << 5) / _km_coni;
  uVar2 = _km_coni * 2;
  iVar25 = 0;
  puVar24 = dword_40B68E8;
  do {
    if (word_40B68E4 * 0xc + 0x1a <= iVar25) {
      dword_40B68F4 = uVar5;
      dword_40B68F0 = uVar6;
      sVar10 = word_40B68E0 / 2;
      uVar6 = _strlen(param_1);
      word_40B68D8 = sVar10 - (sword)(uVar6 >> 1);
      word_40B68DA = 0xffef;
      iVar17 = 0;
      cVar1 = *param_1;
      while (cVar1 != '\0') {
        _kmpaint((int)cVar1);
        iVar17 = iVar17 + 1;
        cVar1 = param_1[iVar17];
      }
      _km_flip_cursor();
      dword_40B68F4 = uVar16;
      dword_40B68F0 = uVar5;
      word_40B68DA = 0;
      word_40B68D8 = 0;
      unk_40B6904 = unk_40B6904 & 0xfdff;
      return 0;
    }
    uVar14 = dword_40B6960;
    if ((((iVar25 == 0) || (iVar25 == 0x16)) || (word_40B68E4 * 0xc + 0x19 == iVar25)) ||
       ((uVar8 = uVar3, uVar11 = uVar5, uVar15 = uVar4, 0x12 < iVar25 - 2U &&
        ((uVar14 = uVar3, iVar25 == 1 ||
         (uVar8 = uVar16, uVar11 = uVar16, uVar15 = uVar16, uVar14 = uVar4, iVar25 == 0x15)))))) {
      uVar8 = uVar14;
      uVar11 = uVar14;
      uVar15 = uVar14;
    }
    puVar18 = (uint *)(dword_40B6940 * (iVar25 + -0x18 + word_40B68DC * 0xc) +
                      (iVar17 - 0x60 / uVar2));
    uVar13 = (undefined2)uVar11;
    if (_km_coni == 2) {
      _adb_watchdog(0);
      puVar21 = (undefined2 *)((int)puVar18 + 0xe);
      if (puVar24 == (uint *)0x0) {
        *puVar21 = dword_40B6960._2_2_;
        *(sword *)(puVar18 + 4) = (sword)uVar8;
        puVar21 = (undefined2 *)((int)puVar18 + 0x12);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar21 = uVar13;
          puVar21 = puVar21 + 1;
        }
        *puVar21 = (sword)uVar15;
        puVar21[1] = dword_40B6960._2_2_;
      }
      else {
        *(undefined2 *)puVar24 = *puVar21;
        *puVar21 = dword_40B6960._2_2_;
        *(undefined2 *)((int)puVar24 + 2) = *(undefined2 *)(puVar18 + 4);
        *(sword *)(puVar18 + 4) = (sword)uVar8;
        puVar21 = (undefined2 *)((int)puVar18 + 0x12);
        puVar18 = puVar24 + 1;
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *(undefined2 *)puVar18 = *puVar21;
          *puVar21 = uVar13;
          puVar21 = puVar21 + 1;
          puVar18 = (uint *)((int)puVar18 + 2);
        }
        *(undefined2 *)puVar18 = *puVar21;
        *puVar21 = (sword)uVar15;
        puVar24 = puVar18 + 1;
        *(undefined2 *)((int)puVar18 + 2) = puVar21[1];
        puVar21[1] = dword_40B6960._2_2_;
      }
loc_406FD50:
      _adb_watchdog(1);
    }
    else if ((int)_km_coni < 3) {
      if (_km_coni == 1) {
        _adb_watchdog(0);
        puVar22 = puVar18 + 7;
        if (puVar24 == (uint *)0x0) {
          *puVar22 = dword_40B6960;
          puVar18[8] = uVar8;
          puVar18 = puVar18 + 9;
          for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
            *puVar18 = uVar11;
            puVar18 = puVar18 + 1;
          }
          *puVar18 = uVar15;
          puVar18[1] = dword_40B6960;
        }
        else {
          *puVar24 = *puVar22;
          *puVar22 = dword_40B6960;
          puVar24[1] = puVar18[8];
          puVar18[8] = uVar8;
          puVar18 = puVar18 + 9;
          puVar22 = puVar24 + 2;
          for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
            *puVar22 = *puVar18;
            *puVar18 = uVar11;
            puVar18 = puVar18 + 1;
            puVar22 = puVar22 + 1;
          }
          *puVar22 = *puVar18;
          *puVar18 = uVar15;
          puVar24 = puVar22 + 2;
          puVar22[1] = puVar18[1];
          puVar18[1] = dword_40B6960;
        }
        goto loc_406FD50;
      }
    }
    else if (_km_coni == 4) {
      puVar20 = (undefined *)((int)puVar18 + 7);
      if (puVar24 == (uint *)0x0) {
        *puVar20 = (undefined)dword_40B6960;
        *(char *)(puVar18 + 2) = (char)uVar8;
        puVar20 = (undefined *)((int)puVar18 + 9);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar20 = (char)uVar11;
          puVar20 = puVar20 + 1;
        }
        *puVar20 = (char)uVar15;
        puVar20[1] = (undefined)dword_40B6960;
      }
      else {
        *(undefined *)puVar24 = *puVar20;
        *puVar20 = (undefined)dword_40B6960;
        *(undefined *)((int)puVar24 + 1) = *(undefined *)(puVar18 + 2);
        *(char *)(puVar18 + 2) = (char)uVar8;
        puVar20 = (undefined *)((int)puVar18 + 9);
        puVar23 = (undefined *)((int)puVar24 + 2);
        for (iVar9 = 9; iVar9 < word_40B68E0 * 8 + 0xf; iVar9 = iVar9 + 1) {
          *puVar23 = *puVar20;
          *puVar20 = (char)uVar11;
          puVar20 = puVar20 + 1;
          puVar23 = puVar23 + 1;
        }
        *puVar23 = *puVar20;
        *puVar20 = (char)uVar15;
        puVar24 = (uint *)(puVar23 + 2);
        puVar23[1] = puVar20[1];
        puVar20[1] = (undefined)dword_40B6960;
      }
    }
    else if (_km_coni == 0x10) {
      puVar22 = puVar24;
      if (puVar24 != (uint *)0x0) {
        puVar22 = puVar24 + 1;
        *puVar24 = *puVar18;
      }
      puVar19 = puVar18 + 1;
      *puVar18 = uVar8 & 0x30000 |
                 CONCAT22((word)(dword_40B6960 >> 0x10) & 0xc | (word)(*puVar18 >> 0x10) & 0xfff0,
                          uVar13);
      iVar9 = 1;
      puVar24 = puVar19;
      puVar18 = puVar22;
      if (1 < word_40B68E0 + 3 >> 1) {
        do {
          puVar22 = puVar18;
          if (puVar18 != (uint *)0x0) {
            puVar22 = puVar18 + 1;
            *puVar18 = *puVar24;
          }
          puVar19 = puVar24 + 1;
          *puVar24 = uVar11;
          iVar9 = iVar9 + 1;
          puVar24 = puVar19;
          puVar18 = puVar22;
        } while (iVar9 < word_40B68E0 + 3 >> 1);
      }
      puVar24 = puVar22;
      if (puVar22 != (uint *)0x0) {
        puVar24 = puVar22 + 1;
        *puVar22 = *puVar19;
      }
      *puVar19 = uVar15 & 0xc0000000 | dword_40B6960 & 0x30000000 | *puVar19 & 0xfffffff;
    }
    iVar25 = iVar25 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2072 start=0x406fe0e */

void _km_big(void)

{
  if ((unk_40B6904 & 0x10) == 0) {
    word_40B68E2 = 0x50;
    word_40B68E6 = 0x28;
    _kmem_alloc_wired(_kernel_map,&dword_40B68EC,(0xa60 / _km_coni) * 0x1fe);
    unk_40B6904 = unk_40B6904 | 0x10;
    dword_40B68E8 = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2073 start=0x406fe72 */

undefined4 _kmrestore(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined2 *puVar9;
  sword sVar10;
  
  if ((unk_40B6904 & 8) != 0) {
    if (dword_40B68E8 != (undefined4 *)0x0) {
      iVar6 = dword_40B6980 + (uint)((int)word_40B68DE << 5) / _km_coni;
      uVar1 = _km_coni * 2;
      iVar5 = 0;
      puVar4 = dword_40B68E8;
      if (0 < word_40B68E4 * 0xc + 0x1a) {
        do {
          puVar7 = (undefined4 *)
                   (dword_40B6940 * (word_40B68DC * 0xc + -0x18 + iVar5) + (iVar6 - 0x60 / uVar1));
          if (_km_coni == 2) {
            iVar2 = 7;
            puVar3 = puVar4;
            puVar9 = (undefined2 *)((int)puVar7 + 0xe);
            if (7 < word_40B68E0 * 8 + 0x11) {
              do {
                puVar4 = (undefined4 *)((int)puVar3 + 2);
                *puVar9 = *(undefined2 *)puVar3;
                iVar2 = iVar2 + 1;
                puVar3 = puVar4;
                puVar9 = puVar9 + 1;
              } while (iVar2 < word_40B68E0 * 8 + 0x11);
            }
          }
          else if ((int)_km_coni < 3) {
            if (_km_coni == 1) {
              puVar7 = puVar7 + 7;
              for (iVar2 = 7; iVar2 < word_40B68E0 * 8 + 0x11; iVar2 = iVar2 + 1) {
                *puVar7 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar7 = puVar7 + 1;
              }
            }
          }
          else if (_km_coni == 4) {
            iVar2 = 7;
            puVar3 = puVar4;
            puVar8 = (undefined *)((int)puVar7 + 7);
            if (7 < word_40B68E0 * 8 + 0x11) {
              do {
                puVar4 = (undefined4 *)((int)puVar3 + 1);
                *puVar8 = *(undefined *)puVar3;
                iVar2 = iVar2 + 1;
                puVar3 = puVar4;
                puVar8 = puVar8 + 1;
              } while (iVar2 < word_40B68E0 * 8 + 0x11);
            }
          }
          else if ((_km_coni == 0x10) &&
                  (iVar2 = 0, puVar3 = puVar4, 0 < (word_40B68E0 + 3 >> 1) + 1)) {
            do {
              puVar4 = puVar3 + 1;
              *puVar7 = *puVar3;
              iVar2 = iVar2 + 1;
              puVar3 = puVar4;
              puVar7 = puVar7 + 1;
            } while (iVar2 < (word_40B68E0 + 3 >> 1) + 1);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < word_40B68E4 * 0xc + 0x1a);
      }
    }
    _km_end_access();
    sVar10 = word_40B6906 + -1;
    iVar6 = (int)(sword)(word_40B6906 + -1);
    _cons_tp = *(undefined4 *)(unk_40B6918 + iVar6 * 4);
    unk_40B6904 = *(word *)(unk_40B6908 + iVar6 * 2) & 8 | unk_40B6904 & 0xfff7;
    word_40B6906 = sVar10;
    if ((unk_40B6908[iVar6 * 2] & 4) != 0) {
      _vidResumeAnimation();
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2074 start=0x4070056 */

int _kmioctl(undefined4 param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if (param_2 == 0x20006b02) {
    if (((word_40B6938 != 0) && ((param_4 & 0xa0000000) != 0)) &&
       (sVar2 = word_40B6938 + -1, bVar5 = word_40B6938 == 1, word_40B6938 = sVar2, bVar5)) {
      _kmrestore();
      _alert_lock_screen(0);
    }
  }
  else if (param_2 < 0x20006b03) {
    if (param_2 == -0x7ff78b99) {
      return 0x16;
    }
    if (-0x7ff78b99 < param_2) {
      if (param_2 == -0x7ff394fb) {
        iVar3 = _km_drawrect(param_3);
        return iVar3;
      }
      if (param_2 == -0x7ff394fa) {
        iVar3 = _km_eraserect(param_3);
        return iVar3;
      }
loc_4070260:
      iVar3 = (**(code **)(DAT_40ae4bc + byte_40B6841 * 0x30))(_cons,param_2,param_3,param_4);
      if (-1 < iVar3) {
        return iVar3;
      }
      iVar3 = _ttioctl(_cons,param_2,param_3,param_4);
      if (iVar3 < 0) {
        return 0x19;
      }
      return iVar3;
    }
    if (param_2 == -0x7ffb94f9) {
      _km_send(0xc5,*param_3 << 0x10);
    }
    else {
      if (param_2 != -0x7ffb94f7) goto loc_4070260;
      uVar1 = *param_3;
      if (uVar1 == 1) {
        _vidSuspendAnimation();
      }
      else if ((int)uVar1 < 2) {
        if (uVar1 != 0) {
          return 0x16;
        }
        _vidStopAnimation();
      }
      else {
        if (uVar1 != 2) {
          return 0x16;
        }
        _vidResumeAnimation();
      }
    }
  }
  else if (param_2 == 0x40046b04) {
    iVar3 = _suser();
    if (iVar3 == 0) {
      return 0xd;
    }
    *param_3 = (int)(sword)unk_40B6904;
  }
  else if (param_2 < 0x40046b05) {
    if (param_2 == 0x20006b03) {
      if (*_pmsgbuf == 0x63061) {
        piVar4 = (int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc);
        do {
          if (*(char *)piVar4 != '\0') {
            if (*(char *)piVar4 == '\n') {
              _kmpaint(0xd);
            }
            _kmpaint((int)*(char *)piVar4);
          }
          piVar4 = (int *)((int)piVar4 + 1);
          if (_pmsgbuf + 0x400 <= piVar4) {
            piVar4 = _pmsgbuf + 3;
          }
        } while ((int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc) != piVar4);
      }
    }
    else {
      if (param_2 != 0x20006b08) goto loc_4070260;
      unk_40B6904 = unk_40B6904 & 0xfff7;
    }
  }
  else if (param_2 == 0x40046b0a) {
    iVar3 = _suser();
    if (iVar3 == 0) {
      return 0xd;
    }
    *param_3 = (uint)((unk_40B6904 & 8) != 0);
  }
  else {
    if (param_2 != 0x40086b0b) goto loc_4070260;
    *(undefined2 *)((int)param_3 + 2) = word_40B68E0;
    *(undefined2 *)param_3 = word_40B68E4;
    *(undefined2 *)(param_3 + 1) = uRam040b6946;
    *(undefined2 *)((int)param_3 + 6) = word_40B694E;
  }
  return 0;
}

