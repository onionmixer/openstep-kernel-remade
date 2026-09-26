/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132b78 */

int FUN_00132b78(int param_1,undefined4 param_2,int param_3,int *param_4,undefined4 param_5)

{
  short sVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  undefined1 local_48 [36];
  undefined1 local_24 [32];
  
  piVar3 = (int *)_kalloc(0x68);
  _bzero(piVar3,0x68);
  _setdiropargs(local_48,param_2,param_1);
  uVar2 = _setdirgid(param_1);
  *(undefined2 *)(param_3 + 8) = uVar2;
  uVar2 = _setdirmode(param_1,*(undefined2 *)(param_3 + 4));
  *(undefined2 *)(param_3 + 4) = uVar2;
  _vattr_to_sattr(param_3,local_24);
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_remove(param_1,param_2);
  local_94 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0xe,_xdr_creatargs,local_48,
                      _xdr_diropres,piVar3,param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x30));
  if (local_94 == 0) {
    local_94 = *piVar3;
    if (local_94 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    if (local_94 == 0) {
      iVar4 = _makenfsnode(piVar3 + 1,piVar3 + 9,*(undefined4 *)(param_1 + 0x24));
      *param_4 = iVar4;
      *(undefined4 *)(*(int *)(iVar4 + 0x30) + 0xc0) = 0;
      if (_nfs_dnlc != 0) {
        _dnlc_enter(param_1,param_2,*param_4,param_5);
      }
      sVar1 = *(short *)(param_3 + 8);
      _nattr_to_vattr(*param_4,piVar3 + 9,param_3);
      if (*(short *)(param_3 + 8) != sVar1) {
        _vattr_null(param_3);
        *(short *)(param_3 + 8) = sVar1;
        param_4 = (int *)*param_4;
        piVar5 = (int *)_kalloc(0x48);
        if (((((*(short *)(param_3 + 0x14) == -1) && (*(int *)(param_3 + 0x1c) == -1)) &&
             (*(short *)(param_3 + 0x38) == -1)) &&
            ((*(int *)(param_3 + 0x3c) == -1 && (*(int *)(param_3 + 0x30) == -1)))) &&
           (*(int *)(param_3 + 0x34) == -1)) {
          _sync_vp(param_4);
          if (*(int *)(param_3 + 0x18) != -1) {
            iVar4 = _mfs_trunc(param_4,*(int *)(param_3 + 0x18));
            if (iVar4 != 0) {
              _sync_vp(param_4);
            }
            *(undefined4 *)(*param_4 + 0x14) = *(undefined4 *)(param_3 + 0x18);
            _binvalfree(param_4);
            *(undefined4 *)(param_4[0xc] + 0x98) = *(undefined4 *)(param_3 + 0x18);
          }
          if ((*(int *)(param_3 + 0x28) != -1) && (*(int *)(param_3 + 0x2c) == -1)) {
            _getthetime(&local_90);
            *(undefined4 *)(param_3 + 0x20) = local_90;
            *(undefined4 *)(param_3 + 0x24) = local_8c;
            *(undefined4 *)(param_3 + 0x28) = local_90;
            *(undefined4 *)(param_3 + 0x2c) = 1000000;
          }
          _vattr_to_sattr(param_3,local_68);
          _bcopy((void *)(param_4[0xc] + 0x40),local_88,0x20);
          iVar4 = _rfscall(*(undefined4 *)(param_4[9] + 0x128),2,_xdr_saargs,local_88,_xdr_attrstat,
                           piVar5,param_5);
          if (iVar4 == 0) {
            iVar4 = *piVar5;
            if (iVar4 == 0) {
              _nfs_cache_check(param_4,piVar5[0xe],piVar5[0xf],piVar5[6],2);
              _nfs_attrcache(param_4,piVar5 + 1);
            }
            else {
              *(undefined4 *)(param_4[0xc] + 0xc0) = 0;
              if (iVar4 == 0x46) {
                _btrash(param_4);
                _nfs_invalidate_caches(param_4);
              }
            }
          }
          else {
            *(undefined4 *)(param_4[0xc] + 0xc0) = 0;
          }
        }
        _kfree(piVar5,0x48);
      }
      goto LAB_00132eb5;
    }
  }
  *param_4 = 0;
LAB_00132eb5:
  _kfree(piVar3,0x68);
  return local_94;
}

