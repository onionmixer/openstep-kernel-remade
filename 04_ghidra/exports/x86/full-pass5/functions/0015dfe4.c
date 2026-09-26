/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015dfe4 */

void _mfs_init(void)

{
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  DAT_001f64d4 = &_vm_info_queue;
  _vm_info_queue = &_vm_info_queue;
  _vm_info_lock_data = 0;
  _lock_init(&_mfs_alloc_lock_data,1);
  _mfs_alloc_wanted = 0;
  _mfs_map = _kmem_suballoc(_kernel_map,local_8,local_c,_mfs_map_size,1);
  _mfs_map_size = DAT_001f6350;
  if (0x1000000 < DAT_001f6350) {
    _mfs_map_size = 0x1000000;
  }
  if (_mfs_max_window == 0) {
    _mfs_max_window = _mfs_map_size / 0x14;
  }
  if (_mfs_max_window < 0x10000) {
    _mfs_max_window = 0x10000;
  }
  _vm_info_zone = _zinit(0x3c,600000,0x2000,0,s_vm_info_zone_001def68);
  return;
}

