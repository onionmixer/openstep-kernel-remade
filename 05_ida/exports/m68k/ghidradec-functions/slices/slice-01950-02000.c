/* GHIDRADEC_FUNCTION index=1950 start=0x40678ce */

void _evinit(void)

{
  _nbic_bus_enable();
  _km_send(0xc5,0xef000000);
  _km_send(0xc5,0);
  _mon_send(0xc6,0x1fffff1);
  _install_scanned_intr(0x23b,sub_40682E2,0);
  _install_scanned_intr(0x1f70,_call_nmi,0);
  if (_dma_chip != 0x139) {
    _install_scanned_intr(0x1e71,_call_nmi,0);
  }
  _install_scanned_intr(0x33a,_evintr,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1951 start=0x4067960 */

undefined4 _evopen(void)

{
  undefined4 uVar1;
  
  *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) & 0xf7;
  if ((unk_40B6904 & 1) == 0) {
    _kminit();
  }
  if (dword_40B4F5A == 0) {
    dword_40B4F5A = 1;
    _kernel_thread(_kernel_task,sub_40683B6);
  }
  if (_evOpenCalled == 0) {
    unk_40B6904 = unk_40B6904 & 0xfff7;
    word_40B6906 = 0;
    word_40B6938 = 0;
    dword_40B4F5E = 0;
    _eventPort = 0;
    _evOpenCalled = 1;
    _evRetryMask = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1952 start=0x40679ec */

undefined4 _evclose(void)

{
  undefined4 uVar1;
  
  if (_evOpenCalled == 0) {
    uVar1 = 6;
  }
  else {
    _evOpenCalled = 0;
    _eventsOpen = 0;
    if (_autoDimmed != 0) {
      _UndoAutoDim();
    }
    if (dword_40B4F5E != 0) {
      _thread_deallocate(dword_40B4F5E);
    }
    dword_40B4F5E = 0;
    _TermMouse();
    if (dword_40B4F6A != 0) {
      _kmem_free(_kernel_map,dword_40B4F6A,~_page_mask & _page_mask + dword_40B4F66);
    }
    if (_evScreen != 0) {
      _kfree(_evScreen,_evScreenSize);
    }
    _screens = 0;
    _evScreen = 0;
    _evScreenSize = 0;
    _evg = 0;
    dword_40B4F6A = 0;
    _eventTask = 0;
    if (_eventPort != 0) {
      _port_release(_eventPort);
      _eventPort = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1953 start=0x4067abe */

undefined4 _evselect(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    if (_evg[1] != *_evg) {
      return 1;
    }
    if (dword_40B4F5E == 0) {
      dword_40B4F5E = _active_threads;
      _thread_reference(_active_threads);
    }
    else if (dword_40B4F5E != _active_threads) {
      _printf(aDoubleSelect);
      return 0xffffffff;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1954 start=0x4067b36 */

uint _evmmap(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uStack_20;
  code *pcStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined *puStack_10;
  
  puVar5 = (undefined4 *)&stack0xfffffff4;
  if (_eventsOpen == 0) {
    dword_40B4F66 = _totalShmemSize;
    puStack_10 = (undefined *)(~_page_mask & _page_mask + _totalShmemSize);
    if (puStack_10 <= param_2) {
      return 0xffffffff;
    }
    puStack_14 = &dword_40B4F6A;
    uStack_18 = _kernel_map;
    pcStack_1c = (code *)0x4067b86;
    iVar2 = _kmem_alloc_wired();
    piVar1 = dword_40B4F6A;
    if (iVar2 != 0) {
      puStack_10 = aEvNoSpaceForSh;
                    /* WARNING: Subroutine does not return */
      puStack_14 = (undefined4 *)0x4067b9a;
      _panic();
    }
    _eop = dword_40B4F6A;
    *dword_40B4F6A = 8;
    piVar1[1] = *piVar1 + 0xcca;
    _evg = (int)piVar1 + *piVar1;
    _evs = piVar1[1] + (int)piVar1;
    *(undefined *)(_evg + 0x45) = 1;
    *(undefined *)(_evg + 0x46) = 1;
    dword_40B4F92 = _evg;
    *(undefined2 *)(_evg + 0x48) = 0x50;
    _waitFrameRate = 5;
    _waitSustain = 0x14;
    _waitSusTime = 0;
    dword_40B4FAE = 0x50;
    dword_40B4F92 = dword_40B4F92 + 0x14;
    dword_40B4F96 = _process_mouse_event;
    dword_40B4F72 = &_keySema;
    puStack_10 = (undefined *)0x4067c34;
    iVar2 = _adb_keybd_present();
    if (iVar2 == 0) {
      dword_40B4F76 = _process_kbd_event;
    }
    else {
      dword_40B4F76 = _process_adb_event;
    }
    puStack_10 = (undefined *)dword_40B4FAE;
    puStack_14 = (undefined4 *)0x4067c5a;
    _InitMouse();
    puStack_14 = (undefined4 *)0x0;
    uStack_18 = 0x4067c62;
    _InitKbd();
    _eventsOpen = 1;
    uStack_18 = 0;
    pcStack_1c = _evvert;
    puVar5 = &uStack_20;
    uStack_20 = 2;
    _callout_dispatch();
    _eventTask = *(undefined4 *)(_active_threads + 0xc);
  }
  *(uint *)((int)puVar5 + -4) = (int)dword_40B4F6A + param_2;
  *(undefined4 *)((int)puVar5 + -8) = 0x4067c98;
  uVar3 = _pmap_kernel();
  *(undefined4 *)((int)puVar5 + -8) = uVar3;
  *(undefined4 *)((int)puVar5 + -0xc) = 0x4067ca0;
  uVar4 = _pmap_resident_extract();
  return uVar4 >> (_page_shift & 0x3f);
}
/* GHIDRADEC_FUNCTION index=1955 start=0x4067cb4 */

void _ev_m_intr(undefined4 *param_1)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  undefined *puVar4;
  
  if (_eventsOpen != 0) {
    _curEvent = *param_1;
    sVar1 = *_evg;
    sVar2 = _evg[1];
    if (dword_40B4F8E < 5) {
      *(undefined4 *)(DAT_40b4f9a + dword_40B4F8E * 4) = _curEvent;
      dword_40B4F8E = dword_40B4F8E + 1;
    }
    if ((dword_40B4F8E != 0) && (*dword_40B4F92 == 0)) {
      iVar3 = 0;
      if (0 < dword_40B4F8E) {
        puVar4 = DAT_40b4f9a;
        do {
          (*dword_40B4F96)(puVar4);
          puVar4 = puVar4 + 4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < dword_40B4F8E);
      }
      dword_40B4F8E = 0;
    }
    if (((sVar2 == sVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
      _evnewevents();
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1956 start=0x4067d6c */

void _ev_k_intr(undefined4 *param_1)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  undefined *puVar4;
  
  if (_eventsOpen == 0) {
    _kmintr_process(param_1);
  }
  else {
    _curEvent = *param_1;
    sVar1 = *_evg;
    sVar2 = _evg[1];
    if (dword_40B4F6E < 5) {
      *(undefined4 *)(DAT_40b4f7a + dword_40B4F6E * 4) = _curEvent;
      dword_40B4F6E = dword_40B4F6E + 1;
    }
    if ((dword_40B4F6E != 0) && (*dword_40B4F72 == 0)) {
      iVar3 = 0;
      if (0 < dword_40B4F6E) {
        puVar4 = DAT_40b4f7a;
        do {
          (*dword_40B4F76)(puVar4);
          puVar4 = puVar4 + 4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < dword_40B4F6E);
      }
      dword_40B4F6E = 0;
    }
    if (((sVar2 == sVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
      _evnewevents();
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1957 start=0x4067e2e */

void _evintr(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  bool bVar4;
  
  _curEvent = *(uint *)(_slot_id + 0x200e008);
  if ((((_curEvent & 0x50000000) == 0x40000000) && (_sound_active == 0)) && (_reconnect != 0)) {
    _km_send(0xc5,0xef000000);
    return;
  }
  uVar1 = (*(uint *)(_slot_id + 0x200e000) & 0xffffff) >> 0x10;
  if ((uVar1 & 0x20) != 0) {
    *(byte *)(_slot_id + 0x200e001) = *(byte *)(_slot_id + 0x200e001) | 0x20;
    _AllKeysUp();
    return;
  }
  if ((uVar1 & 0x40) == 0) {
    _printf(a0xXSpuriousKey,*(uint *)(_slot_id + 0x200e000));
    return;
  }
  if (((int)_curEvent >> 0x18 & 0xfU) == 0xf) {
    return;
  }
  if ((_curEvent & 0x40000000) != 0) {
    return;
  }
  if (((int)_curEvent >> 0x18 & 1U) == 0) {
    if (_eventsOpen == 0) {
      _kmintr_process(&_curEvent);
      if (((_intr_mask & 4) == 0) && ((*_intrstat & 4) == 0)) {
        *_intrmask = *_intrmask | 4;
        _intr_mask = _intr_mask | 4;
      }
      goto loc_4068062;
    }
    bVar4 = _evg[1] != *_evg;
    if ((-1 < (char)_curEvent) && ((unk_40B6904 & 0x100) != 0)) {
      _alert_key = _kybd_process(&_curEvent);
      return;
    }
    if (dword_40B4F6E < 5) {
      *(uint *)(DAT_40b4f7a + dword_40B4F6E * 4) = _curEvent;
      dword_40B4F6E = dword_40B4F6E + 1;
    }
    if ((dword_40B4F6E != 0) && (*dword_40B4F72 == 0)) {
      iVar2 = 0;
      if (0 < dword_40B4F6E) {
        puVar3 = DAT_40b4f7a;
        do {
          (*dword_40B4F76)(puVar3);
          puVar3 = puVar3 + 4;
          iVar2 = iVar2 + 1;
        } while (iVar2 < dword_40B4F6E);
      }
      dword_40B4F6E = 0;
    }
  }
  else {
    if (_eventsOpen == 0) goto loc_4068062;
    bVar4 = _evg[1] != *_evg;
    if (dword_40B4F8E < 5) {
      *(uint *)(DAT_40b4f9a + dword_40B4F8E * 4) = _curEvent;
      dword_40B4F8E = dword_40B4F8E + 1;
    }
    if ((dword_40B4F8E != 0) && (*dword_40B4F92 == 0)) {
      iVar2 = 0;
      if (0 < dword_40B4F8E) {
        puVar3 = DAT_40b4f9a;
        do {
          (*dword_40B4F96)(puVar3);
          puVar3 = puVar3 + 4;
          iVar2 = iVar2 + 1;
        } while (iVar2 < dword_40B4F8E);
      }
      dword_40B4F8E = 0;
    }
  }
  if (((!bVar4) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
    _evnewevents();
  }
loc_4068062:
  if (((_recon_poll == 0) && (_reconnect != 0)) && (_ns_callfree != 0)) {
    _timeout(_reconpoll,0,_hz * 3);
    _recon_poll = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1958 start=0x40680a4 */

int _evvert(void)

{
  sword sVar1;
  sword sVar2;
  sword *psVar3;
  int iVar4;
  undefined *puVar5;
  bool bVar6;
  
  if (_eventsOpen != 0) {
    sVar1 = *_evg;
    sVar2 = _evg[1];
    _DoKbdRepeat();
    if (((_mouseDelX != 0) || (_mouseDelY != 0)) || ((*(uint *)(_evg + 0x1a) & 0x10000) != 0)) {
      _mouse_motion();
    }
    if (((dword_40B4F8E != 0) && (dword_40B4F8E != 0)) && (*dword_40B4F92 == 0)) {
      iVar4 = 0;
      if (0 < dword_40B4F8E) {
        puVar5 = DAT_40b4f9a;
        do {
          (*dword_40B4F96)(puVar5);
          puVar5 = puVar5 + 4;
          iVar4 = iVar4 + 1;
        } while (iVar4 < dword_40B4F8E);
      }
      dword_40B4F8E = 0;
    }
    if (((dword_40B4F6E != 0) && (dword_40B4F6E != 0)) && (*dword_40B4F72 == 0)) {
      iVar4 = 0;
      if (0 < dword_40B4F6E) {
        puVar5 = DAT_40b4f7a;
        do {
          (*dword_40B4F76)(puVar5);
          puVar5 = puVar5 + 4;
          iVar4 = iVar4 + 1;
        } while (iVar4 < dword_40B4F6E);
      }
      dword_40B4F6E = 0;
    }
    if (((sVar2 == sVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
      _evnewevents();
    }
    if (_waitSusTime != 0) {
      _waitSusTime = _waitSusTime + -1;
    }
    if ((*(char *)((int)_evg + 0x47) == '\0') && (*(int *)(_evg + 10) == 0)) {
      if ((*(int *)(_evg + 0x1e) != *(int *)(_evg + 0x1c)) &&
         ((int)_evg[0x24] < *(int *)(_evg + 8) - *(int *)(_evg + 0x1c))) {
        *(undefined *)(_evg + 0x22) = 1;
      }
      if (((*(char *)((int)_evg + 0x45) == '\0') || (*(char *)(_evg + 0x23) == '\0')) ||
         (*(char *)(_evg + 0x22) == '\0')) {
        if ((*(int *)(_evg + 0x20) != 0) && (_waitSusTime == 0)) {
          _HideWaitCursor();
        }
      }
      else if (*(int *)(_evg + 0x20) == 0) {
        _ShowWaitCursor();
      }
      if ((*(int *)(_evg + 0x20) != 0) &&
         (sVar1 = _waitFrameTime + -1, bVar6 = _waitFrameTime == 1, _waitFrameTime = sVar1, bVar6))
      {
        _AnimateWaitCursor();
      }
    }
    if (((_intr_mask & 4) == 0) && ((*_intrstat & 4) == 0)) {
      *_intrmask = *_intrmask | 4;
      _intr_mask = _intr_mask | 4;
    }
    if ((_autoDimTime < *(int *)(_evg + 8)) && (_autoDimmed == 0)) {
      _DoAutoDim();
    }
    if (_evRetryMask != 0) {
      _evretry();
    }
    psVar3 = _evg;
    *(int *)(_evg + 8) = *(int *)(_evg + 8) + 1;
    if (*(int *)(psVar3 + 8) == 0) {
      *(int *)(psVar3 + 8) = *(int *)(psVar3 + 8) + 1;
    }
  }
  return _eventsOpen;
}
/* GHIDRADEC_FUNCTION index=1959 start=0x4068456 */

void _evnewevents(void)

{
  if (dword_40B4F5E != 0) {
    _selwakeup(dword_40B4F5E,0);
    _thread_deallocate_interrupt(dword_40B4F5E);
    dword_40B4F5E = 0;
  }
  if (_eventPort != 0) {
    dword_40B4F62 = 1;
    _thread_wakeup_prim(&_eventMsg,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1960 start=0x40684a6 */

void _LLEventPost(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  sword *psVar1;
  sword *psVar2;
  sword *psVar3;
  int iVar4;
  sword *psVar5;
  sword sVar6;
  sword sVar7;
  int iVar8;
  
  iVar4 = *(int *)(_evg + 8);
  psVar1 = _evg + *_evg * 0x14 + 0x25;
  psVar2 = _evg + _evg[2] * 0x14 + 0x25;
  psVar3 = _evg + _evg[1] * 0x14 + 0x25;
  if ((1 << (param_1 & 0x1f) & 0x1ffeU) != 0) {
    if (_autoDimmed == 0) {
      _autoDimTime = _autoDimPeriod + iVar4;
    }
    else {
      _UndoAutoDim();
    }
  }
  psVar5 = _evg;
  sVar7 = (sword)param_2;
  sVar6 = (sword)((uint)param_2 >> 0x10);
  if (((((*(byte *)((int)_evg + 0x33) & 2) == 0) && (psVar3 != psVar1)) && (psVar2[1] == 0)) &&
     ((param_1 == *(uint *)(psVar2 + 2) && ((1 << (param_1 & 0x1f) & 0x2e0U) != 0)))) {
    *(int *)(psVar2 + 4) = (int)sVar6;
    *(int *)(psVar2 + 6) = (int)sVar7;
    *(int *)(psVar2 + 8) = iVar4;
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *(undefined4 *)(psVar2 + 0xe) = *param_3;
    *(undefined4 *)(psVar2 + 0x10) = param_3[1];
    *(undefined4 *)(psVar2 + 0x12) = param_3[2];
    return;
  }
  if (*_evg == *psVar3) {
    return;
  }
  *(uint *)(psVar3 + 2) = param_1;
  *(int *)(psVar3 + 4) = (int)sVar6;
  *(int *)(psVar3 + 6) = (int)sVar7;
  *(undefined4 *)(psVar3 + 10) = *(undefined4 *)(psVar5 + 6);
  *(int *)(psVar3 + 8) = iVar4;
  psVar3[0xc] = 0;
  psVar3[0xd] = 0;
  if (param_3 != (undefined4 *)0x0) {
    *(undefined4 *)(psVar3 + 0xe) = *param_3;
    *(undefined4 *)(psVar3 + 0x10) = param_3[1];
    *(undefined4 *)(psVar3 + 0x12) = param_3[2];
  }
  psVar1 = _evg;
  if (param_1 == 2) {
    psVar3[0xf] = _leftENum;
    _leftENum = 0;
  }
  else if ((int)param_1 < 3) {
    if (param_1 == 1) {
      do {
        psVar1[3] = psVar1[3] + 1;
      } while (psVar1[3] == 0);
      _leftENum = _evg[3];
      psVar3[0xf] = _leftENum;
    }
  }
  else if (param_1 == 3) {
    do {
      psVar1[3] = psVar1[3] + 1;
    } while (psVar1[3] == 0);
    _rightENum = _evg[3];
    psVar3[0xf] = _rightENum;
  }
  else if (param_1 == 4) {
    psVar3[0xf] = _rightENum;
    _rightENum = 0;
  }
  if ((1 << (param_1 & 0x1f) & 0x66U) != 0) {
    *(undefined *)(psVar3 + 0x12) = _lastPressure;
  }
  if ((1 << (param_1 & 0x1f) & 0x1eU) != 0) {
    if (iVar4 - _clickTime <= _clickTimeThresh) {
      iVar8 = (int)sVar6 - (int)_clickLoc._0_2_;
      if (iVar8 < 0) {
        iVar8 = -iVar8;
      }
      if (iVar8 <= _clickSpaceThresh) {
        iVar8 = (int)sVar7 - (int)_clickLoc._2_2_;
        if (iVar8 < 0) {
          iVar8 = -iVar8;
        }
        if (iVar8 <= word_40C3316) {
          if ((param_1 == 1) || (param_1 == 3)) {
            iVar8 = _clickState + 1;
            _clickState = _clickState + 1;
            _clickTime = iVar4;
            *(int *)(psVar3 + 0x10) = iVar8;
          }
          else {
            *(int *)(psVar3 + 0x10) = _clickState;
          }
          goto loc_40686F8;
        }
      }
    }
    if ((param_1 == 1) || (param_1 == 3)) {
      _clickLoc = param_2;
      _clickState = 1;
      _clickTime = iVar4;
      psVar3[0x10] = 0;
      psVar3[0x11] = 1;
    }
    else {
      psVar3[0x10] = 0;
      psVar3[0x11] = 0;
    }
  }
loc_40686F8:
  psVar1 = _evg;
  _evg[1] = *psVar3;
  psVar1[2] = *psVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=1961 start=0x4068710 */

undefined4 _evioctl(undefined4 param_1,int param_2,int *param_3)

{
  bool bVar1;
  sword sVar2;
  sword *psVar3;
  int iVar4;
  
  psVar3 = _evg;
  if ((_eventsOpen == 0) && (param_2 != -0x3fe79afc)) {
    return 6;
  }
  bVar1 = false;
  if ((_eventsOpen != 0) && (_evg[1] != *_evg)) {
    bVar1 = true;
  }
  sVar2 = _leftENum;
  if (param_2 != -0x3ffb9abe) {
    if (param_2 < -0x3ffb9abd) {
      if (param_2 == -0x7ffb9abc) {
        _MoveTheCursor(*param_3,0);
      }
      else if (param_2 < -0x7ffb9abb) {
        if ((param_2 != -0x7ffb9aff) ||
           (iVar4 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),*param_3,6,0,param_3),
           iVar4 == 0)) {
          return 0x16;
        }
        if (_eventPort != 0) {
          _port_release(_eventPort);
        }
        dword_40B123E = *param_3;
        _eventPort = dword_40B123E;
      }
      else {
        if (param_2 != -0x7feb9afe) {
          return 0x16;
        }
        _LLEventPost(*param_3,param_3[1],param_3 + 2);
      }
      goto loc_4068864;
    }
    if (param_2 == -0x3fe79afc) {
      _evsetup_screens(param_3);
      goto loc_4068864;
    }
    if (-0x3fe79afc < param_2) {
      if (param_2 == 0x20006546) {
        _StartCursor();
      }
      else {
        if (param_2 != 0x40046545) {
          return 0x16;
        }
        *(sword *)param_3 = _evg[0xc];
        *(sword *)((int)param_3 + 2) = psVar3[0xd];
      }
      goto loc_4068864;
    }
    sVar2 = _rightENum;
    if (param_2 != -0x3ffb9abd) {
      return 0x16;
    }
  }
  *param_3 = -(int)-((int)sVar2 == *param_3);
loc_4068864:
  if (((!bVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
    _evnewevents();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1962 start=0x4068894 */

undefined4 _evsioctl(undefined4 param_1,int param_2,int *param_3)

{
  sword sVar1;
  sword sVar2;
  sword *psVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  sword sVar7;
  
  if (_eventsOpen == 0) {
    return 6;
  }
  sVar1 = *_evg;
  sVar2 = _evg[1];
  if (param_2 == -0x3ff39a96) {
    uVar5 = sub_4068F24(param_3);
    return uVar5;
  }
  if (param_2 < -0x3ff39a95) {
    if (param_2 == -0x7ffb9aaf) {
      _buttonsTied = *param_3;
    }
    else if (param_2 < -0x7ffb9aae) {
      if (param_2 == -0x7ffb9ad4) {
        _waitFrameRate = 0;
        if (1 < *param_3) {
          _waitFrameRate = (sword)*param_3;
        }
      }
      else if (param_2 < -0x7ffb9ad3) {
        if (param_2 == -0x7ffb9af4) {
          if (*param_3 - 1U < 1000) {
            _initialKeyRepeat = *param_3;
          }
        }
        else if (param_2 < -0x7ffb9af3) {
          if (param_2 != -0x7ffb9af6) {
            return 0x16;
          }
          if (*param_3 - 1U < 1000) {
            _keyRepeat = *param_3;
          }
        }
        else if (param_2 == -0x7ffb9ad8) {
          sVar7 = 0;
          if (-1 < *param_3) {
            sVar7 = (sword)*param_3;
          }
          _evg[0x24] = sVar7;
        }
        else {
          if (param_2 != -0x7ffb9ad6) {
            return 0x16;
          }
          _waitSustain = 0;
          if (-1 < *param_3) {
            _waitSustain = (sword)*param_3;
          }
        }
      }
      else if (param_2 == -0x7ffb9ab8) {
        _clickSpaceThresh = *(undefined2 *)param_3;
        word_40C3316 = (undefined2)*param_3;
      }
      else if (param_2 < -0x7ffb9ab7) {
        if (param_2 != -0x7ffb9aba) {
          return 0x16;
        }
        _clickTimeThresh = *param_3;
      }
      else if (param_2 == -0x7ffb9ab3) {
        _autoDimTime = *param_3 + (_autoDimTime - _autoDimPeriod);
        _autoDimPeriod = *param_3;
      }
      else {
        if (param_2 != -0x7ffb9ab1) {
          return 0x16;
        }
        _mouseHandedness = *param_3;
      }
    }
    else if (param_2 == -0x7ff79af2) {
      uVar5 = _kalloc(*param_3);
      iVar4 = _curMapLen;
      iVar6 = _copyinmsg(param_3[1],uVar5,*param_3);
      if ((iVar6 != 0) || (iVar6 = _SetKeyMapping(uVar5,*param_3), iVar6 == 0)) {
        _kfree(uVar5,*param_3);
        return 0x16;
      }
      if (_mapNotDefault == 0) {
        _mapNotDefault = 1;
      }
      else {
        _kfree(iVar6,iVar4);
      }
    }
    else if (param_2 < -0x7ff79af1) {
      if (param_2 == -0x7ffb9a9c) {
        _curBright = _SetCurBrightness(*param_3);
        _RecordBrightness();
      }
      else if (param_2 < -0x7ffb9a9b) {
        if (param_2 != -0x7ffb9aaa) {
          return 0x16;
        }
        if (*param_3 == 0) {
          _UndoAutoDim();
          _autoDimTime = _autoDimPeriod + *(int *)(_evg + 8);
        }
        else {
          _autoDimTime = *(int *)(_evg + 8);
          _DoAutoDim();
        }
      }
      else if (param_2 == -0x7ffb9a9a) {
        _SetAttenuation(3,*param_3);
        _snd_device_vol_set();
        _snd_device_vol_save();
      }
      else {
        if (param_2 != -0x7ffb9a98) {
          return 0x16;
        }
        _dimmedBrightness = *param_3;
        if (_dimmedBrightness < 0) {
          _dimmedBrightness = 0;
        }
        if (0x3d < _dimmedBrightness) {
          _dimmedBrightness = 0x3d;
        }
        if (_autoDimmed != 0) {
          _DoAutoDim();
        }
      }
    }
    else {
      if (param_2 == -0x7feb9afd) {
        _keySema = _keySema + 1;
        *(int *)(_evg + 10) = *(int *)(_evg + 10) + 1;
      }
      else {
        if (-0x7feb9afd < param_2) {
          if (param_2 != -0x7fab9ab6) {
            if (param_2 == -0x3ff79af1) {
              uVar5 = *(undefined4 *)(_curMapping + 0x2d8);
              if (_curMapLen < *param_3) {
                *param_3 = _curMapLen;
              }
              iVar4 = _copyoutmsg(uVar5,param_3[1],*param_3);
              if (iVar4 == 0) goto loc_4068E9E;
            }
            return 0x16;
          }
          psVar3 = _evg;
          psVar3[10] = 0;
          psVar3[0xb] = 1;
          _numMouseScales = *param_3;
          sVar7 = (sword)*param_3;
          while (sVar7 = sVar7 + -1, sVar7 != -1) {
            iVar4 = (int)sVar7;
            (&_mouseScaleThresholds)[iVar4] = *(undefined2 *)((int)param_3 + iVar4 * 2 + 4);
            *(undefined2 *)(_mouseScaleFactors + iVar4 * 2) =
                 *(undefined2 *)((int)param_3 + iVar4 * 2 + 0x2c);
          }
          psVar3 = _evg + 0xb;
          _evg[10] = 0;
          *psVar3 = 0;
          goto loc_4068E9E;
        }
        if (param_2 != -0x7feb9afe) {
          return 0x16;
        }
        _keySema = _keySema + 1;
        *(int *)(_evg + 10) = *(int *)(_evg + 10) + 1;
      }
      _LLEventPost(*param_3,param_3[1],param_3 + 2);
      *(int *)(_evg + 10) = *(int *)(_evg + 10) + -1;
      _keySema = _keySema + -1;
    }
  }
  else if (param_2 == 0x40046549) {
    *(undefined2 *)param_3 = _clickSpaceThresh;
    *(undefined2 *)((int)param_3 + 2) = word_40C3316;
  }
  else if (param_2 < 0x4004654a) {
    if (param_2 == 0x40046510) {
      *param_3 = _curMapLen;
    }
    else if (param_2 < 0x40046511) {
      if (param_2 == 0x2000654c) {
        _ResetMouse();
      }
      else if (param_2 < 0x2000654d) {
        if (param_2 != 0x20006511) {
          return 0x16;
        }
        _ResetKbd();
      }
      else if (param_2 == 0x4004650b) {
        *param_3 = _keyRepeat;
      }
      else {
        if (param_2 != 0x4004650d) {
          return 0x16;
        }
        *param_3 = _initialKeyRepeat;
      }
    }
    else if (param_2 == 0x4004652b) {
      *param_3 = (int)_waitSustain;
    }
    else if (param_2 < 0x4004652c) {
      if (param_2 != 0x40046529) {
        return 0x16;
      }
      *param_3 = (int)_evg[0x24];
    }
    else if (param_2 == 0x4004652d) {
      *param_3 = (int)_waitFrameRate;
    }
    else {
      if (param_2 != 0x40046547) {
        return 0x16;
      }
      *param_3 = _clickTimeThresh;
    }
  }
  else if (param_2 == 0x40046554) {
    *param_3 = _autoDimTime;
  }
  else if (param_2 < 0x40046555) {
    if (param_2 == 0x40046550) {
      *param_3 = _mouseHandedness;
    }
    else if (param_2 < 0x40046551) {
      if (param_2 != 0x4004654e) {
        return 0x16;
      }
      *param_3 = _autoDimPeriod;
    }
    else if (param_2 == 0x40046552) {
      *param_3 = _buttonsTied;
    }
    else {
      if (param_2 != 0x40046553) {
        return 0x16;
      }
      *param_3 = _autoDimmed;
    }
  }
  else if (param_2 == 0x40046567) {
    iVar4 = _vol_r + _vol_l;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 1;
    }
    *param_3 = iVar4 >> 1;
  }
  else if (param_2 < 0x40046568) {
    if (param_2 == 0x40046555) {
      *param_3 = _autoDimTime - *(int *)(_evg + 8);
    }
    else {
      if (param_2 != 0x40046565) {
        return 0x16;
      }
      *param_3 = _curBright;
    }
  }
  else if (param_2 == 0x40046569) {
    *param_3 = _dimmedBrightness;
  }
  else {
    if (param_2 != 0x4054654b) {
      return 0x16;
    }
    iVar4 = 0x14;
    if (_numMouseScales < 0x15) {
      iVar4 = _numMouseScales;
    }
    *param_3 = iVar4;
    sVar7 = (sword)iVar4;
    while (sVar7 = sVar7 + -1, sVar7 != -1) {
      iVar4 = (int)sVar7;
      *(undefined2 *)((int)param_3 + iVar4 * 2 + 4) = (&_mouseScaleThresholds)[iVar4];
      *(undefined2 *)((int)param_3 + iVar4 * 2 + 0x2c) =
           *(undefined2 *)(_mouseScaleFactors + iVar4 * 2);
    }
  }
loc_4068E9E:
  if (((sVar2 == sVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
    _evnewevents();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1963 start=0x4068fa2 */

void _process_kbd_event(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 2) & 0x7f;
  bVar2 = *(byte *)(param_1 + 2) & 0x7f;
  if ((-1 < *(char *)(param_1 + 3)) && (bVar2 != _deviceMods)) {
    _process_device_mods(bVar1);
  }
  if (*(char *)(param_1 + 2) < '\0') {
    _DoKbdEvent(*(byte *)(param_1 + 3) & 0x7f,*(byte *)(param_1 + 3) >> 7 ^ 1,bVar1);
  }
  if ((*(char *)(param_1 + 3) < '\0') && (bVar2 != _deviceMods)) {
    _process_device_mods(bVar1);
  }
  _deviceMods = bVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=1964 start=0x4069026 */

undefined _process_device_mods(byte param_1)

{
  undefined uVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar2 = 1;
  do {
    uVar1 = 0;
    if ((bVar2 & (_deviceMods ^ param_1)) != 0) {
      _deviceMods = bVar2 ^ _deviceMods;
      uVar1 = _DoKbdEvent(*(undefined *)((int)&aQrwtusv + iVar3),-(int)-((bVar2 & _deviceMods) != 0)
                          ,_deviceMods);
    }
    iVar3 = iVar3 + 1;
    bVar2 = bVar2 << 1;
  } while (iVar3 < 7);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1965 start=0x406908c */

void _AlphaLockFeedback(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0x30000;
  }
  _km_send(0xc5,uVar1);
  _adb_keyboard_LED(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1966 start=0x40690bc */

void _process_adb_event(int param_1)

{
  _DoKbdEvent(*(byte *)(param_1 + 3) & 0x7f,*(byte *)(param_1 + 3) >> 7 ^ 1,
              *(byte *)(param_1 + 2) & 0x7f);
  return;
}
/* GHIDRADEC_FUNCTION index=1967 start=0x40690f8 */

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
/* GHIDRADEC_FUNCTION index=1968 start=0x4069156 */

void _DoAutoDim(void)

{
  if (_dimmedBrightness < _curBright) {
    _SetCurBrightness(_dimmedBrightness);
  }
  _autoDimmed = 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1969 start=0x406917c */

void _UndoAutoDim(void)

{
  _SetCurBrightness(_curBright);
  _autoDimTime = _autoDimPeriod + *(int *)(_evg + 0x10);
  _autoDimmed = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1970 start=0x40691ac */

void _RecordBrightness(void)

{
  undefined uStack_24;
  uint uStack_23;
  
  _nvram_check(&uStack_24);
  uStack_23 = uStack_23 & 0xf03fffff | (_curBright & 0x3f) << 0x16;
  _nvram_set(&uStack_24);
  return;
}
/* GHIDRADEC_FUNCTION index=1971 start=0x40691dc */

void _DoBrightnessChange(int param_1)

{
  _curBright = _SetCurBrightness(param_1 + _curBright);
  return;
}
/* GHIDRADEC_FUNCTION index=1972 start=0x40691fc */

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
/* GHIDRADEC_FUNCTION index=1973 start=0x4069250 */

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
/* GHIDRADEC_FUNCTION index=1974 start=0x40693ca */

void _DoSpecialKey(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (_curMapping != 0) {
    if (param_2 == 0) {
      if ((*(byte *)(_curMapping + 0x2ce) == param_1) || (*(byte *)(_curMapping + 0x2cf) == param_1)
         ) {
        _snd_device_vol_save();
      }
      else if ((*(byte *)(_curMapping + 0x2d0) == param_1) ||
              (*(byte *)(_curMapping + 0x2d1) == param_1)) {
        _callout_dispatch(4,_RecordBrightness,0);
      }
    }
    else if ((*(byte *)(_curMapping + 0x2ce) == param_1) ||
            (*(byte *)(_curMapping + 0x2cf) == param_1)) {
      _DoSoundKey(param_1,param_2,param_3);
    }
    else if ((*(byte *)(_curMapping + 0x2d0) == param_1) ||
            (*(byte *)(_curMapping + 0x2d1) == param_1)) {
      if (_autoDimmed != 0) {
        _UndoAutoDim();
      }
      if (*(byte *)(_curMapping + 0x2d0) == param_1) {
        iVar1 = _curBright + 1;
      }
      else {
        iVar1 = _curBright + -1;
      }
      _curBright = _SetCurBrightness(iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1975 start=0x40694da */

undefined4 _SetKeyMapping(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  word wVar8;
  int iVar9;
  sword sVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  undefined2 uStack_2ec;
  byte abStack_2ea [128];
  uint uStack_26a;
  int aiStack_266 [144];
  int iStack_26;
  int iStack_22;
  byte abStack_1e [10];
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar12 = &stack0xfffffffc;
  iVar13 = -1;
  iStack_c = param_1 + param_2;
  iStack_10 = param_1;
  uStack_8 = 1;
  _bzero(&uStack_2ec,0x2dc);
  uStack_26a = 0xffffffff;
  iStack_14 = param_1;
  uStack_8 = sub_40694AE(&iStack_10);
  uStack_2ec = (undefined2)uStack_8;
  iVar2 = sub_40694AE(&iStack_10);
  iVar9 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = sub_40694AE(&iStack_10);
      if (0xf < (int)uVar3) {
        return 0;
      }
      if ((int)uStack_26a < (int)uVar3) {
        uStack_26a = uVar3;
      }
      aiStack_266[uVar3] = iStack_10;
      iVar11 = 0;
      iVar4 = sub_40694AE(&iStack_10);
      if (0 < iVar4) {
        do {
          iVar5 = sub_40694AE(&iStack_10);
          if (0x7f < iVar5) {
            return 0;
          }
          if ((abStack_2ea[iVar5] & 0x10) != 0) {
            return 0;
          }
          abStack_2ea[iVar5] = (byte)uVar3 & 0xf | 0x10 | abStack_2ea[iVar5];
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar4);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar2);
  }
  iVar9 = 0;
  iVar2 = sub_40694AE(&iStack_10);
  do {
    if (iVar9 < iVar2) {
      *(int *)(puVar12 + -0x222) = iStack_10;
      uVar3 = sub_40694AE(&iStack_10);
      if (uVar3 == 0xff) goto loc_406963E;
      abStack_2ea[iVar9] = abStack_2ea[iVar9] | 0x20;
      iVar11 = 0;
      iVar4 = 1;
      if (-1 < (int)uStack_26a) {
        do {
          if ((uVar3 & 1) != 0) {
            iVar4 = iVar4 * 2;
          }
          iVar11 = iVar11 + 1;
          uVar3 = (int)uVar3 >> 1;
        } while (iVar11 <= (int)uStack_26a);
      }
      iVar11 = 0;
      if (0 < iVar4) {
        do {
          iVar5 = sub_40694AE(&iStack_10);
          iVar6 = sub_40694AE(&iStack_10);
          if ((iVar5 == -1) && (iVar13 < iVar6)) {
            iVar13 = iVar6;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar4);
      }
    }
    else {
loc_406963E:
      *(undefined4 *)(puVar12 + -0x222) = 0;
    }
    puVar12 = puVar12 + 4;
    iVar9 = iVar9 + 1;
    if (0x7f < iVar9) {
      iStack_26 = sub_40694AE(&iStack_10);
      iStack_22 = iStack_10;
      if (iVar13 < iStack_26) {
        iVar9 = 0;
        if (0 < iStack_26) {
          do {
            iVar13 = 0;
            iVar2 = sub_40694AE(&iStack_10);
            if (0 < iVar2) {
              do {
                sub_40694AE(&iStack_10);
                sub_40694AE(&iStack_10);
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar2);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iStack_26);
        }
        iVar9 = sub_40694AE(&iStack_10);
        if (iVar9 < 10) {
          if (iVar9 == 0) {
            if (word_40B1256 != 0) {
              return 0;
            }
            iVar9 = 0;
            do {
              abStack_1e[iVar9] = *(byte *)(iVar9 + _curMapping + 0x2ce);
              iVar9 = iVar9 + 1;
            } while (iVar9 < 9);
          }
          else {
            iVar13 = 8;
            do {
              do {
                abStack_1e[iVar13] = 0xff;
                wVar8 = (word)((uint)iVar13 >> 0x10);
                sVar10 = (sword)iVar13 + -1;
                iVar13 = CONCAT22(wVar8,sVar10);
              } while (sVar10 != -1);
              iVar13 = (uint)wVar8 * 0x10000 + -1;
            } while (wVar8 != 0);
            iVar13 = 0;
            if (0 < iVar9) {
              do {
                iVar2 = sub_40694AE(&iStack_10);
                bVar7 = sub_40694AE(&iStack_10);
                if (8 < iVar2) {
                  return 0;
                }
                abStack_1e[iVar2] = bVar7;
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar9);
            }
          }
          iVar9 = 0;
          do {
            if (abStack_1e[iVar9] != 0xff) {
              abStack_2ea[abStack_1e[iVar9]] = abStack_2ea[abStack_1e[iVar9]] | 0x60;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 4);
          uVar1 = *(undefined4 *)(_curMapping + 0x2d8);
          _keySema = _keySema + 1;
          iVar9 = 0;
          do {
            abStack_2ea[iVar9] = unk_40C3336[iVar9] & 0x80 | abStack_2ea[iVar9];
            iVar9 = iVar9 + 1;
          } while (iVar9 < 0x80);
          *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) & 0xffff;
          iVar9 = 0;
          if (uStack_26a < 0x80000000) {
            do {
              _CalcModBit(&uStack_2ec,iVar9);
              iVar9 = iVar9 + 1;
            } while (iVar9 <= (int)uStack_26a);
          }
          _bcopy(&uStack_2ec,&_curMappingStorage,0x2dc);
          _curMapLen = param_2;
          _keySema = _keySema + -1;
          return uVar1;
        }
      }
      return 0;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1976 start=0x40697d4 */

void _CalcModBit(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = _alphaLock;
  uVar1 = 1 << (param_2 + 0x10U & 0x3f);
  uVar4 = ~uVar1 & *(uint *)(_evg + 0xc);
  iVar3 = sub_4069364(param_1,param_2);
  if (iVar3 != 0) {
    uVar4 = uVar1 | uVar4;
  }
  if (param_2 == 1) {
    if (((uVar4 & 0x100000) != 0) && (*(int *)(param_1 + 0x86) == 0)) {
      if ((uVar4 & 0x20000) == 0) {
        if (_keyPressed == 0) {
          _alphaLock = -(int)-(_alphaLock == 0);
        }
      }
      else {
        _keyPressed = 0;
      }
    }
    uVar4 = (int)(uVar4 & 0x20000) >> 1 | _alphaLock << 0x10 | uVar4 & 0xfffeffff;
  }
  else if (param_2 == 0) {
    _alphaLock = (uVar4 & 0x1ffff) >> 0x10;
  }
  if (_alphaLock != uVar2) {
    _AlphaLockFeedback(_alphaLock);
  }
  *(uint *)(_evg + 0xc) = uVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=1977 start=0x40698a8 */

void _DoModCalc(int param_1,int param_2)

{
  byte bVar1;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  bVar1 = *(byte *)(param_1 + 2 + param_2);
  if ((bVar1 & 0x10) != 0) {
    _CalcModBit(param_1,bVar1 & 0xf);
    if ((bVar1 & 0x20) == 0) {
      uStack_8 = (undefined2)param_2;
      uStack_6 = 0;
      uStack_e = 0;
      uStack_a = 0;
      uStack_c = 0;
      uStack_10 = 0;
      _LLEventPost(0xc,*(undefined4 *)(_evg + 0x18),&uStack_10);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1978 start=0x4069916 */

void _DoCharGen(sword *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  sword sVar2;
  int iVar3;
  word wVar4;
  word wVar5;
  int iVar6;
  uint uVar7;
  sword sVar8;
  uint uVar9;
  word *pwVar10;
  byte *pbVar11;
  byte *pbVar12;
  word *pwVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  word wStack_10;
  sword sStack_e;
  word wStack_c;
  word wStack_a;
  sword sStack_8;
  word wStack_6;
  
  _keyPressed = 1;
  sVar2 = *param_1;
  sStack_e = -(sword)-(param_3 == 2);
  sVar8 = (sword)param_2;
  uVar14 = 0xb;
  if (param_3 != 0) {
    uVar14 = 10;
  }
  wVar5 = (word)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10);
  pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
  sStack_8 = sVar8;
  if (pwVar13 != (word *)0x0) {
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar4 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar4 = *pwVar13;
    }
    if (wVar4 != 0) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar4 & 1) != 0) {
            if ((wVar5 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar4 = (sword)wVar4 >> 1;
          wVar5 = (sword)wVar5 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_c = (word)(char)*(byte *)pwVar10;
      wStack_a = (word)(byte)*pwVar10;
    }
    else {
      wStack_c = *pwVar10;
      wStack_a = pwVar10[1];
    }
    pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
    uVar7 = (*(uint *)(_evg + 0xc) & 0x3ffff) >> 0x10;
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar5 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar5 = *pwVar13;
    }
    if ((wVar5 != 0) && (uVar7 != 0)) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar5 & 1) != 0) {
            if ((uVar7 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar5 = (sword)wVar5 >> 1;
          uVar7 = (int)uVar7 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_10 = (word)(char)*(byte *)pwVar10;
      wStack_6 = (word)(byte)*pwVar10;
    }
    else {
      wStack_10 = *pwVar10;
      wStack_6 = pwVar10[1];
    }
    if (wStack_c == 0xffff) {
      pbVar12 = *(byte **)(_curMapping + 0x2ca);
      iVar3 = 0;
      if (wStack_a != 0) {
        do {
          if (sVar2 == 0) {
            pbVar11 = pbVar12 + 1;
            iVar6 = (uint)*pbVar12 * 2;
          }
          else {
            pbVar11 = pbVar12 + 2;
            iVar6 = *(sword *)pbVar12 * 4;
          }
          pbVar12 = pbVar11 + iVar6;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)wStack_a);
      }
      uVar1 = *(undefined4 *)(_evg + 0xc);
      iVar3 = 0;
      if (sVar2 == 0) {
        pwVar13 = (word *)(pbVar12 + 1);
        uVar7 = (uint)*pbVar12;
      }
      else {
        pwVar13 = (word *)(pbVar12 + 2);
        uVar7 = (uint)*(sword *)pbVar12;
      }
      if (0 < (int)uVar7) {
        do {
          if (sVar2 == 0) {
            pwVar10 = (word *)((int)pwVar13 + 1);
            wStack_c = (word)*(byte *)pwVar13;
          }
          else {
            pwVar10 = pwVar13 + 1;
            wStack_c = *pwVar13;
          }
          if (wStack_c == 0xff) {
            wStack_6 = 0;
            sStack_e = 0;
            wStack_a = 0;
            wStack_c = 0;
            wStack_10 = 0;
            if (param_3 != 0) {
              if (sVar2 == 0) {
                pwVar13 = (word *)((int)pwVar10 + 1);
                uVar9 = (uint)*(byte *)pwVar10;
              }
              else {
                pwVar13 = pwVar10 + 1;
                uVar9 = (uint)(sword)*pwVar10;
              }
              *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) | 1 << (uVar9 + 0x10 & 0x3f);
              uVar16 = *(undefined4 *)(_evg + 0x18);
              uVar15 = 0xc;
              sStack_8 = sVar8;
              goto loc_4069B8A;
            }
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              sStack_8 = sVar8;
            }
            else {
              pwVar13 = pwVar10 + 1;
              sStack_8 = sVar8;
            }
          }
          else {
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              wStack_6 = (word)*(byte *)pwVar10;
            }
            else {
              pwVar13 = pwVar10 + 1;
              wStack_6 = *pwVar10;
            }
            uVar16 = *(undefined4 *)(_evg + 0x18);
            uVar15 = uVar14;
loc_4069B8A:
            wStack_10 = wStack_c;
            wStack_a = wStack_6;
            _LLEventPost(uVar15,uVar16,&wStack_10);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)uVar7);
      }
      *(undefined4 *)(_evg + 0xc) = uVar1;
    }
    else {
      _LLEventPost(uVar14,*(undefined4 *)(_evg + 0x18),&wStack_10);
    }
  }
  if ((*(byte *)(_curMapping + 2 + param_2) & 0x40) != 0) {
    _DoSpecialKey(param_2,param_3,*(undefined4 *)(_evg + 0xc));
  }
  if (param_3 == 1) {
    word_40B1252 = uRam040c364a;
    word_40B1254 = sVar8;
  }
  else if ((param_3 == 0) && (param_2 == word_40B1254)) {
    word_40B1252 = 0xffff;
    word_40B1254 = -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1979 start=0x4069c24 */

void _DoKbdEvent(int param_1,int param_2,undefined2 param_3)

{
  byte bVar1;
  
  bVar1 = *(byte *)(_curMapping + 2 + param_1);
  if (param_2 == 0) {
    if (-1 < (char)bVar1) {
      _AllKeysUp();
      return;
    }
    bVar1 = bVar1 & 0x7f;
  }
  else {
    bVar1 = bVar1 | 0x80;
  }
  *(uint *)(_evg + 0xc) = CONCAT22((sword)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10),param_3);
  *(byte *)(_curMapping + 2 + param_1) = bVar1;
  if (param_2 == 0) {
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,0);
    }
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
  }
  else {
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,param_2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1980 start=0x4069ce2 */

void _DoKbdRepeat(void)

{
  sword sVar1;
  bool bVar2;
  
  if (((word_40B1252 != -1) && (_eventsOpen != 0)) &&
     (sVar1 = word_40B1252 + -1, bVar2 = word_40B1252 == 1, word_40B1252 = sVar1, bVar2)) {
    if ((*(byte *)(word_40B1254 + 2 + _curMapping) & 0x20) != 0) {
      _DoCharGen(_curMapping,(int)word_40B1254,2);
    }
    word_40B1252 = sRam040c3652;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1981 start=0x4069d3a */

void _ResetKbd(void)

{
  int iVar1;
  undefined4 unaff_D3;
  
  if (_mapNotDefault == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(_curMapping + 0x2d8);
    unaff_D3 = _curMapLen;
  }
  _InitKbd(1);
  if (iVar1 != 0) {
    _kfree(iVar1,unaff_D3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1982 start=0x4069d84 */

undefined4 _InitKbd(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined uStack_24;
  uint uStack_23;
  
  _mapNotDefault = 0;
  _keyPressed = 0;
  _alphaLock = 0;
  _curMapping = &_curMappingStorage;
  _AlphaLockFeedback(0);
  _initialKeyRepeat = 0x23;
  _keyRepeat = 8;
  word_40B1256 = _adb_keybd_present();
  if (word_40B1256 == 0) {
    uVar2 = 0x34a;
    puVar1 = unk_40AD172;
  }
  else {
    uVar2 = 0x3f0;
    puVar1 = unk_40AD4BC;
  }
  _SetKeyMapping(puVar1,uVar2);
  _AllKeysUp();
  if (param_1 == 0) {
    _nvram_check(&uStack_24);
    _curBright = (uStack_23 & 0xfffffff) >> 0x16;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1983 start=0x4069e12 */

void _AllKeysUp(void)

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  word_40B1254 = 0xffff;
  word_40B1252 = 0xffff;
  if (_curMapping != (sword *)0x0) {
    sVar1 = *_curMapping;
    pbVar7 = *(byte **)(_curMapping + 0x43);
    if (pbVar7 == (byte *)0x0) {
      uVar4 = 0;
      pbVar6 = (byte *)0x0;
    }
    else if (sVar1 == 0) {
      pbVar6 = pbVar7 + 1;
      uVar4 = (uint)*pbVar7;
    }
    else {
      pbVar6 = pbVar7 + 2;
      uVar4 = (uint)*(sword *)pbVar7;
    }
    uVar2 = 0;
    do {
      iVar3 = 0;
      pbVar7 = pbVar6;
      if (0 < (int)uVar4) {
        do {
          if (sVar1 == 0) {
            pbVar8 = pbVar7 + 1;
            uVar5 = (uint)*pbVar7;
          }
          else {
            pbVar8 = pbVar7 + 2;
            uVar5 = (uint)*(sword *)pbVar7;
          }
          if (uVar5 == uVar2) goto loc_4069E8A;
          iVar3 = iVar3 + 1;
          pbVar7 = pbVar8;
        } while (iVar3 < (int)uVar4);
      }
      pbVar7 = (byte *)((int)_curMapping + uVar2 + 2);
      *pbVar7 = *pbVar7 & 0x7f;
loc_4069E8A:
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x80);
  }
  if (_eventsOpen != 0) {
    *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) & 0xffc1ffff;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1984 start=0x4069eb8 */

void _MoveTheCursor(int param_1)

{
  undefined4 uVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = -1;
  if (_screens == 0) {
    return;
  }
  iVar4 = _evScreen + _currentScreen * 0x28;
  if (((((param_1._0_2_ < *(sword *)(iVar4 + 0xc)) || (*(sword *)(iVar4 + 0xe) <= param_1._0_2_)) ||
       (param_1._2_2_ < *(sword *)(iVar4 + 0x10))) || (*(sword *)(iVar4 + 0x12) <= param_1._2_2_))
     && (iVar5 = sub_406AA0C(param_1), iVar5 < 0)) {
    sVar2 = _cursorPin._0_2_;
    if ((_cursorPin._0_2_ <= param_1._0_2_) &&
       (sVar2 = param_1._0_2_, _cursorPin._2_2_ < param_1._0_2_)) {
      sVar2 = _cursorPin._2_2_;
    }
    sVar3 = dword_40C3618._0_2_;
    if ((dword_40C3618._0_2_ <= param_1._2_2_) &&
       (sVar3 = param_1._2_2_, dword_40C3618._2_2_ < param_1._2_2_)) {
      sVar3 = dword_40C3618._2_2_;
    }
    param_1 = CONCAT22(sVar2,sVar3);
  }
  if (param_1 == *(int *)(_evg + 0x18)) {
    return;
  }
  *(int *)(_evg + 0x18) = param_1;
  if (iVar5 < 0) {
    _evdispatch(3,_currentScreen,0);
  }
  else {
    _evdispatch(1,_currentScreen,0);
    uVar6 = *(undefined4 *)(_evScreen + 0xc + iVar5 * 0x28);
    uVar1 = *(undefined4 *)(_evScreen + 0x10 + iVar5 * 0x28);
    _cursorPin._2_2_ = (sword)uVar6;
    _cursorPin._0_2_ = (sword)((uint)uVar6 >> 0x10);
    _cursorPin = CONCAT22(_cursorPin._0_2_,_cursorPin._2_2_ + -1);
    dword_40C3618._2_2_ = (sword)uVar1;
    dword_40C3618._0_2_ = (sword)((uint)uVar1 >> 0x10);
    dword_40C3618 = CONCAT22(dword_40C3618._0_2_,dword_40C3618._2_2_ + -1);
    _currentScreen = iVar5;
    _evdispatch(2,iVar5,0);
  }
  if (*(int *)(_evg + 0x34) != 0) {
    if (((*(uint *)(_evg + 0x34) & 0x40) == 0) || ((*(uint *)(_evg + 8) & 4) == 0)) {
      if (((char)*(undefined4 *)(_evg + 0x34) < '\0') && ((*(uint *)(_evg + 8) & 1) != 0)) {
        uVar6 = 7;
      }
      else {
        if ((*(uint *)(_evg + 0x34) & 0x20) == 0) goto loc_406A05C;
        uVar6 = 5;
      }
    }
    else {
      uVar6 = 6;
    }
    _LLEventPost(uVar6,param_1,0);
  }
loc_406A05C:
  if (((*(byte *)(_evg + 0x33) & 1) != 0) &&
     (((((param_1._0_2_ < *(sword *)(_evg + 0x28) || (*(sword *)(_evg + 0x2a) <= param_1._0_2_)) ||
        (param_1._2_2_ < *(sword *)(_evg + 0x2c))) || (*(sword *)(_evg + 0x2e) <= param_1._2_2_)) &&
      ((*(byte *)(_evg + 0x33) & 1) != 0)))) {
    _LLEventPost(9,*(undefined4 *)(_evg + 0x18),0);
    *(byte *)(_evg + 0x33) = *(byte *)(_evg + 0x33) & 0xfe;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1985 start=0x406a0d0 */

uint _process_mouse_event(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (_buttonsTied == 0) {
    if (_mouseHandedness != 0) {
      bVar1 = *(byte *)(param_1 + 3);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 2) & 1 | bVar1 & 0xfe;
      *(byte *)(param_1 + 2) = bVar1 & 1 | *(byte *)(param_1 + 2) & 0xfe;
    }
  }
  else {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfe;
    }
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 1;
  }
  if ((~(uint)*(byte *)(param_1 + 3) & 1) != (*(uint *)(_evg + 8) & 7) >> 2) {
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      _lastPressure = 0xff;
      _LLEventPost(1,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 4;
    }
    else {
      _lastPressure = 0;
      _LLEventPost(2,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffb;
    }
    *(uint *)(_evg + 8) = uVar2;
    *(byte *)(_evg + 0x33) =
         *(byte *)(_evg + 0x33) & 0xfd | (byte)(((*(byte *)(_evg + 0x33) & 7) >> 2) << 1);
    if ((*(byte *)(_evg + 0x33) & 2) == 0) {
      uVar2 = *(uint *)(_evg + 0xc) & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(_evg + 0xc) | 0x100;
    }
    *(uint *)(_evg + 0xc) = uVar2;
  }
  uVar2 = ~(uint)*(byte *)(param_1 + 2) & 1;
  if (uVar2 != (*(uint *)(_evg + 8) & 1)) {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      _LLEventPost(3,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 1;
    }
    else {
      _LLEventPost(4,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffe;
    }
    *(uint *)(_evg + 8) = uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 1;
  uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(param_1 + 2)) & 0xfffffefe;
  if ((*(word *)(param_1 + 2) & 0xfefe) != 0) {
    uVar2 = *(uint *)(param_1 + 3) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelX = _mouseDelX - uVar2;
    uVar2 = *(uint *)(param_1 + 2) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelY = _mouseDelY - uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 0;
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1986 start=0x406a29c */

int _mouse_motion(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  iVar1 = _evg;
  iVar3 = *(int *)(_evg + 0x14);
  if (iVar3 == 0) {
    if ((*(uint *)(_evg + 0x34) & 0x20000) == 0) {
      iVar3 = _mouseDelX;
      if (_mouseDelX < 0) {
        iVar3 = -_mouseDelX;
      }
      iVar2 = _mouseDelY;
      if (_mouseDelY < 0) {
        iVar2 = -_mouseDelY;
      }
      if ((int)_mouseScaleThresholds << (-(int)-(dword_40B4FB6 != 0) & 0x3fU) < iVar2 + iVar3) {
        iVar4 = 1;
        if (1 < _numMouseScales) {
          puVar5 = unk_40C3696;
          do {
            if (iVar2 + iVar3 <= (int)*(sword *)puVar5 << (-(int)-(dword_40B4FB6 != 0) & 0x3fU))
            break;
            puVar5 = (undefined *)((int)puVar5 + 2);
            iVar4 = iVar4 + 1;
          } while (iVar4 < _numMouseScales);
        }
        _mouseDelX = _mouseDelX * *(sword *)(_mouseScaleFactors + (iVar4 + -1) * 2);
        _mouseDelY = _mouseDelY * *(sword *)(_mouseScaleFactors + (iVar4 + -1) * 2);
      }
    }
    *(uint *)(_evg + 0x34) = *(uint *)(_evg + 0x34) & 0xfffcffff;
    iVar3 = _MoveTheCursor(CONCAT22(_mouseDelX._2_2_ + *(sword *)(iVar1 + 0x18),
                                    _mouseDelY._2_2_ + *(sword *)(iVar1 + 0x1a)),
                           *(undefined4 *)(iVar1 + 0x34));
    _mouseDelY = 0;
    _mouseDelX = 0;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1987 start=0x406a394 */

void _ShowWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 1;
  sub_406A9D4(1);
  _waitFrameTime = _waitFrameRate + 1;
  _waitSusTime = _waitSustain;
  return;
}
/* GHIDRADEC_FUNCTION index=1988 start=0x406a3ca */

void _HideWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 0;
  sub_406A9D4(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1989 start=0x406a3e4 */

void _AnimateWaitCursor(void)

{
  sub_406A9D4(*(int *)(_evg + 0x1c) + 1);
  _waitFrameTime = _waitFrameRate;
  return;
}
/* GHIDRADEC_FUNCTION index=1990 start=0x406a40a */

void _evsetup_screens(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[2];
  if (_evScreen == 0) {
    _evScreenSize = param_1[1] * 0x28;
    _evScreen = _kalloc(_evScreenSize);
    _bzero(_evScreen,_evScreenSize);
    _totalShmemSize = 0xcd2;
  }
  iVar1 = _evScreen;
  iVar2 = iVar2 * 0x28;
  iVar3 = param_1[5];
  *(int *)(_evScreen + 0xc + iVar2) = param_1[4];
  *(int *)(iVar1 + 0x10 + iVar2) = iVar3;
  iVar1 = iVar1 + iVar2;
  *(int *)(iVar1 + 8) = param_1[3];
  _totalShmemSize = _totalShmemSize + *(int *)(iVar1 + 8);
  *param_1 = _totalShmemSize;
  return;
}
/* GHIDRADEC_FUNCTION index=1991 start=0x406a49e */

int _ev_register_screen(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (_evg == 0) {
    iVar2 = -1;
  }
  else {
    if (_screens == 0) {
      dword_40B1278 = _evs;
    }
    puVar1 = (undefined4 *)(_evScreen + _screens * 0x28);
    *param_1 = (int)puVar1;
    *puVar1 = param_2;
    puVar1[7] = param_3;
    puVar1[6] = param_4;
    puVar1[8] = param_5;
    puVar1[9] = param_6;
    if (puVar1[2] != 0) {
      puVar1[1] = dword_40B1278;
    }
    dword_40B1278 = puVar1[2] + dword_40B1278;
    iVar2 = _screens + 0x100;
    _screens = _screens + 1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1992 start=0x406a522 */

undefined4 _ev_unregister_screen(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((_evg == 0) || (param_1 = param_1 + -0x100, param_1 < 0)) || (_screens <= param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    _evdispatch(1,_currentScreen,0);
    iVar1 = _evScreen;
    param_1 = param_1 * 0x28;
    *(undefined4 *)(_evScreen + 0x1c + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x18 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x20 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x24 + param_1) = 0;
    _evdispatch(2,_currentScreen,0);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1993 start=0x406a59a */

void _InitMouseVars(void)

{
  sword sVar1;
  int iVar2;
  
  _clickTimeThresh = 0x1e;
  word_40C3316 = 3;
  _clickSpaceThresh = 3;
  _clickTime = 0xffffffe2;
  _clickLoc._2_2_ = 0xfffd;
  _clickLoc._0_2_ = 0xfffd;
  _clickState = 1;
  _autoDimTime = *(int *)(_evg + 0x10) + 0x1d718;
  _autoDimPeriod = 0x1d718;
  _dimmedBrightness = 0xf;
  _buttonsTied = 1;
  _mouseHandedness = 0;
  _numMouseScales = dword_40B1260;
  sVar1 = dword_40B1260._2_2_;
  while (sVar1 = sVar1 + -1, sVar1 != -1) {
    iVar2 = (int)sVar1;
    (&_mouseScaleThresholds)[iVar2] = *(undefined2 *)(unk_40B1264 + iVar2 * 2);
    *(undefined2 *)(_mouseScaleFactors + iVar2 * 2) = *(undefined2 *)(unk_40B126E + iVar2 * 2);
  }
  _mouseDelY = 0;
  _mouseDelX = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1994 start=0x406a668 */

void _InitMouse(int param_1)

{
  int iVar1;
  sword sVar2;
  undefined2 *puVar3;
  sword sVar4;
  undefined2 *puVar5;
  
  puVar5 = _evg;
  puVar3 = _evg;
  sVar4 = (sword)param_1;
  while (sVar2 = sVar4 + -1, _evg = puVar3, sVar2 != -1) {
    iVar1 = (int)sVar2;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x27) = 0;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x2d) = 0;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x2f) = 0;
    puVar5[iVar1 * 0x14 + 0x26] = 0;
    puVar5[iVar1 * 0x14 + 0x25] = sVar4;
    puVar3 = _evg;
    sVar4 = sVar2;
  }
  iVar1 = param_1 * 5 + -5;
  puVar3[iVar1 * 4 + 0x25] = 0;
  puVar3[2] = puVar3[iVar1 * 4 + 0x25];
  puVar3[1] = puVar3[(sword)puVar3[2] * 0x14 + 0x25];
  *puVar3 = puVar3[1];
  *(undefined4 *)(puVar3 + 4) = 0;
  puVar3[3] = 0xd;
  *(undefined4 *)(puVar3 + 6) = 0;
  *(undefined4 *)(puVar3 + 8) = 1;
  puVar3[0xc] = 100;
  puVar3[0xd] = 100;
  _screens = 0;
  _sessionPressure = 0;
  _sessionPrecision = 0;
  _lastPressure = 0;
  *(byte *)((int)puVar3 + 0x33) = *(byte *)((int)puVar3 + 0x33) & 0xfd;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xfb;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xef;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xf7;
  _rightENum = 0;
  _leftENum = 0;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xfe;
  puVar3 = _evg;
  *(undefined4 *)(_evg + 0x1a) = 0;
  *(undefined4 *)(puVar3 + 10) = 0;
  _autoDimmed = 0;
  _mouseDelY = 0;
  _mouseDelX = 0;
  dword_40B4FB6 = _adb_mouse_present();
  _InitMouseVars();
  return;
}
/* GHIDRADEC_FUNCTION index=1995 start=0x406a7a8 */

void _TermMouse(void)

{
  if (_screens != 0) {
    _evdispatch(1,_currentScreen,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1996 start=0x406a7ca */

void _ResetMouse(void)

{
  if (_autoDimmed != 0) {
    _UndoAutoDim();
  }
  _InitMouseVars();
  return;
}
/* GHIDRADEC_FUNCTION index=1997 start=0x406a7e6 */

undefined4 _StartCursor(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((_screens != 0) &&
     (_currentScreen = sub_406AA0C(*(undefined4 *)(_evg + 0x18)), -1 < _currentScreen)) {
    uVar1 = *(undefined4 *)(_evScreen + 0xc + _currentScreen * 0x28);
    uVar2 = *(undefined4 *)(_evScreen + 0x10 + _currentScreen * 0x28);
    _cursorPin._2_2_ = (sword)uVar1;
    _cursorPin = CONCAT22((sword)((uint)uVar1 >> 0x10),_cursorPin._2_2_ + -1);
    dword_40C3618._2_2_ = (sword)uVar2;
    dword_40C3618 = CONCAT22((sword)((uint)uVar2 >> 0x10),dword_40C3618._2_2_ + -1);
    _SetCurBrightness(_curBright);
    _evdispatch(2,_currentScreen,0);
    return 0;
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=1998 start=0x406a86a */

void _evdispatch(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  
  iVar1 = _evScreen + param_2 * 0x28;
  uVar4 = 0;
  if ((param_1 < 4) || ((*(byte *)(iVar1 + 0x14) & 0x60) != 0)) {
    *(byte *)(iVar1 + 0x14) =
         *(byte *)(iVar1 + 0x14) & 0x9f |
         (DAT_40b127c[(param_1 & 3) + ((*(byte *)(iVar1 + 0x14) & 0x7f) >> 5) * 4] & 3) << 5;
    uVar2 = (*(byte *)(iVar1 + 0x14) & 0x7f) >> 5;
    if (uVar2 == 2) {
      pcVar5 = *(code **)(iVar1 + 0x20);
loc_406A8F0:
      if (pcVar5 != (code *)0x0) {
        uVar4 = (*pcVar5)(iVar1,*(undefined4 *)(_evg + 0x18),*(undefined4 *)(_evg + 0x1c));
      }
    }
    else if (uVar2 < 3) {
      if ((uVar2 == 1) && (*(code **)(iVar1 + 0x18) != (code *)0x0)) {
        uVar4 = (**(code **)(iVar1 + 0x18))(iVar1);
      }
    }
    else if (uVar2 == 3) {
      pcVar5 = *(code **)(iVar1 + 0x1c);
      goto loc_406A8F0;
    }
    if (uVar4 == 0) {
      *(byte *)(iVar1 + 0x14) = (byte)(((uint)*(byte *)(iVar1 + 0x14) << 0x19) >> 0x1e);
    }
  }
  if (param_1 == 4) {
    dword_40B4FB2 = param_3;
  }
  else if (-1 < *(char *)(iVar1 + 0x14)) goto loc_406A96C;
  if (*(code **)(iVar1 + 0x24) != (code *)0x0) {
    cVar3 = (**(code **)(iVar1 + 0x24))(iVar1,dword_40B4FB2);
    *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) & 0x7f | cVar3 << 7;
    uVar4 = *(byte *)(iVar1 + 0x14) >> 7 | uVar4;
  }
loc_406A96C:
  uVar2 = 1 << (param_2 & 0x3f);
  _evRetryMask = _evRetryMask & ~uVar2;
  if (uVar4 != 0) {
    _evRetryMask = uVar2 | _evRetryMask;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1999 start=0x406a992 */

void _evretry(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _evRetryMask;
  for (uVar2 = 0; (uVar1 != 0 && (uVar2 < _screens)); uVar2 = uVar2 + 1) {
    if ((uVar1 & 1) != 0) {
      _evdispatch(0,uVar2,0);
    }
    uVar1 = uVar1 >> 1;
  }
  return;
}

