
undefined4
_port_status(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if ((((param_1 == 0) || (iVar4 = _ipc_right_lookup_write(param_1,param_2,&iStack_8), iVar4 != 0))
      || (iVar4 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar4 != 0)) ||
     ((uStack_c & 0x170000) == 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) == 0) {
    *param_6 = 0;
    *param_7 = 0;
    *param_3 = 0;
    *param_4 = 0xffffffff;
    *param_5 = 0;
    return 0;
  }
  iVar4 = *(int *)(iStack_8 + 4);
  piVar1 = *(int **)(iVar4 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      iVar5 = piVar1[2];
      goto loc_40470A0;
    }
    _ipc_pset_remove(piVar1,iVar4);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  iVar5 = 0;
loc_40470A0:
  uVar2 = *(undefined4 *)(iVar4 + 0x38);
  uVar3 = *(undefined4 *)(iVar4 + 0x34);
  *param_6 = 1;
  *param_7 = 1;
  *param_3 = iVar5;
  *param_4 = uVar3;
  *param_5 = uVar2;
  return 0;
}
