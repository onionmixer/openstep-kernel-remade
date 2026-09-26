
void _thread_switch_continue(void)

{
  if (-1 < *(int *)(_active_threads + 0x60)) {
    _thread_depress_abort(_active_threads);
  }
  _thread_syscall_return(0);
  return;
}

