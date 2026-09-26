
void sub_407F2E4(void)

{
  if ((_kernel_task == 0) || (dword_40B2080 != 0)) {
    _timeout(sub_407F2E4,0,_hz);
  }
  else {
    if (dword_40B2088 != 0) {
      _kernel_thread_noblock(_kernel_task,sub_407E934);
    }
    dword_40B2080 = 1;
  }
  return;
}

