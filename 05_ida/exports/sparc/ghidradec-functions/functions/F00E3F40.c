
/* WARNING: Removing unreachable block (ram,0xf00e40b4) */
/* WARNING: Removing unreachable block (ram,0xf00e406c) */

undefined8 sub_F00E3F40(int param_1,int param_2)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x70) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((((((*(uint *)(param_1 + 0x18) & 0xc) == 4) &&
           (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x1c) == 0x90008)) &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) &&
         ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x2200018 &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x38) == 0x2200018)))) &&
        ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x40) == 0x2200018 &&
         ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x48) == 0x2200018 &&
          (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x50) == 0x2200018)))))) &&
       ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x58) == 0x2200018 &&
        ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x60) == 0x6200018 &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x68) == 0x2200018)))))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _audio_port_to_stream();
      __NXAudioPlayStream();
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
