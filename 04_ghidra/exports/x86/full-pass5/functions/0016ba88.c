/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ba88 */

void _consider_zone_gc(void)

{
  if (_zone_gc_max_rate == 0) {
    _zone_gc_max_rate = _hz;
  }
  if ((_zone_gc_allowed != 0) && (_zone_gc_last_tick + _zone_gc_max_rate < _sched_tick)) {
    _zone_gc_last_tick = _sched_tick;
    _zone_gc();
  }
  return;
}

