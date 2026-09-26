
void _unmount_all(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  
  _proc_shutdown();
  _kill_tasks();
  _mfs_cache_clear();
  _vm_object_cache_clear();
  _fd_shutdown();
  _vm_object_shutdown();
  _vnode_pager_shutdown();
  puVar2 = (undefined4 *)*_rootvfs;
  while (puVar2 != (undefined4 *)0x0) {
    _printf(aUnmountingS,puVar2 + 8);
    puVar1 = (undefined4 *)*puVar2;
    iVar3 = _dounmount(puVar2);
    if (iVar3 == 0) {
      puVar4 = (undefined8 *)&aDone;
    }
    else {
      puVar4 = &aFailed;
    }
    _printf(puVar4);
    puVar2 = puVar1;
  }
  _vn_rele(_rootdir);
  iVar3 = _dounmount(_rootvfs);
  if (iVar3 != 0) {
    _printf(aRootUnmountFai);
  }
  return;
}

