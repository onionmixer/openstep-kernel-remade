/* GHIDRADEC_FUNCTION index=3350 start=0xf003ed9c */

/* WARNING: Removing unreachable block (ram,0xf003ee10) */
/* WARNING: Removing unreachable block (ram,0xf003ee1c) */
/* WARNING: Removing unreachable block (ram,0xf003ede0) */

undefined8 sub_F003ED9C(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = 0;
  if ((_nfs_cto != 0) ||
     ((*(uint *)(*(int *)(*(int *)(*param_1 + 0x24) + 0x128) + 0x14) & 0x4000000) == 0)) {
    iVar1 = *param_1;
    _nfs_getattr_otw(iVar1,(undefined *)((int)register0x00000038 + -0x48),param_3);
    if (iVar1 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x50) =
           *(undefined4 *)((int)register0x00000038 + -0x20);
      *(undefined4 *)((int)register0x00000038 + -0x4c) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
      _nfs_cache_check(*param_1,(undefined *)((int)register0x00000038 + -0x50),
                       *(undefined4 *)((int)register0x00000038 + -0x30),0);
      _nfs_attrcache_va(*param_1,(undefined *)((int)register0x00000038 + -0x48));
    }
    else if (iVar1 == 0x46) {
      *(undefined *)(dword_F0133DDC + 0x39) = 2;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3351 start=0xf003ee44 */

/* WARNING: Removing unreachable block (ram,0xf003eecc) */
/* WARNING: Removing unreachable block (ram,0xf003ee84) */
/* WARNING: Removing unreachable block (ram,0xf003ee78) */

undefined8 sub_F003EE44(int param_1,uint param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar3;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_3 < 2) {
    iVar2 = *(int *)(param_1 + 0x30);
    if ((*(int *)(iVar2 + 0x7c) == 0) && (*(sword *)(iVar2 + 0x62) == 0)) {
      bVar3 = (param_2 & 2) == 0;
      if (((param_2 & 2) != 0) &&
         ((_nfs_cto != 0 ||
          (bVar3 = (param_2 & 2) == 0,
          (*(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x4000000) == 0)))) {
        _sync_vp(param_1);
        bVar3 = (param_2 & 2) == 0;
      }
    }
    else {
      _sync_vp(param_1);
      _nfs_purge_caches(param_1,param_2);
      bVar3 = (param_2 & 2) == 0;
    }
    iVar1 = 0;
    if (!bVar3) {
      iVar1 = (int)*(sword *)(iVar2 + 0x62);
    }
  }
  else {
    iVar1 = 0;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3352 start=0xf003eeec */

/* WARNING: Removing unreachable block (ram,0xf003efcc) */
/* WARNING: Removing unreachable block (ram,0xf003ef88) */
/* WARNING: Removing unreachable block (ram,0xf003ef6c) */
/* WARNING: Removing unreachable block (ram,0xf003ef98) */
/* WARNING: Removing unreachable block (ram,0xf003efec) */
/* WARNING: Removing unreachable block (ram,0xf003ef4c) */

undefined8 sub_F003EEEC(undefined4 *param_1,int param_2,int param_3,uint param_4,sword *param_5)

{
  undefined4 unaff_l0;
  undefined4 *puVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar3;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar1 = (undefined4 *)0x0;
  if (param_1[10] != 1) {
    puVar1 = (undefined4 *)0x15;
    goto locret_F003EFF8;
  }
  iVar2 = param_1[0xc];
  if ((param_3 == 1) ||
     ((bVar3 = (param_4 & 2) == 0, param_3 == 0 &&
      (bVar3 = (param_4 & 2) == 0, *(int *)(iVar2 + 0x70) == 0)))) {
    *param_5 = *param_5 + 1;
    if (*(int *)(iVar2 + 0x70) == 0) {
      *(sword **)(iVar2 + 0x70) = param_5;
    }
    else {
      _crfree();
      *(sword **)(iVar2 + 0x70) = param_5;
    }
    bVar3 = (param_4 & 2) == 0;
    if (*(int *)*param_1 != 0) {
      _vnode_uncache(param_1);
      bVar3 = (param_4 & 2) == 0;
    }
  }
  if (bVar3) {
loc_F003EFB0:
    bVar3 = puVar1 == (undefined4 *)0x0;
  }
  else {
    bVar3 = true;
    if (param_3 == 1) {
      _rlock(iVar2);
      puVar1 = param_1;
      sub_F003F730(param_1,(undefined *)((int)register0x00000038 + -0x48),param_5);
      bVar3 = false;
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)((int)register0x00000038 + -0x30);
        goto loc_F003EFB0;
      }
    }
  }
  if (bVar3) {
    sub_F003F000(param_1,param_2,param_3,param_4,param_5);
    puVar1 = param_1;
  }
  if (((param_4 & 2) != 0) && (param_3 == 1)) {
    _runlock(iVar2);
  }
locret_F003EFF8:
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3353 start=0xf003f000 */

/* WARNING: Removing unreachable block (ram,0xf003f374) */
/* WARNING: Removing unreachable block (ram,0xf003f340) */
/* WARNING: Removing unreachable block (ram,0xf003f2cc) */
/* WARNING: Removing unreachable block (ram,0xf003f190) */
/* WARNING: Removing unreachable block (ram,0xf003f1c0) */
/* WARNING: Removing unreachable block (ram,0xf003f230) */
/* WARNING: Removing unreachable block (ram,0xf003f1e8) */
/* WARNING: Removing unreachable block (ram,0xf003f258) */
/* WARNING: Removing unreachable block (ram,0xf003f148) */
/* WARNING: Removing unreachable block (ram,0xf003f0e8) */
/* WARNING: Removing unreachable block (ram,0xf003f0ac) */
/* WARNING: Removing unreachable block (ram,0xf003f0d0) */
/* WARNING: Removing unreachable block (ram,0xf003f0f8) */
/* WARNING: Removing unreachable block (ram,0xf003f17c) */
/* WARNING: Removing unreachable block (ram,0xf003f1d0) */
/* WARNING: Removing unreachable block (ram,0xf003f26c) */
/* WARNING: Removing unreachable block (ram,0xf003f1b0) */
/* WARNING: Removing unreachable block (ram,0xf003f08c) */
/* WARNING: Removing unreachable block (ram,0xf003f09c) */
/* WARNING: Removing unreachable block (ram,0xf003f334) */
/* WARNING: Removing unreachable block (ram,0xf003f384) */
/* WARNING: Removing unreachable block (ram,0xf003f3cc) */
/* WARNING: Removing unreachable block (ram,0xf003f074) */

undefined8 sub_F003F000(uint *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  word wVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  uint *puVar10;
  undefined4 unaff_l3;
  uint uVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  bVar3 = false;
  if (*(int *)(param_2 + 0x14) == 0) {
    puVar12 = (uint *)0x0;
  }
  else {
    uVar11 = *(int *)(param_2 + 8) + *(int *)(param_2 + 0x14);
    if ((-1 < *(int *)(param_2 + 8)) && (-1 < (int)uVar11)) {
      if (param_3 == 1) {
        if (param_1[10] == 1) {
          if ((uint)_active_u[0x9a] < uVar11) {
            _psignal(*_active_u,0x19);
            puVar12 = (uint *)0x1b;
            goto locret_F003F3D8;
          }
          uVar11 = param_1[0xc];
        }
        else {
          uVar11 = param_1[0xc];
        }
      }
      else {
        uVar11 = param_1[0xc];
      }
      _rlock(uVar11);
      puVar1 = (uint *)(*(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00);
      if ((int)puVar1 < 1) {
        _panic(aRwvpZeroSize);
      }
      iVar9 = *(int *)(param_2 + 8);
      puVar8 = (uint *)0x0;
      do {
        iVar7 = iVar9;
        .udiv(iVar9,puVar1);
        .urem(iVar9,puVar1);
        puVar10 = *(uint **)(param_2 + 0x14);
        if ((uint *)((int)puVar1 - iVar9) < *(uint **)(param_2 + 0x14)) {
          puVar10 = (uint *)((int)puVar1 - iVar9);
        }
        (**(code **)(param_1[7] + 0x50))
                  (param_1,iVar7,(undefined *)((int)register0x00000038 + -0x4c),
                   (undefined *)((int)register0x00000038 + -0x50));
        puVar6 = puVar1;
        if ((param_1[1] & 0x400000) != 0) {
          _geteblk();
          if (param_3 != 0) goto loc_F003F278;
          puVar12 = param_1;
          sub_F003F5B4(param_1,puVar6[8] + iVar9,*(undefined4 *)(param_2 + 8),puVar10,puVar6 + 10,
                       param_5,(undefined *)((int)register0x00000038 + -0x48));
          if (puVar12 == (uint *)0x0) {
            uVar4 = *puVar6;
            goto loc_F003F27C;
          }
loc_F003F190:
          _brelse(puVar6);
          goto loc_F003F3CC;
        }
        if (param_3 == 0) {
          iVar5 = *(int *)((int)register0x00000038 + -0x4c);
          if (iVar7 < 0) {
            _geteblk();
            _bzero(puVar6[8],puVar6[5]);
            puVar6[10] = 0;
          }
          else {
            _incore(iVar5,*(undefined4 *)((int)register0x00000038 + -0x50));
            if (iVar5 != 0) {
              _nfs_validate_caches(*(undefined4 *)((int)register0x00000038 + -0x4c),param_5,0);
            }
            puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
            if (*(int *)(uVar11 + 100) + 1 != iVar7) goto loc_F003F268;
            (**(code **)(param_1[7] + 0x50))
                      (param_1,*(int *)(uVar11 + 100) + 2,
                       (undefined *)((int)register0x00000038 + -0x4c),
                       (undefined *)((int)register0x00000038 + -0x54));
            puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
            _breada(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1,
                    *(undefined4 *)((int)register0x00000038 + -0x54),puVar1);
          }
        }
        else {
          puVar12 = (uint *)(int)*(sword *)(uVar11 + 0x62);
          if (puVar12 != (uint *)0x0) goto loc_F003F3CC;
          puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
          if (puVar10 == puVar1) {
            _getblk(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1);
          }
          else {
loc_F003F268:
            _bread(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1);
          }
        }
loc_F003F278:
        uVar4 = *puVar6;
        puVar12 = puVar8;
loc_F003F27C:
        if ((uVar4 & 4) != 0) {
          puVar12 = puVar6;
          _geterror(puVar6);
          goto loc_F003F190;
        }
        if (param_3 == 0) {
          *(int *)(uVar11 + 100) = iVar7;
          puVar8 = (uint *)(*(int *)(uVar11 + 0x98) - *(int *)(param_2 + 8));
          if ((int)puVar8 < 1) {
            _brelse(puVar6);
            puVar12 = (uint *)0x0;
            goto loc_F003F3CC;
          }
          if ((int)puVar8 < (int)puVar10) {
            bVar3 = true;
            puVar10 = puVar8;
          }
        }
        iVar7 = puVar6[8] + iVar9;
        _uiomove(iVar7,puVar10,param_3,param_2);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar7;
        if (param_3 == 0) {
loc_F003F340:
          _brelse(puVar6);
        }
        else {
          uVar4 = *(uint *)(param_2 + 8);
          if (*(uint *)(uVar11 + 0x98) < uVar4) {
            *(uint *)(uVar11 + 0x98) = uVar4;
            if (*(uint *)(*param_1 + 0x14) < uVar4) {
              *(uint *)(*param_1 + 0x14) = uVar4;
            }
            wVar2 = *(word *)(param_1 + 1);
          }
          else {
            wVar2 = *(word *)(param_1 + 1);
          }
          if ((wVar2 & 0x40) != 0) {
            puVar12 = param_1;
            _nfswrite(param_1,puVar6[8] + iVar9,*(int *)(param_2 + 8) - (int)puVar10,puVar10,param_5
                     );
            goto loc_F003F340;
          }
          *(word *)(uVar11 + 0x60) = *(word *)(uVar11 + 0x60) | 0x10;
          if ((uint *)((int)puVar10 + iVar9) == puVar1) {
            *puVar6 = *puVar6 | 0x80;
            _bawrite();
          }
          else {
            _bdwrite(puVar6);
          }
        }
        if (((*(char *)(dword_F0133DDC + 0x38) != '\0') || (*(int *)(param_2 + 0x14) < 1)) ||
           (bVar3)) goto loc_F003F3BC;
        iVar9 = *(int *)(param_2 + 8);
        puVar8 = puVar12;
      } while( true );
    }
    puVar12 = (uint *)0x16;
  }
  goto locret_F003F3D8;
loc_F003F3BC:
  if (puVar12 == (uint *)0x0) {
    puVar12 = (uint *)(int)*(char *)(dword_F0133DDC + 0x38);
  }
loc_F003F3CC:
  _runlock(uVar11);
locret_F003F3D8:
  return CONCAT44(param_2,puVar12);
}
/* GHIDRADEC_FUNCTION index=3354 start=0xf003f570 */

/* WARNING: Removing unreachable block (ram,0xf003f598) */
/* WARNING: Removing unreachable block (ram,0xf003f57c) */

undefined8 sub_F003F570(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_28 [10];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _bcopy(param_1,(undefined *)((int)register0x00000038 + -0x28),0x20);
  uVar1 = 0;
  puVar2 = (undefined *)((int)register0x00000038 + -8);
  do {
    uVar1 = uVar1 + 1;
    _printf(&aX,*(undefined4 *)(puVar2 + -0x20));
    puVar2 = puVar2 + 4;
  } while (uVar1 < 8);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3355 start=0xf003f5b4 */

/* WARNING: Removing unreachable block (ram,0xf003f6b4) */
/* WARNING: Removing unreachable block (ram,0xf003f698) */
/* WARNING: Removing unreachable block (ram,0xf003f680) */
/* WARNING: Removing unreachable block (ram,0xf003f68c) */
/* WARNING: Removing unreachable block (ram,0xf003f6ac) */
/* WARNING: Removing unreachable block (ram,0xf003f708) */
/* WARNING: Removing unreachable block (ram,0xf003f64c) */

undefined8
sub_F003F5B4(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  while( true ) {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x128) + 0x1c);
    if (param_4 < iVar1) {
      iVar1 = param_4;
    }
    *(int *)((int)register0x00000038 + -0x44) = param_2;
    iVar3 = *(int *)(param_1 + 0x30);
    *(undefined4 *)((int)register0x00000038 + -0x38) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(iVar3 + 0x44);
    *(undefined4 *)((int)register0x00000038 + -0x30) = *(undefined4 *)(iVar3 + 0x48);
    *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(iVar3 + 0x4c);
    *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(iVar3 + 0x50);
    *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar3 + 0x54);
    *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(iVar3 + 0x58);
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(iVar3 + 0x5c);
    *(int *)((int)register0x00000038 + -0x18) = param_3;
    *(int *)((int)register0x00000038 + -0x10) = iVar1;
    *(int *)((int)register0x00000038 + -0x14) = iVar1;
    iVar3 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar3,6,_xdr_readargs,(undefined *)((int)register0x00000038 + -0x38),_xdr_rdresult,
             (undefined *)((int)register0x00000038 + -0x90),param_6);
    bVar4 = false;
    if (iVar3 == 0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x90);
      if (iVar3 == 0x46) {
        _printf(aNfsReadErrorEs,*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x34);
        sub_F003F570(*(int *)(param_1 + 0x30) + 0x40);
        _printf(&asc_F010D700);
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      bVar4 = iVar3 == 0;
      if (iVar3 == 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x48);
        param_4 = param_4 - iVar2;
        param_2 = param_2 + iVar2;
        param_3 = param_3 + iVar2;
      }
    }
    if (((!bVar4) || (param_4 == 0)) || (*(int *)((int)register0x00000038 + -0x48) != iVar1)) break;
    iVar1 = *(int *)(param_1 + 0x24);
  }
  *param_5 = param_4;
  if (iVar3 == 0) {
    _nattr_to_vattr(param_1,(undefined *)((int)register0x00000038 + -0x8c),
                    *(undefined4 *)((int)register0x00000038 + 0x5c));
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3356 start=0xf003f718 */

undefined8 sub_F003F718(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x2d);
}
/* GHIDRADEC_FUNCTION index=3357 start=0xf003f724 */

undefined8 sub_F003F724(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x2d);
}
/* GHIDRADEC_FUNCTION index=3358 start=0xf003f730 */

