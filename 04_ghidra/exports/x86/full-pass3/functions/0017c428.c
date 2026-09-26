/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c428 */

undefined4 _gc_control(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  pbVar1 = *(byte **)(DAT_001e875c + 0x24);
  iVar2 = _suser();
  uVar3 = 0;
  if (iVar2 != 0) {
    do {
    } while (_gc_lock != 0);
    LOCK();
    UNLOCK();
    if (_gc_active == 0) {
      _gc_active = 1;
      LOCK();
      _gc_lock = 0;
      UNLOCK();
      if ((*pbVar1 & 1) != 0) {
        _mfs_cache_clear();
        _vm_object_cache_clear();
        _inode_cache_clear();
        _rnode_cache_clear();
        _proc_cache_clear();
      }
      if ((*pbVar1 & 2) != 0) {
        _zone_gc();
      }
      if ((*pbVar1 & 4) != 0) {
        _zone_reclaim();
      }
      do {
      } while (_gc_lock != 0);
      LOCK();
      UNLOCK();
      _gc_active = 0;
    }
    LOCK();
    uVar3 = 1;
    _gc_lock = 0;
    UNLOCK();
  }
  return uVar3;
}

