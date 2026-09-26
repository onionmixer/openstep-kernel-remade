
undefined4 _lock_read_to_write(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    bVar1 = *(byte *)((int)param_1 + 6);
    if ((char)bVar1 < '\0') {
      if ((param_1[1] & 0xffff2000U) == 0x2000) {
        *(byte *)((int)param_1 + 6) = bVar1 & 0xdf;
        _thread_wakeup_prim(param_1,0,0);
      }
      return 1;
    }
    *(byte *)((int)param_1 + 6) = bVar1 | 0x80;
    while (*(sword *)(param_1 + 1) != 0) {
      if ((0 < _lock_wait_time) && (iVar2 = _lock_wait_time + -1, 0 < iVar2)) {
        do {
          if (*(sword *)(param_1 + 1) == 0) break;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x10) != 0) {
        if (*(sword *)(param_1 + 1) == 0) {
          return 0;
        }
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  return 0;
}

