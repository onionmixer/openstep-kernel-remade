
void _ipc_kmsg_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == -3) {
    _netipc_msg_release(param_1);
  }
  else if (iVar1 != -1) {
    _kfree(param_1,iVar1);
  }
  return;
}

