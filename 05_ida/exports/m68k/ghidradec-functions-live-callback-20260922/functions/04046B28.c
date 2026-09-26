
int _mach_port_get_receive_status(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  iVar2 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  piVar1 = *(int **)(iStack_8 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      *param_3 = piVar1[2];
      goto loc_4046BA8;
    }
    _ipc_pset_remove(piVar1,iStack_8);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  *param_3 = 0;
loc_4046BA8:
  param_3[1] = *(int *)(iStack_8 + 0x30);
  param_3[2] = *(int *)(iStack_8 + 0x14);
  param_3[3] = *(int *)(iStack_8 + 0x38);
  param_3[4] = *(int *)(iStack_8 + 0x34);
  param_3[5] = *(int *)(iStack_8 + 0x1c);
  param_3[6] = -(int)-(*(int *)(iStack_8 + 0x18) != 0);
  param_3[7] = -(int)-(*(int *)(iStack_8 + 0x24) != 0);
  param_3[8] = -(int)-(*(int *)(iStack_8 + 0x20) != 0);
  return 0;
}

