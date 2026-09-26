
/* WARNING: Removing unreachable block (ram,0xf00511fc) */
/* WARNING: Removing unreachable block (ram,0xf00511c8) */
/* WARNING: Removing unreachable block (ram,0xf005117c) */
/* WARNING: Removing unreachable block (ram,0xf0051138) */
/* WARNING: Removing unreachable block (ram,0xf005114c) */
/* WARNING: Removing unreachable block (ram,0xf0051198) */
/* WARNING: Removing unreachable block (ram,0xf00511e8) */
/* WARNING: Removing unreachable block (ram,0xf0051204) */
/* WARNING: Removing unreachable block (ram,0xf0051128) */

undefined8 _sbupdate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar7;
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
  iVar1 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 0x20);
  (**(code **)(*(int *)(iVar1 + 0x1c) + 0x80))();
  uVar2 = 0x2000;
  if (-1 < iVar1) {
    .div(0x2000,iVar1);
    iVar1 = *(int *)(param_1 + 8);
    _getblk(iVar1,uVar2,*(undefined4 *)(iVar6 + 0x68));
    _bcopy(iVar6,*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar6 + 0x68));
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x90) = 0;
    *(undefined *)(*(int *)(iVar1 + 0x20) + 0xd3) = 0;
    _bwrite(iVar1);
    iVar7 = *(int *)(iVar6 + 0x2d8);
    iVar5 = 0;
    iVar1 = *(int *)(iVar6 + 0x9c) + -1 + *(int *)(iVar6 + 0x34);
    .div();
    if (0 < iVar1) {
      iVar3 = *(int *)(iVar6 + 0x38);
      do {
        iVar4 = *(int *)(iVar6 + 0x30);
        if (iVar1 < iVar5 + iVar3) {
          iVar4 = iVar1 - iVar5;
          .umul(iVar4,*(undefined4 *)(iVar6 + 0x34));
        }
        iVar3 = *(int *)(param_1 + 8);
        _getblk(iVar3,*(int *)(iVar6 + 0x98) + iVar5 << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f),
                iVar4);
        _bcopy(iVar7,*(undefined4 *)(iVar3 + 0x20),iVar4);
        _bwrite(iVar3);
        iVar3 = *(int *)(iVar6 + 0x38);
        iVar5 = iVar5 + iVar3;
        iVar7 = iVar7 + iVar4;
      } while (iVar5 < iVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
