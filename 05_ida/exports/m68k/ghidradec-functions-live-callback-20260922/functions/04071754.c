
void _alert_lock_screen(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (_eventsOpen != 0) {
    if (param_1 == 0) {
      *(undefined4 *)(_evg + 0x14) = 0;
    }
    else {
loc_40717E0:
      while (*(int *)(_evg + 0x14) == 1) {
        iVar4 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104);
        iVar1 = *(int *)(*(int *)(_processor_ptr + 0x128) + 0x100);
        iVar2 = *(int *)(_active_threads + 0x54);
        iVar3 = *(int *)(_active_threads + 0x5c);
        if (((*(byte *)(_active_threads + 0x4b) & 2) != 0) || (0 < *(int *)(_processor_ptr + 0x104))
           ) goto loc_40717DA;
        if ((iVar3 != 2) && ((iVar3 < 3 && (iVar3 == 1)))) goto loc_40717CE;
        if (((iVar4 != 0) && (iVar2 <= iVar1)) &&
           ((iVar2 < iVar1 || (*(int *)(_processor_ptr + 0x120) == 0)))) goto loc_40717DA;
      }
      *(undefined4 *)(_evg + 0x14) = 1;
    }
    if ((_eventTask != 0) && (iVar4 = *(int *)(_eventTask + 0x18), iVar4 != _eventTask + 0x18)) {
      do {
        if (param_1 == 0) {
          _thread_resume(iVar4);
        }
        else {
          _thread_suspend(iVar4);
        }
        iVar4 = *(int *)(iVar4 + 0x10);
      } while (iVar4 != _eventTask + 0x18);
    }
  }
  return;
loc_40717CE:
  if ((*(int *)(_processor_ptr + 0x120) == 0) && ((0 < iVar4 && (iVar2 <= iVar1)))) {
loc_40717DA:
    _thread_block();
  }
  goto loc_40717E0;
}

