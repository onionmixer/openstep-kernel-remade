
void _sched_init(void)

{
  unk_40C25E8 = _recompute_priorities;
  dword_40C25EC = 0;
  _init_timeout_element(_recompute_priorities_timer);
  _min_quantum = _hz / 10;
  _wait_queue_init();
  _pset_sys_bootstrap();
  dword_40C23A0 = &_action_queue;
  _action_queue = &_action_queue;
  _sched_tick = 0;
  _sched_usec = 0;
  _ast_init();
  return;
}
