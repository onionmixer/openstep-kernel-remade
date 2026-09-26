
undefined4 _convert_port_to_space(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 2)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x7c);
    _ipc_space_reference(uVar1);
  }
  return uVar1;
}
