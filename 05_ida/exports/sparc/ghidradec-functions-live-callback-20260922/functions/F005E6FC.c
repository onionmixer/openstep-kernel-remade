
/* WARNING: Removing unreachable block (ram,0xf005e794) */
/* WARNING: Removing unreachable block (ram,0xf005e770) */
/* WARNING: Removing unreachable block (ram,0xf005e7ac) */
/* WARNING: Removing unreachable block (ram,0xf005e71c) */

undefined8 _ipc_splay_tree_join(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 != 0) {
    sub_F005E2C8(iVar2,param_2 + 8,*(undefined4 *)(param_2 + 0xc),param_2 + 0x10,
                 *(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 4) = 0;
    iVar1 = param_1[1];
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = iVar2;
    }
    else {
      if (*param_1 != 0) {
        sub_F005E2C8(iVar1,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
        sub_F005E1A4(0,*(undefined4 *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,
                     param_1 + 4,param_1 + 5);
      }
      sub_F005E2C8(*(undefined4 *)((int)register0x00000038 + -0xc),param_1 + 2,param_1[3],
                   param_1 + 4,param_1[5]);
      *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) = iVar2;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    param_1[1] = iVar2;
    *param_1 = *(int *)(iVar2 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return CONCAT44(param_2,param_1);
}

