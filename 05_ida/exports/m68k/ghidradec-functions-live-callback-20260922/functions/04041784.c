
void _ipc_pset_destroy(int *param_1)

{
  int iVar1;
  
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0x7f;
  _ipc_mqueue_changed(param_1 + 3,0x10004009);
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[*(word *)(param_1 + 1) & 0x7fff],param_1);
  }
  return;
}

