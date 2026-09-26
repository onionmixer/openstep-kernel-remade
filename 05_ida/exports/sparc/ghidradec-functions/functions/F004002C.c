
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
