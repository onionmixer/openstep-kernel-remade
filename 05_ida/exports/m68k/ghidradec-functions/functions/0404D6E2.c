
void _mfs_cache_trim(void)

{
  undefined4 uVar1;
  
  while (uVar1 = _vm_info_queue, _mfs_files_max < _mfs_files_mapped) {
    _vm_info_dequeue(_vm_info_queue);
    _mfs_memfree(uVar1,1);
  }
  return;
}
