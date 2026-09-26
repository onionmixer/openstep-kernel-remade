
undefined8
sub_F005E1A4(uint param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
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
  uVar1 = *(uint *)(param_2 + 0x10);
  puVar3 = *(undefined4 **)((int)register0x00000038 + 0x5c);
joined_r0xf005e1b0:
  if (param_1 == uVar1) {
    *param_3 = param_2;
loc_F005E2B8:
    *param_5 = param_4;
    *puVar3 = param_6;
    return CONCAT44(param_2,param_1);
  }
  if (param_1 < uVar1) {
    iVar2 = *(int *)(param_2 + 0x18);
    if (iVar2 == 0) {
      *param_3 = param_2;
      goto loc_F005E2B8;
    }
    uVar1 = *(uint *)(iVar2 + 0x10);
    if (param_1 < uVar1) {
      if (*(int *)(iVar2 + 0x18) != 0) {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar2 + 0x1c);
        *(int *)(iVar2 + 0x1c) = param_2;
        param_2 = iVar2;
      }
      *param_6 = param_2;
    }
    else {
      *param_6 = param_2;
    }
    param_6 = (int *)(param_2 + 0x18);
    param_2 = *(int *)(param_2 + 0x18);
    if (uVar1 < param_1) {
      if (*(int *)(iVar2 + 0x1c) != 0) {
        *param_4 = param_2;
        param_4 = (int *)(param_2 + 0x1c);
        param_2 = *(int *)(param_2 + 0x1c);
        goto loc_F005E2A4;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      goto joined_r0xf005e1b0;
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x1c);
    if (iVar2 == 0) {
      *param_3 = param_2;
      goto loc_F005E2B8;
    }
    uVar1 = *(uint *)(iVar2 + 0x10);
    if (uVar1 < param_1) {
      if (*(int *)(iVar2 + 0x1c) != 0) {
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x18) = param_2;
        param_2 = iVar2;
      }
      *param_4 = param_2;
    }
    else {
      *param_4 = param_2;
    }
    param_4 = (int *)(param_2 + 0x1c);
    param_2 = *(int *)(param_2 + 0x1c);
    if (param_1 < uVar1) {
      if (*(int *)(iVar2 + 0x18) != 0) {
        *param_6 = param_2;
        param_6 = (int *)(param_2 + 0x18);
        param_2 = *(int *)(param_2 + 0x18);
        goto loc_F005E2A4;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      goto joined_r0xf005e1b0;
    }
  }
loc_F005E2A4:
  uVar1 = *(uint *)(param_2 + 0x10);
  goto joined_r0xf005e1b0;
}

