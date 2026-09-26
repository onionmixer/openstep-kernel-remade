/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d5b4 */

void _pnotify_start(void)

{
  thread_act_t in_stack_fffffff4;
  task_t *in_stack_fffffff8;
  
  _task_create(_kernel_task,(ledger_array_t)0x0,(mach_msg_type_number_t)&stack0xfffffff8,
               in_stack_fffffff4,in_stack_fffffff8);
  _task_deallocate(in_stack_fffffff8);
  _thread_create((task_t)in_stack_fffffff8,(thread_act_t *)&stack0xfffffff4);
  _thread_deallocate(in_stack_fffffff4);
  _thread_start(in_stack_fffffff4,_notify_server_loop);
  _thread_resume(in_stack_fffffff4);
  return;
}

