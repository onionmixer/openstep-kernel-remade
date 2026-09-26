/* GHIDRADEC_FUNCTION index=2850 start=0x402a56c */

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
/* GHIDRADEC_FUNCTION index=2851 start=0x402a788 */

undefined4 sub_402A788(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x126);
  _rflush(param_1);
  _rinval(param_1);
  if ((*(int *)(iVar1 + 0x16) == 1) && (*(sword *)(*(int *)(iVar1 + 0x10) + 6) == 1)) {
    _rp_rmhash(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x2e));
    _rinactive(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x2e));
    _vn_rele(*(undefined4 *)(iVar1 + 0x10));
    _vfs_putnum(unk_40B3534,*(undefined4 *)(iVar1 + 0x26));
    if (-1 < *(int *)(iVar1 + 0x56)) {
      _kfree(*(undefined4 *)(iVar1 + 0x52),*(int *)(iVar1 + 0x56));
    }
    _kfree(iVar1,0x6e);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2852 start=0x402a934 */

undefined * sub_402A934(word param_1,undefined *param_2)

{
  word wVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined auStack_10 [12];
  
  puVar4 = auStack_10;
  do {
    uVar2 = (uint)param_1;
    wVar1 = (word)(uVar2 / 10);
    puVar3 = puVar4 + 1;
    *puVar4 = a0123456789[(word)(param_1 + wVar1 * -10)];
    puVar4 = puVar3;
    param_1 = wVar1;
  } while (uVar2 / 10 != 0);
  do {
    puVar3 = puVar3 + -1;
    puVar4 = param_2 + 1;
    *param_2 = *puVar3;
    param_2 = puVar4;
  } while (auStack_10 < puVar3);
  return puVar4;
}
/* GHIDRADEC_FUNCTION index=2853 start=0x402a990 */

void sub_402A990(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 4),param_2);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 5),puVar1 + 1);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 6),puVar1 + 1);
  *puVar1 = 0x2e;
  puVar1 = (undefined *)sub_402A934(*(undefined *)(param_1 + 7),puVar1 + 1);
  *puVar1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2854 start=0x402abc8 */

