/* GHIDRADEC_FUNCTION index=477 start=0x4016f48 */

int _dounmount(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = _vfs_lock(param_1);
  if (iVar2 == 0) {
    _dnlc_purge();
    (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
    iVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1);
    if (iVar2 == 0) {
      if (iVar1 != 0) {
        _vn_rele(iVar1);
        _vfs_remove(param_1);
      }
      _kfree(param_1,0x12a);
    }
    else {
      _vfs_unlock(param_1);
    }
  }
  return iVar2;
}

