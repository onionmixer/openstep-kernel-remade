
int sub_402A56C(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,int param_7,uint param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined auStack_c2 [64];
  undefined auStack_82 [68];
  undefined auStack_3e [58];
  
  iVar4 = 0;
  puVar1 = (undefined4 *)_kalloc(0x6e);
  _bzero(puVar1,0x6e);
  *(byte *)(puVar1 + 5) =
       *(byte *)(puVar1 + 5) & 0x5f | (byte)(((param_8 ^ 1) & 1) << 7) |
       (byte)(((param_8 & 0x7f) >> 6) << 5);
  *puVar1 = *param_3;
  puVar1[1] = param_3[1];
  puVar1[2] = param_3[2];
  puVar1[3] = param_3[3];
  *(undefined4 *)((int)puVar1 + 0x2e) = 5;
  *(undefined4 *)((int)puVar1 + 0x2a) = 0xb;
  uVar2 = _vfs_getnum(unk_40B3534,0x20);
  *(undefined4 *)((int)puVar1 + 0x26) = uVar2;
  _bcopy(param_5,(int)puVar1 + 0x32,0x20);
  *(undefined4 *)((int)puVar1 + 0x5e) = 3;
  *(undefined4 *)((int)puVar1 + 0x62) = 0x3c;
  *(undefined4 *)((int)puVar1 + 0x66) = 0x1e;
  *(undefined4 *)((int)puVar1 + 0x6a) = 0x3c;
  if ((param_8 & 0x1000) == 0) {
    *(undefined4 *)((int)puVar1 + 0x5a) = 1;
    *(int *)((int)puVar1 + 0x56) = param_7;
    if (-1 < param_7) {
      uVar2 = _kalloc(param_7);
      *(undefined4 *)((int)puVar1 + 0x52) = uVar2;
      _bcopy(param_6,uVar2,param_7);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)((int)puVar1 + 0x26);
    *(undefined4 *)(param_2 + 0x18) = 1;
    *(undefined4 **)(param_2 + 0x126) = puVar1;
    iVar4 = _makenfsnode(param_4,0,param_2);
    if ((*(word *)(iVar4 + 4) & 1) == 0) {
      *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) | 1;
      iVar3 = (**(code **)(*(int *)(iVar4 + 0x1c) + 0x14))
                        (iVar4,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
      if (iVar3 == 0) {
        _vn_rele(iVar4);
        _vattr_to_nattr(auStack_3e,auStack_82);
        iVar4 = _makenfsnode(param_4,auStack_82,param_2);
        *(word *)(iVar4 + 4) = *(word *)(iVar4 + 4) | 1;
        puVar1[4] = iVar4;
        iVar3 = (**(code **)(*(int *)(param_2 + 4) + 0xc))(param_2,auStack_c2);
        if (iVar3 == 0) {
          uVar2 = _nfstsize();
          uVar2 = _min(0x2000,uVar2);
          *(undefined4 *)((int)puVar1 + 0x1a) = uVar2;
          *(undefined4 *)((int)puVar1 + 0x22) = 0x2000;
          *(undefined4 *)(param_2 + 0x10) = 0x2000;
          **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
          *(undefined4 *)(*(int *)(iVar4 + 0x2e) + 0x6c) = *(undefined4 *)(_active_u + 0x1a);
          *param_1 = iVar4;
          return 0;
        }
      }
      goto loc_402A744;
    }
  }
  iVar3 = 0x16;
loc_402A744:
  if (puVar1 != (undefined4 *)0x0) {
    if (-1 < *(int *)((int)puVar1 + 0x56)) {
      _kfree(*(undefined4 *)((int)puVar1 + 0x52),*(int *)((int)puVar1 + 0x56));
    }
    _kfree(puVar1,0x6e);
  }
  if (iVar4 != 0) {
    _vn_rele(iVar4);
  }
  *param_1 = 0;
  return iVar3;
}

