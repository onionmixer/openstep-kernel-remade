
/* WARNING: Removing unreachable block (ram,0xf00408f4) */
/* WARNING: Removing unreachable block (ram,0xf00408c4) */
/* WARNING: Removing unreachable block (ram,0xf0040874) */
/* WARNING: Removing unreachable block (ram,0xf0040868) */
/* WARNING: Removing unreachable block (ram,0xf00408a0) */
/* WARNING: Removing unreachable block (ram,0xf00408cc) */
/* WARNING: Removing unreachable block (ram,0xf0040934) */
/* WARNING: Removing unreachable block (ram,0xf004085c) */

undefined8 sub_F00407D4(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar5;
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
  iVar5 = *(int *)(param_1 + 0x30);
  if ((*(word *)(iVar5 + 0x60) & 8) == 0) {
    iVar1 = *param_2;
  }
  else {
    if (*(int *)(iVar5 + 0x98) == param_2[2]) {
      iVar1 = 0;
      goto locret_F004093C;
    }
    iVar1 = *param_2;
  }
  if (param_2[1] == 1) {
    uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x1c);
    if (*(uint *)(iVar1 + 4) < uVar2) {
      uVar2 = *(uint *)(iVar1 + 4);
    }
    *(uint *)((int)register0x00000038 + -0xc) = uVar2;
    *(int *)((int)register0x00000038 + -0x10) = param_2[2];
    _bcopy(*(int *)(param_1 + 0x30) + 0x40,(undefined *)((int)register0x00000038 + -0x30),0x20);
    *(uint *)((int)register0x00000038 + -0x3c) = uVar2;
    uVar3 = uVar2;
    _kalloc();
    *(uint *)((int)register0x00000038 + -0x34) = uVar3;
    _bzero();
    iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    _rfscall(iVar1,0x10,_xdr_rddirargs,(undefined *)((int)register0x00000038 + -0x30),
             _xdr_getrddirres,(undefined *)((int)register0x00000038 + -0x48),param_3);
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)register0x00000038 + -0x44);
      if (iVar1 == 0x46) {
        _btrash(param_1);
        _nfs_invalidate_caches(param_1);
      }
      if (iVar1 == 0) {
        if (*(int *)((int)register0x00000038 + -0x3c) != 0) {
          iVar1 = *(int *)((int)register0x00000038 + -0x34);
          _uiomove(iVar1,*(int *)((int)register0x00000038 + -0x3c),0,param_2);
          *(int *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x40);
          param_2[2] = *(int *)((int)register0x00000038 + -0x40);
        }
        uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
        if (*(int *)((int)register0x00000038 + -0x38) != 0) {
          *(word *)(iVar5 + 0x60) = *(word *)(iVar5 + 0x60) | 8;
          *(int *)(iVar5 + 0x98) = param_2[2];
          uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
        }
      }
      else {
        uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
      }
    }
    else {
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x34);
    }
    _kfree(uVar4,uVar2);
  }
  else {
    iVar1 = 0x16;
  }
locret_F004093C:
  return CONCAT44(param_2,iVar1);
}

