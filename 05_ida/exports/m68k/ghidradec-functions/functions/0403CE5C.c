
void _ipc_kmsg_destroy(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(_active_threads + 0xa0);
  iVar1 = *piVar2;
  _ipc_kmsg_enqueue(piVar2,param_1);
  if (iVar1 == 0) {
    while (iVar1 = *piVar2, iVar1 != 0) {
      _ipc_kmsg_clean(iVar1);
      _ipc_kmsg_rmqueue(piVar2,iVar1);
      if (*(int *)(iVar1 + 8) < 1) {
        _ipc_kmsg_free(iVar1);
      }
      else {
        _kfree(iVar1,*(int *)(iVar1 + 8));
      }
    }
  }
  return;
}
