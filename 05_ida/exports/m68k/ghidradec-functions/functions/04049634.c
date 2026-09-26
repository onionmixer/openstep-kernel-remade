
void _ipc_task_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    iVar3 = *(int *)(param_1 + 0x60);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 100);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 0x68);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x6c + iVar3 * 4);
      if ((iVar2 != 0) && (iVar2 != -1)) {
        _ipc_port_release_send(iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    _ipc_space_destroy(*(undefined4 *)(param_1 + 0x7c));
    _ipc_port_dealloc_special(iVar1,_ipc_space_kernel);
  }
  return;
}
