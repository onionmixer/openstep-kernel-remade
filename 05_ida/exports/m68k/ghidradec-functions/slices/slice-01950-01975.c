/* GHIDRADEC_FUNCTION index=1950 start=0x4067960 */

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
/* GHIDRADEC_FUNCTION index=1951 start=0x40679ec */

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
/* GHIDRADEC_FUNCTION index=1952 start=0x4067abe */

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
/* GHIDRADEC_FUNCTION index=1953 start=0x4067b36 */

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
/* GHIDRADEC_FUNCTION index=1954 start=0x4067cb4 */

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
/* GHIDRADEC_FUNCTION index=1955 start=0x4067d6c */

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
/* GHIDRADEC_FUNCTION index=1956 start=0x4067e2e */

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
/* GHIDRADEC_FUNCTION index=1957 start=0x40680a4 */

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
/* GHIDRADEC_FUNCTION index=1958 start=0x4068456 */

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
/* GHIDRADEC_FUNCTION index=1959 start=0x40684a6 */

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
/* GHIDRADEC_FUNCTION index=1960 start=0x4068710 */

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
/* GHIDRADEC_FUNCTION index=1961 start=0x4068894 */

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
/* GHIDRADEC_FUNCTION index=1962 start=0x4068fa2 */

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
/* GHIDRADEC_FUNCTION index=1963 start=0x4069026 */

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
/* GHIDRADEC_FUNCTION index=1964 start=0x406908c */

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
/* GHIDRADEC_FUNCTION index=1965 start=0x40690bc */

void _process_adb_event(int param_1)

{
  _DoKbdEvent(*(byte *)(param_1 + 3) & 0x7f,*(byte *)(param_1 + 3) >> 7 ^ 1,
              *(byte *)(param_1 + 2) & 0x7f);
  return;
}
/* GHIDRADEC_FUNCTION index=1966 start=0x40690f8 */

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
/* GHIDRADEC_FUNCTION index=1967 start=0x4069156 */

void _DoAutoDim(void)

{
  if (_dimmedBrightness < _curBright) {
    _SetCurBrightness(_dimmedBrightness);
  }
  _autoDimmed = 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1968 start=0x406917c */

void _UndoAutoDim(void)

{
  _SetCurBrightness(_curBright);
  _autoDimTime = _autoDimPeriod + *(int *)(_evg + 0x10);
  _autoDimmed = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1969 start=0x40691ac */

void _RecordBrightness(void)

{
  undefined uStack_24;
  uint uStack_23;
  
  _nvram_check(&uStack_24);
  uStack_23 = uStack_23 & 0xf03fffff | (_curBright & 0x3f) << 0x16;
  _nvram_set(&uStack_24);
  return;
}
/* GHIDRADEC_FUNCTION index=1970 start=0x40691dc */

void _DoBrightnessChange(int param_1)

{
  _curBright = _SetCurBrightness(param_1 + _curBright);
  return;
}
/* GHIDRADEC_FUNCTION index=1971 start=0x40691fc */

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
/* GHIDRADEC_FUNCTION index=1972 start=0x4069250 */

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
/* GHIDRADEC_FUNCTION index=1973 start=0x40693ca */

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
/* GHIDRADEC_FUNCTION index=1974 start=0x40694da */

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

