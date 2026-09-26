
void _netisr_thread_continue(void)

{
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

