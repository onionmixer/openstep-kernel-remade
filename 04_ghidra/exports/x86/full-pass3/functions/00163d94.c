/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163d94 */

void _recompute_priorities(void)

{
  _sched_tick = _sched_tick + 1;
  _set_timeout(&_recompute_priorities_timer,_hz);
  if (_sched_thread_id != 0) {
    _clear_wait(_sched_thread_id,0,0);
  }
  return;
}

