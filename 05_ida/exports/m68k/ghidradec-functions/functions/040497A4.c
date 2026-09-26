
void _ipc_thread_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0xa4);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    iVar2 = *(int *)(param_1 + 0xa8);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_release_send(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0xac);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_release_send(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0xb8);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_dealloc_special(iVar2,_ipc_space_reply);
    }
    iVar2 = *(int *)(param_1 + 0xb0);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x7c);
      if (*(int *)(iVar3 + 4) != 0) {
        iVar4 = _ipc_right_reverse(iVar3,iVar2,&uStack_8,&uStack_c);
        if (iVar4 != 0) {
          _ipc_right_destroy(iVar3,uStack_8,uStack_c);
        }
      }
      _ipc_port_release_send(iVar2);
    }
    _ipc_port_dealloc_special(iVar1,_ipc_space_kernel);
  }
  return;
}
