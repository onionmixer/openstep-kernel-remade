
undefined4 _convert_pset_name_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x148) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(undefined4 *)(param_1 + 0x150));
  }
  _pset_deallocate(param_1);
  return uVar1;
}

