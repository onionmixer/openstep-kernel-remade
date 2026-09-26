
void _swtch_continue(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return;
}

