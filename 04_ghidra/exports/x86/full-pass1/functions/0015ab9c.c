/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ab9c */

void _initKernelStacks(void)

{
  DAT_001e5b9c = &DAT_001e5b98;
  DAT_001e5b98 = &DAT_001e5b98;
  _lock_init(&_stack_queue_lock,1);
  DAT_001e5ba0 = 0x1000;
  DAT_001e5ba4 = _page_size + 0xfffU >> 0xc;
  return;
}

