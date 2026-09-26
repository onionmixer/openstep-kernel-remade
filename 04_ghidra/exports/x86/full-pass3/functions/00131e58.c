/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131e58 */

int FUN_00131e58(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_28 [36];
  
  iVar2 = _nfs_validate_caches(param_1,param_4,0);
  if (iVar2 != 0) {
    return iVar2;
  }
  _rlock(*(undefined4 *)(param_1 + 0x30));
  iVar2 = _dnlc_lookup(param_1,param_2,param_4);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    piVar4 = (int *)_kalloc(0x68);
    _bzero(piVar4,0x68);
    _setdiropargs(local_28,param_2,param_1);
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),4,_xdr_diropargs,local_28,
                     _xdr_diropres,piVar4,param_4);
    if (iVar2 == 0) {
      iVar2 = *piVar4;
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 != 0) goto LAB_00131f78;
      iVar3 = _makenfsnode(piVar4 + 1,piVar4 + 9,*(undefined4 *)(param_1 + 0x24));
      *param_3 = iVar3;
      if (_nfs_dnlc != 0) {
        _dnlc_enter(param_1,param_2,iVar3,param_4);
      }
    }
    else {
LAB_00131f78:
      *param_3 = 0;
    }
    _kfree(piVar4,0x68);
    if (iVar2 != 0) goto LAB_00131fcc;
  }
  else {
    *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;
    iVar3 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,param_4);
    iVar2 = 0;
    if (iVar3 != 0) {
      _vn_rele(*param_3);
      _runlock(*(undefined4 *)(param_1 + 0x30));
      return iVar3;
    }
  }
  iVar3 = *param_3;
  iVar1 = *(int *)(iVar3 + 0x28);
  if ((iVar1 - 3U < 2) || (iVar1 == 8)) {
    iVar3 = _specvp(iVar3,(int)*(short *)(iVar3 + 0x2c),iVar1);
    _vn_rele(*param_3);
    *param_3 = iVar3;
  }
LAB_00131fcc:
  _runlock(*(undefined4 *)(param_1 + 0x30));
  return iVar2;
}

