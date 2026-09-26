
void _stack_init(undefined4 *param_1)

{
  uint uVar1;
  
  if (_stack_check_usage != 0) {
    uVar1 = 0;
    do {
      *param_1 = 0xdeadbeef;
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < 0x3fd);
  }
  return;
}
