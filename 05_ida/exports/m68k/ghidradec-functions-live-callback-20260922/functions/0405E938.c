
void _vm_map_entry_delete(int param_1,int *param_2)

{
  if (*(sword *)((int)param_2 + 0x26) != 0) {
    _vm_map_entry_unwire(param_1,param_2);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - (param_2[3] - param_2[2]);
  if ((*(byte *)(param_2 + 6) & 0xa0) == 0) {
    _vm_object_deallocate(param_2[4]);
  }
  else {
    _vm_map_deallocate(param_2[4]);
  }
  __vm_map_entry_dispose(param_1 + 8,param_2);
  return;
}

