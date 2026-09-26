
undefined4 _lock_try_read_to_write(int *param_1)

{
  sword sVar1;
  
  if (*param_1 == _active_threads) {
    *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    if ((char)*(byte *)((int)param_1 + 6) < '\0') {
      return 0;
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x80;
    sVar1 = *(sword *)(param_1 + 1);
    *(sword *)(param_1 + 1) = sVar1 + -1;
    if (sVar1 != 1) {
      do {
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      } while (*(sword *)(param_1 + 1) != 0);
    }
  }
  return 1;
}
