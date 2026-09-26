
/* WARNING: Removing unreachable block (ram,0xf005076c) */
/* WARNING: Removing unreachable block (ram,0xf005070c) */
/* WARNING: Removing unreachable block (ram,0xf0050720) */
/* WARNING: Removing unreachable block (ram,0xf0050780) */
/* WARNING: Removing unreachable block (ram,0xf00506f8) */

undefined8 sub_F00506E8(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
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
  _copyin(param_3,(undefined *)((int)register0x00000038 + -0xc),4);
  puVar1 = *(undefined **)((int)register0x00000038 + -0xc);
  if ((param_3 == (undefined *)0x0) &&
     (sub_F0051228(puVar1,(undefined *)((int)register0x00000038 + -0xe)), param_3 = puVar1,
     puVar1 == (undefined *)0x0)) {
    iVar2 = (int)*(sword *)((int)register0x00000038 + -0xe);
    _bdevvp();
    uVar3 = *(uint *)(DAT_f011c7c0 + (uint)(*(word *)((int)register0x00000038 + -0xe) >> 8) * 0x18);
    *(int *)((int)register0x00000038 + -0x14) = iVar2;
    if ((uVar3 & 0x400) != 0) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
    }
    param_3 = (undefined *)((int)register0x00000038 + -0x14);
    sub_F0050874(param_3,param_2,param_1);
    if (param_3 != (undefined *)0x0) {
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x14));
    }
  }
  return CONCAT44(param_2,param_3);
}