int sub_402ABC8(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined auStack_3e [58];
  
  iVar9 = 0;
  bVar2 = false;
  if (*(int *)(param_2 + 0x12) == 0) {
    iVar9 = 0;
  }
  else if ((*(int *)(param_2 + 8) < 0) ||
          (uVar6 = *(int *)(param_2 + 0x12) + *(int *)(param_2 + 8), (int)uVar6 < 0)) {
    iVar9 = 0x16;
  }
  else if (((param_3 == 1) && (param_1[10] == 1)) && (*(uint *)((int)_active_u + 0x25e) < uVar6)) {
    _psignal(*_active_u,0x19);
    iVar9 = 0x1b;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 0x2e);
    _rlock(iVar1);
    uVar6 = *(uint *)(*(int *)(param_1[9] + 0x126) + 0x22) & 0xfffffc00;
    if ((int)uVar6 < 1) {
                    /* WARNING: Subroutine does not return */
      _panic(aRwvpZeroSize);
    }
    do {
      uVar8 = *(uint *)(param_2 + 8) % uVar6;
      uVar7 = *(uint *)(param_2 + 8) / uVar6;
      uVar5 = *(uint *)(param_2 + 0x12);
      if (uVar6 - uVar8 < *(uint *)(param_2 + 0x12)) {
        uVar5 = uVar6 - uVar8;
      }
      (**(code **)(param_1[7] + 0x50))(param_1,uVar7,&uStack_42,&uStack_46);
      if ((*(byte *)((int)param_1 + 5) & 0x40) == 0) {
        if (param_3 == 0) {
          if ((int)uVar7 < 0) {
            iVar3 = _geteblk(uVar6);
            _blkclr(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x14));
            *(undefined4 *)(iVar3 + 0x28) = 0;
          }
          else {
            iVar3 = _incore(uStack_42,uStack_46);
            if (iVar3 != 0) {
              _nfs_validate_caches(uStack_42,param_5,0);
            }
            if (uVar7 == *(int *)(iVar1 + 0x62) + 1U) {
              (**(code **)(param_1[7] + 0x50))(param_1,uVar7 + 1,&uStack_42,&uStack_4a);
              iVar3 = _breada(uStack_42,uStack_46,uVar6,uStack_4a,uVar6);
            }
            else {
loc_402ADC6:
              iVar3 = _bread(uStack_42,uStack_46,uVar6);
            }
          }
        }
        else {
          if (*(sword *)(iVar1 + 0x60) != 0) {
            iVar9 = (int)*(sword *)(iVar1 + 0x60);
            goto loc_402AED8;
          }
          if (uVar6 != uVar5) goto loc_402ADC6;
          iVar3 = _getblk(uStack_42,uStack_46,uVar6);
        }
      }
      else {
        iVar3 = _geteblk(uVar6);
        if ((param_3 == 0) &&
           (iVar9 = sub_402B07A(param_1,uVar8 + *(int *)(iVar3 + 0x20),*(undefined4 *)(param_2 + 8),
                                uVar5,iVar3 + 0x28,param_5,auStack_3e), iVar9 != 0)) {
          _brelse(iVar3);
          goto loc_402AED8;
        }
      }
      if ((*(byte *)(iVar3 + 3) & 4) != 0) {
        iVar9 = _geterror(iVar3);
        _brelse(iVar3);
        goto loc_402AED8;
      }
      if (param_3 == 0) {
        *(uint *)(iVar1 + 0x62) = uVar7;
        uVar7 = *(int *)(iVar1 + 0x90) - *(int *)(param_2 + 8);
        if ((int)uVar7 < 1) {
          _brelse(iVar3);
          iVar9 = 0;
          goto loc_402AED8;
        }
        if ((int)uVar7 < (int)uVar5) {
          bVar2 = true;
          uVar5 = uVar7;
        }
      }
      uVar4 = _uiomove(uVar8 + *(int *)(iVar3 + 0x20),uVar5,param_3,param_2);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (param_3 == 0) {
        _brelse(iVar3);
      }
      else {
        uVar7 = *(uint *)(param_2 + 8);
        if (*(uint *)(iVar1 + 0x90) < uVar7) {
          *(uint *)(iVar1 + 0x90) = uVar7;
          if (*(uint *)(*param_1 + 0x14) < uVar7) {
            *(uint *)(*param_1 + 0x14) = uVar7;
          }
        }
        if ((*(byte *)((int)param_1 + 5) & 0x40) == 0) {
          *(word *)(iVar1 + 0x5e) = *(word *)(iVar1 + 0x5e) | 0x10;
          if (uVar6 == uVar8 + uVar5) {
            *(word *)(iVar3 + 2) = *(word *)(iVar3 + 2) | 0x80;
            _bawrite(iVar3);
          }
          else {
            _bdwrite(iVar3);
          }
        }
        else {
          iVar9 = _nfswrite(param_1,*(int *)(iVar3 + 0x20) + uVar8,*(int *)(param_2 + 8) - uVar5,
                            uVar5,param_5);
          _brelse(iVar3);
        }
      }
    } while (((*(char *)(dword_40B57D4 + 100) == '\0') && (0 < *(int *)(param_2 + 0x12))) &&
            (!bVar2));
    if (iVar9 == 0) {
      iVar9 = (int)*(char *)(dword_40B57D4 + 100);
    }
loc_402AED8:
    _runlock(iVar1);
  }
  return iVar9;
}
/* GHIDRADEC_FUNCTION index=2855 start=0x402b03a */

void sub_402B03A(undefined4 param_1)

