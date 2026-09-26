
void _initKernelStacks(void)

{
  dword_40B3716 = &dword_40B3712;
  dword_40B3712 = &dword_40B3712;
  _lock_init(&_stack_queue_lock,1);
  dword_40B371A = 0x1000;
  dword_40B371E = _page_size + 0xfffU >> 0xc;
  return;
}

