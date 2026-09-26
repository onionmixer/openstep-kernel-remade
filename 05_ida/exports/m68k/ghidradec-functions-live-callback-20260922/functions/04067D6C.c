
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

