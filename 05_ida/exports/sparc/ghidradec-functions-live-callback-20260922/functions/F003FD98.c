
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

