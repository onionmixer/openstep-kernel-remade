
undefined8 sub_F0046F08(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(iVar2 + 0x38);
  (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))(iVar1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar2 + 0x4c);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar2 + 0x5c);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(iVar2 + 0x60);
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x7c);
    *(undefined4 *)(param_2 + 0x1c) = _fifoinfo;
  }
  return CONCAT44(param_2,iVar1);
}
