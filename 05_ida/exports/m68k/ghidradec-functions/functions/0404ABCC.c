
void _lock_write(int *param_1)

{
  int iVar1;
  
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    while ((*(byte *)((int)param_1 + 6) & 0x40) != 0) {
      if ((0 < _lock_wait_time) && (iVar1 = _lock_wait_time + -1, 0 < iVar1)) {
        do {
          if ((*(byte *)((int)param_1 + 6) & 0x40) == 0) break;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x50) == 0x50) {
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x40;
    while ((param_1[1] & 0xffff8000U) != 0) {
      if ((0 < _lock_wait_time) && (iVar1 = _lock_wait_time + -1, 0 < iVar1)) {
        do {
          if ((param_1[1] & 0xffff8000U) == 0) break;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x10) != 0) {
        if ((param_1[1] & 0xffff8000U) == 0) {
          return;
        }
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  return;
}
