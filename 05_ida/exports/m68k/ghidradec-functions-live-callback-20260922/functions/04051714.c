
void _sched_thread(void)

{
  _sched_thread_id = _active_threads;
  _assert_wait(0,0);
  _thread_block_with_continuation(_sched_thread_continue);
                    /* WARNING: Subroutine does not return */
  _sched_thread_continue();
}

