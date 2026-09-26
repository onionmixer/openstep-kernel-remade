
void _netisr_thread(void)

{
  undefined4 uVar1;
  
  uVar1 = _active_threads;
  _stack_privilege(_active_threads);
  _thread_bind(uVar1,_master_processor);
  _thread_block_with_continuation(_netisr_thread_continue);
  return;
}
