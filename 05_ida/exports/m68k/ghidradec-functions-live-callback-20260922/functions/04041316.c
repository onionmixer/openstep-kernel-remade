
void _ipc_port_release_sonce(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (param_1[1] < 0) {
    param_1[7] = param_1[7] + -1;
  }
  else if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[(param_1[1] & 0x7fffffffU) >> 0x10],param_1);
  }
  return;
}

