/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121274 */

void _netisr_thread_continue(void)

{
  _splnet();
  while (_netisr != 0) {
    if ((_netisr & 4) != 0) {
      _netisr = _netisr & 0xfffffffb;
      _ipintr();
    }
    if ((_netisr & 1) != 0) {
      _netisr = _netisr & 0xfffffffe;
      _rawintr();
    }
  }
  _assert_wait(&_soft_net_wakeup,0);
  _thread_block_with_continuation(_netisr_thread_continue);
  return;
}

