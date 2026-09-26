/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c4b8 */

int _nfsgetattr(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_10;
  int local_c;
  int local_8;
  
  iVar5 = param_1[0xc];
  _getthetime(&local_c);
  if ((local_c < *(int *)(iVar5 + 0xc0)) ||
     ((local_c == *(int *)(iVar5 + 0xc0) && (local_8 < *(int *)(iVar5 + 0xc4))))) {
    piVar3 = (int *)(iVar5 + 0x80);
    piVar6 = param_2;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar6 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar6 = piVar6 + 1;
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1[9] + 0x128) + 0x28);
    param_2[3] = CONCAT22((short)((uint)uVar1 >> 0x10),CONCAT11(0xff,(char)uVar1));
    uVar2 = *(uint *)(*param_1 + 0x14);
    if (((uint)param_2[6] < uVar2) &&
       (((*(byte *)(*param_1 + 0x38) & 2) != 0 || ((*(byte *)(iVar5 + 0x60) & 0x10) != 0)))) {
      param_2[6] = uVar2;
    }
    local_10 = 0;
  }
  else {
    piVar3 = (int *)_kalloc(0x48);
    local_10 = _rfscall(*(undefined4 *)(param_1[9] + 0x128),1,_xdr_fhandle,param_1[0xc] + 0x40,
                        _xdr_attrstat,piVar3,param_3);
    if (local_10 == 0) {
      local_10 = *piVar3;
      if (local_10 == 0) {
        _nattr_to_vattr(param_1,piVar3 + 1,param_2);
        uVar1 = *(undefined4 *)(*(int *)(param_1[9] + 0x128) + 0x28);
        param_2[3] = CONCAT22((short)((uint)uVar1 >> 0x10),CONCAT11(0xff,(char)uVar1));
      }
      else if (local_10 == 0x46) {
        _btrash(param_1);
        _vnode_uncache(param_1);
        _mfs_invalidate(param_1);
        *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
        _dnlc_purge_vp(param_1);
        _binvalfree(param_1);
      }
    }
    _kfree(piVar3,0x48);
    if (local_10 == 0) {
      iVar5 = param_1[0xc];
      if ((-1 < *(char *)(iVar5 + 0x10)) &&
         (((*(int *)(iVar5 + 0xa8) != param_2[10] || (*(int *)(iVar5 + 0xac) != param_2[0xb])) ||
          (*(int *)(iVar5 + 0x98) != param_2[6])))) {
        _sync_vp_invalidate(param_1,param_4);
        _vnode_uncache(param_1);
        *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
        _dnlc_purge_vp(param_1);
        _binvalfree(param_1);
      }
      if (((*(byte *)(param_1 + 1) & 0x40) == 0) &&
         ((*(byte *)(*(int *)(param_1[9] + 0x128) + 0x14) & 0x10) == 0)) {
        piVar3 = param_2;
        piVar6 = (int *)(param_1[0xc] + 0x80);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        param_1[10] = *param_2;
        FUN_0012c380(param_1);
      }
    }
  }
  param_2[6] = *(int *)(param_1[0xc] + 0x98);
  return local_10;
}