/* WARNING: Removing unreachable block (ram,0xf003f748) */
/* WARNING: Removing unreachable block (ram,0xf003f734) */

undefined8 sub_F003F730(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _sync_vp(param_1);
  _nfsgetattr(param_1,param_2,param_3,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3359 start=0xf003f758 */

/* WARNING: Removing unreachable block (ram,0xf003f924) */
/* WARNING: Removing unreachable block (ram,0xf003f900) */
/* WARNING: Removing unreachable block (ram,0xf003f8b4) */
/* WARNING: Removing unreachable block (ram,0xf003f874) */
/* WARNING: Removing unreachable block (ram,0xf003f80c) */
/* WARNING: Removing unreachable block (ram,0xf003f7e4) */
/* WARNING: Removing unreachable block (ram,0xf003f7cc) */
/* WARNING: Removing unreachable block (ram,0xf003f7f8) */
/* WARNING: Removing unreachable block (ram,0xf003f840) */
/* WARNING: Removing unreachable block (ram,0xf003f888) */
/* WARNING: Removing unreachable block (ram,0xf003f8f4) */
/* WARNING: Removing unreachable block (ram,0xf003f91c) */
/* WARNING: Removing unreachable block (ram,0xf003f93c) */
/* WARNING: Removing unreachable block (ram,0xf003f75c) */

undefined8 sub_F003F758(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar1 = (int *)0x48;
  _kalloc();
  if (*(sword *)(param_2 + 0x14) == -1) {
    iVar3 = 0x16;
    if ((((*(int *)(param_2 + 0x1c) != -1) || (*(sword *)(param_2 + 0x38) != -1)) ||
        (*(int *)(param_2 + 0x3c) != -1)) || (*(int *)(param_2 + 0x30) != -1)) goto loc_F003F93C;
    if (*(int *)(param_2 + 0x34) == -1) {
      _sync_vp(param_1);
      if (*(int *)(param_2 + 0x18) == -1) {
        iVar3 = *(int *)(param_2 + 0x28);
      }
      else {
        piVar2 = param_1;
        _mfs_trunc();
        if (piVar2 == (int *)0x0) {
          iVar3 = *param_1;
        }
        else {
          _sync_vp(param_1);
          iVar3 = *param_1;
        }
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2 + 0x18);
        _binvalfree(param_1);
        *(undefined4 *)(param_1[0xc] + 0x98) = *(undefined4 *)(param_2 + 0x18);
        iVar3 = *(int *)(param_2 + 0x28);
      }
      if ((iVar3 != -1) && (*(int *)(param_2 + 0x2c) == -1)) {
        _getthetime((undefined *)((int)register0x00000038 + -0x50));
        *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x50);
        *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x4c);
        *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x50);
        *(undefined4 *)(param_2 + 0x2c) = 1000000;
      }
      _vattr_to_sattr(param_2,(undefined *)((int)register0x00000038 + -0x28));
      _bcopy(param_1[0xc] + 0x40,(undefined *)((int)register0x00000038 + -0x48),0x20);
      iVar3 = *(int *)(param_1[9] + 0x128);
      _rfscall(iVar3,2,_xdr_saargs,(undefined *)((int)register0x00000038 + -0x48),_xdr_attrstat,
               piVar1,param_3);
      if (iVar3 == 0) {
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          *(int *)((int)register0x00000038 + -0x58) = piVar1[0xe];
          *(int *)((int)register0x00000038 + -0x54) = piVar1[0xf];
          _nfs_cache_check(param_1,(undefined *)((int)register0x00000038 + -0x58),piVar1[6],2);
          _nfs_attrcache(param_1,piVar1 + 1);
        }
        else {
          *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
          if (iVar3 == 0x46) {
            _btrash(param_1);
            _nfs_invalidate_caches(param_1);
          }
        }
      }
      else {
        *(undefined4 *)(param_1[0xc] + 0xc0) = 0;
      }
      goto loc_F003F93C;
    }
  }
  iVar3 = 0x16;
loc_F003F93C:
  _kfree(piVar1,0x48);
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3360 start=0xf003f94c */

/* WARNING: Removing unreachable block (ram,0xf003f95c) */

undefined8 sub_F003F94C(undefined4 param_1,uint param_2,int param_3)

{
  sword sVar1;
  uint uVar2;
  sword *psVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _nfsgetattr(param_1,(undefined *)((int)register0x00000038 + -0x48),param_3,0);
  *(char *)(dword_F0133DDC + 0x38) = (char)param_1;
  iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
  uVar5 = param_2;
  if (iVar4 == 0) {
    if (*(sword *)(param_3 + 2) != 0) {
      uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
      if (*(sword *)(param_3 + 2) != *(sword *)((int)register0x00000038 + -0x42)) {
        uVar5 = (int)param_2 >> 3;
        uVar6 = uVar5;
        if (*(sword *)(param_3 + 4) != *(sword *)((int)register0x00000038 + -0x40)) {
          psVar3 = (sword *)(param_3 + 10);
          uVar6 = (int)param_2 >> 6;
          if (psVar3 < (sword *)(param_3 + 0x2a)) {
            sVar1 = *psVar3;
            while (sVar1 != -1) {
              if (*(sword *)((int)register0x00000038 + -0x40) == sVar1) {
                uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
                goto loc_F003F9F8;
              }
              psVar3 = psVar3 + 1;
              if ((sword *)(param_3 + 0x2a) <= psVar3) break;
              sVar1 = *psVar3;
            }
          }
        }
        uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
        uVar5 = uVar6;
      }
loc_F003F9F8:
      if ((uVar2 & uVar5) != uVar5) {
        iVar4 = 0xd;
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F003FA20;
      }
    }
    iVar4 = 0;
  }
locret_F003FA20:
  return CONCAT44(uVar5,iVar4);
}
/* GHIDRADEC_FUNCTION index=3361 start=0xf003fa28 */

