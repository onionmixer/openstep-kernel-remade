/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011df9c */

/* WARNING: Type propagation algorithm not settling */

int _vn_open(undefined4 param_1,undefined4 param_2,uint param_3,undefined2 param_4,int *param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_90;
  undefined1 local_88 [24];
  undefined4 local_70;
  int local_48 [2];
  undefined2 local_40;
  undefined4 local_2c;
  
  local_90 = 0;
  if ((param_3 & 1) != 0) {
    local_90 = 0x100;
  }
  if ((param_3 & 0x402) != 0) {
    local_90 = CONCAT31(local_90._1_3_,0x80);
  }
  if ((param_3 & 0x200) == 0) {
    iVar3 = _lookupname(param_1,param_2,1,0,local_48);
    if (iVar3 != 0) {
      return iVar3;
    }
    if ((param_3 & 0x402) != 0) {
      if (*(int *)(local_48[0] + 0x28) == 2) {
        iVar3 = 0x15;
        goto LAB_0011e1ac;
      }
      if (((*(byte *)(*(int *)(local_48[0] + 0x24) + 0xc) & 1) != 0) &&
         (1 < *(int *)(local_48[0] + 0x28) - 3U)) {
        iVar3 = 0x1e;
        goto LAB_0011e1ac;
      }
      if (((*(byte *)(local_48[0] + 4) & 2) != 0) &&
         (_vnode_uncache(local_48[0]), (*(byte *)(local_48[0] + 4) & 2) != 0)) {
        iVar3 = 0x1a;
        goto LAB_0011e1ac;
      }
    }
    iVar3 = (**(code **)(*(int *)(local_48[0] + 0x1c) + 0x1c))
                      (local_48[0],local_90,*(undefined4 *)(_active_u + 0x1c));
    if (iVar3 != 0) goto LAB_0011e1ac;
    if (((*(byte *)(*(int *)(local_48[0] + 0x24) + 0xc) & 8) != 0) &&
       (*(int *)(local_48[0] + 0x28) - 3U < 2)) {
      iVar3 = 1;
      goto LAB_0011e1ac;
    }
  }
  else {
    _vattr_null(local_48 + 1);
    local_48[1] = 1;
    local_40 = param_4;
    if ((param_3 & 0x400) != 0) {
      local_2c = 0;
    }
    uVar2 = param_3 & 0x800;
    param_3 = param_3 & 0xfffff1ff;
    iVar3 = _vn_create(param_1,param_2,local_48 + 1,uVar2 != 0,local_90,local_48);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  if (*(int *)(local_48[0] + 0x28) == 6) {
    iVar3 = 0x2d;
  }
  else {
    iVar3 = (*(code *)**(undefined4 **)(local_48[0] + 0x1c))
                      (local_48,param_3,*(undefined4 *)(_active_u + 0x1c));
    if (iVar3 == 0) {
      if ((param_3 & 0x400) != 0) {
        param_3 = param_3 & 0xfffffbff;
        _vattr_null(local_88);
        local_70 = 0;
        iVar3 = (**(code **)(*(int *)(local_48[0] + 0x1c) + 0x18))
                          (local_48[0],local_88,*(undefined4 *)(_active_u + 0x1c));
      }
      if (iVar3 == 0) {
        if (((param_3 & 0x40000000) == 0) && (*(int *)(local_48[0] + 0x28) == 1)) {
          _map_vnode(local_48[0]);
        }
        *param_5 = local_48[0];
        return 0;
      }
    }
  }
LAB_0011e1ac:
  if (*(short *)(local_48[0] + 6) != 0) {
    sVar1 = *(short *)(local_48[0] + 6);
    *(short *)(local_48[0] + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      (**(code **)(*(int *)(local_48[0] + 0x1c) + 0x4c))
                (local_48[0],*(undefined4 *)(_active_u + 0x1c));
    }
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vn_rele_001db786);
}

