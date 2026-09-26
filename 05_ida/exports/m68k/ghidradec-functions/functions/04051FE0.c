
void _task_deallocate(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, *param_1 = iVar1 + -1, iVar1 == 1)) {
    iVar1 = param_1[9];
    _pset_remove_task(iVar1,param_1);
    _pset_deallocate(iVar1);
    _vm_map_deallocate(param_1[2]);
    _ipc_space_release(param_1[0x1f]);
    _utask_free(param_1[0xc]);
    _zfree(_task_zone,param_1);
  }
  return;
}