/* WARNING: Removing unreachable block (ram,0xf003faa4) */
/* WARNING: Removing unreachable block (ram,0xf003fabc) */
/* WARNING: Removing unreachable block (ram,0xf003fa74) */
/* WARNING: Removing unreachable block (ram,0xf003fac4) */
/* WARNING: Removing unreachable block (ram,0xf003fad0) */
/* WARNING: Removing unreachable block (ram,0xf003fa40) */

undefined8 sub_F003FA28(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar2 = 6;
  if (*(int *)(param_1 + 0x28) != 5) goto locret_F003FAD8;
  uVar1 = 0x400;
  _kalloc();
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar1;
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar2,5,_xdr_fhandle,*(int *)(param_1 + 0x30) + 0x40,_xdr_rdlnres,
           (undefined *)((int)register0x00000038 + -0x18),param_3);
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x18);
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      _uiomove(iVar2,*(undefined4 *)((int)register0x00000038 + -0x14),0,param_2);
    }
    else {
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
      if (iVar2 != 0x46) goto loc_F003FAD0;
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  else {
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
loc_F003FAD0:
  _kfree(uVar1,0x400);
locret_F003FAD8:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3362 start=0xf003fae0 */

/* WARNING: Removing unreachable block (ram,0xf003faf0) */
/* WARNING: Removing unreachable block (ram,0xf003faf8) */
/* WARNING: Removing unreachable block (ram,0xf003fae8) */

undefined8 sub_F003FAE0(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(param_1 + 0x30);
  _rlock(iVar1);
  sub_F0040DD4(param_1);
  _runlock(iVar1);
  return CONCAT44(param_2,(int)*(sword *)(iVar1 + 0x62));
}
/* GHIDRADEC_FUNCTION index=3363 start=0xf003fb0c */

/* WARNING: Removing unreachable block (ram,0xf003fbc8) */
/* WARNING: Removing unreachable block (ram,0xf003fbac) */
/* WARNING: Removing unreachable block (ram,0xf003fb8c) */
/* WARNING: Removing unreachable block (ram,0xf003fb44) */
/* WARNING: Removing unreachable block (ram,0xf003fb58) */
/* WARNING: Removing unreachable block (ram,0xf003fba4) */
/* WARNING: Removing unreachable block (ram,0xf003fbbc) */
/* WARNING: Removing unreachable block (ram,0xf003fbd4) */
/* WARNING: Removing unreachable block (ram,0xf003fb14) */

undefined8 sub_F003FB0C(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(param_1 + 0x30);
  _rp_rmhash(iVar1);
  iVar2 = 0;
  if (*(int *)(iVar1 + 0x7c) != 0) {
    *(word *)(iVar1 + 0x60) = *(word *)(iVar1 + 0x60) & 0xffef;
    _rlock(*(undefined4 *)(*(int *)(iVar1 + 0x7c) + 0x30));
    _setdiropargs((undefined *)((int)register0x00000038 + -0x30),*(undefined4 *)(iVar1 + 0x78),
                  *(undefined4 *)(iVar1 + 0x7c));
    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x7c) + 0x24) + 0x128);
    _rfscall(iVar2,10,_xdr_diropargs,(undefined *)((int)register0x00000038 + -0x30),_xdr_enum,
             (undefined *)((int)register0x00000038 + -0x34),*(undefined4 *)(iVar1 + 0x74));
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x34);
    }
    _runlock(*(undefined4 *)(*(int *)(iVar1 + 0x7c) + 0x30));
    _vn_rele(*(undefined4 *)(iVar1 + 0x7c));
    *(undefined4 *)(iVar1 + 0x7c) = 0;
    _kfree(*(undefined4 *)(iVar1 + 0x78),0xff);
    *(undefined4 *)(iVar1 + 0x78) = 0;
    _crfree(*(undefined4 *)(iVar1 + 0x74));
    *(undefined4 *)(iVar1 + 0x74) = 0;
  }
  _rfree(iVar1);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3364 start=0xf003fbe4 */

/* WARNING: Removing unreachable block (ram,0xf003fc5c) */
/* WARNING: Removing unreachable block (ram,0xf003fd70) */
/* WARNING: Removing unreachable block (ram,0xf003fd24) */
/* WARNING: Removing unreachable block (ram,0xf003fce0) */
/* WARNING: Removing unreachable block (ram,0xf003fcb4) */
/* WARNING: Removing unreachable block (ram,0xf003fc74) */
/* WARNING: Removing unreachable block (ram,0xf003fc18) */
/* WARNING: Removing unreachable block (ram,0xf003fc08) */
/* WARNING: Removing unreachable block (ram,0xf003fc68) */
/* WARNING: Removing unreachable block (ram,0xf003fc88) */
/* WARNING: Removing unreachable block (ram,0xf003fcd8) */
/* WARNING: Removing unreachable block (ram,0xf003fcfc) */
/* WARNING: Removing unreachable block (ram,0xf003fd38) */
/* WARNING: Removing unreachable block (ram,0xf003fd7c) */
/* WARNING: Removing unreachable block (ram,0xf003fd88) */
/* WARNING: Removing unreachable block (ram,0xf003fbf4) */

undefined8 sub_F003FBE4(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar2 = param_1;
  _nfs_validate_caches(param_1,param_4,0);
  if (iVar2 != 0) goto locret_F003FD90;
  _rlock(*(undefined4 *)(param_1 + 0x30));
  iVar2 = param_1;
  _dnlc_lookup(param_1,param_2,param_4);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    piVar1 = (int *)0x68;
    _kalloc();
    _bzero();
    _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_2,param_1);
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar2,4,_xdr_diropargs,(undefined *)((int)register0x00000038 + -0x30),_xdr_diropres,
             piVar1,param_4);
    if (iVar2 == 0) {
      iVar2 = *piVar1;
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar2 == 0) {
        piVar3 = piVar1 + 1;
        _makenfsnode(piVar3,piVar1 + 9,*(undefined4 *)(param_1 + 0x24));
        *param_3 = (int)piVar3;
        if (_nfs_dnlc != 0) {
          _dnlc_enter(param_1,param_2,piVar3,param_4);
        }
      }
      else {
        *param_3 = 0;
      }
    }
    else {
      *param_3 = 0;
    }
    _kfree(piVar1,0x68);
    bVar5 = iVar2 == 0;
loc_F003FD44:
    if (bVar5) {
      iVar4 = *param_3;
      if ((*(int *)(iVar4 + 0x28) - 3U < 2) || (*(int *)(iVar4 + 0x28) == 8)) {
        _specvp(iVar4,(int)*(sword *)(iVar4 + 0x2c));
        _vn_rele(*param_3);
        *param_3 = iVar4;
      }
    }
  }
  else {
    *(sword *)(iVar2 + 6) = *(sword *)(iVar2 + 6) + 1;
    iVar2 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,param_4);
    bVar5 = true;
    if (iVar2 == 0) goto loc_F003FD44;
    _vn_rele(*param_3);
  }
  _runlock(*(undefined4 *)(param_1 + 0x30));
locret_F003FD90:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3365 start=0xf003fd98 */

/* WARNING: Removing unreachable block (ram,0xf0040010) */
/* WARNING: Removing unreachable block (ram,0xf003ffdc) */
/* WARNING: Removing unreachable block (ram,0xf003ff98) */
/* WARNING: Removing unreachable block (ram,0xf003ff64) */
/* WARNING: Removing unreachable block (ram,0xf003ff38) */
/* WARNING: Removing unreachable block (ram,0xf0040008) */
/* WARNING: Removing unreachable block (ram,0xf003fed4) */
/* WARNING: Removing unreachable block (ram,0xf003fe9c) */
/* WARNING: Removing unreachable block (ram,0xf003fe0c) */
/* WARNING: Removing unreachable block (ram,0xf003fdf4) */
/* WARNING: Removing unreachable block (ram,0xf003fdd4) */
/* WARNING: Removing unreachable block (ram,0xf003fde8) */
/* WARNING: Removing unreachable block (ram,0xf003fe04) */
/* WARNING: Removing unreachable block (ram,0xf003fe94) */
/* WARNING: Removing unreachable block (ram,0xf003fea8) */
/* WARNING: Removing unreachable block (ram,0xf0040000) */
/* WARNING: Removing unreachable block (ram,0xf003ff0c) */
/* WARNING: Removing unreachable block (ram,0xf003ff40) */
/* WARNING: Removing unreachable block (ram,0xf003ff78) */
/* WARNING: Removing unreachable block (ram,0xf003ffac) */
/* WARNING: Removing unreachable block (ram,0xf003ffe8) */
/* WARNING: Removing unreachable block (ram,0xf004001c) */
/* WARNING: Removing unreachable block (ram,0xf003fdc0) */

undefined8
sub_F003FD98(int param_1,uint param_2,int *param_3,int param_4,undefined4 param_5,int *param_6)

