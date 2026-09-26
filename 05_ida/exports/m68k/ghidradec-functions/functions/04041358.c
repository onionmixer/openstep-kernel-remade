
void _ipc_port_release_receive(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _ipc_port_destroy(param_1);
  if (iVar1 != 0) {
    _ipc_object_release(iVar1);
  }
  return;
}
