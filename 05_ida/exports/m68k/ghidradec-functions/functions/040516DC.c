
void _sched_thread_continue(void)

{
  do {
    _compute_mach_factor();
    if ((bRam040c2453 & 1) != 0) {
      _do_thread_scan();
    }
    _assert_wait(0,0);
    _thread_block_with_continuation(_sched_thread_continue);
  } while( true );
}
