
undefined4 _ipc_mqueue_copyin(int param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 4) != 0) &&
     (puVar2 = (uint *)_ipc_entry_lookup(param_1,param_2), puVar2 != (uint *)0x0)) {
    piVar1 = (int *)puVar2[1];
    if ((*puVar2 & 0x20000) == 0) {
      if ((*puVar2 & 0x80000) == 0) {
        return 0x10004002;
      }
      piVar3 = piVar1 + 3;
    }
    else {
      piVar3 = (int *)piVar1[0xb];
      if (piVar3 != (int *)0x0) {
        if (piVar3[1] < 0) {
          return 0x1000400a;
        }
        _ipc_pset_remove(piVar3,piVar1);
        if (*piVar3 == 0) {
          _zfree((&_ipc_object_zones)[*(word *)(piVar3 + 1) & 0x7fff],piVar3);
        }
      }
      piVar3 = piVar1 + 0xf;
    }
    *piVar1 = *piVar1 + 1;
    *param_4 = (uint)piVar1;
    *param_3 = piVar3;
    return 0;
  }
  return 0x10004002;
}
