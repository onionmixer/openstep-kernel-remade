
void _vmp_put(int param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    _vm_info_enqueue(param_1);
  }
  _lock_done(param_1 + 0x18);
  if (_mfs_files_max < _mfs_files_mapped) {
    _mfs_cache_trim();
  }
  if ((*(byte *)(param_1 + 0x34) & 0x10) != 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xef;
    _vmp_invalidate(param_1);
  }
  return;
}
