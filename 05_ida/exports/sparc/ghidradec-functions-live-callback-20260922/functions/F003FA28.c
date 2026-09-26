
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

