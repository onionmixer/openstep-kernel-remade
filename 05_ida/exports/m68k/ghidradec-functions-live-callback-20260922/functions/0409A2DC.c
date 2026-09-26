
void _do_trace(int param_1)

{
  *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0x3fff;
  _exception_with_continuation(6,0,0,0);
  return;
}

