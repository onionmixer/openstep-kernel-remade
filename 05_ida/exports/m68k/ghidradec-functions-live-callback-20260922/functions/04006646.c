
void _utask_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x152);
  if (iVar1 != 0) {
    _kfree(*(undefined4 *)(param_1 + 0x146),iVar1 << 2);
    _kfree(*(undefined4 *)(param_1 + 0x14a),iVar1);
    *(undefined4 *)(param_1 + 0x152) = 0;
  }
  _zfree(_u_task_zone,param_1);
  return;
}