{
  int *piVar1;
  word wVar4;
  int iVar2;
  int *piVar3;
  int iVar5;
  word wVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  if (param_4 == 1) {
    iVar2 = param_1;
    sub_F003FBE4(param_1,param_2,param_6,uVar7,0,0);
    if (iVar2 == 0) {
      _vn_rele(*param_6);
      iVar2 = 0x11;
      goto locret_F0040024;
    }
    *param_6 = 0;
  }
  else {
    *param_6 = 0;
  }
  piVar1 = (int *)0x68;
  _kalloc();
  _bzero();
  _setdiropargs((undefined *)((int)register0x00000038 + -0x50),param_2,param_1);
  iVar2 = param_1;
  _setdirgid();
  iVar5 = *param_3;
  *(sword *)(param_3 + 2) = (sword)iVar2;
  if (iVar5 == 4) {
    wVar4 = *(word *)(param_3 + 1);
    wVar6 = 0x2000;
loc_F003FE44:
    *(word *)(param_3 + 1) = wVar4 | wVar6;
    param_3[6] = (int)*(sword *)(param_3 + 0xe);
  }
  else {
    if (iVar5 == 3) {
      wVar4 = *(word *)(param_3 + 1);
      wVar6 = 0x6000;
      goto loc_F003FE44;
    }
    if (iVar5 == 8) {
      param_3[6] = -1;
      wVar4 = *(word *)(param_3 + 1);
      wVar6 = 0x2000;
loc_F003FE84:
      *(word *)(param_3 + 1) = wVar4 | wVar6;
    }
    else if (iVar5 == 6) {
      wVar4 = *(word *)(param_3 + 1);
      wVar6 = 0xc000;
      goto loc_F003FE84;
    }
  }
  _vattr_to_sattr(param_3,(undefined *)((int)register0x00000038 + -0x2c));
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_remove(param_1,param_2);
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar2,9,_xdr_creatargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_diropres,
           piVar1,uVar7);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      piVar3 = piVar1 + 1;
      _makenfsnode(piVar3,piVar1 + 9,*(undefined4 *)(param_1 + 0x24));
      *param_6 = (int)piVar3;
      if (param_3[6] == 0) {
        *(undefined4 *)(piVar3[0xc] + 0x98) = 0;
        _mfs_trunc(*param_6,0);
        _binvalfree(*param_6);
      }
      if (_nfs_dnlc != 0) {
        _dnlc_enter(param_1,param_2,*param_6,uVar7);
      }
      wVar4 = *(word *)(param_3 + 2);
      param_2 = (uint)wVar4;
      _nattr_to_vattr(*param_6,piVar1 + 9,param_3);
      if (wVar4 != *(word *)(param_3 + 2)) {
        _vattr_null((undefined *)((int)register0x00000038 + -0x90));
        *(word *)((int)register0x00000038 + -0x88) = wVar4;
        sub_F003F758(*param_6,(undefined *)((int)register0x00000038 + -0x90),uVar7);
        *(word *)(param_3 + 2) = wVar4;
      }
      iVar5 = *param_6;
      if ((*(int *)(iVar5 + 0x28) - 3U < 2) || (*(int *)(iVar5 + 0x28) == 8)) {
        _specvp(iVar5,(int)*(sword *)(iVar5 + 0x2c));
        _vn_rele(*param_6);
        *param_6 = iVar5;
      }
    }
    else if (iVar2 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _runlock(*(undefined4 *)(param_1 + 0x30));
  _kfree(piVar1,0x68);
locret_F0040024:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3366 start=0xf004002c */

/* WARNING: Removing unreachable block (ram,0xf0040244) */
/* WARNING: Removing unreachable block (ram,0xf004022c) */
/* WARNING: Removing unreachable block (ram,0xf0040160) */
/* WARNING: Removing unreachable block (ram,0xf0040100) */
/* WARNING: Removing unreachable block (ram,0xf00400dc) */
/* WARNING: Removing unreachable block (ram,0xf004021c) */
/* WARNING: Removing unreachable block (ram,0xf00401a8) */
/* WARNING: Removing unreachable block (ram,0xf00400a4) */
/* WARNING: Removing unreachable block (ram,0xf00400ac) */
/* WARNING: Removing unreachable block (ram,0xf00401d4) */
/* WARNING: Removing unreachable block (ram,0xf0040224) */
/* WARNING: Removing unreachable block (ram,0xf00400e8) */
/* WARNING: Removing unreachable block (ram,0xf004010c) */
/* WARNING: Removing unreachable block (ram,0xf0040120) */
/* WARNING: Removing unreachable block (ram,0xf004025c) */
/* WARNING: Removing unreachable block (ram,0xf0040268) */
/* WARNING: Removing unreachable block (ram,0xf0040048) */

undefined8 sub_F004002C(int param_1,undefined4 param_2,sword *param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  iVar3 = param_1;
  sub_F003FBE4(param_1,param_2,(undefined *)((int)register0x00000038 + -0x34),param_3,0,0);
  iVar5 = 0;
  if (iVar3 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x34);
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x70))
              (iVar2,(undefined *)((int)register0x00000038 + -0x38));
    iVar5 = 0;
    if (iVar2 == 0) {
      iVar5 = *(int *)((int)register0x00000038 + -0x34);
      *(undefined4 *)((int)register0x00000038 + -0x34) =
           *(undefined4 *)((int)register0x00000038 + -0x38);
    }
  }
  bVar6 = iVar3 == 0;
  if ((iVar3 == 0) && (bVar6 = true, *(int *)((int)register0x00000038 + -0x34) != 0)) {
    _rlock(*(undefined4 *)(param_1 + 0x30));
    _dnlc_purge_vp(*(undefined4 *)((int)register0x00000038 + -0x34));
    if ((*(word *)(*(int *)((int)register0x00000038 + -0x34) + 6) < 2) ||
       (iVar2 = *(int *)(*(int *)(*(int *)((int)register0x00000038 + -0x34) + 0x30) + 0x7c),
       iVar2 != 0)) {
      *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x34) + 0x30) + 0x60) =
           *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x34) + 0x30) + 0x60) & 0xffef;
      _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_2,param_1);
      iVar3 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
      _rfscall(iVar3,10,_xdr_diropargs,(undefined *)((int)register0x00000038 + -0x30),_xdr_enum,
               (undefined *)((int)register0x00000038 + -0x3c),param_3);
      iVar2 = *(int *)((int)register0x00000038 + -0x34);
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
      *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0xc0) = 0;
      iVar2 = iVar3;
      if (iVar3 == 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x3c);
      }
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
    }
    else {
      _newname();
      _runlock(*(undefined4 *)(param_1 + 0x30));
      iVar3 = param_1;
      sub_F00403A4(param_1,param_2,param_1,iVar2,param_3);
      _rlock(*(undefined4 *)(param_1 + 0x30));
      if (iVar3 == 0) {
        iVar4 = *(int *)((int)register0x00000038 + -0x34);
        *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
        *(int *)(*(int *)(iVar4 + 0x30) + 0x7c) = param_1;
        *(int *)(*(int *)(iVar4 + 0x30) + 0x78) = iVar2;
        if (*(int *)(*(int *)(iVar4 + 0x30) + 0x74) == 0) {
          sVar1 = *param_3;
        }
        else {
          _crfree();
          sVar1 = *param_3;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x34);
        *param_3 = sVar1 + 1;
        *(sword **)(*(int *)(iVar2 + 0x30) + 0x74) = param_3;
      }
      else {
        _kfree(iVar2,0xff);
      }
    }
    _runlock(*(undefined4 *)(param_1 + 0x30));
    if (iVar5 == 0) {
      _bflush(*(undefined4 *)((int)register0x00000038 + -0x34),0xffffffff,0xffffffff);
      iVar5 = *(int *)((int)register0x00000038 + -0x34);
    }
    else {
      _bflush(iVar5,0xffffffff,0xffffffff);
    }
    _vn_rele(iVar5);
    bVar6 = iVar3 == 0;
  }
  if (bVar6) {
    iVar3 = *(int *)((int)register0x00000038 + -0x3c);
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3367 start=0xf0040284 */

/* WARNING: Removing unreachable block (ram,0xf004038c) */
/* WARNING: Removing unreachable block (ram,0xf0040370) */
/* WARNING: Removing unreachable block (ram,0xf0040330) */
/* WARNING: Removing unreachable block (ram,0xf0040304) */
/* WARNING: Removing unreachable block (ram,0xf004034c) */
/* WARNING: Removing unreachable block (ram,0xf0040378) */
/* WARNING: Removing unreachable block (ram,0xf0040394) */
/* WARNING: Removing unreachable block (ram,0xf00402fc) */

undefined8 sub_F0040284(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))
            (param_1,(undefined *)((int)register0x00000038 + -0x54));
  if (iVar1 == 0) {
    param_1 = *(int *)((int)register0x00000038 + -0x54);
  }
  iVar1 = *(int *)(param_1 + 0x30);
  *(undefined4 *)((int)register0x00000038 + -0x50) = *(undefined4 *)(iVar1 + 0x40);
  *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar1 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x48) = *(undefined4 *)(iVar1 + 0x48);
  *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(iVar1 + 0x4c);
  *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(iVar1 + 0x50);
  *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar1 + 0x54);
  *(undefined4 *)((int)register0x00000038 + -0x38) = *(undefined4 *)(iVar1 + 0x58);
  *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(iVar1 + 0x5c);
  _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_3,param_2);
  _rlock(*(undefined4 *)(param_2 + 0x30));
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar1,0xc,_xdr_linkargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_enum,
           (undefined *)((int)register0x00000038 + -0x58),param_4);
  *(undefined4 *)(*(int *)(param_2 + 0x30) + 0xc0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_2 + 0x30));
  if ((iVar1 == 0) && (iVar1 = *(int *)((int)register0x00000038 + -0x58), iVar1 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
    _btrash(param_2);
    _nfs_invalidate_caches(param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3368 start=0xf00403a4 */

/* WARNING: Removing unreachable block (ram,0xf0040504) */
/* WARNING: Removing unreachable block (ram,0xf00404e8) */
/* WARNING: Removing unreachable block (ram,0xf00404b0) */
/* WARNING: Removing unreachable block (ram,0xf0040468) */
/* WARNING: Removing unreachable block (ram,0xf0040444) */
/* WARNING: Removing unreachable block (ram,0xf0040424) */
/* WARNING: Removing unreachable block (ram,0xf00403fc) */
/* WARNING: Removing unreachable block (ram,0xf00403cc) */
/* WARNING: Removing unreachable block (ram,0xf00403e4) */
/* WARNING: Removing unreachable block (ram,0xf0040418) */
/* WARNING: Removing unreachable block (ram,0xf0040430) */
/* WARNING: Removing unreachable block (ram,0xf0040458) */
/* WARNING: Removing unreachable block (ram,0xf0040494) */
/* WARNING: Removing unreachable block (ram,0xf00404c4) */
/* WARNING: Removing unreachable block (ram,0xf00404f0) */
/* WARNING: Removing unreachable block (ram,0xf004050c) */
/* WARNING: Removing unreachable block (ram,0xf00403b4) */

undefined8 sub_F00403A4(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_2;
  _strcmp(param_2,&unk_F010D708);
  if ((((iVar1 == 0) || (iVar1 = param_2, _strcmp(param_2,&unk_F010D710), iVar1 == 0)) ||
      (iVar1 = param_4, _strcmp(param_4,&unk_F010D718), iVar1 == 0)) ||
     (iVar1 = param_4, _strcmp(param_4,&unk_F010D720), iVar1 == 0)) {
    iVar1 = 0x16;
  }
  else {
    _rlock(*(undefined4 *)(param_1 + 0x30));
    _dnlc_remove(param_1,param_2);
    _dnlc_remove(param_3,param_4);
    if (param_3 != param_1) {
      _rlock(*(undefined4 *)(param_3 + 0x30));
    }
    _setdiropargs((undefined *)((int)register0x00000038 + -0x50),param_2,param_1);
    _setdiropargs((undefined *)((int)register0x00000038 + -0x2c),param_4,param_3);
    iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar1,0xb,_xdr_rnmargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_enum,
             (undefined *)((int)register0x00000038 + -0x54),param_5);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
    *(undefined4 *)(*(int *)(param_3 + 0x30) + 0xc0) = 0;
    _runlock(*(undefined4 *)(param_1 + 0x30));
    if (param_3 != param_1) {
      _runlock(*(undefined4 *)(param_3 + 0x30));
    }
    if ((iVar1 == 0) && (iVar1 = *(int *)((int)register0x00000038 + -0x54), iVar1 == 0x46)) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
      _btrash(param_3);
      _nfs_invalidate_caches(param_3);
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3369 start=0xf004051c */

/* WARNING: Removing unreachable block (ram,0xf0040680) */
/* WARNING: Removing unreachable block (ram,0xf004064c) */
/* WARNING: Removing unreachable block (ram,0xf0040608) */
/* WARNING: Removing unreachable block (ram,0xf00405e0) */
/* WARNING: Removing unreachable block (ram,0xf00405a8) */
/* WARNING: Removing unreachable block (ram,0xf0040570) */
/* WARNING: Removing unreachable block (ram,0xf0040558) */
/* WARNING: Removing unreachable block (ram,0xf0040540) */
/* WARNING: Removing unreachable block (ram,0xf004052c) */
/* WARNING: Removing unreachable block (ram,0xf0040548) */
/* WARNING: Removing unreachable block (ram,0xf0040568) */
/* WARNING: Removing unreachable block (ram,0xf004057c) */
/* WARNING: Removing unreachable block (ram,0xf00405bc) */
/* WARNING: Removing unreachable block (ram,0xf00405e8) */
/* WARNING: Removing unreachable block (ram,0xf0040638) */
/* WARNING: Removing unreachable block (ram,0xf004066c) */
/* WARNING: Removing unreachable block (ram,0xf0040694) */
/* WARNING: Removing unreachable block (ram,0xf0040520) */

undefined8 sub_F004051C(int param_1,undefined4 param_2,int param_3,int *param_4,undefined4 param_5)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar2 = (int *)0x68;
  _kalloc();
  _bzero();
  _setdiropargs((undefined *)((int)register0x00000038 + -0x50),param_2,param_1);
  iVar3 = param_1;
  _setdirgid();
  *(sword *)(param_3 + 8) = (sword)iVar3;
  iVar3 = param_1;
  _setdirmode(param_1,*(undefined2 *)(param_3 + 4));
  *(sword *)(param_3 + 4) = (sword)iVar3;
  _vattr_to_sattr(param_3,(undefined *)((int)register0x00000038 + -0x2c));
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_remove(param_1,param_2);
  iVar3 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar3,0xe,_xdr_creatargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_diropres,
           piVar2,param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x30));
  if (iVar3 == 0) {
    iVar3 = *piVar2;
    if (iVar3 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    if (iVar3 == 0) {
      piVar4 = piVar2 + 1;
      _makenfsnode(piVar4,piVar2 + 9,*(undefined4 *)(param_1 + 0x24));
      *param_4 = (int)piVar4;
      bVar5 = _nfs_dnlc != 0;
      *(undefined4 *)(piVar4[0xc] + 0xc0) = 0;
      if (bVar5) {
        _dnlc_enter(param_1,param_2,*param_4,param_5);
      }
      sVar1 = *(sword *)(param_3 + 8);
      _nattr_to_vattr(*param_4,piVar2 + 9,param_3);
      if (sVar1 != *(sword *)(param_3 + 8)) {
        _vattr_null(param_3);
        *(sword *)(param_3 + 8) = sVar1;
        sub_F003F758(*param_4,param_3,param_5);
      }
    }
    else {
      *param_4 = 0;
    }
  }
  else {
    *param_4 = 0;
  }
  _kfree(piVar2,0x68);
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3370 start=0xf00406a4 */

/* WARNING: Removing unreachable block (ram,0xf0040728) */
/* WARNING: Removing unreachable block (ram,0xf00406f0) */
/* WARNING: Removing unreachable block (ram,0xf00406bc) */
/* WARNING: Removing unreachable block (ram,0xf00406c4) */
/* WARNING: Removing unreachable block (ram,0xf0040704) */
/* WARNING: Removing unreachable block (ram,0xf0040730) */
/* WARNING: Removing unreachable block (ram,0xf00406b4) */

undefined8 sub_F00406A4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _setdiropargs((undefined *)((int)register0x00000038 + -0x30),param_2,param_1);
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_purge_vp(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar1,0xf,_xdr_diropargs,(undefined *)((int)register0x00000038 + -0x30),_xdr_enum,
           (undefined *)((int)register0x00000038 + -0x34),param_3);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x30));
  if ((iVar1 == 0) && (iVar1 = *(int *)((int)register0x00000038 + -0x34), iVar1 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3371 start=0xf0040740 */

/* WARNING: Removing unreachable block (ram,0xf00407bc) */
/* WARNING: Removing unreachable block (ram,0xf0040760) */
/* WARNING: Removing unreachable block (ram,0xf0040790) */
/* WARNING: Removing unreachable block (ram,0xf00407c4) */
/* WARNING: Removing unreachable block (ram,0xf0040754) */

undefined8
sub_F0040740(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _setdiropargs((undefined *)((int)register0x00000038 + -0x50),param_2,param_1);
  _vattr_to_sattr(param_3,(undefined *)((int)register0x00000038 + -0x28));
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_4;
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar1,0xd,_xdr_slargs,(undefined *)((int)register0x00000038 + -0x50),_xdr_enum,
           (undefined *)((int)register0x00000038 + -0x54),param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  if ((iVar1 == 0) && (iVar1 = *(int *)((int)register0x00000038 + -0x54), iVar1 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3372 start=0xf00407d4 */

/* WARNING: Removing unreachable block (ram,0xf00408f4) */
/* WARNING: Removing unreachable block (ram,0xf00408c4) */
/* WARNING: Removing unreachable block (ram,0xf0040874) */
/* WARNING: Removing unreachable block (ram,0xf0040868) */
/* WARNING: Removing unreachable block (ram,0xf00408a0) */
/* WARNING: Removing unreachable block (ram,0xf00408cc) */
/* WARNING: Removing unreachable block (ram,0xf0040934) */
/* WARNING: Removing unreachable block (ram,0xf004085c) */

undefined8 sub_F00407D4(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar5 = *(int *)(param_1 + 0x30);
  if ((*(word *)(iVar5 + 0x60) & 8) == 0) {
    iVar1 = *param_2;
  }
  else {
    if (*(int *)(iVar5 + 0x98) == param_2[2]) {
      iVar1 = 0;
      goto locret_F004093C;
    }
    iVar1 = *param_2;
  }
  if (param_2[1] == 1) {
    uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x1c);
    if (*(uint *)(iVar1 + 4) < uVar2) {
      uVar2 = *(uint *)(iVar1 + 4);
    }
    *(uint *)((int)register0x00000038 + -0xc) = uVar2;
    *(int *)((int)register0x00000038 + -0x10) = param_2[2];
    _bcopy(*(int *)(param_1 + 0x30) + 0x40,(undefined *)((int)register0x00000038 + -0x30),0x20);
    *(uint *)((int)register0x00000038 + -0x3c) = uVar2;
    uVar3 = uVar2;
    _kalloc();
    *(uint *)((int)register0x00000038 + -0x34) = uVar3;
    _bzero();
    iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar1,0x10,_xdr_rddirargs,(undefined *)((int)register0x00000038 + -0x30),
             _xdr_getrddirres,(undefined *)((int)register0x00000038 + -0x48),param_3);
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)register0x00000038 + -0x44);
      if (iVar1 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar1 == 0) {
        if (*(int *)((int)register0x00000038 + -0x3c) != 0) {
          iVar1 = *(int *)((int)register0x00000038 + -0x34);
          _uiomove(iVar1,*(int *)((int)register0x00000038 + -0x3c),0,param_2);
          *(int *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x40);
          param_2[2] = *(int *)((int)register0x00000038 + -0x40);
        }
        uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
        if (*(int *)((int)register0x00000038 + -0x38) != 0) {
          *(word *)(iVar5 + 0x60) = *(word *)(iVar5 + 0x60) | 8;
          *(int *)(iVar5 + 0x98) = param_2[2];
          uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
        }
      }
      else {
        uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
      }
    }
    else {
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
    }
    _kfree(uVar4,uVar2);
  }
  else {
    iVar1 = 0x16;
  }
locret_F004093C:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3373 start=0xf0040944 */

/* WARNING: Removing unreachable block (ram,0xf00409fc) */
/* WARNING: Removing unreachable block (ram,0xf0040a08) */
/* WARNING: Removing unreachable block (ram,0xf00409ec) */
/* WARNING: Removing unreachable block (ram,0xf0040980) */

undefined8 sub_F0040944(uint *param_1,undefined4 param_2)

{
  sword sVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (((*param_1 & 1) == 0) &&
     (sVar1 = *(sword *)(*(int *)(param_1[0x10] + 0x30) + 0x62), sVar1 != 0)) {
    *(sword *)(param_1 + 7) = sVar1;
    *param_1 = *param_1 | 4;
    _biodone();
  }
  else if ((dword_F012F528 == 0) || ((*param_1 & 0x100) == 0)) {
    sub_F0040B74(param_1);
  }
  else {
    puVar3 = _async_bufhead;
    puVar2 = param_1;
    if (_async_bufhead != (uint *)0x0) {
      for (; puVar3[3] != 0; puVar3 = (uint *)puVar3[3]) {
      }
      puVar3[3] = (uint)param_1;
      puVar2 = _async_bufhead;
    }
    _async_bufhead = puVar2;
    bVar4 = _nfs_wakeup_one_biod == 1;
    param_1[3] = 0;
    if (bVar4) {
      _wakeup_one(&_async_bufhead);
    }
    else {
      _wakeup(&_async_bufhead);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3374 start=0xf0040b74 */

/* WARNING: Removing unreachable block (ram,0xf0040c24) */
/* WARNING: Removing unreachable block (ram,0xf0040bcc) */
/* WARNING: Removing unreachable block (ram,0xf0040cb0) */
/* WARNING: Removing unreachable block (ram,0xf0040c8c) */
/* WARNING: Removing unreachable block (ram,0xf0040c98) */
/* WARNING: Removing unreachable block (ram,0xf0040ba8) */
/* WARNING: Removing unreachable block (ram,0xf0040c04) */
/* WARNING: Removing unreachable block (ram,0xf0040d24) */
/* WARNING: Removing unreachable block (ram,0xf0040c58) */

undefined8 sub_F0040B74(uint *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  sword sVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar1 = (int *)param_1[0x10];
  iVar8 = piVar1[0xc];
  piVar2 = piVar1;
  (**(code **)(piVar1[7] + 0x80))(piVar1);
  if ((*param_1 & 1) == 0) {
    iVar7 = (int)*(sword *)(iVar8 + 0x62);
    if (iVar7 == 0) {
      uVar5 = param_1[9];
      .umul(uVar5,piVar2);
      uVar5 = *(int *)(iVar8 + 0x98) - uVar5;
      uVar3 = param_1[5];
      if (uVar5 <= param_1[5]) {
        uVar3 = uVar5;
      }
      if ((int)uVar3 < 0) {
        _panic(aDoBioWriteCoun);
        uVar5 = param_1[9];
      }
      else {
        uVar5 = param_1[9];
      }
      .umul(uVar5,piVar2);
      piVar2 = piVar1;
      _nfswrite(piVar1,param_1[8],uVar5,uVar3,*(undefined4 *)(iVar8 + 0x70));
      sVar6 = (sword)piVar2;
      *(sword *)(param_1 + 7) = sVar6;
      iVar7 = (int)sVar6;
      if ((*param_1 & 0x100) != 0) {
        *(sword *)(iVar8 + 0x62) = sVar6;
      }
    }
    else {
      *(sword *)(param_1 + 7) = *(sword *)(iVar8 + 0x62);
    }
  }
  else {
    uVar3 = param_1[9];
    .umul(uVar3,piVar2);
    piVar4 = piVar1;
    sub_F003F5B4(piVar1,param_1[8],uVar3,param_1[5],param_1 + 10,*(undefined4 *)(iVar8 + 0x70),
                 (undefined *)((int)register0x00000038 + -0x48));
    *(sword *)(param_1 + 7) = (sword)piVar4;
    iVar7 = (int)(sword)piVar4;
    bVar9 = iVar7 == 0;
    if (!bVar9) goto loc_F0040CE8;
    uVar5 = param_1[5];
    uVar3 = 0;
    if (param_1[10] != 0) {
      _bzero(param_1[8] + (uVar5 - param_1[10]));
      uVar3 = param_1[10];
      uVar5 = param_1[5];
    }
    bVar9 = true;
    if (uVar3 != uVar5) goto loc_F0040CE8;
    uVar3 = param_1[9];
    .umul(uVar3,piVar2);
    if (uVar3 < *(uint *)(iVar8 + 0x98)) {
      bVar9 = true;
      goto loc_F0040CE8;
    }
    iVar7 = -0x62;
  }
  bVar9 = iVar7 == 0;
loc_F0040CE8:
  if ((!bVar9) && (iVar7 != -0x62)) {
    *param_1 = *param_1 | 4;
    iVar8 = *piVar1;
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x34) == 0)) {
      *(int *)(iVar8 + 0x34) = iVar7;
    }
  }
  _biodone(param_1);
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=3375 start=0xf0040d34 */

undefined8 sub_F0040D34(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x47);
}
/* GHIDRADEC_FUNCTION index=3376 start=0xf0040d40 */

undefined8 sub_F0040D40(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3377 start=0xf0040d4c */

undefined8 sub_F0040D4C(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,(uint)(param_1 == param_2));
}
/* GHIDRADEC_FUNCTION index=3378 start=0xf0040d64 */

undefined8 sub_F0040D64(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3379 start=0xf0040dd4 */

/* WARNING: Removing unreachable block (ram,0xf0040e10) */
/* WARNING: Removing unreachable block (ram,0xf0040de4) */

undefined8 sub_F0040DD4(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar3 = *(int *)(param_1 + 0x30);
  _bflush(param_1,0xffffffff,0xffffffff);
  uVar1 = 0;
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x24);
  if (*(int *)(iVar3 + 0x98) != 0) {
    do {
      _blkflush(param_1,uVar1 >> 10,iVar2);
      uVar1 = uVar1 + iVar2;
    } while (uVar1 < *(uint *)(iVar3 + 0x98));
  }
  *(word *)(iVar3 + 0x60) = *(word *)(iVar3 + 0x60) & 0xffef;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3380 start=0xf0040e48 */

/* WARNING: Removing unreachable block (ram,0xf0040e80) */

sqword sub_F0040E48(int param_1,uint param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1;
  }
  if (param_4 != (uint *)0x0) {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x24);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x3ff;
    }
    uVar1 = param_2;
    .umul(param_2,iVar2 >> 10);
    *param_4 = uVar1;
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3381 start=0xf0040e94 */

/* WARNING: Removing unreachable block (ram,0xf0041294) */
/* WARNING: Removing unreachable block (ram,0xf0041228) */
/* WARNING: Removing unreachable block (ram,0xf0041220) */
/* WARNING: Removing unreachable block (ram,0xf004119c) */
/* WARNING: Removing unreachable block (ram,0xf0041130) */
/* WARNING: Removing unreachable block (ram,0xf00410e8) */
/* WARNING: Removing unreachable block (ram,0xf00410a4) */
/* WARNING: Removing unreachable block (ram,0xf004102c) */
/* WARNING: Removing unreachable block (ram,0xf0040fe0) */
/* WARNING: Removing unreachable block (ram,0xf0040fac) */
/* WARNING: Removing unreachable block (ram,0xf0040f54) */
/* WARNING: Removing unreachable block (ram,0xf0040ee0) */
/* WARNING: Removing unreachable block (ram,0xf0040f4c) */
/* WARNING: Removing unreachable block (ram,0xf0040f74) */
/* WARNING: Removing unreachable block (ram,0xf0040fcc) */
/* WARNING: Removing unreachable block (ram,0xf0040ff0) */
/* WARNING: Removing unreachable block (ram,0xf004104c) */
/* WARNING: Removing unreachable block (ram,0xf00410c4) */
/* WARNING: Removing unreachable block (ram,0xf0041148) */
/* WARNING: Removing unreachable block (ram,0xf004117c) */
/* WARNING: Removing unreachable block (ram,0xf00411f8) */
/* WARNING: Removing unreachable block (ram,0xf0041210) */
/* WARNING: Removing unreachable block (ram,0xf0041248) */
/* WARNING: Removing unreachable block (ram,0xf00412b4) */
/* WARNING: Removing unreachable block (ram,0xf0040eb4) */

undefined8 sub_F0040E94(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  int *piVar7;
  sword *psVar8;
  undefined4 unaff_l1;
  uint uVar9;
  int iVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar14;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar14 = 0;
  piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar7 != 0);
    piVar1 = piVar7;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100000;
  *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
  iVar10 = param_1[0xc];
  _rlock(iVar10);
  uVar5 = _page_size;
  psVar8 = *(sword **)(*param_1 + 0x30);
  uVar12 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00;
  if (psVar8 == (sword *)0x0) {
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
      psVar8 = *(sword **)(iVar10 + 0x70);
      if (psVar8 == (sword *)0x0) {
        _printf(aNfsFailureOnPa);
        _runlock(iVar10);
        piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
        do {
          do {
          } while (*piVar7 != 0);
          piVar1 = piVar7;
          _simple_lock_try();
          uVar13 = 2;
        } while (piVar1 == (int *)0x0);
        uVar5 = *(uint *)(param_2 + 0x20);
        goto loc_F00412D0;
      }
    }
    else {
      psVar8 = (sword *)_active_u[7];
    }
  }
  *psVar8 = *psVar8 + 1;
  if (*(int *)(iVar10 + 0x70) == 0) {
    *(sword **)(iVar10 + 0x70) = psVar8;
  }
  else {
    _crfree();
    *(sword **)(iVar10 + 0x70) = psVar8;
  }
  if (*(uint *)(iVar10 + 0x98) < param_3 + uVar5) {
    _vm_page_zero_fill(param_2);
  }
  while( true ) {
    uVar2 = param_3;
    .udiv(param_3,uVar12);
    uVar3 = param_3;
    .urem(param_3,uVar12);
    uVar9 = uVar5;
    if (uVar12 - uVar3 < uVar5) {
      uVar9 = uVar12 - uVar3;
    }
    uVar4 = *(uint *)(iVar10 + 0x98) - param_3;
    if (*(uint *)(iVar10 + 0x98) <= param_3) break;
    if (uVar4 < uVar9) {
      uVar9 = uVar4;
    }
    (**(code **)(param_1[7] + 0x50))
              (param_1,uVar2,(undefined *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    if (*(int *)((int)register0x00000038 + -0x10) < 0) {
      _runlock(iVar10);
      piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      uVar5 = *(uint *)(param_2 + 0x20);
      uVar13 = 1;
      goto loc_F0041264;
    }
    _nfs_validate_caches
              (*(undefined4 *)((int)register0x00000038 + -0xc),*(undefined4 *)(iVar10 + 0x70),0);
    iVar11 = 0;
    if (*(int *)(iVar10 + 100) + 1U == uVar2) {
      (**(code **)(param_1[7] + 0x50))
                (param_1,*(int *)(iVar10 + 100) + 2,0,(undefined *)((int)register0x00000038 + -0x14)
                );
      puVar6 = *(uint **)((int)register0x00000038 + -0xc);
      _breada(puVar6,*(undefined4 *)((int)register0x00000038 + -0x10),uVar12,
              *(undefined4 *)((int)register0x00000038 + -0x14),uVar12);
    }
    else {
      puVar6 = *(uint **)((int)register0x00000038 + -0xc);
      _bread(puVar6,*(undefined4 *)((int)register0x00000038 + -0x10),uVar12);
    }
    *(uint *)(iVar10 + 100) = uVar2;
    if ((*puVar6 & 4) == 0) {
      _copy_to_phys(puVar6[8] + uVar3,*(int *)(param_2 + 0x24) + iVar14,uVar9);
      if ((*puVar6 & 0xfffffffc) == 0) {
        *puVar6 = *puVar6 | 0x400000;
      }
    }
    else {
      iVar11 = (int)*(sword *)(puVar6 + 7);
    }
    _brelse(puVar6);
    if (iVar11 != 0) {
      *(int *)(*param_1 + 0x34) = iVar11;
      if (*(sword *)(*param_1 + 4) == 0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
          _printf(aSD_1,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
        }
        if (iVar11 == 0x46) {
          _printf(aNfsReadErrorOn);
        }
        else {
          _printf(aNfsReadErrorDO,iVar11);
        }
      }
      _runlock(iVar10);
      piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      uVar5 = *(uint *)(param_2 + 0x20);
      uVar13 = 2;
      goto loc_F0041264;
    }
    uVar5 = uVar5 - uVar9;
    iVar14 = iVar14 + uVar9;
    param_3 = param_3 + uVar9;
    if (((int)uVar5 < 1) || (uVar9 == 0)) goto loc_F0041294;
  }
  if (iVar14 == 0) {
    _runlock(iVar10);
    piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
    do {
      do {
      } while (*piVar7 != 0);
      piVar1 = piVar7;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    uVar5 = *(uint *)(param_2 + 0x20);
    uVar13 = 1;
loc_F0041264:
    *(uint *)(param_2 + 0x20) = uVar5 & 0xffefffff;
    *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
    goto locret_F00412E4;
  }
loc_F0041294:
  _runlock(iVar10);
  piVar7 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar7 != 0);
    piVar1 = piVar7;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar13 = 0;
  uVar5 = *(uint *)(param_2 + 0x20);
loc_F00412D0:
  *(uint *)(param_2 + 0x20) = uVar5 & 0xffefffff;
  *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
locret_F00412E4:
  return CONCAT44(param_2,uVar13);
}
/* GHIDRADEC_FUNCTION index=3382 start=0xf00412ec */

/* WARNING: Removing unreachable block (ram,0xf00415f0) */
/* WARNING: Removing unreachable block (ram,0xf00415a4) */
/* WARNING: Removing unreachable block (ram,0xf0041584) */
/* WARNING: Removing unreachable block (ram,0xf004157c) */
/* WARNING: Removing unreachable block (ram,0xf00414e4) */
/* WARNING: Removing unreachable block (ram,0xf0041398) */
/* WARNING: Removing unreachable block (ram,0xf00414b8) */
/* WARNING: Removing unreachable block (ram,0xf0041480) */
/* WARNING: Removing unreachable block (ram,0xf00413e0) */
/* WARNING: Removing unreachable block (ram,0xf0041388) */
/* WARNING: Removing unreachable block (ram,0xf00413c8) */
/* WARNING: Removing unreachable block (ram,0xf00413f4) */
/* WARNING: Removing unreachable block (ram,0xf00414c4) */
/* WARNING: Removing unreachable block (ram,0xf004149c) */
/* WARNING: Removing unreachable block (ram,0xf00414f4) */
/* WARNING: Removing unreachable block (ram,0xf0041554) */
/* WARNING: Removing unreachable block (ram,0xf0041570) */
/* WARNING: Removing unreachable block (ram,0xf004158c) */
/* WARNING: Removing unreachable block (ram,0xf0041600) */
/* WARNING: Removing unreachable block (ram,0xf004161c) */
/* WARNING: Removing unreachable block (ram,0xf0041338) */

undefined8 sub_F00412EC(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  sword *psVar5;
  uint uVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar9 = 0;
  iVar7 = param_1[0xc];
  if (((_active_threads == _pageoutThread) && ((*(word *)(iVar7 + 0x60) & 1) != 0)) &&
     (*(int *)(*(int *)(iVar7 + 0x68) + 0x198) != 0)) {
    uVar10 = 2;
  }
  else {
    iVar4 = iVar7;
    _rlock_timeout(iVar7,5);
    if (iVar4 == 1) {
      uVar10 = 2;
    }
    else {
      psVar5 = *(sword **)(*param_1 + 0x30);
      uVar8 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24);
      if (psVar5 == (sword *)0x0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
          _printf(aNfsFailureOnPa_0);
loc_F004158C:
          _runlock(iVar7);
          uVar10 = 2;
          goto locret_F0041628;
        }
        psVar5 = (sword *)_active_u[7];
      }
      *psVar5 = *psVar5 + 1;
      if (*(int *)(iVar7 + 0x70) == 0) {
        *(sword **)(iVar7 + 0x70) = psVar5;
      }
      else {
        _crfree();
        *(sword **)(iVar7 + 0x70) = psVar5;
      }
      do {
        uVar1 = param_4;
        .udiv(param_4,uVar8);
        uVar2 = param_4;
        .urem(param_4,uVar8);
        uVar6 = param_3;
        if (uVar8 - uVar2 < param_3) {
          uVar6 = uVar8 - uVar2;
        }
        (**(code **)(param_1[7] + 0x50))
                  (param_1,uVar1,(undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x10));
        if (*(sword *)(iVar7 + 0x62) != 0) {
          *(int *)(*param_1 + 0x34) = (int)*(sword *)(iVar7 + 0x62);
          if (*(sword *)(*param_1 + 4) == 0) {
            if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
              _printf(aSD_2,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
            }
            if (*(sword *)(iVar7 + 0x62) == 0x1c) {
              _printf(aNfsWriteErrorO_0);
              *(undefined2 *)(iVar7 + 0x62) = 0;
            }
            else if (*(sword *)(iVar7 + 0x62) == 0x46) {
              _printf(aNfsWriteErrorO_1);
            }
            else {
              _printf(aNfsWriteErrorD_0);
            }
          }
          goto loc_F004158C;
        }
        iVar4 = *(int *)((int)register0x00000038 + -0x10);
        if (iVar4 < 0) {
          _printf(aNfsMappingErro);
          goto loc_F004158C;
        }
        puVar3 = *(uint **)((int)register0x00000038 + -0xc);
        if (uVar6 == uVar8) {
          _getblk(puVar3,iVar4,uVar6);
        }
        else {
          _bread(puVar3,iVar4,uVar8);
        }
        if ((*puVar3 & 4) != 0) {
          *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar3 + 7);
          if (*(sword *)(*param_1 + 4) == 0) {
            if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
              _printf(aSD_3,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
            }
            if (*(sword *)(puVar3 + 7) == 0x46) {
              _printf(aNfsReadErrorOn_0);
            }
            else {
              _printf(aNfsReadErrorDO_0);
            }
          }
          _brelse(puVar3);
          goto loc_F004158C;
        }
        _copy_from_phys(param_2 + iVar9,puVar3[8] + uVar2,uVar6);
        param_4 = param_4 + uVar6;
        if (*(uint *)(iVar7 + 0x98) < param_4) {
          *(uint *)(iVar7 + 0x98) = param_4;
        }
        param_3 = param_3 - uVar6;
        iVar9 = iVar9 + uVar6;
        *(word *)(iVar7 + 0x60) = *(word *)(iVar7 + 0x60) | 0x10;
        if (uVar6 + uVar2 == uVar8) {
          *puVar3 = *puVar3 | 0x400000;
          _bawrite();
        }
        else {
          _bdwrite(puVar3);
        }
      } while ((param_3 != 0) && (uVar6 != 0));
      _runlock(iVar7);
      uVar10 = 0;
    }
  }
