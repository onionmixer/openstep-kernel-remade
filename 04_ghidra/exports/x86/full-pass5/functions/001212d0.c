/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001212d0 */

void _netisr_thread(void)

{
  undefined4 uVar1;
  
  uVar1 = _active_threads;
  _stack_privilege(_active_threads);
  _thread_bind(uVar1,_master_processor);
  _thread_block_with_continuation(_netisr_thread_continue);
  return;
}

