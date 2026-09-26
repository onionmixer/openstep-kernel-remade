
void _switch_context(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  _active_threads = param_3;
  _active_stacks = *(undefined4 *)(param_3 + 0x28);
  _stack_pointers = *(int *)(param_3 + 0x28) + 0xff4;
  if ((*(int *)(param_3 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_3 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  *(int *)(param_1 + 0x30) = param_2;
  if (param_2 == 0) {
    __switch_context(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  else {
    __switch_context_discard
              (*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  return;
}
