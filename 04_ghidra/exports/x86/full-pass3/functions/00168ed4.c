/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168ed4 */

void _swapper_init(void)

{
  DAT_001f6d94 = &_swapin_queue;
  _swapin_queue = &_swapin_queue;
  _swapper_lock_data = 0;
  return;
}

