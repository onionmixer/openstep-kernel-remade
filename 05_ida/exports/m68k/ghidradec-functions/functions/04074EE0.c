
void _od_timer(void)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  if ((_kernel_task != 0) && (dword_40B4FBE == 0)) {
    _kernel_thread_noblock(_kernel_task,_od_label_alloc);
    _kernel_thread_noblock(_kernel_task,_od_try_attach);
    _kernel_thread_noblock(_kernel_task,_od_request);
    dword_40B4FBE = 1;
  }
  puVar3 = _od_ctrl;
  do {
    if ((*(char *)((int)puVar3 + 0x260) != '\0') &&
       (*(char *)((int)puVar3 + 0x260) = *(char *)((int)puVar3 + 0x260) + -1,
       *(char *)((int)puVar3 + 0x260) == '\0')) {
      *(uint *)((int)puVar3 + 0x220) = *(uint *)((int)puVar3 + 0x220) | 0x200000;
      _odintr(puVar3);
    }
    puVar3 = (undefined *)((int)puVar3 + 0x28c);
  } while (puVar3 < &_od_dbug);
  puVar4 = _od_drive;
  puVar3 = unk_40C3E36;
  do {
    if ((((*(word *)((int)puVar4 + 0x18) & 0x6000) == 0x6000) && (cVar1 = *puVar3, -1 < cVar1)) &&
       (*puVar3 = *puVar3 + '\x01', '\n' < cVar1)) {
      *puVar3 = -1;
      _kernel_thread_noblock(_kernel_task,_od_spiral);
    }
    puVar3 = puVar3 + 0x20;
    puVar4 = (undefined *)((int)puVar4 + 0x20);
  } while (puVar4 < &_od_empty);
  if ((0 < _od_update_time) &&
     (bVar2 = 0x1e < _od_update_time, _od_update_time = _od_update_time + 1, bVar2)) {
    _od_update_time = -1;
    _kernel_thread_noblock(_kernel_task,_od_update_thread);
  }
  _timeout(_od_timer,0,_hz);
  return;
}
