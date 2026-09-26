
void _start_initial_context(int param_1)

{
  _active_threads = param_1;
  _active_stacks = *(undefined4 *)(param_1 + 0x28);
  _stack_pointers = *(int *)(param_1 + 0x28) + 0xff4;
  __switch_context0(0,*(undefined4 *)(param_1 + 0x24),0);
  return;
}

