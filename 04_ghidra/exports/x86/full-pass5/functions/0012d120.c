/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012d120 */

void FUN_0012d120(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_6c;
  int local_64;
  undefined4 local_60;
  int *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined1 local_44 [6];
  short local_3e;
  
  iVar2 = FUN_0012dc2c(param_1,param_3);
  if (iVar2 == 0) {
    *param_2 = 0x46;
  }
  else {
    if (((*param_3 & 1) == 0) &&
       (((*param_3 & 2) == 0 ||
        (iVar3 = FUN_0012dc70(*(int *)(param_4 + 0x1c) + 0x10,param_3 + 6), iVar3 != 0)))) {
      if (*(int *)(iVar2 + 0x28) == 1) {
        iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                          (iVar2,local_44,*(undefined4 *)(_active_u + 0x1c));
      }
      else {
        _printf(s_rfs_write__attempt_to_write_to_n_001dbf9d);
        iVar3 = 0x15;
      }
      if (iVar3 == 0) {
        if (*(short *)(*(int *)(_active_u + 0x1c) + 2) != local_3e) {
          iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x1c))
                            (iVar2,0x80,*(int *)(_active_u + 0x1c));
        }
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x30);
          if (iVar3 == 0) {
            local_6c = 0;
            for (puVar1 = *(undefined4 **)(param_1 + 0x34); puVar1 != (undefined4 *)0x0;
                puVar1 = (undefined4 *)*puVar1) {
              local_6c = local_6c + 1;
            }
            piVar4 = (int *)_kalloc(local_6c * 8);
            FUN_0012d3b4(*(undefined4 *)(param_1 + 0x34),piVar4);
            local_50 = 1;
            local_54 = *(undefined4 *)(param_1 + 0x24);
            local_48 = *(undefined4 *)(param_1 + 0x2c);
            local_5c = piVar4;
            local_58 = local_6c;
            if (*(int *)(iVar2 + 0x28) == 1) {
              _map_vnode(iVar2);
              iVar3 = _mfs_io(iVar2,&local_5c,1,4,*(undefined4 *)(_active_u + 0x1c));
              _unmap_vnode(iVar2);
            }
            else {
              iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 8))
                                (iVar2,&local_5c,1,4,*(undefined4 *)(_active_u + 0x1c));
            }
            _kfree(piVar4,local_6c * 8);
          }
          else {
            local_60 = *(undefined4 *)(param_1 + 0x2c);
            local_5c = &local_64;
            local_58 = 1;
            local_50 = 1;
            local_54 = *(undefined4 *)(param_1 + 0x24);
            local_48 = *(undefined4 *)(param_1 + 0x2c);
            local_64 = iVar3;
            if (*(int *)(iVar2 + 0x28) == 1) {
              _map_vnode(iVar2);
              iVar3 = _mfs_io(iVar2,&local_5c,1,4,*(undefined4 *)(_active_u + 0x1c));
              _unmap_vnode(iVar2);
            }
            else {
              iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 8))
                                (iVar2,&local_5c,1,4,*(undefined4 *)(_active_u + 0x1c));
            }
          }
          (**(code **)(*(int *)(iVar2 + 0x1c) + 0x48))(iVar2,*(undefined4 *)(_active_u + 0x1c));
          if (iVar3 == 0) {
            iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                              (iVar2,local_44,*(undefined4 *)(_active_u + 0x1c));
          }
        }
      }
    }
    else {
      iVar3 = 0x1e;
    }
    *param_2 = iVar3;
    if (iVar3 == 0) {
      _vattr_to_nattr(local_44,param_2 + 1);
    }
    _vn_rele(iVar2);
  }
  return;
}

