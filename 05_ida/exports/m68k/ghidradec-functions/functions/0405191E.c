
void _swtch_pri_continue(void)

{
  undefined4 uVar1;
  
  if (-1 < *(int *)(_active_threads + 0x60)) {
    _thread_depress_abort(_active_threads);
  }
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return;
}
