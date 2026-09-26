
void _mfs_map_remove(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    _vmp_push(param_1);
  }
  _lock_write(&_mfs_alloc_lock_data);
  _vm_map_remove(_mfs_map,param_2,param_3);
  if (_mfs_alloc_wanted != 0) {
    _mfs_alloc_wanted = 0;
    _thread_wakeup_prim(&_mfs_map,0,0);
  }
  _lock_done(&_mfs_alloc_lock_data);
  if (*(int *)(param_1 + 0x20) != 0) {
    _vm_object_deactivate_pages(*(int *)(param_1 + 0x20));
  }
  return;
}
