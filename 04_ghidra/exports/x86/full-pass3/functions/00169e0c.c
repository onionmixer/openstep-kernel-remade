/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169e0c */

void FUN_00169e0c(void)

{
  int iVar1;
  
  iVar1 = _active_threads;
  _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  DAT_001e7244 = 1;
  UNLOCK();
  if (DAT_001e7268 < DAT_001e7264 + DAT_001e7260) {
    DAT_001e7268 = DAT_001e7268 + 1;
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _kernel_thread(*(undefined4 *)(iVar1 + 0xc),FUN_0016a140,0);
    _thread_block_with_continuation(FUN_00169e0c);
  }
  _assert_wait(&DAT_001e7268,0);
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _thread_block_with_continuation(FUN_00169e0c);
  return;
}

