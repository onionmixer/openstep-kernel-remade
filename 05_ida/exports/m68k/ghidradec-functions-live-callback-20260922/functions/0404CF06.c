
void _mfs_init(void)

{
  double dVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  dword_40C23D0 = &_vm_info_queue;
  _vm_info_queue = &_vm_info_queue;
  _lock_init(&_mfs_alloc_lock_data,1);
  _mfs_alloc_wanted = 0;
  _mfs_map = _kmem_suballoc(_kernel_map,auStack_8,auStack_c,_mfs_map_size,1);
  dVar1 = (double)dword_40C22D8;
  if (dword_40C22D8 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  _mfs_map_size = (uint)dVar1;
  if (0x1000000 < _mfs_map_size) {
    _mfs_map_size = 0x1000000;
  }
  if (_mfs_max_window == 0) {
    _mfs_max_window = _mfs_map_size / 0x14;
  }
  if (_mfs_max_window < 0x10000) {
    _mfs_max_window = 0x10000;
  }
  _vm_info_zone = _zinit(0x36,540000,0x2000,0,aVmInfoZone);
  return;
}

