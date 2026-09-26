/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168abc */

void _consider_thread_collect(void)

{
  if (_thread_collect_max_rate == 0) {
    _thread_collect_max_rate = _hz;
  }
  if ((_thread_collect_allowed != 0) &&
     (_thread_collect_last_tick + _thread_collect_max_rate < _sched_tick)) {
    _thread_collect_last_tick = _sched_tick;
  }
  return;
}

