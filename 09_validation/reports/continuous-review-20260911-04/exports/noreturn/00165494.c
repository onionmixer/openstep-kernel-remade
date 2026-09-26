
void _thread_switch_continue(void)

{
  if (-1 < *(int *)(_active_threads + 100)) {
    _thread_depress_abort(_active_threads);
  }
                    /* WARNING: Subroutine does not return */
  _thread_syscall_return(0);
}