locret_F0041628:
  return CONCAT44(param_2,uVar10);
}
/* GHIDRADEC_FUNCTION index=3383 start=0xf0041630 */

undefined8 sub_F0041630(int param_1,int *param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar2 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,(undefined *)((int)register0x00000038 + -0x48),
             *(undefined4 *)(_active_u + 0x1c));
  sVar1 = *(sword *)((int)register0x00000038 + -0x34);
  if (iVar2 == 0) {
    *param_2 = (int)sVar1;
    if (*(int *)(*(int *)(param_1 + 0x30) + 0x7c) != 0) {
      *param_2 = sVar1 + -1;
    }
    iVar2 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3384 start=0xf0041690 */

undefined8 sub_F0041690(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,0x400);
}
/* GHIDRADEC_FUNCTION index=3385 start=0xf0041784 */

/* WARNING: Removing unreachable block (ram,0xf0041a58) */
/* WARNING: Removing unreachable block (ram,0xf0041a30) */
/* WARNING: Removing unreachable block (ram,0xf0041a08) */
/* WARNING: Removing unreachable block (ram,0xf00419e0) */
/* WARNING: Removing unreachable block (ram,0xf00419b8) */
/* WARNING: Removing unreachable block (ram,0xf0041990) */
/* WARNING: Removing unreachable block (ram,0xf004197c) */
/* WARNING: Removing unreachable block (ram,0xf00419a4) */
/* WARNING: Removing unreachable block (ram,0xf00419cc) */
/* WARNING: Removing unreachable block (ram,0xf00419f4) */
/* WARNING: Removing unreachable block (ram,0xf0041a1c) */
/* WARNING: Removing unreachable block (ram,0xf0041a44) */
/* WARNING: Removing unreachable block (ram,0xf0041a6c) */
/* WARNING: Removing unreachable block (ram,0xf0041968) */

