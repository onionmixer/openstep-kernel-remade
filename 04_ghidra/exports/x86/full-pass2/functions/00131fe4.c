/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131fe4 */

int FUN_00131fe4(int param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                int *param_6,undefined4 param_7)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int local_104;
  int local_f4;
  undefined4 local_f0;
  undefined1 local_ec [32];
  undefined1 local_cc [32];
  undefined1 local_ac [8];
  short local_a4;
  short local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  short local_74;
  int local_70;
  undefined1 local_6c [36];
  undefined1 local_48 [36];
  undefined1 local_24 [32];
  
  if (param_4 == 1) {
    local_104 = _nfs_validate_caches(param_1,param_7,0);
    if (local_104 == 0) {
      _rlock(*(undefined4 *)(param_1 + 0x30));
      iVar6 = _dnlc_lookup(param_1,param_2,param_7);
      *param_6 = iVar6;
      if (iVar6 == 0) {
        piVar5 = (int *)_kalloc(0x68);
        _bzero(piVar5,0x68);
        _setdiropargs(local_6c,param_2,param_1);
        local_104 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),4,_xdr_diropargs,
                             local_6c,_xdr_diropres,piVar5,param_7);
        if (local_104 == 0) {
          local_104 = *piVar5;
          if (local_104 == 0x46) {
            _btrash(param_1);
            _nfs_invalidate_caches(param_1);
          }
          if (local_104 != 0) goto LAB_0013213c;
          iVar6 = _makenfsnode(piVar5 + 1,piVar5 + 9,*(undefined4 *)(param_1 + 0x24));
          *param_6 = iVar6;
          if (_nfs_dnlc != 0) {
            _dnlc_enter(param_1,param_2,iVar6,param_7);
          }
        }
        else {
LAB_0013213c:
          *param_6 = 0;
        }
        _kfree(piVar5,0x68);
        if (local_104 == 0) goto LAB_00132154;
      }
      else {
        *(short *)(iVar6 + 6) = *(short *)(iVar6 + 6) + 1;
        local_104 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,param_7);
        if (local_104 != 0) {
          _vn_rele(*param_6);
          _runlock(*(undefined4 *)(param_1 + 0x30));
          goto LAB_0013219f;
        }
LAB_00132154:
        iVar6 = *param_6;
        iVar3 = *(int *)(iVar6 + 0x28);
        if ((iVar3 - 3U < 2) || (iVar3 == 8)) {
          iVar6 = _specvp(iVar6,(int)*(short *)(iVar6 + 0x2c),iVar3);
          _vn_rele(*param_6);
          *param_6 = iVar6;
        }
      }
      _runlock(*(undefined4 *)(param_1 + 0x30));
    }
LAB_0013219f:
    if (local_104 == 0) {
      _vn_rele(*param_6);
      return 0x11;
    }
  }
  *param_6 = 0;
  piVar5 = (int *)_kalloc(0x68);
  _bzero(piVar5,0x68);
  _setdiropargs(local_48,param_2,param_1);
  uVar4 = _setdirgid(param_1);
  *(undefined2 *)(param_3 + 2) = uVar4;
  iVar6 = *param_3;
  if (iVar6 == 4) {
    *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) | 0x2000;
  }
  else {
    if (iVar6 != 3) {
      if (iVar6 == 8) {
        *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) | 0x2000;
        param_3[6] = -1;
      }
      else if (iVar6 == 6) {
        *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) | 0xc000;
      }
      goto LAB_00132256;
    }
    *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) | 0x6000;
  }
  param_3[6] = (int)(short)param_3[0xe];
LAB_00132256:
  _vattr_to_sattr(param_3,local_24);
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_remove(param_1,param_2);
  local_104 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),9,_xdr_creatargs,local_48,
                       _xdr_diropres,piVar5,param_7);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  if (local_104 == 0) {
    local_104 = *piVar5;
    if (local_104 == 0) {
      iVar6 = _makenfsnode(piVar5 + 1,piVar5 + 9,*(undefined4 *)(param_1 + 0x24));
      *param_6 = iVar6;
      if (param_3[6] == 0) {
        *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x98) = 0;
        _mfs_trunc(*param_6,0);
        _binvalfree(*param_6);
      }
      if (_nfs_dnlc != 0) {
        _dnlc_enter(param_1,param_2,*param_6,param_7);
      }
      sVar1 = (short)param_3[2];
      _nattr_to_vattr(*param_6,piVar5 + 9,param_3);
      if ((short)param_3[2] != sVar1) {
        _vattr_null(local_ac);
        piVar2 = (int *)*param_6;
        local_a4 = sVar1;
        piVar7 = (int *)_kalloc(0x48);
        if (((((local_98 == -1) && (local_90 == -1)) && (local_74 == -1)) &&
            ((local_70 == -1 && (local_7c == -1)))) && (local_78 == -1)) {
          _sync_vp(piVar2);
          if (local_94 != -1) {
            iVar6 = _mfs_trunc(piVar2,local_94);
            if (iVar6 != 0) {
              _sync_vp(piVar2);
            }
            *(int *)(*piVar2 + 0x14) = local_94;
            _binvalfree(piVar2);
            *(int *)(piVar2[0xc] + 0x98) = local_94;
          }
          if ((local_84 != -1) && (local_80 == -1)) {
            _getthetime(&local_f4);
            local_8c = local_f4;
            local_88 = local_f0;
            local_84 = local_f4;
            local_80 = 1000000;
          }
          _vattr_to_sattr(local_ac,local_cc);
          _bcopy((void *)(piVar2[0xc] + 0x40),local_ec,0x20);
          iVar6 = _rfscall(*(undefined4 *)(piVar2[9] + 0x128),2,_xdr_saargs,local_ec,_xdr_attrstat,
                           piVar7,param_7);
          if (iVar6 == 0) {
            iVar6 = *piVar7;
            if (iVar6 == 0) {
              _nfs_cache_check(piVar2,piVar7[0xe],piVar7[0xf],piVar7[6],2);
              _nfs_attrcache(piVar2,piVar7 + 1);
            }
            else {
              *(undefined4 *)(piVar2[0xc] + 0xc0) = 0;
              if (iVar6 == 0x46) {
                _btrash(piVar2);
                _nfs_invalidate_caches(piVar2);
              }
            }
          }
          else {
            *(undefined4 *)(piVar2[0xc] + 0xc0) = 0;
          }
        }
        _kfree(piVar7,0x48);
        *(short *)(param_3 + 2) = sVar1;
      }
      iVar6 = *param_6;
      iVar3 = *(int *)(iVar6 + 0x28);
      if ((iVar3 - 3U < 2) || (iVar3 == 8)) {
        iVar6 = _specvp(iVar6,(int)*(short *)(iVar6 + 0x2c),iVar3);
        _vn_rele(*param_6);
        *param_6 = iVar6;
      }
    }
    else if (local_104 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _runlock(*(undefined4 *)(param_1 + 0x30));
  _kfree(piVar5,0x68);
  return local_104;
}

