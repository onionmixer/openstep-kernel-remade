
void _swapin_thread(void)

{
  _stack_privilege(_active_threads);
                    /* WARNING: Subroutine does not return */
  _swapin_thread_continue();
}
