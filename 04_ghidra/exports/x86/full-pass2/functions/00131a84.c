/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131a84 */

int FUN_00131a84(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [32];
  undefined1 local_24 [32];
  
  piVar1 = (int *)_kalloc(0x48);
  if (((((*(short *)(param_2 + 0x14) == -1) && (*(int *)(param_2 + 0x1c) == -1)) &&
       (*(short *)(param_2 + 0x38) == -1)) &&
      ((*(int *)(param_2 + 0x3c) == -1 && (*(int *)(param_2 + 0x30) == -1)))) &&
     (*(int *)(param_2 + 0x34) == -1)) {
    _sync_vp(param_1);
    if (*(int *)(param_2 + 0x18) != -1) {
      iVar2 = _mfs_trunc(param_1,*(int *)(param_2 + 0x18));
      if (iVar2 != 0) {
        _sync_vp(param_1);
      }
      *(undefined4 *)(*param_1 + 0x14) = *(undefined4 *)(param_2 + 0x18);
      _binvalfree(param_1);
      *(undefined4 *)(param_1[0xc] + 0x98) = *(undefined4 *)(param_2 + 0x18);
    }
    if ((*(int *)(param_2 + 0x28) != -1) && (*(int *)(param_2 + 0x2c) == -1)) {
      _getthetime(&local_4c);
      *(undefined4 *)(param_2 + 0x20) = local_4c;
      *(undefined4 *)(param_2 + 0x24) = local_48;
      *(undefined4 *)(param_2 + 0x28) = local_4c;
      *(undefined4 *)(param_2 + 0x2c) = 1000000;
    }
    _vattr_to_sattr(param_2,local_24);
    _bcopy((void *)(param_1[0xc] + 0x40),local_44,0x20);
    iVar2 = _rfscall(*(undefined4 *)(param_1[9] + 0x128),2,_xdr_saargs,local_44,_xdr_attrstat,piVar1
                     ,param_3);
    if (iVar2 == 0) {
      iVar2 = *piVar1;
      if (iVar2 == 0) {
        _nfs_cache_check(param_1,piVar1[0xe],piVar1[0xf],piVar1[6],2);
        _nfs_attrcache(param_1,piVar1 + 1);
      }
      else {
        *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
        if (iVar2 == 0x46) {
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
        }
      }
    }
    else {
      *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
    }
  }
  else {
    iVar2 = 0x16;
  }
  _kfree(piVar1,0x48);
  return iVar2;
}

