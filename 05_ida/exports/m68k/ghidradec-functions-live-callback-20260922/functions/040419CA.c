
undefined4 _ipc_right_dncancel(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_dncancel(param_2,param_3,*(undefined4 *)(param_4 + 8));
  *(undefined4 *)(param_4 + 8) = 0;
  if ((*(byte *)(param_4 + 1) & 0x40) != 0) {
    _ipc_space_release(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

