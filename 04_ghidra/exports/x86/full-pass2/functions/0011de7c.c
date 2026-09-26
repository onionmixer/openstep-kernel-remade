/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011de7c */

int _vn_rdwr(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  if ((param_1 == 1) && ((*(byte *)(*(int *)(param_2 + 0x24) + 0xc) & 1) != 0)) {
    iVar1 = 0x1e;
  }
  else {
    local_24 = param_3;
    local_20 = param_4;
    local_1c = &local_24;
    local_18 = 1;
    local_14 = param_5;
    local_10 = param_6;
    local_8 = param_4;
    if ((*(int *)(param_2 + 0x28) == 1) && ((*(byte *)(*_active_u + 0x16) & 2) == 0)) {
      _map_vnode(param_2);
      iVar1 = _mfs_io(param_2,&local_1c,param_1,param_7,_active_u[7]);
      _unmap_vnode(param_2);
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 8))
                        (param_2,&local_1c,param_1,param_7,_active_u[7]);
    }
    if (param_8 == (int *)0x0) {
      if ((local_8 != 0) && (iVar1 == 0)) {
        iVar1 = 5;
      }
    }
    else {
      *param_8 = local_8;
    }
  }
  return iVar1;
}

