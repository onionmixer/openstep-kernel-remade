
/* WARNING: Removing unreachable block (ram,0xf00b78bc) */
/* WARNING: Removing unreachable block (ram,0xf00b788c) */
/* WARNING: Removing unreachable block (ram,0xf00b78b0) */
/* WARNING: Removing unreachable block (ram,0xf00b78c8) */
/* WARNING: Removing unreachable block (ram,0xf00b7878) */

undefined8 _esp_internal_reset(int param_1,uint param_2)

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
  if ((param_2 & 0x20) != 0) {
    _esp_printstate(param_1,&aReset);
  }
  if ((param_2 & 0xf) != 0) {
    _esp_hw_reset(param_1,param_2);
  }
  if ((param_2 & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0xb2);
    *(undefined2 *)(param_1 + 0xb2) = 0xffff;
    _bzero(param_1 + 0xb8,0x100);
    _bzero(param_1 + 0x5e,8);
    _bzero(param_1 + 0x66,8);
    *(undefined *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined *)(param_1 + 0x53) = 0;
    *(undefined *)(param_1 + 0x4c) = 0xff;
    *(undefined *)(param_1 + 0x52) = 0xff;
    *(undefined *)(param_1 + 0x54) = 0xff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0;
  }
  return CONCAT44(param_2,param_1);
}

