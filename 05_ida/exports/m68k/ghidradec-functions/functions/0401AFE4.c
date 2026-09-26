
int _vn_rdwr(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  if ((param_1 == 1) && ((*(byte *)(*(int *)(param_2 + 0x24) + 0xf) & 1) != 0)) {
    iVar1 = 0x1e;
  }
  else {
    uStack_22 = param_3;
    iStack_1e = param_4;
    puStack_1a = &uStack_22;
    uStack_16 = 1;
    uStack_12 = param_5;
    uStack_e = param_6;
    iStack_8 = param_4;
    if ((*(int *)(param_2 + 0x28) == 1) && ((*(byte *)(*_active_u + 0x16) & 0x40) == 0)) {
      _map_vnode(param_2);
      iVar1 = _mfs_io(param_2,&puStack_1a,param_1,param_7,*(undefined4 *)((int)_active_u + 0x1a));
      _unmap_vnode(param_2);
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 8))
                        (param_2,&puStack_1a,param_1,param_7,*(undefined4 *)((int)_active_u + 0x1a))
      ;
    }
    if (param_8 == (int *)0x0) {
      if ((iStack_8 != 0) && (iVar1 == 0)) {
        iVar1 = 5;
      }
    }
    else {
      *param_8 = iStack_8;
    }
  }
  return iVar1;
}
