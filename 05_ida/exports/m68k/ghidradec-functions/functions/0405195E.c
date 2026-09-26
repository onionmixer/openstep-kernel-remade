
undefined4 _swtch_pri(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _active_threads;
  _thread_depress_priority(_active_threads,_min_quantum);
  _thread_block_with_continuation(_swtch_pri_continue);
  if (-1 < *(int *)(iVar1 + 0x60)) {
    _thread_depress_abort(iVar1);
  }
  uVar2 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar2 = 1;
  }
  return uVar2;
}
