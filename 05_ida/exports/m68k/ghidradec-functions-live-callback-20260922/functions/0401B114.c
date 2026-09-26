
/* WARNING: Type propagation algorithm not settling */

int _vn_open(undefined4 param_1,undefined4 param_2,uint param_3,undefined2 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined auStack_7c [20];
  undefined4 uStack_68;
  int aiStack_42 [2];
  undefined2 uStack_3a;
  undefined4 uStack_2a;
  
  uVar3 = 0;
  if ((param_3 & 1) != 0) {
    uVar3 = 0x100;
  }
  if ((param_3 & 0x402) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  if ((param_3 & 0x200) == 0) {
    iVar2 = _lookupname(param_1,param_2,1,0,aiStack_42);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((param_3 & 0x402) != 0) {
      if (*(int *)(aiStack_42[0] + 0x28) == 2) {
        iVar2 = 0x15;
        goto loc_401B306;
      }
      if (((*(byte *)(*(int *)(aiStack_42[0] + 0x24) + 0xf) & 1) != 0) &&
         (1 < *(int *)(aiStack_42[0] + 0x28) - 3U)) {
        iVar2 = 0x1e;
        goto loc_401B306;
      }
      if (((*(byte *)(aiStack_42[0] + 5) & 2) != 0) &&
         (_vnode_uncache(aiStack_42[0]), (*(byte *)(aiStack_42[0] + 5) & 2) != 0)) {
        iVar2 = 0x1a;
        goto loc_401B306;
      }
    }
    iVar2 = (**(code **)(*(int *)(aiStack_42[0] + 0x1c) + 0x1c))
                      (aiStack_42[0],uVar3,*(undefined4 *)(_active_u + 0x1a));
    if (iVar2 != 0) goto loc_401B306;
    if (((*(byte *)(*(int *)(aiStack_42[0] + 0x24) + 0xf) & 8) != 0) &&
       (*(int *)(aiStack_42[0] + 0x28) - 3U < 2)) {
      iVar2 = 1;
      goto loc_401B306;
    }
  }
  else {
    _vattr_null(aiStack_42 + 1);
    aiStack_42[1] = 1;
    uStack_3a = param_4;
    if ((param_3 & 0x400) != 0) {
      uStack_2a = 0;
    }
    uVar1 = param_3 & 0x800;
    param_3 = param_3 & 0xfffff1ff;
    iVar2 = _vn_create(param_1,param_2,aiStack_42 + 1,uVar1 != 0,uVar3,aiStack_42);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (*(int *)(aiStack_42[0] + 0x28) == 6) {
    iVar2 = 0x2d;
  }
  else {
    iVar2 = (*(code *)**(undefined4 **)(aiStack_42[0] + 0x1c))
                      (aiStack_42,param_3,*(undefined4 *)(_active_u + 0x1a));
    if (iVar2 == 0) {
      if ((param_3 & 0x400) != 0) {
        param_3 = param_3 & 0xfffffbff;
        _vattr_null(auStack_7c);
        uStack_68 = 0;
        iVar2 = (**(code **)(*(int *)(aiStack_42[0] + 0x1c) + 0x18))
                          (aiStack_42[0],auStack_7c,*(undefined4 *)(_active_u + 0x1a));
      }
      if (iVar2 == 0) {
        if (((param_3 & 0x40000000) == 0) && (*(int *)(aiStack_42[0] + 0x28) == 1)) {
          _map_vnode(aiStack_42[0]);
        }
        *param_5 = aiStack_42[0];
        return 0;
      }
    }
  }
loc_401B306:
  _vn_rele(aiStack_42[0]);
  return iVar2;
}