{
  uint uVar1;
  undefined4 auStack_24 [8];
  
  _bcopy(param_1,auStack_24,0x20);
  uVar1 = 0;
  do {
    _printf(&aX,auStack_24[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}
/* GHIDRADEC_FUNCTION index=2856 start=0x402b07a */

int sub_402B07A(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 param_6,
               undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_88;
  undefined auStack_84 [68];
  int iStack_40;
  int iStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  while( true ) {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x1a);
    if (param_4 < iVar3) {
      iVar3 = param_4;
    }
    iVar1 = *(int *)(param_1 + 0x2e);
    uStack_30 = *(undefined4 *)(iVar1 + 0x3e);
    uStack_2c = *(undefined4 *)(iVar1 + 0x42);
    uStack_28 = *(undefined4 *)(iVar1 + 0x46);
    uStack_24 = *(undefined4 *)(iVar1 + 0x4a);
    uStack_20 = *(undefined4 *)(iVar1 + 0x4e);
    uStack_1c = *(undefined4 *)(iVar1 + 0x52);
    uStack_18 = *(undefined4 *)(iVar1 + 0x56);
    uStack_14 = *(undefined4 *)(iVar1 + 0x5a);
    iStack_3c = param_2;
    iStack_10 = param_3;
    iStack_c = iVar3;
    iStack_8 = iVar3;
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),6,_xdr_readargs,&uStack_30,
                     _xdr_rdresult,&iStack_88,param_6);
    iVar1 = iStack_88;
    if (iVar2 != 0) break;
    if (iStack_88 == 0x46) {
      _printf(aNfsReadErrorEs,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
      sub_402B03A(*(int *)(param_1 + 0x2e) + 0x3e);
      _printf(&asc_40A6049);
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    iVar2 = iVar1;
    if (iVar1 != 0) break;
    param_4 = param_4 - iStack_40;
    param_2 = iStack_40 + param_2;
    param_3 = iStack_40 + param_3;
    if ((param_4 == 0) || (iVar3 != iStack_40)) break;
  }
  *param_5 = param_4;
  if (iVar2 == 0) {
    _nattr_to_vattr(param_1,auStack_84,param_7);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2857 start=0x402b1be */

void sub_402B1BE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _sync_vp(param_1);
  _nfsgetattr(param_1,param_2,param_3,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2858 start=0x402b1f2 */

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
/* GHIDRADEC_FUNCTION index=2859 start=0x402b5f2 */

int sub_402B5F2(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iStack_48;
  undefined auStack_28 [36];
  
  iStack_48 = 0;
  iVar2 = _nfs_validate_caches(param_1,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  iStack_48 = *(int *)(param_1 + 0x2e);
  _rlock();
  iVar2 = _dnlc_lookup(param_1,param_2,param_4);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    iStack_48 = 0x68;
    piVar3 = (int *)_kalloc();
    _bzero(piVar3,0x68);
    _setdiropargs(auStack_28,param_2,param_1);
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),4,_xdr_diropargs,auStack_28,
                     _xdr_diropres,piVar3,param_4);
    if (iVar2 == 0) {
      iVar2 = *piVar3;
      if (iVar2 == 0x46) {
        iStack_48 = param_1;
        _btrash();
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 != 0) goto loc_402B712;
      iStack_48 = *(int *)(param_1 + 0x24);
      iVar4 = _makenfsnode(piVar3 + 1,piVar3 + 9);
      *param_3 = iVar4;
      if (_nfs_dnlc != 0) {
        iStack_48 = param_4;
        _dnlc_enter(param_1,param_2,iVar4);
      }
    }
    else {
loc_402B712:
      *param_3 = 0;
    }
    piVar5 = (int *)&stack0xffffffbc;
    iStack_48 = 0x68;
    _kfree(piVar3);
    if (iVar2 != 0) goto loc_402B75C;
  }
  else {
    *(sword *)(iVar2 + 6) = *(sword *)(iVar2 + 6) + 1;
    iStack_48 = param_4;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40);
    if (iVar2 != 0) {
      iStack_48 = *param_3;
      _vn_rele();
      piVar5 = &iStack_48;
      goto loc_402B75C;
    }
  }
  iVar4 = *param_3;
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 - 3U < 2) || (piVar5 = (int *)&stack0xffffffbc, iVar1 == 8)) {
    iStack_48 = iVar1;
    iVar4 = _specvp(iVar4,(int)*(sword *)(iVar4 + 0x2c));
    _vn_rele(*param_3);
    *param_3 = iVar4;
    piVar5 = (int *)&stack0xffffffbc;
  }
loc_402B75C:
  *(undefined4 *)((int)piVar5 + -4) = *(undefined4 *)(param_1 + 0x2e);
  *(undefined4 *)((int)piVar5 + -8) = 0x402b766;
  _runlock();
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2860 start=0x402bc9e */

int sub_402BC9E(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iStack_50;
  undefined auStack_4c [36];
  undefined auStack_28 [36];
  
  iVar1 = _strcmp(param_2,&asc_40A6047);
  if ((((iVar1 == 0) || (iVar1 = _strcmp(param_2,&asc_40A6712), iVar1 == 0)) ||
      (iVar1 = _strcmp(param_4,&asc_40A6047), iVar1 == 0)) ||
     (iVar1 = _strcmp(param_4,&asc_40A6712), iVar1 == 0)) {
    return 0x16;
  }
  _rlock(*(undefined4 *)(param_1 + 0x2e));
  _dnlc_remove(param_1,param_2);
  _dnlc_remove(param_3,param_4);
  if (param_1 != param_3) {
    _rlock(*(undefined4 *)(param_3 + 0x2e));
  }
  _setdiropargs(auStack_4c,param_2,param_1);
  _setdiropargs(auStack_28,param_4,param_3);
  iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),0xb,_xdr_rnmargs,auStack_4c,
                   _xdr_enum,&iStack_50,param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  *(undefined4 *)(*(int *)(param_3 + 0x2e) + 0xb6) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x2e));
  if (param_1 != param_3) {
    _runlock(*(undefined4 *)(param_3 + 0x2e));
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  if (iStack_50 != 0x46) {
    return iStack_50;
  }
  _btrash(param_1);
  _nfs_invalidate_caches(param_1);
  _btrash(param_3);
  _nfs_invalidate_caches(param_3);
  return 0x46;
}
/* GHIDRADEC_FUNCTION index=2861 start=0x402c364 */

