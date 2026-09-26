
void _freeStack(int param_1)

{
  dword_40C232C = dword_40C232C + -1;
  _lock_write(&_stack_queue_lock);
  sub_404A45C(param_1 + -0xc);
  _lock_done(&_stack_queue_lock);
  if (dword_40AF7DC != 0) {
    dword_40AF7DC = 0;
    _thread_wakeup_prim(&dword_40B3712,0,0);
  }
  if (dword_40AF7D8 < dword_40AF7D4) {
    sub_404A498(param_1 + -0xc);
  }
  return;
}
