
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

