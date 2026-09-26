
void _gc_control(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if ((iVar2 != 0) && (_gc_active == 0)) {
    _gc_active = 1;
    if ((*(byte *)(iVar1 + 3) & 1) != 0) {
      _mfs_cache_clear();
      _vm_object_cache_clear();
      _inode_cache_clear();
      _rnode_cache_clear();
      _proc_cache_clear();
    }
    if ((*(byte *)(iVar1 + 3) & 2) != 0) {
      _zone_gc();
    }
    if ((*(byte *)(iVar1 + 3) & 4) != 0) {
      _zone_reclaim();
    }
    _gc_active = 0;
  }
  return;
}

