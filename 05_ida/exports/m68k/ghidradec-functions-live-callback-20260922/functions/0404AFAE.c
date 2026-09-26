
void _lock_clear_recursive(int *param_1)

{
  if (*param_1 != _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aLockClearRecur);
  }
  if ((*(uint *)((int)param_1 + 6) & 0xfffffff) >> 0x10 == 0) {
    *param_1 = -1;
  }
  return;
}

