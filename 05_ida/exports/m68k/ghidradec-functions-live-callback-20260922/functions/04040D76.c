
int * _ipc_port_lock_mqueue(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      return piVar1 + 3;
    }
    _ipc_pset_remove(piVar1,param_1);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  return (int *)(param_1 + 0x3c);
}

