
/* WARNING: Removing unreachable block (ram,0xf003f554) */
/* WARNING: Removing unreachable block (ram,0xf003f52c) */
/* WARNING: Removing unreachable block (ram,0xf003f4a8) */
/* WARNING: Removing unreachable block (ram,0xf003f4a0) */
/* WARNING: Removing unreachable block (ram,0xf003f4e0) */
/* WARNING: Removing unreachable block (ram,0xf003f548) */
/* WARNING: Removing unreachable block (ram,0xf003f560) */
/* WARNING: Removing unreachable block (ram,0xf003f47c) */

undefined8 _nfswrite(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
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
    iVar1 = *(int *)(*(int *)(iVar1 + 0x128) + 0x20);
    if (param_4 < iVar1) {
      iVar1 = param_4;
    }
    *(int *)((int)register0x00000038 + -0x10) = param_2;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(iVar2 + 0x44);
    *(undefined4 *)((int)register0x00000038 + -0x38) = *(undefined4 *)(iVar2 + 0x48);
    *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(iVar2 + 0x4c);
    *(undefined4 *)((int)register0x00000038 + -0x30) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar2 + 0x5c);
    *(int *)((int)register0x00000038 + -0x20) = param_3;
    *(int *)((int)register0x00000038 + -0x18) = iVar1;
    *(int *)((int)register0x00000038 + -0x14) = iVar1;
    *(int *)((int)register0x00000038 + -0x1c) = param_3;
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar2,8,_xdr_writeargs,(undefined *)((int)register0x00000038 + -0x40),_xdr_attrstat,
             (undefined *)((int)register0x00000038 + -0x88),param_5);
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x88);
      if (iVar2 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
        param_4 = param_4 - iVar1;
      }
      else {
        param_4 = param_4 - iVar1;
      }
    }
    else {
      param_4 = param_4 - iVar1;
    }
    param_2 = param_2 + iVar1;
    param_3 = param_3 + iVar1;
    if ((iVar2 != 0) || (param_4 == 0)) break;
    iVar1 = *(int *)(param_1 + 0x24);
  }
  if (iVar2 == 0) {
    _nfs_attrcache(param_1,(undefined *)((int)register0x00000038 + -0x84));
  }
  if (iVar2 == 0x1c) {
    _printf(aNfsWriteErrorO,*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x34);
  }
  else {
    if (iVar2 < 0x1d) {
      if (iVar2 == 0) goto locret_F003F568;
      iVar1 = *(int *)(param_1 + 0x24);
    }
    else {
      if (iVar2 == 0x45) goto locret_F003F568;
      iVar1 = *(int *)(param_1 + 0x24);
    }
    _printf(aNfsWriteErrorD,iVar2,*(int *)(iVar1 + 0x128) + 0x34);
    sub_F003F570(*(int *)(param_1 + 0x30) + 0x40);
    _printf(&asc_F010D6C8);
  }
locret_F003F568:
  return CONCAT44(param_2,iVar2);
}
