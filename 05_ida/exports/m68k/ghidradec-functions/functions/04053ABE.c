
void _consider_thread_collect(void)

{
  if (_thread_collect_max_rate == 0) {
    _thread_collect_max_rate = _hz;
  }
  if ((_thread_collect_allowed != 0) &&
     (_thread_collect_max_rate + _thread_collect_last_tick < _sched_tick)) {
    _thread_collect_last_tick = _sched_tick;
    _thread_collect_scan();
  }
  return;
}
