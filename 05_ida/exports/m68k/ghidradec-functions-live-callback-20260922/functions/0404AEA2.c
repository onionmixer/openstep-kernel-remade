
undefined4 _lock_try_write(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
    uVar1 = 1;
  }
  else if ((param_1[1] & 0xffffc000U) == 0) {
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x40;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

