
/* WARNING: Removing unreachable block (ram,0xf00510b8) */
/* WARNING: Removing unreachable block (ram,0xf0051098) */
/* WARNING: Removing unreachable block (ram,0xf0051070) */
/* WARNING: Removing unreachable block (ram,0xf00510a0) */
/* WARNING: Removing unreachable block (ram,0xf00510d4) */
/* WARNING: Removing unreachable block (ram,0xf0051054) */

sqword sub_F005102C(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20);
  if (*(int *)(iVar5 + 0x55c) != 0x11954) {
    _panic(aUfsStatfs);
  }
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar5 + 0x34);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar5 + 0x28);
  iVar1 = *(int *)(iVar5 + 0xc4);
  .umul(iVar1,*(undefined4 *)(iVar5 + 0x38));
  iVar1 = iVar1 + *(int *)(iVar5 + 0xcc);
  *(int *)(param_2 + 0xc) = iVar1;
  iVar4 = *(int *)(iVar5 + 0x28);
  iVar2 = iVar4;
  .umul(iVar4,100 - *(int *)(iVar5 + 0x3c));
  .div();
  *(int *)(param_2 + 0x10) = iVar2 - (iVar4 - iVar1);
  uVar3 = *(undefined4 *)(iVar5 + 0x2c);
  .umul(uVar3,*(undefined4 *)(iVar5 + 0xb8));
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar5 + 200);
  _bcopy(param_1 + 0x14,param_2 + 0x1c,8);
  return (qword)param_2 << 0x20;
}
