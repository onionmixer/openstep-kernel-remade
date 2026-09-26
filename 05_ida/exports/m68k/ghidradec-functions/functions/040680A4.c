
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
