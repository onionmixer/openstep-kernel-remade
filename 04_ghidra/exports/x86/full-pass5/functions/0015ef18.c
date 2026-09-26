/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ef18 */

undefined4 _mfs_map_remove(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_4 != 0) {
    _vmp_push(param_1);
  }
  _lock_write(&_mfs_alloc_lock_data);
  _vm_map_remove(_mfs_map,param_2,param_3);
  if (_mfs_alloc_wanted != 0) {
    _mfs_alloc_wanted = 0;
    _thread_wakeup_prim(&_mfs_map,0,0);
  }
  uVar4 = _lock_done(&_mfs_alloc_lock_data);
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 != 0) {
    piVar1 = (int *)(iVar3 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    _vm_object_deactivate_pages(iVar3);
    LOCK();
    uVar4 = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar3 + 0x10) = 0;
    UNLOCK();
  }
  return uVar4;
}

