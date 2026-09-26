
void _vm_map_entry_unwire(undefined4 param_1,int param_2)

{
  _vm_fault_unwire(param_1,param_2);
  *(undefined2 *)(param_2 + 0x26) = 0;
  return;
}
