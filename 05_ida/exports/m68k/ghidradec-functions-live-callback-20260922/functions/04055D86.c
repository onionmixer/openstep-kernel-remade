
void _consider_zone_gc(void)

{
  if (_zone_gc_max_rate == 0) {
    _zone_gc_max_rate = _hz;
  }
  if ((_zone_gc_allowed != 0) && (_zone_gc_max_rate + _zone_gc_last_tick < _sched_tick)) {
    _zone_gc_last_tick = _sched_tick;
    _zone_gc();
  }
  return;
}

