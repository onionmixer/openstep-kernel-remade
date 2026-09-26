
void _ipc_kmsg_put_to_kernel(undefined4 param_1,int param_2,undefined4 param_3)

{
  _bcopy(param_2 + 0x14,param_1,param_3);
  if (*(int *)(param_2 + 8) < 1) {
    _ipc_kmsg_free(param_2);
  }
  else {
    _kfree(param_2,*(int *)(param_2 + 8));
  }
  return;
}

