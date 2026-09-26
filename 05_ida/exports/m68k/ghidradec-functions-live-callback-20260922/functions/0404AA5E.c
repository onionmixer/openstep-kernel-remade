
void _stack_alloc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _allocStack();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aStackAlloc);
  }
  _stack_attach(param_1,iVar1,param_2);
  return;
}

