
undefined4 _swtch(void)

{
  undefined4 uVar1;
  
  _thread_block_with_continuation(_swtch_continue);
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  return uVar1;
}
