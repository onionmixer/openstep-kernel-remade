
undefined4 _ipc_kmsg_put(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0x10) = 0;
  iVar1 = _copyoutmsg(param_2 + 0x14,param_1,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x10004008;
  }
  if ((*(int *)(param_2 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
    _ipc_kmsg_cache = param_2;
  }
  else if (*(int *)(param_2 + 8) < 1) {
    _ipc_kmsg_free(param_2);
  }
  else {
    _kfree(param_2,*(int *)(param_2 + 8));
  }
  return uVar2;
}

