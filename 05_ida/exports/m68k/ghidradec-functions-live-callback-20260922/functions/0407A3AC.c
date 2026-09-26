
void _od_unlock_check(sword param_1)

{
  if (_od_lock_pid == param_1) {
    _od_lock(0x20006410);
  }
  return;
}

