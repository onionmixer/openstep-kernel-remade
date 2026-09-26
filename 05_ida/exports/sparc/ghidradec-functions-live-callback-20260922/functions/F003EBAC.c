
/* WARNING: Removing unreachable block (ram,0xf003ec68) */
/* WARNING: Removing unreachable block (ram,0xf003ebec) */

undefined8 sub_F003EBAC(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar4 = *(int *)(param_1 + 0x128);
  iVar5 = iVar4;
  _rfscall(iVar4,0x11,_xdr_fhandle,*(int *)(*(int *)(iVar4 + 0x10) + 0x30) + 0x40,_xdr_statfs,
           (undefined *)((int)register0x00000038 + -0x20),*(undefined4 *)(_active_u + 0x1c));
  if (iVar5 == 0) {
    iVar5 = *(int *)((int)register0x00000038 + -0x20);
  }
  if (iVar5 == 0) {
    uVar3 = *(uint *)(iVar4 + 0x20);
    uVar1 = *(uint *)((int)register0x00000038 + -0x1c);
    uVar2 = uVar1;
    if ((uVar3 == 0) || (uVar2 = uVar3, uVar3 < uVar1)) {
      *(uint *)(iVar4 + 0x20) = uVar2;
    }
    else {
      *(uint *)(iVar4 + 0x20) = uVar1;
    }
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    _bcopy(param_1 + 0x14,param_2 + 0x1c,8);
  }
  return CONCAT44(param_2,iVar5);
}

