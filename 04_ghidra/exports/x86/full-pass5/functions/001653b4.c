/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001653b4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _swtch(void)

{
  boolean_t bVar1;
  
  _thread_block_with_continuation(_swtch_continue);
  bVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    bVar1 = 1;
  }
  return bVar1;
}

