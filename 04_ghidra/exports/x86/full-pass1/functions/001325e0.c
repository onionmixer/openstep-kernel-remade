/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001325e0 */

int FUN_001325e0(int param_1,undefined4 param_2,short *param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int local_5c;
  int local_58;
  int local_54;
  undefined1 local_50 [36];
  int local_2c;
  undefined1 local_28 [36];
  
  local_58 = 0;
  iVar2 = _nfs_validate_caches(param_1,param_3,0);
  if (iVar2 != 0) goto LAB_00132752;
  _rlock(*(undefined4 *)(param_1 + 0x30));
  local_2c = _dnlc_lookup(param_1,param_2,param_3);
  if (local_2c == 0) {
    piVar3 = (int *)_kalloc(0x68);
    _bzero(piVar3,0x68);
    _setdiropargs(local_50,param_2,param_1);
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),4,_xdr_diropargs,local_50,
                     _xdr_diropres,piVar3,param_3);
    if (iVar2 == 0) {
      iVar2 = *piVar3;
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 != 0) goto LAB_00132700;
      local_2c = _makenfsnode(piVar3 + 1,piVar3 + 9,*(undefined4 *)(param_1 + 0x24));
      if (_nfs_dnlc != 0) {
        _dnlc_enter(param_1,param_2,local_2c,param_3);
      }
    }
    else {
LAB_00132700:
      local_2c = 0;
    }
    _kfree(piVar3,0x68);
    if (iVar2 == 0) goto LAB_00132716;
  }
  else {
    *(short *)(local_2c + 6) = *(short *)(local_2c + 6) + 1;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,param_3);
    if (iVar2 != 0) {
      _vn_rele(local_2c);
      _runlock(*(undefined4 *)(param_1 + 0x30));
      goto LAB_00132752;
    }
LAB_00132716:
    iVar4 = *(int *)(local_2c + 0x28);
    if ((iVar4 - 3U < 2) || (iVar4 == 8)) {
      iVar4 = _specvp(local_2c,(int)*(short *)(local_2c + 0x2c),iVar4);
      _vn_rele(local_2c);
      local_2c = iVar4;
    }
  }
  _runlock(*(undefined4 *)(param_1 + 0x30));
LAB_00132752:
  if ((iVar2 == 0) &&
     (iVar4 = (**(code **)(*(int *)(local_2c + 0x1c) + 0x70))(local_2c,&local_54), iVar4 == 0)) {
    local_5c = local_2c;
    local_2c = local_54;
  }
  else {
    local_5c = 0;
  }
  if (iVar2 == 0) {
    if (local_2c != 0) {
      _rlock(*(undefined4 *)(param_1 + 0x30));
      _dnlc_purge_vp(local_2c);
      if ((*(ushort *)(local_2c + 6) < 2) || (*(int *)(*(int *)(local_2c + 0x30) + 0x7c) != 0)) {
        pbVar1 = (byte *)(*(int *)(local_2c + 0x30) + 0x60);
        *pbVar1 = *pbVar1 & 0xef;
        _setdiropargs(local_28,param_2,param_1);
        iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),10,_xdr_diropargs,
                         local_28,_xdr_enum,&local_58,param_3);
        *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
        *(undefined4 *)(*(int *)(local_2c + 0x30) + 0xc0) = 0;
        iVar4 = iVar2;
        if (iVar2 == 0) {
          iVar4 = local_58;
        }
        if (iVar4 == 0x46) {
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
        }
      }
      else {
        uVar5 = _newname();
        _runlock(*(undefined4 *)(param_1 + 0x30));
        iVar2 = FUN_00132a04(param_1,param_2,param_1,uVar5,param_3);
        _rlock(*(undefined4 *)(param_1 + 0x30));
        if (iVar2 == 0) {
          *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
          *(int *)(*(int *)(local_2c + 0x30) + 0x7c) = param_1;
          *(undefined4 *)(*(int *)(local_2c + 0x30) + 0x78) = uVar5;
          iVar4 = *(int *)(*(int *)(local_2c + 0x30) + 0x74);
          if (iVar4 != 0) {
            _crfree(iVar4);
          }
          *param_3 = *param_3 + 1;
          *(short **)(*(int *)(local_2c + 0x30) + 0x74) = param_3;
        }
        else {
          _kfree(uVar5,0xff);
        }
      }
      _runlock(*(undefined4 *)(param_1 + 0x30));
      if (local_5c == 0) {
        _bflush(local_2c,0xffffffff,0xffffffff);
        local_5c = local_2c;
      }
      else {
        _bflush(local_5c,0xffffffff,0xffffffff);
      }
      _vn_rele(local_5c);
    }
    if (iVar2 == 0) {
      iVar2 = local_58;
    }
  }
  return iVar2;
}

