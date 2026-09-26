
void _stack_finalize(undefined4 param_1)

{
  uint uVar1;
  
  if (_stack_check_usage != 0) {
    uVar1 = _stack_usage(param_1);
    if (_stack_max_usage < uVar1) {
      _stack_max_usage = uVar1;
    }
  }
  return;
}
