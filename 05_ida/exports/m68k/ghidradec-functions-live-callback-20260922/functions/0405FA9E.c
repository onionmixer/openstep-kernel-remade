
void __vm_object_allocate(undefined4 param_1,int param_2)

{
  _bcopy(_vm_object_template,param_2,0x52);
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  *(undefined4 *)(param_2 + 0x10) = param_1;
  if (dword_40C31B0 == &_vm_object_list) {
    _vm_object_list = param_2;
  }
  else {
    dword_40C31B0[2] = param_2;
  }
  *(undefined4 **)(param_2 + 0xc) = dword_40C31B0;
  *(int **)(param_2 + 8) = &_vm_object_list;
  dword_40C31B0 = (undefined4 *)param_2;
  _vm_object_count = _vm_object_count + 1;
  return;
}

