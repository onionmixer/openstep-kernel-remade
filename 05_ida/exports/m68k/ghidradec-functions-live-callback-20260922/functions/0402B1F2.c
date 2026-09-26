
int sub_402B1F2(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined auStack_44 [32];
  undefined auStack_24 [32];
  
  piVar1 = (int *)_kalloc(0x48);
  if (((((*(sword *)(param_2 + 0x12) == -1) && (*(int *)(param_2 + 0x18) == -1)) &&
       (*(sword *)(param_2 + 0x34) == -1)) &&
      ((*(int *)(param_2 + 0x36) == -1 && (*(int *)(param_2 + 0x2c) == -1)))) &&
     (*(int *)(param_2 + 0x30) == -1)) {
    _sync_vp(param_1);
    if (*(int *)(param_2 + 0x14) != -1) {
      iVar2 = _mfs_trunc(param_1,*(int *)(param_2 + 0x14));
      if (iVar2 != 0) {
        _sync_vp(param_1);
      }
      *(undefined4 *)(*param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
      _binvalfree(param_1);
      *(undefined4 *)(*(int *)((int)param_1 + 0x2e) + 0x90) = *(undefined4 *)(param_2 + 0x14);
    }
    if ((*(int *)(param_2 + 0x24) != -1) && (*(int *)(param_2 + 0x28) == -1)) {
      _getthetime(&uStack_4c);
      *(undefined4 *)(param_2 + 0x1c) = uStack_4c;
      *(undefined4 *)(param_2 + 0x20) = uStack_48;
      *(undefined4 *)(param_2 + 0x24) = uStack_4c;
      *(undefined4 *)(param_2 + 0x28) = 1000000;
    }
    _vattr_to_sattr(param_2,auStack_24);
    _bcopy(*(int *)((int)param_1 + 0x2e) + 0x3e,auStack_44,0x20);
    iVar2 = _rfscall(*(undefined4 *)(param_1[9] + 0x126),2,_xdr_saargs,auStack_44,_xdr_attrstat,
                     piVar1,param_3);
    if (iVar2 == 0) {
      iVar2 = *piVar1;
      if (iVar2 == 0) {
        _nfs_cache_check(param_1,piVar1[0xe],piVar1[0xf],piVar1[6],2);
        _nfs_attrcache(param_1,piVar1 + 1);
      }
      else {
        *(undefined4 *)(*(int *)((int)param_1 + 0x2e) + 0xb6) = 0;
        if (iVar2 == 0x46) {
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
        }
      }
    }
    else {
      *(undefined4 *)(*(int *)((int)param_1 + 0x2e) + 0xb6) = 0;
    }
  }
  else {
    iVar2 = 0x16;
  }
  _kfree(piVar1,0x48);
  return iVar2;
}

