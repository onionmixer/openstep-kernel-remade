/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0918 */

void _initDmaLock(void)

{
  DAT_001e871c = 0;
  DAT_001e8720 = 0;
  DAT_001e8728 = (undefined4 *)_simple_lock_alloc();
  *DAT_001e8728 = 0;
  return;
}

