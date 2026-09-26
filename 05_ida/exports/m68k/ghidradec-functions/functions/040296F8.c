
void sub_40296F8(int param_1)

{
  _rlock_awaken_count = _rlock_awaken_count + 1;
  if (param_1 != 0) {
    _wakeup(param_1);
  }
  return;
}
