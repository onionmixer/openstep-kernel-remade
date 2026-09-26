
void _idle_thread(void)

{
  int iVar1;
  
  iVar1 = _active_threads;
  _stack_privilege(_active_threads);
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  *(word *)(iVar1 + 0x4a) = *(word *)(iVar1 + 0x4a) | 0x80;
  *(int *)(_processor_ptr + 0x118) = iVar1;
  _thread_block_with_continuation(_idle_thread_continue);
                    /* WARNING: Subroutine does not return */
  _idle_thread_continue();
}