undefined8 sub_F0041784(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (*param_1 == 0) {
    piVar1 = param_1;
    (**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (piVar1 != (int *)0x0) {
      *piVar1 = *param_2;
      piVar1[1] = param_2[1];
      piVar1[2] = param_2[2];
      piVar1[3] = param_2[3];
      piVar1[4] = param_2[4];
      piVar1[5] = param_2[5];
      piVar1[6] = param_2[6];
      piVar1[7] = param_2[7];
      piVar1[8] = param_2[8];
      piVar1[9] = param_2[9];
      piVar1[10] = param_2[10];
      piVar1[0xb] = param_2[0xb];
      piVar1[0xc] = param_2[0xc];
      piVar1[0xd] = param_2[0xd];
      piVar1[0xe] = param_2[0xe];
      piVar1[0xf] = param_2[0xf];
      uVar2 = 1;
      piVar1[0x10] = param_2[0x10];
      goto locret_F0041A84;
    }
  }
  else {
    piVar1 = param_1;
    (**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (piVar1 != (int *)0x0) {
      *param_2 = *piVar1;
      param_2[1] = piVar1[1];
      param_2[2] = piVar1[2];
      param_2[3] = piVar1[3];
      param_2[4] = piVar1[4];
      param_2[5] = piVar1[5];
      param_2[6] = piVar1[6];
      param_2[7] = piVar1[7];
      param_2[8] = piVar1[8];
      param_2[9] = piVar1[9];
      param_2[10] = piVar1[10];
      param_2[0xb] = piVar1[0xb];
      param_2[0xc] = piVar1[0xc];
      param_2[0xd] = piVar1[0xd];
      param_2[0xe] = piVar1[0xe];
      param_2[0xf] = piVar1[0xf];
      uVar2 = 1;
      param_2[0x10] = piVar1[0x10];
      goto locret_F0041A84;
    }
  }
  piVar1 = param_1;
  _xdr_enum(param_1,param_2);
  if (((((piVar1 != (int *)0x0) &&
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 1), piVar1 != (int *)0x0)) &&
       (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 2), piVar1 != (int *)0x0)) &&
      (((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 3), piVar1 != (int *)0x0 &&
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 4), piVar1 != (int *)0x0)) &&
       ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 5), piVar1 != (int *)0x0 &&
        ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 6), piVar1 != (int *)0x0 &&
         (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 7), piVar1 != (int *)0x0)))))))) &&
     ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 8), piVar1 != (int *)0x0 &&
      ((((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 9), piVar1 != (int *)0x0 &&
         (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 10), piVar1 != (int *)0x0)) &&
        (piVar1 = param_1, sub_F00422B8(param_1,param_2 + 0xb), piVar1 != (int *)0x0)) &&
       (piVar1 = param_1, sub_F00422B8(param_1,param_2 + 0xd), piVar1 != (int *)0x0)))))) {
    sub_F00422B8(param_1,param_2 + 0xf);
    uVar2 = 1;
    if (param_1 != (int *)0x0) goto locret_F0041A84;
  }
  uVar2 = 0;
