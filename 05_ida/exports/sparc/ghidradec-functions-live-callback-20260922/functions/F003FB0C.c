
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

