
undefined4 _ipc_pset_move(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 0x2c);
  if (param_3 != piVar2) {
    if (piVar2 == (int *)0x0) {
      _ipc_pset_add(param_3,param_2);
    }
    else if (param_3 == (int *)0x0) {
      _ipc_pset_remove(piVar2,param_2);
      if (-1 < piVar2[1]) {
        if (*piVar2 == 0) {
          _zfree((&_ipc_object_zones)[(piVar2[1] & 0x7fffffffU) >> 0x10],piVar2);
        }
        piVar2 = (int *)0x0;
      }
    }
    else {
      _ipc_pset_remove(piVar2,param_2);
      _ipc_pset_add(param_3,param_2);
      if (*piVar2 == 0) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar2 + 1) & 0x7fff],piVar2);
      }
    }
  }
  uVar1 = 0;
  if ((param_3 == (int *)0x0) && (piVar2 == (int *)0x0)) {
    uVar1 = 0xc;
  }
  return uVar1;
}
