/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001653ec */

void _swtch_pri_continue(void)

{
  undefined4 uVar1;
  
  if (-1 < *(int *)(_active_threads + 100)) {
    _thread_depress_abort(_active_threads);
  }
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return;
}

