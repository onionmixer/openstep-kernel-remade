
/* WARNING: Removing unreachable block (ram,0xf00e317c) */

undefined8 sub_F00E30F0(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
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
  if ((*(int *)(param_1 + 4) == 0x6c) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x2200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x8080408)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 100) == 0x2200018)) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0x40;
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _EvGetParameterInt(uVar1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,
                         *(undefined4 *)(param_1 + 0x68),param_2 + 0x24,
                         (undefined *)((int)register0x00000038 + -0xc));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x20) = 0x2200408;
      *(uint *)(param_2 + 0x20) = (uVar2 & 0xfff) << 4 | 0x2200008;
      *(undefined *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = uVar2 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}

