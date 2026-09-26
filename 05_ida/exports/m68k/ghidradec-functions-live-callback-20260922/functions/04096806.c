
void _stack_handoff(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = _stack_detach(param_1);
  _stack_attach(param_2,uVar2,0);
  _active_threads = param_2;
  if ((*(int *)(param_2 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  __stack_handoff(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24));
  return;
}

