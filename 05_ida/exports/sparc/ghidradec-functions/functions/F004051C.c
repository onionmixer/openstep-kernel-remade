
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