locret_F0041A84:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3386 start=0xf0041af0 */

/* WARNING: Removing unreachable block (ram,0xf0041bd0) */
/* WARNING: Removing unreachable block (ram,0xf0041b68) */
/* WARNING: Removing unreachable block (ram,0xf0041b44) */
/* WARNING: Removing unreachable block (ram,0xf0041b10) */
/* WARNING: Removing unreachable block (ram,0xf0041b28) */
/* WARNING: Removing unreachable block (ram,0xf0041b4c) */
/* WARNING: Removing unreachable block (ram,0xf0041bac) */
/* WARNING: Removing unreachable block (ram,0xf0041bf0) */
/* WARNING: Removing unreachable block (ram,0xf0041af4) */

qword sub_F0041AF0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = param_1;
  _spltty();
  iVar3 = *(int *)(param_1 + 4);
  while (iVar3 == 0) {
    _sleep(param_1,0x18);
    iVar3 = *(int *)(param_1 + 4);
  }
  _splx(uVar1);
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x5c))
            (*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  uVar2 = *(undefined4 *)(param_1 + 8);
  _vn_rele(uVar2);
  puVar4 = (undefined4 *)(param_1 & 0xffffff80);
  _spltty();
  if (*(sword *)((int)puVar4 + 10) == 0) {
    _panic(&aMfree_8);
  }
  iVar3 = (int)((uint)*(word *)((int)puVar4 + 10) << 0x10) >> 0xf;
  *(sword *)((int)&word_F0134B0C + iVar3) = *(sword *)((int)&word_F0134B0C + iVar3) + -1;
  word_F0134B0C = word_F0134B0C + 1;
  *(undefined2 *)((int)puVar4 + 10) = 0;
  if (0x7f < (uint)puVar4[1]) {
    _mclput(puVar4);
  }
  puVar4[1] = 0;
  puVar4[0x1f] = 0;
  *puVar4 = _mfree;
  _mfree = puVar4;
  _splx(uVar2);
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return CONCAT44(param_2,param_1) & 0xffffffffffffff80;
}
/* GHIDRADEC_FUNCTION index=3387 start=0xf0041c00 */

