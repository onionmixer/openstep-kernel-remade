/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e690 */

undefined4 _thread_set_cthread_self(undefined4 param_1)

{
  *(undefined4 *)(*(int *)(_active_threads + 0x28) + 0xe8) = param_1;
  return 0;
}