int sub_402C364(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  sword sVar5;
  uint uVar6;
  int iVar7;
  undefined auStack_3e [58];
  
  piVar1 = (int *)param_1[0x10];
  iVar2 = *(int *)((int)piVar1 + 0x2e);
  iVar4 = (**(code **)(piVar1[7] + 0x80))(piVar1);
  if ((*param_1 & 1) == 0) {
    sVar5 = *(sword *)(iVar2 + 0x60);
    if (sVar5 == 0) {
      uVar6 = *(int *)(iVar2 + 0x90) - iVar4 * param_1[9];
      if (param_1[5] < uVar6) {
        uVar6 = param_1[5];
      }
      if ((int)uVar6 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aDoBioWriteCoun);
      }
      sVar5 = _nfswrite(piVar1,param_1[8],param_1[9] * iVar4,uVar6,*(undefined4 *)(iVar2 + 0x6c));
      *(sword *)(param_1 + 7) = sVar5;
      iVar7 = (int)sVar5;
      if ((*param_1 & 0x100) != 0) {
        *(sword *)(iVar2 + 0x60) = sVar5;
      }
    }
    else {
      *(sword *)(param_1 + 7) = sVar5;
      iVar7 = (int)sVar5;
    }
loc_402C46A:
    if (iVar7 == 0) goto loc_402C48A;
  }
  else {
    puVar3 = param_1 + 10;
    sVar5 = sub_402B07A(piVar1,param_1[8],iVar4 * param_1[9],param_1[5],puVar3,
                        *(undefined4 *)(iVar2 + 0x6c),auStack_3e);
    *(sword *)(param_1 + 7) = sVar5;
    iVar7 = (int)sVar5;
    if (iVar7 == 0) {
      uVar6 = *puVar3;
      if (uVar6 != 0) {
        _bzero(param_1[8] + (param_1[5] - uVar6),uVar6);
      }
      if ((*puVar3 != param_1[5]) || (iVar4 * param_1[9] < *(uint *)(iVar2 + 0x90)))
      goto loc_402C46A;
      iVar7 = -0x62;
    }
  }
  if (iVar7 != -0x62) {
    *param_1 = *param_1 | 4;
    iVar2 = *piVar1;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) == 0)) {
      *(int *)(iVar2 + 0x30) = iVar7;
    }
  }
