
void _stack_privilege(int param_1)

{
  if (param_1 != _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aStackPrivilege);
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(param_1 + 0x2c) = _active_stacks;
  }
  return;
}

