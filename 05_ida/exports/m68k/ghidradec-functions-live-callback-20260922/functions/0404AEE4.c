
undefined4 _lock_try_read(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == _active_threads) || ((*(byte *)((int)param_1 + 6) & 0xc0) == 0)) {
    *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

