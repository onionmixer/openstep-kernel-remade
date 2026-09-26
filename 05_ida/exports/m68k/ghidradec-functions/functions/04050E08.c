
void _thread_continue(int param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(_active_threads + 0x30);
  if (param_1 != 0) {
    _thread_dispatch(param_1);
  }
  (*pcVar1)();
  return;
}
