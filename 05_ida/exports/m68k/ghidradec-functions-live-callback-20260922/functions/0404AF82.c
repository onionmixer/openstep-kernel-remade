
void _lock_set_recursive(undefined4 *param_1)

{
  if ((*(byte *)((int)param_1 + 6) & 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aLockSetRecursi);
  }
  *param_1 = _active_threads;
  return;
}

