/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165494 */

void _thread_switch_continue(void)

{
  if (-1 < *(int *)(_active_threads + 100)) {
    _thread_depress_abort(_active_threads);
  }
  _thread_syscall_return(0);
  return;
}

