
void _objc_setMultithreaded(char param_1)

{
  if (param_1 == '\x01') {
    __objc_multithread_mask = 0;
  }
  else {
    __objc_multithread_mask = 0xffffffff;
  }
  return;
}
