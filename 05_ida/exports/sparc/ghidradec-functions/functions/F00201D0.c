
undefined8 _soqinsque(int param_1,int param_2,int param_3)

{
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
  int iVar1;
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
  *(int *)(param_2 + 0x10) = param_1;
  if (param_3 == 0) {
    *(sword *)(param_1 + 0x18) = *(sword *)(param_1 + 0x18) + 1;
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x14) != param_1) {
      for (iVar1 = *(int *)(param_1 + 0x14); *(int *)(iVar1 + 0x14) != param_1;
          iVar1 = *(int *)(iVar1 + 0x14)) {
      }
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(int *)(iVar1 + 0x14) = param_2;
  }
  else {
    *(sword *)(param_1 + 0x20) = *(sword *)(param_1 + 0x20) + 1;
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x1c) != param_1) {
      for (iVar1 = *(int *)(param_1 + 0x1c); *(int *)(iVar1 + 0x1c) != param_1;
          iVar1 = *(int *)(iVar1 + 0x1c)) {
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(int *)(iVar1 + 0x1c) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
