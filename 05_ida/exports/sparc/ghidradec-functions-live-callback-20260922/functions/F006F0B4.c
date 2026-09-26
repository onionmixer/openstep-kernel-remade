
undefined8 _thread_change_psets(int param_1,int param_2,int param_3)

{
  int iVar1;
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
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x1c);
  if (param_2 + 0x138 == iVar2) {
    *(int *)(param_2 + 0x13c) = iVar1;
  }
  else {
    *(int *)(iVar2 + 0x1c) = iVar1;
  }
  if (param_2 + 0x138 == iVar1) {
    *(int *)(param_2 + 0x138) = iVar2;
  }
  else {
    *(int *)(iVar1 + 0x18) = iVar2;
  }
  *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + -1;
  iVar1 = *(int *)(param_3 + 0x13c);
  if (param_3 + 0x138 == iVar1) {
    *(int *)(param_3 + 0x138) = param_1;
  }
  else {
    *(int *)(iVar1 + 0x18) = param_1;
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(param_1 + 0x18) = param_3 + 0x138;
  *(int *)(param_3 + 0x13c) = param_1;
  *(int *)(param_1 + 400) = param_3;
  *(int *)(param_3 + 0x140) = *(int *)(param_3 + 0x140) + 1;
  return CONCAT44(param_2,param_1);
}

