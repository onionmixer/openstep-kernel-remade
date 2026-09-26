
undefined4 _mfs_trunc(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x34) & 8) == 0) {
    *(uint *)(iVar1 + 0x14) = param_2;
    uVar4 = 0;
  }
  else {
    _vmp_get(iVar1);
    uVar2 = ~_page_mask & _page_mask + param_2;
    uVar5 = 0;
    if (*(uint *)(iVar1 + 0x10) <= uVar2) {
      uVar5 = uVar2 - *(uint *)(iVar1 + 0x10);
    }
    if (uVar5 < *(uint *)(iVar1 + 0xc)) {
      _mfs_map_remove(iVar1,uVar5 + *(int *)(iVar1 + 8),*(uint *)(iVar1 + 0xc) + *(int *)(iVar1 + 8)
                      ,0);
      *(uint *)(iVar1 + 0xc) = uVar5;
    }
    if (uVar2 < *(uint *)(iVar1 + 0x14)) {
      _vno_flush(param_1,uVar2,*(uint *)(iVar1 + 0x14) - uVar2);
    }
    *(uint *)(iVar1 + 0x14) = param_2;
    if (uVar2 != param_2) {
      iVar3 = uVar2 - param_2;
      if ((param_2 < *(uint *)(iVar1 + 0x10)) ||
         (*(int *)(iVar1 + 0xc) + *(uint *)(iVar1 + 0x10) < iVar3 + param_2)) {
        _remap_vnode(param_1,param_2,iVar3);
      }
      _bzero((param_2 + *(int *)(iVar1 + 8)) - *(int *)(iVar1 + 0x10),iVar3);
      *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + 1;
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x40;
      _vmp_push(iVar1);
      *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + -1;
    }
    _vmp_put(iVar1);
    uVar4 = 1;
  }
  return uVar4;
}

