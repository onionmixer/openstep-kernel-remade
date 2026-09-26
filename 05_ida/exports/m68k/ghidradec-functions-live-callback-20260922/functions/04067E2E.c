
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

