
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