loc_402C48A:
  _biodone(param_1);
  return iVar7;
}
/* GHIDRADEC_FUNCTION index=2862 start=0x402c536 */

void sub_402C536(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  _bflush(param_1,0xffffffff,0xffffffff);
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x22);
  uVar3 = 0;
  if (*(int *)(iVar1 + 0x90) != 0) {
    do {
      _blkflush(param_1,uVar3 >> 10,iVar2);
      uVar3 = iVar2 + uVar3;
    } while (uVar3 < *(uint *)(iVar1 + 0x90));
  }
  *(word *)(iVar1 + 0x5e) = *(word *)(iVar1 + 0x5e) & 0xffef;
  return;
}
/* GHIDRADEC_FUNCTION index=2863 start=0x402cd4e */

undefined4 sub_402CD4E(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    puVar1 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
      puVar1[3] = param_2[3];
      puVar1[4] = param_2[4];
      puVar1[5] = param_2[5];
      puVar1[6] = param_2[6];
      puVar1[7] = param_2[7];
      puVar1[8] = param_2[8];
      puVar1[9] = param_2[9];
      puVar1[10] = param_2[10];
      puVar1[0xb] = param_2[0xb];
      puVar1[0xc] = param_2[0xc];
      puVar1[0xd] = param_2[0xd];
      puVar1[0xe] = param_2[0xe];
      puVar1[0xf] = param_2[0xf];
      puVar1[0x10] = param_2[0x10];
      return 1;
    }
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (puVar1 != (undefined4 *)0x0) {
      *param_2 = *puVar1;
      param_2[1] = puVar1[1];
      param_2[2] = puVar1[2];
      param_2[3] = puVar1[3];
      param_2[4] = puVar1[4];
      param_2[5] = puVar1[5];
      param_2[6] = puVar1[6];
      param_2[7] = puVar1[7];
      param_2[8] = puVar1[8];
      param_2[9] = puVar1[9];
      param_2[10] = puVar1[10];
      param_2[0xb] = puVar1[0xb];
      param_2[0xc] = puVar1[0xc];
      param_2[0xd] = puVar1[0xd];
      param_2[0xe] = puVar1[0xe];
      param_2[0xf] = puVar1[0xf];
      param_2[0x10] = puVar1[0x10];
      return 1;
    }
  }
  iVar2 = _xdr_enum(param_1,param_2);
  if (((((iVar2 != 0) && (iVar2 = _xdr_u_long(param_1,param_2 + 1), iVar2 != 0)) &&
       (iVar2 = _xdr_u_long(param_1,param_2 + 2), iVar2 != 0)) &&
      ((((iVar2 = _xdr_u_long(param_1,param_2 + 3), iVar2 != 0 &&
         (iVar2 = _xdr_u_long(param_1,param_2 + 4), iVar2 != 0)) &&
        ((iVar2 = _xdr_u_long(param_1,param_2 + 5), iVar2 != 0 &&
         ((iVar2 = _xdr_u_long(param_1,param_2 + 6), iVar2 != 0 &&
          (iVar2 = _xdr_u_long(param_1,param_2 + 7), iVar2 != 0)))))) &&
       (iVar2 = _xdr_u_long(param_1,param_2 + 8), iVar2 != 0)))) &&
     ((((iVar2 = _xdr_u_long(param_1,param_2 + 9), iVar2 != 0 &&
        (iVar2 = _xdr_u_long(param_1,param_2 + 10), iVar2 != 0)) &&
       (iVar2 = sub_402D624(param_1,param_2 + 0xb), iVar2 != 0)) &&
      ((iVar2 = sub_402D624(param_1,param_2 + 0xd), iVar2 != 0 &&
       (iVar2 = sub_402D624(param_1,param_2 + 0xf), iVar2 != 0)))))) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2864 start=0x402d04e */