/* WARNING: Removing unreachable block (ram,0xf0041c0c) */

undefined8 sub_F0041C00(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)(param_1 + 4) = 1;
  _wakeup();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3388 start=0xf0041c1c */

/* WARNING: Removing unreachable block (ram,0xf0041d4c) */
/* WARNING: Removing unreachable block (ram,0xf0041cd8) */
/* WARNING: Removing unreachable block (ram,0xf0041ccc) */
/* WARNING: Removing unreachable block (ram,0xf0041c58) */
/* WARNING: Removing unreachable block (ram,0xf0041c80) */
/* WARNING: Removing unreachable block (ram,0xf0041cf0) */
/* WARNING: Removing unreachable block (ram,0xf0041d74) */
/* WARNING: Removing unreachable block (ram,0xf0041c24) */

undefined8 sub_F0041C1C(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar1 = param_1;
  sub_F0041784(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar4 = 0;
    goto locret_F0041D8C;
  }
  if ((*param_1 == 0) && (*(int *)(param_2 + 0x4c) != 0)) {
    piVar1 = param_1;
    _spltty();
    puVar2 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x1;
      _m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_16);
      }
      *(undefined2 *)((int)puVar2 + 10) = 1;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
      _mfree = (undefined4 *)*puVar2;
      puVar2[1] = 0xc;
      *puVar2 = 0;
    }
    _splx(piVar1);
    if (puVar2 == (undefined4 *)0x0) {
      _printf(aXdrRrokFailedC);
      uVar4 = 0;
      goto locret_F0041D8C;
    }
    iVar3 = puVar2[1];
    *(code **)((int)puVar2 + iVar3) = sub_F0041AF0;
    iVar3 = (int)puVar2 + iVar3;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2 + 0x44);
    param_1[2] = iVar3;
    piVar1 = param_1;
    _xdrmbuf_putbuf(param_1,*(undefined4 *)(param_2 + 0x48),*(undefined4 *)(param_2 + 0x44),
                    sub_F0041C00,iVar3);
    if (piVar1 != (int *)0x0) {
      uVar4 = 1;
      goto locret_F0041D8C;
    }
    *(undefined4 *)(iVar3 + 4) = 1;
  }
  _xdr_bytes(param_1,param_2 + 0x48,param_2 + 0x44,0x2000);
  uVar4 = 1;
  if (param_1 == (int *)0x0) {
    uVar4 = 0;
  }
locret_F0041D8C:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3389 start=0xf0041dc8 */

/* WARNING: Removing unreachable block (ram,0xf0041e20) */
/* WARNING: Removing unreachable block (ram,0xf0041df8) */
/* WARNING: Removing unreachable block (ram,0xf0041de4) */
/* WARNING: Removing unreachable block (ram,0xf0041e0c) */
/* WARNING: Removing unreachable block (ram,0xf0041e34) */
/* WARNING: Removing unreachable block (ram,0xf0041dd0) */

undefined8 sub_F0041DC8(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1;
  _xdr_u_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = param_1, _xdr_u_long(param_1,param_2 + 4), iVar1 != 0)) &&
      (iVar1 = param_1, _xdr_u_long(param_1,param_2 + 8), iVar1 != 0)) &&
     ((iVar1 = param_1, _xdr_u_long(param_1,param_2 + 0xc), iVar1 != 0 &&
      (iVar1 = param_1, sub_F00422B8(param_1,param_2 + 0x10), iVar1 != 0)))) {
    sub_F00422B8(param_1,param_2 + 0x18);
    uVar2 = 1;
    if (param_1 != 0) goto locret_F0041E4C;
  }
  uVar2 = 0;
locret_F0041E4C:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3390 start=0xf0041e88 */

/* WARNING: Removing unreachable block (ram,0xf0041e98) */

undefined8 sub_F0041E88(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _xdr_bytes(param_1,param_2 + 4,param_2,0x400);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=3391 start=0xf0042248 */

/* WARNING: Removing unreachable block (ram,0xf0042264) */
/* WARNING: Removing unreachable block (ram,0xf0042250) */

undefined8 sub_F0042248(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1;
  _xdr_fhandle(param_1,param_2);
  if (iVar1 != 0) {
    sub_F0041784(param_1,param_2 + 0x20);
    uVar2 = 1;
    if (param_1 != 0) goto locret_F004227C;
  }
  uVar2 = 0;
locret_F004227C:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3392 start=0xf00422b8 */

/* WARNING: Removing unreachable block (ram,0xf00422d4) */
/* WARNING: Removing unreachable block (ram,0xf00422c0) */

undefined8 sub_F00422B8(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1;
  _xdr_long(param_1,param_2);
  if (iVar1 != 0) {
    _xdr_long(param_1,param_2 + 4);
    uVar2 = 1;
    if (param_1 != 0) goto locret_F00422EC;
  }
  uVar2 = 0;
locret_F00422EC:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3393 start=0xf0042438 */

/* WARNING: Removing unreachable block (ram,0xf004247c) */
/* WARNING: Removing unreachable block (ram,0xf0042454) */
/* WARNING: Removing unreachable block (ram,0xf0042468) */
/* WARNING: Removing unreachable block (ram,0xf0042490) */
/* WARNING: Removing unreachable block (ram,0xf0042440) */

undefined8 sub_F0042438(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1;
  _xdr_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = param_1, _xdr_long(param_1,param_2 + 4), iVar1 != 0)) &&
      (iVar1 = param_1, _xdr_long(param_1,param_2 + 8), iVar1 != 0)) &&
     (iVar1 = param_1, _xdr_long(param_1,param_2 + 0xc), iVar1 != 0)) {
    _xdr_long(param_1,param_2 + 0x10);
    uVar2 = 1;
    if (param_1 != 0) goto locret_F00424A8;
  }
  uVar2 = 0;
locret_F00424A8:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3394 start=0xf00429a4 */

undefined8 sub_F00429A4(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3395 start=0xf00429b0 */

/* WARNING: Removing unreachable block (ram,0xf00429d0) */

undefined8 sub_F00429B0(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffff7;
  if ((uVar1 & 0x10) != 0) {
    *param_1 = uVar1 & 0xffffffe7;
    _wakeup(param_1 + 0x1a);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3396 start=0xf00434d4 */

/* WARNING: Removing unreachable block (ram,0xf0043598) */
/* WARNING: Removing unreachable block (ram,0xf004356c) */
/* WARNING: Removing unreachable block (ram,0xf0043528) */
/* WARNING: Removing unreachable block (ram,0xf0043584) */
/* WARNING: Removing unreachable block (ram,0xf00434f8) */
/* WARNING: Removing unreachable block (ram,0xf00434e0) */

undefined8 sub_F00434D4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  word wVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = 1;
  _m_get(1,8);
  if (iVar1 == 0) {
    _printf(aBindresvportCo);
    iVar6 = 0x37;
  }
  else {
    iVar3 = *(int *)(iVar1 + 4);
    *(undefined2 *)(iVar1 + iVar3) = 2;
    iVar3 = iVar1 + iVar3;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined2 *)(iVar1 + 8) = 0x10;
    uVar2 = *(undefined4 *)(_active_u + 0x1c);
    _crdup();
    uVar5 = *(undefined4 *)(_active_u + 0x1c);
    *(undefined4 *)(_active_u + 0x1c) = uVar2;
    iVar6 = 0x30;
    wVar4 = 0x3ff;
    *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = 0;
    do {
      if (wVar4 < 0x200) break;
      *(word *)(iVar3 + 2) = wVar4;
      iVar6 = param_1;
      _sobind(param_1,iVar1);
      wVar4 = wVar4 - 1;
    } while (iVar6 == 0x30);
    _m_freem(iVar1);
    *(undefined4 *)(_active_u + 0x1c) = uVar5;
    _crfree(uVar2);
  }
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=3397 start=0xf004435c */

undefined8 sub_F004435C(undefined4 param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3398 start=0xf00443f4 */

undefined8 sub_F00443F4(int param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3399 start=0xf0044808 */

undefined8 sub_F0044808(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar2 = (int *)0x0;
  piVar4 = dword_F012F558;
  if (dword_F012F558 != (int *)0x0) {
    iVar1 = dword_F012F558[1];
    piVar3 = piVar2;
    piVar2 = dword_F012F558;
    while( true ) {
      if ((iVar1 == param_1) && (piVar2[2] == param_2)) {
        *param_3 = (int)piVar3;
        goto locret_F004485C;
      }
      piVar4 = (int *)*piVar2;
      if (piVar4 == (int *)0x0) break;
      iVar1 = piVar4[1];
      piVar3 = piVar2;
      piVar2 = piVar4;
    }
  }
  *param_3 = (int)piVar2;
  piVar2 = piVar4;
locret_F004485C:
  return CONCAT44(param_2,piVar2);
}

