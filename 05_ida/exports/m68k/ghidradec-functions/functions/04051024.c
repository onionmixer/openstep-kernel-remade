
void _recompute_priorities(void)

{
  int iVar1;
  
  _sched_tick = _sched_tick + 1;
  _set_timeout(_recompute_priorities_timer,_hz);
  iVar1 = _sched_usec_elapsed();
  _sched_usec = iVar1 * 3 + _sched_usec * 5;
  if (_sched_usec < 0) {
    _sched_usec = _sched_usec + 7;
  }
  _sched_usec = _sched_usec >> 3;
  if (_sched_thread_id != 0) {
    _clear_wait(_sched_thread_id,0,0);
  }
  return;
}
