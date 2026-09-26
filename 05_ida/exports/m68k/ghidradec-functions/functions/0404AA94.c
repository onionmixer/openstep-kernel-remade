
void _stack_free(int param_1)

{
  int iVar1;
  
  iVar1 = _stack_detach(param_1);
  if (iVar1 != *(int *)(param_1 + 0x2c)) {
    _freeStack(iVar1);
  }
  return;
}
