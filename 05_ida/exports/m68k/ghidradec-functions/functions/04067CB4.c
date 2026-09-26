
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
