
void sub_40548F6(void)

{
  if (dword_40B4DD8 < dword_40B4DD0 + dword_40B4DD4) {
    dword_40B4DD8 = dword_40B4DD8 + 1;
    _kernel_thread(*(undefined4 *)(_active_threads + 0xc),sub_40548DC,0);
    _thread_block_with_continuation(sub_40548F6);
  }
  _assert_wait(&dword_40B4DD8,0);
  _thread_block_with_continuation(sub_40548F6);
  return;
}
