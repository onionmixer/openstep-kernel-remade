
void _lock_read(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  if (*param_1 != _active_threads) {
    while ((*(byte *)((int)param_1 + 6) & 0xc0) != 0) {
      if ((0 < _lock_wait_time) && (iVar2 = _lock_wait_time + -1, 0 < iVar2)) {
        do {
          if ((*(byte *)((int)param_1 + 6) & 0xc0) == 0) break;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      bVar1 = *(byte *)((int)param_1 + 6);
      if ((bVar1 & 0x10) != 0) {
        if ((bVar1 & 0xc0) == 0) break;
        *(byte *)((int)param_1 + 6) = bVar1 | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + 1;
  return;
}