void sub_402D04E(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 1;
  _wakeup(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2865 start=0x402d1b4 */

undefined4 sub_402D1B4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 4), iVar1 != 0)) &&
      (iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0)) &&
     (((iVar1 = _xdr_u_long(param_1,param_2 + 0xc), iVar1 != 0 &&
       (iVar1 = sub_402D624(param_1,param_2 + 0x10), iVar1 != 0)) &&
      (iVar1 = sub_402D624(param_1,param_2 + 0x18), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2866 start=0x402d624 */

undefined4 sub_402D624(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_long(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_long(param_1,param_2 + 4), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2867 start=0x402dc58 */

void sub_402DC58(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2868 start=0x402dc60 */

void sub_402DC60(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffff7;
  if ((uVar1 & 0x10) != 0) {
    *param_1 = uVar1 & 0xffffffe7;
    _wakeup(param_1 + 0x1a);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2869 start=0x402e54e */

int sub_402E54E(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  word wVar5;
  undefined2 *puVar6;
  
  iVar2 = _m_get(1,8);
  if (iVar2 == 0) {
    _printf(aBindresvportCo);
    iVar3 = 0x37;
  }
  else {
    puVar6 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
    *puVar6 = 2;
    *(undefined4 *)(puVar6 + 2) = 0;
    *(undefined2 *)(iVar2 + 8) = 0x10;
    uVar4 = _crdup(*(undefined4 *)(_active_u + 0x1a));
    uVar1 = *(undefined4 *)(_active_u + 0x1a);
    *(undefined4 *)(_active_u + 0x1a) = uVar4;
    *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2) = 0;
    iVar3 = 0x30;
    wVar5 = 0x3ff;
    do {
      if (wVar5 < 0x200) break;
      puVar6[1] = wVar5;
      iVar3 = _sobind(param_1,iVar2);
      wVar5 = wVar5 - 1;
    } while (iVar3 == 0x30);
    _m_freem(iVar2);
    *(undefined4 *)(_active_u + 0x1a) = uVar1;
    _crfree(uVar4);
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2870 start=0x402f08a */

void sub_402F08A(undefined4 param_1,undefined4 *param_2)

{
  switch(param_1) {
  case :
    *param_2 = 0;
    break;
  case :
    *param_2 = 8;
    break;
  case :
    *param_2 = 9;
    break;
  case :
    *param_2 = 10;
    break;
  case :
    *param_2 = 0xb;
    break;
  case :
    *param_2 = 0xc;
    break;
  :
    *param_2 = 0x10;
    param_2[1] = 0;
    param_2[2] = param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2871 start=0x402f0f2 */

void sub_402F0F2(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    *param_2 = 6;
  }
  else if (param_1 == 1) {
    *param_2 = 7;
  }
  else {
    *param_2 = 0x10;
    param_2[1] = 1;
    param_2[2] = param_1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2872 start=0x402f42a */

undefined4 * sub_402F42A(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = dword_40B3596;
      (puVar2 != (undefined4 *)0x0 && ((param_1 != puVar2[1] || (param_2 != puVar2[2]))));
      puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_3 = puVar1;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=2873 start=0x402faaa */

void sub_402FAAA(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffffe;
  if ((uVar1 & 2) != 0) {
    *param_1 = uVar1 & 0xfffffffc;
    _wakeup(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2874 start=0x402fd84 */

void sub_402FD84(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)0x0;
  puVar2 = *(uint **)(_drhashtbl + (*param_1 & 0x1f) * 4);
  while( true ) {
    if (puVar2 == (uint *)0x0) {
      return;
    }
    if (param_1 == puVar2) break;
    puVar1 = puVar2;
    puVar2 = (uint *)puVar2[9];
  }
  if (puVar1 == (uint *)0x0) {
    *(uint *)(_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2[9];
    return;
  }
  puVar1[9] = puVar2[9];
  return;
}

