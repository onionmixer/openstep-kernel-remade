
/* WARNING: Removing unreachable block (ram,0xf005e850) */
/* WARNING: Removing unreachable block (ram,0xf005e82c) */

undefined8 _ipc_splay_tree_bounds(uint *param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
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
  uVar2 = param_1[1];
  *(uint *)((int)register0x00000038 + -0xc) = uVar2;
  if (uVar2 == 0) {
    *param_3 = 0xffffffff;
    *param_4 = 0;
  }
  else {
    if (*param_1 != param_2) {
      sub_F005E2C8(uVar2,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4
                   ,param_1 + 5);
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *param_1 = param_2;
      param_1[1] = uVar2;
    }
    uVar2 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
    if (param_2 < uVar2) {
      if ((uint *)param_1[3] == param_1 + 2) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = ((uint *)param_1[3])[-3];
      }
      *param_3 = uVar1;
    }
    else {
      *param_3 = uVar2;
    }
    if (uVar2 < param_2) {
      if ((uint *)param_1[5] == param_1 + 4) {
        *param_4 = 0;
      }
      else {
        *param_4 = ((uint *)param_1[5])[-2];
      }
    }
    else {
      *param_4 = uVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
