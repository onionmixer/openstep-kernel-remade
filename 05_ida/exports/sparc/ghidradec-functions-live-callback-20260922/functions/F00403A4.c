
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

