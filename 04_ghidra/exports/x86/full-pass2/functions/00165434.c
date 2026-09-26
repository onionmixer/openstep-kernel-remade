/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165434 */

boolean_t _swtch_pri(int pri)

{
  thread_act_t thread;
  boolean_t bVar1;
  
  thread = _active_threads;
  _thread_depress_priority(_active_threads,_min_quantum);
  _thread_block_with_continuation(_swtch_pri_continue);
  if (-1 < *(int *)(thread + 100)) {
    _thread_depress_abort(thread);
  }
  bVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    bVar1 = 1;
  }
  return bVar1;
}

